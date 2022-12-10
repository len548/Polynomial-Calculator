/*
Implement the types using classes. Represent the types using sequences of same-type
elements stored in vectors (vector<> in C++).
Create a main program with a menu to demonstrate the services (all the methods) a
class provides in arbitrary order (based on the selections of the user). Make the main
program instantiate an object of the class. The methods of the class can be called through
the menu items. Print the state of the object either after the completion of each menu item or
through another menu item for printing. If there are methods or friend functions that need
multiple objects (like adding two matrices, for example), the main program should make it
possible to create and print these objects through the menu.
Implement unit tests which should be run automatically.

Implement the polynomial type.
Represent a polynomial as a sequence of its real-valued coefficients.
Implement as methods: adding two polynomials, multiplying two polynomials,
evaluating the polynomial (substituting a value to the variable).
*/
//Author:    Ren Koike
//Date:      2022.03.17
//Title:     Polynomials

#include <iostream>
#include <math.h>
#include "Poly.cpp"

using namespace std;

#define NORMAL_MODE
#ifdef NORMAL_MODE
class Menu
{
public:
    Menu() : a(2) { }
    void run();
private:
    Poly a;

    void menuWrite();
    void read();
    void display();
    void add();
    void mul();
    void evaluate();
};

int main()
{
    Menu m;
    m.run();
}

void Menu::run()
{
    int n = 0;
    do
    {
        menuWrite();
        cout << endl << ">>>>" ;
        cin >> n;
        switch(n)
        {
        case 1:
            read();
            break;
        case 2:
            display();
            break;
        case 3:
            add();
            break;
        case 4:
            mul();
            break;
        case 5:
            evaluate();
            break;
        }
    }
    while(n!=0);
}

void Menu::menuWrite()
{
    cout << endl << endl;
    cout << " 0. - Quit" << endl;
    cout << " 1. - Read polynomial" << endl;
    cout << " 2. - Display polynomial" << endl;
    cout << " 3. - Add polynomial" << endl;
    cout << " 4. - Multiply polynomials" << endl;
    cout << " 5. - Evaluate polynomials" << endl;
}

void Menu::read()
{
    try
    {
        cout << "Give the maximum power and coefficients of polynomial(x^0..): ";
        cin >> a;
    }
    catch(Poly::EXCEPTION ex)
    {
        if(ex == Poly::INVALID)
            cout << "Invalid size!" << endl;
        else
            cout << "Unknown error!" <<endl;
    }
}

void Menu::display()
{
    cout << a;
}


void Menu::add()
{
    try
    {
        Poly b;
        cout << "Give the maximum power and coefficients of the second polynomial(x^0..): " << endl;
        cin >> b;
        cout << "Sum of the polynomials: " << endl;
        cout << a + b << endl;
    }
    catch(Poly::EXCEPTION ex)
    {
        if(ex == Poly::INVALID)
            cout << "Invalid size!" << endl;
        else
            cout << "Unknown error!" << endl;
    }
}


void Menu::mul()
{
    try
    {
        Poly b;
        cout << "Give the maximum power and coefficients of the second polynomial(x^0..): " << endl;
        cin >> b;
        cout << "Product of the polynomials: " << endl;
        cout << a * b << endl;
    }
    catch(Poly::EXCEPTION ex)
    {
        if(ex == Poly::INVALID)
            cout << "Invalid size!" << endl;
        else
            cout << "Unknown error!" << endl;
    }
}

void Menu::evaluate()
{
    double x;
    cout << "Give a value to substitute to polynomial: " << endl;
    cin >> x;
    double sum = a(0);
    for(int i = 1; i < a.getSize(); i++)
        sum += a(i) * pow(x, i);
    cout << "Result: " << sum;
}

#else

#endif
