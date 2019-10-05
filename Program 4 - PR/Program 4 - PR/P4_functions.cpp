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




void menu(vector<string> vect, vector<string> vec2,int i) {
	cout << vec2.at(i) << " for " << vect.at(i) << " " ;//base set up for menu

}

void Main_Menu(vector<string> vect, vector<string> vec2) {
	int num = 0;
	cout << "Welcome to the S&R luxary vendng machines " << endl << "Your options are the following" << endl;
	for (int i = 0; i < vect.size(); ++i) {//creates the menu in full format
		menu(vect, vec2, i);
		num += 1;
		if ((num % 3) == 0) {
			cout << endl;
		}

	}
	cout << endl;
}

string upper(string choice) {// upper casees the user string
	cin >> choice;
	for (int i = 0; i < choice.size(); ++i) {
		choice[i] = toupper(choice[i]);
	}
	return choice;
}

double snack_cost(string choice, vector<string> vect,vector<double> vect2) {//  finds the cost of the snack
	double cost = 0;
	for (int i = 0; i < vect.size(); ++i) {
		if (choice == vect.at(i)) {
			cost = vect2.at(i);
		}
	}
	return cost;
}

double change_user(string choice, double cost,vector<string> vect, vector<string> vect2) {// uses the previosly gathered value to find the change needed 
	double change;
	double pay =0;
	for (int i = 0; i < vect.size(); ++i) {
		if (choice == vect.at(i)) {
			choice = vect2.at(i);
		}
	}
	cout << "In order to purchase " << choice << " you will need atleast $" << cost << " how much will you be paying with?[we don't accept currency over $20]" << endl;
	while ((!(cin >> pay))|| (pay > 20)){
		cout << "Make sure you enter a valid amount of money " << endl;
		cin.clear();
		cin.ignore(100, '\n');
	}
	change = pay - cost;
	return change;
}