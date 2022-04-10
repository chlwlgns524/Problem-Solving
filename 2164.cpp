#define _CRT_SECURE_NO_WARNIGS
#include <iostream>
using namespace std;

template <class T>
class Queue {
public:
	Queue(int n);
	void Enqueue(const T& item);
	T Dequeue();
	int GetSize() const;
private:
	T* info;
	int front;
	int rear;
	int capacity;
	int size;
};

template <class T>
Queue<T>::Queue(int n) : size(n), capacity(n + 1), front(0), rear(n) {
	info = new T[capacity];
	for (int i = 0; i < capacity; i++)
		info[i] = i + 1;
}

template <class T>
void Queue<T>::Enqueue(const T& item) {
	info[rear] = item;
	rear = (rear + 1) % capacity;
	size++;
}

template <class T>
T Queue<T>::Dequeue() {
	T result = info[front];
	front = (front + 1) % capacity;
	size--;
	return result;
}

template <class T>
int Queue<T>::GetSize() const {
	return size;
}
/*
* Ä«µå2
*/
int main() {
	int N;
	cin >> N;
	Queue<int> q(N);

	if (N != 1) {
		do {
			q.Dequeue();
			int b = q.Dequeue();
			q.Enqueue(b);
		} while (q.GetSize() != 1);
	}
	int ans = q.Dequeue();
	cout << ans;

	return 0;
}