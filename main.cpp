#include <iostream>
#include "declarations.h"
int main(){
    char zmienna='0';
    vector<akta> archiwum_kryminalne;
    while(zmienna!='q'){
        zmienna=opcje();
    switch (zmienna) {
        case '1':
            cout<<endl;
            wyswietl_liste_akt(archiwum_kryminalne);
            break;
        case '2':
            cout<<endl;
            dodaj_sprawe(archiwum_kryminalne);
            break;
        case '3':
            cout<<endl;
            usun_sprawe(archiwum_kryminalne);
            break;
        case '4':
            cout<<endl;
            zmiana_danych(archiwum_kryminalne);
            break;
        case '5':
            cout<<endl;
            wyszukiwanie_po_numerze(archiwum_kryminalne);
            break;
        case '6':
            cout<<endl;
            wyszukiwanie_po_typie(archiwum_kryminalne);
        case '7':
            cout<<endl;
            zapisz_do_pliku(archiwum_kryminalne);
            break;
        case '8':
            cout<<endl;
            sprawdz_plik(archiwum_kryminalne);//wczytaj z pliku
            break;
        case '9':
            cout<<endl;
            wyswietl_zawartosc_struktury(archiwum_kryminalne);
            break;
        case '0':
            cout<<endl;
            wyrarzenia_regularne(archiwum_kryminalne);
            break;
        case 'q':
            return 0;
        default:
            cout<<"Nieprawidlowy znak, podaj opcje jeszcze raz: ";
            break;
    }
}
    return 0;
}
void zapisz_do_pliku(vector<akta> &archiwum_krym){
    ofstream plik;
    char a;
    cout<<"1. Nadpisz plik.\n2. Dopisz do pliku na jego koniec.\n3. Zapisz wszystkie dane nadpisujac plik.\n4. Zapisz wszystkie dane dopisujac do pliku.\n5. Nie zapisuj.\nPodaj, jak chcesz zapisac dane: ";
    cin>>a;
    switch (a) {
        case '1':
            plik.open("tekstowy.txt", ios::out);
            if(plik.is_open()){
                cout<<"Plik zostal otwarty!\n";
                akta nowe;
                nowe=archiwum_krym.at(wybierz_akta(archiwum_krym));
                plik.write((const char*)&nowe, sizeof(nowe));
                plik.close();
            }
            else
                cout<<"Blad otwierania pliku.\n";
            break;
        case '2':
            plik.open("tekstowy.txt", ios::out | ios::app);
            if(plik.is_open()){
                akta nowe;
                nowe=archiwum_krym.at(wybierz_akta(archiwum_krym));
                plik.write((const char*)&nowe, sizeof(nowe));
                plik.close();
            }
            else
                cout<<"Blad otwierania pliku.\n";
            break;
        case '3':
            plik.open("tekstowy.txt", ios::out);
            if(plik.is_open()){
                cout<<"Plik zostal otwarty!\n";
                akta nowe;
                for(int i =0; i<archiwum_krym.size();i++){
                    nowe=archiwum_krym.at(i);
                    plik.write((const char*)&nowe, sizeof(nowe));
                }
                plik.close();
            }
            else
                cout<<"Blad otwierania pliku.\n";
                break;
        case '4':
            plik.open("tekstowy.txt", ios::out | ios::app);
            if(plik.is_open()){
                akta nowe;
                for(int i =0; i<archiwum_krym.size();i++){
                nowe=archiwum_krym.at(i);
                plik.write((const char*)&nowe, sizeof(nowe));
                }
                plik.close();
            }
            else
                cout<<"Blad otwierania pliku.\n";
        case '5':
            cout<<"Nie wprowadzono zadnych zmian.\n";
            break;
        default:
            cout<<"Nieprawidlowy znak.";
            break;
    }
}
void sprawdz_plik(vector<akta> &archiwum_krym){
    fstream plik;
    plik.open("tekstowy.txt", ios::in);
    if(plik.good()==false){
        cout<<"Plik nie istnieje"<<endl;
        plik.close();
    }
    else{
        cout<<"Plik zostal poprawnie otwarty.\n";
        plik.close();
        wczytaj_z_pliku(archiwum_krym);
}
}
void wczytaj_z_pliku(vector<akta> &archiwum_krym){
    fstream plik;
    plik.open("tekstowy.txt", ios::in);
        do{
        akta nowe;
        plik.read((char*)&nowe, sizeof(nowe));
        archiwum_krym.push_back(nowe);
    }
    while(!plik.eof());
    plik.close();
    archiwum_krym.pop_back();
}
void wyswietl_liste_akt(const vector<akta> &typ){
    int i=0;
    for(auto &j: typ){
            i++;
            cout<<"Pozycja na liscie: "<<i<<", numer akt: "<<j.numer_akt<<endl;
    }
    }
void dodaj_sprawe(vector<akta> &archiwum_krym){
    akta nowa;
    wczytaj_sprawe(nowa);
    archiwum_krym.push_back(nowa);
}
void wczytaj_sprawe(akta&  sprawa){
            cout<<"Numer akt: ";
            wpisywanie_do_char_array(sprawa.numer_akt, 50);
            sprawa.typ_sprawy=def_typ_sprawy();
            cout<<"Data rozpoczecia: \n";
            data_input(sprawa.data_rozp);
            cout<<"Data zakonczenia:";
            if(wybierz_czy_wpisac()=='y'){cout<<"Wpisz: ";
            data_input(sprawa.data_zak);
                while(sprawa.data_zak.rok<sprawa.data_rozp.rok){
                    cout<<"Blad wprowadzenia daty, podaj jeszcze raz:";
                    data_input(sprawa.data_zak);}}
            cout<<"Oficer prowadzacy: ";
            wpisywanie_do_char_array(sprawa.oficer, 256);
            cout<<"Imie i Nazwisko oskarzonego:";
            if(wybierz_czy_wpisac()=='y'){cout<<"Wpisz: ";
            wpisywanie_do_char_array(sprawa.oskarzony, 256);}
            cout<<"Imie i Nazwisko poszkodowanego:";
            if(wybierz_czy_wpisac()=='y'){cout<<"Wpisz: ";
            wpisywanie_do_char_array(sprawa.poszkodowany, 256);}
            cout<<"Swiadek: ";
            wpisywanie_do_char_array(sprawa.swiadek, 256);
        }
char wybierz_czy_wpisac()
{
    char a='a';
    cout<<"\nWpisz 'Y' jeżeli chcesz wpisac, 'n' jezeli pominac: ";
    cin>>a;
    while(a=='Y' || a=='y')
    return 'y';
    return 'n';
}
void wpisywanie_do_char_array(char tab[], int si){
    cin.ignore();
    cin.getline(tab, si);
}
void wyswietlanie_char_array(char tab[], int a){
    int i=0;
    while(tab[i] !='\0'){
        cout<<tab[i];
        i++;
    }
    cout<<endl;
}
int def_typ_sprawy(){
    int rodzaj = 0;
    cout<<"Wybierz typ sprawy: \n1.Wykroczenie drogowe\n2.Kradziez\n3.Wymuszenie\n4.Rozboj\n5.Zabojstwo\n6.Cyberprzestepstwo\n7.Bez kategorii\nPodaj numer: ";
    do{
    while (cout<<"Podaj ktore akta chcesz wybrac: " && !(cin >> rodzaj)) {
        cin.clear(); //clear bad input flag
        cin.ignore(numeric_limits<streamsize>::max(), '\n'); //discard input
        cout << "Zly znak; podaj poprawny numer:\n";
    }
    }
    while(rodzaj<1 || rodzaj>7);
    return rodzaj;
}
void decode_typ_sprawy(int a){
    switch (a) {
        case 1:
            cout<<"1.Wykroczenie drogowe";
            break;
        case 2:
            cout<<"2.Kradziez";
            break;
        case 3:
            cout<<"Wymuszenie";
            break;
        case 4:
            cout<<"4.Rozboj";
            break;
        case 5:
            cout<<"5.Zabojstwo";
            break;
        case 6:
            cout<<"6.Cyberprzestepstwo";
            break;
        case 7:
            cout<<"Bez kategorii";
            break;
    }
}
void data_input(s_data_kalendarzowa&  data){
    cout<<"Podaj dzien: ";
    cin>>data.dzien;
    while(data.dzien<1 || data.dzien>31){
        cout<<"Nieprawidlowe dane, wpisz poprawny dzien: ";
        cin>>data.dzien;
    }
    cout<<"Podaj miesiac: ";
    cin>>data.miesiac;
    while(data.miesiac <1 || data.miesiac>12){
        cout<<"Nieprawidlowe dane, wpisz poprawny miesiac: ";
        cin>>data.miesiac;
    }
    cout<<"Podaj rok:";
    cin>>data.rok;
       while(data.rok <1 || data.rok>2021){
        cout<<"Nieprawidlowe dane, wpisz poprawny rok: ";
        cin>>data.rok;
        }
}
void data_output(const s_data_kalendarzowa&  data){
    cout<<data.dzien<<"/"<<data.miesiac<<"/"<<data.rok<<endl;
}
int wybierz_akta(vector<akta> &arch){
    cout<<"Wybierz akta: \nDostepne akta: \n";
    wyswietl_liste_akt(arch);
    int a=0;
    do{
    while (cout<<"Podaj ktore akta chcesz wybrac: " && !(std::cin >> a)) {
        cin.clear(); //clear bad input flag
        cin.ignore(std::numeric_limits<streamsize>::max(), '\n'); //discard input
        cout << "Zly znak; podaj poprawny numer:\n";
    }
    }
    while(a>(arch.size()+1));
    return (a-1);
}
void usun_sprawe(vector<akta> &archiwum_krym){
    size_t i = 0;
    cout<<"Podaj ktore akta chcesz usunac: \n";
    wyswietl_liste_akt(archiwum_krym);
    do{
    while (cout<<"Podaj ktore akta chcesz wybrac: " && !(std::cin >> i)) {
        cin.clear(); //clear bad input flag
        cin.ignore(std::numeric_limits<streamsize>::max(), '\n'); //discard input
        cout << "Zly znak; podaj poprawny numer:\n";
    }
    }
    while(i>(archiwum_krym.size()+1));
    archiwum_krym.erase(archiwum_krym.begin()+(i-1));
}

void zmiana_danych(vector<akta> &arch){
    akta *sprawa;
    size_t a=wybierz_akta(arch);
    sprawa=&arch.at(a);
    wyswietl_element_struktury(*sprawa);
    wczytaj_sprawe(*sprawa);
}
void zmiana_danych2(akta &sprawa){
    char a='a';
    cout<<"\nPodaj jakie dane chcesz zmienic:\n1.Numer akt\n2.Typ sprawy\n3.Date rozpoczecia\n4.Date zakonczenia\n5.Oficera prowadzacego\n6.Oskarzonego\n7.Poszkodowanego\n8.Swiadka\n9.Nic nie zmieniaj\nPodaj liczbe: ";
    cin>>a;
        switch (a) {
            case '1':
                cout<<"Podaj nowy numer akt: ";
                wpisywanie_do_char_array(sprawa.numer_akt, 50);
                break;
            case '2':
                cout<<"Podaj nowy typ sprawy: ";
                sprawa.typ_sprawy=def_typ_sprawy();
                break;
            case '3':
                cout<<"Nowa data rozpoczecia:\n";
                data_input(sprawa.data_rozp);
                break;
            case '4':
                cout<<"Nowa data zakonczenia:\n";
                data_input(sprawa.data_zak);
                break;
            case '5':
                cout<<"Nowy oficer prowadzacy: ";
                wpisywanie_do_char_array(sprawa.oficer, 256);
                break;
            case '6':
                cout<<"Nowe Imie i Nazwisko oskarzonego \n(Pozostaw puste, jezeli nie ma): ";
                wpisywanie_do_char_array(sprawa.oskarzony, 256);
                break;
            case '7':
                cout<<"Nowe Imie i Nazwisko poszkodowanego \n(Pozostaw puste, jezeli nie ma): ";
                wpisywanie_do_char_array(sprawa.poszkodowany, 256);
                break;
            case '8':
                cout<<"Swiadek \n(Pozostaw puste, jezeli nie ma): ";
                wpisywanie_do_char_array(sprawa.swiadek, 256);
                break;
            default:
                break;
        }
}
void wyszukiwanie_po_numerze(const vector<akta>& szukany){
    char stt[50];
    int licz=0, a=0;
    cout<<"Podaj szukany numer sprawy: ";
    cin.ignore();
    cin.getline(stt, 50);
    for(auto &p:szukany)
        {
            licz++;
        if(strcmp(p.numer_akt ,stt)==0){
            cout<<"Znaleziono akta na pozycji "<<licz<<endl;
            a++;
        }
        }
    if(a==0)
        cout<<"Nieznaleziono akt o podanym numerze.\n";
}
void wyszukiwanie_po_typie(const vector<akta>& szukany){
    
    int licz=0, a=0, b=0;
    a=def_typ_sprawy();
    for(auto &p:szukany)
        {
            licz++;
        if (p.typ_sprawy==a){
                cout<<"Znaleziono akta na pozycji "<<licz<<endl;
            b++;
        }
    }
    if(b==0)
        cout<<"Nie znaleziono akt o podanym numerze.\n";
}
void dostepne_funkcje(){
    cout<<"\n1. Wyswietl liste akt.\n2. Dodaj akta.\n3. Usun akta.\n4. Zmien dane w aktach.\n5. Wyszukaj akta po numerze.\n6. Wyszukaj akta po typie.\n7. Zapisz zgromadzone dane do pliku.\n8. Odczytaj dane z pliku.\n9. Wyswitl szczegoly akt.\n0. Wyszukaj po wyrarzeniu.\nq. Wyjscie z programu.";
}
char opcje(){
    char a='a';
    cout<<"Menu wyboru dostepnych funkcji. ";
    dostepne_funkcje();
    cout<<"\nPodaj z jakiej funkcji chcesz skorzystac: ";
    cin>>a;
    return a;
}
 void wyswietl_element_struktury(akta &sprawa){
     cout<<"\nNumer akt: ";
     wyswietlanie_char_array(sprawa.numer_akt, 50);
     cout<<"Typ sprawy: ";
     decode_typ_sprawy(sprawa.typ_sprawy);
     cout<<"\nData rozpoczecia: ";
     data_output(sprawa.data_rozp);
     cout<<"Data zakonczenia: ";
     data_output(sprawa.data_zak);
     cout<<"Oficer prowadzacy: ";
     wyswietlanie_char_array(sprawa.oficer, 256);
     cout<<"Oskarzony: ";
     wyswietlanie_char_array(sprawa.oskarzony, 256);
     cout<<"Poszkodowany: ";
     wyswietlanie_char_array(sprawa.poszkodowany, 256);
     cout<<"Swiadek: ";
     wyswietlanie_char_array(sprawa.swiadek, 256);
 }
 
void wyswietl_zawartosc_struktury(vector<akta> &arch)
{
    wyswietl_liste_akt(arch);
    size_t a = 0;
    do{
    while (cout<<"Podaj ktore akta chcesz wyswietlic: " && !(std::cin >> a)) {
        cin.clear(); //clear bad input flag
        cin.ignore(std::numeric_limits<streamsize>::max(), '\n'); //discard input
        cout << "Zly znak; podaj poprawny numer:\n";
    }
    }
    while(a>(arch.size()+1));
    wyswietl_element_struktury(arch[a-1]);
}
void wyrarzenia_regularne(const vector<akta> &archiwum_krym)
{
    if(archiwum_krym.empty())
    {
        cout<<"Brak danych w archiwum";
        return;
    }
    char a;
    char *tab=(char*)malloc(sizeof(char)*251);
    if(tab==0)
        return;
    cout<<"Podaj wyrażenie regularne(do 256 znakow): ";
    wpisywanie_do_char_array(tab, 256);
    regex reg (tab);
    free(tab);
    cout<<"Czy cały ciąg znaków musi spełniać warunek? Y jeśli tak: ";
    cin>>a;
    int num=0;
    if(a=='Y' || a=='y')
    for(auto &i: archiwum_krym)
    {
        num++;
        if(regex_match (i.numer_akt,reg))
            cout<<"Znaleziono \""<<i.numer_akt<<"\" sa to akta nr "<<num<<endl;
        else if(regex_match (i.oficer,reg))
            cout<<"Znaleziono \""<<i.oficer<<"\" sa to akta nr "<<num<<endl;
        else if(regex_match (i.oskarzony,reg))
            cout<<"Znaleziono \""<<i.oskarzony<<"\" sa to akta nr "<<num<<endl;
        else if(regex_match (i.poszkodowany,reg))
            cout<<"Znaleziono \""<<i.poszkodowany<<"\" sa to akta nr "<<num<<endl;
        else if(regex_match (i.swiadek,reg))
            cout<<"Znaleziono \""<<i.swiadek<<"\" sa to akta nr "<<num<<endl;
        else
            cout<<"Nie znaleziono.\n";
    }
    
    else
    for(auto &i: archiwum_krym)
    {
        num++;
        if(regex_search (i.numer_akt,reg))
            cout<<"Znaleziono \""<<i.numer_akt<<"\" sa to akta nr "<<num<<endl;
        else if(regex_search (i.oficer,reg))
            cout<<"Znaleziono \""<<i.oficer<<"\" sa to akta nr "<<num<<endl;
        else if(regex_search (i.oskarzony,reg))
            cout<<"Znaleziono \""<<i.oskarzony<<"\" sa to akta nr "<<num<<endl;
        else if(regex_search (i.poszkodowany,reg))
            cout<<"Znaleziono \""<<i.poszkodowany<<"\" sa to akta nr "<<num<<endl;
        else if(regex_search (i.swiadek,reg))
            cout<<"Znaleziono \""<<i.swiadek<<"\" sa to akta nr "<<num<<endl;
        else
            cout<<"Nie znaleziono.\n";
    }
    return;
}
