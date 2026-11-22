#ifndef RECEPTA_H
#define RECEPTA_H
#include <string>
#include <iostream>
using namespace std;
class Recepta {
private:
    string stan_pacjenta;
    string zestaw_lekow;
    double koszt_lekow;
public:
    Recepta();
    void generuj_recepte();
    string pobierz_stan() const;
    string pobierz_zestaw() const;
    double pobierz_koszt() const;
    void wyswietl_recepte() const;
};

#endif