//
// Created by kapelnik on 23/11/2019.
//

#include "../include/Session.h"
#include "../include/User.h"
#include "../include/json.hpp"
#include "../include/Watchable.h"
#include <unordered_map>
#include <iostream>
#include <fstream>
#include <ostream>
#include <sstream>

using json=nlohmann::json;
using namespace std;
std::vector<Watchable *> content;
std::vector<BaseAction *> actionsLog;
std::unordered_map<std::string, User *> userMap;
User *activeUser;

Session::Session(const std::string &configFilePath) : content(), actionsLog(), userMap() {         //constructor
    //insert from json file to watchable vector "content"
    User *defaultUser = new LengthRecommenderUser("default");
    activeUser = defaultUser;
    //******add to userMap
    pair<std::string, User *> upair(defaultUser->getName(), defaultUser);
    userMap.insert(upair);
    //Read Config File


    //MOVIES
    std::ifstream i(configFilePath);
    //std::ifstream i("./include/config1.json");
    json j;
    i >> j; // j has all watchable content
    json jj = j["movies"];
    std::vector<std::string> tags;
    int index = 0;
    for (int i = 0; i < jj.size(); ++i) {
        for (int k = 0; k < jj[i]["tags"].size(); ++k) {
            tags.push_back(jj[i]["tags"][k]);
        }
        Watchable *mov = new Movie(index, jj[i]["name"], jj[i]["length"], tags);
        tags.clear();
        index++;
        content.push_back(mov);
        // Movie(long id, const std::string& name, int length, const std::vector<std::string>& tags)
    }
    //TV Series

    jj = j["tv_series"];

    for (int series = 0; series < jj.size(); ++series) {
        for (int k = 0; k < jj[series]["tags"].size(); ++k) {
            tags.push_back(jj[series]["tags"][k]);
        }
        for (int season = 0; season < jj[series]["seasons"].size(); ++season) {
            for (int episode = 0; episode < jj[series]["seasons"][season]; ++episode) {
                Watchable *epi = new Episode(index, jj[series]["name"], jj[series]["episode_length"], season + 1,
                                             episode + 1, tags);
                index++;
                content.push_back(epi);
            }

            // Episode(long id, const std::string& seriesName,int length, int season, int episode ,const std::vector<std::string>& tags):
        }
        tags.clear();

    }
}

Session::~Session() {    //Destructor}

    // delete all watchable
    for (auto watch : content) {
        delete watch;
    }
    // delete all BaseAction in actionlog
    for (auto log : actionsLog) {
        delete log;
    }
    for (auto log : userMap) {
        delete log.second;
    }

}

Session::Session(const Session &other) {     //Copy constructor
    for (auto log : other.actionsLog) {
        actionsLog.push_back(log->clone());
    }
    for (auto watch : other.content) {
        content.push_back(watch->clone());
    }
    activeUser = other.activeUser->clone(activeUser->getName());

    for (std::pair<std::string, User *> element : other.userMap) {
        std::pair<std::string, User *> elementcopy(element.first, element.second->clone(element.first));
        this->userMap.insert(elementcopy);

        for (Watchable *his : element.second->get_history()) //connect the history in each user to the new movie pointer
        {
            for (auto watch : content) {
                if (his->get_id() == watch->get_id()) {
                    his = watch;
                    break;
                }
            }
        }
    }
}

Session &Session::operator=(const Session &other) {  //Copy Assignment           RULE OF 5

    actionsLog.clear();
    for (auto log : other.actionsLog) {
        actionsLog.push_back(log->clone());
    }
    content.clear();
    for (auto watch : other.content) {
        content.push_back(watch->clone());
    }
    activeUser = other.activeUser->clone(activeUser->getName());

    userMap.clear();
    for (std::pair<std::string, User *> element : other.userMap) {
        std::pair<std::string, User *> elementcopy(element.first, element.second->clone(element.first));
        this->userMap.insert(elementcopy);

        for (Watchable *his : element.second->get_history()) //connect the history in each user to the new movie pointer
        {
            for (auto watch : content) {
                if (his->get_id() == watch->get_id()) {
                    his = watch;
                    break;
                }
            }
        }
    }
    return *this;
}

Session::Session(Session &&other) {     //Move constructor
    content = other.content;
    actionsLog = other.actionsLog;
    userMap = other.userMap;
    activeUser = other.activeUser;
}

Session &Session::operator=(Session &&other) { //move assignment
    for (auto watch : content) {
        delete watch;
    }
    for (auto action : actionsLog) {
        delete action;
    }
    for (std::pair<std::string, User *> element : other.userMap) {
        delete element.second;
    }
    delete activeUser;

    content = other.content;
    actionsLog = other.actionsLog;
    userMap = other.userMap;
    activeUser = other.activeUser;
    return *this;
}


User &Session::get_activeUser() {
    return *activeUser;
}

void Session::start() {
    //for(int i=0;i<200;i++)
    //cout<< content.at(i)->toString();
    std::string input;
    while (input != "exit") {
        cout << "splflix is now on" << endl;
        std::getline(std::cin, input);
        //input="createuser tal len";
        command = split(input);
        BaseAction *action;
        if (command.at(0) == "createuser") {
            action = new CreateUser();
            action->act(*this);
        } else if (command.at(0) == "changeuser") {
            action = new ChangeActiveUser();
            action->act(*this);
        } else if (command.at(0) == "deleteuser") {
            action = new DeleteUser();
            action->act(*this);
        } else if (command.at(0) == "dupuser") {
            action = new DuplicateUser();
            action->act(*this);
        } else if (command.at(0) == "content") {
            action = new PrintContentList();
            action->act(*this);
        } else if (command.at(0) == "watchhist") {
            action = new PrintWatchHistory();
            action->act(*this);
        } else if (command.at(0) == "watch") {
            stringstream id_s(command.at(1));
            int id = 0;
            try {
                id_s >> id;
                command.at(1) = to_string(--id);
            }
            catch (const std::exception &e) {}
            action = new Watch();
            action->act(*this);
        } else if (command.at(0) == "log") {
            action = new PrintActionsLog();
            action->act(*this);
        }
    }
}

std::vector<std::string> Session::split(std::string str) {
    vector<std::string> output;
    string word;
    for (auto x : str) {
        if (x == ' ') {
            output.push_back(word);
            word = "";
        } else
            word = word + x;
    }
    output.push_back(word);
    return output;
}

std::vector<std::string> Session::get_command() {
    return command;
}

void Session::add_user(User *user) {        //******add to userMap
    pair<std::string, User *> upair(user->getName(), user);
    userMap.insert(upair);

}

void Session::add_actionlog(BaseAction &action) {
    actionsLog.push_back(&action);
}

void Session::print_actionlog() {
    for (int i = 0; i < actionsLog.size(); ++i)
        cout << actionsLog.at(i)->toString() << endl;
}

bool Session::isTaken(std::string name) {
    if (userMap.find(name) == userMap.end())
        return false;
    return true;
}

std::vector<BaseAction *> &Session::get_actionsLog() {
    return actionsLog;
}


User *Session::get_user_by_name(std::string name) {
    if (isTaken(name)) {
        std::unordered_map<std::string, User *>::iterator x = userMap.find(name);
        return x->second;
    }
}


std::vector<Watchable *> &Session::get_contant() {
    return this->content;
}

void Session::set_activeUser(std::string name) {
    activeUser = get_user_by_name(name);
}

void Session::delete_user(std::string name) {
    delete get_user_by_name(name);
    userMap.erase(name);
}

std::vector<Watchable *> &Session::get_content() {
    return content;
}

void Session::set_command(std::vector<std::string> cmd) {
    command = cmd;
}

User &getActiveUser() {
    return *activeUser;
}

