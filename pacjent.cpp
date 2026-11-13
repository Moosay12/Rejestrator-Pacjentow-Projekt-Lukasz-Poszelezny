#include "Pacjent.h" 

Pacjent::Pacjent() {
    imie = "Brak";
    nazwisko = "Brak";
    wiek = 0;
    plec = "Brak";
    choroba = "Brak";
    priorytet = 1;
}
Pacjent::Pacjent(string i, string n, int w, string p, string ch, int pr) {
    ustaw_imie(i);
    ustaw_nazwisko(n);
    ustaw_wiek(w);
    ustaw_plec(p);
    ustaw_chorobe(ch);
    ustaw_priorytet(pr);
}

string Pacjent::dodaj_imie() const {
    return imie; }
string Pacjent::dodaj_nazwisko() const {
    return nazwisko;}
int Pacjent::dodaj_wiek() const {
    return wiek; }
string Pacjent::dodaj_plec() const {
    return plec; 
}

string Pacjent::dodaj_chorobe() const {
    return choroba; }

int Pacjent::dodaj_priorytet() const {
    return priorytet; 
}

void Pacjent::ustaw_imie(const string& i) {
    if (i == "") { 
        throw string("Blad: Imie nie moze byc puste!"); 
    }
    imie = i; }
void Pacjent::ustaw_nazwisko(const string& n) {
    if (n == "") { // Jesli nazwisko jest puste
        throw string("Blad: Nazwisko nie moze byc puste!");
    }
    nazwisko = n;
}
void Pacjent::ustaw_wiek(int w) {
    if (w < 0 || w > 130) { 
        throw string("Podano nieprawidlowy wiek pacjenta");
    }
    wiek = w;
}
void Pacjent::ustaw_plec(const string& p) {
    if (p == "") { 
        throw string("Plec nie moze byc pusta");}
    plec = p;
}
void Pacjent::ustaw_chorobe(const string& ch) {
    if (ch == "") { 
        throw string("Choroba nie moze byc pusta!");
    }
    choroba = ch;
}
void Pacjent::ustaw_priorytet(int pr) {
    if (pr < 1 || pr > 3) { 
        throw string("Priorytet musi wynosic 1 (niski), 2 (sredni) lub 3 (wysoki)!");
    }
    priorytet = pr;
}

bool Pacjent::operator==(const Pacjent& inny) const {
    return (imie == inny.imie && nazwisko == inny.nazwisko && wiek == inny.wiek);
}
bool Pacjent::operator<(const Pacjent& inny) const {
    return priorytet > inny.priorytet;
}
ostream& operator<<(ostream& os, const Pacjent& p) {
    os << "[" << p.typ_pacjenta() << "] "
       << p.imie << " " << p.nazwisko 
       << ", Wiek: " << p.wiek 
       << ", Plec: " << p.plec 
       << ", Choroba: " << p.choroba 
       << ", Priorytet: " << p.priorytet 
       << ", Koszt leczenia: " << p.cena_leczenia() << " PLN";
    return os;
}