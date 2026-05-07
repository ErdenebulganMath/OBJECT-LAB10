#include <vector>
#include <iostream>
using namespace std;
int main()
{
    Circle c1, c2, c3;
    Triangle t1, t2, t3;
    Square s1, s2, s3;

    vector<Shape2D> list_of_shapes; // Create new list

    list_of_shapes.push_back(c1); // Insert item circle
    list_of_shapes.push_back(c2); // Insert item circle
    list_of_shapes.push_back(c3); // Insert item circle

    list_of_shapes.push_back(t1); // Insert item triangle
    list_of_shapes.push_back(t2); // Insert item triangle
    list_of_shapes.push_back(t3); // Insert item triangle

    list_of_shapes.push_back(s1); // Insert item square
    list_of_shapes.push_back(s2); // Insert item square
    list_of_shapes.push_back(s3); // Insert item square

    cout << list_of_shapes.size() << endl;     // How many?
    cout << list_of_shapes[1].print() << endl; // Get item number 1 and calls member function
    return 0;
}