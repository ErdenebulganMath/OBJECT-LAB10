#include <bits/stdc++.h>
#include <ctime>
#include <cmath>
using namespace std;

// Энгийн классууд 

// ================= POINT =================
struct Point
{
    float x;
    float y;
};

// ================= SHAPE =================
class Shape
{
protected:
    Point points[100];

public:
    virtual ~Shape() {}
};

// ================= SHAPE2D =================
class Shape2D : public Shape
{
protected:
    string name;

public:
    Shape2D(string n)
    {
        name = n;
    }

    virtual float talbai() = 0;
    virtual float perimetr() = 0;

    string getName()
    {
        return name;
    }

    virtual ~Shape2D() {}
};

// ================= CIRCLE =================
class Circle : public Shape2D
{
    Point p;
    float radius;

public:
    Circle(Point p1, float r, string n) : Shape2D(n)
    {
        p = p1;
        radius = r;
    }

    float talbai() override
    {
        return 3.14f * radius * radius;
    }

    float perimetr() override
    {
        return 2 * 3.14f * radius;
    }
};

// ================= SQUARE =================
class Square : public Shape2D
{
    Point p1, p2, p3, p4;
    float a;

public:
    Square(Point topLeft, float length, string n) : Shape2D(n)
    {
        p1 = topLeft;
        a = length;

        p2 = {topLeft.x + a, topLeft.y};
        p3 = {topLeft.x + a, topLeft.y - a};
        p4 = {topLeft.x, topLeft.y - a};
    }

    float talbai() override
    {
        return a * a;
    }

    float perimetr() override
    {
        return 4 * a;
    }
};

// ================= TRIANGLE =================
class Triangle : public Shape2D
{
    Point p1, p2, p3;
    float a;

public:
    Triangle(Point top, float side, string n) : Shape2D(n)
    {
        p1 = top;
        a = side;

        float h = sqrt(3) / 2 * a;
        p2 = {top.x - a / 2, top.y - h};
        p3 = {top.x + a / 2, top.y - h};
    }

    float talbai() override{
        return (sqrt(3) / 4) * a * a;
    }

    float perimetr() override{
        return 3 * a;
    }
};

// Template class хэсэг 

template <typename T>
class GeoList {
    private :
        T *data;
        int capacity;
        int len;

    void resize()
    {
        if (len == capacity)
        {
            capacity = capacity * 2;
            T *newData = new T[capacity];

            for (int i = 0; i < len; i++)
            {
                newData[i] = data[i];
            }
            delete[] data;
            data = newData;
        }
    }

    public :
        GeoList(){
            capacity = 15;
            len = 0;
            data = new T[capacity];
        }

        ~GeoList(){
            delete[] data;
        }

        void add(T t){
            if (len == capacity){
                resize();
            }
        data[len++] = t ;
        }

    T &operator[](int i){
        return data[i];
    }

    int length(){
        return len ;
    }

    T get(int index){
        if (index >= 0 && index < len){
            return data[index];
        }

        throw out_of_range("Index out of range");
    }

    void remove(int index){
        if (index < 0 || index >= len){
            cout << "Tuhain indexiin element oldsongui" << endl;
            return;
        }

        for (int i = index ; i < len - 1 ; i++){
            data[i] = data[i + 1];
            }
        len = len - 1 ;
    }

    void insert(T t , int index){
        if(index < 0 || index > len){
            cout << "Tuhain indexiin element oldsongui" << endl;
            return;
        }

        if(len == capacity){
            resize();
        }

        for(int i=len ; i>index ; i--){
            data[i] = data[i-1] ;
        }
        data[index] = t ;
        len = len + 1 ;
    }

};

int main(){

    srand(time(0)) ;

    GeoList<Shape2D*> shapes ;

    int n = 20 + rand() % 11 ;
    
    for(int i=0 ; i<n ; i++){
        int type = rand() % 3 ; 
        float size = 1 + rand() % 10 ; 

        string name = "Shape " + to_string(i + 1) ;

        if(type == 0){
            Point p = {float(rand() % 10), float(rand() % 10)} ;
            shapes.add(new Circle(p, size, name)) ;
        }

        else if(type == 1){
            Point p = {float(rand() % 10), float(rand() % 10)} ;
            shapes.add(new Square(p, size, name)) ;
        }

        else if(type == 2){
            Point p = {float(rand() % 10), float(rand() % 10)} ;
            shapes.add(new Triangle(p, size, name)) ;
        }
    }

    // Bubble sort by area  

    for(int i = 0 ; i<shapes.length() - 1 ; i++){
        for(int j = 0 ; j<shapes.length() - i - 1 ; j++){
            if(shapes[j]->talbai() > shapes[j + 1]->talbai()){
                swap(shapes[j], shapes[j + 1]) ;
            }
        }
    }

     cout << "===== SORTED BY AREA =====\n\n";

    for (int i = 0; i < shapes.length(); i++)
    {
        cout << shapes[i]->getName() << endl;
        cout << "Area: " << shapes[i]->talbai() << endl;
        cout << "Perimeter: " << shapes[i]->perimetr() << endl;
        cout << "----------------------" << endl;
    }

    // ===== MEMORY CLEANUP =====
    for (int i = 0; i < shapes.length(); i++)
    {
        delete shapes[i];
    }

}