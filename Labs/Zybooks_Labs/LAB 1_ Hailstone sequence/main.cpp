#include <iostream>
using namespace std;

int main() {

   /* Type your code here. */
   int n; 
   int counter = 1;

   cin >> n;

   cout << n << "\t";



   while ( n >1)

   {
        if ( n%2 == 0)
   {
  


      n = n /2;
       cout << n << "\t";
      
      
      }
   else
   {
      

      n = 3 * n + 1;
      cout << n << "\t";
      
      }

      counter++;

   if ( counter % 10 ==0)
   {
      cout << endl;

   }
   }



   // for ( int i = n; i > 1; i --)
   // {
   //    if ( n%2 == 0)
   // {
  


   //    n = n /2;
   //     cout << n << "\t";
      
      
   //    }
   // else
   // {
   //    cout << n << "\t";

   //    n = 3 * n + 1;}




   
   // counter++;

   // if ( counter%10 ==0)
   // {
   //    cout << endl;

   // }
   // }



   

  

   return 0;
}
