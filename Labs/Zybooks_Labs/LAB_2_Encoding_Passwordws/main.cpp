#include <iostream>
#include <cstring>
using namespace std;

void encodePassword(char* password, int key) {
    int size = strlen(password);

    // Define a string containing all lowercase consonants
    char consonants[] = "bcdfghjklmnpqrstvwxyz";

    // Calculate the effective key within the range of 0 to 25
    key %= 26;

    // Iterate over each character in the password
    for (int i = 0; i < size; i++) {
        char c = password[i];

        // Check if the character is a consonant
        bool isConsonant = false;
        for (int j = 0; j < 21; j++) { // 21 is the length of consonants
            if (consonants[j] == c) {
                isConsonant = true;
                break;
            }
        }
        if (isConsonant) {
            // Increase the character by the key
            c += key;
            // If the character exceeds 'z', wrap it around
            if (c > 'z') {
                c -= 26;
            }
            password[i] = c;
        }
    }

    // Reverse the encoded password
    for (int i = 0; i < size / 2; i++) {
        swap(password[i], password[size - i - 1]);
    }
}

int main() {
    char password[50];
    int key;

    // Input password and key
    cin >> password;
    cin >> key;

    // Encode the password
    encodePassword(password, key);

    // Output the encoded password
    cout << password;

    return 0;
}