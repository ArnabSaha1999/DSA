#include<iostream>
#include<unordered_map>

using namespace std;

void printUnorderedMap(unordered_map<string, int> &ages) {
    for(unordered_map<string, int>::iterator it = ages.begin(); it != ages.end(); it++) {
        cout<<(*it).first<<" : "<<(*it).second<<endl;
    } cout<<endl;
}

int main() {
    unordered_map<string, int> ages;

    if(ages.empty()) {
        cout<<"The Unordered Map is Empty"<<endl;
    }
    // Insertion
    ages["Alice"] = 30;
    ages.insert(make_pair("Bob", 25));
    ages.insert(pair<string, int>("Charlie", 40));
    ages.insert({"Steve", 24});
    ages.emplace("Dave", 35);

    cout<<"Printing the Unordered Map Elements: "<<endl;
    printUnorderedMap(ages);
    cout<<"Size of Unordered map: "<<ages.size()<<endl;

    // Accessing elements
    cout<<"Bob's age: "<<ages["Bob"]<<endl;
    cout<<"Steve's age: "<<ages.at("Steve")<<endl;

    // Checking if key exists
    if(ages.count("Eve") == 0) {
        cout<<"Eve not found in the Unordered map."<<endl;
    }

    for(auto &element : ages) {
        element.second++;
    }
    cout<<"Printing Unordered Map elements after incrementing the Unordered Map elements value: "<<endl;
    printUnorderedMap(ages);
    // Deleting element
    ages.erase("Charlie");
    cout<<"Printing Unordered Map elements after erasing 'Charlie':"<<endl;
    printUnorderedMap(ages);

    // Size of the map
    cout<<"Size of Unordered map: "<<ages.size()<<endl;

    //Find an element in Map and print from that element.
    string target = "Steve";
    cout<<"Search "<<target<<" and print from that element till the end: "<<endl;
    unordered_map<string, int>::iterator it = ages.find(target);
    for(; it != ages.end(); it++) {
        cout<<(*it).first<<" : "<<(*it).second<<endl;
    }

    // Clearing the map
    ages.clear();

    return 0;
}
