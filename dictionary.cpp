#include <iostream>
using namespace std;

template <class T, class K>
class dictionary {
private:
	int size = 100;
	int top = 0;
	T* keys = (T*)malloc(sizeof(T) * size);
	K* values = (K*)malloc(sizeof(K) * size);
public:
	void resize() {
		size += 100;
		keys = (T*)realloc(keys, sizeof(T) * size);
		values = (K*)realloc(values, sizeof(K) * size);
	}

	void push(T key, K value) {
		if (top + 1 == size)
			resize();
		keys[top] = key;
		values[top] = value;
		top++;
	}

	void pop(T key) {
		int i;
		for (i = 0; i <= top; i++) {
			if (keys[i] == key) {
				keys[i] == NULL;
				values[i] == NULL;
				break;
			}
		}
		for (i+=1; i <= top; i++) {
			keys[i - 1] = keys[i];
		}
		top--;
		return;
	}

	T* ret_keys() {
		return keys;
	}

	K* ret_values() {
		return values;
	}

	int find(T key) {
		for (int idx = 0; idx <= top; idx++) {
			if (keys[i] == key) {
				cout << keys[i] << "   "<< values[i] << endl;
				return idx;
			}
		}
	}
};