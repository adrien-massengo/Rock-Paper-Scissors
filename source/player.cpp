#include "player.h"

player::player() {
	choiceCorrespondance.insert({ 1, "rock" });
	choiceCorrespondance.insert({ 2, "paper" });
	choiceCorrespondance.insert({ 3, "scissors" });
}


void player::setInputChoice(int input)
{
	inputChoice = input;
	setActiveChoice(inputChoice);
}
void player::setActiveChoice(int active)
{
	activeChoice = active;
}
int player::getActiveChoice()
{
	return activeChoice;
}
std::string player::getCoresspondingChoice(int activeChoice)
{
	auto choiceValue = choiceCorrespondance.find(activeChoice);
		return choiceValue->second;
}
void player::compareRes(int humanResult, int computorResult)
{
		auto humanValue = choiceCorrespondance.find(humanResult);
		auto compValue = choiceCorrespondance.find(computorResult);


		std::cout << "You: " << humanValue->second << "\nComputor: " << compValue->second << "\n";
		if (humanValue->second == compValue->second)
		{
			std::cout << "It's a draw!";
		}
		else if (humanValue->second == "rock" && compValue->second == "scissors" || humanValue->second == "paper" && compValue->second == "rock" || humanValue->second == "scissors" && compValue->second == "paper")
		{
			std::cout << "You win!";
		}
		else if (humanValue->second == "rock" && compValue->second == "paper" || humanValue->second == "paper" && compValue->second == "scissors" || humanValue->second == "scissors" && compValue->second == "rock")
		{
			std::cout << "The Computor wins";
		}
		else if (humanValue->second == "paper" && compValue->second == "rock")
		{
			std::cout << "You win";
		}
}