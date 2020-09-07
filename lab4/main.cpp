#include <iostream>
#include <gtest/gtest.h>

#include "utils/programmerDetails.h"
#include "utils/argumentParsing.h"


/** Tresc zadan dla Panstwa:

Zadanie 0: absolutnie obowiazkowe, chociaz bez punktow
1) Pierwsza rzecza jest poprawa bledow kompilacji,
   czyli wpisanie poprawnych Panstwa danych w pliku: programmerDetails.h
2) Oddanne zadanie musi sie bezwzglednie kompilowac,
   jesli sie nie skompiluje to jest to 0 punktow za zadanie!
   Oczywiscie w razie problemow z kompilacja prosze pisać.
   Dobrze, jesli nie byloby warningow kompilacji, ale za to nie obnizam punktow.
3) Oddane zadanie nie powinno crashować na żadnym teście,
   jeśli crashuje proszę zrobic implementacje -fake, ktora bedzie zwracac zawsze te same wartosci
   -test bedzie failowal, ale za to testy nie beda sie crashowaly.
   Jak ktos nie lubi fake'ow to moze odszukac test,
   ktory crashuje i zmienic jego nazwe dodajac z przodu prefix DISABLED_
   -wtedy test nie bedzie uruchamiany w ogole.
   W przypadku crasha biorę pod uwagę tylko tyle testów, ile przejdzie do czasu crasha!
5) Mam program antyplagiatowy, dlatego prosze pracowac samodzielnie!
   Osoby ktore udostepniaja swoje rozwiazania rowniez beda mialy kare!

Zadanie implementacyjne - patrz pliki: shape.h
**/

int main(int argc, char* argv[])
{
    StudentsInfo::validateStudentsInfo();

    ArgumentParsing::reactToProgramArgumentsPossibilyExit(argc, argv);

    ::testing::InitGoogleTest(&argc, argv);

    return RUN_ALL_TESTS();
}
