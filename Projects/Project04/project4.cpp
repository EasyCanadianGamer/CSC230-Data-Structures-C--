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

  int counter = 0;
  int rCounter = 0;
  int dCounter = 0;
  char op;
  string ssn, name, last;


  start = clock();
  // implement this missing part
  // make the array size inside the hash table is 10007
  HashTable<string> irs(10007);

  // read the file
  ifstream infile(argv[1]);
  while (!infile.eof())
  {
    infile >> op;
    infile >> ssn;
    infile >> name;
    infile >> last;


    name = name + " " + last;

      // Check the operation type

    cout << "Operation: " << op << endl;
    switch(op)
    {    case 'i':
         if(irs.insert(ssn,name))
         {
          counter++;
         }
      break;
    case 'd':
        if(irs.erase(ssn))
        {
          dCounter++;
        }
      break;
    case 'r':
        if( irs.find(ssn))
        {
                  rCounter++;
        }         
         break;
  }
  }
  // infile.close();





  end = clock();
  duration = ( end - start ) / (double) CLOCKS_PER_SEC;
  
  cout << "Number of insertions: " << counter-- << endl;
  cout << "Number of deletions: " << dCounter-- << endl;
  cout << "Number of retrievals: " << rCounter << endl;
  cout << "Number of items in the list: " << irs.getSize() << endl;
  cout << "Time taken: " << duration << " seconds" << endl;
  return 0;

}
  
    

