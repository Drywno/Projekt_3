/// @file pch.h Plik zawieraj�cy klas� scalacz

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
    string* tablica; ///< wska�nik do zmiennej zawieraj�cej nieposortowan� tablic� typu string
    int* tablicaposortowana; ///< wska�nik do tablicy zawieraj�cej posortowan� tablic�

public:
    scalacz(string a); ///< Konstruktor klasy scalacz
    ~scalacz(); ///< Destruktor klasy scalacz
    int sprawdz(int i, string a); ///< Funkcja do sprawdzania element�w w tablicy
    int dlugoscTablicy(string a); ///< Funkcja zwracaj�ca d�ugo�� tablicy
    void zwrocTablice(string a); ///< Funkcja zwracaj�ca tablic� (nieposortowan�)
    void tablicatotabposortowana(int a); ///< Funkcja do konwersji tablicy
    void sortuj(int a); ///< Funkcja sortuj�ca tablic�
    string zwracajTablice(string a); ///< Funkcja zwracaj�ca posortowan� tablic� jako string
    int* pobierzTablice(); ///< Funkcja zwracaj�ca wska�nik na posortowan� tablic�
};
