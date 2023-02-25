//Made By: Shivam Dargan
//CSBS-1 
// 102018021
//Multiplicative Cipher
#include<bits/stdc++.h>
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

string encryptText(string plaintext, int key) {
    string ciphertext = "";
    for (char c : plaintext) {
        if (isalpha(c)) {
            c = toupper(c);
            int value = c - 'A';
            value = (value * key) % 26;
            ciphertext += (char)(value + 'A');
        }
    }
    return ciphertext;
}

string decryptText(string ciphertext, int key) {
    string plaintext = "";
    int keyInverse = modInverse(key, 26);
    for (char c : ciphertext) {
        if (isalpha(c)) {
            c = toupper(c);
            int value = c - 'A';
            value = (value * keyInverse) % 26;
            plaintext += (char)(value + 'A');
        }
    }
    return plaintext;
}

int main() {
    string plaintext, ciphertext;
    int key;
    cout << "Enter the plaintext: ";
    cin>>plaintext;
    cout << "Enter the key (must be coprime with 26): ";
    cin >> key;
    if (key % 2 == 0 || key % 13 == 0) {
        cerr << "Key must be coprime with 26.\n";
        return 1;
    }
    ciphertext = encryptText(plaintext, key);
    cout << "Encrypted text: " << ciphertext << endl;
    plaintext = decryptText(ciphertext, key);
    cout << "Decrypted text: " << plaintext << endl;
    return 0;
}
