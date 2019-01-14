using namespace std;
#include <iostream>

/* 4 friendly functions for classes (default exists if not implemented):
 * Constructor: For initialization, called right after creation of an object
 * Destructor: For an object's last words, called right before deletion of an object
 * Copy Constructor: Like a parameterized constructor, but it takes another object of that class to make a duplicate (Uses pass by reference, because pass by value would clone the object with a... copy constructor) 
 * Copy Assignment:
 */


class thing{
	public:
		thing(){
			attribute = new int;
		}
		thing(string thingName):name(thingName){// Constructor with initialization list
			attribute = new int;
		}
		~thing(); //Destructor: starts with ~
		string getName(){return name;}
		void setName(string n){name = n;}
		int getAttribute(){return *attribute;}
		void setAttribute(int a){*attribute = a;}
	private:
		string name;
		int* attribute;

};

thing::~thing(){
	//Do destructor things here, member variables still available
	cout << name << " is being destroyed" << endl;
	delete attribute;
}

int main(){

	thing thing1("Thing 1");
	cout << "Made object " << thing1.getName() << endl;
	
	thing1.setAttribute(42);
	
	thing thing2(thing1); //Using copy constructor to make a copy of thing 1

	thing2.setName("Thing 2");
	cout << "Made a copy of " << thing1.getName() << " , " << thing2.getName() << endl;
	//Both things have attribute that point to the same place on the heap, which is probably bad (Shallow Copy)

	return 0;
}
