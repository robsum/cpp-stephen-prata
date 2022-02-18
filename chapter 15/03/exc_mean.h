#include <iostream>
#include <stdexcept>

class bad_exception : public std::logic_error {
    private:
        double v1;
        double v2;
    public:
        double value_v1() { return v1; }
        double value_v2() { return v2; }
        bad_exception() : std::logic_error("error") {}
        virtual const char* what() const noexcept {
            return "error";
        }
};

class bad_hmean : public bad_exception {
    private:
        double v1;
        double v2;
    public:
        bad_hmean(double a = 0, double b = 0) : v1(a), v2(b) {}
        void mesg();
};

inline void bad_hmean::mesg() {
    std::cout << "hmean(" << v1 << ", " << v2 << "): "
        << "niepoprawne argumenty: a = -b\n";
}

class bad_gmean : public bad_exception {
    public:
        double v1;
        double v2;
        bad_gmean(double a = 0, double b = 0) : v1(a), v2(b) {}
        const char* mesg();
};

inline const char* bad_gmean::mesg() {
    return "Argumenty funkcji gmean() powinny być >= 0\n";
}

