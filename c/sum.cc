
#include <iostream>

using namespace std;

//int sum(int n) {
long sum(int n) {
	return n ? sum(n-1) + n: 0;
}

int main(){
	cout<< sum(1000000) << endl;
	//cout<< sum(1000000) << endl;
	// Segmentation fault
}
