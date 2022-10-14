#include "setTextColor.h"
#include <Windows.h>

textColor::textColor()
{
	ccm.insert({ "blue",1 });
	ccm.insert({ "green",2 });
	ccm.insert({ "aqua",3 });
	ccm.insert({ "red",4 });
	ccm.insert({ "purple",5 });
	ccm.insert({ "yellow",6 });
	ccm.insert({ "white",7 });
	ccm.insert({ "grey", 8 });
	ccm.insert({ "light blue", 9 });
}
void textColor::set(std::string color, std::string text)
{
	auto colorValue = ccm.find(color);
	HANDLE hConsole;
	hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(hConsole, colorValue -> second);
	std::cout << text << std::endl;
	SetConsoleTextAttribute(hConsole, 7);
}