#include <fstream>
#include <iostream>

using namespace std;

// getLast:
// 		displays last n lines in the specified file.
//    	assumes each line is maximum of 256 characters. 
// N.B. will have to check for lines greater than 256.
//      returns 0 if successful;  1 if error;
int getLast(int linesToRead, string filename){
	
	char ringBuffer[linesToRead][256];
	int ringBufferIndex = 0;
	
	ifstream reader(filename);
	
	cout << "In getLast function with request to read last " << linesToRead << " lines from " 
		<< filename << endl;
			
	if( !reader ){
		cout << "Error openning file " << filename << endl;
		return -1;
	}

	while( reader.peek() != EOF ){
		reader.getline(ringBuffer[ringBufferIndex], 256);
	//	cout << "[" << ringBufferIndex << "]: " << ringBuffer[ringBufferIndex] << endl;
		ringBufferIndex = ( ringBufferIndex + 1 ) % linesToRead;
	}

	cout << "Done reading file.  Index is " << ringBufferIndex << endl;
	
	// At this point, ringBufferIndex should already be at the correct position.
	for(int i = 0 ; i < linesToRead; i++ ){
		cout << "[" << ringBufferIndex << "]" << ringBuffer[ringBufferIndex] << endl;
		ringBufferIndex = ( ringBufferIndex + 1 ) % linesToRead;
		}
	
	reader.close();
	return 0;
	
}

int main(){
	
	string fileName = "output1.txt";
	ofstream myFile(fileName);
	int linesToRead = 0;
	char ltr[10];
	
	
	if( !myFile ){
		cout << "Encounter error openning file myFile" << endl;
		return -1;
	}
			
	for(int i = 0; i < 100 ; i++){
			
		myFile << "myFile line: " << i << "\n";
	}
	
	myFile.close();
	
	cout << "Enter number of lines to read (max=99): " << endl;
	cin.getline(ltr, 10);
	cout << "You entered " << ltr << endl;
	linesToRead = stoi(ltr);
	
	getLast(linesToRead, fileName);
	return 0;
	
	
	
}