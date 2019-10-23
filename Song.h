//DOCUMETN HERE

#ifndef SONG_H
#define SONG_H
#include "UtPod.h"

//Song class declaration
class Song {
private:
    char *title;
    char *artist;
    int size;

public:
    Song(char *t,char *a, int s);
    void setTitle(const char *t);
    char* getTitle();
    void setArtist(const char *a);
    char* getArtist();
    void setSize(const int s);
    int getSize();

    //override = < >
};

#endif