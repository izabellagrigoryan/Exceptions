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
        
        try
        {   
            delete[] i;
            throw std::exception("Terminated destructor");
        }
        catch (std::exception& msg)
        {
            std::cerr << msg.what() << " from destructor" << std::endl;
        }
    }
};

int main()
{   
    A a;
    try
    {     
        a.i[4] = 8;
        throw std::exception("Terminated destructor");
    }
    catch (const std::exception& msg)
    {
        std::cout << msg.what() << " out of destructor" << std::endl;
    }
    
    return 0;
}

