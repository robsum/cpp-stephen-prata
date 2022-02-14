#ifndef PERSON_H_
#define PERSON_H_

#include <string>
#include <random>

class Person {
    private:
        std::string name;
        std::string surname;
    public:
        Person() : name("brak"), surname("brak") {}
        Person(const char* n, const char* s) : name(n), surname(s) {}
        virtual void Show() const = 0;
        virtual ~Person() = 0;
};

class Gunslinger : virtual public Person {
    protected:
        double time;
        int cuts;
    public:
        Gunslinger() : Person(), time(0), cuts(0) {}
        Gunslinger(const Person& p, double t, int c) : Person(p), time(t), cuts(c) {}
        double Draw() { return time; }
        void Show() const;
};

class PokerPlayer : virtual public Person {
    public:
        PokerPlayer() : Person() {}
        PokerPlayer(const Person& p) : Person(p) {}
        unsigned int Draw() const {
            std::random_device dev;
            std::mt19937 rng(dev());
            std::uniform_int_distribution<std::mt19937::result_type> dist6(1, 52);

            return dist6(rng);
        }
        void Show() const;
};

class BadGuy : public Gunslinger, public PokerPlayer {
    public:
        void Show() const;
        double Gdraw() const;
        unsigned int Cdraw() const;
};

#endif