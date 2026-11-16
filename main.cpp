#include <iostream>
#include "pacjent_p.h"
using namespace std;

int main() {
    PacjentP pacjent1("Jan", "Kowalski", 45, "Mezczyzna", "Zapalenie pluc", 2, 104, 5);
    PacjentP pacjent2("Kajetan", "Dudek", 50, "Mezczyzna", "Zlamanie", 3, 201, 3);
    PacjentP pacjent3("Sakub", "Jolarek", 30, "Kobieta", "Migrena", 1, 205, 1);
    cout << "=== LISTA PACJENTOW ===" << endl;
    pacjent1.wyswietl_dane();
    pacjent2.wyswietl_dane();
    pacjent3.wyswietl_dane();
    cout << pacjent1 << endl;
    cout << pacjent2 << endl;
    PacjentP pacjent4("Jan", "Kowalski", 45, "Mezczyzna", "Inna choroba", 1, 100, 1);
    if (pacjent1 == pacjent4) {
        cout << "Pacjent 1 i Pacjent 4 to ta sama osoba." << endl;
    } else {
        cout << "Pacjent 1 i Pacjent 4 to inne osoby." << endl;}
    if (pacjent3 < pacjent2) {
            cout << "Pacjent 2 ma wyzszy priorytet w kolejce niz Pacjent 3." << endl;}

    return 0;
}