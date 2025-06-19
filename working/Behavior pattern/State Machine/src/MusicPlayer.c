#include "MusicPlayer.h"
#include <stdlib.h>

// StoppedState
void stoppedPressPlay(MusicPlayer *player);
void stoppedPressPause(MusicPlayer *player);
void stoppedPressStop(MusicPlayer *player);

PlayerState stoppedState = { stoppedPressPlay, stoppedPressPause, stoppedPressStop };

void stoppedPressPlay(MusicPlayer *player) {
    printf("Bắt đầu phát nhạc...\n");
    changeState(player, &playingState);
}

void stoppedPressPause(MusicPlayer *player) {
    printf("Không thể tạm dừng khi đã dừng.\n");
}

void stoppedPressStop(MusicPlayer *player) {
    printf("Nhạc đã dừng.\n");
}

// PlayingState
void playingPressPlay(MusicPlayer *player);
void playingPressPause(MusicPlayer *player);
void playingPressStop(MusicPlayer *player);

PlayerState playingState = { playingPressPlay, playingPressPause, playingPressStop };

void playingPressPlay(MusicPlayer *player) {
    printf("Đang phát lại bài hát...\n");
}

void playingPressPause(MusicPlayer *player) {
    printf("Tạm dừng nhạc...\n");
    changeState(player, &pausedState);
}

void playingPressStop(MusicPlayer *player) {
    printf("Dừng phát nhạc...\n");
    changeState(player, &stoppedState);
}

// PausedState
void pausedPressPlay(MusicPlayer *player);
void pausedPressPause(MusicPlayer *player);
void pausedPressStop(MusicPlayer *player);

PlayerState pausedState = { pausedPressPlay, pausedPressPause, pausedPressStop };

void pausedPressPlay(MusicPlayer *player) {
    printf("Tiếp tục phát nhạc...\n");
    changeState(player, &playingState);
}

void pausedPressPause(MusicPlayer *player) {
    printf("Nhạc đã tạm dừng.\n");
}

void pausedPressStop(MusicPlayer *player) {
    printf("Dừng phát nhạc từ trạng thái tạm dừng...\n");
    changeState(player, &stoppedState);
}