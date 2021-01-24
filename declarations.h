#ifndef declarations_h
#define declarations_h
#include <vector>
#include <stdio.h>
#include <string.h>
#include <cstring>
#include <fstream>
#include <array>
#include <regex>
using namespace std;
struct s_data_kalendarzowa{
    int dzien;
    int miesiac;
    int rok;
};
struct akta{
    char numer_akt[50];
    int typ_sprawy;
    s_data_kalendarzowa data_rozp;
    s_data_kalendarzowa data_zak;
    char oficer[256];
    char oskarzony[256];
    char poszkodowany[256];
    char swiadek[256];
};
void wczytaj_sprawe(akta &arg);
void data_input(s_data_kalendarzowa &numery);
void data_output(const s_data_kalendarzowa &numery);
void decode_typ_sprawy(int ar);
void zmiana_danych(vector<akta> &arch);
void wpisywanie_do_char_array(char tablica[], int a);
void wyswietl_element_struktury(akta &a);
void wyswietlanie_char_array(char tab[], int a);
void wyszukiwanie_po_numerze(const vector<akta> &arch);
void wyswietl_liste_akt(const vector<akta>&arch);
void dodaj_sprawe(vector<akta> &arch);
void usun_sprawe(vector<akta> &arch);
void wyszukiwanie_po_typie(const vector<akta> &arch);
void zapisz_do_pliku(vector<akta> &arch);
void wczytaj_z_pliku(vector<akta> &arch);
void dostepne_funkcje();
void wyswietl_zawartosc_struktury(vector<akta> &arch);
void sprawdz_plik(vector<akta> &arch);
void zmiana_danych2(akta &arg);
void wyrarzenia_regularne(const vector<akta> &arch);
char wybierz_czy_wpisac();
char opcje();
int wybierz_akta(vector<akta> &arch);
int def_typ_sprawy();
#endif
