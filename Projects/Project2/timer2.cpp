#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <chrono>

using namespace std;

// Define a structure to hold the information of a person
struct Person
{
  string ssn;
  string name;
};

int main(int argc, char *argv[])
{

  // Open the input file
  fstream infile(argv[1]);

  // Initialize variables
  int array_size = 1000;
  int num_items = 0;
  bool duplicate = false;
  Person *array = new Person[array_size];
  int c = 0;

  // Start the timer
  auto start = chrono::high_resolution_clock::now();

  // Process the input file
  char op;
  string ssn, name, last;

  while (!infile.eof())
  {

    infile >> op;
    infile >> ssn;
    infile >> name;
    infile >> last;

    array[c].ssn = ssn;
    array[c].name = name + " " + last;
    switch (op)
    {
    case 'i':
      // Insertion

      duplicate = false;
      for (int i = 0; i < num_items; i++)
      {
        if (array[i].ssn == ssn)
        {
          duplicate = true;
          break;
        }
      }
      if (!duplicate)
      {
        // Add the new person to the end of the array
        if (num_items == array_size)
        {
          // If the array is full, create a new array with doubled size
          array_size *= 2;
          Person *new_array = new Person[array_size];
          for (int i = 0; i < num_items; i++)
          {
            new_array[i] = array[i];
          }
          array = new_array;
          delete[] array;
        }
        // Add the new person to the end of the array
        array[num_items].ssn = ssn;
        array[num_items].name = name;
        num_items++;
      }
      break;
    }
    c++;
  }

  for (int i = 0; i < c; i++)
  {
    cout << array[i].ssn << "  " << array[i].name << endl;
  }
}