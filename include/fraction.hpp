#ifndef FRACTION_H
#define FRACTION_H

#include <iostream>
#include <cassert>
#include <iomanip>
#include <cmath>

class Fraction {
    int numer;
    int denom;
    int gcd(int n, int m = 1);
    void normalize();
public:
    Fraction(int numer, int denom);
    Fraction(double value);
    Fraction();
    Fraction(const Fraction& other);
    ~Fraction();

    operator double();
    const Fraction operator+();
    const Fraction operator-();
    Fraction& operator++();
    Fraction& operator--();
    const Fraction operator++(int);
    const Fraction operator--(int);
    Fraction& operator=(const Fraction& other);
    Fraction& operator+=(const Fraction& other);
    Fraction& operator-=(const Fraction& other);
    Fraction& operator*=(const Fraction& other);
    Fraction& operator/=(const Fraction& other);

    friend const Fraction operator+
        (const Fraction& left, const Fraction& right);
    friend const Fraction operator-
        (const Fraction& left, const Fraction& right);
    friend const Fraction operator*
        (const Fraction& left, const Fraction& right);
    friend const Fraction operator/
        (const Fraction& left, const Fraction& right);

    friend bool operator==
        (const Fraction& left, const Fraction& right);
    friend bool operator!=
        (const Fraction& left, const Fraction& right);
    friend bool operator<
        (const Fraction& left, const Fraction& right);
    friend bool operator<=
        (const Fraction& left, const Fraction& right);
    friend bool operator>
        (const Fraction& left, const Fraction& right);
    friend bool operator>=
        (const Fraction& left, const Fraction& right);

    friend std::istream& operator>>
        (std::istream& left, Fraction& right);
    friend std::ostream& operator<<
        (std::ostream& left, const Fraction& right);
};

#endif
