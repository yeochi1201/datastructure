#include <iostream>
using namespace std;

template <class T>
class stack {
private:
	int s_size = 100;
	T* my_stack = (T*)malloc(sizeof(T) * s_size);
	int top = -1;
public:
	void resize() {
		s_size += 100;
		my_stack = (T*)realloc(my_stack, sizeof(T) * s_size);
	}
	bool empty() {
		if (top == -1) return true;
		else return false;
	}
	bool full() {
		if (top + 1 == s_size) {
			return true;
		}
		else return false;
	}
	void push(T a) {
		if (full())
			resize();
		my_stack[++top] = a;
	}
	void pop() {
		if (empty()) return;
		else {
			my_stack[top--] = NULL;
		}
	}
	T front() {
		if (empty())return -1;
		else return my_stack[top];
	}
	int size() {
		return top + 1;
	}
	void print() {
		for (int i = 0; i <= top; i++)
			cout << my_stack[i] << "  ";
	}
};

int main()
{
	int sw, item;
	stack<int> Stack = stack<int>();
	while (true)
	{
		cout << "1.push 2.pop 3.empty 4.full 5.front 6.size 7.print" << endl;
		cin >> sw;
		switch (sw) {
		case 1:
			cin >> item;
			Stack.push(item);
			break;
		case 2:
			Stack.pop();
			break;
		case 3:
			cout << Stack.empty();
			break;
		case 4:
			cout << Stack.full();
			break;
		case 5:
			cout << Stack.front();
			break;
		case 6:
			cout << Stack.size();
			break;
		case 7:
			Stack.print();
		}
		if (sw == -1)
			return 0;
		cout << endl;
	}
}