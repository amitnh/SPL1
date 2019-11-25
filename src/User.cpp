//
// Created by kapelnik on 23/11/2019.
//

#include "User.h"
#include <nlohmann/json.hpp>

class User {
public:
    User(const std::string &name) {
        this.name(name);
    }

        ~User()     //Destructor


    }
    User(User &&other)      //Move constructor
    User& operator=(const User &other)   //Copy Assignment           RULE OF 5
    User(const User &other):name(other.name), history(other.history)      //Copy constructor
    User& operator=(User &&other){}   //Copy Assignment



    virtual Watchable* getRecommendation(Session& s) = 0;
    std::string getName() {
        return this->name;
    }
    std::vector<Watchable*> get_history(){
        return this->history;
    }
    protected:
        std::vector<Watchable*> history;
    private:
        const std::string name;

}


class LengthRecommenderUser : public User {
public:
    LengthRecommenderUser(const std::string &name):User(name) {//use USER constractor

}
    virtual Watchable* getRecommendation(Session& s){
        //later
    }

private:
}

class RerunRecommenderUser : public User {
public:
    RerunRecommenderUser(const std::string& name):User(name){ };//use USER constractor
    virtual Watchable* getRecommendation(Session& s)
    {

    }
private:
}

class GenreRecommenderUser : public User {
public:
    GenreRecommenderUser(const std::string& name):User(name){ };//use USER constractor
    virtual Watchable* getRecommendation(Session& s){

    }
private:
}

#endif