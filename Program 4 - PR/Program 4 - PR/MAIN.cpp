#include<iostream>
#include<iomanip>
#include<string>
#include<fstream>
#include<vector>
#include<cstring>
#include<algorithm>
#include<sstream>
#include<cctype>
#include "P4_Header.h"
using namespace std;

string opt;
int num = 0;
string chc;
double prc = 0;
ifstream inFS;
vector<string> Options(0);
vector<string> Choice(0);
vector <int> Price(0);


int main() {
	inFS.open("snacks.txt");
	if (!inFS.is_open()) {
		cout << " Could not open file snacks.txt" << endl;
		return 1;
	}

	while (!inFS.eof()) {
		inFS >> opt;
		inFS >> chc;
		inFS >> prc;
		Options.push_back(opt);
		Choice.push_back(chc);
		Price.push_back(prc);

	}
	inFS.close();
	cout << "Welcome to the S&R luxary vendng machines " << endl << "Your options are the following" << endl;
	for (int i = 0; i < Options.size(); ++i) {
		menu(Options, Choice, i);
		num += 1;
		if ((num % 3) == 0) {
			cout << endl;
		}

	}

	cout << endl;
	system("pause");
	return 0;
}