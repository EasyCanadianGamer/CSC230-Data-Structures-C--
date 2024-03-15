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
  const int INITIALIZED_SIZE = 1000;
  int insertion_counter = 0;
  int deletion_counter = 0;
  int retrieval_counter = 0;
  int array_size = INITIALIZED_SIZE;
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
    // Check the operation type
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
          delete[] array;
          array = new_array;
        }
        // Add the new person to the end of the array
        array[num_items].ssn = ssn;
        array[num_items].name = name;
        num_items++;

        if (num_items < array_size / 4)
        {
          array_size = array_size / 2;
          Person *new_array = new Person[array_size];
          for (int i = 0; i < num_items; i++)
          {
            new_array[i] = array[i];
          }
          delete[] array;
          array = new_array;
        }
        array[num_items].ssn = ssn;
        array[num_items].name = name;
        num_items++;
        insertion_counter++;
      } if (num_items == array_size)
        {
          // If the array is full, create a new array with doubled size
          array_size *= 2;
          Person *new_array = new Person[array_size];
          for (int i = 0; i < num_items; i++)
          {
            new_array[i] = array[i];
          }
          delete[] array;
          array = new_array;
        }
        // Add the new person to the end of the array
        array[num_items].ssn = ssn;
        array[num_items].name = name;
        num_items++;

        if (num_items < array_size / 4)
        {
          array_size = array_size / 2;
          Person *new_array = new Person[array_size];
          for (int i = 0; i < num_items; i++)
          {
            new_array[i] = array[i];
          }
          delete[] array;
          array = new_array;
        }
        array[num_items].ssn = ssn;
        array[num_items].name = name;
        num_items++;
        insertion_counter++;
      }
      break;

    case 'd':
      // Deletion

      for (int i = 0; i < num_items; i++)
      {
        if (array[i].ssn == ssn && array[i].name == name)
        {
          // Delete the person from the array
          for (int j = i + 1; j < num_items; j++)
          {
            array[j - 1] = array[j];
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
        if (array[i].ssn == ssn && array[i].name == name)
        {
          retrieval_counter++;
          break;
        }
      }
      break;
    }
    c++;
  }

  // Stop the timer
  auto end = chrono::high_resolution_clock::now();
  auto duration = chrono::duration_cast<chrono::microseconds>(end - start);

  for (int i = 0; i < c; i++)
  {
    cout << array[i].ssn << "  " << array[i].name << endl;
  }

  // Print the results
  cout << "The Number of Valid Insertation :" << insertion_counter << endl;
  cout << "The Number of Valid Deletion :" << deletion_counter << endl;
  cout << "The Number of Valid Retrieval :" << retrieval_counter << endl;
  cout << "Item numbers in the array :" << num_items << endl;
}