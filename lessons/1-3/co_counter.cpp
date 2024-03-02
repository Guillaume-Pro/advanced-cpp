#include <generator>
#include <iostream>

generator<unsigned int> iota(unsigned int n = 0)
{
    while (true)
        co_yield n++;
}