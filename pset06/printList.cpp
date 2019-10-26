// bubble sort by idebtor@gmail.com
// This brute force version of bubble sort that takes O(n^2).
// 2019/02/02: Created
//
// Compilation:
// g++ bubble.cpp -o sort
// g++ bubble.cpp -o sort -DDEBUG
// To use DEBUG or test it, compile with -D option and turn #if 1 on.
// To make the function included in other program, turn #if 0 off.


#include <cstdlib>
#include <ctime>
#include <cassert>
#include <iostream>
#include <iomanip>
#include "nowic.h"

using namespace std;

void printList(int *list, int N, int max_print, int per_line) {
    DPRINT(cout << ">printList...N=" << N << " max_print=" << max_print << endl;)

        while(max_print>=N){
            max_print = max_print/2;
        }
        for(int i = 0; i < max_print; i++){
            if(((i+1)%per_line)==1)
                cout << endl;
            cout << "       " << list[i] ;
        }
        cout << endl;
        for(int i = N-max_print; i < N; i++){
            if(((i+1-N+max_print)%per_line)==1)
                cout << endl;
            cout << "       " << list[i] ;
        }
        // your code here
        // Optionally, you may create a help function such as _printList()/


    DPRINT(cout << "<printList" << endl;)
}
