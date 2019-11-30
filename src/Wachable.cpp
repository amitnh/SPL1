//
// Created by amit on 11/25/19.
//
#include <string>
#include <vector>
#include "../include/Watchable.h"
#include "../include/Session.h"
#include "../include/User.h"
using namespace std;


Watchable::Watchable(long id, int length, const std::vector<std::string> &tags):id{id},length{length},tags{tags}{}
Watchable::~Watchable() {

}

vector<std::string>  Watchable::get_tags() const {
    return tags;
}

long Watchable::get_id() const {
    return id;
}

int Watchable::get_length() const {
    return length;
}

Movie::Movie(long id, const std::string &name, int length, const std::vector<std::string> &tags):Watchable(id,length,tags),name{name}{}

Watchable *Movie::getNextWatchable(Session &s) const {
    return s.get_activeUser().getRecommendation(s);
}

std::string Movie::toString() const {
    //<content_id> <content_name> <content_length>minutes[<tag_1>, <tag_2>, ..., <tag_n>]
    std::string s;
    s = to_string(this->get_id()+1) + ". " + this->get_name() + " " + to_string(this->get_length()) + " minutes [";
    for ( auto i : get_tags() ) // runs on all the vector in tags
        s +=  i + ", ";
    s = s.substr(0, s.size()-2); // remove the last ", "
    s+="]";
    return s;
}

std::string Movie::get_name() const {
    return name;
}

std::string Movie::get_full_name() const {
    return get_name();
}

Episode::Episode(long id, const std::string& seriesName,int length, int season, int episode ,const std::vector<std::string>& tags):Watchable(id,length,tags),season{season},episode{episode},seriesName{seriesName}{}

std::string Episode::toString() const {
    //<content_id> <content_name> <content_length>minutes[<tag_1>, <tag_2>, ..., <tag_n>]
    //s= +"S" + season.toString() + "E"+ episode.toString() + "[";

    std::string s;
    s = "\n" + to_string(this->get_id()+1) + ". " + this->get_name() + " " + to_string(this->get_length()) + " minutes S" + to_string(get_season()) +"E" + to_string(get_episode()) +" [";

    for ( auto i : get_tags() ) // runs on all the vector in tags
        s +=  i + ", ";
    s = s.substr(0, s.size()-2); // remove the last ", "
    s+="]";
    return s;
}

Watchable *Episode::getNextWatchable(Session &s) const {
    int cur_id = get_id();
    if (cur_id < s.get_contant().size()) {
        if (s.get_contant().at(cur_id + 1)->get_name() == get_name())
            if (!s.get_activeUser().searchinhistory(cur_id + 1))
                return s.get_contant().at(cur_id + 1);
    }
    return s.get_activeUser().getRecommendation(s);
}


int Episode::get_season() const {
    return season;
}

int Episode::get_episode() const {
    return episode;
}

std::string Episode::get_name() const {
    return seriesName;
}

std::string Episode::get_full_name() const {
    return seriesName + " S"+to_string(season) +"E" +to_string(episode);
}


