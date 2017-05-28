#include <iostream>
#include <math.h>
#include <fstream>

using namespace std;

int fibNaive(int i){
	if(i == 0) return 0;
	if(i == 1) return 1;
	return fibNaive(i-1) + fibNaive(i-2);
	
}

int main(){
	
	int number = 40;
	/* 
	for(int number = 0; number <= numMax ; number++ ){
		cout << "Naive version of fibonacii with input " << number 
			<< " returns: " << fibNaive(number) << endl;
		
	 }
	*/
	
	
	cout << "Naive version of fibonacii with input " << number 
		<< " returns: " << fibNaive(number) << endl;


	
	return 0;
	
}