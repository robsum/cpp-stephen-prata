#include <iostream>
#include <string>
#include "pairs.h"
#include <valarray>

typedef std::valarray<int> ArrayInt;
typedef Pair<ArrayInt, ArrayInt> PairArray;

class Wine {
    private:
        std::string label;
        PairArray yearBottles;
        int noOfYrs;
    public:
        Wine(const char* l, int y, const int yr[], const int bot[])
        : label(l), noOfYrs(y) {
            yearBottles.first().resize(noOfYrs);
            yearBottles.second().resize(noOfYrs);
            for (int i = 0; i < noOfYrs; ++i) {
                yearBottles.first()[i] = yr[i];
                yearBottles.second()[i] = bot[i];
            }
        }
        Wine(const char* l, int y) : label(l), noOfYrs(y) {
            yearBottles.first().resize(noOfYrs);
            yearBottles.second().resize(noOfYrs);
         }
        Wine() : label("noname"), noOfYrs(0) { }
        void GetBottles() {
            std::cout << "Podaj dane o winie " << label << " dla " << noOfYrs << " roczników: " << std::endl;
            int yr;
            int bottles;
            yearBottles.first().resize(noOfYrs);
            yearBottles.second().resize(noOfYrs);
            for (int i = 0; i < noOfYrs; ++i) {
                std::cout << "Podaj rocznik: ";
                std::cin >> yr;
                std::cout << "Podaj liczbe butelek: ";
                std::cin >> bottles;

                yearBottles.first()[i] = yr;
                yearBottles.second()[i] = bottles;
            }
        }

        void Show() {
            std::cout << "Wino: " << label << std::endl;
            std::cout << "\tRocznik\tButelki\n";
            for (int i = 0; i < noOfYrs; ++i) {
                std::cout << "\t" << yearBottles.first()[i] << "\t" << yearBottles.second()[i] << std::endl;
            }
        }

        const std::string& Label() const { return label; }

        int sum() {
            int sum = 0;
            for (int i = 0; i < noOfYrs; ++i) {
                sum += yearBottles.second()[i];
            }
            return sum;
        }
        

};