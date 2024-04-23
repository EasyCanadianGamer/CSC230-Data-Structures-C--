#include <iostream>
#include <cstdio>
#include <ctime>
#include <fstream>

#include "DLL.h"
using namespace std;

int main(int argc, char *argv[]) {
  clock_t start, end;
  double duration;

  start = clock();

  /* Your code is here */


  fstream infile(argv[1]);


    DLL irs;
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
        irs.insert(ssn,name,counter);
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


  // irs.display();

  // DLL irscopy = DLL(irs);



  cout << "Number of insertions: " << counter-- << endl;
  cout << "Number of deletions: " << dCounter-- << endl;
  cout << "Number of retrievals: " << rCounter << endl;
  cout << "Number of items in the list: " << irs.size() << endl;




  cout<<"elapsed time: "<< duration <<'\n';
}

