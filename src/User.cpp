//
// Created by kapelnik on 23/11/2019.
//

#include "../include/User.h"
#include "../include/Watchable.h"


//#include <nlohmann/json.hpp>

    User::User(const std::string &name):name(name),history() {}

    //User::~User(){}  //Destructor
    //User::User(User &&other) {}     //Move constructor
    //User&  User::operator=(const User &other){}   //Copy Assignment           RULE OF 5
    // User(const User &other):name(other.name), history(other.history) {}     //Copy constructor
    //User& User::operator=(User &&other){}   //Copy Assignment



    Watchable* User::getRecommendation(Session& s)
    {

    }
    std::string User::getName() const {
        return this->name;
    }
    std::vector<Watchable*> User::get_history() const{
        return this->history;
    }
       // std::vector<Watchable*> history;
        //const std::string name;




//lass LengthRecommenderUser : public User {

LengthRecommenderUser::LengthRecommenderUser(const std::string &name):User(name) {}//use USER constractor}
    Watchable* LengthRecommenderUser::getRecommendation(Session& s){
        //later
    }


//class RerunRecommenderUser : public User {
RerunRecommenderUser::RerunRecommenderUser(const std::string& name):User(name){ };//use USER constractor
    Watchable* RerunRecommenderUser::getRecommendation(Session& s)
    {

    }

//class GenreRecommenderUser : public User {
    GenreRecommenderUser::GenreRecommenderUser(const std::string& name):User(name){ };//use USER constractor
    Watchable* GenreRecommenderUser::getRecommendation(Session& s){

    }
