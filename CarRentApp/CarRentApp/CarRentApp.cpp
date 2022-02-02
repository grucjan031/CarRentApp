#include <iostream>
#include "Cars.h"
#include "Menu.h"
#include "Rent.h"

//by program działał prawidłowo trzeba go zkompilować i włączyć
//nie za pomoca lokalnego debugera windows

int main()
{
    bool check = false;
	Cars CarList;
    Rent Rent;
	Menu Menu;



	for (;;) {
        Menu.RenderMainScreen();
        for (;;) {
            if (GetAsyncKeyState(0x31) & 0x8000) {   //klawisz 1
                CarList.ViewCars();
                Sleep(500);
                break;
                
            }
            if (GetAsyncKeyState(0x32) & 0x8000) {   //klawisz 2
                Rent.AddRent(CarList, Menu);
                Sleep(500);
                break;
            }
            if (GetAsyncKeyState(0x33) & 0x8000) {   //klawisz 3
                Rent.ShowCurrentRents(Menu, CarList);
                Sleep(500);
                break;
            }

            if (GetAsyncKeyState(0x34) & 0x8000) {   //klawisz 4
                CarList.AddCar();
                Sleep(500);
                break;
            }
            if (GetAsyncKeyState(0x35) & 0x8000) {   //klawisz 5
                CarList.RemoveCar();
                Sleep(500);
                break;
            }
            if (GetAsyncKeyState(0x36) & 0x8000) {   //klawisz 6
                CarList.UpdateMileage();
                Sleep(500);
                break;
            }
            if (GetAsyncKeyState(0x37) & 0x8000) {   //klawisz 7 
                CarList.UpdatePrice();
                Sleep(500);
                break;
            }
            if (GetAsyncKeyState(0x38) & 0x8000) {   //klawisz 8 
                Menu.RenderOptions();
                Sleep(500);
                break;
            }
            if (GetAsyncKeyState(0x39) & 0x8000) {   //klawisz 9 
                Rent.CutRent();
                Sleep(500);
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
	}	

}

