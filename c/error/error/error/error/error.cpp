#include "error.hh"
#include <iostream>

void Error(std::string msg)
{
    std::cerr
     << "\n=========================================================\n"
     << msg
     << "\n=========================================================\n";
    exit(EXIT_FAILURE);
}
