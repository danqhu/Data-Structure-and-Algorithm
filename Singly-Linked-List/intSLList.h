//************************ intSLList.h ********************
//    singly-Linked List class to store integers
#ifndef INT_LINKED_LIST
#define INT_LINKED_LIST

class IntSLLNode{
public:
	IntSLLNode(){
		next = nullptr;
	}
	IntSLLNode(int el, IntSLLNode *ptr = nullptr){
		info = el;
		next = ptr;
	}

	int info;
	IntSLLNode *next;
};


class IntSLList{
public:
	//构造函数
	IntSLList(){
		head = tail = nullptr;
	}
	//析构函数
	~IntSLList();
	//成员函数
	int isEmpty(){
		return head == nullptr;
	}
	void addToHead(int);
	void addToTail(int);
	int deleteFromHead();
	int deleteFromTail();
	void deleteNode(int);
	bool isInList(int) const;

private:
	IntSLLNode *head, *tail;
};

#endif