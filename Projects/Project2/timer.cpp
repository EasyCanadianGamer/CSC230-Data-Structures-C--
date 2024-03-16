#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <cstdio>
#include <ctime>

using namespace std;

// Define a structure to hold the information of IRS
struct IRS
{
  string ssn;
  string name;
};

int main(int argc, char *argv[])
{
  clock_t start, end;
  double duration;
  // Open the input file
  fstream infile(argv[1]);

  // Initialize variables
  int insertion_counter = 0;
  int deletion_counter = 0;
  int retrieval_counter = 0;
  int array_size = 1000;
  int num_items = 0;
  bool duplicate = false;
  IRS *irs = new IRS[array_size];
  int c = 0;

  // Start the timer
  start = clock();

  // Process the input file
  char op;
  string ssn, name, last;

  while (!infile.eof())
  {

    infile >> op;
    infile >> ssn;
    infile >> name;
    infile >> last;

    irs[c].ssn = ssn;
    irs[c].name = name + " " + last;
    // Check the operation type
    
    switch (op)
    {
    case 'i':
      // Insertion

      duplicate = false;
      // checks for duplicates
      for (int i = 0; i < num_items; i++)
      {
        if (irs[i].ssn == ssn)
        {
          duplicate = true;
          break;
        }
      }

      
      if (!duplicate) // if there the duplicate is either false or true it will add the new entrys at the end of the array
      {
        // Add the new irs to the end of the array
        irs[num_items].ssn = ssn;
        irs[num_items].name = name;
        num_items++;
        insertion_counter++;
      }
      break;

    case 'd':
      // Deletion

      for (int i = 0; i < num_items; i++)
      {
        if (irs[i].ssn == ssn && irs[i].name == name) // if the given ssn and name matches the name and ssn in the array then delete and increase the deletion counter by one.
        {
          // Delete the irs from the array
          for (int j = i + 1; j < num_items; j++)
          {
            irs[j - 1] = irs[j];
          }
          num_items--;
          deletion_counter++;
          break;
        }
      }
      break;

    case 'r':
      // Retrieval

      for (int i = 0; i < num_items; i++)
      {
        if (irs[i].ssn == ssn&& irs[i].name == name) // if the ssn entry matches the ssn in the array, the increase the counter by one
        {
          retrieval_counter++;
          break;
        }
      }
      break;
    }
    c++;

    
        if (c >= array_size)
        {
          // If the array is full, create a new array with doubled size
          array_size *= 2;
          IRS *new_irs = new IRS[array_size];
          for (int i = 0; i < num_items; i++)
          {
            new_irs[i] = irs[i];
          }
          delete[] irs;
          irs = new_irs;
        }


          // If the array entry is less then 1/4 of the array_size, create a new array with half of the size

         if (num_items <= array_size/ 4)
        {
          array_size = array_size / 2;
          IRS* new_irs = new IRS[array_size];
          for (int i = 0; i < num_items; i++)
          {
            new_irs[i] = irs[i];
          }
          delete[] irs;
          irs = new_irs;
        }
  }

  // Stop the timer
  end = clock();
  duration = ( end - start ) / (double) CLOCKS_PER_SEC;

  // Print the results
  cout << "The Number of Valid Insertation :" << insertion_counter << endl;
  cout << "The Number of Valid Deletion :" << deletion_counter << endl;
  cout << "The Number of Valid Retrieval :" << retrieval_counter << endl;
  cout << "Item numbers in the array :" << num_items<< endl;
  cout<<"elapsed time: "<< duration <<'\n';

}