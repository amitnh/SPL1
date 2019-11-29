//
// Created by amit on 11/25/19.
//
#include <string>
#include <iostream>
#include "../include/Session.h"
#include "../include/Action.h"
#include "../include/User.h"
#include "../include/Watchable.h"
using namespace std;

//enum ActionStatus{PENDING, COMPLETED, ERROR}

//class BaseAction::{
    BaseAction::BaseAction():status{PENDING},errorMsg{""}{
}

void BaseAction::complete() {
status=COMPLETED;
}

void BaseAction::error(const std::string &errorMsg) {
    this->errorMsg=errorMsg;
    std::cout<<errorMsg;
    status==ERROR;
}

ActionStatus BaseAction::getStatus() const {
    return status;
}

std::string BaseAction::getStatusString(ActionStatus status) const {
    if (status == 0)
        return "PENDING";
    if (status==1)
        return "COMPLETED";
    if (status==2)
        return "ERROR";
}

std::string BaseAction::get_errorMsg() const {
    return errorMsg;
}

//class CreateUser  : public BaseAction {
    void CreateUser::act(Session& sess)
    {
        sess.add_actionlog(*this);
        std::vector<std::string> command = sess.get_command();
        if ((int)command.size()<3)
            error("The command is too short for Create User action");
        else if (command.at(2).compare("len")*command.at(2).compare("rer")*command.at(2).compare("gen")!=0) {
            error("Wrong recommendation algorithm, use only 'len','gen' or 'rer' ");
        }
        else if (sess.isTaken(command.at(1))){
            error("Name already exists");
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
        string s = "CreateUser "  + getStatusString(getStatus());
        if (get_errorMsg()!="")
            s+=":" + get_errorMsg();
        return s;
    }

//class ChangeActiveUser : public BaseAction {
    void ChangeActiveUser::act(Session& sess){
        sess.add_actionlog(*this);
        std::vector<std::string> command = sess.get_command();
        if ((int)command.size()<2)
            error("The command is too short for the action");
        else if (!sess.isTaken(command.at(1))) {
            error("This user name is not in the system");
        }
        else
        {
            sess.set_activeUser(command.at(1));
            complete();
        }
    }
    std::string ChangeActiveUser::toString() const {
        string s = "ChangeUser "  + getStatusString(getStatus());
        if (get_errorMsg()!="")
            s+=":" + get_errorMsg();
        return s;
    }

//class DeleteUser : public BaseAction {
    void DeleteUser::act(Session & sess){
    sess.add_actionlog(*this);
    std::vector<std::string> command = sess.get_command();
    if ((int)command.size()<2)
        error("The command is too short for the action");
    else if (!sess.isTaken(command.at(1))) {
        error("This user name is not in the system");
    }
    else
    {
        sess.delete_user(command.at(1));
        complete();
    }
}

    std::string DeleteUser::toString() const {
        std::string s = "deleteuser "  + getStatusString(getStatus());
        if (get_errorMsg()!="")
            s+=":" + get_errorMsg();
        return s;
    }


//class DuplicateUser : public BaseAction {
    void DuplicateUser::act(Session & sess){
    sess.add_actionlog(*this);
    std::vector<std::string> command = sess.get_command();
    if ((int)command.size()<3)
        error("The command is too short for the action");
    else if (!sess.isTaken(command.at(1))) {
        error("This user is not in the system");}
    else if (sess.isTaken(command.at(2))) {
        error("This user name is taken already");
    }
    else
    {
        User* newUser = sess.get_user_by_name(command.at(1)).clone();

        sess.add_user(newUser);
        sess.delete_user(command.at(1));
        complete();
    }
    } //make DuplicateUser var here in "act", to pull Name1 name2 from the start method
    std::string DuplicateUser::toString() const{
        string s = "DuplicateUser "  + getStatusString(getStatus());
        if (get_errorMsg()!="")
            s+=":" + get_errorMsg();
        return s;
    }


//class PrintContentList : public BaseAction {
    void PrintContentList::act (Session& sess){
    std::vector<Watchable*>& content =  sess.get_content();
    for(auto v: content)
    {
        cout<<v->toString()<<endl;
    }
    }
    std::string PrintContentList::toString() const{
        string s = "PrintContentList "  + getStatusString(getStatus());
        if (get_errorMsg()!="")
            s+=":" + get_errorMsg();
        return s;
    }

//class PrintWatchHistory : public BaseAction {
    void PrintWatchHistory::act (Session& sess){}
    std::string PrintWatchHistory::toString() const{}


//class Watch : public BaseAction {
    void Watch::act(Session& sess){}
    std::string Watch::toString() const{;}


//class PrintActionsLog : public BaseAction {
    void PrintActionsLog::act(Session& sess){
    std::vector<BaseAction*>& actionlogvec =  sess.get_actionsLog();
    for(auto v: actionlogvec)
    {
        cout<<v->toString()<<endl;
    }
}
    std::string PrintActionsLog::toString() const{}


//class Exit : public BaseAction {
    void Exit::act(Session& sess){}
    std::string Exit::toString() const{}


