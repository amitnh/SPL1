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
    void print_actionlog();
    void add_user(User *user);
    void add_actionlog(BaseAction &action);
    User& get_user_by_name(std::string name);
    std::vector<std::string> split(std::string str);
    std::vector<std::string> get_command(); // inputs separate by words
private:
    std::vector<std::string> command; // inputs separate by words
    std::vector<Watchable*> content;
    std::vector<BaseAction*> actionsLog;
    std::unordered_map<std::string,User*> userMap;
    User* activeUser;
};
#endif
