#include <iostream>
using namespace std;

//Back to Linked Lists
class linkedList{
	private:
		struct Node{
			int data;
			Node* next;
		};
		Node* head;
		Node* tail;
	public:
		linkedList():head(NULL), tail(NULL){}	
		~linkedList(){
			deleteList();
		}
		void append(int value){

			Node* end = new Node;
			end->next = NULL;
			end->data = value;
	
			if(head){
				tail->next = end;
				tail = end;
			}
			else{
				head = end;
				tail = end;	
			}

		}

		void printList()const{
			Node* p = head;

			while(p){
				cout << p->data << " ";
				p = p->next;
			}
			cout << endl;
		}

		void deleteList(){
			Node* p = head;
			Node* next;

			if(p->next){ 
				next = p->next;

				while(p){
					delete p;
					p = next;
					next = p->next;
					
				}
			}
			else{
				delete p;
			}
			head = NULL;
			tail = NULL;

		}	

};

int main(){

	linkedList list;

	list.append(42);
	list.append(69);
	list.printList();	
	
	//list.deleteList();

	return 0;
}
