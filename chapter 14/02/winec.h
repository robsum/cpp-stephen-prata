#include <iostream>
#include <string>
#include "pairs.h"
#include <valarray>

typedef std::valarray<int> ArrayInt;
typedef Pair<ArrayInt, ArrayInt> PairArray;

class Wine : private PairArray, private std::string {
    private:
        int noOfYrs;
    public:
        Wine(const char* l, int y, const int yr[], const int bot[])
        : std::string(l), noOfYrs(y) {
            PairArray::first().resize(noOfYrs);
            PairArray::second().resize(noOfYrs);
            for (int i = 0; i < noOfYrs; ++i) {
                PairArray::first()[i] = yr[i];
                PairArray::second()[i] = bot[i];
            }
        }
        Wine(const char* l, int y) : std::string(l), noOfYrs(y) {
            PairArray::first().resize(noOfYrs);
            PairArray::second().resize(noOfYrs);
         }
        Wine() : std::string("noname"), noOfYrs(0) { }
        void GetBottles() {
            std::cout << "Podaj dane o winie " << (std::string) *this << " dla " << noOfYrs << " roczników: " << std::endl;
            int yr;
            int bottles;
            PairArray::first().resize(noOfYrs);
            PairArray::second().resize(noOfYrs);
            for (int i = 0; i < noOfYrs; ++i) {
                std::cout << "Podaj rocznik: ";
                std::cin >> yr;
                std::cout << "Podaj liczbe butelek: ";
                std::cin >> bottles;

                PairArray::first()[i] = yr;
                PairArray::second()[i] = bottles;
            }
        }

        void Show() {
            std::cout << "Wino: " << (const std::string &) *this << std::endl;
            std::cout << "\tRocznik\tButelki\n";
            for (int i = 0; i < noOfYrs; ++i) {
                std::cout << "\t" << PairArray::first()[i] << "\t" << PairArray::second()[i] << std::endl;
            }
        }

        const std::string& Label() const { return (const std::string &) *this; }

        int sum() {
            int sum = 0;
            for (int i = 0; i < noOfYrs; ++i) {
                sum += PairArray::second()[i];
            }
            return sum;
        }
        

};