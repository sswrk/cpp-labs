#include "fraction.h"
#include <stdexcept>
#include <iostream>

int NWD(int a, int b) {
    int pom;
    while(b!=0) {
        pom = b;
        b = a%b;
        a = pom;
    }
    return a;
}

Fraction::Fraction(int numerator, int denominator): numerator(numerator), denominator(denominator) {
    if(denominator == 0)
        throw(std::invalid_argument("Mianownik nie moze byc 0!"));
}

void Fraction::setDenominator(int denominator) {
    if(denominator == 0)
        throw(std::invalid_argument("Mianownik nie moze byc 0!"));

    this->denominator = denominator;

}

Fraction operator+(const Fraction &fraction1, const Fraction &fraction2) {
    int denominator = NWW( fraction1.denominator, fraction2.denominator );
    int numerator = fraction1.numerator * ( denominator/fraction1.denominator ) + fraction2.numerator * ( denominator/fraction2.denominator );

    int nwd = NWD(numerator, denominator);
    denominator/=nwd;
    numerator/=nwd;

    return Fraction( numerator, denominator );
}

Fraction operator*(const Fraction &fraction1, const Fraction &fraction2) {
    int denominator = fraction1.denominator * fraction2.denominator;
    int numerator = fraction1.numerator * fraction2.numerator;

    denominator/=NWD(numerator, denominator);
    numerator/=NWD(numerator, denominator);

    return Fraction( numerator, denominator );
}