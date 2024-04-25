#include <iostream>
#include <fstream>
#include "hashTable.h"
#include <string>
#include <time.h>
#include <ctime>

using namespace std;

int main(int argc, char* argv[]){
  clock_t start, end;
  double duration;

  start = clock();
  // implement this missing part
  // make the array size inside the hash table is 10007
  HashTable<string> ht(10007);

  fstream infile(argv[1]);


    SLL irs;
    int counter=0;
    int dCounter=0;
    int rCounter=0;

   char op;
  string ssn, name, last;

  while (!infile.eof())
  {

    infile >> op;
    infile >> ssn;
    infile >> name;
    infile >> last;
    name = name + " " + last;



    // Check the operation type
    switch(op)
    {    case 'i':
        irs.insert(ssn,name);
      break;
    case 'd':
        irs.remove(ssn,dCounter);
      break;
    case 'r':
        if( irs.search(ssn) != -1)
        {
                  rCounter++;
        }         
         break;
  }
  }


  end = clock();
  duration = ( end - start ) / (double) CLOCKS_PER_SEC;




  cout << "Number of insertions: " << counter-- << endl;
  cout << "Number of deletions: " << dCounter-- << endl;
  cout << "Number of retrievals: " << rCounter << endl;
  cout << "Number of items in the list: " << irs.size() << endl;




  cout<<"elapsed time: "<< duration <<'\n';
}
  
    
}
