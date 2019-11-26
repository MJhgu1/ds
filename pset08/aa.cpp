#include <iostream>
#include <sstream>
#include <string>
using namespace std;

int joy(int a, int b){
  return a*b*1004;
}

int main(int argc, char **argv) {
  int (*fp)(int,int);
  fp = joy;
  cout<< "joy: " << fp(1,1) <<endl;
}
