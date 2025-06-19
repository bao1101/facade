#ifndef MUSIC_PLAYER_H
#define MUSIC_PLAYER_H

#include <stdio.h>
#include "PlayerState.h"

typedef struct MusicPlayer {
    PlayerState *state;
} MusicPlayer;

void changeState(MusicPlayer *player, PlayerState *newState) {
    player->state = newState;
}

void clickPlayButton(MusicPlayer *player) {
    player->state->pressPlay(player);
}

void clickPauseButton(MusicPlayer *player) {
    player->state->pressPause(player);
}

void clickStopButton(MusicPlayer *player) {
    player->state->pressStop(player);
}

#endif // MUSIC_PLAYER_H