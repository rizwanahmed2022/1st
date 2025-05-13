#include <iostream>
using namespace std;

void encryption(string text, int newText[], char enryptedText[], int userKey = 0);
void dencryption(string text, int newText[], char enryptedText[], int userKey = 0);




int printarray(int array[], int size);
char printarray(char array[], int size);





int main() {

    string text;
    int choise;

    cout << "Choose One Option For:\n";
    cout << "1. Encryption\n";
    cout << "2. Decryption\n";
    cin >> choise;

    cout << "Enter Your Text: ";
    cin.ignore(); // Clear the input buffer
    getline(cin, text);

    int newtext[text.length()] = {};
    char encryptedText[text.length()] = {};


    if(choise == 1) {
        cout << "Enter Your Key: ";
        int key;
        cin >> key;
        encryption(text, newtext, encryptedText, key);
    } else {
        cout << "Enter Your Key: ";
        int key;
        cin >> key;
        dencryption(text, newtext, encryptedText, key);
    }




    cout << "ASCII Codes: ";
    printarray(newtext, text.length());

    cout << "Converted Text:  ";
    printarray(encryptedText, text.length());

    return 0;

}




void encryption(string text, int newText[], char enryptedText[], int userKey) {
    // Convert each character to its ASCII value
    for(size_t i = 0; i < text.length(); i++) {
        newText[i] = text[i];
    }

    

    // Encrypt the text by adding the userKey to each ASCII value
    for(size_t i = 0; i < text.length(); i++) {
        if(newText[i] == 32) {
            newText[i] = newText[i];
        } else {
            newText[i] = newText[i] - 97;
            newText[i] = (newText[i] + userKey) % 26;
            newText[i] = newText[i] + 97;
        }
        // Convert the encrypted ASCII value back to a character
        enryptedText[i] = newText[i];
    }


}

void dencryption(string text, int newText[], char encryptedText[], int userKey) {
    // Convert each character to its ASCII value
    for(size_t i = 0; i < text.length(); i++) {
        newText[i] = text[i];
    }

    // Decrypt the text by subtracting the userKey from each ASCII value
    for(size_t i = 0; i < text.length(); i++) {
        if(newText[i] == 32) {
            newText[i] = newText[i];
        } else {
            newText[i] = newText[i] - 97;
            newText[i] = (newText[i] - userKey + 26) % 26;
            newText[i] = newText[i] + 97;
        }
        // Convert the encrypted ASCII value back to a character
        encryptedText[i] = newText[i];
    }


}





int printarray(int array[], int size) {
    for(int i = 0; i < size; i++) {
        cout << array[i];
    }
    cout << endl;
    return 0;
};

char printarray(char array[], int size) {
    for(int i = 0; i < size; i++) {
        cout << array[i];
    }
    cout << endl;
    return 0;
};
