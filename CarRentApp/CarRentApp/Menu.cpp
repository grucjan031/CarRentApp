#include "Menu.h"



void Menu::RenderBigLogo()
{ 
	HANDLE hOut;

	hOut = GetStdHandle(STD_OUTPUT_HANDLE);

	SetConsoleTextAttribute(hOut, FOREGROUND_BLUE);
	cout << "  ,ad8888ba,                        88888888ba                                " << endl;
	cout << " d8\"'    `\"8b                       88      \"8b                        ,d     " << endl;
	cout << "d8'                                 88      ,8P                        88     " << endl;
	cout << "88            ,adPPYYba, 8b,dPPYba, 88aaaaaa8P' ,adPPYba, 8b,dPPYba, MM88MMM  " << endl;
	cout << "88            \"\"     `Y8 88P'   \"Y8 88\"\"\"\"88'  a8P_____88 88P'   `\"8a  88" << endl;
	cout << "Y8,           ,adPPPPP88 88         88    `8b  8PP\"\"\"\"\"\"\" 88       88  88" << endl;
	cout << " Y8a.    .a8P 88,    ,88 88         88     `8b \"8b, ,  aa 88       88  88," << endl;
	cout << "  `\"Y8888Y\"'  `\"8bbdP\"Y8 88         88      `8b `\"Ybbd8\"' 88       88  \"Y888" << endl;
	cout << endl;
	cout << endl;
	cout << endl;

	SetConsoleTextAttribute(hOut, FOREGROUND_RED);
	cout << "       db                                 " << endl;
	cout << "      d88b                                " << endl;
	cout << "     d8'`8b                               " << endl;
	cout << "    d8'  `8b     8b,dPPYba,  8b,dPPYba,   " << endl;
	cout << "   d8YaaaaY8b    88P'    \"8a 88P'    \"8a  " << endl;
	cout << "  d8\"\"\"\"\"\"\"\"8b   88       d8 88       d8  " << endl;
	cout << " d8'        `8b  88b,   ,a8\" 88b, , a8\"  " << endl;
	cout << "d8'          `8b 88`YbbdP\"'  88`YbbdP\"'" << endl;
	cout << "                 88          88           " << endl;
	cout << "                 88          88           " << endl;
	cout << endl;
	SetConsoleTextAttribute(hOut, FOREGROUND_GREEN);
	cout << "Nacisnij enter by zaczac ";
	getchar();
	system("cls");



}
void Menu::RenderSmallLogo() {
	HANDLE hOut;

	hOut = GetStdHandle(STD_OUTPUT_HANDLE);

	SetConsoleTextAttribute(hOut, FOREGROUND_INTENSITY | FOREGROUND_RED | FOREGROUND_BLUE);
	cout << "     #####                ######                         #                  " << endl;
	cout << "    #     #   ##   #####  #     # ###### #    # #####   # #   #####  #####  " << endl;
	SetConsoleTextAttribute(hOut, FOREGROUND_RED);
	cout << "    #        #  #  #    # #     # #      ##   #   #    #   #  #    # #    # " << endl;
	cout << "    #       #    # #    # ######  #####  # #  #   #   #     # #    # #    # " << endl;
	cout << "    #       ###### #####  #   #   #      #  # #   #   ####### #####  #####  " << endl;
	SetConsoleTextAttribute(hOut, FOREGROUND_BLUE);
	cout << "    #     # #    # #   #  #    #  #      #   ##   #   #     # #      #      " << endl;
	cout << "     #####  #    # #    # #     # ###### #    #   #   #     # #      #      " << endl;
	SetConsoleTextAttribute(hOut, TextColor);

}
void Menu::RenderMainScreen()
{
	system("cls");
	RenderSmallLogo();
	cout << "[1]Przeglad floty		" << " [4]Dodaj pojazd" << "	[7]Aktualizuj cene"<< endl;
	cout << "[2]Wynajmij pojazd		" << " [5]Usun pojazd"  << "		[8]Opcje" << endl;
	cout << "[3]Wynajete aktualnie	" << "	 [6]Aktualizuj przebieg"<< " [9]Skroc wypozycznie" << endl;
	cout << "[q]Wyjscie" << "		Historia wynajmow w pliku renthistory.txt" << endl;

	cout << "Nacisnij odpowiedni przycisk by przejsc dalej" << endl;
}

void Menu::RenderOptions(){
	system("cls");
	HANDLE hOut;

	hOut = GetStdHandle(STD_OUTPUT_HANDLE);
	cout << "[1]Wybierz kolor tekstu	[q]wyjscie" << endl;

	for (;;) {

		if (GetAsyncKeyState(0x31) & 0x8000) {//klawisz 1
			cout << "1.Niebieski 2.Zielony 4.Czerwony 15.Bialy" << endl;
			cout << "Podaj numer wybranego koloru: ";
			bool temp1 = false;
			do {
				cin >> TextColor;

				if (cin.fail()) {
					cin.clear();
					cin.ignore();
				}
				else
					temp1 = true;
			} while (!temp1);

			SetConsoleTextAttribute(hOut, TextColor);
			break;
		}
		if (GetAsyncKeyState(0x51) & 0x8000) {   //klawisz q
			break;
		}
	}

}

Menu::Menu(){
	TextColor = 2;
	SetConsoleTitle(TEXT("CarRentApp"));
	RenderBigLogo();

}
