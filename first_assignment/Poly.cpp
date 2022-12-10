#include "Poly.h"
#include <iostream>

///constructor
Poly::Poly(int n)
{
    if(n < 1) throw INVALID;
    _v.clear();
    _v.resize(n);
}
Poly& Poly::operator=(const Poly& p)
{
    int s = p.getSize();
    reSize(s);
    for(int i = 0; i < s; i++)
    {
        _v[i] = p._v[i];
    }
}

void Poly::reSize(int n)
{
    if(n < 1) throw INVALID;
    _v.resize(n,0);
}

Poly operator+(const Poly& a, const Poly& b)
{
    int sizeA = a.getSize();
    int sizeB= b.getSize();
    Poly res;
    if(sizeA > sizeB)
        res = a;
    else
        res = b;
    for(int i = 0; i < min(sizeA, sizeB); i++)
        res._v[i] = a._v[i] + b._v[i];
    return res;
}

Poly operator* (const Poly& a, const Poly& b)
{
    int s = a.getSize();
    int t = b.getSize();
    Poly res(s + t -1);
    for(int i = 0; i < s; i++)
    {
        for(int j = 0; j < t; j++)
            res._v[i+j] = res._v[i+j] + a._v[i] * b._v[j];
    }
    return res;
}

ostream &operator<< (ostream &s, const Poly &p)
{
    int size = p.getSize();
    double c = p._v[size-1];
    if(c == 1)
        s << "x^" << size-1 << " ";
    else if(c == -1)
                s << "-x^" << size-1 <<" ";
    else
        s << c << "x^" << size-1 << " ";
    for(int i = size-2;  i >= 1; i--)
    {
        c = p._v[i];

        if(i == 1)
        {
            if(c == 1)
                s << "+x ";
            else if(c == -1)
                s << "-x" <<" ";
            else if(c < 0)
                s << c << "x ";
            else if(c > 0)
                s << "+" << c << "x ";
        }
        else
        {
            if(c == 1)
                s << "+x^" << i <<" ";
            else if(c == -1)
                s << "-x^" << i <<" ";
            else if(c < 0)
                s << c << "x^" << i <<" ";
            else if(c > 0)
                s << "+" << c << "x^" << i <<" ";
        }
    }
    if(p._v[0] < 0)
        s << p._v[0];
    else if(p._v[0] > 0)
        s << "+" << p._v[0];
}

istream &operator>> (istream &s, Poly &p)
{
    int n;
    s >> n;
    p.reSize(n+1);
    //double c;
    for(int i = n; i >= 0; i--)
    {
        s >> p._v[i];
    }
    return s;
}

double Poly::operator()(int i) const
{
    int s = getSize();
    if(i >= s || i < 0) throw OVERINDEXED;
    return _v[i];
}

double& Poly::operator()(int i)
{
    int s = getSize();
    if(i >= s || i < 0) throw OVERINDEXED;
    return _v[i];
}
