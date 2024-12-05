/// @file pch.cpp Plik g³ówny

#include "pch.h"
#include <cstdlib>
#include <ctime>

/// @brief Konstruktor klasy scalacz, automatycznie sortuje tablicê
/// @param a - tablica do posortowania
scalacz::scalacz(string a) {
    if (a != "") {
        int i = 0;
        int tabcheck = 0;
        int spaces = dlugoscTablicy(a); // U¿ycie zaktualizowanej nazwy funkcji
        tablica = new string[spaces + 1];
        tablicaposortowana = new int[spaces + 1];

        while (i < a.length()) {
            if (a[i] == ' ') {
                i += 1;
                continue;
            }

            int wordLength = sprawdz(i, a); // U¿ycie zaktualizowanej nazwy funkcji

            tablica[tabcheck] = a.substr(i, wordLength);
            tabcheck += 1;

            i += wordLength;
        }
        tablicatotabposortowana(spaces); // U¿ycie zaktualizowanej nazwy funkcji
        sortuj(spaces); // U¿ycie zaktualizowanej nazwy funkcji
    }
    else {
        tablica = new string[1];
        tablica[0] = "";
        tablicaposortowana = new int[0];
    }
}

/// @brief Destruktor klasy scalacz, usuwa zmienne dynamiczne tablica i tablicaposortowana
scalacz::~scalacz() {
    delete[] tablica;
    delete[] tablicaposortowana;
};

/// @brief Funkcja sprawdzaj¹ca d³ugoœæ danego elementu tablicy
/// @param i - miejsce elementu w string a
/// @param a - nieposortowana tablica tablica
int scalacz::sprawdz(int i, string a) {
    int length = 0;
    while (i + length < a.length() && a[i + length] != ' ') {
        length += 1;
    }
    return length;
}

/// @brief Funkcja zwracaj¹ca d³ugoœæ tablicy
/// @param a - nieposortowana tablica tablica
int scalacz::dlugoscTablicy(string a) {
    int spaces = 0;
    for (int j = 0; j < a.length(); j++) {
        if (a[j] == ' ') {
            spaces += 1;
        }
    }
    return spaces + 1;
}

/// @brief Funkcja zwracaj¹ca tablicê w formie tekstowej (nieposortowanej)
/// @param a - nieposortowana tablica tablica
void scalacz::zwrocTablice(string a) {
    int i = 0;
    while (i < dlugoscTablicy(a)) { // U¿ycie zaktualizowanej nazwy funkcji
        cout << tablica[i] << " , ";
        i++;
    }
}

/// @brief Funkcja konwertuj¹ca string tablica do tablicy int tablicaposortowana
/// @param spaces - liczba elementów tablicy tablicaposortowana
void scalacz::tablicatotabposortowana(int spaces) {
    int i = 0;
    while (i < (spaces)) {
        tablicaposortowana[i] = stoi(tablica[i]);
        i++;
    }
}

/// @brief Funkcja sortuj¹ca tablicê tablicaposortowana
/// @param spaces - liczba elementów tablicy tablicaposortowana
void scalacz::sortuj(int spaces) {
    int mnoznik = 1;

    while (mnoznik < spaces) {
        for (int i = 0; i < spaces; i += (2 * mnoznik)) {
            int mid = min(i + mnoznik, spaces);
            int end = min(i + 2 * mnoznik, spaces);

            int* temp = new int[spaces];
            int left = i, right = mid, k = i;

            while (left < mid && right < end) {
                if (tablicaposortowana[left] <= tablicaposortowana[right]) {
                    temp[k++] = tablicaposortowana[left++];
                }
                else {
                    temp[k++] = tablicaposortowana[right++];
                }
            }

            while (left < mid) {
                temp[k++] = tablicaposortowana[left++];
            }

            while (right < end) {
                temp[k++] = tablicaposortowana[right++];
            }

            for (int j = i; j < end; j++) {
                tablicaposortowana[j] = temp[j];
            }

            delete[] temp;
        }

        mnoznik *= 2;
    }
}

/// @brief Funkcja zwracaj¹ca posortowan¹ tablicê jako string
/// @param a - nieposortowana tablica tablica
string scalacz::zwracajTablice(string a) {
    if (tablica[0] == "") {
        return "";
    }
    else {
        int i = 0;
        string r;
        while (i < dlugoscTablicy(a)) { // U¿ycie zaktualizowanej nazwy funkcji
            r += to_string(tablicaposortowana[i]);
            if (i != (dlugoscTablicy(a) - 1)) { // U¿ycie zaktualizowanej nazwy funkcji
                r += " ";
            }
            i++;
        }
        return r;
    }
}
    /// @brief Funkcja zwracaj¹ca wskaŸnik na posortowan¹ tablicê
    int* scalacz::pobierzTablice() {
        return tablicaposortowana;
    }
