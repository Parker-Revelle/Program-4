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
int stock;
vector<int> stocks(0);
double cost = 0;
double change =0;
ifstream inFS;
vector<string> Options(0);
vector<string> Choice(0);
vector <double> Price(0);
char userInp;


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
		inFS >> stock;
		Options.push_back(opt);
		Choice.push_back(chc);
		Price.push_back(prc);
		stocks.push_back(stock);

	}
	inFS.close();// closes the file

	bool running = true;
		while (running) {
			
				Main_Menu(Options, Choice, stocks);// creates the vending machines menu

				choice = upper(choice, Choice, stocks);//makes sure each character is capitilized

				cost = snack_cost(choice, Choice, Price);// returns the cost of the item if the user enter the correct symbol

				change = change_user(choice, cost, Choice, Options);// returns how much change the user needs

				exact_change(change);
			
				cout << "Would you like to purchase another item? [Y] [N] >>>";
				cin >> userInp;
				while (toupper(userInp) != 'Y' && toupper(userInp) != 'N') {
					cout << "Invalid option. Would you like to purchase another item? [Y] [N] >>>";
					cin >> userInp;
				}
				if (toupper(userInp) == 'Y') {
					continue;
				}

				else if (toupper(userInp) == 'N') {
					cout << "Thank you for shopping!" << endl;
					running = false;
				}
				
		}
	system("pause");
	return 0;
}