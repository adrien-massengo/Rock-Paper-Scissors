#include <iostream>
#include <Windows.h>
#include <time.h>
#include <string>
#include <algorithm>
#include "setTextColor.h"
#include "player.h"

void printTitle();
void printRules();
void game(player& human, player& computor, int& playerChoice);

int main()
{
	textColor tC_Setter;
	player human;
	player computor;
	bool playing;
	srand(time(NULL));
	std::string playAgain;
	std::string startgame;
	int playerChoice;
	printTitle();
	printf("\n");
	printRules();
	
	
	while (true)
	{
		printf("\nPlay\ny/n\n");
		getline(std::cin, startgame);
		transform(startgame.begin(), startgame.end(), startgame.begin(), ::tolower);
		if (startgame == "y")
		{
			playing = true;
			while (playing)
			{
				game(human, computor, playerChoice);
				printf("\nPlay Again?\ny/n\n");
				std::cin >> playAgain;
				transform(playAgain.begin(), playAgain.end(), playAgain.begin(), ::tolower);
				if (playAgain == "n")
				{
					playing = false;
				}
				else
				{

				}
			}
		}
		else if (startgame == "n")
		{
			break;
		}
		else
		{
			tC_Setter.set("red", "You have entered an invalid input. Try Again");
		}
	}
	return 0;
}

void printTitle()
{
	HANDLE hConsole;
	hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	std::cout << "-------------------------------------------------------------------" << std::endl;
	SetConsoleTextAttribute(hConsole, 3);
	std::cout << " ______              __      ______                         " << std::endl;
	std::cout << "|   __ \\.-----.----.|  |--. |   __ \\.---.-.-----.-----.----." << std::endl;
	std::cout << "|      <|  _  |  __||    <  |    __/|  _  |  _  |  -__|   _|" << std::endl;
	std::cout << "|___|__||_____|____||__|__| |___|   |___._|   __|_____|__|  " << std::endl;
	std::cout << "                                          |__|              " << std::endl;
	std::cout << " _______        __                               " << std::endl;
	std::cout << "|     __|.----.|__|.-----.-----.-----.----.-----." << std::endl;
	std::cout << "|__     ||  __||  ||__ --|__ --|  _  |   _|__ --|" << std::endl;
	std::cout << "|_______||____||__||_____|_____|_____|__| |_____|" << std::endl;
	SetConsoleTextAttribute(hConsole, 7);
	std::cout << "-------------------------------------------------------------------" << std::endl;
}
void printRules()
{
#include <Windows.h>
	HANDLE hConsole;
	hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	std::cout << "----------------------------------------" << std::endl;
	SetConsoleTextAttribute(hConsole, 2);
	std::cout << "__________      .__                 " << std::endl;
	std::cout << "\\______   \\__ __|  |   ____   ______" << std::endl;
	std::cout << " |       _/  |  \\  | _/ __ \\ /  ___/" << std::endl;
	std::cout << " |    |   \\  |  /  |_\\  ___/ \\___ \\ " << std::endl;
	std::cout << " |____|_  /____/|____/\\___  >____  >" << std::endl;
	std::cout << "        \\/                \\/     \\/ " << std::endl;
	SetConsoleTextAttribute(hConsole, 7);
	std::cout << "----------------------------------------" << std::endl;
	std::cout << "1. Pick one of either rock, paper or scissors\n2. So does the computer\n3. rock beats scissors, scissors beats paper, paper beats rock\n4. Whoever wins, wins";
}
void game(player& human, player& computor, int& playerChoice) 
{
	printf("[1]Rock\n[2]Paper\n[3]Scissors.\nChoose.\n");
	std::cin >> playerChoice;
	human.setInputChoice(playerChoice);
	computor.setActiveChoice(rand() % 3 + 1);
	printf("Rock....");
	Sleep(450);
	printf("Paper....");
	Sleep(450);
	printf("Scissors....");
	Sleep(700);
	printf("Go!\n");
	human.compareRes(human.getActiveChoice(), computor.getActiveChoice());
}