#include "stdafx.h"
#include "SearchandSort.h"
//#include <iostream>
//#include <vector>

using namespace std;
//const int MLS = 100;

SearchandSort::SearchandSort()
{
	items[MLS] = 0;
}


SearchandSort::~SearchandSort()
{
}

void SearchandSort::Menu_Opt() {

	if (SIZE < 1) {
		cout << "EMPTY" << endl;
	}
	else {
		for (int count = 0; count < SIZE; count++) {
			cout << items[count] << " ";
		}
	}

	if (KNOWN == true)
		cout << "Ordered" << endl;
	cout << "---------------------------------------------" << endl;
	cout << "\t\t" << " MENU:" << endl;
	cout << "---------------------------------------------" << endl;
	cout << "1. Reset current List from keyboard" << endl;
	cout << "2. Bubble Sort" << endl;
	cout << "3. Selection Sort" << endl;
	cout << "4. Insertion Sort" << endl;
	cout << "5. Linear Search" << endl;
	cout << "6. Binary Search" << endl;
	cout << "7. Quit program" << endl;
	cout << "---------------------------------------------" << endl;
	cout << "Current List" << endl;
	cout << "" << endl;
}

void SearchandSort::Store_Input() {
	element uservalue = 0;
	SIZE = 0;
	cout << "enter elements, " << SENTINEL << " to stop:";

	while ((uservalue != SENTINEL) && (SIZE < MLS)) {
		while (!(cin >> uservalue)) {
			cout << "It is not an integer!!!";
			cin.clear();
			cin.ignore(100, '\n');
		}
		if (uservalue != SENTINEL) {
			items[SIZE] = uservalue;
			SIZE++;
		}
		else
			;
	}
	KNOWN = false;
}

void SearchandSort::Bubble_Sort() {
	bool swap;
	int temp;
	int theoricalComparisons = 0;
	int theoricalMoves = 0;
	int actualComparisons = 0;
	int actualMoves = 0;

	theoricalComparisons = (SIZE * SIZE) / 2;
	theoricalMoves = ((SIZE * SIZE) / 2) * 3;
	do {
		swap = false;
		for (int count = 0; count < (SIZE - 1); count++) {
			actualComparisons++;
			if (items[count] > items[count + 1]) {
				temp = items[count];
				items[count] = items[count + 1];
				items[count + 1] = temp;
				swap = true;
				actualMoves += 3;
			}
		}
	} while (swap);
	KNOWN = true;
	cout << "Theorical Comparisons " << theoricalComparisons << "and, Theorical Moves" << theoricalMoves << endl;
	cout << "Actual Comparisons " << actualComparisons << "and, Actual Moves" << actualMoves << endl;
	cout << "Finishing Bubble Sort...." << endl;
}

void SearchandSort::Selection_Sort() {
	int scanArray, minIndexArray, minValueArray;
	int theoricalComparisons = 0;
	int theoricalMoves = 0;
	int actualComparisons = 0;
	int actualMoves = 0;

	theoricalComparisons = (SIZE * SIZE) / 2;
	theoricalMoves = ((SIZE * SIZE) / 2) + SIZE;

	for (scanArray = 0; scanArray < (SIZE - 1); scanArray++) {
		minIndexArray = scanArray;
		minValueArray = items[scanArray];
		for (int i = (scanArray + 1); i < SIZE; i++) {
			actualComparisons++;
			if (items[i] < minValueArray) {
				minValueArray = items[i];
				minIndexArray = i;
				actualMoves++;
			}
			items[minIndexArray] = items[scanArray];
			items[scanArray] = minValueArray;
		}
		actualMoves += 3;
	}
	KNOWN = true;
	cout << "Theorical Comparisons " << theoricalComparisons << " and, Theorical Moves" << theoricalMoves << endl;
	cout << "Actual Comparisons " << actualComparisons << " and, Actual Moves" << actualMoves << endl;
	cout << "Finishing Selection Sort...." << endl;
}

void SearchandSort::Insertion_Sort() {

	int scanArray, minArray, maxArray, temp;
	bool done, swap;
	int theoricalComparisons = 0;
	int theoricalMoves = 0;
	int actualComparisons = 0;
	int actualMoves = 0;

	theoricalComparisons = (SIZE * SIZE) / 2;
	theoricalMoves = ((SIZE * SIZE) / 2) * 3;

	for (int i = 1; i < SIZE; i++) {
		maxArray = i;
		done = false;
		//bool swap;
		while ((maxArray >= 1) && (!done)) {
			actualComparisons++;
			minArray = maxArray - 1;
			if (items[minArray] < items[maxArray]) {
				temp = items[minArray];
				items[minArray] = items[maxArray];
				items[maxArray] = temp;
				//swap = true;
				maxArray--;
				actualMoves += 3;
			}
			else
				done = true;
		}
	}
	KNOWN = true;
	cout << "Theorical Comparisons " << theoricalComparisons << " and, Theorical Moves" << theoricalMoves << endl;
	cout << "Actual Comparisons " << actualComparisons << " and, Actual Moves" << actualMoves << endl;
	cout << "Finishing Insertion Sort...." << endl;
}

void SearchandSort::Linear_Search(element target) {
	int scanArray = 0;
	bool found;
	int actualComparisons = 0;
	found = false;
	while (!found && (scanArray < SIZE)) {
		actualComparisons++;
		if (items[scanArray] == target) {
			found = true;
			scanArray++;
			cout << "Target #" << target << ", was found in position #"
				<< scanArray << endl;
			cout << "Theorical Comparisons " << SIZE << endl;
			cout << "Actual Comparisons " << actualComparisons << endl;
		}
		else {
			scanArray++;
		}
	}
	if (found != true) {
		cout << "Target #" << target << ", was not found..." << endl;
		cout << "Theorical Comparisons " << SIZE << endl;
		cout << "Actual Comparisons " << actualComparisons << endl;
	}
	cout << "Finishing Linear Search..." << scanArray << endl;
}

void SearchandSort::Binary_Search(element target) {

	int first = 0;
	int last = SIZE - 1;
	int middle;
	int position = -1;
	bool found = false;
	int theoricalComparisons = 0;
	//int theoricalMoves = 0;
	int actualComparisons = 0;
	//int actualMoves = 0;

	while (first <= last) {
		middle = (first + last) / 2;
		first = middle + 1;
		theoricalComparisons++;
	}

	while (!found && (first <= last)) {
		middle = (first + last) / 2;
		if (items[middle] == target) {
			found = true;
			position = middle + 1;
			cout << "Target #" << target << " was found in position #"
				<< position << endl;
		}
		else if (items[middle] > target) {
			last = middle - 1;
			actualComparisons++;
		}
		else if (items[middle] < target) {
			first = middle + 1;
			actualComparisons++;
		}
		else if (found != true) {
			cout << "Target # " << target << " was not found..." << endl;
		}
		else
			;
	}
	cout << "Theorical Comparisons " << theoricalComparisons << endl;
	cout << "Actual Comparisons " << actualComparisons << endl;
	cout << "Finishing Binary Search..." << endl;
}