#include <iostream>
#include <cmath>
#include "exc_mean.h"

double hmean(double a, double b);
double gmean(double a, double b);

int main(void) {
    using std::cout;
    using std::cin;
    using std::endl;

    double x, y, z;

    cout << "Podaj dwie liczby: ";
    while (cin >> x >> y) {
        try {
            z = hmean(x, y);
            cout << "Średnia harmoniczna liczb " << x << " i " << y
                 << " wynosi " << z << endl;
            cout << "Średnia geometryczna liczb " << x << " i " << y
                 << " wynosi " << gmean(x, y) << endl;
            cout << "Podaj kolejną parę liczb (w, aby wyjść): ";
        } catch (bad_hmean& bg) {
            bg.mesg();
            cout << bg.what();
            cout << "Spróbuj ponownie.\n";
            continue;
        } catch (bad_gmean& hg) {
            cout << hg.mesg();
            cout << hg.what();
            cout << "Użyte wartości: " << hg.v1 << ", "
                 << hg.v2 << endl;
            cout << "Niestety, to koniec zabawy.\n";
            break;
        }
    }
    cout << "Koniec.\n";
    return EXIT_SUCCESS;
}

double hmean(double a, double b) {
    if (a == -b) {
        throw bad_hmean(a, b);
    }
    return 2.0 * a * b / (a + b);
}

double gmean(double a, double b) {
    if (a < 0 || b < 0) {
        throw bad_gmean(a, b);
    }
    return std::sqrt(a * b);
}
