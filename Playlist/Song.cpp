#include "Song.h"
#include <string>
#include <iostream>
using namespace std;

Songs::Songs() {  // Default constructor
    songName = "none";// Default name: NoName indicates name was not set
    songDescription = "none";
    songCount = 0;
}

Songs::Songs (string name, string description) { //constructor to initialize variables
    songName = name;
    songDescription = description;
    songCount = 0;
}

void Songs::SetName (string name) {
    songName = name;
}

string Songs::GetName () {
    return songName;
}

void Songs::SetDescription (string description) {
    songDescription = description;
}

void Songs::PrintSong () {
    cout << songName << ": \"" << endl;
    cout << songDescription << "\", " << endl;
    cout << songCount << " play(s)." << endl;
}

void Songs::PlaySong () { //Plays the songs
    cout << songDescription << endl;
    ++songCount;
}
