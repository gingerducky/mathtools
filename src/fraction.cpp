#include "fraction.hpp"

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

const Fraction Fraction::operator+ ()
{
    Fraction temp(+numer, denom);
    return temp;
}

const Fraction Fraction::operator- ()
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

const Fraction operator+(const Fraction& left, const Fraction& right)
{
    int newNumer = left.numer * right.denom + right.numer * left.denom;
    int newDenom = left.denom * right.denom;
    Fraction result(newNumer, newDenom);
    return result;
}

const Fraction operator-(const Fraction& left, const Fraction& right)
{
    int newNumer = left.numer * right.denom - right.numer * left.denom;
    int newDenom = left.denom * right.denom;
    Fraction result(newNumer, newDenom);
    return result;
}

const Fraction operator*(const Fraction& left, const Fraction& right)
{
    int newNumer = left.numer * right.numer;
    int newDenom = left.denom * right.denom;
    Fraction result(newNumer, newDenom);
    return result;
}

const Fraction operator/(const Fraction& left, const Fraction& right)
{
    int newNumer = left.numer * right.denom;
    int newDenom = left.denom * right.numer;
    Fraction result(newNumer, newDenom);
    return result;
}

bool operator==(const Fraction& left, const Fraction& right)
{
    return (left.numer * right.denom == right.numer * left.denom);
}

bool operator!=(const Fraction& left, const Fraction& right)
{
    return (left.numer * right.denom != right.numer * left.denom);
}

bool operator<(const Fraction& left, const Fraction& right)
{
    return (left.numer * right.denom < right.numer * left.denom);
}

bool operator<=(const Fraction& left, const Fraction& right)
{
    return (left.numer * right.denom <= right.numer * left.denom);
}

bool operator>(const Fraction& left, const Fraction& right)
{
    return (left.numer * right.denom > right.numer * left.denom);
}

bool operator>=(const Fraction& left, const Fraction& right)
{
    return (left.numer * right.denom >= right.numer * left.denom);
}

std::istream& operator>>(std::istream& left, Fraction& right)
{
    std::cout << "Enter the value of numerator: ";
    left >> right.numer;
    std::cout << "Enter the value of denominator: ";
    left >> right.denom;
    right.normalize();
    return left;
}

std::ostream& operator<<(std::ostream& left, const Fraction& right)
{
    left << right.numer << "/" << right.denom;
    return left;
}

int Fraction::gcd(int n, int m)
{
    int gcd = 1;
    for (int k = 1; k <= n && k <= m; ++k)
    {
        if (n % k == 0 && m % k == 0) gcd = k;
    }
    return gcd;
}

void Fraction::normalize()
{
    if (denom == 0)
    {
        std::cout << "Invalid denominator in fraction. Need to quit.\n";
        assert(false);
    }

    if (denom < 0)
    {
        denom = -denom;
        numer = -numer;
    }

    int divisor = gcd(abs(numer), abs(denom));
    numer = numer / divisor;
    denom = denom / divisor;
}
