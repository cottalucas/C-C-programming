#include "Triangle.h"
#include <iostream>

int Triangle::getA()
{
    return side1;
}

void Triangle::setA(int x)
{
    side1 = x;
}

int Triangle::getB()
{
    return side2;
}

void Triangle::setB(int y)
{
    side2 = y;
}

int Triangle::getC()
{
    return side3;
}

void Triangle::setC(int z)
{
    side3 = z;
{

bool isValid()
{
    if ((side1 > 0) && (side2 > 0) && (side3 > 0))
    {
        if (((side1 + side2) > side3) || ((side2 + side3) > side1) || ((side1 + side3) > side2))
        {
            return true;
        } else { return false; }
    } else { return false;}
}


int main()
{
    Triangle triangle;
    triangle.set_values(1,2,3);

    std::cout << "Test side1 " << triangle.getA();

    return 0;
}
