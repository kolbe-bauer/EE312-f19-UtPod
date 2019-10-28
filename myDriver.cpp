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
    cout << "Dhiraj title: " << dhiraj.getTitle() << endl;
    cout << "Dhiraj artist: " << dhiraj.getArtist() << endl;
    cout << "Dhiraj size: " << dhiraj.getSize() << endl;
    dhiraj.setSize(69);
    cout << "after setting size " << dhiraj.getSize() << endl;
    dhiraj.setTitle("Kolbe");
    cout << "after setting title " << dhiraj.getTitle() << endl;

    Song kolbe("Kolbe","dm48254",69);
    bool test=dhiraj==kolbe;
    cout << "are Kolbe and Dhiraj the same? " << test << endl;
    test=dhiraj<kolbe;
    cout << "is dhiraj greater than kolbe? " << test << endl;

    return 0;
}