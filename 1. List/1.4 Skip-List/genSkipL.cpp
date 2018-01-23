#include <iostream>
#include "genSkipL.h"
#include <list>
#include <string>
using namespace std;

int main(){
	SkipList<int> sl;
	sl.skipListInsert(10);
	sl.skipListInsert(14);
	cout << sl.skipListSearch(10) << endl;
	cout << sl.skipListSearch(11) << endl;

	

}