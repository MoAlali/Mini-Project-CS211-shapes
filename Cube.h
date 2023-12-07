#pragma once
#include "Shape3D.h"
#include<iostream>
#include<fstream>
using namespace std;

class Cube :  public Shape3D
{

    double side;
public:
    Cube()
    {
        side = 0;
    }
    Cube(double side)
    {
        this->side;
    }
    void computeSurfaceArea() {
        double area;
        area = 6 * side * side;
        print("Surface Area", area);
        this->surfaceArea = area;
    }
    void computeVolume() {
        double volume;
        volume = side * side * side;
        print("Volume", volume);
        printToFile("Volume", volume , "Surface Area", surfaceArea);
        this->volume = volume;
    }
    void print(string x, double y)
    {
        cout << x << " of Cube = " << y << "\n";
    }
    void printToFile(string x, double y , string x2, double y2)
    {
        ofstream ofs;
        ofs.open("shapes.dat");
        if (!ofs) {
            cout << "Error opening file" << endl;

        }
        cout << "Shapes.dat file updated ." << "\n";
        ofs << x << " of Cube = " << y << "\n";
        ofs << x2 << " of Cube = " << y2 << "\n";

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
    bool operator==(const Cube& other) const {
        return this->surfaceArea == other.surfaceArea || this->volume == other.volume;
    }

    bool operator>(const Cube& other) const {
        return this->surfaceArea > other.surfaceArea || this->volume > other.volume;
    }

    bool operator<(const Cube& other) const {
        return this->surfaceArea < other.surfaceArea || this->volume < other.volume;
    }
};

