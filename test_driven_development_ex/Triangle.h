//Triangle.h
#ifndef TRIANGLE_H
#define TRIANGLE_H

class Triangle
{
    private:
    int side1, side2, side3;

    public:
    //constructor
    Triangle(int x, int y, int z)
    {
        side1 = x;
        side2 = y;
        side3 = z;
    }
    
    int getA();
    void setA(int x);

    int getB();
    void setB(int y);

    int getC();
    void setC(int z);

    bool isValid();
};

#endif
