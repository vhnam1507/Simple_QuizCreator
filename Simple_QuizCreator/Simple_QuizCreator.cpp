#include <iostream>
#include <fstream>
#include <string>
#include "Quiz.h"
#include "QuizTopic.h"
#include "Menu.h"
using namespace std;

int main()
{
	cout << "-------20H1120232 _ Vu Hoang Nam _ Chapter 3 _ Bai tap 1 _ Quan ly de thi trac nghiem--------\n" << endl;

	string f;
	QuizTopic de;
	Menu m("Main Menu");

	m.addSelection("Quit");
	m.addSelection("Create a new QuizTopic");
	m.addSelection("Add more Quiz");
	m.addSelection("Output the current QuizTopic");
	m.addSelection("Import a QuizTopic from a FILE");
	m.addSelection("Export the current QuizTopic into a FILE");
	m.addSelection("Deduplicate Quiz");
	m.addSelection("Start the Quiz");

	while (true) {
		switch (m.select()) {
		case 0:
			return 0;
		case 1:
			de.TopicGenerate();
			break;
		case 2:
			de.addQuestion();
			break;
		case 3:
			de.outputQTopic();
			break;
		case 4:
			cout << "Enter the name of the file you want to import: ";
			getline(cin, f);
			if (de.ReadingFile(f)) cout << "SUCCESSFUL!\n";
			else "EROR!! Please check it again! MAKE SURE YOU ENTERED THE RIGHT NAME AND THE FILE EXISTS";
			break;
		case 5:
			cout << "Enter the name of the file you want to export: ";
			getline(cin, f);
			if (de.SavingFile(f)) cout << "SUCCESSFUL! \n";
			else "EROR!! Please check it again! ";
			break;
		case 6:
			cout << "QuizCreator deleted: " << de.deduplication() << " duplicate Quiz! \n";

		case 7:
			de.execute();
		default:
			break;
		}
	}


}

