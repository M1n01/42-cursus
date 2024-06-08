#include "../includes/Base.hpp"
#include "../includes/A.hpp"
#include "../includes/B.hpp"
#include "../includes/C.hpp"
#include <iostream>

Base *generate(void)
{
    srand(time(NULL)); // mainに移動したほうがいい
    int random = rand() % 3;

    if (random == 0)
    {
        return new A();
    }
    else if (random == 1)
    {
        return new B();
    }
    else
    {
        return new C();
    }
}

void identify(Base *p)
{
    if (dynamic_cast<A *>(p) != NULL)
    {
        std::cout << "A" << std::endl;
    }
    else if (dynamic_cast<B *>(p) != NULL)
    {
        std::cout << "B" << std::endl;
    }
    else if (dynamic_cast<C *>(p) != NULL)
    {
        std::cout << "C" << std::endl;
    }
    else
    {
        std::cout << "Unknown type" << std::endl;
    }
}

void identify(Base & p)
{
    try
    {
        A &a = dynamic_cast<A &>(p);
        (void)a;
        std::cout << "A" << std::endl;
    }
    catch (const std::bad_cast &e)
    {
        try
        {
            B &b = dynamic_cast<B &>(p);
            (void)b;
            std::cout << "B" << std::endl;
        }
        catch (const std::bad_cast &e)
        {
            try
            {
                C &c = dynamic_cast<C &>(p);
                (void)c;
                std::cout << "C" << std::endl;
            }
            catch (const std::bad_cast &e)
            {
                std::cout << "Unknown type" << std::endl;
            }
        }
    }
}


int main()
{
    Base *base = generate();
    

    std::cout << "Identify by pointer:" << std::endl;
    identify(base);
    std::cout << "Identify by reference:" << std::endl;
    identify(*base);
    delete base;

    return 0;
}
