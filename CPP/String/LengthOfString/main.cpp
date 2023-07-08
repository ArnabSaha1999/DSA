#include<iostream>
#include<cstring>

using namespace std;

//Approach 1: Function to calculate the length of a C-style string
int getLength(char name[]) {
    int count = 0;
    // Iterate through the string until the null character is encountered
    for(int i = 0; name[i] != '\0'; i++) {
        count++;
    } 
    return count;
}

//Approach 2: Function to calculate the length of a C-style string using strlen function
int getLengthStrLen(char name[]) {
    return strlen(name);
}

int main() {
    char name[20];
    cout<<"Enter your full name: "<<endl;
    cin.getline(name, 20);
    cout<<"Your name is : "<<name<<endl;
    cout<<"The Length of your name: "<< getLength(name)<<endl;
    cout<<"The Length of your name: "<<getLengthStrLen(name)<<endl;
    return 0;
}
