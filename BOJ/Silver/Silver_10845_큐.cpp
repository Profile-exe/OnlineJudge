#include <iostream>
using namespace std;

typedef struct
{
	int front;
	int rear;
	int data[10001];
} Queue;

void init(Queue& q)
{
	q.front = 0;
	q.rear = 0;
}

bool isEmpty(Queue& q)
{
	if (q.front == q.rear) return true;
	else				   return false;
}

void push(Queue& q, int item)
{
	q.data[q.rear++] = item;
}

int pop(Queue& q)
{
	if (isEmpty(q)) return -1;
	return q.data[q.front++];
}

int front(Queue& q)
{
	if (isEmpty(q)) return -1;
	return q.data[q.front];
}

int rear(Queue& q)
{
	if (isEmpty(q)) return -1;
	return q.data[q.rear - 1];
}

int size(Queue& q)
{
	if (isEmpty(q)) return 0;
	return (q.rear - q.front);
}

Queue q;
string oList[6] = { "push", "pop", "size", "empty", "front", "back" };
string order;

int main(void)
{
	int N, item;
	cin >> N;
	for (auto i = 0; i < N; i++) {
		cin >> order;
		if (order == oList[0]) {
			cin >> item;
			push(q, item);
		}
		if (order == oList[1]) {
			cout << pop(q) << endl;
		}
		if (order == oList[2]) {
			cout << size(q) << endl;
		}
		if (order == oList[3]) {
			cout << isEmpty(q) << endl;
		}
		if (order == oList[4]) {
			cout << front(q) << endl;
		}
		if (order == oList[5]) {
			cout << rear(q) << endl;
		}
	}
	return 0;
}