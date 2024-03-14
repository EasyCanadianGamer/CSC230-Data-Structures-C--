#include <iostream>
#include <cstdio>
#include <ctime>
#include <fstream>
#include<unordered_map>
using namespace std;





 struct IRS{
    string name;
    string ssn;
    char l;
 
 };

int Valids( IRS temp[], int ind, char k);

void checkValids( IRS temp[],IRS temp2[], int ind, char k);
void checkDupe(IRS temp[], IRS temp2[], int ind);




int main(int argc, char* argv[]) {
  clock_t start, end;
  double duration;  
  int index = 0;
  


  start = clock();

  /* Your code is here */
int c =0;


  char key1 = 'i';
  char key2 = 'r';
  char key3 = 'd'; 


 static IRS irs[1000];

 IRS valids[1000];




  fstream input(argv[1]); 
  while(!input.eof()){ 

    input >> irs[index].l;
    input >> irs[index].ssn;
    input  >> irs[index].name;
    string Lname;
    input >> Lname;
    irs[index].name += " " + Lname;


    index++;
if(!input) break; 

  } 
  
  input.close(); 


  // put inserts in the new list:
  checkValids(irs, valids, index, key1);



checkDupe(irs, valids, index);


  cout << "Valid Insertations: " << Valids(valids, index, key1) << endl;
  cout << "Valid Deletations: " << Valids(irs, index, key3) << endl;
  cout << "Valid Retrevials: " << Valids(irs, index, key2) << endl;



  end = clock();
  duration = ( end - start ) / (double) CLOCKS_PER_SEC;

  cout<<"elapsed time: "<< duration <<'\n';
}

int Valids( IRS temp[], int ind, char k)
{
  int c = 0;

  for( int i =0; i < ind; i++)
  {
    if(temp[i].l == k)
    {
      c++;
    }
  }
  return c;
}




void checkValids( IRS temp[],IRS temp2[], int ind, char k)
{
  for( int i = 0; i < ind; i++)
  {
    if(temp[i].l == k)
    {
      temp2[i].l = temp[i].l;
      temp2[i].ssn = temp[i].ssn;
      temp2[i].name = temp[i].name;
    }
  }
}


void checkDupe(IRS temp[], IRS temp2[], int ind)
{
  for( int i =0; i < ind; i++)
  {

    if (temp2[i].l != temp[i].l)
    {
          if(temp2[i].ssn == temp[i+1].ssn)
    {
            temp2[i].ssn 
    }
    }
  }
}

