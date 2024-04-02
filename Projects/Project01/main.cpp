
#include "colormod.h"
#include <iostream>
#include <vector>
#include <cstring> 

using namespace std;

bool search(vector<vector<char>>& matrix, const string& word, int x, int y, int dx, int dy, vector<vector<int>>& matrix2);
bool matchWord(const vector<vector<char>>& matrix, const string& word, int i, int j, int di, int dj);
void record(vector<vector<int>>& matrix2,  int i, int j, int x);
bool searchWord(const vector<vector<char>>& matrix, const string& word, int i, int j);
void printMatrix(const vector<vector<char>>& matrix, const vector<vector<int>>& highlightMatrix);

void printM(const vector<vector<char>>& matrix, const vector<string>& words);
int main(int argc, char *argv[]) {
    int x, y;
    char c;

    string word;

    // Read the dimensions of the matrix
    cin >> x >> y;

    // Initialize the matrix and the highlight matrix
    vector<vector<char>> matrix(x, vector<char>(y));

    vector<string> words(argv + 1, argv + argc);
    // Read the matrix from the standard input
    for (int i = 0; i < x; i++) {
        for (int j = 0; j < y; j++) {
            cin >> c;
            matrix[i][j] = c;
        }
    }

    // // Loop through the command-line arguments (excluding the program name)
    for (int k = 1; k < argc; k++) {
        word = argv[k];
    }


    
    //     // Loop through all positions in the matrix
    //     for (int i = 0; i < x; i++) {
    //         for (int j = 0; j < y; j++) {
    //             // Search for the word in all directions
    //             if (search(matrix, word, i, j, 0, 0, highlightMatrix) ||
    //                 search(matrix, word, i, j, 0, 1, highlightMatrix) ||
    //                 search(matrix, word, i, j, 0, -1, highlightMatrix) ||
    //                 search(matrix, word, i, j, 1, 0, highlightMatrix) ||
    //                 search(matrix, word, i, j, -1, 0, highlightMatrix) ||
    //                 search(matrix, word, i, j, 1, 1, highlightMatrix) ||
    //                 search(matrix, word, i, j, -1, -1, highlightMatrix) ||
    //                 search(matrix, word, i, j, -1, 1, highlightMatrix) ||
    //                 search(matrix, word, i, j, 1, -1, highlightMatrix)) {
    //                 // If word is found, mark the corresponding positions in the highlight matrix
    //                 record(highlightMatrix, i, j, 1);
    //             }
    //         }
    //     }
    // }

    // // Print the matrix with highlighted positions
    // printMatrix(matrix, highlightMatrix);


    printM(matrix, words);

    return 0;
}

bool search(vector<vector<char>>& matrix, const string& word, int x, int y, int dx, int dy, vector<vector<int>>& matrix2) {
    int wordLength = word.length();

    // Calculate the new position based on the direction vector (dx, dy)
    int newX = x;
    int newY = y;

    // Check if the word can fit starting from position (x, y) in the given direction (dx, dy)
    for (int i = 0; i < wordLength; i++) {
        // Check if the current position is within the bounds of the matrix
        if (newX >= 0 && newX < matrix.size() && newY >= 0 && newY < matrix[0].size()) {
            // Check if the character matches the corresponding character in the word
            if (word[i] == matrix[newX][newY]) {
                // Mark the position in matrix2 as visited
                matrix2[newX][newY] = 1;
            } else {
                // If any character does not match, return false
                return false;
            }
        } else {
            // If the position is out of bounds, return false
            return false;
        }

        // Move to the next position using the direction vector
        newX += dx;
        newY += dy;
    }

    // If the loop completes without returning false, the word is found
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

// function to check if a word matches at a given starting position and direction
bool matchWord(const vector<vector<char>>& matrix, const string& word, int i, int j, int di, int dj) {
    for (char c : word) {
        if (i < 0 || i >= matrix.size() || j < 0 || j >= matrix[0].size() || matrix[i][j] != c) {
            return false;
        }
        i += di;
        j += dj;
    }
    return true;
}



bool searchWord(const vector<vector<char>>& matrix, const string& word, int i, int j) {
    static const int dirs[][2] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}, {-1, -1}, {-1, 1}, {1, -1}, {1, 1}};
    for (const auto& dir : dirs) {
        int di = dir[0];
        int dj = dir[1];
        if (matchWord(matrix, word, i, j, di, dj)) {
            return true;
        }
    }
    return false;
}


void printM(const vector<vector<char>>& matrix, const vector<string>& words) {
    Color::Setting red(Color::FG_RED);
    Color::Setting def(Color::FG_DEFAULT);
    for (int i = 0; i < matrix.size(); i++) {
        for (int j = 0; j < matrix[0].size(); j++) {
            bool found = false;
            for (const auto& word : words) {
                if (searchWord(matrix, word, i, j)) {
                    cout << red << matrix[i][j] << def;
                    found = true;
                    break;
                }
            }
            if (!found) {
                cout << matrix[i][j];
            }
        }
        cout << endl;
    }
}