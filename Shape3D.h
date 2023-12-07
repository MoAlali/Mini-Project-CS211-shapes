#pragma once
#include "Shape.h"
#include<iostream>
using namespace std;
class Shape3D :    public Shape
{
   
public:
    double surfaceArea, volume, length, width;
    Shape3D() {
        volume = 0;
        surfaceArea = 0;

    }

    Shape3D(double surfaceArea, double volume) {
        this->surfaceArea = surfaceArea;
        this->volume = volume;

    }

    bool operator==(const Shape3D& other) const {
        return this->surfaceArea == other.surfaceArea || this->volume == other.volume;
    }

    bool operator>(const Shape3D& other) const {
        return this->surfaceArea > other.surfaceArea || this->volume > other.volume;
    }

    bool operator<(const Shape3D& other) const {
        return this->surfaceArea < other.surfaceArea || this->volume < other.volume;
    }

    virtual void printToFile() override {

    }
    virtual void readFromFile() override {

    }
    virtual void print() override {

    }
    virtual void readData() override {

    }
    virtual void computeSurfaceArea() {

    }

    virtual void computeVolume() {

    }

    double getSurfaceArea() {
        return surfaceArea;
    }
    double getVolume() {
        return volume;
    }
    void setVolume(double res) {
        this->volume = volume;
    }
    void setSurfaceArea(double res) {
        this->surfaceArea = surfaceArea;
    }
};

