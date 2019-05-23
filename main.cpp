#include <iostream>
#include "tree.cpp"
using namespace std;

int main() 
{
	tree<char> t1('a');
	t1.INSERT('b');
	t1.INSERT('c');
	t1.INSERT('g');
	t1.INSERT('t');
	t1.INSERT('h');
	t1.REMOVE('z');
	t1.HEIGHT();
	t1.PRINT();
	cout<<endl;
	t1.EXISTS('a');
	t1.EXISTS('z');
	cout<<endl<<endl;
	
	tree<int> t2(5);
	t2.INSERT(-100);
	t2.INSERT(36);
	t2.INSERT(53);
	t2.INSERT(23);
	t2.INSERT(636);
	t2.INSERT(66);
	t2.REMOVE(6);
	t2.HEIGHT();
	t2.PRINT();
	cout<<endl;
	t2.EXISTS(23);
	t2.EXISTS(156);
	return 0;
}
