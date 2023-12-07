#pragma once
#include "Shape3D.h"
#include<iostream>
using namespace std;
#include<fstream>

class Cone :    public Shape3D
{

    double radius, height;
public:
    Cone()
    {
        radius = 0;
        height = 0;
    }
    Cone(double radius, double height)
    {
        this->radius = radius;
        this->height = height;
    }
    void computeSurfaceArea() {
        double area;
        area = 3.14 * radius * (radius + sqrt(radius * radius + height * height));
        print("Surface Area", area);
 
        this->surfaceArea = area;
    }
    void computeVolume() {
        double volume;
        volume = (3.14 * radius * radius * height) / 3;
        print("Volume", volume);
        printToFile("Volume", volume , "Surface Area", surfaceArea);
        this->volume = volume;
    }
    void print(string x, double y)
    {
        cout << x << " of Cone = " << y << "\n";
    }
    void printToFile(string x, double y, string x2, double y2)
    {
        ofstream ofs;
        ofs.open("shapes.dat");
        if (!ofs) {
            cout << "Error opening file" << endl;

        }
        cout << "Shapes.dat file updated ." << "\n";
        ofs << x << " of Cone = " << y << "\n";
        ofs << x2 << " of Cone = " << y2 << "\n";

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
        cout << "Enter height: " << endl;
        cin >> height;
    }
    bool operator==(const Cone& other) const {
        return this->surfaceArea == other.surfaceArea || this->volume == other.volume;
    }

    bool operator>(const Cone& other) const {
        return this->surfaceArea > other.surfaceArea || this->volume > other.volume;
    }

    bool operator<(const Cone& other) const {
        return this->surfaceArea < other.surfaceArea || this->volume < other.volume;
    }


};

