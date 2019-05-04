#include <iostream>
#include "..\\header\\Zfraction.hpp"

Fraction::Fraction()
{
    m_numerateur = 1;
    m_denominateur = 1;
}

Fraction::Fraction(int numerateur, int denominateur)
{
    int diviseurCommun1 = 1;
    int diviseurCommun2 = 1;

    if (numerateur == 1 && denominateur == 1)
    {
        m_denominateur = 1;
        m_numerateur = 1;
    }
    else
    {
        for (size_t i = 1; i < 100; i++)
        {
            if (numerateur % i == 0)
                diviseurCommun1 = i;
        }

        if (denominateur % diviseurCommun1 == 0)
        {
            diviseurCommun2 = diviseurCommun1;

            if (diviseurCommun1 != 1 && diviseurCommun2 != 1)
            {
                do
                {
                    numerateur /= diviseurCommun1;
                    denominateur /= diviseurCommun2;

                } while (numerateur % diviseurCommun1 == 0 && denominateur % diviseurCommun2 == 0);
            }
            m_denominateur = denominateur;
            m_numerateur = numerateur;
        }
        else
        {
            m_denominateur = denominateur;
            m_numerateur = numerateur;
        }
    }
}

Fraction::Fraction(int numerateur) : m_numerateur(numerateur), m_denominateur(1) {}

std::ostream &Fraction::affiche(std::ostream &flux) const
{
    if (m_denominateur == 1 && m_denominateur == 1)
        flux << m_numerateur;
    else if (m_numerateur != 0 && m_denominateur == 1)
        flux << m_numerateur;
    else
        flux << m_numerateur << "/" << m_denominateur;
    return flux;
}

bool Fraction::estEgale(Fraction const &fraction) const
{
    float val = (float)((float)m_numerateur / (float)m_denominateur);
    float val2 = (float)((float)fraction.m_numerateur / (float)fraction.m_denominateur);

    return (val == val2);
}

bool Fraction::estSuperieur(Fraction const &fraction) const
{
    float val = (float)((float)m_numerateur / (float)m_denominateur);
    float val2 = (float)((float)fraction.m_numerateur / (float)fraction.m_denominateur);

    return (val > val2);
}

std::ostream &
operator<<(std::ostream &flux, Fraction const &fraction)
{
    Fraction ret(fraction);
    fraction.affiche(flux);
    return flux;
}

Fraction& Fraction::operator+=(Fraction const &fraction)
{
    if (m_denominateur != fraction.m_denominateur)
    {
        m_numerateur = (m_numerateur * fraction.m_denominateur) + (m_denominateur * fraction.m_numerateur);
        m_denominateur = m_denominateur * fraction.m_denominateur;
    }
    else
    {
        m_numerateur += fraction.m_numerateur;
    }

    return *this;
}

Fraction operator+(Fraction const &fraction1, Fraction const &fraction2)
{
    Fraction ret(fraction1);
    ret += fraction2;
    return ret;
}

Fraction& Fraction::operator-=(Fraction const &fraction)
{
    if (m_denominateur != fraction.m_denominateur)
    {
        m_numerateur = (m_numerateur * fraction.m_denominateur) - (m_denominateur * fraction.m_numerateur);
        m_denominateur = m_denominateur * fraction.m_denominateur;
    }
    else
    {
        m_numerateur -= fraction.m_numerateur;
    }

    return *this;
}

Fraction operator-(Fraction const &fraction1, Fraction const &fraction2)
{
    Fraction f(fraction1);
    f -= fraction2;
    return f;
}

Fraction& Fraction::operator*=(Fraction const &fraction)
{
    m_numerateur *= fraction.m_numerateur;
    m_denominateur *= fraction.m_denominateur;

    return *this;
}

Fraction operator*(Fraction const &fraction1, Fraction const &fraction2)
{
    Fraction temp(fraction1);
    temp *= fraction2;
    return temp;
}

Fraction& Fraction::operator/=(Fraction const &fraction)
{
    m_numerateur *= fraction.m_denominateur;
    m_denominateur *= fraction.m_numerateur;

    return *this;
}

Fraction operator/(Fraction const &fraction1, Fraction const &fraction2)
{
    Fraction temp(fraction1);
    temp /= fraction2;
    return temp;
}

bool operator==(Fraction const &fraction1, Fraction const &fraction2)
{
    return fraction1.estEgale(fraction2);
}

bool operator!=(Fraction const &fraction1, Fraction const &fraction2)
{
    return !fraction1.estEgale(fraction2);
}

bool operator>(Fraction const &fraction1, Fraction const &fraction2)
{
    return fraction1.estSuperieur(fraction2);
}

bool operator<(Fraction const &fraction1, Fraction const &fraction2)
{
    return !fraction1.estSuperieur(fraction2);
}