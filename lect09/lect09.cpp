#include <iostream>
#include <array>
#include <vector>
#include <list>
#include <set>
#include <stack>
using namespace std;

//The C++ standard template library: contains a template for a bunch of data structures
//It has iterators that allow you to genericly iterate through them
class spell{
private:
	string name;
public:
	spell(string s){
		name = s;
	}
	void resolve(){
		cout << name << endl;
	}
};

class minStack{
private:
       	vector<int> stack;
	vector<int> mins;
public:
	void push(int value){
		stack.push_back(value);
		if(!mins.empty()){
			if(mins.back() > stack.back()){
				mins.push_back(stack.back());
			}
		}
		else{
			mins.push_back(stack.back());
		}
	}
	void pop(){
		if(mins.back() == stack.back()){
			mins.pop_back();
		}
		stack.pop_back();
	}
	int min(){
		return mins.back();
	}
	int top(){
		return stack.back();
	}
	bool empty(){
		if(stack.empty()){
			return true;
		}
		else{
			return false;
		}
	}
};


int main(){

	array<string, 4> countries = {"Snorsh", "Wakanda", "Britannia", "Guaido's Venezuela"};
	
	vector<string> continents;

	list<string> states;

	set<string> cities;

	cout << "Countries: " << endl;
	for(auto i : countries){
		cout << i << endl;
	}
	
	continents.push_back("Pangaea");
	states.push_back("Palau");
	cities.insert("Pendragon");
	cities.insert("Rapture");
	cities.insert("r/Pyongyang");


	stack<spell> the;
	spell counterspell = spell("Counterspell");
	spell lightning = spell("Lightning Bolt");
	the.push(lightning);
	the.push(counterspell);
	
	the.top().resolve();
	the.pop();
	the.top().resolve();
	the.pop();

	minStack test;
	test.push(5);
	test.push(1);
	test.push(2);
	test.push(-1);
	cout << test.min() <<endl;
	cout << test.top() <<endl;

	test.pop();
	cout << test.min() << endl;
	cout << test.top() << endl;

	return 0;
}
