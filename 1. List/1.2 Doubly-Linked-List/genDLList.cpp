#include <iostream>
#include "genDLList.h"
using namespace std;

template<class T>
void DoublyLinkedList<T>::addToDLLTail(const T &el){
	if(tail != 0){
		tail = new DLLNode<T>(el, 0, tail);
		tail->prev->next = tail;
	}else{
		head = tail = new DLLNode<T>(el);
	}
}

template<class T>
T DoublyLinkedList<T>::deleteFromTail(){
	T el = tail->info;
	if(head == tail){
		delete head;
		head = tail = 0;
	}else{
		tail = tail->prev;
		delete tail->next;
		tail->next = 0;
	}

	return el;
}

template<class T>
void DoublyLinkedList<T>::addToDLLHead(const T &el){
	if(head != 0){
		head = new DLLNode<T>(el, head, 0);
		head->next->prev = head;
	}else{
		head = tail = new DLLNode<T>(el);
	}
}


template<class T>
T DoublyLinkedList<T>::deleteFromHead(){
	T el = head->info;
	if(head == tail){
		delete head;
		head = tail = 0;
	}else{
		head = head->next;
		delete head->prev;
		head->prev = 0;
	}
}

template<class T>
void DoublyLinkedList<T>::deleteNode(const T &el){
	if(head != 0){	
		if(head == tail && head->info == el){
			delete head;
			head = tail = 0;
		}else if( head->info == el){                     
			head = head->next;
			delete head->prev;
			head->prev = 0;
		}else{
			DLLNode<T> *tmp;
			for(tmp = head->next; tmp != 0 && tmp->info != el; tmp = tmp->next);
			if(tmp != 0){
				tmp->prev->next = tmp->next;
				if(tmp != tail)
					tmp->next->prev = tmp->prev;
				else{
					tail = tmp->prev;
					tail->next = 0;
				}

				delete tmp;
			}
		}
	}
}

template<class T>
bool DoublyLinkedList<T>::isInList(const T &el){
	DLLNode<T> *tmp;
	for(tmp = head; tmp != 0 && tmp->info != el; tmp = tmp->next);

	return tmp != 0;	
}




int main(int argc, char *argv[]){
	DoublyLinkedList<int> list;
	list.addToDLLTail(1);
	list.addToDLLTail(2);
	list.addToDLLTail(3);                   
	list.deleteNode(3);
	cout << list.isInList(1) << list.isInList(2) << list.isInList(3) << endl;
	cout << list.deleteFromTail()  << endl;
	cout << list.deleteFromTail()  << endl;

}