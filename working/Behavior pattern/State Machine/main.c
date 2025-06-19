#include "MusicPlayer.h"

int main() {
    MusicPlayer player = { &stoppedState };

    clickPlayButton(&player);  // Bắt đầu phát nhạc
    clickPauseButton(&player); // Tạm dừng
    clickPlayButton(&player);  // Tiếp tục phát
    clickStopButton(&player);  // Dừng phát nhạc

    return 0;
}