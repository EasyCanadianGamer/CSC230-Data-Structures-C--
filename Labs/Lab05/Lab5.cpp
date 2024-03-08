#include <iostream>
using namespace std;

int A[100];

void com(int len, int size){

  if( len < 1)
  {
    for( int i = 0; i < size; i ++)
    {
      cout << A[i];
    }
     cout << endl;
  }
      else
    {
      for ( int i = 0;  i< 10; i++)
      {
        A[len-1] = i;
        com(len-1, size);
      }
    }

}

int main(int argc, char* argv[]){

  com(atoi(argv[1]), atoi(argv[1]));
}
