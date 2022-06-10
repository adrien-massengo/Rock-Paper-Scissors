#include <iostream>
#include <windows.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <cstdlib>
#include <ctype.h>
#include <iostream>
#include<bits/stdc++.h>
#include <iostream>

using namespace std;
int gameExit()
{
	return 0;
}
void breakline(int line_num)
{
	for (int i = 0; i <= line_num; i++)
	{
		cout << "\n";
	}
}
void setTextColor(int color, string text)
{
	HANDLE hConsole;
	hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(hConsole, color);
	cout << text << endl;
	SetConsoleTextAttribute(hConsole, 7);
}
void printTitle()
{
	HANDLE hConsole;
	hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	cout << "-------------------------------------------------------------------" << endl;
	SetConsoleTextAttribute(hConsole, 3);
	cout << " ______              __      ______                         " << endl;
	cout << "|   __ \\.-----.----.|  |--. |   __ \\.---.-.-----.-----.----." << endl;
	cout << "|      <|  _  |  __||    <  |    __/|  _  |  _  |  -__|   _|" << endl;
	cout << "|___|__||_____|____||__|__| |___|   |___._|   __|_____|__|  " << endl;
	cout << "                                          |__|              " << endl;
	cout << " _______        __                               " << endl;
	cout << "|     __|.----.|__|.-----.-----.-----.----.-----." << endl;
	cout << "|__     ||  __||  ||__ --|__ --|  _  |   _|__ --|" << endl;
	cout << "|_______||____||__||_____|_____|_____|__| |_____|" << endl;
	SetConsoleTextAttribute(hConsole, 7);
	cout << "-------------------------------------------------------------------" << endl;
}
void printRules()
{
	HANDLE hConsole;
	hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	cout << "----------------------------------------" << endl;
	SetConsoleTextAttribute(hConsole, 2);
	cout << "__________      .__                 " << endl;
	cout << "\\______   \\__ __|  |   ____   ______" << endl;
	cout << " |       _/  |  \\  | _/ __ \\ /  ___/" << endl;
	cout << " |    |   \\  |  /  |_\\  ___/ \\___ \\ " << endl;
	cout << " |____|_  /____/|____/\\___  >____  >" << endl;
	cout << "        \\/                \\/     \\/ " << endl;
	SetConsoleTextAttribute(hConsole, 7);
	cout << "----------------------------------------" << endl;
}
void  game()
{
	Sleep(1000);
	string playerChoice;
	string computorChoice;
	int compSelect;
	cout << "Choose. Rock, Paper or Scissors.\n";
	getline(cin, playerChoice);
	transform(playerChoice.begin(), playerChoice.end(), playerChoice.begin(), ::tolower);
	cout << "Rock...\n";
	Sleep(500);
	cout << "Paper...\n";
	Sleep(500);
	cout << "Scissors...\n";
	Sleep(700);
	cout << "Go!\n";
	compSelect = rand() % 3 + 1;
	switch (compSelect)
	{
	case 1:
		computorChoice = "rock";
		break;
	case 2:
		computorChoice = "paper";
		break;
	case 3:
		computorChoice = "scissors";
	default:
		break;
	}
	cout << "You: " << playerChoice << "!" << endl;
	cout << "Computor: " << computorChoice << "!" << endl;
	if (computorChoice == playerChoice){
		cout << "It's a draw!\n";
	}
	else if (computorChoice ==  "rock" && playerChoice == "paper"){
		cout << "Your paper covers the computor's rock. You win!\n";
	}
	else if (computorChoice == "rock" && playerChoice == "scissors"){
		cout << "The computor's rock shatters your scissors. You lose!\n";
	}
	else if (computorChoice == "paper" && playerChoice == "rock"){
		cout << "The computor's paper covers your rock. You lose!\n";
	}
	else if (computorChoice == "paper" && playerChoice == "scissors"){
		cout << "Your scissors cuts the computor's  paper. You Win!\n";
	}
	else if (computorChoice == "scissors" && playerChoice == "rock"){
		cout << "Your rock shatters the computor's scissors. You win!\n";
	}
	else if (computorChoice == "scissors" && playerChoice == "paper"){
		cout << "Your scissors cuts the computor's paper. You win!\n";
	}
	else
	gameExit();

}

int main(){
	srand(time(NULL));
	string again;
	printTitle();
	breakline(1);
	printRules();
	breakline(1);
	string play;
	cout << "Play?\n";
	cout << "y/n\n";
	getline(cin, play);
	transform(play.begin(), play.end(), play.begin(), ::tolower);
	if (play == "y"){
		game();
	}
	else
	return 0;

}