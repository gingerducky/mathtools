#include "fraction.h"

Fraction::Fraction(int num, int den = 1)
    :numer(num), denom(den)
{
    normalize();
}

Fraction::Fraction(double value)
{
    denom = 1;
    while ((value - static_cast<int>(value)) > 0.0)
    {
        value *= 10.0;
        denom *= 10;
    }
    numer = static_cast<int>(value);
    normalize();
}

Fraction::Fraction()
    :numer(0), denom(1)
{}

Fraction::Fraction(const Fraction& other)
    :numer(other.numer), denom(other.denom)
{}

Fraction::~Fraction() {}

Fraction::operator double()
{
    double num = static_cast<double>(numer);
    return (num / denom);
}

const Fraction Fraction::operator+ () const
{
    Fraction temp(+numer, denom);
    return temp;
}

const Fraction Fraction::operator- () const
{
    Fraction temp(-numer, denom);
    return temp;
}

Fraction& Fraction::operator++()
{
    numer = numer + denom;
    this->normalize();
    return *this;
}

Fraction& Fraction::operator--()
{
    numer = numer - denom;
    this->normalize();
    return *this;
}

const Fraction Fraction::operator++(int)
{
    Fraction temp(numer, denom);
    ++(*this);
    return temp;
}

const Fraction Fraction::operator--(int)
{
    Fraction temp(numer, denom);
    --(*this);
    return temp;
}

Fraction& Fraction::operator=(const Fraction& right)
{
    if (*this != right)
    {
        numer = right.numer;
        denom = right.denom;
    }

    return *this;
}

Fraction& Fraction::operator+=(const Fraction& right)
{
    numer = numer * right.denom + denom * right.numer;
    denom = denom * right.denom;
    normalize();
    return *this;
}

Fraction& Fraction::operator-=(const Fraction& right)
{
    numer = numer * right.denom - denom * right.numer;
    denom = denom * right.denom;
    normalize();
    return *this;
}

Fraction& Fraction::operator*=(const Fraction& right)
{
    numer = numer * right.numer;
    denom = denom * right.denom;
    normalize();
    return *this;
}

Fraction& Fraction::operator/=(const Fraction& right)
{
    numer = numer * right.denom;
    denom = denom * right.numer;
    normalize();
    return *this;
}


