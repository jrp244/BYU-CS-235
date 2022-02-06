#ifndef Playlist_H
#define Playlist_H
#include <string>
#include <vector>
#include "Song.h"
using namespace std;

class Playlist {
public:
//All of these functions manipulate the playlist
    string GetName ();
    void ListSongs ();
    void AddSongToPlaylist (Songs* newSong);
    void ListPlaylists (string);
    void PlayPlaylist ();
    void RemovePlaylist (string);
    void RemoveSongFromPlaylist (int);
    void RemoveSongFromPlaylist(Songs*);
    Playlist (); //Default constructor
    Playlist (string name); //Constructor with arguments
private:
    string playlistName;
    vector <Songs*> playlistSongs;
};

#endif