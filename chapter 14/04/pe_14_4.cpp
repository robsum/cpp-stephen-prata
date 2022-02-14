#include "person.h"
#include <iostream>

int main(void) {
    Gunslinger gunslinger = Gunslinger();
    PokerPlayer pokerplayer = PokerPlayer();
    BadGuy badguy = BadGuy();

    pokerplayer.Show();
    gunslinger.Show();
    badguy.Show();


    return EXIT_SUCCESS;
}