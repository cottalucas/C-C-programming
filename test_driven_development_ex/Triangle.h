//Triangle.h
#ifndef TRIANGLE_H
#define TRIANGLE_H

class Triangle
{
    private:
    int x, y, z;

    public:
    //constructor
    Triangle(int x, int y, int z){}
    
    int getA();
    void setA(int x);

    int getB();
    void setB(int y);

    int getC();
    void setC(int z);

    bool isValid();
};

#endif
