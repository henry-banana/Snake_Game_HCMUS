#include "../header/Sound.h"

void playNgu() {
    PlaySound(TEXT("resource\\sound\\ngu.wav"), NULL, SND_FILENAME);
}
void playPop() {
    Beep(800, 40);
}

void playNen() {
    PlaySoundW(TEXT("resource\\sound\\nen.wav"), NULL, SND_FILENAME);
}

void playSound() {
    PlaySound(TEXT("resource\\sound\\nen.wav"), NULL, SND_FILENAME | SND_ASYNC);
}

void stopSound() {
    PlaySound(NULL, NULL, 0);
}

void soundControl(bool& running, bool& play) {
    bool wasPlaying = false;

    while (running) {
        if (play && !wasPlaying) {
            playSound();
            wasPlaying = true;
        }
        else if (!play && wasPlaying) {
            stopSound();
            wasPlaying = false;
        }

        std::this_thread::sleep_for(std::chrono::milliseconds(100));
    }

    stopSound();
}