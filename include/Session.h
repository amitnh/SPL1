#ifndef SESSION_H_
#define SESSION_H_

#include <vector>
#include <unordered_map>
#include <string>
#include "../include/Action.h"

class User;
class Watchable;

class Session{
public:
    Session(const std::string &configFilePath);
    ~Session();     //Destructor
    Session(const Session &other);      //Copy constructor
    Session(Session &&other);      //Move constructor
    Session& operator=(const Session &other);   //Copy Assignment           RULE OF 5
    Session& operator=(Session &&other);   //Copy Assignment

    User& get_activeUser();
    void start();
private:
    std::vector<Watchable*> content;
    std::vector<BaseAction*> actionsLog;
    std::unordered_map<std::string,User*> userMap;
    User* activeUser;
};
#endif
