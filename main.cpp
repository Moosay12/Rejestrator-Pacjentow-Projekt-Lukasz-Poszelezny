#include <iostream>
#include <string>
#include <thread>
#include <chrono>
#include "pacjent_p.h"
#include "pacjent_dziecko.h"
#include "Lekarz.h"
using namespace std;

void pasek_ladowania() {
    const int szerokosc = 20;
    cout << "Rejestrowanie wizyty..." << endl;
    for (int i = 0; i <= szerokosc; i++) {
        cout << "\r[";
        for (int j = 0; j < szerokosc; j++) {
            cout << (j < i ? "=" : " ");}
        cout << "] " << (i * 100) / szerokosc << "%";
        cout.flush();
        this_thread::sleep_for(chrono::milliseconds(100));}
    cout << "Wizyta zarejestrowana pomyslnie!" << endl;
}
int main(){
    string imie, nazwisko, plec, choroba;
    int wiek, priorytet, dni;
    cout << "=== REJESTRACJA PACJENTA ===" << endl;
    while (true) {
        cout << "Podaj imie: ";
        getline(cin, imie);
        if (imie != "") break;
        cout << "Imie nie moze byc puste" << endl;
    }
    while(true){
        cout << "Podaj nazwisko: ";
        getline(cin, nazwisko);
        if (nazwisko != "") break;
        cout << "Nazwisko nie moze byc puste" << endl;
    }
    while(true){
        cout << "Podaj wiek (0-130): ";
        cin >> wiek;
        cin.ignore();
        if (wiek >= 0 && wiek <= 130) break;
        cout << "Podano nieprawidlowy wiek" << endl;}
    while (true){
        cout << "Podaj plec: ";
        getline(cin, plec);
        if (plec != "") break;
        cout << "Plec nie moze byc pusta" << endl;
    }
    while(true){
        cout << "Podaj chorobe: ";
        getline(cin, choroba);
        if (choroba != "") break;
        cout << "Choroba nie moze byc pusta" << endl;
    }
    while(true){
        cout << "Podaj priorytet (1 - stabilny, 2 - pilny, 3 - zagrozenie zycia): ";
        cin >> priorytet;
        if (priorytet >= 1 && priorytet <= 3) break;
        cout << "Priorytet musi wynosic 1, 2 lub 3" << endl;
    }

    while(true) {
        cout << "Podaj liczbe dni pobytu: ";
        cin >> dni;
        cin.ignore();
        if (dni > 0) break;
        cout << "Liczba dni musi byc wieksza od 0" << endl;}
    Pacjent* pacjent = nullptr;
    try {
        if (wiek < 18){
            string opiekun, telefon;
            cout << "Pacjent niepelnoletni - wymagane dane opiekuna." << endl;
            while (true){
                cout << "Podaj imie i nazwisko opiekuna: ";
                getline(cin, opiekun);
                if (opiekun != "") break;
                cout << "Dane opiekuna nie moga byc puste!" << endl;}
            while (true){
                cout << "Podaj telefon opiekuna: ";
                getline(cin, telefon);
                if (telefon != "") break;
                cout << "Telefon nie moze byc pusty!" << endl;}
            pacjent = new PacjentDziecko(imie, nazwisko, wiek, plec, choroba, priorytet, opiekun, telefon, dni);
        } else{
            int sala;
            while (true){
                cout << "Podaj numer sali: ";
                if (!(cin >> sala)) {
                    cin.clear();
                    cin.ignore(10000, '\n');
                    cout << "Wpisz numer sali jako liczbe" << endl;
                    continue;}
                if (sala > 0) break;
                cout << "Numer sali musi byc wiekszy od 0" << endl;}
            pacjent = new PacjentP(imie, nazwisko, wiek, plec, choroba, priorytet, sala, dni);
        }
        Lekarz przypisany_lekarz(pacjent->dodaj_priorytet());
        pasek_ladowania();
        cout << "=== PODSUMOWANIE PRZYJECIA ===" << endl;
        pacjent->wyswietl_dane();
        cout << *pacjent << endl;
        przypisany_lekarz.wyswietl_lekarza();}
    catch (const string& blad) {
        cout << "Wystapil blad: " << blad << endl;
    }
    delete pacjent;
     cout << "Nacisnij Enter,aby zakonczyc rejestrace" << endl;
    cin.ignore(10000, '\n');
    cin.get();
    return 0;
}