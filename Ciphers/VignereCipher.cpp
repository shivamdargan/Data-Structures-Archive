//Made By: Shivam Dargan
//CSBS-1 
// 102018021
//Vignere Cipher
#include <bits/stdc++.h>
using namespace std;

string encryptText(string plainText, string key)
{
    string cipherText = plainText;
    int keyIndex = 0;
    transform(plainText.begin(), plainText.end(), cipherText.begin(),
              [&key, &keyIndex](char c) {
                  if (!isalpha(c))
                      return c;
                  int offset = isupper(c) ? 'A' : 'a';
                  int keyChar = tolower(key[keyIndex]) - 'a';
                  int cipherChar = (c + keyChar - offset) % 26 + offset;
                  keyIndex = (keyIndex + 1) % key.length();
                  return (char)cipherChar;
              });
    return cipherText;
}

string decryptText(string cipherText, string key)
{
    string plainText = cipherText;
    int keyIndex = 0;
    transform(cipherText.begin(), cipherText.end(), plainText.begin(),
              [&key, &keyIndex](char c) {
                  if (!isalpha(c))
                      return c;
                  int offset = isupper(c) ? 'A' : 'a';
                  int keyChar = tolower(key[keyIndex]) - 'a';
                  int plainChar = (c - keyChar - offset + 26) % 26 + offset;
                  keyIndex = (keyIndex + 1) % key.length();
                  return (char)plainChar;
              });
    return plainText;
}

int main()
{
    string plainText, key, cipherText;

    cout << "Enter the plaintext: ";
    cin>>plainText;

    cout << "Enter the key: ";
    cin>>key;

    cipherText = encryptText(plainText, key);
    cout << "Encrypted Text: " << cipherText << endl;

    cout << "Decrypted Text: " << decryptText(cipherText, key) << endl;

    return 0;
}


