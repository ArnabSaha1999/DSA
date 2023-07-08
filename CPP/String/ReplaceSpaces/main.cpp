#include<iostream>
#include<string>
using namespace std;

// Approach 1: This function replaces spaces in the input string with the string "@40" using the replace function.
void replaceSpaces(string &str) {
    for(int i = 0; i < str.length(); i++) {
        if(str[i] == ' ') {
            str.replace(i, 1, "@40");
        }
    }
}

// Approach 2: This function replaces spaces in the input string with the string "@40" using a temporary string.
void replaceSpacesUsingTempString(string &str) {
    string temp;
    for(char s : str) {
        if(s == ' ') {
            temp += "@40";
        } else {
            temp += s;
        }
    }
    str = temp;
}

// Approach 3: This function optimizes the space usage and time complexity for replacing spaces in the input string.
void replaceSpacesOptimized(string &str) {
    int spaceCount = 0;
    for(int i = 0; i < str.length(); i++) {
        if(str[i] == ' ') {
            spaceCount++;
        }
    }

    // Calculate the new length of the string after replacing spaces.
    int newLength = str.length() + (spaceCount * 3);

    // Reserve memory in the string to accommodate the additional characters.
    str.reserve(newLength);

    // Replace spaces with "@40" in-place, shifting characters only once.
    for(int i = 0; i < str.length(); i++) {
        if(str[i] == ' ') {
            str.replace(i, 1, "@40");
            i += 3;  // Skip the replaced characters.
        }
    }
}

int main() {
    string str = "Hello World! This is a new input string.";

    cout << "The string before replacing spaces: " << endl;
    cout << str << endl;

    // Approach 1: replaceSpaces
    replaceSpaces(str);
    cout << "After replacing spaces using replaceSpaces: " << endl;
    cout << str << endl;

    // Approach 2: replaceSpacesUsingTempString
    replaceSpacesUsingTempString(str);
    cout << "After replacing spaces using replaceSpacesUsingTempString: " << endl;
    cout << str << endl;

    // Approach 3: replaceSpacesOptimized
    replaceSpacesOptimized(str);
    cout << "After replacing spaces using replaceSpacesOptimized: " << endl;
    cout << str << endl;

    return 0;
}
