// Exception.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>

class A
{
public:
    int* i;
    A()
    {
        i = new int[100];        
    }
    
    ~A() noexcept(false)
    {
        std::cout << "This is destructor" << std::endl;
        delete[] i;
        throw std::exception("Terminated destructor");
    }
};

int main()
{
    try
    {
        A a;
    }
    catch (const std::exception& msg)
    {
        std::cout << msg.what();
    }
    
    return 0;
}

