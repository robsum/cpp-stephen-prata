#include <iostream>
#include <stdexcept>

class bad_hmean : std::logic_error {
    private:
        double v1;
        double v2;
    public:
        bad_hmean(double a = 0, double b = 0) : std::logic_error("błąd hmean"), v1(a), v2(b) {}
        void mesg();
        virtual char* what() { return "bad_hmean\n"; };
};

inline void bad_hmean::mesg() {
    std::cout << "hmean(" << v1 << ", " << v2 << "): "
        << "niepoprawne argumenty: a = -b\n";
}

class bad_gmean : std::logic_error {
    public:
        double v1;
        double v2;
        bad_gmean(double a = 0, double b = 0) : std::logic_error("błąd gmean"), v1(a), v2(b) {}
        const char* mesg();
        virtual char* what() { return "bad_gmean\n"; };
};

inline const char* bad_gmean::mesg() {
    return "Argumenty funkcji gmean() powinny być >= 0\n";
}

