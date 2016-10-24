#include"lstack.h"
#include<iostream>
int main(){
	lstack <int>*s=new lstack<int>(5);
	s->push(1);
	s->push(2);
	s->push(3);
	s->push(4);
	s->push(5);
	s->push(6);//stack is full
		
	s->print();
	
	s->pop();
	s->pop();
	s->pop();
	s->pop();
	s->print();
}
