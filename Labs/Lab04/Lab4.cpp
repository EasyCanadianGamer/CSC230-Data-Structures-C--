#include <iostream> 
#include <fstream> 
using namespace std; 
 

 struct myData{
    string name;
    string ssn;
 };




int main(int argc, char* argv[]){   
char i;

myData data1[1000];

int index =0;   


string SSn;

fstream input(argv[1]); 
  while(!input.eof()){ 

    input >> i;
    //cout << i; 
    input >> data1[index].ssn;
    //cout << data1[index].ssn;
    input  >> data1[index].name;
    //cout << data1[index].name;
    string Lname;
    input >> Lname;
    data1[index].name += " " + Lname;

    //cout << data1[index].name << " " << Lname;


    index++;
if(!input) break; 

  } 
  
  input.close(); 



cout << "Input a SSN: " << endl;
cin >> SSn;


bool found = false;

for ( int i = 0; i < index;i++)
{
    string str= data1[index].ssn;
    if ( str.compare(SSn) ==0)
    {
        cout << "Found at location " << i << endl;
      found = true;
      break;
    }
}




if (!found) {
    cout << "Not found" << endl;
  }


return 0;
} 