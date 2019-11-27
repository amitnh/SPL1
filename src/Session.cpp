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

        //Read Config File
        //MOVIES
        std::ifstream i("./include/config1.json");
        json j;
        i>>j; // j has all watchable content
        json jj =j["movies"];
        std::vector<std::string> tags;
        int index =0;
        for(int i=0; i<jj.size();++i){
            for(int k=0; k<jj[i]["tags"].size();++k){
                tags.push_back(jj[i]["tags"][k]);
            }
            Watchable* mov = new Movie(index, jj[i]["name"],jj[i]["length"], tags );
            tags.empty();
            index++;
            content.push_back(mov);
                    // Movie(long id, const std::string& name, int length, const std::vector<std::string>& tags)
        }
        //TV Series

        jj= j["tv_series"];

        for(int i=0; i<jj.size();++i){
            cout << jj[i]["tags"]<< endl;

            for(int k=0; k<jj[i]["tags"].size();++k){
                tags.push_back(jj[i]["tags"][k]);
            }
            for(int i=0; i<jj[i]["seasons"].size();i++) {
                for(int k=0;k< jj[i]["seasons"][i];++k) {
                    Watchable* episode = new Episode(index, jj[i]["name"],jj[i]["episode_length"],i,k,tags );
                    tags.empty();
                    index++;
                    content.push_back(episode);
                }

            // Episode(long id, const std::string& seriesName,int length, int season, int episode ,const std::vector<std::string>& tags):
            }
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

//Copy Assignment
    void start(){

    }
    void addUser(User*)
    {
        // add to userMap
    }
    User& getActiveUser()
    {
        return *activeUser;
    }

