#ifndef USER_H_
#define USER_H_

#include <vector>
#include <string>
#include <unordered_set>
#include <unordered_map>
class Watchable;
class Session;

class User{
public:
    User(const std::string& name);
    virtual Watchable* getRecommendation(Session& s) = 0;
    virtual User* clone()=0;
    std::string getName() const;
    std::vector<Watchable*> get_history() const;
    bool searchinhistory(int id);
protected:
    std::vector<Watchable*> history;
private:
    const std::string name;

};


class LengthRecommenderUser : public User {
public:
    LengthRecommenderUser(const std::string& name);
    virtual Watchable* getRecommendation(Session& s);
    LengthRecommenderUser* clone();
    int get_avg_his_length();
    void set_avg_his_length(int new_average);
private:
    int avg_his_length; //minutes average
};

class RerunRecommenderUser : public User {
public:
    RerunRecommenderUser(const std::string& name);
    virtual Watchable* getRecommendation(Session& s);
    RerunRecommenderUser* clone();

    void set_current_id_towatch(int id);

    int get_current_id_towatch();

private:
    int current_id_towatch;
};

class GenreRecommenderUser : public User {
public:
    GenreRecommenderUser(const std::string& name);
    virtual Watchable* getRecommendation(Session& s);
    GenreRecommenderUser* clone();
    static bool sortbysec(const std::pair<std::string,int> &a, const std::pair<std::string,int> &b);


private:
    std::vector< std::pair<std::string,int>> favorite_tags;
};

#endif
