/// @file pch.h Plik zawieraj¹cy klasê scalacz

//
// pch.h
//

#pragma once

#include "gtest/gtest.h"
#include <string>
#include <iostream>
#include <algorithm>

using namespace std;

/// @brief Klasa scalacz oraz deklaracje jej metod
class scalacz {
private:
    string* tablica; ///< wskaŸnik do zmiennej zawieraj¹cej nieposortowan¹ tablicê typu string
    int* tablicaposortowana; ///< wskaŸnik do tablicy zawieraj¹cej posortowan¹ tablicê

public:
    scalacz(string a); ///< Konstruktor klasy scalacz
    ~scalacz(); ///< Destruktor klasy scalacz
    int sprawdz(int i, string a); ///< Funkcja do sprawdzania elementów w tablicy
    int dlugoscTablicy(string a); ///< Funkcja zwracaj¹ca d³ugoœæ tablicy
    void zwrocTablice(string a); ///< Funkcja zwracaj¹ca tablicê (nieposortowan¹)
    void tablicatotabposortowana(int a); ///< Funkcja do konwersji tablicy
    void sortuj(int a); ///< Funkcja sortuj¹ca tablicê
    string zwracajTablice(string a); ///< Funkcja zwracaj¹ca posortowan¹ tablicê jako string
    int* pobierzTablice(); ///< Funkcja zwracaj¹ca wskaŸnik na posortowan¹ tablicê
};
