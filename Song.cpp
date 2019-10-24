//
// Created by Kolbe on 10/24/2019.
//

#include "Song.h"

using namespace std;

Song::Song(string t, string a, int s) {
    title=t;
    artist=a;
    size=s;
}
int Song::getSize() { return size;}
string Song::getArtist() { return artist;}
string Song::getTitle() { return title;}
void Song::setArtist(const string a) {artist=a;}
void Song::setSize(const int s) {size=s;}
void Song::setTitle(const string t) {title=t;}

bool Song::operator==(Song const &rhs) {
    return title==rhs.title && artist==rhs.artist && size==rhs.size;
}
bool Song::operator>(Song const &rhs) {
    if(title==rhs.title){
        if(artist==rhs.artist)
            return size>rhs.size;
        return artist>rhs.artist;
    }
    return title>rhs.title
}
bool Song::operator<(Song const &rhs) {
    if(title==rhs.title){
        if(artist==rhs.artist)
            return size<rhs.size;
        return artist<rhs.artist;
    }
    return title<rhs.title
}

Song::~Song() {
    cout << "debug - in destructor for " << title << endl;
}
