#include <iostream>
using namespace std;

template <class T>
class Stack {
public:
	Stack(int n);
	~Stack();
	void Push(const T& item);
	void Pop();
	T Top() const;
	bool IsEmpty() const;
private:
	int top;
	T* info;
};

template <class T>
Stack<T>::Stack(int n) : top(0) {
	info = new T[n];
	for (int i = 0; i < n; i++)
		info[i] = NULL;
}

template <class T>
Stack<T>::~Stack() {
	top = 0;
	delete[] info;
}

template <class T>
void Stack<T>::Push(const T& item) {
	info[top++] = item;
}

template <class T>
void Stack<T>::Pop() {
	top--;
}

template <class T>
T Stack<T>::Top() const {
	return info[top - 1];
}

template <class T>
bool Stack<T>::IsEmpty() const {
	return top == 0;
}
/*
* Á¦·Î
*/
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int k;
	cin >> k;
	Stack<int> s(k);
	
	for (int i = 0; i < k; i++) {
		int num;
		cin >> num;
		if (num)
			s.Push(num);
		else
			s.Pop();
	}

	int sum = 0;
	while (!s.IsEmpty()) {
		sum += s.Top();
		s.Pop();
	}
	cout << sum;

	return 0;
}