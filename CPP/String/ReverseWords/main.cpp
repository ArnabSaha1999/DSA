#include<iostream>
#include<stack>
#include<string>
#include<vector>

using namespace std;

//Approach 1: Reverses the words in the input string using a vector
string reverseWordsUsingVector(string &str) {
    vector<string> wordsArray;
    string word;
    // Extract words from the input string
    for(char s : str) {
        if(s != ' ') {
            word += s; // Build the word character by character
        } else {
            if(!word.empty()) {
                wordsArray.push_back(word); // Add the word to the vector
                word.clear(); // Clear the word for the next word
            }
        }
    }
    if(!word.empty()) {
        wordsArray.push_back(word); // Add the last word to the vector
        word.clear();
    }

    string reversedString;
    // Build the reversed string by appending words in reverse order
    for(int i = wordsArray.size() - 1; i >= 0; i--) {
        reversedString += wordsArray[i]; // Append each word in reverse order
        reversedString += ' '; // Add a space between words
    }
    reversedString.pop_back(); // Remove trailing space
    return reversedString;
}

//Approach 2: Reverses the words in the input string using a stack
string reverseWordsUsingStack(string &str) {
    stack<string> wordStack;
    string word;
    // Extract words from the input string
    for(char s : str) {
        if(s != ' ') {
            word += s; // Build the word character by character
        } else {
            if(!word.empty()) {
                wordStack.push(word); // Push the word onto the stack
                word.clear(); // Clear the word for the next word
            }
        }
    }
    if(!word.empty()) {
        wordStack.push(word); // Push the last word onto the stack
        word.clear();
    }
    string reversedString;
    // Build the reversed string by popping words from the stack
    while(!wordStack.empty()) {
        reversedString += wordStack.top(); // Append the top word from the stack
        wordStack.pop(); // Pop the word from the stack
        reversedString += ' '; // Add a space between words
    }
    reversedString.pop_back(); // Remove trailing space
    return reversedString;
}

//Approach 3: Reverses the words in the input string using another string
string reverseWords(string &str) {
    string reversedString;
    string word;

    int i = str.length() - 1;
    // Traverse the input string from right to left
    while (i >= 0) {
        while (i >= 0 && str[i] == ' ') {
            // Skip any trailing spaces
            i--;
        }

        if (i < 0) {
            break;  // Reached the beginning of the input string
        }

        if (!reversedString.empty()) {
            reversedString += ' ';
        }

        word.clear();
        while (i >= 0 && str[i] != ' ') {
            // Build the current word
            word = str[i] + word;
            i--;
        }

        reversedString += word;
    }

    return reversedString;
}

int main() {
    string str = " Hello  World   ";
    cout<<"The given string: '"<<str<<"'"<<endl;
    cout<<"The string after reversing words using vector: '"<< reverseWordsUsingVector(str)<<"'"<<endl;
    cout<<"The string after reversing words using stack: '"<<reverseWordsUsingStack(str)<<"'"<<endl;
    cout<<"The string after reversing words using another string: '"<<reverseWords(str)<<"'"<<endl;
    return 0;
}
