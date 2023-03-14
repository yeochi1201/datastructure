#include <iostream>

using namespace std;

template<typename T>
struct node {
	T data = NULL;
	T* link = NULL;

	node() {
		T data = NULL;
		T* link = NULL;
	}
};

template <typename T>
class linkedlist {
private:
	node<T> head = new node<T>;
	int size = 0;

public:
	linkedlist() {
		head.data = NULL;
		head.link = NULL;
	}

	void pushback(T item) {
		node<T> temp = new node<T>;
		node<T> ptr = search(size);

		temp.data = item;
		ptr.link = temp;
		size++;
		return;
	}

	void pushfront(T item) {
		node<T> temp = new node<T>;
		temp.data = item;
		node<T> next = head.link;

		head.link = temp;
		temp.link = next;
		size++;
		return;
	}

	void insertpush(T item, int num) {
		if (num > size)
			pushback(item);
		return;
		node<T> temp = new node<T>;
		temp.data = item;

		node<T> prev = search(num - 1);

		node<T> next = search(num);

		prev.link = temp;
		temp.link = next;
		size++;
		return;
	}

	void deletenode(int num) {
		if (num >= size) {
			node<T> prev = search(size - 1);
			node<T> temp = prev.link;
			delete(temp);
			prev.link = NULL;
			size--;
			return;
		}
		node<T> prev = search(num - 1);
		node<T> next = search(num);
		node<T> temp = prev.link;
		delete(temp);

		prev.link = next;
		size--;
		return;
	}

	node<T> search(int num) {
		node<T> find = head;
		for (int i = 0; i < num; i++) {
			find = &(find.link);
		}
		return find;
	}

	void display() {
		node<T> temp = &head;
		for (int i = 0; i < size; i++) {
			temp = &(temp.next);
			cout << temp.data << "\n";
		}
		return;
	}
};

int main() {
	linkedlist<int> lk = linkedlist<int>();
	lk.pushfront(2);
	lk.display();
	lk.pushfront(1);
	lk.display();
	lk.pushback(3);
	lk.display();
	lk.pushback(4);
	lk.display();
}