#include <iostream>
#include <cstring>
using namespace std;

const int MAX_ITEMS = 100;
template <class T>
class Stack {
public:
	Stack();
	void Push(const T& item);
	void Pop();
	T Top() const;
	bool IsEmpty() const;
	void MakeEmpty();
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
T Stack<T>::Top() const {
	return info[top - 1];
}

template <class T>
bool Stack<T>::IsEmpty() const {
	return top == 0;
}

template <class T>
void Stack<T>::MakeEmpty() {
	top = 0;
}
/*
* °ýÈ£
*/
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int T;
	Stack<char> s;
	
	cin >> T;
	cin.ignore();
	while (T--) {
		bool balanced = true;
		char str[100];
		cin.getline(str, 100);

		for (int i = 0; i < strlen(str); i++) {
			if (str[i] == '(') s.Push(str[i]);
			if (str[i] == ')') {
				if (!s.IsEmpty() && (s.Top() == '(')) s.Pop();
				else {
					balanced = false;
					break;
				}
			}
		}

		if (balanced && s.IsEmpty())
			cout << "YES\n";
		else
			cout << "NO\n";
		s.MakeEmpty();
	}
	
	return 0;
}