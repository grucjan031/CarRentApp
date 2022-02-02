#pragma once
#include <iostream>
#include <windows.h>
#include <iostream>
#include <cstdlib>
#include "Cars.h"


using namespace std;

class Menu {
public:
	int TextColor;
	void RenderBigLogo();
	void RenderSmallLogo();
	void RenderMainScreen();
	void RenderOptions();
	Menu();


};