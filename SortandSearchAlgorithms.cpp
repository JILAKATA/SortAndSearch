// SortandSearchAlgorithms.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "SearchandSort.h"
#include <iostream>
#include <cmath>
#include <ctime>
#include <vector>
#include <cstdlib>
using namespace std;
//typedef int element;

//Maximun List Size
//const int MLS = 100;
//Create an Sentinel, so the user can stop inputing numbers
//const element SENTINEL = -1;

//int SIZE;

int main()
{
	SearchandSort Alg;

	int user_Opt;
	element target = 0;
	//Sort.Known = true;
	//SIZE = 0;
	cout << "===========================================================================================" << endl;
	cout << "Welcome, this program will search and sort numbers by using sorting and searching";
	cout << "algorithms" << endl;
	cout << "===========================================================================================" << endl;
	cout << "Choose the following options: " << endl;
	do {
		Alg.Menu_Opt();
		while (!(cin >> user_Opt)) {
			cout << "Please enter an option from 1 through 6:";
			cin.clear();
			cin.ignore(100, '\n');
		}
		while (user_Opt < 1 || user_Opt > 7) {
			cout << "Invalid option, please enter a number option from the menu!!: ";
			cin.clear();
			cin.ignore(100, '\n');
			cin >> user_Opt;
		}
		if (user_Opt == 1) {
			Alg.Store_Input();
		}

		else if (user_Opt == 2) {
			Alg.Bubble_Sort();
		}
		else if (user_Opt == 3) {
			Alg.Selection_Sort();
		}

		else if (user_Opt == 4) {
			Alg.Insertion_Sort();
		}
		else if (user_Opt == 5) {
			cout << "Enter a number to search: ";
			cin >> target;
			Alg.Linear_Search(target);
		}
		else if (user_Opt == 6) {
			cout << "Enter a number to search: ";
			cin >> target;
			Alg.Binary_Search(target);
		}
		else
			;
	} while (user_Opt != 7);
	system("pause");
	return 0;
}


