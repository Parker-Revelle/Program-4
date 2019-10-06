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
	cout << "|" << vec2.at(i) << " for " << vect.at(i) << "| " ;//base set up for menu

}

void Main_Menu(vector<string> vect, vector<string> vec2) {
	int num = 0;
	cout << "Welcome to the S&R luxury vendng machines " << endl << "Your options are the following" << endl;
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

void exact_change(double change) {// functions that takes change value and gives the proper amount of change
	cout <<endl<< " Your change is " << change << " you will be given " << endl;
	if (change != 0) {
		int Tens = change / 10;
		change -= (Tens * 10);
		int fives = change / 5;
		change -= (fives * 5);
		int DA = change / 1;
		change -= (DA * 1);
		int Q = change / .25;
		change -= (Q * .25);
		int D = change / .1;
		change -= (D * .1);
		int N = change / .05;
		change -= (N * .05);
		int P = change / .01;

		if (Tens > 1) {
			cout << Tens << " Ten dollar bill" << endl;
		}
		else if (Tens == 1) {
			cout << "1 Ten dollar bill" << endl;
		}

		if (fives > 1) {
			cout << fives << " five dollar bill" << endl;
		}
		else if (fives == 1) {
			cout << "1 five dollar bill" << endl;
		}

		if (DA > 1) {
			cout << DA << " dollars" << endl;
		}
		else if (DA == 1) {
			cout << "1 dollar" << endl;
		}

		if (Q > 1) {
			cout << Q << " quarters" << endl;
		}
		else if (Q == 1) {
			cout << "1 quarter" << endl;
		}

		if (D > 1) {
			cout << D << " dimes" << endl;
		}
		else if (D == 1) {
			cout << "1 dime" << endl;
		}

		if (N > 0) {
			cout << N << " nickel" << endl;
		}

		if (P > 1) {
			cout << P << " pennies" << endl;
		}
		else if (P == 1) {
			cout << "1 penny" << endl;
		}
	}
	else {
		cout << "no change" << endl;
	}
}