#include "Triangle.h"
#include <iostream>

int Triangle::getA()
{
    return side1;
}

void Triangle::setA(int x)
{
    this->side1 = x;
}

int Triangle::getB()
{
    return side2;
}

void Triangle::setB(int y)
{
    this->side2 = y;
}

int Triangle::getC()
{
    return side3;
}

void Triangle::setC(int z)
{
    this->side3 = z;
}

bool Triangle::isValid()
{
    if ((side1 > 0) && (side2 > 0) && (side3 > 0))
    {
        return ((side1 + side2) > side3) || ((side2 + side3) > side1) || ((side1 + side3) > side2);
    } 
    
    else 
    { 
        return false; 
    }
}


int main()
{
    Triangle *triangle;
    triangle = new Triangle(10, 15, 20);    
    
    std::cout << "Test side1 " << triangle->getA() << std::endl;
    std::cout << "Test side2 " << triangle->getB() << std::endl;
    std::cout << "Test side3 " << triangle->getC() << std::endl;

    if (triangle->isValid() == true)
    {
        std::cout << "Valid triangle" << std::endl;
    }
    else
    {
        std::cout << "Invalid triangle" << std::endl;
    }

    return 0;
}
