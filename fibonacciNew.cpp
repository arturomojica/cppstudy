#include <iostream>
#include <math.h>
#include <fstream>

using namespace std;

int fibonacci(int i, int memo[]){
	if( i == 0 || i == 1 ){ return i; }
	if( memo[i] == 0 ){
		memo[i] = fibonacci(i - 1, memo) + fibonacci(i - 2, memo);		
		cout << "Fibonacci at index " << i << " is " << memo[i] << endl;
	}
	return memo[i];
}

int fibonacci(int n){
	
	return fibonacci(n, new int[n+1]);
}

int main(){
	int number = 40;
	cout << "Fibonacci of " << number << " is: " << fibonacci(number) << endl;
}