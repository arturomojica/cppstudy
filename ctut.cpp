#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include <math.h>


using namespace std;

/* 
int getFactorial(int num){
	int result;
	if(num == 0){
		return 0;
	}
	else if(num == 1){
		result = 1;
	}
	else{
		result = getFactorial(num - 1) * num;
	}
	return result;
}

void makeMeYoung(int* agePtr){
	
	*agePtr = 29;
	

}

void actYourAge(int& age){
	age = 39;
}
 */

class Animal{
	/* Attributes: height, weigth */
	/* capabilities: run , eat, */
	private: 
		int height;
		int weight;
		string name;
		
		static int numOfAnimals;  // static are variables shared by all instances of animals
		
	public:
		void getFamily(){cout << "We are Animals" << endl; }
		virtual void getClass(){ cout << "I'm an Animal." << endl; }
		int getHeight(){ return height; }
		int getWeight(){ return weight; }
		string getName(){ return name; }
		virtual void makeSound(){ cout << "Woof-Woof" << endl; }
		
		void setHeight(int cm){ height = cm; }
		void setWeight(int kg){ weight = kg; }
		void setName(string callIt){ name = callIt; }
		
		void setAll(int, int, string);
		
		Animal(int, int, string);
		~Animal();
		Animal();
		
		// Protected: available to members of class or subclass
		
		static int getNumOfAnimals() { return numOfAnimals; }
		
		void toString();
};

int Animal::numOfAnimals = 0;

void Animal::setAll(int height, int weight, string name){
	
	this->height = height;
	this->weight = weight;
	this->name = name;
	Animal::numOfAnimals++;
}

Animal::Animal(int height, int weight, string name) {
	this->height = height;
	this->weight = weight;
	this->name = name;
	Animal::numOfAnimals++;
}
 
Animal::~Animal(){
	cout << "Animal: " << this->name << " destroyed." << endl;
	if( Animal::numOfAnimals > 0 ){
		Animal::numOfAnimals--;
	}
}

Animal::Animal(){
	Animal::numOfAnimals++;
} 
 
void Animal::toString(){
	cout << this->name << " is " << this->height << " cms tall and "
		<< this->weight << " kgs heavy. " << endl;
} 

class Dog : public Animal{
	
	private:
		string sound = "Woof";
		
	public:
		void getClass(){ cout << "I'm a dog." << endl; }
		getSound(){ cout << sound << endl; }
		//string getSound(){ return sound; }
		Dog(int, int, string, string);
		Dog() : Animal(){};
		void toString();
};

Dog::Dog(int height, int weight, string name, string bark) :
	Animal(height, weight, name){
		this->sound = bark;
	}

void Dog::toString(){
	cout << this->getName() << " is " << this->getWeight() << " kgs heavy and "
		<< this->getHeight() << " cms tall and sounds like " << this->sound <<endl;
}	

void whatClassAreYou(Animal *animal){
		animal->getClass();
}

class Chihuahua : public Dog{
	public:
		void getClass() { cout << "I'm a Chihuahua! " << endl; }
		void getDerived() { cout << "I'm an Animal and a Dog. " << endl; }
};

class Cat : public Animal{
	public:
		void makeSound(){ cout << "Meow" << endl; }
};

int main(){

	Animal doug;
	doug.setName("Doug");
	doug.setHeight(25);
	doug.setWeight(40);
	
	cout << doug.getName() << " is " << doug.getWeight() << " kgs in weight and "
		<< doug.getHeight() << " cms tall." << endl;

	Animal tom(25, 99, "tom");
	
	cout << tom.getName() << " is " << tom.getWeight() << " kgs in weight and "
		<< tom.getHeight() << " cms tall." << endl;

	Dog charlie(14, 22, "Charlie", "yap-yap");
	/* cout << charlie.getName() << " is " << charlie.getWeight() << " kgs in weight, "
		<< charlie.getHeight() << " cms tall and sounds like " << charlie.getSound()
		<< endl;
 */
	
	cout << "Number of animals = " << Animal::getNumOfAnimals() << endl;
	charlie.getSound();
	charlie.toString();
	charlie.Animal::toString();
	
	Animal *animal = new Animal;
	Dog *dog = new Dog;
	
	animal->getClass();
	dog->getClass();
	
	whatClassAreYou(animal);
	whatClassAreYou(dog);
	
	Chihuahua *chiquita = new Chihuahua;
	chiquita->getClass();
	chiquita->getDerived();
	whatClassAreYou(chiquita);
	
	Dog spot;
	Chihuahua dot;
	
	Animal* ptrDog = &spot;
	Animal* ptrChihuahua = &dot;
	
	ptrDog -> getClass();
	ptrDog -> getFamily();
	
	ptrChihuahua -> getClass();
	ptrChihuahua -> getFamily();
	
	ptrDog -> makeSound();
	Cat kitty;
	Cat* ptrCat = &kitty;
	ptrCat->makeSound();

/* 
	int myAge = 39;
	int* agePtr = &myAge;
	
	cout << "Address of pointer " << agePtr << endl;
	cout << "Data at memory address " << *agePtr << endl;
	makeMeYoung(&myAge);
	cout << "My new age is " << *agePtr << endl;
	
	int& ageRef = myAge;
	cout << "Age reference points to: " << ageRef << endl;
	cout << "myAge: " << myAge << endl;
	ageRef++ ;
	cout << "myAge: " << myAge << endl;

	actYourAge(myAge);
	cout << "Act your age: " << myAge << endl;
 */
	/* int myAge = 39;
	char myGrade = 'A';
	char *gradePtr = &myGrade;
	int badNums[5] = {4, 14, 24, 34,44};
	int * numArrayPtr = badNums;
	
	cout << "My Age: " << myAge << endl;
	cout << "My grade: " << myGrade << endl;
	cout << "Size of int " << sizeof(myAge) << endl;
	cout << "Size of char " << sizeof(myGrade) << endl;
	cout << "Address of myAge: " << &myAge << endl;
	cout << "Address of myGrade: " << &myGrade << endl;
	cout << "Another way of looking at address of myGrade: " << gradePtr << endl;
	cout << "Data at gradePtr: " << *gradePtr << endl;
	cout << "Size of int addres " << sizeof(&myAge) << endl;
	cout << "size of char address " << sizeof(&myGrade) << endl;
	cout << "address of badNums array: " << numArrayPtr << " has " << *numArrayPtr << endl;
	numArrayPtr++;
	cout << "address of badNums array: " << numArrayPtr << " has " << *numArrayPtr << endl;
	numArrayPtr++;
	cout << "address of badNums array: " << numArrayPtr << " has " << *numArrayPtr << endl;
	
	numArrayPtr = badNums; // restore initial value
	for (int i = 0; i < sizeof(badNums)/sizeof(int) ; i++){
		cout << "data at index [" << i << "]";
		cout << "at address [" << numArrayPtr << "]: " ;
		cout << badNums[i] << endl;
		numArrayPtr++;
	}
 */
/* 
	string steveQuote = "A day without sunshile is like, you know, night.";
	ofstream myStream("stevequote.txt");
	char letter;
	int i;
	int number = 0;
	
	try{
		if(number != 0){
			cout << 2/number << endl;
		}
		else{
			throw(number);
		}
	}
	catch(int errorCode){
		cout << errorCode << " is not valid!" << endl;
	}
 */	
	/* 
	if(! myStream){
		cout << "Error opening file" << endl;
		return -1;
		
	}
	else{
		
		myStream << steveQuote << endl;
		myStream.close();
	}
 */
	//ofstream writer2("stevequote.txt", ios::app);
	// Open a stream to append to what's already there with ios::app
	// ios::binary  : tread as binary
	// ios::in  : open file to read input
	// ios::trunc  : default (truncate when open)
	// ios::out  : open file to write output.
	/* 
	if(! writer2){
		cout << "Error opening file" << endl;
		return -1;
		
	}
	else{
		
		writer2 << "\n -Steve Martin" << endl;
		
		for (int i = 0; i <= 100; i++){
			writer2 << "Another line with index [" << i << "]\n";
		}
		writer2.close();
	}
	
	
	
	ifstream reader("stevequote.txt");
	if (!reader){
		cout << "Error openning file!" << endl;
		return -1;
	}
	else{
		for (i = 0; ! reader.eof(); i++){
			reader.get(letter);
			cout << letter;
		}
		cout << "Read " << i << " characters." << endl;
		reader.close();
	}


 */




/* 
	for (int i = 0; i <= 10; i++){
		cout << "Factorial of " << i << " is " << getFactorial(i) << endl;
	}
 */
/* 
	vector <int> lotteryNumVect(10);
	vector<int> first;
	vector<int> second;
	vector<int> third;

	int lotteryNumberArray[5] = {4, 14, 24, 34, 44};
	cout << "size of lotteryNumberArray: " << ( sizeof(lotteryNumberArray) / sizeof(int) ) << endl;
	cout << "The vector size is " << lotteryNumVect.size() << endl;
	cout << "The size of Array is " << ( sizeof(lotteryNumberArray) / sizeof(int) ) << endl;

	for (int i = 0; i < sizeof(lotteryNumberArray) / sizeof(int) ; i++ ){
			cout << lotteryNumberArray[i] << endl;

	}

	lotteryNumVect.insert(lotteryNumVect.begin(), lotteryNumberArray,
		lotteryNumberArray+3);


	cout << "The element at vector[0] is " << lotteryNumVect.at(0) << endl;
	cout << "The vector size is " << lotteryNumVect.size() << endl;
	
	lotteryNumVect.push_back(64);
	cout << "final value: " << lotteryNumVect.back() << endl;
	cout << "vector size " << lotteryNumVect.size() << endl;
	
	for (int i = 0; i < lotteryNumVect.size(); i++ ){
		cout << "[" << i <<"]:" << lotteryNumVect.at(i) << endl;
		
	}
	
	first.assign(7, 100);
	vector<int>::iterator it;
	it=first.begin()+1;
	
	second.assign(it, first.end()-1);
	int myInts[]={1776, 7, 4};
	
	third.assign(myInts, myInts+3);
	
	cout << "Size of first: " << first.size() << endl;
	for ( int i = 0; i < first.size(); i++ ){
		cout << "[" << i <<"]:" << first.at(i) << endl;
	}
	
	cout << "Size of second: " << second.size() << endl;
	for ( int i = 0; i < second.size(); i++ ){
		cout << "[" << i <<"]:" << second.at(i) << endl;
	}
	
	cout << "Size of third: " << third.size() << endl;
	for ( int i = 0; i < third.size(); i++ ){
		cout << "[" << i <<"]:" << third.at(i) << endl;
	}
	 */
	

	/*
	string dogString = "dog";
	string catString = "cat";

	cout << dogString.compare(catString) << endl;
	cout << dogString.compare(dogString) << endl;
	cout << catString.compare(dogString) << endl;

	 */
	/*
	char happyArray[6] = {'H','a','p','p','y','\0'};
	string birthdaystring = " Birthday";
	double eulersConstant = .57721;
	string eulerGuess;
	double eulerGuessDouble;

	cout << happyArray + birthdaystring << endl;
	*/
	/*
	string yourName;

	cout << "What is your name? " << endl;
	getline(cin, yourName);

	cout << "Hello " << yourName << endl;

	string wholeName = yourName.assign(yourName);
	cout << wholeName << endl;
	cout << "yourName is " << yourName << endl;

	string firstName = yourName.assign(yourName,0, 6);
	cout << firstName << endl;
	cout << "yourName is " << yourName << endl;

	cout << wholeName << endl;
	int lastNameIndex = wholeName.find("Mojica", 0);
	cout << "Index for last name is " << lastNameIndex << endl;

	wholeName.replace(7, 6, "Maximus");
	cout << "New name is " << wholeName << endl;
	 */
	/*
	cout << yourName << " what is Euler's constant? " << endl;
	getline(cin, eulerGuess);



	eulerGuessDouble = stod(eulerGuess);

	if(eulerGuessDouble == eulersConstant){
		cout << "You are correct!" << endl;
	}
	else{
		cout << "Wrong!" << endl;
	}

	cout << "Size of string " << eulerGuess.size() << endl;
	cout << "Is string empty " << eulerGuess.empty() << endl;
	cout << eulerGuess.append(" was your guess.") << endl;

	 */



	/*
	string numberGuessed;
	int intNumberGuessed = 0;

	do{
		cout << "Enter a number between 0 and 10: ";
		getline(cin, numberGuessed);
		intNumberGuessed = stoi(numberGuessed);

	} while (intNumberGuessed != 4);
	cout << "Yay!  You guessed the correct number: " << intNumberGuessed << endl;

	 */


	/*
	int randNum = (rand() % 100) + 1;
	while (randNum != 100){

		cout << randNum << endl;
		randNum = (rand() % 100) + 1;
	}
	cout << "Found " << randNum << endl;
	 */

/* 	int i;
	int badNums[5] = {4, 13, 14, 24, 34};
	cout << "Size of badNums[] "<< sizeof(badNums) / sizeof(badNums[0]) << endl;
	for(i=0; i < sizeof(badNums) / sizeof(badNums[0]); i++){

		cout << badNums[i] << endl;

	}

	char myName[2][6] = {{'A','r','t','u','r','o'},
		{'M','o','j','i','c','a'}};

	cout << "My first name is " << myName[0][0] << endl;

	for(int j = 0; j<2; j++){

		for(int k = 0; k < 6; k++ ){

			cout << "[" << j <<"][" <<k << "]: " << myName[j][k] << endl;

		}

	}
	cout << endl;
	 */
	/*
	cout << "Hello World from Arturo" << endl;
	const double PI = 3.1415926535;
	char myGrade = 'A';
	bool isHappy = true;
	int myAge = 39;
	float favNum = 3.1415926535;
	double otherfavNum = 1.6180339887;
	double base = 2;
	*/
	// Other Data Types
	// short int : at least 16 bits
	// long int : at least 32 bits
	// long long int : at list 64 bits
	// unsigned int : Same size as signed version
	// long double : Not less than double

	/*
	cout << "Size of bool " << sizeof(isHappy) << endl;
	cout << "Size of char " << sizeof(myGrade) << endl;
	cout << "Size of int " << sizeof(myAge) << endl;
	cout << "Size of double " << sizeof(otherfavNum) << endl;
	cout << "Size of float " << sizeof(favNum) << endl;

	int exponent = 32-1;
	int largestInt = 2 ^ exponent;
	cout << "Exponent " << exponent << endl;
	cout << "Largest integer " << largestInt << endl;
	cout << "Favorite Number " << favNum << endl;
	*/
	/*
	for ( exponent = 0; exponent < 32 ; exponent++) {

		cout << "2 ^ " << exponent << " = " << pow(base,exponent)  << endl;
	}
	*/
	/*
	cout << "4 / 5 = " << 4 /5 << endl;
	cout << "4 / 5 = " << (float) 4  / 5 << endl;
	*/
	/*
	int greetingOption = 2;

	switch(greetingOption){
		case 1:
			cout << "bonjour" << endl;
			break;
		case 2:
			cout << "hola" << endl;
			break;
		case 3:
			cout << "holla" << endl;
			break;
		default:
			cout << "Hello" << endl;

	}
	*/


	return 0;
}
