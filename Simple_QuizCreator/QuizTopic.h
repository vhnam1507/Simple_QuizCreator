#pragma once
#include <vector>
#include "Quiz.h"
#include <string>
using namespace std;

class QuizTopic
{
private:
	vector<Quiz> listQuest;
public:
	void TopicGenerate();
	void addQuestion();
	void outputQTopic();
	bool SavingFile(string f);
	bool ReadingFile(string f);
	int deduplication();
	int execute();
};

