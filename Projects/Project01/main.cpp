#include <iostream>
#include <vector>
#include <cstring> 

using namespace std;

bool checkL(vector<vector<char>> &matrix, char *word, int x);
bool checkR(vector<vector<char>> &matrix, char *word, int x);
bool checkU(vector<vector<char>> &matrix, char *word, int x);
bool checkD(vector<vector<char>> &matrix, char *word, int x);
bool checkW(vector<vector<char>> &matrix, char *word);
int len(char *word);




int main(int argc, char *argv[]) {
    int x, y;
    char c;
    char str[100];

    cin >> x;
    cin >> y;


    vector<vector<char>> vect(x, vector<char>(y)); 
    vector<vector<char>> vect1(x, vector<char>(y)); 


   
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

    int wordLength = len(argv[1]);


    if (checkW(vect, argv[1])) {
        for ( int i = 1; i < wordLength+1; i++)
        {

            for ( int k = i; k < i; k++)
            {
                if (checkR(vect,argv[1],k))
                {  
                    cout << "Word not found!" << endl;
                }
                if ( checkL(vect,argv[1],k))
                {
                    cout << "Word not found!" << endl;
                }
                if ( checkD(vect,argv[1],k))
                {
                    cout << "Word not found!" << endl;
                }
                if ( checkU(vect,argv[1],k))
                {
                    cout << "Word not found!" << endl;
                }
                else
                {
                    cout << "Word not found!" << endl;
                    break;
                }
            }
            }

                    cout << "letter found!" << endl;
        }
        else
        {
            cout << "letter Not found!" << endl;
        }
   
    

        

    return 0;
} 
// this checks the first letter
bool checkW(vector<vector<char>> &matrix, char *word) {
    int rows = matrix.size();
    int cols = matrix[0].size();

    for( int i = 0; i < rows; i++)
    {
        for (int j= 0; j< cols; j++){
            bool match = true;
            if (matrix[i][j] != word[0]) {
                match = false;
            }
        
        if (match) return true;    
        }
    }

    return false;
}

int len( char *word)
{
    int wordLength = strlen(word);   

    return wordLength;
}
bool checkL(vector<vector<char>>& matrix, char* word, int x) {
    int wordLength = strlen(word);
    int cols = matrix[0].size();

    for (int j = 0; j < cols; ++j) {
        bool match = true;
        for (int k = 0; k < wordLength; ++k) {
            if (j + k >= cols || matrix[x][j + k] != word[k]) {
                match = false;
                break;
            }
        }
        if (match) return true;
    }

    return false;
}

bool checkR(vector<vector<char>>& matrix, char* word, int x) {
    int wordLength = strlen(word);
    int cols = matrix[0].size();

    for (int j = cols - 1; j >= 0; --j) {
        bool match = true;
        for (int k = 0; k < wordLength; ++k) {
            if (j - k < 0 || matrix[x][j - k] != word[k]) {
                match = false;
                break;
            }
        }
        if (match) return true;
    }

    return false;
}

bool checkU(vector<vector<char>>& matrix, char* word, int x) {
    int wordLength = strlen(word);
    int rows = matrix.size();

    for (int i = 0; i < rows; ++i) {
        bool match = true;
        for (int k = 0; k < wordLength; ++k) {
            if (i + k >= rows || matrix[i + k][x] != word[k]) {
                match = false;
                break;
            }
        }
        if (match) return true;
    }

    return false;
}

bool checkD(vector<vector<char>>& matrix, char* word, int x) {
    int wordLength = strlen(word);
    int rows = matrix.size();

    for (int i = rows - 1; i >= 0; --i) {
        bool match = true;
        for (int k = 0; k < wordLength; ++k) {
            if (i - k < 0 || matrix[i - k][x] != word[k]) {
                match = false;
                break;
            }
        }
        if (match) return true;
    }

    return false;
}

