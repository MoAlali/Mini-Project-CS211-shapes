#include <iostream>
#include"Cone.h"
#include"Cube.h"
#include"Cylinder.h"
#include"Hexagon.h"
#include"sphere.h"
#include"square.h"
#include"Triangle.h"
#include "Circle.h"

int main()
{

    double r, side, base, height;
    int choice;

    cout << "--------------------" << endl;
    cout << "Attention, make sure that you have created a file before, to use the second option" << endl;
    cout << "(1) Store data: " << endl;
    cout << "(2) Retrieve data: " << endl;
    cout << "--------------------" << endl;
    cin >> choice;

    if (choice == 1) {
        int n;
        cout << "Select any Number to calculate : " << "\n";
        cout << "1. Circle \n";
        cout << "2. Square\n";
        cout << "3. Triangle\n";
        cout << "4. Hexagon\n";
        cout << "5. Sphere\n";
        cout << "6. Cube\n";
        cout << "7. Cylinder\n";
        cout << "8. Cone\n";
        cin >> n;
        if (n == 1) {
            Circle obj1;
            obj1.readData();
            obj1.computeArea();
            obj1.computePerimeter();
        }

        if (n == 2) {
            Square obj2;
            obj2.readData();
            obj2.computeArea();
            obj2.computePerimeter();
        }

        if (n == 3) {
            Triangle obj3;
            obj3.readData();
            obj3.computeArea();
            obj3.computePerimeter();
        }

        if (n == 4) {
            Hexagon obj4;
            obj4.readData();
            obj4.computeArea();
            obj4.computePerimeter();
        }

        if (n == 5) {
            Sphere obj5;
            obj5.readData();
            obj5.computeSurfaceArea();
            obj5.computeVolume();
        }

        if (n == 6) {
            Cube obj6;
            obj6.readData();
            obj6.computeSurfaceArea();
            obj6.computeVolume();
        }

        if (n == 7) {
            Cylinder obj7;
            obj7.readData();
            obj7.computeSurfaceArea();
            obj7.computeVolume();
        }


        if (n == 8) {
            Cone obj8;
            obj8.readData();
            obj8.computeSurfaceArea();
            obj8.computeVolume();
        }
    }
    else if(choice == 2){
        Circle s;
        s.readFromFile();
    }
    else {
        cout << "invalid entery";
    }


 

    return 0;
}