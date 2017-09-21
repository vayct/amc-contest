#include <sstream>
#include <iostream>
#include <string.h>
#include <stdlib.h>
#include <bitset>
using namespace std;



int SIZE = 16;

//returns true if k'th bit is set
bool testBit(unsigned long long code, int k){
	return (code & 1ULL << k) > 0;
}

//set the k'th bit of code
void setBit(unsigned long long &code, int k){
	code |= 1ULL << k ;
}

//clear the k'th bit of code
void clearBit(unsigned long long &code, int k){
	code &= ~(1ULL << k);
}

//keep counter of code
void andBit(unsigned long long &code, int k){
	code &= 1ULL << k;
}

int main() {



	int endFlag = 0;
	while( endFlag == 0){

		unsigned long long numA, numB, numC, numS;	
		
		//check to see if user enter 0 to break out of loop
		cin >> numA;
		if(numA == 0) break;


		//read in the other 3 number
		cin >> numB >> numC >> numS;

		
		//0 and 1 tracker, currently all 111111111111111111111111111111111111;
		unsigned long long zero = 0;
		zero = ~zero;
		unsigned long long one = 0;
		one = ~one;

		char result[SIZE];

		//do the computation to generate the new number
		//TODO check for duplicate and break out
		for(int i=0; i < 64000; i++){

			//flip all the bits AND zero, then set that result to zero
			//that way, only 0 from the calculation is saved as 1
			zero = ~numS & zero;

			//calculation AND one, then set that result to one
			//that way, only 1 from the calculation is saved as 1
			one = numS & one;

			numS = (numA * numS + numB) % numC;
		}

		
		//initilaized the result to display ???????????????????????????????
		for(int i = 0; i < SIZE; i++){
			result[i] = '?';
		}

		for(int i = 0; i < SIZE; i++){

			//if there is a 1 in zero, then the bit is 0 throughout the calculation
			if(testBit(zero,i)){				 
				result[i] = '0';
			}

			//if there is a 1 in one, then the bit is 1 throughout the calculation
			if(testBit(one,i)){
				result[i] ='1';
			}
		}

		//reverse the result since the number is stored in big endian
		for(int k = SIZE -1; k >= 0; k--){
			cout << result[k] << "";
		}
		cout<<endl;
			



		
	}
	




}//end main
