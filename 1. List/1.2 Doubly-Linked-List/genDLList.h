#ifndef DOUBLY_LINKED_LIST
#define DOUBLY_LINKED_LIST

template<class T>
class DLLNode{
public:
	DLLNode(){
		prev = next = nullptr;
	}
	DLLNode(const T &el, DLLNode *n = 0, DLLNode *p = 0){
		info = el;
		next = n;
		prev = p;
	}

	T info;
	DLLNode<T> *next, *prev;
};


template<class T>
class DoublyLinkedList{
public:
	DoublyLinkedList(){
		head = tail = 0;
	}
	void addToDLLTail(const T &);
	T deleteFromTail();
	void addToDLLHead(const T &);
	T deleteFromHead();
	void deleteNode(const T &);
	bool isInList(const T &);
protected:
	DLLNode<T> *head, *tail;
};

#endif