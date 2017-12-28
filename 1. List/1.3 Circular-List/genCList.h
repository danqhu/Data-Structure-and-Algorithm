//************************ intSLList.h ********************
//    Circular List class 
#ifndef CIRCULAR_LIST
#define CIRCULAR_LIST
template<class T>
class genCLNode{
public:
	genCLNode(){
		next = prev = nullptr;
	}
	genCLNode(T el, genCLNode<T> *n = 0, genCLNode<T> *p = 0){
		info = el;
		next = n;
		prev = p;
	}

	T info;
	genCLNode<T> *next, *prev;
};



template<class T>
class genCList{
public:
	//构造函数
	genCList(){
		tail = nullptr;
	}
	//析构函数
	~genCList();
	//成员函数
	int isEmpty(){
		return tail == nullptr;
	}

	void addToTail(T);
	T deleteFromTail();
	void deleteNode(T);
	bool isInList(T) const;

private:
	genCLNode<T> *tail;
};

#endif