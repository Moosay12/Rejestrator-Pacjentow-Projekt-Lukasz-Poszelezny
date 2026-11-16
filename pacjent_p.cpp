#include "pacjent_p.h"

PacjentP::PacjentP(string i, string n, int w, string p, string ch, int pr, int sala, int dni)
    : Pacjent(i, n, w, p, ch, pr) {
    numer_sali = sala;
    pobyt = dni;}
void PacjentP::wyswietl_dane() const {
    cout << "[PACJENT P] " << imie << " " << nazwisko 
         << " | Wiek: " << wiek << " | Sala nr: " << numer_sali 
         << " | Pobyt: " << pobyt << " dni" << endl;
}
double PacjentP::cena_leczenia() const {
    return pobyt * 150.0 + (priorytet * 200.0);}
string PacjentP::typ_pacjenta() const {
    return "pacjent_p";
}