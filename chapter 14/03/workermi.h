#ifndef WORKERMI_H_
#define WORKERMI_H_

#include <iostream>
#include <string>

class Worker {
    private:
        std::string fullname;
        long id;
    protected:
        virtual void Data() const;
        virtual void Get();
    public:
        Worker() : fullname("brak"), id(0L) {}
        Worker(const std::string& s, long n)
            : fullname(s), id(n) {}
        virtual ~Worker() = 0;
        virtual void Set() = 0;
        virtual void Show() const = 0;
};

// inline std::ostream& operator<<(std::ostream & Str, Worker const & v) { 
//     v.Show();
//     return Str;
// }

class Waiter : virtual public Worker {
    private:
        int panache;
    protected:
        void Data() const;
        void Get();
    public:
        Waiter() : Worker(), panache(0) {}
        Waiter(const std::string& s, long n, int p = 0)
            : Worker(s, n), panache(p) {}
        Waiter(const Worker& wk, int p = 0)
            : Worker(wk), panache(p) {}
        void Set();
        void Show() const;
        virtual ~Waiter() {}
};

class Singer : virtual public Worker {
    protected:
        enum { inna, alt, kontralt, sopran, bas, baryton, tenor };
        enum { Vtypes = 7 };
        void Data() const;
        void Get();
    private:
        static const char* pv[Vtypes];
        int voice;
    public:
        Singer() : Worker(), voice(inna) {}
        Singer(const std::string& s, long n, int v = inna)
            : Worker(s, n), voice(v) {}
        Singer(const Worker& wk, int v = inna)
            : Worker(wk), voice(v) {}
        void Set();
        void Show() const;
        virtual ~Singer() {}
};

class SingingWaiter : public Singer, public Waiter {
    protected:
        void Data() const;
        void Get();
    public:
        SingingWaiter() {}
        SingingWaiter(const std::string& s, long n, int p = 0, int v = inna)
            : Worker(s, n), Waiter(s, n, p), Singer(s, n, v) {}
        SingingWaiter(const Worker& wk, int p = 0, int v = inna)
            : Worker(wk), Waiter(wk, p), Singer(wk, v) {}
        SingingWaiter(const Waiter& wt, int v = inna)
            : Worker(wt), Waiter(wt), Singer(wt, v) {}
        SingingWaiter(const Singer& wt, int p = 0)
            : Worker(wt), Waiter(wt, p), Singer(wt) {}
        void Set();
        void Show() const;
        virtual ~SingingWaiter() {}
};
#endif