// Benjamin Rose
// Idea is to practice managing memory and developing OOP principles such as encapsulation, abstraction, and polymorphism

#ifndef POLY_POLY_H
#define POLY_POLY_H

#include <iostream>

class Poly
{
    // Overloaded >> operator
    friend std::istream &operator>>(std::istream &inStream, Poly &sourceCoeff);

    // Overloaded << operator
    friend std::ostream &operator<<(std::ostream &outStream, const Poly &SourcePoly);

public:
    // Constructors and Destructor
    Poly();
    Poly(int coeff);
    Poly(int coeff, int power);
    Poly(const Poly &source);
    ~Poly();

    // Getter and Setter
    int getCoeff(int power) const;
    void setCoeff(int coeff, int power);

    // Binary arithmetic operators
    Poly operator+(const Poly &rhs) const;
    Poly operator-(const Poly &rhs) const;
    Poly operator*(const Poly &rhs) const;

    // Compound assignment operators
    Poly &operator+=(const Poly &rhs);
    Poly &operator-=(const Poly &rhs);
    Poly &operator*=(const Poly &rhs);

    // Comparison operators
    bool operator==(const Poly &rhs) const;
    bool operator!=(const Poly &rhs) const;

    // Assignment operator
    Poly &operator=(const Poly &rhs);

    // Debug helper
    void printPoly(const Poly &p, const std::string &label) const;

private:
    int *coeffPtr; // Pointer to array
    int size;      // Size of array
};

#endif // POLY_POLY_H
