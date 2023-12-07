#pragma once
#include "Shape3D.h"
#include<iostream>
using namespace std;
#include<fstream>
class Cylinder :  public Shape3D
{
    double redius, height;

public:
    Cylinder()
    {
        redius = 0;
        height = 0;

    }
    Cylinder(double redius, double height)
    {
        this->redius = redius;
        this->height = height;
    }
    void computeSurfaceArea() {
        double area;
        area = (2 * 3.14 * redius) * (redius + height);
        print("Surface Area", area);
        this->surfaceArea = area;
    }
    void computeVolume() {
        double volume;
        volume = 3.14 * redius * redius * height;
        print("Volume", volume);
        printToFile("Volume", volume , "Surface Area", surfaceArea);
        this->volume = volume;
    }
    void print(string x, double y)
    {
        cout << x << " of Cylinder = " << y << "\n";
    }
    void printToFile(string x, double y, string x2, double y2)
    {
        ofstream ofs;
        ofs.open("shapes.dat");
        if (!ofs) {
            cout << "Error opening file" << endl;

        }
        cout << "Shapes.dat file updated ." << "\n";
        ofs << x << " of Cylinder = " << y << "\n";
        ofs << x2 << " of Cylinder = " << y2 << "\n";

    }
    void readFromFile() {
        fstream file("Shapes.dat", ios::in);
        string contents((istreambuf_iterator<char>(file)), (istreambuf_iterator<char>()));
        file.close();
        cout << contents;
    }
    void readData() {
        cout << "Enter radius: " << endl;
        cin >> redius;
        cout << "Enter height: " << endl;
        cin >> height;
    }
    bool operator==(const Cylinder& other) const {
        return this->surfaceArea == other.surfaceArea || this->volume == other.volume;
    }

    bool operator>(const Cylinder& other) const {
        return this->surfaceArea > other.surfaceArea || this->volume > other.volume;
    }

    bool operator<(const Cylinder& other) const {
        return this->surfaceArea < other.surfaceArea || this->volume < other.volume;
    }

};

