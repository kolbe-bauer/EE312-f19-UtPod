//
// Created by Kolbe on 10/24/2019.
//

#include "Song.h"

using namespace std;

Song::Song(){
    title="";
    artist="";
    size=0;
}
Song::Song(string t, string a, int s) {
    title=t;
    artist=a;
    size=s;
}
int Song::getSize() const { return size;}
string Song::getArtist() const { return artist;}
string Song::getTitle() const { return title;}
void Song::setArtist(const string a) {artist=a;}
void Song::setSize(const int s) {size=s;}
void Song::setTitle(const string t) {title=t;}

bool Song::operator==(Song const &rhs) {
    return title==rhs.title && artist==rhs.artist && size==rhs.size;
}
bool Song::operator>(Song const &rhs) {
    if(artist==rhs.artist){
        if(title==rhs.title)
            return size>rhs.size;
        return title>rhs.title;
    }
    return artist>rhs.artist;
}
bool Song::operator<(Song const &rhs) {
    if(artist==rhs.artist){
        if(title==rhs.title)
            return size<rhs.size;
        return title<rhs.title;
    }
    return artist<rhs.artist;
}

ostream& operator << (ostream& out, const Song &s)
{
    out << "Song Title: " << s.getTitle() << "; ";
    out << "Song Artist: " << s.getArtist() << "; ";
    out << "Song Size: " << s.getSize() ;
    return out;
}
Song::~Song() {
    //cout << "debug - in destructor for " << title << endl;
}