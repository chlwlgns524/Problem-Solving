#include <iostream>
#include <string>
using namespace std;

template <class T> class Stack;
template <class T>
class Node {
public:
	Node(const T& v, Node<T>* n) : value(v), next(n) {}
	friend class Stack<T>;
private:
	T value;
	Node<T>* next;
};

template <class T>
class Stack {
public:
	Stack();
	~Stack();
	void Push(const T& item);
	void Pop();
	T Top() const;
	bool IsEmpty() const;
	void MakeEmpty();
private:
	Node<T>* top;
};

template <class T>
Stack<T>::Stack() : top(nullptr) {}

template <class T>
Stack<T>::~Stack() {
	MakeEmpty();
}

template <class T>
void Stack<T>::Push(const T& item) {
	top = new Node<T>(item, top);
}

template <class T>
void Stack<T>::Pop() {
	Node<T>* discard = top;
	top = top->next;
	delete discard;
}

template <class T>
T Stack<T>::Top() const {
	return top->value;
}

template <class T>
bool Stack<T>::IsEmpty() const {
	return top == nullptr;
}

template <class T>
void Stack<T>::MakeEmpty() {
	while (!IsEmpty()) Pop();
}
/*
* 스택 수열
*/
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	Stack<int> sim;
	string op;
	bool possible = true;
	int n;
	cin >> n;
	
	int* series = new int[n];
	for (int i = 0; i < n; i++)
		cin >> series[i];
	
	int i = 1, j = 0;
	while (j < n) {
		if (!sim.IsEmpty()) {
			if (sim.Top() == series[j]) {
				sim.Pop();
				op += '-';
				j++;
				continue;
			}
			else if (sim.Top() > series[j]) {
				possible = false;
				break;
			}
		}
		sim.Push(i++);
		op += '+';
	}

	if (possible) {
		for (unsigned int i = 0; i < op.length(); i++)
			cout << op[i] << "\n";
	}
	else
		cout << "NO\n";

	return 0;
}