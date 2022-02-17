#include <iostream>
#include "tv.h"

bool Tv::volup() {
    if (volume < MaxVal) {
        volume++;
        return true;
    } else return false;
}

bool Tv::voldown() {
    if (volume > MinVal) {
        volume--;
        return true;
    } else return false;
}

void Tv::chanup() {
    if (channel < maxchannel) {
        channel++;
    } else {
        channel = 1;
    }
}

void Tv::chandown() {
    if (channel > 1) {
        channel--;
    } else {
        channel = maxchannel;
    }
}

void Tv::settings() const {
    using std::cout;
    using std::endl;
    cout << "Telewizor jest " << (state == Off ? "Wyłączony" : "Włączony") << endl;
    if (state == On) {
        cout << "Głośność = " << volume << endl;
        cout << "Program = " << channel << endl;
        cout << "Tryb = " << (mode ==  Antenna ? "antena" : "kabel") << endl;
        cout << "Wejście = " << (input == TV ? "TV" : "DVD") << endl;
    } 
}

void Remote::settings() const {
    std::cout << "Pilot jest w trybie " << (remote_mode == RemoteMode::Normal ? "normalnym" : "interaktywnym") << std::endl;
}

void Tv::change_remote_mode(Remote& r) {
    if (state == On)
        r.change_remote_mode();
}

