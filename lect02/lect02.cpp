#include <iostream>
using namespace std;

class dayOfYear{

	private: //Hiding information like this makes this an Abstract Data Type (ADT)
		int day;
		int month; //Cannot initialize values here because this code is never "run", needs constructor

	public:
		dayOfYear(){
			day = 1;
			month = 1;
		}
		dayOfYear(int m = 1, int d = 1); //Parameterized constructor with default values
		void setDate(int m, int d);
		void input();
		int getDay()const{return day;} //Constant Functions: keeps stuff constant while in the scope
		int getMonth()const{return month;}
};

dayOfYear::dayOfYear(int m, int d){
	day = d;
	month = m;
}

void dayOfYear::setDate(int m, int d){ //Non-inline definition of function for when declarations are in a header
	day = d;
	month = m;
}

void dayOfYear::input(){
	cin>>day>>month;
}


int main(){
	dayOfYear date(1, 42);

	//date.setDate(42, 42);

	cout << date.getMonth() << "/" << date.getDay() <<endl;

	return 0;
}
