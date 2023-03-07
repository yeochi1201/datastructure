#include <iostream>
using namespace std;

template <class T>
class queue {
private:
	int front = -1;
	int q_size = 100;
	T* my_queue = (T*)malloc(sizeof(T) * q_size);
public:
	void resize(){
		q_size += 100;
		my_queue = (T*)realloc(my_queue, sizeof(T) * q_size);
	}

	void push(T item) {
		if (front + 1 == q_size)
			resize();
		my_queue[++front] = item;
	}

	void pop() {
		if (front == -1) {
			return;
		}
		else {
			my_queue[0] == NULL;
			for (int i = 1; i <= front; i++)
				my_queue[i - 1] = my_queue[i];
			front--;
			return;
		}
	}

	int front() {
		return my_queue[front];
	}

	int back() {
		return my_queue[0];
	}

	int size() {
		return front + 1;
	}

	void empty() {
		if (front == -1)
			return true;
		else return false;
	}

	void full() {
		if (front + 1 == q_size)
			return true;
		else return false;
	}
};