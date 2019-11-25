//
// Created by kapelnik on 23/11/2019.
//

#include "Session.h"
#include <nlohmann/json.hpp>
using json = nlohmann::json;
class Session{
public:
    Session(const std::string &configFilePath){         //constructor
        //insert from json file to watchable vector "content"
        activeUser = User("default");

    }
    ~Session()     //Destructor
    Session(const Session &other)      //Copy constructor
    Session(Session &&other)      //Move constructor
    Session& operator=(const Session &other)   //Copy Assignment           RULE OF 5
    Session& operator=(Session &&other);   //Copy Assignment
    void start();
    void addUser(User*)
    {
        // add to userMap
    }
private:
    std::vector<Watchable*> content;
    std::vector<BaseAction*> actionsLog;
    std::unordered_map<std::string,User*> userMap;
    User* activeUser;
};