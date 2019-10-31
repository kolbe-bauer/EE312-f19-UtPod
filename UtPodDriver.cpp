/* utPod_driver.cpp
Demo Driver for the UtPod.

Roger Priebe
EE 312 10/16/18

This is a basic driver for the UtPod.

You will want to do more complete testing.

*/
#include <cstdlib>
#include <iostream>
#include "Song.h"
#include "UtPod.h"

using namespace std;

int main(int argc, char *argv[])
{
    UtPod t;

    Song s1("Beatles", "Hey Jude1", 4);
    int result = t.addSong(s1);
    cout << "result = " << result << endl;

    t.showSongList();

    Song s2("Beatles", "Hey Jude2", 5);
    result = t.addSong(s2);
    cout << "result = " << result << endl;

    t.showSongList();

    Song s3("Beatles", "Hey Jude3", 6);
    result = t.addSong(s3);
    cout << "result = " << result << endl;

    Song s4("Beatles", "Hey Jude4", 7);
    result = t.addSong(s4);
    cout << "result = " << result << endl;

    Song s5("Beatles", "Hey Jude5", 241);
    result = t.addSong(s5);
    cout << "add result = " << result << endl;

    t.showSongList();

    result = t.removeSong(s2);
    cout << "delete result = " << result << endl;

    result = t.removeSong(s3);
    cout << "delete result = " << result << endl;

    t.showSongList();

    result = t.removeSong(s1);
    cout << "delete result = " << result << endl;

    result = t.removeSong(s5);
    cout << "delete result = " << result << endl;

    result = t.removeSong(s4);
    cout << "delete result = " << result << endl;


    t.showSongList();

    result = t.addSong(s5);
    cout << "add result = " << result << endl;

    t.showSongList();
    cout << "memory = " << t.getRemainingMemory() << endl;
    //  ///////////////////////////////////////////////////////////////////////

    Song d1("Maroon 5","Memories",20);
    Song d2("Post Malone","Circles",20);
    Song d3("Kanye","Follow God",20);
    Song d4("Camia Cabello","Liar",20);
    Song d5("Normani","Motivation",20);
    Song d6("Young Thug","Hot",20);
    Song d7("Playboi Carti","Magnolia",20);
    Song d8("21 Savage","alot",20);
    Song d9("DaBaby","Suge",20);
    Song d10("Lil Skies","Magic",20);

    Song d11("Rich Brian","Seventeen",20);
    Song d12("Maroon 5","Sugar",20);
    Song d13("Camia Cabello","Havana",20);
    Song d14("EDEN","Circles",20);
    Song d15("Yung Gravy","Magic",20);

    //20*10=200
    UtPod k1(200);
    cout << "Starting UTPod Memory: " << k1.getTotalMemory() << endl;
    k1.addSong(d1);
    k1.addSong(d2);
    k1.addSong(d3);
    k1.addSong(d4);
    k1.addSong(d5);
    k1.addSong(d6);
    k1.addSong(d7);
    k1.addSong(d8);
    k1.addSong(d9);
    k1.addSong(d10);
    cout << "Ten Songs Added to UTPod" << endl;
    k1.showSongList();
    cout << "Remaining memory in UTPod: "<< k1.getRemainingMemory() << endl;
    cout << "Try to add 11th Song: " << d11 << endl;
    k1.addSong(d11);
    cout << "Now UTPod includes songs: " << endl;
    k1.showSongList();

    cout << "UTPod's songs sorted: " << endl;
    k1.sortSongList();
    k1.showSongList();

    cout << "UTPod's songs shuffled/randomized: " << endl;
    for(int i=0;i<10;i++)
        k1.shuffle();
    k1.showSongList();

    cout << "UTPod's songs sorted: " << endl;
    k1.sortSongList();
    k1.showSongList();

    cout << "Remove the following five songs: " << endl;
    cout << d10 << endl;
    cout << d9 << endl;
    cout << d8 << endl;
    cout << d7 << endl;
    cout << d6 << endl;
    k1.removeSong(d10);
    k1.removeSong(d9);
    k1.removeSong(d8);
    k1.removeSong(d7);
    k1.removeSong(d6);
    cout << "Songs in UTPod are now: " << endl;
    k1.showSongList();

    cout << "Now add these five songs to UTPod: " << endl;
    cout << d12 << endl;
    cout << d13 << endl;
    cout << d14 << endl;
    cout << d15 << endl;
    cout << d1 << endl;
    k1.addSong(d1);
    k1.addSong(d12);
    k1.addSong(d13);
    k1.addSong(d14);
    k1.addSong(d15);
    cout << "Songs in UTPod are now: " << endl;
    k1.showSongList();

    cout << "UTPod's songs sorted: " << endl;
    k1.sortSongList();
    k1.showSongList();

    cout << "UTPod's songs shuffled/randomized: " << endl;
    for(int i=0;i<10;i++)
        k1.shuffle();
    k1.showSongList();

    cout << "Removing a song removes it's first instance" << endl;
    cout << "Remove: " << d1 << endl;
    k1.removeSong(d1);
    cout << "Now songs in UTPod are: " << endl;
    k1.showSongList();

    cout << "UTPod's songs sorted: " << endl;
    k1.sortSongList();
    k1.showSongList();

    cout << "And the remaining memory in our UTPod is: " << k1.getRemainingMemory() << endl;

}