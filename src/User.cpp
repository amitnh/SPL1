//
// Created by kapelnik on 23/11/2019.
//

#include "../include/User.h"
#include "../include/Watchable.h"

#include "../include/Session.h"


//#include <nlohmann/json.hpp>
using namespace std;
    User::User(const std::string &name):name(name),history() {}

    //User::~User(){}  //Destructor
    //User::User(User &&other) {}     //Move constructor
    //User&  User::operator=(const User &other){}   //Copy Assignment           RULE OF 5
    // User(const User &other):name(other.name), history(other.history) {}     //Copy constructor
    //User& User::operator=(User &&other){}   //Copy Assignment

    std::string User::getName() const {
        return this->name;
    }
    std::vector<Watchable*> User::get_history() const{
        return this->history;
    }

bool User::searchinhistory(int id) {
    for(auto wtch : history)
        if (wtch->get_id()==id)
            return true;
        return false;

}

// std::vector<Watchable*> history;
        //const std::string name;




//class LengthRecommenderUser : public User {
LengthRecommenderUser::LengthRecommenderUser(const std::string &name):User(name) {}//use USER constractor}

    Watchable* LengthRecommenderUser::getRecommendation(Session& sess) {
        int min=2275488857, id=0;
        for(auto x : sess.get_contant()){
           if(!searchinhistory(x->get_id()))
                if(abs(x->get_length()-avg_his_length)<min) {
                    id = x->get_id();
                    min = abs(x->get_length()-avg_his_length);
                }
        }

    }
void LengthRecommenderUser::set_avg_his_length(int new_average) {
    avg_his_length = new_average;
}

int LengthRecommenderUser::get_avg_his_length() {
    return avg_his_length;
}
LengthRecommenderUser *LengthRecommenderUser::clone() {
    return new LengthRecommenderUser(*this);
}


//class RerunRecommenderUser : public User {
RerunRecommenderUser::RerunRecommenderUser(const std::string& name):User(name){ };//use USER constractor
    Watchable* RerunRecommenderUser::getRecommendation(Session& s)
    {

    }
RerunRecommenderUser *RerunRecommenderUser::clone() {
    return new RerunRecommenderUser(*this);
}

//class GenreRecommenderUser : public User {
    GenreRecommenderUser::GenreRecommenderUser(const std::string& name):User(name){ };//use USER constractor
    Watchable* GenreRecommenderUser::getRecommendation(Session& s){

    }
GenreRecommenderUser *GenreRecommenderUser::clone() {
    return new GenreRecommenderUser(*this);
}
