#ifndef FRACTION_H
#define FRACTION_H

/** Implementacja ulamka:
[3pkt] Zaimplementuj klase Ulamek (ang. Fraction), posiadająca licznik (ang. numerator) i mianownik (ang. denominator).
       Powinna zawierac jeden konstruktor ustawiajacy licznik i mianownik (domyslne wartosci licznika=0 a mianownika domyslna 1)
       Gettery i settery do wartosci licznika i mianownika
       operator+ dla ulamka zwracajacy ulamek
       operator* dla ulamka zwracajacy ulamek
[1pkt] Niepoprawny mianownik powinien byc zglaszany przez wyjatek std::invalid_argument.
[1pkt] Prosze o skracanie ulamkow po operacji + i * (pomocny moze sie okazac algorytm euklidesa), oczywiscie tutaj robimy tylko dla przypadkow dodatnich
**/

int NWD(int a, int b);
inline int NWW(int a, int b) { return a/NWD(a,b)*b; }

class Fraction
{
private:
    int numerator;
    int denominator;
public:
    Fraction(int numerator = 0, int denominator = 1);

    inline int getNumerator() const { return this->numerator; }
    inline int getDenominator() const { return this->denominator; }
    inline void setNumerator(int numerator) { this->numerator = numerator; }
    void setDenominator(int denominator);

    friend Fraction operator+(const Fraction& fraction1, const Fraction& fraction2);
    friend Fraction operator*(const Fraction& fraction1, const Fraction& fraction2);

};

#endif // FRACTION_H
