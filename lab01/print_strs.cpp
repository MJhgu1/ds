#include <iostream>
using namespace std;


void print_strs(int n, char *strs[]) {

   // your code here
   cout << "argv[0] = " << strs[0] << endl;

   if(strs[1]!=0){
     for (int i = 1; i < n; ++i)
       cout <<  strs[i] << endl;
     }
   else
       cout << "Hello World!" << endl;


 }
