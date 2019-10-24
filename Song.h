//DOCUMETN HERE

#ifndef SONG_H
#define SONG_H
#include <string>
#include <iostream>

using namespace std;

//Song class declaration
class Song {
private:
    string title;
    string artist;
    int size;

public:
    Song(string t,string a, int s);
    void setTitle(const string t);
    string getTitle();
    void setArtist(const string a);
    string getArtist();
    void setSize(const int s);
    int getSize();

    bool operator >(Song const &rhs);
    bool operator ==(Song const &rhs);
    bool operator <(Song const &rhs);

    ~Song();
};

ostream& operator << (ostream& out,const Song &s);

#endif