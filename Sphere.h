#pragma once
#include "Shape3D.h"
#include<fstream>
using namespace std;
class Sphere :    public Shape3D
{
    double radius;
public:
    Sphere()
    {
        radius = 0;
    }
    Sphere(double radius){
        this->radius = radius;
    }
    void computeSurfaceArea() {
        double area;
        area = 4 * 3.14 * radius * radius;
        print("Area", area);
  
        this->surfaceArea = area;
    }
    void computeVolume() {
        double Volume;
        Volume = (4 / 3) * (3.14 * radius * radius * radius);
        print("Volume", Volume);
        printToFile("Volume", Volume , "SurfaceArea", surfaceArea);
        this->volume = Volume;
    }
    virtual void print(string x, double y)
    {
        cout << x << " of Sphere = " << y << "\n";
    }
    virtual void printToFile(string x, double y, string x2, double y2)
    {
        ofstream ofs;
        ofs.open("shapes.dat");
        if (!ofs) {
            cout << "Error opening file" << endl;

        }
        cout << "Shapes.dat file updated ." << "\n";
        ofs << x << " of Sphere = " << y << "\n";
        ofs << x2 << " of Sphere = " << y2 << "\n";

    }
    void readFromFile() {
        fstream file("Shapes.dat", ios::in);
        string contents((istreambuf_iterator<char>(file)), (istreambuf_iterator<char>()));
        file.close();
        cout << contents;
    }
    void readData() {
        cout << "Enter radius: " << endl ;
        cin >> radius;
    }
    bool operator==(const Sphere& other) const {
        return this->surfaceArea == other.surfaceArea || this->volume == other.volume;
    }

    bool operator>(const Sphere& other) const {
        return this->surfaceArea > other.surfaceArea || this->volume > other.volume;
    }

    bool operator<(const Sphere& other) const {
        return this->surfaceArea < other.surfaceArea || this->volume < other.volume;
    }
};

