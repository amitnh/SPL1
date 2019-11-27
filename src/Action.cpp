//
// Created by amit on 11/25/19.
//
#include <string>
#include <iostream>
#include "../include/Session.h"
#include "../include/Action.h"


//enum ActionStatus{PENDING, COMPLETED, ERROR}

//class BaseAction::{
    BaseAction::BaseAction():status{PENDING}{}

void BaseAction::complete() {

}

void BaseAction::error(const std::string &errorMsg) {

}

ActionStatus BaseAction::getStatus() const {
    return status;
}

std::string toString(){}
    void complete(){}
    void error(const std::string& errorMsg){}
    std::string getErrorMsg(){}
    std::string errorMsg;
    ActionStatus status;


//class CreateUser  : public BaseAction {
    void CreateUser::act(Session& sess)
    {
        //std::string user_name,recommendation_algorithm;
        //sess.addUser();
        std::vector<std::string> command = sess.get_command();
        if (command.at(2)!="len"|command.at(2)!="rer"|command.at(2)!="gen") {
            //error
        }
    }
    std::string CreateUser::toString() const
    {
       // cout<< "CreateUser " + CreateUser.toString();
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


