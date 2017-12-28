#include <iostream>
#include <string>
#include "genCList.h"

using namespace std;

template<class T>
genCList<T>::~genCList(){
	if(tail != 0){
		genCLNode<T> *p;
		while(tail != tail->next){
			tail->prev->next = tail->next;
			tail->next->prev = tail->prev;
			p = tail->prev;
			cout << "ready to delete " << tail->info << endl;
			delete tail;
			cout << "delete successfully" << endl;
			tail = p;
		}
		delete tail;
		tail = 0;		
	}	
}


template<class T>
void genCList<T>::addToTail(T el){
	if(isEmpty()){
		tail = new genCLNode<T> (el);
		tail->next = tail;
		tail->prev = tail;
	}else{
		tail->next = new genCLNode<T> (el, tail->next, tail);
		tail = tail->next;
	}
}

template<class T>
T genCList<T>::deleteFromTail(){
	T tmp = tail->info;
	if(tail == tail->next){
		delete tail;
		tail = 0;
	}else{
		genCLNode<T> *tmp = tail->prev;
		tail->prev->next = tail->next;
		tail->next->prev = tail->prev;
		delete tail;
		tail = tmp;
	}

	return tmp;
}



int main(){

	genCList<string> list;
	list.addToTail("a");
	list.addToTail("bc");
	list.addToTail("def");
	cout << list.deleteFromTail() << endl;
	cout << list.deleteFromTail() << endl;
	cout << list.deleteFromTail() << endl;

	return 0;

}