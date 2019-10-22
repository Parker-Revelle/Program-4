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



//Takes in the vectors of the name, price, and stock available to create the menu
void menu(vector<string> vect, vector<string> vec2,int i, vector<int> stocks) {
	cout << left << "|" << vec2.at(i) << " for " << vect.at(i) << setw(7) << " (Stock: " << stocks.at(i) <<") | ";//base set up for menu

}

//Creates the menu, and displays it in rows
void Main_Menu(vector<string> vect, vector<string> vec2, vector<int> stocks) {
	int num = 0;
	cout << "Welcome to the S&R luxury vendng machines " << endl << "Your options are the following" << endl;
	
	for (int i = 0; i < vect.size(); ++i) {//creates the menu in full format
		menu(vect, vec2, i, stocks);
		num += 1;
		if ((num % 3) == 0) {
			cout << endl;
		}

	}
	cout << endl;
}

//Checks that the user is actually inputting a valid option, as well as making the user choice uppercase for future use
string upper(string choice, vector<string> vect, vector<int> &stocks) {// upper casees the user string
	cin >> choice;
	bool running = true;
	for (int i = 0; i < choice.size(); ++i) {
		choice[i] = toupper(choice[i]);
	}
	//Checks that the item is in stock
	while (running) {
		for (int i = 0; i < vect.size(); i++) {
			if (choice == vect.at(i)) {
				if (stocks.at(i) > 0) {
					stocks.at(i) = stocks.at(i) - 1;
					return choice;
					break;
				}
				else {
					cout << "This item is out of stock." << endl;
				}
			}

			

		}
		//The for loop didn't break, and so the option wasn't found. Asks again for the user to make a choice
		cout << "Please select a valid option >>> ";
		cin.clear();
		cin.ignore(100, '\n');
		cin >> choice;
		for (int i = 0; i < choice.size(); ++i) {
			choice[i] = toupper(choice[i]);
		}
	}

	//Returns the validated choice of the user
	return choice;
}

//Finds snack cost from vectors
double snack_cost(string choice, vector<string> vect,vector<double> vect2) {//  finds the cost of the snack
	double cost = 0;
	for (int i = 0; i < vect.size(); ++i) {
		if (choice == vect.at(i)) {
			cost = vect2.at(i);
		}

		
	}

	

	return cost;
}

//This function gets the choice of the user, outputs the price, then asks for money in from user 
double change_user(string choice, double cost,vector<string> vect, vector<string> vect2) {// uses the previosly gathered value to find the change needed 
	double change;
	double pay =0;
	for (int i = 0; i < vect.size(); ++i) {
		if (choice == vect.at(i)) {
			choice = vect2.at(i);
		}
	}

	
	
	//Checks that the user inputs at least the amount to pay for option, but less than 20
	cout << "In order to purchase " << choice << " you will need at least $" << cost << " how much will you be paying with?[we don't accept currency over $20]" << endl;
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