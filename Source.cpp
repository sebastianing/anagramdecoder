#include <iostream>
#include <string>
#include <fstream>
#include <string.h>
#include <algorithm>
#include <time.h>
using namespace std;
/*Pre-Initiate functions before, but leave the code at the end.*/
int estimate(int x);

void main(){
	cout << "Loading..." << endl;
	/*Define all variables*/
	int lnt, est, combos;
	string st, line, dict, search, answer;
	combos = 0;
	/*String Transfer from Dictionary */
	ifstream myFile("dictionary.txt");
	if (myFile.is_open())
	{
		while (getline(myFile, line)){
			dict += line;
		}
		myFile.close()
	}
start:
	/*Start User Interaction*/
	system("CLS");
	cout << "Anagram Generator" << endl;
	cout << "Enter String" << endl;
	getline(cin, st);
	lnt = st.length();
	est = estimate(lnt);
	cout << "Estimated Combinations: " << est << endl;
	cout << "Do you want to show all words? [Y/N]" << endl;
	getline(cin, answer);
	/*Anagram Sort Code*/
	sort(st.begin(), st.end());
	do {  combos = combos + 1;
	/*Dictionary Seach*/
	search = " ";
	search += st;
	search += " ";
	if (dict.find(search) != std::string::npos) {
		std::cout << "A real word (below)" << '\n';
	}
	//Word Print
	if (answer == "Y")cout << st << '\n';
	else
		if (answer == "y")cout << st << '\n';
		else 
			if (dict.find(search) != std::string::npos) {
				std::cout << st << '\n';
			}
	}
	/*To reorder while running operation above*/
	while (next_permutation(st.begin(), st.end()));
	cout << "Combinations: " << combos << endl;
	/*Code Shutdown*/
	cout << "Would you like to go again? [Y/N]" << endl;
	getline(cin, answer);
	if (answer == "Y")goto start;
	else{
		if (answer == "y")goto start;
	}
}
/*Factorial Estimator*/
int estimate(int x){
	int value = 1;
	for ( int i = 2; i <= x; i++){
		value = value * i;
	}
	return value;
}