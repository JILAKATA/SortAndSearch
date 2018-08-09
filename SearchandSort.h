#pragma once
#include <iostream>
#include <vector>
#include <cstdlib>
#include <algorithm>
#include <iterator>

using namespace std;
const int DEFAULT_MLS = 0;
typedef int element;
//int SIZE;
const int MLS = 100;
const element SENTINEL = -1;
class SearchandSort
{
private:
	//const int MLS = 100;
	//vector<int> items;
	element items[MLS];

public:
	SearchandSort();
	//Menu(element items2[]);
	~SearchandSort();
	void Menu_Opt();
	void Store_Input();
	bool KNOWN;
	void Bubble_Sort();
	void Insertion_Sort();
	void Selection_Sort();
	void Binary_Search(element target);
	void Linear_Search(element target);
	int SIZE;
};