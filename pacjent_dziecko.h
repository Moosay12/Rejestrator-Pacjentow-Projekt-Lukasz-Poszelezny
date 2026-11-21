#ifndef PACJENT_DZIECKO_H
#define PACJENT_DZIECKO_H
#include "pacjent.h"
class PacjentDziecko : public Pacjent {
private:
    string opiekun;
    string telefon_opiekuna;
    int pobyt;

public:
    PacjentDziecko();
    PacjentDziecko(string i, string n, int w, string p, string ch, int pr, string op, string tel, int dni);
    string dodaj_opiekuna() const;
    string dodaj_telefon_opiekuna() const;
    int dodaj_pobyt() const;
    void ustaw_opiekuna(const string& op);
    void ustaw_telefon_opiekuna(const string& tel);
    void ustaw_pobyt(int dni);
    void wyswietl_dane() const override;
    double cena_leczenia() const override;
    string typ_pacjenta() const override;
};

#endif