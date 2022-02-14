#include <iostream>
#include <cstring>
#include "workermi.h"
#include "queuetp.h"

const int SIZE = 5;

int main(void) {
    using std::cin;
    using std::cout;
    using std::endl;
    using std::strchr;

    Worker* lolas[SIZE];
    QueueTp<Worker*> queue = QueueTp<Worker*>();

    int ct;
    for (ct = 0; ct < SIZE; ++ct) {
        char choice;
        cout << "Podaj kategorię pracownika:\n";
        cout << "k: kelner  p: piosenkarz   "
             << "s: śpiewający kelner  w: wyjście\n";
        cin >> choice;
        while (strchr("kpsw", choice) == NULL) {
            cout << "Wpisz k, p, s lub w: ";
            cin >> choice;
        }
        if (choice == 'w') {
            break;
        }
        switch (choice) {
            case 'k' : lolas[ct] = new Waiter;
                       break;
            case 'p' : lolas[ct] = new Singer;
                       break;
            case 's' : lolas[ct] = new SingingWaiter;
                       break;

        }
        queue.add(lolas[ct]);
        cin.get();
        lolas[ct]->Set();
    }

    cout << "\nLista pracowników queue:\n";
    int i;
    Worker* w;
    while (queue.get(w)) {
        w->Show();
    }
    // cout << "\nLista pracowników standard array:\n";
    // for (i = 0; i < ct; ++i) {
    //     cout << lolas[i] << endl;
    //     lolas[i]->Show();
    // }
    for (i = 0; i < ct; ++i) {
        delete lolas[i];
    }
    cout << "Koniec.\n";
    return EXIT_SUCCESS;
}