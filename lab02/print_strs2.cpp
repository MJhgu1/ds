#include <iostream>
#include<vector>
using namespace std;


void print_strs(int n, char *strs[]) {

   // your code here
   //cout << "argv[0] = " << strs[0] << endl;

   if(strs[1]!=0){
     for (int i = 0; i < n; ++i)
       cout << strs[i] << endl;
     }
   else
       cout << "Hello World!" << endl;


 }

 void print_strs(vector<string> v) {

   cout << "Print argv using indexing \n";
   // your code here
   for(int i = 0; i < v.size(); i++){
     cout << v[i] << endl;
   }
 }
