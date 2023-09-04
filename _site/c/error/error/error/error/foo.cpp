#include "error.hh"
int main()
{
    for(int i=0; i<99; i++)
        if(i==55)
            Error("this works");
    return 0;
}

// $ g++ -c error.cpp foobar.cpp
// $ g++ error.o foobar.o -o exampleprogram
