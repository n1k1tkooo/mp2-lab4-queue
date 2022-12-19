#ifndef __QUEUE_H__
#define __QUEUE_H__

const int MAX_SIZE_QUEUE = 50;
const int MIN_SIZE_QUEUE = 5;
using namespace std;

template <class T>
class Queue {
	T* pMem;
	int size;
	int top;
public:
	Queue(int _Size) {
		size = _Size;  
		top = -1;
		if ((size > MAX_SIZE_QUEUE) || (size < MIN_SIZE_QUEUE)) { throw size; }
		pMem = new T[size];
	}

	void push(const T _Elem) { 
		if (isFull() == true) { throw exception(); }
		else {
			top = top + 1;
			pMem[top] = _Elem;
		}
	}

	T change() { 
		if (isEmpty() == true) { throw exception(); }
		else {
			T Task = pMem[0];
			for (int i = 0; i < top; i++) { pMem[i] = pMem[i + 1]; }
			top = top - 1;
			return Task;
		}
	}

	T get() { 
		if (isEmpty()) { throw "Empty"; }
		return pMem[0];
	}

	int isEmpty(void) const { return top == -1; }
	int count() { return top + 1; };
	int isFull(void) const { return top == size - 1; }
	~Queue() { delete[] pMem; }
	int getSize() { return size; }
};

#endif
