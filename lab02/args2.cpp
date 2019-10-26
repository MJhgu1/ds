// C++ for C Coders & Data Structures
// Lecture note by idebtor@gmail.com
//
// Lab 2:
//	1. Using vector class in c++
//	2. ranged-for loop
//	3. function overloading
//	4. include file

#include<iostream>
#include<vector>
using namespace std;

void print_strs(int n, char *strs[]);
void print_strs(vector<string> v);

int main(int argc, char *argv[]) {

	vector<string> v;

	cout << "Using char arrays \n";
	print_strs(argc - 1, &argv[1]);

	// copy *argv[] to a vector<string> object; use push_back() method (or
	// member function) in the vector class

	cout << "Copy *argv[] using vector<string> \n";
	// your code here
	int i = 0;

	while(argv[i]!=0){
		v.push_back(argv[i]);
		i++;
	}
	
	print_strs(v);

}
