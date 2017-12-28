#include <iostream>
#include "intSLList.h"
using namespace std;

IntSLList::~IntSLList(){
	for(IntSLLNode *p; !isEmpty();){
		p = head->next;
		delete head;
		head = p;
	}
}


void IntSLList::addToHead(int el){
	head = new IntSLLNode(el, head);
	if(tail == nullptr)
		tail = head;
}

void IntSLList::addToTail(int el){
	if(tail != 0){
		tail->next = new IntSLLNode(el);
		tail = tail->next;
	}else{
		head = tail = new IntSLLNode(el);
	}
}

int IntSLList::deleteFromHead(){
	int el = head->info;
	IntSLLNode *tmp = head;
	if(head == tail){
		head = tail = nullptr;
	}else{
		head = head->next;
	}
	delete tmp;

	return el;
}

int IntSLList::deleteFromTail(){
	int el = tail->info;
	if(head == tail){
		delete head;
		head = tail = nullptr;
	}else{
		IntSLLNode *tmp;
		for(tmp = head; tmp->next != tail; tmp = tmp->next);
		delete tail;
		tail = tmp;
		tail->next = nullptr;
	}

	return el;
}

void IntSLList::deleteNode(int el){
	if(head != nullptr){
		if(head == tail && el == head->info){
			delete head;
			head = tail = nullptr;
		}else if(el == head->info){
			IntSLLNode *tmp = head;
			head = head->next;
			delete tmp;
		}else{
			IntSLLNode *pred, *tmp;
			for(pred = head, tmp = head->next; tmp != nullptr && !(tmp->info == el); pred = pred->next, tmp = tmp->next);
			if(tmp != nullptr){
				pred->next = tmp->next;
				if(tmp == tail)
					tail = pred;
				delete tmp;
			}
		}
	}
}

bool IntSLList::isInList(int el) const {
	IntSLLNode *tmp;
	for(tmp = head; tmp != nullptr && tmp->info != el; tmp = tmp->next);
	return tmp != nullptr;
}





int main(int argc, char *argv[]){


	IntSLList list;
	list.addToTail(1);
	list.addToTail(2);
	list.addToTail(3);                   
	IntSLLNode *tmp;
	list.deleteNode(3);
	cout << list.isInList(1) << list.isInList(2) << list.isInList(3) << endl;
	cout << list.deleteFromTail()  << endl;

}