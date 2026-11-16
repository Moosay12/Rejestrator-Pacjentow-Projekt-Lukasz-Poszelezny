#ifndef PACJENT_P_H
#define PACJENT_P_H
#include "pacjent.h"


class PacjentP : public Pacjent {
private:
    int numer_sali;
    int pobyt;
public:
    PacjentP(string i, string n, int w, string p, string ch, int pr, int sala, int dni);
    void wyswietl_dane() const override;
    double cena_leczenia() const override;
    string typ_pacjenta() const override;
};



#endif