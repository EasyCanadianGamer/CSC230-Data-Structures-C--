#include <iostream>
#include <fstream>
using namespace std;

// quick sort function
void quickSort(int arr[], int left, int right) {

    // please implement this function
    if ((right - left) < 2) {
        return;
    }

    int p = arr[left];
    int j = left;
    int t = right;

    while(j < t){
      if(arr[j+1] <= p){
        int temp = arr[j+1];
        arr[j+1] = arr[j];
        arr[j] = temp;
        j++;
      }
      else {
        int temp = arr[j+1];
        arr[j+1] = arr[t];
        arr[t] = temp;
        t--;
      }
    }
  quickSort(arr, left, j-1);
  quickSort(arr, j+1, right);

   
}

int main(int argc, char* argv[]){
  fstream input(argv[1]);

  int vals[5000];

    // please implement this function
    cout << "The Quick Sort result is: " << endl;
    int len = 0;
    int ind = 0;
    int val = 0;


    while(!input.eof()){
      input >> val;
      vals[ind] = val;
      ind++;
      len++;
  }

  quickSort(vals, 0, len-1);

  for(int i = 0; i < len; i++){
    cout << vals[i] << " " << endl;
  }

}
