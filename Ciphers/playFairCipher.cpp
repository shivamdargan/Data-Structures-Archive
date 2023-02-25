//Made By: Shivam Dargan
//CSBS-1 
// 102018021
//Playfair Cipher
#include <bits/stdc++.h>
using namespace std;

const int SIZE = 5;  // size of the Playfair matrix


void generate_matrix(char key[], char matrix[][SIZE]) {
    bool used[26] = {false};
    int i = 0, j = 0;

    // fill in the key
    for (int k = 0; key[k] != '\0'; k++) {
        if (!used[toupper(key[k]) - 'A'] && key[k] != 'J') {
            matrix[i][j] = toupper(key[k]);
            used[matrix[i][j] - 'A'] = true;
            j++;
            if (j == SIZE) {
                i++;
                j = 0;
            }
        }
    }

    // fill in the remaining letters
    for (int k = 0; k < 26; k++) {
        if (!used[k] && k != ('J' - 'A')) {
            matrix[i][j] = k + 'A';
            j++;
            if (j == SIZE) {
                i++;
                j = 0;
            }
        }
    }
}

// function to find the row and column of a given letter in the Playfair matrix
void find_position(char letter, char matrix[][SIZE], int& row, int& col) {
    if (letter == 'J') {
        letter = 'I';
    }
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            if (matrix[i][j] == letter) {
                row = i;
                col = j;
                return;
            }
        }
    }
}

string encryptText(string plaintext, char matrix[][SIZE]) {
    string ciphertext = "";
    int pt_len = plaintext.length();
    char pt[pt_len];
    int i = 0;

    // remove any non-letter characters and convert to uppercase
    for (int j = 0; j < pt_len; j++) {
        if (isalpha(plaintext[j])) {
            pt[i] = toupper(plaintext[j]);
            i++;
        }
    }

    // add a padding 'Z' if the plaintext length is odd
    if (i % 2 == 1) {
        pt[i] = 'Z';
        i++;
    }

    // encrypt the plaintext in pairs of letters
    for (int j = 0; j < i; j += 2) {
        int row1, col1, row2, col2;
        find_position(pt[j], matrix, row1, col1);
        find_position(pt[j + 1], matrix, row2, col2);
        if (row1 == row2) {  // same row
            ciphertext += matrix[row1][(col1 + 1) % SIZE];
            ciphertext += matrix[row2][(col2 + 1) % SIZE];
        } else if (col1 == col2) {  // same column
            ciphertext += matrix[(row1 + 1) % SIZE][col1];
            ciphertext += matrix[(row2 + 1) % SIZE][col2];
        } else {  // different row and column
            ciphertext += matrix[row1][col2];
            ciphertext += matrix[row2][col1];
        }
    }

    return ciphertext;
}

string decryptText(string ciphertext, char matrix[][SIZE]) {
    string plaintext = "";
    int ct_len = ciphertext.length();
    char ct[ct_len];
    int i = 0;

    // remove any non-letter characters and convert to uppercase
    for (int j = 0; j < ct_len; j++) {
        if (isalpha(ciphertext[j])) {
            ct[i] = toupper(ciphertext[j]);
            i++;
        }
    }

    // decrypt the ciphertext in pairs of letters
    for (int j = 0; j < i; j += 2) {
        int row1, col1, row2, col2;
        find_position(ct[j], matrix, row1, col1);
        find_position(ct[j + 1], matrix, row2, col2);
        if (row1 == row2) {  // same row
            plaintext += matrix[row1][(col1 + SIZE - 1) % SIZE];
            plaintext += matrix[row2][(col2 + SIZE - 1) % SIZE];
        } else if (col1 == col2) {  // same column
            plaintext += matrix[(row1 + SIZE - 1) % SIZE][col1];
            plaintext += matrix[(row2 + SIZE - 1) % SIZE][col2];
        } else {  // different row and column
            plaintext += matrix[row1][col2];
            plaintext += matrix[row2][col1];
        }
    }

    return plaintext;
}

int main() {
    char key[100], matrix[SIZE][SIZE];
    string ciphertext;
    string plaintext;
    cout << "Enter the key: ";
    cin>>key;
    cout<<"Enter Plain Text"<<endl;
    cin>>plaintext;
    generate_matrix(key, matrix);

    ciphertext = encryptText(plaintext,matrix);
    cout<<"Ciphertext: "<<ciphertext<<endl;
    // decrypt the ciphertext using the Playfair cipher
    string finalText = decryptText(ciphertext, matrix);

    // print the plaintext
    cout << "Plaintext: " << finalText << endl;

    return 0;
}

