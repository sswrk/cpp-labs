#include <iostream>
#include <gtest/gtest.h>

#include "utils/programmerDetails.h"
#include "utils/argumentParsing.h"


/** Tresc zadan dla Panstwa:

Zadanie 0: absolutnie obowiazkowe, chociaz bez punktow
1) Pierwsza rzecza jest poprawa bledow kompilacji,
   czyli wpisanie poprawnych Panstwa danych w pliku: programmerDetails.h
2) Oddanne kolokwium musi sie bezwzglednie kompilowac,
   jesli sie nie skompiluje to jest to 0 punktow za kolokwium!
   Oczywiscie w razie problemow z kompilacja prosze pisać.
   Maja Panstwo udostepniona sprawdzarke automatyczna, wiec prosze z niej skorzystac.
   Jesli ktos ma problem kompilacji na tescie to trzeba zakomentowac caly test zaczynajac od:
   TEST_F(...)
   Dobrze, jesli nie byloby warningow kompilacji, ale za to nie obnizam punktow.
3) Oddane kolokwium nie powinno crashować na żadnym teście,
   jeśli crashuje proszę przed nazwa testu:
   TEST_F(nazwaKlasy, nazwaTestu)
   dac przedrostek DISABLED_:
   TEST_F(nazwaKlasy, DISABLED_nazwaTestu)
   -wtedy test nie bedzie uruchamiany w ogole.
   W przypadku crasha biorę pod uwagę tylko tyle testów, ile przejdzie do czasu crasha!
5) Mam program antyplagiatowy, dlatego prosze pracowac samodzielnie!
   Osoby ktore udostepniaja swoje rozwiazania rowniez beda mialy kare!

Dodam, ze struktura projektu wraz z CMake'iem dostarczona przez pana Michala,
ktory zgodzil sie aby byla na nastepne zadania.
**/

int main(int argc, char* argv[])
{
    StudentsInfo::validateStudentsInfo();

    ArgumentParsing::reactToProgramArgumentsPossibilyExit(argc, argv);

    ::testing::InitGoogleTest(&argc, argv);

    return RUN_ALL_TESTS();
}
