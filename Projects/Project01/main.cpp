#include <iostream>
#include <vector>
#include <cstring> 

using namespace std;

bool search(vector<vector<char>>& matrix, char* word, int x, int y, int dx, int dy);


int len(char *word);




int main(int argc, char *argv[]) {
    int x, y;
    char c;
    char str[100];

    cin >> x;
    cin >> y;


    vector<vector<char>> vect(x, vector<char>(y)); 
    //vector<vector<char>> vect1(x, vector<char>(y)); 


   
    for (int i = 0; i < x; i++) {
        for (int j = 0; j < y; j++) {
            cin >> c;
            vect[i][j] = c;
        }
    }

    for (int i = 0; i < x; i++) {
        for (int j = 0; j < y; j++) {
            cout << vect[i][j] << " ";
        }
        cout << endl;
    }

    int s = argc - 1; 
   for( int k = 1; k < s ; k++)
   {
    for( int i =0; i < x; i++)
    {
        for ( int j = 0; j < y; j++)
        {

        }
    }
   }

    return 0;
} 

bool search(vector<vector<char>>& matrix, char* word, int x, int y, int dx, int dy) 
{
        int wordLength = strlen(word);   
        int x = x + dx;
        int y = x + dy;

        for( int i = 0; i < wordLength; i++)
        {

            bool match = false;
            if(word[i] == matrix [x][y])
            {
                match = true;
            }
            if(match) return false;
        }
        return true;

}
