/// @file test.cpp Plik główny przerób zmienne w plikach, oraz komentarze (polski) aby działały jako jeden projekt

#include "pch.h"
#include <cstdlib>
#include <ctime>

/// @brief Test1, sprawdza czy tablica zostanie niezmieniona jeżeli wpiszemy już posortowaną tablicę
TEST(Testyogolne, Zachowanie_niezmienionej_tablicy) {
    string input = ("2 4 6 8 10 12 14");
    scalacz a(input);
    EXPECT_EQ(input, a.zwracajTablice(input));
}

/// @brief Test2, Sprawdza czy dobrze posortuje odwróconą tablicę
TEST(Testyogolne, sortowanie_odwrotnej_tablicy) {
    string input = ("20 18 16 14 12 10 8 6 4 2 0");
    scalacz a(input);
    EXPECT_EQ("0 2 4 6 8 10 12 14 16 18 20", a.zwracajTablice(input));
}

/// @brief Test3, sprawdza czy posortuje randomową tablicę
TEST(Testyogolne, randomowa_tablica) {
    srand(static_cast<unsigned int>(time(0)));
    int i = 0;
    string r;
    int t = rand() % 50 + 5;
    while (i < t) {
        r += to_string(rand() % 5000 - 1000);
        if (i != (t - 1)) {
            r += " ";
        }
        i++;
    }

    scalacz a(r);

    int spaces = 0;
    for (int j = 0; j < r.length(); j++) {
        if (r[j] == ' ') {
            spaces += 1;
        }
    }

    int j = 0;
    int* tab = a.pobierzTablice();
    while (j < spaces - 1) {
        if (tab[j] == tab[j + 1]) {
            EXPECT_EQ(tab[j], tab[j + 1]);
        }
        else {
            EXPECT_LT(tab[j], tab[j + 1]);
        }
        j += 1;
    }
}

/// @brief Test4 sprawdza czy posortuje tablicę z ujemnymi elementami
TEST(Testyogolne, ujemne_elementy) {
    string input = ("-3 -7 -22 -47 -102 -345 -23 -15 -50 -8 -25000 -950");
    scalacz a(input);
    EXPECT_EQ("-25000 -950 -345 -102 -50 -47 -23 -22 -15 -8 -7 -3", a.zwracajTablice(input));
}

/// @brief Test5 sprawdza czy posortuje tablicę z ujemnymi i dodatnimi elementami
TEST(Testyogolne, elementy_dodatnie_i_ujemne) {
    string input = ("9 3 12 6 8 5 10 -3 -1 -7 0");
    scalacz a(input);
    EXPECT_EQ("-7 -3 -1 0 3 5 6 8 9 10 12", a.zwracajTablice(input));
}

/// @brief Test6 sprawdza czy wyskoczy błąd przy tablicy bez elementów
TEST(Testyogolne, sortowanie_tablicy_bez_elemenow) {
    string input = ("");
    scalacz a(input);
    EXPECT_EQ("", a.zwracajTablice(input));
}

/// @brief Test7 sprawdza czy posortuje tablicę z jednym elementem
TEST(Testyogolne, sortowanie_tablicy_jeden_element) {
    string input = ("7");
    scalacz a(input);
    EXPECT_EQ("7", a.zwracajTablice(input));
}

/// @brief Test8 sprawdza czy posortuje tablicę z powtarzającymi się elementami
TEST(Testyogolne, sortowanie_tablicy_powtarzajace_elementy) {
    string input = ("4 4 4 6 6 6 5 5 5 5 5 30 18 18 18");
    scalacz a(input);
    EXPECT_EQ("4 4 4 5 5 5 5 5 6 6 6 18 18 18 30", a.zwracajTablice(input));
}

/// @brief Test9 sprawdza czy posortuje tablicę z powtarzającymi się ujemnymi elementami
TEST(Testyogolne, sortowanie_tablicy_powtarzajace_ujemne_elementy) {
    string input = ("-4 -4 -4 -6 -6 -6 -5 -5 -5 -5 -5 -30 -18 -18 -18");
    scalacz a(input);
    EXPECT_EQ("-30 -18 -18 -18 -6 -6 -6 -5 -5 -5 -5 -5 -4 -4 -4", a.zwracajTablice(input));
}

/// @brief Test10 sprawdza czy posortuje tablicę z powtarzającymi się ujemnymi i dodatnimi elementami
TEST(Testyogolne, sortowanie_tablicy_powtarzajace_elementy_dodatnie_ujemne) {
    string input = ("-2 -2 2 4 -4 -4 3 3 -3 -3 3 20 15 -15 15");
    scalacz a(input);
    EXPECT_EQ("-15 -4 -4 -3 -3 -2 -2 2 3 3 3 4 15 15 20", a.zwracajTablice(input));
}

/// @brief Test11 sprawdza czy posortuje tablicę z dwoma elementami rosnąco
TEST(Testyogolne, sortowanie_tablicy_dwa_elementy_rosnaco) {
    string input = ("5 9");
    scalacz a(input);
    EXPECT_EQ("5 9", a.zwracajTablice(input));
}
