#include "Rent.h"


Rent::Rent(){
    LoadRents();
    CorrectRents();
}

void Rent::ViewCarsForRent(Cars Obj1, Menu Obj2){
    system("cls");
    HANDLE hOut;

    hOut = GetStdHandle(STD_OUTPUT_HANDLE);
    int i = 0;

    while (!((i > Obj1.Samochody.size() - 1) || (i < 0))) {
        bool temp123 = false;
        cout << "Marka: " << Obj1.Samochody[i].Marka << endl;
        cout << "Model: " << Obj1.Samochody[i].Model << endl;
        cout << "Numer rejestracyjny: " << Obj1.Samochody[i].NrRej << endl;
        cout << "Rocznik: " << Obj1.Samochody[i].Rocznik << endl;
        cout << "Przebieg: " << Obj1.Samochody[i].Przebieg <<" km" << endl;
        cout << "Cena za dzien: " << Obj1.Samochody[i].CenaZaDzien << endl;
        cout << "Moc: " << Obj1.Samochody[i].Moc << " koni mechanicznych" << endl;
        for (int j = 0; j < NrRejWyp.size(); j++) {
            if (NrRejWyp[j] == Obj1.Samochody[i].NrRej) {
                SetConsoleTextAttribute(hOut, 4);
                cout << "Status: Aktualnie wypozyczony" << endl;
                SetConsoleTextAttribute(hOut, Obj2.TextColor);
                temp123 = true;

            }
   
        }
        if (temp123 == false) {
            SetConsoleTextAttribute(hOut, 2);
            cout << "Status: Dostepny" << endl;
            SetConsoleTextAttribute(hOut, Obj2.TextColor);
        }

        cout << "<-[a]       [d]->   [enter]wynajmij    [q]wyjscie";
        bool check = false;
        for (;;) {
            if (GetAsyncKeyState(0x41) & 0x8000) {   //klawisz a
                if (i == 0) {
                    i = Obj1.Samochody.size() - 1;
                }
                else {
                    i--;

                }
                break;
            }
            if (GetAsyncKeyState(0x44) & 0x8000) {   //klawisz d
                i++;
                break;
            }
            if (GetAsyncKeyState(0x51) & 0x8000) {   //klawisz q
                check = true;
                Option = -1;
                break;
            }
            if (GetAsyncKeyState(0x0D) & 0x8000) {   //klawisz enter
                Option = i;
                check = true;
                break;
                Sleep(500);
            }
        }
        if (check == true) {
            break;
        }
        if ((i > Obj1.Samochody.size() - 1)) {
            i = 0;
        }
        if (i < 0) {
            i = Obj1.Samochody.size() - 1;
        }
        Sleep(200);
        system("cls");
    }

}

void Rent::AddRent(Cars Obj1, Menu Obj2) {
    ViewCarsForRent(Obj1, Obj2);
    if (Option >-1 && Option < Obj1.Samochody.size()) {
        
        RentingProcess(Obj1);
    
    }
}

void Rent::RentingProcess(Cars Obj1){
    Sleep(500);

    Klienci.push_back(Klient());

    string temp;//bug
    cin >> temp;//tutaj przechowamy wszystkie znaki ktore wcisnal uzytkownik
    //i wskakuja one automatycznie do cina
    system("cls");
    cout << "Podaj imie: ";
    cin.clear();
    Sleep(500);
    cin >> Klienci[Klienci.size()-1].Imie;
    cout << endl<< "Podaj nazwisko: ";
    cin >> Klienci[Klienci.size() - 1].Nazwisko;
    cout << endl<< "Podaj pesel: ";
    cin >> Klienci[Klienci.size() - 1].Pesel;
    cout << endl << "Podaj numer telefonu: ";
    cin >> Klienci[Klienci.size() - 1].NrTel;
    cout << endl<<"Na ile dni: ";
    bool temp1 = false;
    do {
        cin >> Klienci[Klienci.size() - 1].LiczbaDni;

        if (cin.fail()) {
            cin.clear();
            cin.ignore();
        }
        else
            temp1 = true;
    } while (!temp1);
    cout << endl << "Kiedy start wypozyczenia(0 jesli dzisiaj, 1 jesli jutro itd.) : ";
    bool temp2 = false;
    do {
        cin >> Klienci[Klienci.size() - 1].DzienStartu;

        if (cin.fail()) {
            cin.clear();
            cin.ignore();
        }
        else
            temp2 = true;
    } while (!temp2);
    Klienci[Klienci.size() - 1].Kwota = Klienci[Klienci.size() - 1].LiczbaDni * Obj1.Samochody[Option].CenaZaDzien;
    cout << endl<<"Kwota: " << Klienci[Klienci.size() - 1].Kwota;

    Klienci[Klienci.size() - 1].Nr_rejA = Obj1.Samochody[Option].NrRej;

    CalculateTime();

    NrRejWyp.push_back(string());
    NrRejWyp[NrRejWyp.size() - 1] = Obj1.Samochody[Option].NrRej;
    SaveRents();
    getchar();
    getchar();

}

void Rent::SaveRents(){
    ofstream strumien1("rents.txt", ios::trunc);
    for (int i = 0; i < NrRejWyp.size(); i++) {
        strumien1 << NrRejWyp[i] << endl;

    }
    strumien1.close();
    ofstream strumien2("clients.txt", ios::trunc);
    for (int i = 0; i < Klienci.size(); i++) {
        strumien2 << Klienci[i].Imie << endl;
        strumien2 << Klienci[i].Nazwisko << endl;
        strumien2 << Klienci[i].Pesel << endl;
        strumien2 << Klienci[i].NrTel << endl;
        strumien2 << Klienci[i].Nr_rejA << endl;
        strumien2 << Klienci[i].LiczbaDni << endl;
        strumien2 << Klienci[i].Kwota << endl;
        strumien2 << Klienci[i].DzienKonca << endl;

    }
    strumien2.close();

}

void Rent::LoadRents(){

    fstream plik;
    plik.open("rents.txt", ios::in);
    for (int i = 0; i < (CountNumberRents()); i++) {

        NrRejWyp.push_back(string());
      
        getline(plik, NrRejWyp[i]);

    }
    
    plik.close();
    fstream plik2;
    plik2.open("clients.txt", ios::in);
    for (int i = 0; i < (CountNumberClients()/8); i++) {

        Klienci.push_back(Klient());

        string temp_1, temp_2, temp_3;

        getline(plik2, Klienci[i].Imie);
        getline(plik2, Klienci[i].Nazwisko);
        getline(plik2, Klienci[i].Pesel);
        getline(plik2, Klienci[i].NrTel);
        getline(plik2, Klienci[i].Nr_rejA);
        getline(plik2, temp_1);
        getline(plik2, temp_2);
        getline(plik2, temp_3);

        Klienci[i].LiczbaDni = stoi(temp_1);
        Klienci[i].Kwota = stoi(temp_2);
        Klienci[i].DzienKonca = stoi(temp_3);
    }

    plik2.close();

}


//
void Rent::ShowCurrentRents(Menu Obj1, Cars Obj2){
    system("cls");
    HANDLE hOut;

    hOut = GetStdHandle(STD_OUTPUT_HANDLE);
    for (int i = 0; i < NrRejWyp.size();i++) {
        cout << NrRejWyp[i];
        for (int j = 0; j < Klienci.size(); j++) {
            if (Klienci[j].Nr_rejA == NrRejWyp[i]) {
                cout << " " << Klienci[j].Imie << " " << Klienci[j].Nazwisko << endl;
                cout << "Pesel: " << Klienci[j].Pesel << " Numer tel: " << Klienci[j].NrTel << endl;
                for (int z = 0; z < Obj2.Samochody.size(); z++) {
                    if (Obj2.Samochody[z].NrRej == NrRejWyp[i]) {
                        cout << Obj2.Samochody[z].Marka << " " << Obj2.Samochody[z].Model;
                    
                    }

                }
                SetConsoleTextAttribute(hOut, 4);
                cout << endl << "Zostalo " << Klienci[j].DzienKonca - DaysSinceEpoch()<< " dni";
                SetConsoleTextAttribute(hOut, Obj1.TextColor);

                break;
            }

        }
        cout << endl;
    }
    cout << "[q]wyjscie" << endl;
    for (;;) {
        if (GetAsyncKeyState(0x51) & 0x8000) {   //klawisz q   
            break;
            Sleep(500);
        }

    }
}

int Rent::CountNumberRents(){
    string linie;
    int count = 0;
    fstream plik;
    plik.open("rents.txt", ios::in);
    while (getline(plik, linie))
        count++;

    plik.close();

    return count;
}

int Rent::CountNumberClients(){
    string linie;
    int count = 0;
    fstream plik;
    plik.open("clients.txt", ios::in);
    while (getline(plik, linie))
        count++;

    plik.close();

    return count;
}

void Rent::CalculateTime(){
    Klienci[Klienci.size() - 1].DzienKonca = DaysSinceEpoch() + Klienci[Klienci.size() - 1].DzienStartu + Klienci[Klienci.size() - 1].LiczbaDni;

}



int Rent::DaysSinceEpoch(){
    time_t seconds;
    seconds = time(NULL);
    return seconds / (86400); // 60 * 60 * 24
}

void Rent::CorrectRents(){
    for (int i = 0; i < (Klienci.size()); i++) {
        if (Klienci[i].DzienKonca <= DaysSinceEpoch()) {
            ArchiveRent(i);
            Klienci.erase(Klienci.begin() + i);
            NrRejWyp.erase(NrRejWyp.begin() + i);

            SaveRents();
        }
    }
}

void Rent::CutRent() {
    system("cls");
    string temp;
    int temp1;
    bool check = false;
    cout << "Podaj numer rejestracyjny(format XX_XXXXX) auta z konkretnego wypozyczenia ktore chcesz skrocic: ";
    cin >> temp;
    for (int i = 0; i < Klienci.size(); i++) {
        if (temp == Klienci[i].Nr_rejA) {
            cout << endl << "Podaj o ile dni chcesz skrocic wypozyczenie: ";

            bool temp2 = false;
            do {
                cin >> temp1;

                if (cin.fail()) {
                    cin.clear();
                    cin.ignore();
                }
                else
                    temp2 = true;
            } while (!temp2);
            Klienci[i].DzienKonca = Klienci[i].DzienKonca - temp1;
            check = true;
            break;
        }
    }
    if (check == false) {
        cout << endl << "Nie znaleziono auta";
        Sleep(2000);
    }
    SaveRents();
    CorrectRents();





}

void Rent::ArchiveRent(int i){
    ofstream strumien("renthistory.txt", ios::app);
 
    strumien << Klienci[i].Imie << ";";
    strumien << Klienci[i].Nazwisko << ";";
    strumien << "Pesel:" << Klienci[i].Pesel << ";";
    strumien << "Tel:" << Klienci[i].NrTel << ";";
    strumien << Klienci[i].Nr_rejA << ";";
    strumien << "Dni:" <<Klienci[i].LiczbaDni << ";";
    strumien <<"Kwota:"<< Klienci[i].Kwota << ";";
    strumien << "DzienStartUnix:"<<Klienci[i].DzienKonca - Klienci[i].DzienKonca << ";";
    strumien << "DzienKoncaUnix:" << Klienci[i].DzienKonca << endl;

    
    strumien.close();
}
