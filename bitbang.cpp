#include <iostream>
#include <string>

#define FILELINE cout << endl << "In file " << __FILE__ << " at line " << __LINE__ << "." << endl;

using namespace std;


void sendData(unsigned int dataToSend){
	
	unsigned int currentBit = 0x80000000;  // Start with MSB.
	cout << "Size of int: " << sizeof(dataToSend) << endl;
	
	cout << "Binary: ";
	
	for(int i=0; i < 32 ; i++ ){
				
		cout << (( dataToSend & currentBit ) ? "1" : "0" ) << " ";
		currentBit /= 2;
		
	}
	//cout << endl << "In file " << __FILE__ << " at line " << __LINE__ << "." << endl;
	FILELINE
}

int main(){
	
	string userData;
	unsigned int dataToSend = 0;
	
	bool isValid = false;
	int dataLen = 0;
	char nextChar;
	
	while( ! isValid ){
		
		cout << "Enter data you want to send (0 to 99): )" << endl;
		getline(cin, userData);
		dataLen = userData.length();
		
		if ( dataLen <= 2 ){
			isValid = true;
			for(int i = 0; i < dataLen; i++ ){
				nextChar = userData.at(i);
				isValid &= ( nextChar >= '0' && nextChar <= '9' );
			}
		}
		
		if( isValid ){
			cout << "You entered "<< dataLen << " characters." << endl;
			dataToSend = stoi(userData);
			cout << "goin to send " << dataToSend << " in serial as: " << endl;
			sendData(dataToSend);
		}
		else{
			cout << userData << " is not valid!" << endl;
		}
		
		
		
	}
	
	FILELINE
	return 0;
	
}