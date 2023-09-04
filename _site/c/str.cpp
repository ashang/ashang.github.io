//#include <iostream>
#include <fstream>
#include <unistd.h>
#define SYSTEM_RELEASE_PATH "/etc/os-release"

use namespace std;

int main (){
	string find_str;
	string str;
	size_t pos = 0;

	string hardware_mode;

	ifstream fin_system( SYSTEM_RELEASE_PATH );

	while(getline(fin_system, str)) {
		//find_str = "HARDWARE_MODEL=";
		find_str = "VERSION_ID=";
		pos = str.find(find_str);
		if (pos != string::npos) {
		    hardware_mode = str.substr(pos);
		}
	}
}
