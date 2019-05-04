#ifndef ZFRACTION_HPP_
#define ZFRACTION_HPP_
#include <iostream>

class Fraction
{
private:
    int m_numerateur;
    int m_denominateur;

public:
    //Fonctions
    std::ostream &affiche(std::ostream &) const;
    bool estEgale(Fraction const&) const;
    bool estSuperieur(Fraction const&) const;
    //Constructeurs
    Fraction();
    Fraction(int, int);
    Fraction(int);
    //Opérateur
    Fraction& operator+=(Fraction const &);
    Fraction& operator-=(Fraction const &);
    Fraction& operator*=(Fraction const &);
    Fraction& operator/=(Fraction const &);
};

//Opérateur de grandeur
bool operator==(Fraction const &, Fraction const &);
bool operator!=(Fraction const &, Fraction const &);
bool operator>(Fraction const &, Fraction const &);
bool operator<(Fraction const &, Fraction const &);

//Opérateur Arithmétique
Fraction operator+(Fraction const &fraction1, Fraction const &fraction2);
Fraction operator-(Fraction const &fraction1, Fraction const &fraction2);
Fraction operator*(Fraction const &fraction1, Fraction const &fraction2);
Fraction operator/(Fraction const &fraction1, Fraction const &fraction2);

//Opérateur de flux
std::ostream &operator<<(std::ostream &flux, Fraction const &fraction);

#endif