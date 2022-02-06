//A Note regarding 'using namespace std':
// The author of this code prefers to not have the line 'using namespace std;'
// Instead, you will see 'std::' in front of string, cout, and other identifiers
// You could put 'using namespace std;' at the top of your code and not need 'std::' in front of these words,
// but many people consider it better practice to not have 'using namespace std;'


#include <iostream>
#include <string>
#include <vector>
#include "Song.h"
#include "Playlist.h"
#include <algorithm>
#include <iomanip>

std::string GetUserString(const std::string& prompt);
//Function declarations
void AddSongsMenuOption(vector <Songs*> &allSongs);
void ListSongsMenuOption(vector <Songs*> &allSongs);
void AddPlaylistMenuOption(vector <Playlist> &allPlaylist);
void AddSongToPlaylistMenuOption(vector <Playlist> &allPlaylist, vector <Songs*> &allSongs);
void ListPlaylistsMenuOption(vector <Playlist> &allPlaylist);
void PlayPlaylistMenuOption(vector <Playlist> &allPlaylist);
void RemovePlaylistMenuOption(vector <Playlist> &allPlaylist);
void RemoveSongFromPlaylistMenuOption(vector <Playlist> &allPlaylist, vector <Songs*> &allSongs);
void RemoveSongFromLibraryMenuOption(vector <Songs*> &allSongs, vector <Playlist> &allPlaylist);
void OptionsMenuOption();
void QuitMenuOption();

int main() {
    std::cout << "Welcome to the Firstline Player!  Enter options to see menu options." << std::endl << std::endl;

    vector <Songs*> allSongs; //Vector for the library of songs
    vector <Playlist> allPlaylist; //Vector of all of the different playlists

    std::string userMenuChoice = "none";
    bool continueMenuLoop = true;

    while (continueMenuLoop) {  //Menu
        userMenuChoice = GetUserString("Enter your selection now: ");

        if (userMenuChoice == "add") {
            AddSongsMenuOption(allSongs);
        }
        else if (userMenuChoice == "list") {
            ListSongsMenuOption(allSongs);
        }
        else if (userMenuChoice == "addp") {
            AddPlaylistMenuOption(allPlaylist);
        }
        else if (userMenuChoice == "addsp") {
            AddSongToPlaylistMenuOption(allPlaylist, allSongs);
        }
        else if (userMenuChoice == "listp") {
            ListPlaylistsMenuOption(allPlaylist);
        }
        else if (userMenuChoice == "play") {
            PlayPlaylistMenuOption(allPlaylist);
        }
        else if (userMenuChoice == "remp") {
            RemovePlaylistMenuOption(allPlaylist);
        }
        else if (userMenuChoice == "remsp") {
            RemoveSongFromPlaylistMenuOption(allPlaylist, allSongs);
        }
        else if (userMenuChoice == "remsl") {
            RemoveSongFromLibraryMenuOption(allSongs, allPlaylist);
        }
        else if (userMenuChoice == "options") {
            OptionsMenuOption();
        }
        else if (userMenuChoice == "quit") {
            QuitMenuOption();
            continueMenuLoop = false;
        }
        else {
            OptionsMenuOption();
        }
    }
    for (unsigned int i = 0; i < allSongs.size(); i++) {
        delete allSongs.at(i); //Deletes the song name and first line
    }

    return 0;
}


std::string GetUserString(const std::string& prompt) {
    std::string userAnswer = "none";
    std::cout << prompt;
    std::getline(std::cin, userAnswer);
    std::cout << std::endl;
    return userAnswer;
}
int GetUserInt(const std::string& prompt) {
    int userAnswer = 0;
    std::cout << prompt;
    std::cin >> userAnswer;
    std::cin.ignore();
    std::cout << std::endl;
    return userAnswer;
}

void AddSongsMenuOption(vector <Songs*> &allSongs) {
    const std::string DONE_KEYWORD = "DONE";
    std::cout << "Enter songs' names and first lines"
              << " (type \"" << DONE_KEYWORD << "\" when done):" << std::endl;

    std::string songName = "none";
    std::string firstLine = "none";

    songName = GetUserString("Song Name: ");
    while (songName != DONE_KEYWORD) {
        firstLine = GetUserString("Song's first line: ");
        //Creates a Song using `songName` and `firstLine` and add it to the allSongs vector
        Songs* newSong = new Songs(songName, firstLine);
        allSongs.push_back(newSong);
        songName = GetUserString("Song Name: ");
    }
}

void ListSongsMenuOption(vector <Songs*> &allSongs) {
    //Takes the vector of pointers and access each member and print out their info through a class function.
    for (unsigned int i = 0; i < allSongs.size(); i++) {
        allSongs.at(i)->PrintSong();
    }
}

void AddPlaylistMenuOption(vector <Playlist> &allPlaylist) {
    string playlistName = GetUserString("Playlist Name: "); //Gets the name from the user
    Playlist newPlaylist(playlistName); //Creates a new playlist
    allPlaylist.push_back(newPlaylist); //Creates a new instance of playlist in the vector
}

void AddSongToPlaylistMenuOption(vector <Playlist> &allPlaylist, vector <Songs*> &allSongs) {
    int playlistIndex = 0;
    int songIndex = 0;
    ListPlaylistsMenuOption(allPlaylist); //Lists the playlists
    playlistIndex =  GetUserInt("Pick a playlist index number: ");
    for (unsigned int i = 0; i < allSongs.size(); i++) {
        std::cout << i << ": " << allSongs.at(i) -> GetName() << std::endl;
    }//Lists the songs
    songIndex = GetUserInt("Pick a Song index number: ");
    allPlaylist.at(playlistIndex).AddSongToPlaylist(allSongs.at(songIndex)); 
    //Takes both index numbers and calls the function to add the song to the instance of the playlist.
}

void ListPlaylistsMenuOption(vector <Playlist> &allPlaylist) {
    for (unsigned int i = 0; i < allPlaylist.size(); i++) {
        string outputString = allPlaylist.at(i).GetName();
        std::cout << i << ": " << outputString << std::endl;
        //Outputs the info to the screen
    }
}

void PlayPlaylistMenuOption(vector <Playlist> &allPlaylist) {
    int playlistIndex = 0;
    ListPlaylistsMenuOption(allPlaylist); //Lists the playlists
    playlistIndex = GetUserInt("Pick a playlist index number: ");
    std::cout << "Playing songs from playlist: " << allPlaylist.at(playlistIndex).GetName() << std::endl;
    allPlaylist.at(playlistIndex).PlayPlaylist(); //Goes to the playlist.cpp function of play playlist
}

void RemovePlaylistMenuOption(vector <Playlist> &allPlaylist) {
    int playlistIndex = 0;
    ListPlaylistsMenuOption(allPlaylist); //Lists the playlists
    playlistIndex = GetUserInt ("Pick a playlist index number to remove: ");
    allPlaylist.erase(allPlaylist.begin() + playlistIndex); //Erases the playlist
}

void RemoveSongFromPlaylistMenuOption(vector <Playlist> &allPlaylist, vector <Songs*> &allSongs) {
    int playlistIndex = 0;
    ListPlaylistsMenuOption(allPlaylist); //Lists the playlists
    playlistIndex = GetUserInt("Pick a playlist index number: ");
    allPlaylist.at(playlistIndex).ListSongs(); //Lists the songs in the playlist
    int songIndex = 0;
    songIndex = GetUserInt("Pick a Song index number to remove: ");
    allPlaylist.at(playlistIndex).RemoveSongFromPlaylist(songIndex); //Removes the song from the playlist
}

void RemoveSongFromLibraryMenuOption(vector <Songs*> &allSongs, vector <Playlist> &allPlaylist) {
    int songIndex = 0;
    for (unsigned int i = 0; i < allSongs.size(); i++) {
        std::cout << i << ": " << allSongs.at(i)->GetName() << std::endl;
    }//Lists the songs
    songIndex = GetUserInt("Pick a Song index number to remove: ");
    for (unsigned int i = 0; i < allPlaylist.size(); i++) {
        allPlaylist.at(i).RemoveSongFromPlaylist(allSongs.at(songIndex));
    }
    delete allSongs.at(songIndex); //Deletes the song name and first line
    allSongs.erase(allSongs.begin() + songIndex);
    
}

void OptionsMenuOption() { //Lists the menu
    std::cout << "add      Adds a list of songs to the library" << std::endl
              << "list     Lists all the songs in the library" << std::endl
              << "addp     Adds a new playlist" << std::endl
              << "addsp    Adds a song to a playlist" << std::endl
              << "listp    Lists all the playlists" << std::endl
              << "play     Plays a playlist" << std::endl
              << "remp     Removes a playlist" << std::endl
              << "remsp    Removes a song from a playlist" << std::endl
              << "remsl    Removes a song from the library (and all playlists)" << std::endl
              << "options  Prints this options menu" << std::endl
              << "quit     Quits the program" << std::endl << std::endl;
}

void QuitMenuOption() { //Quits the program
    std::cout << "Goodbye!" << std::endl;
}

