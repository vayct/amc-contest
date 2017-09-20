#include <sstream>
#include <iostream>
#include <string.h>
#include <stdlib.h>
#include <bitset>
using namespace std;





int main() {

	cout <<bitset<32>(	1ULL | (1 << 31)) << endl;

	
	unsigned long long zero = 0;
	unsigned long long one = 0;
	
	int endFlag = 0;
	while( endFlag == 0){

		unsigned long long numA, numB, numC, numS;	
		

		cin >> numA;
		if(numA == 0) break;

		cin >> numB >> numC >> numS;

		unsigned long long result = (numA * numS + numB) % numC;
		cout << result << "=" << bitset<32>(result) <<"\n";

		for(int i < 0; i < 32; i++){


		}

		
	}
	




}//end main
