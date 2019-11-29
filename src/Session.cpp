//
// Created by kapelnik on 23/11/2019.
//

#include "../include/Session.h"
#include "../include/User.h"
#include "../include/json.hpp"
#include "../include/Watchable.h"

#include <iostream>
#include <fstream>
#include <ostream>
using json=nlohmann::json;
using namespace std;
std::vector<Watchable*> content;
std::vector<BaseAction*> actionsLog;
std::unordered_map<std::string,User*> userMap;
User* activeUser;

    Session::Session(const std::string &configFilePath):content(), actionsLog(), userMap(){         //constructor
        //insert from json file to watchable vector "content"
        User* defaultUser = new LengthRecommenderUser("default");
        activeUser = defaultUser;
        //******add to userMap
        pair<std::string,User*> upair(defaultUser->getName(),defaultUser);
        userMap.insert(upair);
        //Read Config File
        //MOVIES
        std::ifstream i(configFilePath);
        //std::ifstream i("./include/config1.json");
        json j;
        i>>j; // j has all watchable content
        json jj =j["movies"];
        std::vector<std::string> tags;
        int index =1;
        for(int i=0; i<jj.size();++i){
            for(int k=0; k<jj[i]["tags"].size();++k){
                tags.push_back(jj[i]["tags"][k]);
            }
            Watchable* mov = new Movie(index, jj[i]["name"],jj[i]["length"], tags );
            tags.clear();
            index++;
            content.push_back(mov);
                    // Movie(long id, const std::string& name, int length, const std::vector<std::string>& tags)
        }
        //TV Series

        jj= j["tv_series"];

        for(int series=0; series<jj.size();++series){
            for(int k=0; k<jj[series]["tags"].size();++k){
                tags.push_back(jj[series]["tags"][k]);
            }
            for(int season=0; season<jj[series]["seasons"].size();++season) {
                for(int episode=0;episode< jj[series]["seasons"][season];++episode) {
                    Watchable* epi = new Episode(index, jj[series]["name"],jj[series]["episode_length"],season+1,episode+1,tags );
                    index++;
                    content.push_back(epi);
                }

            // Episode(long id, const std::string& seriesName,int length, int season, int episode ,const std::vector<std::string>& tags):
            }
            tags.clear();

        }
    }
    Session::~Session()  {}    //Destructor
    Session::Session(const Session &other) {}     //Copy constructor
    Session::Session(Session &&other) {}     //Move constructor
    Session&     Session::operator=(const Session &other) {}  //Copy Assignment           RULE OF 5
    Session&     Session::operator=(Session &&other){}

User &Session::get_activeUser() {
    return *activeUser;
}

void Session::start() {
        //for(int i=0;i<200;i++)
        //cout<< content.at(i)->toString();
        std::string input;
    while(true) {
        while (input!="start"){std::getline(std::cin,input);} // wait for "start" command
        cout << "splflix is now on" << endl;
        while (input != "exit") {
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
                action = new Watch();
                action->act(*this);
            } else if (command.at(0) == "log") {
                action = new PrintActionsLog();
                action->act(*this);
            }
        }
    }
}

std::vector<std::string> Session::split(std::string str) {
        vector<std::string> output;
        string word = "";
        for (auto x : str)
        {
            if (x == ' ')
            {
                output.push_back(word);
                word = "";
            }
            else
                word = word + x;
        }
        output.push_back(word);
        return output;
}

std::vector<std::string> Session::get_command() {
    return command;
}

void Session::add_user(User *user)     {        //******add to userMap
    pair<std::string,User*> upair(user->getName(),user);
    userMap.insert(upair);

}

void Session::add_actionlog(BaseAction &action) {
    actionsLog.push_back(&action);
}

void Session::print_actionlog() {
    for(int i=0; i<actionsLog.size();++i)
        cout<<actionsLog.at(i)->toString() <<endl;
}

bool Session::isTaken(std::string name) {
    if( userMap.find(name)== userMap.end())
        return false;
    return true;
}

std::vector<BaseAction *>& Session::get_actionsLog() {
    return actionsLog;
}


User &Session::get_user_by_name(std::string name) {
        if(!isTaken(name))
        if( userMap.find(name)== userMap.end())
            return *userMap.end().operator*().second;
}

std::vector<Watchable *> &Session::get_contant() {
    return this->content;
}

User& getActiveUser()
    {
        return *activeUser;
    }

