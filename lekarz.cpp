#include "lekarz.h"


Lekarz::Lekarz() {
    przypisz_z_bazy(1);
}


Lekarz::Lekarz(int pr) {
    przypisz_z_bazy(pr);
}  


Lekarz::Lekarz(string i, string n, string spec, int pr) {
    ustaw_imie(i);
    ustaw_nazwisko(n);
    ustaw_specjalizacje(spec);
    ustaw_obslugiwany_priorytet(pr);
}


void Lekarz::przypisz_z_bazy(int pr) {
    if (pr == 1) {
        imie = "Filip";
        nazwisko = "Stefaniak";
        specjalizacja = "Internista";
        obslugiwany_priorytet = 1;
    } 
    else if (pr == 2) {
        imie = "Antoni";
        nazwisko = "Baltoski";
        specjalizacja = "Specjalista Dyzurny";
        obslugiwany_priorytet = 2;
    } 
    else if (pr == 3) {
        imie = "Mikołaj";
        nazwisko = "Cywiński";
        specjalizacja = "Chirurg Ratunkowy SOR";
        obslugiwany_priorytet = 3;
    } 
    else {
        throw string("Nie ma lekarza w bazie dla takiego priorytetu (dozwolone 1-3)");
    }
}


string Lekarz::dodaj_imie() const { return imie; }
string Lekarz::dodaj_nazwisko() const { return nazwisko; }
string Lekarz::dodaj_specjalizacje() const { return specjalizacja; }
int Lekarz::dodaj_obslugiwany_priorytet() const { return obslugiwany_priorytet; }


void Lekarz::ustaw_imie(const string& i) {
    if (i == "") throw string("Blad: Imie lekarza nie moze byc puste!");
    imie = i;
}

void Lekarz::ustaw_nazwisko(const string& n) {
    if (n == "") throw string("Blad: Nazwisko lekarza nie moze byc puste!");
    nazwisko = n;
}

void Lekarz::ustaw_specjalizacje(const string& spec) {
    if (spec == "") throw string("Blad: Specjalizacja nie moze byc pusta!");
    specjalizacja = spec;
}

void Lekarz::ustaw_obslugiwany_priorytet(int pr) {
    if (pr < 1 || pr > 3) throw string("Blad: Priorytet musi wynosic 1, 2 lub 3!");
    obslugiwany_priorytet = pr;
}


void Lekarz::wyswietl_lekarza() const {
    cout << "Przydzielony lekarz: dr " << imie << " " << nazwisko 
         << " - " << specjalizacja << endl;}