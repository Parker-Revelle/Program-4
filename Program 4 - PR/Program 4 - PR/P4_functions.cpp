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
	cout << vec2.at(i) << " for " << vect.at(i) << " " ;

}

void Main_Menu(vector<string> vect, vector<string> vec2) {
	int num = 0;
	cout << "Welcome to the S&R luxary vendng machines " << endl << "Your options are the following" << endl;
	for (int i = 0; i < vect.size(); ++i) {//creates the menu
		menu(vect, vec2, i);
		num += 1;
		if ((num % 3) == 0) {
			cout << endl;
		}

	}
	cout << endl;
}

string upper(string choice) {
	cin >> choice;
	for (int i = 0; i < choice.size(); ++i) {
		choice[i] = toupper(choice[i]);
	}
	return choice;
}

double snack_cost(string choice, vector<string> vect,vector<double> vect2) {
	double cost = 0;
	for (int i = 0; i < vect.size(); ++i) {
		if (choice == vect.at(i)) {
			cost = vect2.at(i);
		}
	}
	return cost;
}