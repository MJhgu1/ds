#include <iostream>
using namespace std;
#define SWAP(x, y, t) ((t) = (x), (x) = (y), (y) = (t))
void selectionSort(int[], int);

int main(int argc, char *argv[]) {
    int i, n, MAX_SIZE;
    if(argv[1]!=NULL){
      if(strtol(argv[2],NULL,10)==0){
        exit(EXIT_FAILURE);
      }else{
        n=strtol(argv[2],NULL,10);
        MAX_SIZE=strtol(argv[2],NULL,10);
        while (1) {
          if(n < 0 || n > MAX_SIZE){
            cout << "Enter the number of samples: ";
            cin >> n;
          }else break;
        }
      }

  }else{
    cout << "input the MAX_SIZE: ";
    cin >> MAX_SIZE;
    do{
        cout << "Enter the number of samples: ";
        cin >> n;
        if(n == 0){
          exit(EXIT_FAILURE);
        }
      }while(n < 0 || n > MAX_SIZE);

    }

      int* list = new int[MAX_SIZE];
      cout << endl;
      cout << "UnSorted array: " << endl;
      for (i = 0; i < n; i++) { // randomly generate numbers
          list[i] = rand() % 1000;
          cout << list[i] << " " ;
        }
        selectionSort(list, n);
        cout << endl;
        cout << "Sorted array: " << endl;
        for (i = 0; i < n; i++) {
          cout << list[i] << " " ;
        }
        cout << endl;
        delete [] list;
        exit(EXIT_SUCCESS);
}

void selectionSort(int list[], int n) {
  int i, j, min, temp;
  for (i = 0; i < n - 1; i++) {
    min = i;
    for (j = i + 1; j < n; j++)
      if (list[j] < list[min])
        min = j;
    temp = list[i];
    list[i] = list[min];
    list[min] = temp;
  }
}
