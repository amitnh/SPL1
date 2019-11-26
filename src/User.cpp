//
// Created by kapelnik on 23/11/2019.
//

#include "../include/User.h"
//#include <nlohmann/json.hpp>

    User::User(const std::string &name):name{name} { }

    User::~User() = default;    //Destructor


    User::User(User &&other) {}     //Move constructor
    User::User& operator=(const User &other){}   //Copy Assignment           RULE OF 5
    User::User(const User &other):name{other.name}, history{other.history} {}     //Copy constructor
    User& User::operator=(User &&other){}   //Copy Assignment



    virtual Watchable* getRecommendation(Session& s){}
    std::string getName() {
        return this->name;
    }
    std::vector<Watchable*> get_history(){
        return this->history;
    }
        std::vector<Watchable*> history;
        const std::string name;

}


//lass LengthRecommenderUser : public User {

LengthRecommenderUser::LengthRecommenderUser(const std::string &name):User(name) {}//use USER constractor}
    virtual Watchable* LengthRecommenderUser::getRecommendation(Session& s){
        //later
    }


//class RerunRecommenderUser : public User {
RerunRecommenderUser::RerunRecommenderUser(const std::string& name):User(name){ };//use USER constractor
    virtual Watchable* RerunRecommenderUser::getRecommendation(Session& s)
    {

    }

//class GenreRecommenderUser : public User {
    GenreRecommenderUser::GenreRecommenderUser(const std::string& name):User(name){ };//use USER constractor
    virtual Watchable* GenreRecommenderUser::getRecommendation(Session& s){

    }
