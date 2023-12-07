#pragma once
#include "Shape2D.h"
class Triangle : public Shape2D
{

    double base, height ,side;
public:
    Triangle()
    {
        base = 0;
        height = 0;
        side = 0;
    }
    Triangle(double base, double height , double side)
    {
        this->base = base;
        this->height = height;
    }
    void computeArea() {
        double area;
        area = (height * base) / 2;
        print("Area", area);
        this->area = area;
    }
    void computePerimeter() {
        double perimeter;
        perimeter = 3 * side;
        print("Perimeter", perimeter);
        printToFile("Perimeter", perimeter ,"Area", area);
        this->perimeter = perimeter;
    }
    void print(string x, double y)
    {
        cout << x << " of Triangle = " << y << "\n";
    }
    void printToFile(string x, double y, string x2, double y2)
    {
        ofstream ofs;
        ofs.open("shapes.dat");
        if (!ofs) {
            cout << "Error opening file" << "\n";

        }
        cout << "Shapes.dat file updated ." << "\n";
        ofs << x << " of Triangle = " << y << "\n";
        ofs << x2 << " of Triangle = " << y2 << "\n";

    }

    void readFromFile() {
        fstream file("Shapes.dat", ios::in);
        string contents((istreambuf_iterator<char>(file)), (istreambuf_iterator<char>()));
        file.close();
        cout << contents;
    }
    void readData() {
        cout << "Enter base: " << endl;
        cin >> base;
        cout << "Enter height: " << endl;
        cin >> height;
    }
    bool operator==(const Triangle& other) const {
        return this->area == other.area || this->perimeter == other.perimeter;
    }

    bool operator>(const Triangle& other) const {
        return this->area > other.area || this->perimeter > other.perimeter;
    }

    bool operator<(const Triangle& other) const {
        return this->area < other.area || this->perimeter < other.perimeter;
    }
};

