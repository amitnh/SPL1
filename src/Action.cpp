//
// Created by amit on 11/25/19.
//
#include <string>
#include <iostream>
#include "../include/Session.h"

enum ActionStatus{PENDING, COMPLETED, ERROR}

class BaseAction{
public:
    BaseAction():status{PENDING}{}
    ActionStatus getStatus(){ }
    virtual void act(Session& sess){}
    virtual std::string toString(){}
protected:
    void complete(){}
    void error(const std::string& errorMsg){}
    std::string getErrorMsg(){}
private:
    std::string errorMsg;
    ActionStatus status;
};

class CreateUser  : public BaseAction {
public:
    virtual void act(Session& sess)
    {
        std::string user_name,recommendation_algorithm;
        sess.addUser()
    }
    virtual std::string toString()
    {
        cout<< "CreateUser " + CreateUser.status.toString();
    }
}

class ChangeActiveUser : public BaseAction {
public:
    virtual void act(Session& sess);
    virtual std::string toString() const;
}

class DeleteUser : public BaseAction {
public:
    virtual void act(Session & sess);
    virtual std::string toString() const;
}


class DuplicateUser : public BaseAction {
public:
    virtual void act(Session & sess);
    virtual std::string toString() const;
}

class PrintContentList : public BaseAction {
public:
    virtual void act (Session& sess);
    virtual std::string toString() const;
}

class PrintWatchHistory : public BaseAction {
public:
    virtual void act (Session& sess);
    virtual std::string toString() const;
}


class Watch : public BaseAction {
public:
    virtual void act(Session& sess);
    virtual std::string toString() const;
}


class PrintActionsLog : public BaseAction {
public:
    virtual void act(Session& sess);
    virtual std::string toString() const;
}

class Exit : public BaseAction {
public:
    virtual void act(Session& sess);
    virtual std::string toString() const;
}

