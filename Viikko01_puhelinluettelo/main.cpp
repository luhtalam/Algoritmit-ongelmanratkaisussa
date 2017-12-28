

#include <cstdlib>
#include <iostream>
#include <algorithm>
#include <vector>
#include <string>

using namespace std;

struct Person {
    string lastName;
    string firstName;
    string number;
};

/*
 * 
 */
bool myCompare(const Person &p1, const Person &p2) {
    if(p1.lastName.compare(p2.lastName) == 0) {
        return p1.firstName < p2.firstName;
    }
    return p1.lastName < p2.lastName;
}

int main(int argc, char** argv) {

    int n;
    cin >> n;
    Person list[100];
    for (int i = 0; i < n; i++) {
        cin >> list[i].firstName >> list[i].lastName >> list[i].number;
    }
    sort(list, list + n, myCompare);
    for (int i = 0; i < n; i++) {
        cout << list[i].firstName << " " << list[i].lastName << " " << list[i].number << endl;
    }
    return 0;
}

