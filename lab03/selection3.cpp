// C++ for C Coders & Data Structures
// Lecture note by idebtor@gmail.com
//
//	selection.cpp - This brute force version of Selection Sort that takes O(n^2).
/*************************************************************
    Lab03 - Understanding a better coding in C/C++
    - NMN(No magic number)
    - DRY(Don't repeat yourself)
    - malloc(), free()
    - assert()
    - rand()
    - mod operator %
    - #if macro
    - Learn about __a better coding__ after all.
***************************************************************/
#include <stdio.h>
#include <iostream>
#include <cassert>
#include <algorithm>
#include <assert.h>
#include <stdlib.h>
using namespace std;

void selectionSort(int *list, int n) {
	int i, j, min, temp;
	for (i = 0; i < n - 1; i++) {
		min = i;
		for (j = i + 1; j < n; j++)
			if (list[j] < list[min]) min = j;
		swap(list[i], list[min]); // Swap min found with the 1st data unsorted
	}
}

void printList(int *list, int n){
	cout << "UNSORTED " << n << endl;
  for (int i = 0; i < n; i++)
    cout << list[i] << " ";
	cout << endl;
}

int main(int argc, char *argv[]) {
	//int list[] = { 3, 4, 1, 7, 0, 9, 6, 5, 2, 8};
	//const int length = 10;
	int N;
	cout << "Let's get number N!! ";
	cin >> N;

	if(N<2){
		cout << "The number must be greater than 1." << endl;
		exit(1);
	}

	int *list = new int[N];
	//list = (int*)malloc(sizeof(int)*N);

	for(int i = 0; i < N; i++){
		list[i]=rand()%N;
	}
	assert(list != nullptr);
	printList(list, N);

	selectionSort(list, N);

	printList(list, N);

	delete[] list;
  cout << "Happy Coding~~" << endl;

}
