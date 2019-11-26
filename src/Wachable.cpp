//
// Created by amit on 11/25/19.
//
#include <string>
#include <vector>

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
}
