//
// Created by amit on 11/25/19.
//
#include <string>
#include <vector>
#include "../include/Watchable.h"
#include "../include/Session.h"
#include "../include/User.h"

/*
class Watchable{
public:
    Watchable(long id, int length, const std::vector<std::string>& tags):id{id},length{length},tags{tags}{}
    virtual ~Watchable()
    {
        for ( auto i : tags ) // runs on all the vector in tags
            delete i;
    }
    virtual std::string toString() const = 0;
    virtual Watchable* getNextWatchable(Session&) const = 0;
private:
    const long id;
    int length;
    std::vector<std::string> tags;
}

class Movie : public Watchable{
public:
    Movie(long id, const std::string& name, int length, const std::vector<std::string>& tags):Watchable(id,length,tags),name{name}{}
    virtual std::string toString() const
    {
        //<content_id> <content_name> <content_length>minutes[<tag_1>, <tag_2>, ..., <tag_n>]
        cout << "\n" + this.id.toString() + this.*name + this->length.toString() + "[";
        for ( auto i : tags ) // runs on all the vector in tags
            cout << i.toString() + ", ";
        cout << "]";
    }
    virtual Watchable* getNextWatchable(Session&)
    {
        Session* s = this;
        return s*.getActiveUser().getRecommendation();
    }
private:
    std::string name;
}

class Episode: public Watchable{
public:
    Episode(long id, const std::string& seriesName,int length, int season, int episode ,const std::vector<std::string>& tags):Watchable(id,length,tags),season{season},episode{episode},seriesName{seriesName}{}
    virtual std::string toString() const
    {
        //<content_id> <content_name> <content_length>minutes[<tag_1>, <tag_2>, ..., <tag_n>]
        cout << "\n" + this.id.toString() + this.*seriesName + this->length.toString() +"S" + season.toString() + "E"+ episode.toString() + "[";
        for ( auto i : tags ) // runs on all the vector in tags
            cout << i.toString() + ", ";
        cout<< "]";
    }
    virtual Watchable* getNextWatchable(Session&)
    {

    }
private:
    std::string seriesName;
    int season;
    int episode;
    long nextEpisodeId;
}*/
Watchable::Watchable(long id, int length, const std::vector<std::string> &tags):id{id},length{length},tags{tags}{}
Watchable::~Watchable() {

}

std::vector<std::string> &Watchable::get_tags() {
    return tags;
}

const long Watchable::get_id(){
    return id;
}

int Watchable::get_length() {
    return length;
}

Movie::Movie(long id, const std::string &name, int length, const std::vector<std::string> &tags):Watchable(id,length,tags),name{name}{}

Watchable *Movie::getNextWatchable(Session &s) const {
    return s.get_activeUser().getRecommendation(s);
}

std::string Movie::toString() const {
    //<content_id> <content_name> <content_length>minutes[<tag_1>, <tag_2>, ..., <tag_n>]
    std::string s;
    s = "\n" + this->get_id().toString() + this.*name + this->get_length().toString() + "[";
    for ( auto i : get_tags() ) // runs on all the vector in tags
        s+= i.toString() + ", ";
    s = s.substr(0, myString.size()-2); // remove the last ", "
    s+="]";
    return s;
}
Episode::Episode(long id, const std::string& seriesName,int length, int season, int episode ,const std::vector<std::string>& tags):Watchable(id,length,tags),season{season},episode{episode},seriesName{seriesName}{}

const std::vector<std::string> &tags) {

}

std::string Episode::toString() const {
    //<content_id> <content_name> <content_length>minutes[<tag_1>, <tag_2>, ..., <tag_n>]
    std::string s;
    s= "\n" + this.id.toString() + this.*seriesName + this->length.toString() +"S" + season.toString() + "E"+ episode.toString() + "[";
    for ( auto i : tags ) // runs on all the vector in tags
       s+= i.toString() + ", ";
    s = s.substr(0, myString.size()-2); // remove the last ", "
    s+="]";
    return s;
}

Watchable *Episode::getNextWatchable(Session &s) const {
    return s.get_activeUser().getRecommendation(s);

}


