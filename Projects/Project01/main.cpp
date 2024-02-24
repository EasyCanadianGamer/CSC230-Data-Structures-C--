#include "colormod.h"
#include <iostream>
#include <vector>
#include <cstring> 

using namespace std;

bool search(vector<vector<char>>& matrix, char* word, int x, int y, int dx, int dy, vector<vector<int>>& matrix2);

void record(vector<vector<int>>& matrix2,  int i, int j, int x);

void printMatrix(vector<vector<int>>& matrix)
{
    int x = matrix.size();

    for (int i = 0; i < x; i++)
    {
        int y = matrix[i].size(); 

        for (int j = 0; j < y; j++)
        {
            cout << matrix[i][j] << " ";
        }
        cout << endl;
    }
}


int main(int argc, char *argv[]) {
    int x, y;
    char c;

    cin >> x;
    cin >> y;


    vector<vector<char>> vect(x, vector<char>(y)); 
    vector<vector<int>> vect1(x, vector<int>(y)); 

    Color::Setting red(Color::FG_RED); 
    Color::Setting def(Color::FG_DEFAULT); 
   
    for (int i = 0; i < x; i++) {
        for (int j = 0; j < y; j++) {
            cin >> c;
            vect[i][j] = c;
        }
    }

        for (int i = 0; i < x; i++) {
            for (int j = 0; j < y; j++) {
                vect1[i][j] = 0;
        }
    }

   for( int k = 0; k < argc-1 ; k++)
   {
        for( int i =0; i < x; i++)
    {
        for ( int j = 0; j < y; j++)
        {
            if( search(vect,argv[1 +k],i,j, 0, 0,vect1))
            {

                if(search(vect,argv[1 +k],i,j, 0, 1,vect1) || search(vect,argv[1 +k],i,j, 0, -1,vect1) || 
                   search(vect,argv[1 + k],i,j, 1, 0,vect1) || search(vect,argv[1 + k],i,j, -1, 0,vect1) || 
                   search(vect,argv[1 + k],i,j, 1, 1,vect1) || search(vect,argv[1 + k],i,j, -1, -1,vect1)||
                   search(vect,argv[1 + k],i,j, -1, 1,vect1)|| search(vect,argv[1 +k],i,j, 1, -1,vect1))
                   {                                     
                         cout << "This ->" << red << "Hello, world!" << def << "<- is red." << endl;
                         
                   }
            }
     
        }
        

    }
    
   }


           


            
            


    return 0;
} 



bool search(vector<vector<char>>& matrix, char* word, int x, int y, int dx, int dy, vector<vector<int>>& matrix2) 
{
    int wordLength = strlen(word);

    for (int i = 0; i < wordLength; i++)
    {
        int newX = x + dx;
        int newY = y + dy;

        if (newX >= 0 && newX < matrix.size() && newY >= 0 && newY < matrix[0].size()) {
            if (word[i] == matrix[newX][newY])
            {
                int d = 1;
                record(matrix2, x, y, d);
                return true;
            }
        }
        else {
            break; 
        }
    }

    int d = 0;
    record(matrix2, x, y, d);
    return false;
}


void record(vector<vector<int>>& matrix2, int i, int j, int x)
{
    matrix2[i][j] = x;
}
