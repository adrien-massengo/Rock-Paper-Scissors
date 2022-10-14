#pragma once
#include <iostream>
#include <map>


class player
{
private:
	std::map<int, std::string> choiceCorrespondance;
	int inputChoice;
	int activeChoice;
public:
	player();
	void setInputChoice(int input);
	void setActiveChoice(int active);
	int getActiveChoice();
	std::string getCoresspondingChoice(int activeChoice);
	void compareRes(int humanResult, int computorResult);
};