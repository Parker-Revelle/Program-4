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
string choice = "hello";
double cost = 0;
double change =0;
ifstream inFS;
vector<string> Options(0);
vector<string> Choice(0);
vector <double> Price(0);


//Need to also keep a running tally and allow for multiple choices.

int main() {
	inFS.open("snacks.txt");//opens the snacks file 
	if (!inFS.is_open()) {//end program if file does open
		cout << " Could not open file snacks.txt" << endl;
		return 1;
	}

	while (!inFS.eof()) {//assigns values of snacks to their given vectors
		inFS >> opt;
		inFS >> chc;
		inFS >> prc;
		Options.push_back(opt);
		Choice.push_back(chc);
		Price.push_back(prc);

	}
	inFS.close();// closes the file


	Main_Menu( Options,Choice);// creates the vending machines menu

	choice = upper(choice, Choice);//makes sure each character is capitilized

	cost = snack_cost(choice, Choice, Price);// returns the cost of the item if the user enter the correct symbol

	change =  change_user(choice, cost, Choice, Options);// returns how much change the user needs
	
	exact_change(change);
	system("pause");
	return 0;
}