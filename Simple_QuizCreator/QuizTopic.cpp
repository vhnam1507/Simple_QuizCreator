#include <vector>
#include "Quiz.h"
#include <string>
#include "QuizTopic.h"
#include <iostream>
using namespace std;

void QuizTopic::TopicGenerate()
{
	listQuest.clear();
	cout << "The previous QuizTopic has been deleted! " << endl;
}

void QuizTopic::addQuestion()
{
	Quiz* n = new Quiz();
	n->inputQuiz();
	listQuest.push_back(*n);
	cout << "\nSuccessfully added QuizTopic!\nThe current QuizTopic has " << listQuest.size() << " questions! " << endl;

}

void QuizTopic::outputQTopic()
{
	cout << "----- This QuizTopic has " << listQuest.size() << " questions------\n\n";
	for (int i = 0; i < listQuest.size(); i++) {
		cout << "Quiz " << i + 1 << ". ";
		listQuest[i].outputQuiz();
		cout << endl;
	}
}

bool QuizTopic::SavingFile(string f)
{
	ofstream fo(f);

	if (!fo.is_open())
		return false;

	fo << listQuest.size() << endl;
	for (int i = 0; i < listQuest.size(); i++) {
		listQuest[i].WritingFile(fo);
	}

	fo.close();
	return true;
}

bool QuizTopic::ReadingFile(string f)
{
	ifstream fi(f);

	if (!fi.is_open())
		return false;

	int dem; fi >> dem;
	string temp;
	getline(fi, temp);

	for (int i = 0; i < dem; i++) {
		Quiz* ptr = new Quiz;
		ptr->ReadingFile(fi);
		listQuest.push_back(*ptr);
	}

	fi.close();
	return true;

}

int QuizTopic::deduplication()
{
	int i = 0; int j;
	int k = listQuest.size();

	while (i < listQuest.size()) {
		Quiz c1 = listQuest[i];
		j = i + 1;
		while (j < listQuest.size()) {
			Quiz c2 = listQuest[j];
			if (duplicateCheck(c1, c2))
				listQuest.erase(listQuest.begin() + j);
			else
				j++;
		}
		i++;
	}
	k = k - listQuest.size();
	return k;
}

int QuizTopic::execute()
{
	cout << "-----LET'S START------\n\n";
	string vote;
	for (int i = 0; i < listQuest.size(); i++) {
		cout << "Quiz " << i + 1 << ". ";
		listQuest[i].outputQuiz();
		cout << "Your choice is: <A/B> ";
		cin >> vote;
		listQuest[i].test(vote);

	}

	return 0;
}
