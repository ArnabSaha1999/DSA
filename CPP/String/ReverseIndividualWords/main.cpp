#include<iostream>
#include<stack>
#include<string>
#include<vector>

using namespace std;

//Approach 1: Reverses the words in the input string using a vector
string reverseWordsUsingVector(string &str) {
    vector<string> wordsArray;
    string word;
    // Iterate through each character in the string
    for (char s : str) { // If it's not a period, add the character to the word
        if (s != '.') { 
            word = s + word;
        } else { // If it's a period, add the word and a period to the array, and clear the word for the next word
            wordsArray.push_back(word);
            wordsArray.push_back(".");
            word.clear();
        }
    }
    
    if (!word.empty()) {  // If there's a word remaining after iterating through the string, add it to the array
        wordsArray.push_back(word);
        word.clear();
    }
    
    string reversedString; // String to store the reversed words
    // Append the words in the array to the reversed string in reverse order
    for (int i = 0; i < wordsArray.size(); i++) {
        reversedString += wordsArray[i];
    }

    return reversedString;
}

//Approach 2: Reverses the words in the input string using a stack
string reverseWordsUsingStack(string &str) {
    stack<string> wordStack;
    string word;
    // Iterate through each character in the string
    for (char s : str) {
        if (s != '.') { // If it's not a period, add the character to the word
            word = s + word;
        } else { // If it's a period, push the word and a period onto the stack, and clear the word for the next word
            wordStack.push(word);
            wordStack.push(".");
            word.clear();
        }
    }
    
    if (!word.empty()) { // If there's a word remaining after iterating through the string, push it onto the stack
        wordStack.push(word);
        word.clear();
    }
    
    string reversedString; // String to store the reversed words
    // Pop words from the stack and append them to the reversed string
    while (!wordStack.empty()) {
        reversedString = wordStack.top() + reversedString;
        wordStack.pop();
    }
    
    return reversedString;
}

//Approach 3: Reverses the words in the input string using another string
string reverseWords(string &str) {
    string reversedString;
    string word;

    int i = 0;

    while (i < str.length()) {
        while(i < str.length() && str[i] != '.') { // Build the current word
            if(str[i] != '.') {
                word = str[i++] + word;
            } 
        }
        while(i < str.length() && str[i] == '.') { // Add periods to the word
            word += "."; 
            i++;
        }
        reversedString += word; // Append the reversed word to the result string
        word.erase(); // Clear the word for the next iteration
    }

    return reversedString;
}

int main() {
    string str = "This.program.is.to...reverse..words.of.the.given.string";
    cout<<"The given string: '"<<str<<"'"<<endl;
    cout<<"The string after reversing words using vector: '"<< reverseWordsUsingVector(str)<<"'"<<endl;
    cout<<"The string after reversing words using stack: '"<<reverseWordsUsingStack(str)<<"'"<<endl;
    cout<<"The string after reversing words using another string: '"<<reverseWords(str)<<"'"<<endl;
    return 0;
}
