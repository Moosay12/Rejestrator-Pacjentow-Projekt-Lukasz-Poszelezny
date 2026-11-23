#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <thread>
#include <chrono>
#include <ctime>
#include "pacjent_p.h"
#include "pacjent_dziecko.h"
#include "lekarz.h"
#include "recepta.h"
using namespace std;

void pasek_ladowania() {
    const int szerokosc = 20;
    cout << "Rejestrowanie wizyty..." << endl;
    for (int i = 0; i <= szerokosc; i++) {
        cout << "\r[";
        for (int j = 0; j < szerokosc; j++) {
            cout << (j < i ? "=" : " ");
        }
        cout << "] " << (i * 100) / szerokosc << "%";
        cout.flush();
        this_thread::sleep_for(chrono::milliseconds(100));
    }
    cout << endl << "Wizyta zarejestrowana pomyslnie!" << endl;
}

int main() {
    srand(time(0));
    vector<Pacjent*> kolejka; 
    int wybor = 0;
    while (wybor != 4) {
        cout << "\n=== MENU GLOWNE ===" << endl;
        cout << "1. Dodaj nowego pacjenta" << endl;
        cout << "2. Wyswietl kolejke pacjentow" << endl;
        cout << "3. Usun pacjenta z kolejki" << endl;
        cout << "4. Zakoncz program" << endl;
        cout << "Wybierz opcje: ";
        if (!(cin >> wybor)) {
            cin.clear();
            cin.ignore(10000, '\n');
            cout << "Wpisz poprawny numer opcji (1-4)!" << endl;
            continue;}
        cin.ignore(10000, '\n'); 
        if (wybor == 1) {
            string imie, nazwisko, plec, choroba;
            int wiek, priorytet, dni;
            cout << "\n=== REJESTRACJA PACJENTA ===" << endl;
            while (true) {
                cout << "Podaj imie: ";
                getline(cin, imie);
                if (imie != "") break;
                cout << "Imie nie moze byc puste" << endl;}
            while (true) {
                cout << "Podaj nazwisko: ";
                getline(cin, nazwisko);
                if (nazwisko != "") break;
                cout << "Nazwisko nie moze byc puste" << endl;
            }
            while (true) {
                cout << "Podaj wiek (0-130): ";
                if (!(cin >> wiek)) {
                    cin.clear();
                    cin.ignore(10000, '\n');
                    cout << "Wpisz wiek jako liczbe" << endl;
                    continue;
                }
                cin.ignore(10000, '\n');
                if (wiek >= 0 && wiek <= 130) break;
                cout << "Podano nieprawidlowy wiek" << endl;
            }
            while (true) {
                cout << "Podaj plec: ";
                getline(cin, plec);
                if (plec != "") break;
                cout << "Plec nie moze byc pusta" << endl;
            }
            while (true) {
                cout << "Podaj chorobe: ";
                getline(cin, choroba);
                if (choroba != "") break;
                cout << "Choroba nie moze byc pusta" << endl;
            }
            while (true) {
                cout << "Podaj priorytet (1 - stabilny, 2 - pilny, 3 - zagrozenie zycia): ";
                if (!(cin >> priorytet)) {
                    cin.clear();
                    cin.ignore(10000, '\n');
                    cout << "Wpisz priorytet jako liczbe" << endl;
                    continue;
                }
                if (priorytet >= 1 && priorytet <= 3) break;
                cout << "Priorytet musi wynosic 1, 2 lub 3" << endl;
            }
            while (true) {
                cout << "Podaj liczbe dni pobytu: ";
                if (!(cin >> dni)) {
                    cin.clear();
                    cin.ignore(10000, '\n');
                    cout << "Wpisz liczbe dni jako liczbe" << endl;
                    continue;
                }
                cin.ignore(10000, '\n');
                if (dni > 0) break;
                cout << "Liczba dni musi byc wieksza od 0" << endl;
            }

            Pacjent* pacjent = nullptr;
            try {
                if (wiek < 18) {
                    string opiekun, telefon;
                    cout << "Pacjent niepelnoletni - wymagane dane opiekuna." << endl;
                    while (true) {
                        cout << "Podaj imie i nazwisko opiekuna: ";
                        getline(cin, opiekun);
                        if (opiekun != "") break;
                        cout << "Dane opiekuna nie moga byc puste!" << endl;
                    }
                    while (true) {
                        cout << "Podaj telefon opiekuna: ";
                        getline(cin, telefon);
                        if (telefon != "") break;
                        cout << "Telefon nie moze byc pusty!" << endl;
                    }
                    pacjent = new PacjentDziecko(imie, nazwisko, wiek, plec, choroba, priorytet, opiekun, telefon, dni);
                } else {
                    int sala;
                    while (true) {
                        cout << "Podaj numer sali: ";
                        if (!(cin >> sala)) {
                            cin.clear();
                            cin.ignore(10000, '\n');
                            cout << "Wpisz numer sali jako liczbe" << endl;
                            continue;
                        }
                        cin.ignore(10000, '\n');
                        if (sala > 0) break;
                        cout << "Numer sali musi byc wiekszy od 0" << endl;
                    }
                    pacjent = new PacjentP(imie, nazwisko, wiek, plec, choroba, priorytet, sala, dni);
                }

                
                bool istnieje = false;
                for (Pacjent* p : kolejka) {
                    if (*p == *pacjent) {
                        istnieje = true;
                        break;
                    }
                }

                if (istnieje) {
                    cout << "Taki pacjent jest juz zarejestrowany w kolejce!" << endl;
                    delete pacjent;
                    continue;
                }

                Lekarz przypisany_lekarz(pacjent->dodaj_priorytet());
                pasek_ladowania();

                kolejka.push_back(pacjent); 

                cout << "=== PODSUMOWANIE PRZYJECIA ===" << endl;
                pacjent->wyswietl_dane();
                cout << *pacjent << endl;
                przypisany_lekarz.wyswietl_lekarza();
                Recepta recepta;
                recepta.wyswietl_recepte();
                double koszt_calkowity = pacjent->cena_leczenia() + recepta.pobierz_koszt();
                cout << "LACZNY KOSZT WIZYTY (leczenie + leki): " << koszt_calkowity << " PLN" << endl;
            }
            catch (const string& blad) {
                cout << "Wystapil blad: " << blad << endl;
                delete pacjent;
            }
        }
        else if (wybor == 2) {
            if (kolejka.empty()) {
                cout << "Kolejka pacjentow jest pusta." << endl;
            } else {
               
                sort(kolejka.begin(), kolejka.end(), [](const Pacjent* a, const Pacjent* b) {
                    return *a < *b;
                });

                cout << "\n=== KOLEJKA PACJENTOW (WG PRIORYTETU) ===" << endl;
                for (size_t i = 0; i < kolejka.size(); i++) {
                    cout << i + 1 << ". " << *kolejka[i] << endl;
                }
            }
        }
        else if (wybor == 3) {
            if (kolejka.empty()) {
                cout << "Brak pacjentow do usuniecia." << endl;
            } else {
                cout << "\n=== USUN PACJENTA ===" << endl;
                for (size_t i = 0; i < kolejka.size(); i++) {
                    cout << i + 1 << ". " << *kolejka[i] << endl;
                }
                int nr;
                cout << "Podaj numer pacjenta do usuniecia (0 - anuluj): ";
                if (cin >> nr && nr >= 1 && nr <= (int)kolejka.size()) {
                    delete kolejka[nr - 1]; 
                    kolejka.erase(kolejka.begin() + (nr - 1)); 
                    cout << "Pacjent usuniety z kolejki." << endl;
                } else {
                    cin.clear();
                    cin.ignore(10000, '\n');
                    cout << "Anulowano lub podano bledny numer." << endl;
                }
            }
        }
        else if (wybor != 4) {
            cout << "Nieznana opcja. Wybierz 1-4." << endl;
        }
    }

    
    for (Pacjent* p : kolejka) {
        delete p;
    }
    kolejka.clear();

    cout << "Nacisnij Enter, aby zakonczyc program" << endl;
    cin.get();
    return 0;
}