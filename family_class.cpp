#include <iostream>
#include <string>

using namespace std;

class Person{
	private:
		string name;
		int age;
		int height;
		int weight;

		static int personCount;
		static int getPeopleCount();
	
	public:
		void setName(string name){ name = name; }
		void setHeight(int height) { height = height; }
		void setWeight(int weight) { weight = weight; }
		string getName(){ return name; }
		int getHeight(){return height; }
		int getWeight(){ return weight; }
		
		static int getPersonCount(){ return personCount; }
		
		Person(string, int, int, int);
		~Person();
		
};

int Person::personCount = 0;

Person::Person(string name, int age, int height, int weight ){
	
	this->name = name;
	this->age = age;
	this->height = height;
	this->weight = weight;
	
	personCount += 1;
}

Person::~Person(){
	personCount -= 1;
}


int main(){
	
	Person arturo("Arturo", 57, 69, 185);
	cout << arturo.getName() << " weighs " << arturo.getWeight() << "." << endl;
	cout << "There are " << getPersonCount(); << " persons left." << endl;
}