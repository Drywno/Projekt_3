#include <iostream>
#include "tab.h"

int main() {
    string a;
    cout << "Podaj liczby odzielone spacją: " << endl;
    getline(cin, a);

    merge b(a);

    b.returntab(a);
    cout << endl << endl;
    b.returntabs(a);
}
