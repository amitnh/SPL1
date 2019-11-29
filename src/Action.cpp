//
// Created by amit on 11/25/19.
//
#include <string>
#include <iostream>
#include "../include/Session.h"
#include "../include/Action.h"
#include "../include/User.h"
#include "../include/Watchable.h"

//enum ActionStatus{PENDING, COMPLETED, ERROR}

//class BaseAction::{
    BaseAction::BaseAction():status{PENDING}{
}

void BaseAction::complete() {
status=COMPLETED;
}

void BaseAction::error(const std::string &errorMsg) {
    std::cout<<errorMsg;
    status==ERROR;
}

ActionStatus BaseAction::getStatus() const {
    return status;
}

//class CreateUser  : public BaseAction {
    void CreateUser::act(Session& sess)
    {
        sess.add_actionlog(*this);
        std::vector<std::string> command = sess.get_command();
        if (command.size()<3)
            error("\nThe command is too short for Create User action");
        else if (command.at(2).compare("len")*command.at(2).compare("rer")*command.at(2).compare("gen")!=0) {
            error("\nWrong recommendation algorithm, use only 'len','gen' or 'rer' ");
        }
        else if (sess.isTaken(command.at(1))){
            error("\nName already exists");
        }
        else
        {
            User* newUser;
            if (command.at(2)=="len")
                newUser = new LengthRecommenderUser(command.at(1));
            else if (command.at(2)=="rer")
                newUser = new RerunRecommenderUser(command.at(1));
            else if (command.at(2)=="gen")
                newUser = new GenreRecommenderUser(command.at(1));
            sess.add_user(newUser);
            complete();
        }

    }
    std::string CreateUser::toString() const
    {
      return "CreateUser "  + std::to_string(this->getStatus());
    }

//class ChangeActiveUser : public BaseAction {
    void ChangeActiveUser::act(Session& sess){}
    std::string ChangeActiveUser::toString() const {}

//class DeleteUser : public BaseAction {
    void DeleteUser::act(Session & sess){}
    std::string DeleteUser::toString() const {}


//class DuplicateUser : public BaseAction {
    void DuplicateUser::act(Session & sess){} //make DuplicateUser var here in "act", to pull Name1 name2 from the start method
    std::string DuplicateUser::toString() const{}


//class PrintContentList : public BaseAction {
    void PrintContentList::act (Session& sess){}
    std::string PrintContentList::toString() const{}

//class PrintWatchHistory : public BaseAction {
    void PrintWatchHistory::act (Session& sess){}
    std::string PrintWatchHistory::toString() const{}



//class Watch : public BaseAction {
    void Watch::act(Session& sess){}
    std::string Watch::toString() const{;}


//class PrintActionsLog : public BaseAction {
    void PrintActionsLog::act(Session& sess){}
    std::string PrintActionsLog::toString() const{}


//class Exit : public BaseAction {
    void Exit::act(Session& sess){}
    std::string Exit::toString() const{}


