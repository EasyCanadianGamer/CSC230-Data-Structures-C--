#include <iostream>
#include <string>
using namespace std;

int main() {


char lettersKey[] = {'a','b','c','d','e','f','g','h','i','j','k','l','m','n','o','p','q','r','s','t','u','v','w','x','y','z'};

string database[] = {};

string password = " ";

int spaces; 

cin >> password;
cin >> spaces;


for ( char& i: password){
   switch (i)
   {
      case 'b':
         i = lettersKey[i + 4];
         break;
      case 'b':
         i = lettersKey[i + 4];
         break;
      case 'b':
         i = lettersKey[i + 4];
         break;
      
      
   } 
}




   return 0;
}