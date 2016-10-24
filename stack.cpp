#include"stack.h"
#include<iostream>
int main(){
	stack <int> s(5);
	int x;
	s.push(1);
	s.push(2);
	s.push(3);
	s.push(4);
	s.push(5);
	s.push(6);//stack is full
	s.display();
	s.pop(x);
	cout<<endl<<x<<" is popped";
	s.pop(x);
	cout<<endl<<x<<" is popped";
	s.pop(x);
	cout<<endl<<x<<" is popped";
	s.pop(x);
	cout<<endl<<x<<" is popped";
	s.display();
}
