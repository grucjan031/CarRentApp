#include "Cars.h"

void Cars::UpdateMileage(){
    system("cls");
    string temp1;
    bool check = false;
    cout << "Podaj numer rejestracyjny auta(format XX_XXXX): ";
    cin >> temp1;
    for (int i = 0; i < Samochody.size(); i++) {
        if (Samochody[i].NrRej == temp1) {
            cout << endl << "Podaj aktualny przebieg: ";
            bool temp = false;
            do {
                cin >> Samochody[i].Przebieg;
                if (std::cin.fail()) {
                    std::cin.clear();
                    std::cin.ignore();
                    cout << "Blad! Podaj liczbe ";
                }
                else
                    temp = true;
            } while (!temp);
            check = true;
            SaveCars();
            break;
        }

    }
    if (check == false) {
        cout << endl <<"Nie znaleziono pojazdu";
        getchar();
    }
    

}

void Cars::UpdatePrice() {
    system("cls");
    string temp1;
    bool check = false;
    cout << "Podaj numer rejestracyjny auta(format XX_XXXX): ";
    cin >> temp1;
    for (int i = 0; i < Samochody.size(); i++) {
        if (Samochody[i].NrRej == temp1) {
            cout << endl << "Podaj aktualna cene: ";
            bool temp = false;
            do {
                cin >> Samochody[i].CenaZaDzien;
                if (std::cin.fail()) {
                    std::cin.clear();
                    std::cin.ignore();
                    cout << "Blad! Podaj liczbe ";
                }
                else
                    temp = true;
            } while (!temp);

            check = true;
            SaveCars();
            break;
        }

    }
    if (check == false) {
        cout << endl << "Nie znaleziono pojazdu";
        getchar();
    }


}

Cars::Cars() {
    CountLine();
    LoadCars();
}

Cars::~Cars() {
    SaveCars();
}

void Cars::LoadCars()
{

    fstream plik;
    plik.open("cars.txt", ios::in);
    for (int i = 0; i < (LineNumber) / 7; i++) {

        Samochody.push_back(Samochod());

        string temp_1, temp_2, temp_3, temp_4;

        getline(plik, Samochody[i].Marka);
        getline(plik, Samochody[i].Model);
        getline(plik, Samochody[i].NrRej);
        getline(plik, temp_1);
        getline(plik, temp_2);
        getline(plik, temp_3);
        getline(plik, temp_4);
        Samochody[i].Rocznik = stoi(temp_1);
        Samochody[i].Przebieg = stoi(temp_2);
        Samochody[i].CenaZaDzien = stof(temp_3);
        Samochody[i].Moc = stoi(temp_4);
    }

    plik.close();
}

void Cars::AddCar() {
    system("cls");
    Samochody.push_back(Samochod());
    int i;
    i = (LineNumber / 7);
    cout << "Podaj marke: " << endl;
    cin >> Samochody[i].Marka;
    cout << "Podaj model: " << endl;
    cin >> Samochody[i].Model;
    cout << "Podaj numer rejestracyjny(format XX_XXXXX): " << endl;
    cin >> Samochody[i].NrRej;
    cout << "Podaj rocznik: " << endl;
 
    bool temp1 = false;
    do {
        cin >> Samochody[i].Rocznik;
        if (cin.fail()) {
            cin.clear();
            cin.ignore();
            cout << "Blad! Podaj liczbe ";
        }
        else
            temp1 = true;
    } while (!temp1);
    cout << "Podaj przebieg: " << endl;
    bool temp2 = false;
    do {
        cin >> Samochody[i].Przebieg;
        if (cin.fail()) {
            cin.clear();
            cin.ignore();
            cout << "Blad! Podaj liczbe ";
        }
        else
            temp2 = true;
    } while (!temp2);

    cout << "Podaj cene za dzien: " << endl;
    bool temp3 = false;
    do {
        cin >> Samochody[i].CenaZaDzien;
        if (cin.fail()) {
            cin.clear();
            cin.ignore();
            cout << "Blad! Podaj liczbe ";
        }
        else
            temp3 = true;
    } while (!temp3);

    cout << "Podaj moc silnika w koniach mechanicznych: " << endl;

    bool temp4 = false;
    do {
        cin >> Samochody[i].Moc;
        if (cin.fail()) {
            cin.clear();
            cin.ignore();
            cout << "Blad! Podaj liczbe ";
        }
        else
            temp4 = true;
    } while (!temp4);
    
    ofstream strumien("cars.txt", ios::app);
    strumien << Samochody[i].Marka << endl;
    strumien << Samochody[i].Model << endl;
    strumien << Samochody[i].NrRej << endl;
    strumien << Samochody[i].Rocznik << endl;
    strumien << Samochody[i].Przebieg << endl;
    strumien << Samochody[i].CenaZaDzien << endl;
    strumien << Samochody[i].Moc << endl;

    strumien.close();

    CountLine();

}

void Cars::RemoveCar()
{
    string temp1;
    bool check = false;
    system("cls");
    cout << "Podaj numer rejestracyjny(format XX_XXXXX) pojazdu do usuniecia: ";
    cout << endl;
    cin >> temp1;

    for (int i = 0; i < (Samochody.size()); i++) {
        if (Samochody[i].NrRej == temp1) {
            Samochody.erase(Samochody.begin() + i);
            check = true;
 

            SaveCars();
            break;

        }
    }
    if (check == false) {
        cout << "Nie znaleziono tego pojazdu" << endl;
        Sleep(1500);
    }


}

void Cars::CountLine()
{
    string linie;
    int count = 0;
    fstream plik;
    plik.open("cars.txt", ios::in);
    while (getline(plik, linie))
        count++;

    plik.close();
    LineNumber = count;

}

void Cars::SaveCars() {
    ofstream strumien("cars.txt", ios::trunc);
    for (int i = 0; i < Samochody.size(); i++) {
        strumien << Samochody[i].Marka << endl;
        strumien << Samochody[i].Model << endl;
        strumien << Samochody[i].NrRej << endl;
        strumien << Samochody[i].Rocznik << endl;
        strumien << Samochody[i].Przebieg << endl;
        strumien << Samochody[i].CenaZaDzien << endl;
        strumien << Samochody[i].Moc << endl;
    }

    strumien.close();
}

void Cars::ViewCars()
{
    system("cls");

    int i = 0;

    while (!((i>Samochody.size()-1) || (i < 0))) {
        cout << "Marka: " << Samochody[i].Marka << endl;
        cout << "Model: " << Samochody[i].Model << endl;
        cout << "Numer rejestracyjny: " << Samochody[i].NrRej << endl;
        cout << "Rocznik: " << Samochody[i].Rocznik << endl;
        cout << "Przebieg: " << Samochody[i].Przebieg <<" km" << endl;
        cout << "Cena za dzien: " << Samochody[i].CenaZaDzien << endl;
        cout << "Moc: " << Samochody[i].Moc << " koni mechanicznych" << endl;
        cout << "<-[a]       [d]->              [q]wyjscie";
        bool check = false;
        for (;;) {
            if (GetAsyncKeyState(0x41) & 0x8000) {   //klawisz a
                if (i == 0) {
                    i = Samochody.size() - 1;
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
                break;
            }
        }
        if (check == true) {
            break;
        }
        if ((i > Samochody.size() - 1)) {
            i = 0;
        }
        if (i < 0) {
            i = Samochody.size() - 1;
        }
        Sleep(200);
        system("cls");
    }



}
