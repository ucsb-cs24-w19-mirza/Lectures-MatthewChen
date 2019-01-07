#include <iostream>
using namespace std;

class Date{
	int day;
	int month;
	
	public:
		void setDate(int d, int m){	
			day = d;
			month = m;
		}

		int getDay(){
			return day;
		}

		int getMonth(){
			return month;
		}

};

int main(){

	Date birthday;
	birthday.setDate(21, 12);

	cout << birthday.getMonth() << "/" << birthday.getDay() << endl;

	return 0;
}
