
// C++ for C Coders & Data Structures
// Lecture note by idebtor@gmail.com
//
// Lab 1:
//  - C and C++ coding using g++
//  - a new line escape character and endl manipulator
//  - `using namespace std;`
//  - Understanding `int main(int argc, char *argv[])`
//  - Using functions and prototype
//  - Compiling multiple source files
//
// The following command line compiles a source files and builds
// an executable a.exe or with a given name. Modify it as you need
// 		g++ hello.cpp
//		./a
//		g++ hello.cpp -o hello
//		./hello

#include <iostream>
using namespace std;

void print_strs(int n, char *strs[]);


int main(int argc, char *argv[]) {
	// your code here
  print_strs(argc,argv);

  return 0;
}

// It prints two dimensional array of characters or an array of strings.
// Each string is terminated by a \0 and n is the number of strings.
void print_strs(int n, char *strs[]) {

   // your code here
   cout << "argv[0] = " << strs[0] << endl;

   for (int i = 1; i < n; ++i)
      cout << "Hello " << strs[i] << endl;


 }
