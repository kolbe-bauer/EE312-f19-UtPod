//
// Created by Kolbe on 10/24/2019.
//

#include <iostream>
#include <cstdlib>
#include <fstream>
#include <string>
#include "Song.h"

using namespace std;

class Song {
private:
    char *title;
    char *artist;
    int size;

public:
    Song(char *t,char *a, int s){
        title=t;
        artist=a;
        size=s;
    }
    void setTitle(const char *t){
        strcpy()
    }
    char* getTitle(){
        return title;
    }
    void setArtist(const char *a){

    }
    char* getArtist(){

    }
    void setSize(const int s){

    }
    int getSize(){

    }

    //override = < >
}