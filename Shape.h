#pragma once
#include <iostream>
#include <fstream>
#include <cstring>  
using namespace std;

class Shape {
    char name[10];
    char color[10];

public:
    Shape() {
        setName("No name");
        setColor("No Color");
    }

    Shape(char Name[10], char Color[10]) {
       
        for (int i = 0; i < 10; ++i) {
            name[i] = Name[i];
            color[i] = Color[i];
        }
    }

    char* getName() {
        return name;
    }

    char* getColor() {
        return color;
    }

    void setName(const char Name[]) {
        int size = strlen(Name);
        for (int i = 0; i < size && i < 10; i++) {
            name[i] = Name[i];
        }
    }

    void setColor(const char Color[]) {
        int size = strlen(Color);
        for (int i = 0; i < size && i < 10; i++) {
            color[i] = Color[i];
        }
    }

    virtual void printToFile() = 0;

    virtual void readFromFile() = 0;

    virtual void readData() = 0;

    virtual void print() = 0; 
  
};
