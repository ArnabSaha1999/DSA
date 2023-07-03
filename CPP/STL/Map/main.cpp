#include<iostream>
#include<map>

using namespace std;

void printMap(map<string, int> &ages) {
    for(map<string, int>::iterator it = ages.begin(); it != ages.end(); it++) {
        cout<<(*it).first <<" : "<<(*it).second<<endl;
    } cout<<endl;
}

void printMapReverse(map<string, int> &ages) {
    for(map<string, int>::reverse_iterator itr = ages.rbegin(); itr != ages.rend(); itr++) {
        cout<<(*itr).first<<" : "<<(*itr).second<<endl;
    } cout<<endl;
}

int main() {
    map<string, int> ages;

    if(ages.empty()) {
        cout<<"The Map is Empty"<<endl;
    }
    // Insertion
    ages["Alice"] = 30;
    ages.insert(make_pair("Bob", 25));
    ages.insert(pair<string, int>("Charlie", 40));
    ages.insert({"Steve", 24});
    ages.emplace("Dave", 35);

    cout<<"Printing the Map Elements: "<<endl;
    printMap(ages);
    cout<<"Print the Map Elements in Reverse order: "<<endl;
    printMapReverse(ages);
    cout<<"Size of map: "<<ages.size()<<endl;

    // Accessing elements
    cout<<"Bob's age: "<<ages["Bob"]<<endl;
    cout<<"Alice's age: "<<ages.at("Alice")<<endl;

    // Checking if key exists
    if(ages.count("Eve") == 0) {
        cout<<"Eve not found in the map."<<endl;
    }

    for(auto &element : ages) {
        element.second++;
    }
    cout<<"Printing Map elements after incrementing the Map elements value: "<<endl;
    printMap(ages);
    // Deleting element
    ages.erase("Charlie");
    cout<<"Printing Map elements after erasing 'Charlie':"<<endl;
    printMap(ages);

    // Size of the map
    cout<<"Size of map: "<<ages.size()<<endl;

    //Find an element in Map and print from that element.
    string target = "Dave";
    cout<<"Search "<<target<<" and print from that element till the end: "<<endl;
    map<string, int>::iterator it = ages.find(target);
    for(; it != ages.end(); it++) {
        cout<<(*it).first<<" : "<<(*it).second<<endl;
    }

    // Clearing the map
    ages.clear();

    return 0;
}
