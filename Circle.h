#pragma once
#include "Shape2D.h"
#include<fstream>
class Circle :  public Shape2D
{
    double radius;
public:
    Circle()
    {
        radius = 0;
    }
    Circle(double radius)
    {
        this->radius = radius;
    }
     void computeArea()
    {
        double area;
        area = 3.14 * radius * radius;
        print("Area", area);
        
        this->area = area;

    }
     void computePerimeter() {
        double perimeter;
        perimeter = 2 * 3.14 * radius;
        print("Perimeter", perimeter);
        printToFile("Perimeter", perimeter , "Area" ,area);
        this->perimeter = perimeter;

    }
     void print(string x, double y)
    {
        cout << x << " of Circle = " << y << "\n";
    }
     void  printToFile(string x, double y , string x2 , double y2){
        ofstream ofs;
        ofs.open("shapes.dat");
        if (!ofs) {
            cout << "Error opening file" << endl;

        }
        cout << "Shapes.dat file updated ." << "\n";
        ofs << x << " of Circle = " << y << "\n";
        ofs << x2 << " of Circle = " << y2 << "\n";

    }
     void readFromFile() {
         fstream file("Shapes.dat", ios::in);
         string contents((istreambuf_iterator<char>(file)), (istreambuf_iterator<char>()));
         file.close();
         cout << contents;
    }
     void readData() {
        cout << "Enter radius: " << endl;
        cin >> radius;
    }
    bool operator==(const Circle& other) const {
        return this->area == other.area || this->perimeter == other.perimeter;
    }

    bool operator>(const Circle& other) const {
        return this->area > other.area || this->perimeter > other.perimeter;
    }

    bool operator<(const Circle& other) const {
        return this->area < other.area || this->perimeter < other.perimeter;
    }

};

