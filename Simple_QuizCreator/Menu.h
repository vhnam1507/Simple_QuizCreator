#pragma once
#include <vector>
#include "Quiz.h"
#include <string>
#include "QuizTopic.h"

class Menu
{
private:
	vector<string> theList;
	string title;
public:
	Menu(string title);
	void addSelection(string selection);
	void Listoutput();
	int select();
};

