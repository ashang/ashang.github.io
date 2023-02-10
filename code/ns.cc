#include <iostream>

#include "ns.h"

namespace my{
	void foo(){
		int myInt;
		std::cout << "Calling  " << __func__ << std::endl;
		std::cout << "foo() called in my ns." << std::endl;
		std::cout << "uninitialized Int: " << myInt << std::endl;
	}
}

int main(){

	my::foo();
	return 0;
}
