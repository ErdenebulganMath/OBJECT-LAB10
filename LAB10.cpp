#include <bits/stdc++.h>
using namespace std;

// ================= POINT =================
struct Point {
    float x;
    float y;
};

// ================= SHAPE =================
class Shape {
protected:
    Point points[100];

public:
    virtual ~Shape() {}
};

// ================= SHAPE2D =================
class Shape2D : public Shape {
protected:
    string name;

public:
    Shape2D(string n) {
        name = n;
    }

    virtual float talbai() = 0;
    virtual float perimetr() = 0;

    string getName() {
        return name;
    }

    virtual ~Shape2D() {}
};

// ================= CIRCLE =================
class Circle : public Shape2D {
    Point p;
    float radius;

public:
    Circle(Point p1, float r, string n) : Shape2D(n) {
        p = p1;
        radius = r;
    }

    float talbai() override {
        return 3.14f * radius * radius;
    }

    float perimetr() override {
        return 2 * 3.14f * radius;
    }
};

// ================= SQUARE =================
class Square : public Shape2D {
    Point p1, p2, p3, p4;
    float a;

public:
    Square(Point topLeft, float length, string n) : Shape2D(n) {
        p1 = topLeft;
        a = length;

        p2 = {topLeft.x + a, topLeft.y};
        p3 = {topLeft.x + a, topLeft.y - a};
        p4 = {topLeft.x, topLeft.y - a};
    }

    float talbai() override {
        return a * a;
    }

    float perimetr() override {
        return 4 * a;
    }
};

// ================= TRIANGLE =================
class Triangle : public Shape2D {
    Point p1, p2, p3;
    float a;

public:
    Triangle(Point top, float side, string n) : Shape2D(n) {
        p1 = top;
        a = side;

        float h = sqrt(3) / 2 * a;
        p2 = {top.x - a / 2, top.y - h};
        p3 = {top.x + a / 2, top.y - h};
    }

    float talbai() override {
        return (sqrt(3) / 4) * a * a;
    }

    float perimetr() override {
        return 3 * a;
    }
};

// ================= TEMPLATE LIST =================
template <typename T>
class MyList {
private:
    T *data;
    int cap;
    int len;

    void resize() {
        cap *= 2;
        T *newData = new T[cap];

        for (int i = 0; i < len; i++)
            newData[i] = data[i];

        delete[] data;
        data = newData;
    }

public:
    MyList() {
        cap = 10;
        len = 0;
        data = new T[cap];
    }

    void add(T t) {
        if (len == cap) resize();
        data[len++] = t;
    }

    T& operator[](int i) {
        return data[i];
    }

    int length() {
        return len;
    }
};

// ================= MAIN =================
int main() {

    MyList<Shape2D*> shapes;

    // ===== RANDOM OBJECTS (20-30 орчим биш demo) =====
    shapes.add(new Circle({0,0}, 5, "Circle1"));
    shapes.add(new Square({0,10}, 4, "Square1"));
    shapes.add(new Triangle({0,10}, 6, "Triangle1"));
    shapes.add(new Circle({1,1}, 3, "Circle2"));
    shapes.add(new Square({2,8}, 2, "Square2"));
    shapes.add(new Triangle({2,5}, 4, "Triangle2"));

    // ===== SORT (bubble sort by area) =====
    for (int i = 0; i < shapes.length(); i++) {
        for (int j = 0; j < shapes.length() - i - 1; j++) {
            if (shapes[j]->talbai() > shapes[j + 1]->talbai()) {
                swap(shapes[j], shapes[j + 1]);
            }
        }
    }

    // ===== OUTPUT =====
    cout << "=== Sorted by Area ===\n\n";

    for (int i = 0; i < shapes.length(); i++) {
        cout << shapes[i]->getName() << endl;
        cout << "Area: " << shapes[i]->talbai() << endl;
        cout << "Perimeter: " << shapes[i]->perimetr() << endl;
        cout << "----------------------" << endl;
    }

    // ===== MEMORY CLEANUP =====
    for (int i = 0; i < shapes.length(); i++) {
        delete shapes[i];
    }

    return 0;
}