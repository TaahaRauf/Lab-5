#include <iostream>
using namespace std;

class Array {
private:
	int* data;
	int capacity;
	int isValidIndex(int index) {
		if (index <= capacity && index >= 0) {
			return 1;
		}
		return 0;
	};
public:
	Array( int cap = 5) {
		capacity = cap;
		data = new int[capacity];

	}
	~ Array() {
		delete[] data;
		data = nullptr;
	}
	int& getValue(int index) {
		return data[index];
	}
	const int& getvalue(int index) const {
		return data[index];
	}
	int setValue(int index,int value) {
		data[index] = value;
	}
	int getCapacity() {
		return capacity;
	}
	void reSize(int newcapacity) {
		int* newarr = new int[newcapacity];
		for (int i = 0; i < capacity; i++) {
			newarr[i] = data[i];
		}
		delete[] data;
		data = newarr;
		newarr = nullptr;
		
	}
	Array( Array & a) {
		capacity = a.capacity;
		data = new int[capacity];
		for (int i = 0; i < capacity; i++) {
			data[i] = a.data[i];
		}


	}
	void display() {
		for (int i = 0; i < capacity; i++) {
			cout << data[i] << " ";
		}
	}
	Array& operator = (const Array& obj) {
		capacity = obj.capacity;
		for (int i = 0; i < capacity; i++) {
			obj.data[i] = data[i];
		}
	}

};
int main() {

}
