#include <iostream>
#include <string>
#include "pairs.h"

class Wine {
    private:
        std::string label;
        PairArray pair;
        int noOfYrs;
    public:
        Wine(const char* l, int y, const int yr[], const int bot[])
        : label(l), noOfYrs(y) {
            pair.first() = yr;
            pair.second() = bot;
        }
        Wine(const char* l, int y) : label(l), noOfYrs(y) { }
        Wine() : label("noname"), noOfYrs(0) { }
        void GetBottles() {
            std::cout << "Podaj dane o winie " << label << " dla " << noOfYrs << " roczników: " << std::endl;
            int yr;
            int bottles;
            for (int i = 0; i < noOfYrs; ++i) {
                std::cout << "Podaj rocznik: ";
                std::cin >> yr;
                std::cout << "Podaj liczbe butelek: ";
                std::cin >> bottles;

                pair.first()[i] = yr;
                pair.second()[i] = bottles;
            }
        }

        void Show() {
            std::cout << "Wino: " << label << std::endl;
            std::cout << "\tRocznik\tButelki\n";
            for (int i = 0; i < noOfYrs; ++i) {
                std::cout << "\t" << pair.first()[i] << "\t" << pair.second()[i] << std::endl;
            }
        }

        std::string& Label() { return label; }

        int sum() {
            int sum = 0;
            for (int i = 0; i < noOfYrs; ++i) {
                sum += pair.second()[i];
            }
            return sum;
        }
        

};