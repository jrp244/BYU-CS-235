#ifndef Song_H
#define Song_H
#include <string>
using namespace std;

class Songs {
public:
//All of these functions manipulate info about a song
    void SetName (string);
    string GetName ();
    void SetDescription (string);
    void PrintSong ();
    void PlaySong ();
    Songs (); //Default constructor
    Songs (string name, string description); //Constructor with arguments
private:
    string songName;
    string songDescription; //Description of an item
    int songCount;
};

#endif