//
// Created by Kolbe on 10/24/2019.
//

#include <iostream>
#include <fstream>
#include <string>
#include <cstdlib>
#include "UtPod.h"
#include "Song.h"

using namespace std;

int main(){
    cout << "Hello World!" << endl;

    Song dhiraj("Manukonda","dm48254",420);
    //string const s=dhiraj.getArtist();
    //cout << "Dhiraj title: " << dhiraj.getTitle() << endl;
    //cout << "Dhiraj artist: " << dhiraj.getArtist() << endl;
    //cout << "Dhiraj size: " << dhiraj.getSize() << endl;
    cout << dhiraj << endl;
    dhiraj.setSize(69);
    //cout << "after setting size " << dhiraj.getSize() << endl;
    cout << dhiraj << endl;
    dhiraj.setTitle("DHIRAJ");
    //cout << "after setting title " << dhiraj.getTitle() << endl;
    cout << dhiraj << endl;

    Song kolbe("kolbe","dm48254",69);
    cout << kolbe << endl;
    bool test=dhiraj==kolbe;
    cout << "are Kolbe and Dhiraj the same? " << test << endl;
    test=dhiraj<kolbe;
    cout << "is dhiraj greater than kolbe? " << test << endl;

    UtPod mayank;
    UtPod ben(42);
    UtPod yaash(-1);
    UtPod harish(690);
    UtPod rithvik(0);

    cout << "mayank memory: " << mayank.getTotalMemory() << endl;
    cout << "mayank memory: " << ben.getRemainingMemory() << endl;
    cout << "mayank memory: " << yaash.getRemainingMemory() << endl;
    cout << "mayank memory: " << harish.getRemainingMemory() << endl;
    cout << "mayank memory: " << rithvik.getRemainingMemory() << endl;

    mayank.addSong(dhiraj);
    mayank.addSong(kolbe);
    cout << "ben memory: " << mayank.getRemainingMemory() << endl;
    mayank.showSongList();
    //mayank.removeSong(dhiraj);
    //mayank.showSongList();
    //cout << "ben memory: " << mayank.getRemainingMemory() << endl;
    //mayank.removeSong(dhiraj);
    //mayank.showSongList();
    mayank.clearMemory();
    //cout << "ben memory: " << mayank.getRemainingMemory() << endl;
    mayank.showSongList();

    return 0;
}