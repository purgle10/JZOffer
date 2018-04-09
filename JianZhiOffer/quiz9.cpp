#include<iostream>
#include<stack>
using namespace std;

template<typename type>
class Queue{
private:
	stack<type> st1;
	stack<type> st2;
public:
	void appendTail(type add);
	type deleteHead();
	Queue() :st1(), st2(){};
	~Queue(){};
};

template<typename type>
void Queue::appendTail(type add){
	st1.push(add);
}

template<typename type>
type Queue::deleteHead(){
	if (st1.empty())
		throw new std::exception("queue is empty.");
	while (!st1.empty())
	{
		st2.push(st1.top());
		st1.pop();
	}
	type Head = st2.top();
	st2.pop();
	while (!st2.empty()){
		st1.push(st2.top());
		st2.pop();
	}
	return Head;
}

int main(){
	Queue<int> q;
	q.appendTail(1);
	q.appendTail(2);
	q.deleteHead();
}