/* cpp2c.cpp */
#include <iostream>
extern "C" void csayhello(char *str);
int main(int argc,char *argv[])
{
    csayhello( "Hello from cpp to c");
    //csayhello( string("Hello from cpp to c"));
    return(0);
}
