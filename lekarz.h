#ifndef LEKARZ_H
#define LEKARZ_H

#include <string>
#include <iostream>
using namespace std;

class Lekarz {
private:
    string imie;
    string nazwisko;
    string specjalizacja;
    int obslugiwany_priorytet;

public:
    Lekarz();
    Lekarz(int pr);
    Lekarz(string i, string n, string spec, int pr);
    string dodaj_imie() const;
    string dodaj_nazwisko() const;
    string dodaj_specjalizacje() const;
    int dodaj_obslugiwany_priorytet() const;
    void ustaw_imie(const string& i);
    void ustaw_nazwisko(const string& n);
    void ustaw_specjalizacje(const string& spec);
    void ustaw_obslugiwany_priorytet(int pr);
    void przypisz_z_bazy(int pr);
    void wyswietl_lekarza() const;
};

#endif