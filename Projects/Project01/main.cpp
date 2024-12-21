
#include "colormod.h"
#include <iostream>
#include <vector>
#include <cstring> 

using namespace std;

bool search(vector<vector<char>>& matrix, const string& word, int x, int y, int dx, int dy, vector<vector<int>>& matrix2);

void record(vector<vector<int>>& matrix2,  int i, int j, int x);

void printMatrix(const vector<vector<char>>& matrix, const vector<vector<int>>& highlightMatrix);


int main(int argc, char *argv[]) {
    int x, y;
    char c;

    // Read the dimensions of the matrix
    cin >> x >> y;

    // Initialize the matrix and the highlight matrix
    vector<vector<char>> matrix(x, vector<char>(y));
    vector<vector<int>> highlightMatrix(x, vector<int>(y, 0));

    // Read the matrix from the standard input
    for (int i = 0; i < x; i++) {
        for (int j = 0; j < y; j++) {
            cin >> c;
            matrix[i][j] = c;
        }
    }

    // Loop through the command-line arguments (excluding the program name)
    for (int k = 1; k < argc; k++) {
        string word = argv[k];

        // Loop through all positions in the matrix
        for (int i = 0; i < x; i++) {
            for (int j = 0; j < y; j++) {
                // Search for the word in all directions
                if (search(matrix, word, i, j, 0, 0, highlightMatrix) ||
                    search(matrix, word, i, j, 0, 1, highlightMatrix) ||
                    search(matrix, word, i, j, 0, -1, highlightMatrix) ||
                    search(matrix, word, i, j, 1, 0, highlightMatrix) ||
                    search(matrix, word, i, j, -1, 0, highlightMatrix) ||
                    search(matrix, word, i, j, 1, 1, highlightMatrix) ||
                    search(matrix, word, i, j, -1, -1, highlightMatrix) ||
                    search(matrix, word, i, j, -1, 1, highlightMatrix) ||
                    search(matrix, word, i, j, 1, -1, highlightMatrix)) {
                    // If word is found, mark the corresponding positions in the highlight matrix
                    record(highlightMatrix, i, j, 1);
                }
            }
        }
    }

    // Print the matrix with highlighted positions
    printMatrix(matrix, highlightMatrix);

    return 0;
}

bool search(vector<vector<char>>& matrix, const string& word, int x, int y, int dx, int dy, vector<vector<int>>& matrix2) {
    int wordLength = word.length();

    // Calculate the new position based on the direction vector (dx, dy)
    int newX = x;
    int newY = y;

    

    //int counter = 0;
    // Check if the word can fit starting from position (x, y) in the given direction (dx, dy)
    for (int i = 0; i < wordLength; i++) {
        // Check if the current position is within the bounds of the matrix
        if (newX >= 0 && newX < matrix.size() && newY >= 0 && newY < matrix[0].size()) {
            // Check if the character matches the corresponding character in the word
            if (word[i] == matrix[newX][newY]) {
                // Mark the position in matrix2 as visited
                
            if( i < wordLength - 1) {
               newX += dx;
               newY += dy;
            }

            } else {
                // If any character does not match, return false
                return false;
            }
        } else {
            // If the position is out of bounds, return false
            return false;
        }

        // Move to the next position using the direction vector

    }

    
    // If the loop completes without returning false, the word is found
    for (int i = 0; i < wordLength; i++) {
           matrix2[newX][newY] = 1;
               newX -= dx;
               newY -= dy;



        }  
          return true;
}



void record(vector<vector<int>>& matrix2, int i, int j, int x)
{
    matrix2[i][j] = x;
}


void printMatrix(const vector<vector<char>>& matrix, const vector<vector<int>>& highlightMatrix) {
    for (int i = 0; i < matrix.size(); ++i) {
        for (int j = 0; j < matrix[i].size(); ++j) {
            // Check if the current position is highlighted
            if (highlightMatrix[i][j] == 1) {
                // If highlighted, print the character in red
                Color::Setting red(Color::FG_RED);
                cout << red << matrix[i][j] << " ";
            } else {
                // If not highlighted, print the character in default color
                Color::Setting def(Color::FG_DEFAULT);
                cout << def << matrix[i][j] << " ";
            }
        }
        // Move to the next line after printing each row
        cout << endl;
 }
}
