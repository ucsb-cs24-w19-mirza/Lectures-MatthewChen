using namespace std;
#include <iostream>

template <class T> //T is a generic data type that gets assigned at runtime
T maximum(T a, T b){
	if(a > b){
		return a;
	}
	else{
		return b;
	}
}

template <class T>
class Pair{
private:
	T first;
	T second;
public:
	Pair(T first, T second){
		this->first = first;
		this->second = second;
	}
	void setFirst(T value){
		first = value;
	}
	void setSecond(T value){
		second = value;
	}
	T getFirst(){return first;}
	T getSecond(){return second;}
};

int main(){

	cout << maximum(1, 2) << endl;
	Pair<int> p(3,4); //using <type> to assign the type for the template

	Pair<string> *pointerToPair = new Pair<string>("Yo", "Dude");
	cout << pointerToPair->getFirst() <<endl;
	return 0;
}
