#include <iostream>
#include <vector>
#include <iomanip>
#include "Playlist.h"
#include "Song.h"
using namespace std;

Playlist::Playlist() { //Default contructor
    playlistName = "none";
}

Playlist::Playlist(string name) { //2nd constructor
    playlistName = name;
}

string Playlist::GetName() { //Returns the customer's name
    return playlistName;
}

void Playlist::ListSongs() {
    for (unsigned int i = 0; i < playlistSongs.size(); i++) {
        cout << i << ": " << playlistSongs.at(i) -> GetName(); //Lists all the songs in a playlist
    }
}

void Playlist::AddSongToPlaylist(Songs* newSong) { //Adds the songs to playlist
    playlistSongs.push_back(newSong);
}

void Playlist::PlayPlaylist() { //Plays playlist
    for (unsigned int i = 0; i < playlistSongs.size(); i++) {
        playlistSongs.at(i)->PlaySong();
    }
}

void Playlist::RemoveSongFromPlaylist(int songIndex) {
    playlistSongs.erase(playlistSongs.begin() + songIndex); //Removes the pointer but leaves the song intact
}

void Playlist::RemoveSongFromPlaylist(Songs* songPtr) {
    for (unsigned int i = 0; i < playlistSongs.size(); i++) {
        if (songPtr == playlistSongs.at(i)) {
            playlistSongs.erase(playlistSongs.begin() + i); //Removes the song from the playlist
            --i;
        }
    }
}

