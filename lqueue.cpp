#include"lqueue.h"
#include<iostream>
int main(){
	lqueue <int> *q=new lqueue<int>;
	int x;
	q->enqueue(1);
	q->display();
	q->enqueue(2);
	q->display();
	q->enqueue(3);
	q->display();
	q->enqueue(4);
	q->display();
	
	q->dequeue();
	q->display();
	q->enqueue(5);
	q->display();
	q->enqueue(6);
	q->display();
}
