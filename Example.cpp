#include <vector>
#include <iostream>
#include <string>
using namespace std;

int main()
{
    vector<int> list_of_ints;  // Create new list
    list_of_ints.push_back(3); // Insert item
    list_of_ints.push_back(23);
    cout << list_of_ints.size() << endl; // How many?
    cout << list_of_ints[1] << endl;     // Get item number 1
    cout << list_of_ints[0] << endl;     // Get item number 0
    return 0;
}
