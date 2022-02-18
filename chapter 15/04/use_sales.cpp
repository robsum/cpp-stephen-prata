#include <iostream>
#include "sales.h"

int main() {
    using std::cout;
    using std::cin;
    using std::endl;

    double vals1[Sales::MONTHS] = {
        1220, 1100, 1122, 2212, 1232, 2334,
        2884, 2393, 3302, 2922, 3002, 3544
    };
    double vals2[Sales::MONTHS] = {
        12, 11, 22, 21, 32, 34,
        28, 29, 33, 29, 32, 25
    };

    Sales sales1(2011, vals1, Sales::MONTHS);
    LabeledSales sales2("Blogstar", 2012, vals2, Sales::MONTHS);
    cout << "Pierwszy blok try:\n";
    try {
        int i;
        cout << "Rok = " << sales1.Year() << endl;
        for (i = 0; i < Sales::MONTHS; ++i) {
            cout << sales1[i] << ' ';
            if (i % 6 == 5) {
                cout << endl;
            }
        }
        cout << "Rok = " << sales2.Year() << endl;
        cout << "Etykieta = " << sales2.Label() << endl;
        for (i = 0; i <= Sales::MONTHS; ++i) {
            cout << sales2[i] << ' ';
            if (i % 6 == 5) {
                cout << endl;
            }
        }
        cout << "Koniec pierwszego bloku try.\n";
    } catch (Sales::bad_index& bad) {
        cout << bad.what();
        LabeledSales::nbad_index* pt;
        if (pt = dynamic_cast<LabeledSales::nbad_index*>(&bad)) {
            cout << "Firma: " << pt->label_val() << endl;
        }
        cout << "Niepoprawny indeks: " << bad.bi_val() << endl;
    }
    // } catch (LabeledSales::nbad_index& bad) {
    //     cout << bad.what();
    //     cout << "Firma: " << bad.label_val() << endl;
    //     cout << "Niepoprawny indeks: " << bad.bi_val() << endl;
    // } catch (Sales::bad_index& bad) {
    //     cout << bad.what();
    //     cout << "Niepoprawny indeks: " << bad.bi_val() << endl;
    // }
    cout << "\nKolejny blok try:\n";
    try {
        sales2[2] = 37.5;
        sales1[20] = 23345;
        cout << "Koniec drugiego bloku try.\n";
    } catch (Sales::bad_index& bad) {
        cout << bad.what();
        LabeledSales::nbad_index* pt;
        if (pt = dynamic_cast<LabeledSales::nbad_index*>(&bad)) {
            cout << "Firma:" << pt->label_val() << endl;
        }
        cout << "Niepoprawny indeks: " << bad.bi_val() << endl;
    }
    // } catch (LabeledSales::nbad_index& bad) {
    //     cout << bad.what();
    //     cout << "Firma: " << bad.label_val() << endl;
    //     cout << "Niepoprawny indeks: " << bad.bi_val() << endl;
    // } catch (Sales::bad_index& bad) {
    //     cout << bad.what();
    //     cout << "Niepoprawny indeks: " << bad.bi_val() << endl;
    // }
    cout << "Koniec\n";

    return EXIT_SUCCESS;
}