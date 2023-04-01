#include <vector>
#include "Quiz.h"
#include <string>
#include "QuizTopic.h"
#include "Menu.h"

Menu::Menu(string title)
{
	this->title = title;
}

void Menu::addSelection(string luachon)
{
	theList.push_back(luachon);
}

void Menu::Listoutput()
{
	cout << "\n---------" << title << "----------\n";
	for (int i = 0; i < theList.size(); i++) {
		cout << i << ". " << theList[i] << endl;
	}
}

int Menu::select()
{
	int c;
	do {
		Listoutput();
		cout << "\n Moi lua chon: ";
		cin >> c;
		string temp;
		getline(cin, temp);
		if (c >= theList.size() || c < 0)
			cout << "Chon SAI, Xin vui long chon lai! " << endl;
	} while (c < 0 || c >= theList.size());

	return c;
}
