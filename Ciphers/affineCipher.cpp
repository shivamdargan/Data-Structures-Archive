//Made By: Shivam Dargan
//CSBS-1 
// 102018021
//Affine Cipher
#include <bits/stdc++.h>
using namespace std;

int modInverse(int a, int m) {
    a = a % m;
    for (int x = 1; x < m; x++) {
        if ((a * x) % m == 1) {
            return x;
        }
    }
    return -1;
}

string encryptText(string plaintext, int a, int b) {
    string ciphertext = "";
    for (char c : plaintext) {
        if (isalpha(c)) {
            c = toupper(c);
            int value = c - 'A';
            value = (a * value + b) % 26;
            ciphertext += (char)(value + 'A');
        }
    }
    return ciphertext;
}

string decryptText(string ciphertext, int a, int b) {
    string plaintext = "";
    int aInverse = modInverse(a, 26);
    for (char c : ciphertext) {
        if (isalpha(c)) {
            c = toupper(c);
            int value = c - 'A';
            value = (aInverse * (value - b + 26)) % 26;
            plaintext += (char)(value + 'A');
        }
    }
    return plaintext;
}

int main() {
    string plaintext, ciphertext;
    int a, b;
    cout << "Enter the plaintext: ";
    cin>>plaintext;
    cout << "Enter the key a (must be coprime with 26): ";
    cin >> a;
    if (a % 2 == 0 || a % 13 == 0) {
        cerr << "Error: key a must be coprime with 26.\n";
        return 1;
    }
    cout << "Enter the key b: ";
    cin >> b;
    ciphertext = encryptText(plaintext, a, b);
    cout << "Encrypted text: " << ciphertext << "\n";
    plaintext = decryptText(ciphertext, a, b);
    cout << "Decrypted text: " << plaintext << "\n";
    return 0;
}
