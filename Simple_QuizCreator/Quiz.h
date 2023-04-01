#pragma once
#include <iostream>
#include <fstream>
#include <string>
using namespace std;

class Quiz
{
private:
	string quest;
	string ans1; string ans2;
	string solve;
public:
	Quiz(string q, string a, string b, string s);
	Quiz();
	~Quiz();

	void inputQuiz();
	void ReadingFile(ifstream& f);
	void WritingFile(ofstream& f);
	void test(string vote);
	void outputQuiz();
	friend bool duplicateCheck(const Quiz& c1, const Quiz& c2);
};

