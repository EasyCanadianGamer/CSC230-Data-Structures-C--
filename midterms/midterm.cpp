#include <iostream>
#include <vector>
#include <cstring>
#include <array>
using namespace std;

// void myth(int n)
// {
//     if ( n > 0)
//     {
//         myth(n-1);
//         for( int i =0; i< n;i++)
//         {
//             cout << "#";
//         }
//         cout << endl;
//     }
// }


// class A{
//     public:
//     void foo(){
//         cout<< "From A" << endl;
//     }
// };
// class B:public A{
//     public:
//     void foo(){
//         cout<< "From B" << endl;
//     }
// };


// bool foo2( char*p)
// {
//     int i =strlen(p);
//     char* r = p + i-1;
//     while( p < r)
//     {
//         if( *p == *r)
//         {
//             p++;
//             r--;
//         }
//         else{
//             return false;
//         }
//     }
//     return true;
// }

// void bar ( int& m, int *n)
// {
//     m = *n;
// }


void printArray(const int* arr, int size)
{
    for (int i = 0; i < size; i++)
    {
        cout << arr[i] << "\t";
    }
    cout << endl;
}

void arrMerge( int*& A, int Asize, int*& B, int Bsize, int*& C, int Csize)
{
    Csize = Asize + Bsize;

    C = new int[Csize];
    for ( int i = 0; i < Asize; i++)
    {
        C[i] = A[i];
    }
    delete [] A;
    for ( int i = 0; i < Bsize; i++)
    {
        C[Asize+i] = B[i];
    }
    delete [] B;
    
}


int main()
{

     int ASIZE = 10;
     int BSIZE = 3;
    int Czse = 0;

    int*a = new int[ASIZE];
    int* b = new int [BSIZE];
    int* c = nullptr;

    for ( int i =0; i < ASIZE; i+2)
    {
        a[i] = i; 
    }
    for ( int i =0; i < BSIZE; i+3)
    {
        b[i] = i;
    }



cout << "Array A: ";
    printArray(a, ASIZE);
    cout << "Array B: ";
    printArray(b, BSIZE);

    arrMerge(a, ASIZE, b, BSIZE, c, Czse);

    cout << "Merged Array C: ";
    printArray(c, Czse);

    delete[] c; 



    

// char arr [] = "tcnjnct";

// cout << boolalpha <<  foo2(arr) << endl;



// int a =10;
// int &b =a; // b =10 
// int c =30;
// b = 20;// a =20

// bar( a, &c);
// a =30
// b =30  

//bar( a, &b);

// cout << a << "\t" << b << "\t" << c << endl;


    // A* p;
    // B obj;
    // p = &obj;
    // p -> foo();




    // myth(atoi(argv[1]));


    // int x = atoi(argv[1]);
    // int y = atoi(argv[2]);



    // vector<vector<int>> vect;
    // vect.resize(x);
    // for ( int i =0; i < x;i++)
    // {
    //     vect[i].resize(y);
    // }

    // for ( int i =0; i<x;i++)
    // {
    //     for(int j = 0; j<y; j++)
    //     {
    //         vect[i][j] =j;
    //     }
    // }
    //     for ( int i =0; i<x;i++)
    // {
    //     for(int j = 0; j<y; j++)
    //     {
    //         cout << vect[i][j] << "\t";
    //     }
    //     cout << endl;
    // }


  
        //return 0;

}

