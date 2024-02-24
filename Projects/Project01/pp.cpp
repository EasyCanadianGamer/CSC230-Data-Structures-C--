
#include "colormod.h"
#include <iostream>
#include <vector>

using namespace std;

typedef vector<vector<char>> Matrix;

// function to check if a word matches at a given starting position and direction
bool matchWord(const Matrix& matrix, const string& word, int i, int j, int di, int dj) {
    for (char c : word) {
        if (i < 0 || i >= matrix.size() || j < 0 || j >= matrix[0].size() || matrix[i][j] != c) {
            return false;
        }
        i += di;
        j += dj;
    }
    return true;
}

// function to search for a word in all directions starting from a given position
bool searchWord(const Matrix& matrix, const string& word, int i, int j) {
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

// function to print the matrix with highlighted words
void printMatrix(const Matrix& matrix, const vector<string>& words) {
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

int main(int argc, char* argv[]) {
    if (argc < 3) {
        cerr << "Usage: " << argv[0] << " word1 word2 ... < matrix_file" << endl;
        return 1;
    }
    vector<string> words(argv + 1, argv + argc);
    Matrix matrix;
    int rows, cols;
    cin >> rows >> cols;
    matrix.resize(rows, vector<char>(cols));
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            cin >> matrix[i][j];
        }
    }
    printMatrix(matrix, words);
   return 0;
}