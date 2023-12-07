#pragma once
#include "Shape.h"
class Shape2D :public Shape {
public:
    double area, perimeter, length, width;
    Shape2D(){
        area = 0;
        perimeter = 0;
        
    }
   
    Shape2D(double area, double perimeter){
        this->area = area;
        this->perimeter = perimeter;

    }

    bool operator==(const Shape2D& other) const {
            return this->area == other.area || this->perimeter == other.perimeter;
    }

    bool operator>(const Shape2D& other) const {
        return this->area > other.area || this->perimeter > other.perimeter;
    }

    bool operator<(const Shape2D& other) const {
        return this->area < other.area || this->perimeter < other.perimeter;
    }
    virtual void printToFile() override {

    }

    virtual void readFromFile() override {

    }
    virtual void print() override {

    }
    virtual void readData() override {

    }
    virtual void computeArea()  {

    }
        
    virtual void computePerimeter() {

    }
     
   
    double getArea() {
        return area;
    }
    double getPerimeter() {
        return perimeter;
    }
    void setArea(double res) {
        this->area = area;
    }
    void setPerimeter(double res) {
         this->perimeter = perimeter;
    }


};

