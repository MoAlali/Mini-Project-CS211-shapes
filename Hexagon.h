#pragma once
#include "Shape2D.h"
#include<iostream>
using namespace std;
#include<fstream>
class Hexagon :    public Shape2D
{
    double side;
public:
    Hexagon()
    {
        side = 0;
    }
    Hexagon(double side)
    {
        this->side = side;
    }
    void computeArea() {
        double area;
        area = 3 * sqrt(3) * side * side / 2;
        print("Area", area);
        
        this->area = area;
    }
    void computePerimeter() {
        double perimeter;
        perimeter = 6 * side;
        print("Perimeter", perimeter);
        printToFile("Perimeter", perimeter ,"Area", area);
        this->perimeter = perimeter;
    }
    void print(string x, double y )
    {
        cout << x << " of Hexagon = " << y << "\n";
    }
    void printToFile(string x, double y, string x2, double y2)
    {
        ofstream ofs;
        ofs.open("shapes.dat");
        if (!ofs) {
            cout << "Error opening file" << endl;

        }
        cout << "Shapes.dat file updated ." << "\n";
        ofs << x << " of Hexagon = " << y << "\n";
        ofs << x2 << " of Hexagon = " << y2 << "\n";

    }
    void readFromFile() {
        fstream file("Shapes.dat", ios::in);
        string contents((istreambuf_iterator<char>(file)), (istreambuf_iterator<char>()));
        file.close();
        cout << contents;
    }
    void readData() {
        cout << "Enter side: " << endl;
        cin >> side;
    }
    bool operator==(const Hexagon& other) const {
        return this->area == other.area || this->perimeter == other.perimeter;
    }

    bool operator>(const Hexagon& other) const {
        return this->area > other.area || this->perimeter > other.perimeter;
    }

    bool operator<(const Hexagon& other) const {
        return this->area < other.area || this->perimeter < other.perimeter;
    }

};

