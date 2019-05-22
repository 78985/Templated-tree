#include <iostream>
#include "tree.cpp"
using namespace std;

int main() 
{
	tree<char> t1('a');
	t1.INSERT('b');
	t1.INSERT('c');
	t1.INSERT('h');
	t1.INSERT('e');
	t1.INSERT('z');
	t1.REMOVE('z');
	t1.HEIGHT();
	t1.PRINT();
	cout<<endl;
	t1.EXISTS('e');
	t1.EXISTS('z');
	cout<<endl<<endl;
	
	tree<int> t2(5);
	t2.INSERT(3);
	t2.INSERT(356);
	t2.INSERT(53);
	t2.INSERT(23);
	t2.INSERT(34532);
	t2.REMOVE(6);
	t2.HEIGHT();
	t2.PRINT();
	cout<<endl;
	t2.EXISTS(356);
	t2.EXISTS(123);
	return 0;
}
