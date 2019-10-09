#include <string>
#include <vector>
using namespace std;// for some reason it would't let me use this functon without adding this if you can find a way to remove them feel free

void menu(vector<string> vect, vector<string> vec2, int i, vector<int> stocks);

string upper(string choice, vector<string> vect, vector<int> &stocks);

double snack_cost(string choice, vector<string> vect, vector<double> vect2);

void Main_Menu(vector<string> vect, vector<string> vec2, vector<int> stocks);

double change_user(string choice, double cost, vector<string> vect, vector<string> vect2);

void exact_change(double change);
