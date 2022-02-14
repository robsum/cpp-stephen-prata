#include "workermi.h"
#include <iostream>


using std::cout;
using std::cin;
using std::endl;

Worker::~Worker() {}

void Worker::Data() const {
    cout << "Imię i nazwisko: " << fullname << endl;
    cout << "Numer identyfikacyjny: " << id << endl;
}

void Worker::Get() {
    getline(cin, fullname);
    cout << "Podaj nnumer identyfikacyjny: ";
    cin >> id;
    while(cin.get() != '\n') {
        continue;
    }
}

void Waiter::Set() {
    cout << "Podaj imię i nazwisko kelnera: ";
    Worker::Get();
    Get();
}

void Waiter::Show() const {
    cout << "Kategoria: kelner\n";
    Worker::Data();
    Data();
}

void Waiter::Data() const {
    cout << "Elegancja: " << panache << endl;
}

void Waiter::Get() {
    cout << "Podaj poziom elegancji kelnera: ";
    cin >> panache;
    while (cin.get() != '\n')
        continue;
}

const char* Singer::pv[Singer::Vtypes] = {
    "inna", "alt", "kontralt", "sopran", "bas", "baryton", "tenor"
};

void Singer::Set() {
    cout << "Podaj imię i nazwisko piosenkarza: ";
    Worker::Get();
    Get();
}

void Singer::Show() const {
    cout << "Kategoria: piosenkarz\n";
    Worker::Data();
    Data();
}

void Singer::Data() const {
    cout << "Skala głosu: " << pv[voice] << endl;
}

void Singer::Get() {
    cout << "Podaj numer dla skali głosu piosenkarza:\n";
    int i;
    for (i = 0; i < Vtypes; ++i) {
        cout << i << ": " << pv[i] << "\t";
        if (i % 4 == 3)
            cout << endl;
    }
    if (i % 4 != 0) {
        cout << "\n";
    }
    cin >> voice;
    while (cin.get() != '\n')
        continue;
}

void SingingWaiter::Data() const {
    Singer::Data();
    Waiter::Data();
}

void SingingWaiter::Get() {
    Waiter::Get();
    Singer::Get();
}

void SingingWaiter::Set() {
    cout << "Podaj imię i nazwisko śpiewającego kelnera: ";
    Worker::Get();
    Get();
}

void SingingWaiter::Show() const {
    cout << "Kategoria: śpiewający kelner\n";
    Worker::Data();
    Data();
}