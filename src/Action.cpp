//
// Created by amit on 11/25/19.
//
#include <string>
#include <iostream>
#include <sstream>
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
        User* newUser = sess.get_user_by_name(command.at(1))->clone(command.at(2));
        sess.add_user(newUser);
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
    sess.add_actionlog(*this);
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
    void PrintWatchHistory::act (Session& sess){
    sess.add_actionlog(*this);
    std::vector<Watchable*>& history =  sess.get_activeUser().get_history();
    cout<<"Watch history for " + sess.get_activeUser().getName()<<endl;
    if (history.empty())
        cout<< "There is no watching history"<<endl;
    else {
        int index = 1;
        for (auto h: history) {
            cout << std::to_string(index) + ". " + h->get_full_name() << endl;
            index++;
        }
    }
    complete();
    }

    std::string PrintWatchHistory::toString() const{
        string s = "PrintWatchHistory "  + getStatusString(getStatus());
        if (get_errorMsg()!="")
            s+=":" + get_errorMsg();
        return s;
    }


//class Watch : public BaseAction {
    void Watch::act(Session& sess){
    sess.add_actionlog(*this);
    std::vector<std::string> command = sess.get_command();

    if ((int)command.size()<2)
        error("The command is too short for the action");
    else {
        stringstream id_s(command.at(1));
        int id = 0;
        try { id_s >> id; }
        catch (const std::exception &e) { error("please choose a correct Id number"); }
        if (id >= sess.get_content().size()) {
            error("Id out of bounds");
        }
        else {
            cout << "Watching " + sess.get_content().at(id)->toString() << endl; // print watching on screen
            sess.get_activeUser().get_history().push_back(sess.get_content().at(id)); // add to history
            Watchable* recommend = sess.get_content().at(id)->getNextWatchable(sess);
            cout << "We recommend watching " + recommend->toString() + ", continue watching ? [y/n]" << endl;
            string input;
            std::getline(std::cin, input); // waits for y/n
            if (input == "y") {
                BaseAction *action = new Watch();
                command.at(1)=to_string(recommend->get_id());
                sess.set_command(command);

                complete();
                action->act(sess);
            }
            complete();
        }
    }
    }
    std::string Watch::toString() const{
        string s = "Watch "  + getStatusString(getStatus());
        if (get_errorMsg()!="")
            s+=":" + get_errorMsg();
        return s;
    }


//class PrintActionsLog : public BaseAction {
    void PrintActionsLog::act(Session& sess){
    std::vector<BaseAction*>& actionlogvec =  sess.get_actionsLog();
    for(auto v: actionlogvec)
    {
        cout<<v->toString()<<endl;
    }
}
    std::string PrintActionsLog::toString() const{
        string s = "PrintActionsLog "  + getStatusString(getStatus());
        if (get_errorMsg()!="")
            s+=":" + get_errorMsg();
        return s;
    }


//class Exit : public BaseAction {
    void Exit::act(Session& sess){}
    std::string Exit::toString() const{
        string s = "Exit "  + getStatusString(getStatus());
        if (get_errorMsg()!="")
            s+=":" + get_errorMsg();
        return s;
    }


