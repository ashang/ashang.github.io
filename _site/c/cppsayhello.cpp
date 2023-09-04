/* cppsayhello.cpp */
#include <iostream>

extern "C" void cppsayhello(char *str);

void cppsayhello(char *str) {
	std::cout << str << "\n";
}
