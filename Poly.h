#ifndef POLY_H
#define POLY_H
#include <iostream>
#include <vector>

using namespace std;

class Poly
{
    public:
        enum EXCEPTION {INVALID, OVERINDEXED};

        Poly(){ _v.clear(); }
        Poly(int n);
        ~Poly() { }
        Poly& operator=(const Poly& p);
        int getSize() const {return _v.size();}

        double operator()(int i) const;
        double &operator()(int i);

        friend Poly operator+ (const Poly& a, const Poly& b);
        friend Poly operator* (const Poly& a, const Poly& b);
        friend ostream &operator<<(ostream &s, const Poly &p);
        friend istream &operator>>(istream &s, Poly &p);
    protected:

    private:
        vector<double> _v;
        void reSize(int k);
};

#endif // POLY_H
