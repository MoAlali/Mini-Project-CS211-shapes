#pragma once
#include "Shape2D.h"

class Square : public Shape2D
{
    double side;

public:
    Square()
    {
        side = 0;
    }
    Square(double side)
    {
        this->side == side;
    }
    void computeArea()
    {
        double area;
        area = side * side;
        print("Area", area);
        
        this->area = area;
    }
    void computePerimeter() {
        double perimeter;
        perimeter = 4 * side;
        print("Perimeter", perimeter);
        printToFile("Perimeter", perimeter ,"Area", area);
        this->perimeter = perimeter;
    }
    void print(string x, double y)
    {
        cout << x << " of Square = " << y << "\n";
    }
    void printToFile(string x, double y, string x2, double y2)
    {
        ofstream ofs;
        ofs.open("shapes.dat");
        if (!ofs) {
            cout << "Error opening file" << "\n";

        }
        cout << "Shapes.dat file updated ." << "\n";
        ofs << x << " of Square = " << y << "\n";
        ofs << x2 << " of Square = " << y2 << "\n";
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
    bool operator==(const Square& other) const {
        return this->area == other.area || this->perimeter == other.perimeter;
    }

    bool operator>(const Square& other) const {
        return this->area > other.area || this->perimeter > other.perimeter;
    }

    bool operator<(const Square& other) const {
        return this->area < other.area || this->perimeter < other.perimeter;
    }
};

