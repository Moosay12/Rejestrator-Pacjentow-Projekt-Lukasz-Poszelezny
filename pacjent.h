#ifndef PACJENT_H 
#define PACJENT_H
#include <string>    
#include <iostream>  
using namespace std;

class Pacjent { 
protected:
    string imie;
    string nazwisko;
    int wiek;
    string plec;
    string choroba;
    int priorytet;

public:
    Pacjent(); 
    Pacjent(string i, string n, int w, string p, string ch, int pr);
    virtual ~Pacjent() = default;
    string dodaj_imie() const;
    string dodaj_nazwisko() const;
    int dodaj_wiek() const;
    string dodaj_plec() const;
    string dodaj_chorobe() const;
    int dodaj_priorytet() const;
    void ustaw_imie(const string& i);
    void ustaw_nazwisko(const string& n);
    void ustaw_wiek(int w);
    void ustaw_plec(const string& p);
    void ustaw_chorobe(const string& ch);
    void ustaw_priorytet(int pr);
    virtual void wyswietl_dane() const = 0;
    virtual double cena_leczenia() const = 0;
    virtual string typ_pacjenta() const = 0;
    bool operator==(const Pacjent& inny) const; 
    bool operator<(const Pacjent& inny) const;
    friend ostream& operator<<(ostream& os, const Pacjent& p);
};

#endif