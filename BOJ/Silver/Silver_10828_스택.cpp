#include <iostream>
#include <string>
using namespace std;

typedef struct
{
    int top;
    int data[10001];
} Stack;

void init(Stack& s)
{
    s.top = -1;
}

bool isEmpty(Stack& s)
{
    return (s.top == -1);
}

void push(Stack& s, int item)
{
    s.data[++s.top] = item;
}

int pop(Stack& s)
{
    if (isEmpty(s)) return -1;
    return s.data[s.top--];
}

int top(Stack& s)
{
    if (isEmpty(s)) return -1;
    return s.data[s.top];
}

int size(Stack& s)
{
    if (isEmpty(s)) return 0;
    return (s.top + 1); //
}

Stack s;
string oList[5] = { "push", "pop", "size", "empty", "top" };
string order;

int main(void)
{
    int N, item;
    init(s);    // 스택 초기화
    cin >> N;
    for (auto i = 0; i < N; i++) {
        cin >> order;
        if (order == oList[0]) {
            cin >> item;
            push(s, item);
        }
        if (order == oList[1]) {
            cout << pop(s) << endl;
        }
        if (order == oList[2]) {
            cout << size(s) << endl;
        }
        if (order == oList[3]) {
            cout << isEmpty(s) << endl;
        }
        if (order == oList[4]) {
            cout << top(s) << endl;
        }
    }
    return 0;
}