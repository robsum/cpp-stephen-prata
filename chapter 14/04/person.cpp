#include "person.h"

#include <iostream>

Person::~Person() {}

void Person::Show() const {
    std::cout << "Osoba " << name << ", " << surname << std::endl;
}

void Gunslinger::Show() const {
    Person::Show();
    std::cout << "Draw: " << time << ", cuts: " << cuts << std::endl;
}

void PokerPlayer::Show() const {
    Person::Show();
    std::cout << "Random card: " << PokerPlayer::Draw() << std::endl;
}

void BadGuy::Show() const {
    Gunslinger::Show();
    PokerPlayer::Show();
}

double BadGuy::Gdraw() const {
    return time;
}

unsigned int BadGuy::Cdraw() const {
    return PokerPlayer::Draw();
}