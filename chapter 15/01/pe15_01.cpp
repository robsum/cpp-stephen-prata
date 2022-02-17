#include <iostream>
#include "tv.h"


int main(void) {
    Tv tv;
    Remote remote;

    remote.settings();
    tv.settings();

    tv.change_remote_mode(remote);

    remote.settings();
    tv.settings();

    tv.onoff();

    remote.settings();
    tv.settings();

    tv.change_remote_mode(remote);

    remote.settings();
    tv.settings();


}