#include<iostream>
#include<iomanip>
#include<string>
#include<fstream>
#include<vector>
#include<cstring>
#include<algorithm>
#include<sstream>
#include<cctype>
using namespace std;

string opt;
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
	


	system("pause");
	return 0;
}