using namespace std;
#include <iostream>

/* 4 friendly functions for classes (default exists if not implemented):
 * Constructor: For initialization, called right after creation of an object
 * Destructor: For an object's last words, called right before deletion of an object
 * Copy Constructor: Like a parameterized constructor, but it takes another object of that class to make a duplicate (Uses pass by reference, because pass by value would clone the object with a... copy constructor) 
 * Copy Assignment: When you assign one object to be something, the copy constructor is run again to assign the new object
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

class point{
	public:
		point(double newX=0, double newY=0);
		double getX(){return x;}
		double getY(){return y;}
		void setX(double newX){x = newX;}
		void setY(double newY){y = newY;}
	private:
		double x;
		double y;
};

point::point(double newX, double newY){
	x = newX;
	y = newY;
}

bool operator==(point &p1, point &p2){ //operator== is the function that is run for ==.  This is overloading that function
	if(p1.getX() == p2.getX() && p1.getY() == p2.getY()){ return true;}
}
point operator+(point &p1, point &p2){
	point p3(p1.getX() + p2.getX(), p1.getY() + p2.getY());
	return p3;
}
ostream& operator<<(ostream &out, point &p){
	out << "(" << p.getX() << ", " << p.getY() << ")";
	return out;
}
int main(){

	thing thing1("Thing 1");
	cout << "Made object " << thing1.getName() << endl;
	
	thing1.setAttribute(42);
	
	thing thing2(thing1); //Using copy constructor to make a copy of thing 1
	//Copy constructor would also be called with a straight assignment of thing2 = thing1 as well (copy assignment)

	thing2.setName("Thing 2");
	cout << "Made a copy of " << thing1.getName() << " , " << thing2.getName() << endl;
	//Both things have attribute that point to the same place on the heap, which is probably bad (Shallow Copy)


	string a, b;
	a = "Hello ";
	b = "World!";
	
	string c = a + b;
	cout << c << endl; // "+" operator overloaded to work with strings, "<<" has been overloaded to work with ostream objects and string objects

	point p1(42, 42);
	point p2(42, 42);

	if(p1 == p2) { //== overloaded here works
		cout << "p1 and p2 are equal" << endl;
	}
	
	cout << p1 << endl;

	return 0;
}
