#ifndef PLAYER_STATE_H
#define PLAYER_STATE_H

typedef struct MusicPlayer MusicPlayer;
typedef struct PlayerState {
    void (*pressPlay)(MusicPlayer *player);
    void (*pressPause)(MusicPlayer *player);
    void (*pressStop)(MusicPlayer *player);
} PlayerState;

#endif // PLAYER_STATE_H