#include "Quiz.h"
#include <fstream>
#include <iostream>
#include <string>
using namespace std;

Quiz::Quiz(string q, string a, string b, string s)
{
	quest = q;
	ans1 = a; ans2 = b;
	solve = s;
}

Quiz::Quiz()
{
}

Quiz::~Quiz()
{
}

void Quiz::inputQuiz()
{
	cout << "Enter your Question: "; getline(cin, quest);
	cout << "Enter ans A: "; getline(cin, ans1);
	cout << "Enter ans B: "; getline(cin, ans2);
	cout << "which is the correct answer? <A/B> "; getline(cin, solve);

}

void Quiz::ReadingFile(ifstream& fin)
{
	getline(fin, quest);
	getline(fin, ans1);
	getline(fin, ans2);
	getline(fin, solve);
}

void Quiz::WritingFile(ofstream& fout)
{
	fout << quest << endl;
	fout << ans1 << endl;
	fout << ans2 << endl;
	fout << solve << endl;
}

void Quiz::test(string vote)
{
	if (vote.compare(solve) == 0)
		cout << "----> You answered CORRECTLY! \n" << endl;
	else
		cout << "----> You answered WRONG! \n" << endl;
}

void Quiz::outputQuiz()
{
	cout << quest << endl;
	cout << "Ans A: " << ans1 << endl;
	cout << "Ans B: " << ans2 << endl;
}

bool duplicateCheck(const Quiz& c1, const Quiz& c2)
{
	if (c1.quest.compare(c2.quest) == 0
		&& c1.ans1.compare(c2.ans1) == 0
		&& c1.ans2.compare(c2.ans2) == 0)
		return true;
	return false;
}
