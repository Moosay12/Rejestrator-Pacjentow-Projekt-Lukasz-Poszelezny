#include "recepta.h"
#include <cstdlib>
Recepta::Recepta(){
    generuj_recepte();
}
void Recepta::generuj_recepte(){
    int los = rand() % 3;
    if (los == 0) {
        stan_pacjenta = "Dobry";
        zestaw_lekow = "Profilaktyczne";
        koszt_lekow = 50.0;
    } 
    else if (los == 1) {
        stan_pacjenta = "Stabilny";
        zestaw_lekow = "Wspomagajace";
        koszt_lekow = 120.0;} 
    else {
        stan_pacjenta = "Pilny";
        zestaw_lekow = "Silne";
        koszt_lekow = 250.0;
    }
}
string Recepta::pobierz_stan() const{ 
    return stan_pacjenta; 
}
string Recepta::pobierz_zestaw() const{ 
    return zestaw_lekow; }
double Recepta::pobierz_koszt() const{ 
    return koszt_lekow; }
void Recepta::wyswietl_recepte() const {
    cout << "\n=== WYSTAWIONA RECEPTA ===" << endl;
    cout << "Stan pacjenta po wizycie: " << stan_pacjenta << endl;
    cout << "Przydzielony zestaw lekow: " << zestaw_lekow <<  endl;
    cout << "Koszt lekow: " << koszt_lekow << " PLN" << endl;
}