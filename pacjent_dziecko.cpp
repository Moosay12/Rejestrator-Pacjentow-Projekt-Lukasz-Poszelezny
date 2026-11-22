#include "pacjent_dziecko.h"

PacjentDziecko::PacjentDziecko() : Pacjent() {
    opiekun = "Brak";
    telefon_opiekuna = "Brak";
    pobyt = 1;}
PacjentDziecko::PacjentDziecko(string i, string n, int w, string p, string ch, int pr, string op, string tel, int dni)
    : Pacjent(i, n, w, p, ch, pr) {
    if (w >= 18) {
        throw string("PacjentDziecko musi miec mniej niz 18 lat!");}
    ustaw_opiekuna(op);
    ustaw_telefon_opiekuna(tel);
    ustaw_pobyt(dni);
}
string PacjentDziecko::dodaj_opiekuna() const{ 
    return opiekun; 
}
string PacjentDziecko::dodaj_telefon_opiekuna() const{
    return telefon_opiekuna;}
int PacjentDziecko::dodaj_pobyt() const{ 
    return pobyt;}
void PacjentDziecko::ustaw_opiekuna(const string& op) {
    if (op == "") throw string("Dane opiekuna nie moga byc puste!");
    opiekun = op;}
void PacjentDziecko::ustaw_telefon_opiekuna(const string& tel){
    if (tel == "") throw string("Telefon opiekuna nie moze byc pusty!");
    telefon_opiekuna = tel;
}
void PacjentDziecko::ustaw_pobyt(int dni){
    if (dni <= 0) throw string("Liczba dni pobytu musi byc wieksza od 0!");
    pobyt = dni;
}
void PacjentDziecko::wyswietl_dane() const{
    cout << "[PACJENT DZIECKO] " << imie << " " << nazwisko
         << " | Wiek: " << wiek
         << " | Pobyt: " << pobyt << " dni"
         << " | Opiekun: " << opiekun << " (tel. " << telefon_opiekuna << ")" << endl;}
double PacjentDziecko::cena_leczenia() const{
    return pobyt * 100.0;}
string PacjentDziecko::typ_pacjenta() const{
    return "PacjentDziecko";
}