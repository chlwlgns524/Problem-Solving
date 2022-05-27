#define _CRT_SECURE_NO_WARNIGS
#include <iostream>
#include <cstring>
using namespace std;

const int MAX_ITEMS = 200;
template <class T>
class Stack {
public:
	Stack();
	void Push(const T& item);
	void Pop();
	T Top() const;
	void MakeEmpty();
	bool IsEmpty() const;
private:
	int top;
	T info[MAX_ITEMS];
};

template <class T>
Stack<T>::Stack() : top(0) {
	for (int i = 0; i < MAX_ITEMS; i++)
		info[i] = NULL;
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
void Stack<T>::MakeEmpty() {
	top = 0;
}

template <class T>
bool Stack<T>::IsEmpty() const {
	return top == 0;
}

template <class T>
T Stack<T>::Top() const {
	return info[top - 1];
}
/*
* ±ÕÇüÀâÈù ¼¼»ó
*/
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	Stack<char> s;
	while (1) {
		bool balanced = true;
		char str[101];
		cin.getline(str, 101);

		if (!strcmp(str, ".")) break;

		for (int i = 0; str[i] != '.'; i++) {
			if (str[i] == '(' || str[i] == '[') s.Push(str[i]);
			if (str[i] == ')') {
				if (!s.IsEmpty() && s.Top() == '(') s.Pop();
				else {
					balanced = false;
					break;
				}
			}
			if (str[i] == ']') {
				if (!s.IsEmpty() && s.Top() == '[') s.Pop();
				else {
					balanced = false;
					break;
				}
			}
		}

		if (balanced && s.IsEmpty()) cout << "yes\n";
		else cout << "no\n";
		s.MakeEmpty();
	}

	return 0;
}