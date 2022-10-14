#pragma once
#include <iostream>
#include <map>

class textColor
{
private:
	std::map<std::string, int> ccm;
public:
	textColor();
	void set(std::string color, std::string text);
};
