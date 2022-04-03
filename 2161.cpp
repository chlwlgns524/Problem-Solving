#include <iostream>
using namespace std;

template <class T> class Node;
template <class T>
class Queue {
public:
	Queue();
	~Queue();
	bool empty() const;
	const T& front() const;
	const T& back() const;
	void push(const T& item);
	void pop();
	int size() const;
private:
	Node<T>* frontNode;
	Node<T>* backNode;
	int queueSize;
};

template <class T>
class Node {
public:
	Node() : info(NULL), next(NULL) {}
	Node(const T& i, Node<T>* n) : info(i), next(n) {}

	friend class Queue<T>;
private:
	T info;
	Node<T>* next;
};
/*
* 카드1
* (큐 구현을 통한 풀이.)
*/
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	Queue<int> q;
	int n;

	cin >> n;
	for (int i = 1; i <= n; i++)
		q.push(i);

	while (1) {
		int top = q.front();
		
		q.pop();
		cout << top << " ";

		if (q.empty())
			return 0;
		else {
			top = q.front();
			q.pop();
			q.push(top);
		}
	}
}

template <class T>
Queue<T>::Queue() : 
	frontNode(NULL), backNode(NULL), queueSize(0) {}

template <class T>
Queue<T>::~Queue() {
	Node<T>* discard;
	
	while (frontNode != NULL) {
		discard = frontNode;
		frontNode = frontNode->next;
		delete discard;
	}

	backNode = NULL;
}

template <class T>
bool Queue<T>::empty() const {
	return frontNode == NULL;
}

template <class T>
const T& Queue<T>::front() const {
	return frontNode->info;
}

template <class T>
const T& Queue<T>::back() const {
	return backNode->info;
}

template <class T>
void Queue<T>::push(const T& item) {
	Node<T>* newNode;

	try {
		newNode = new Node<T>(item, NULL);
		if (empty())
			frontNode = backNode = newNode;
	
		else {
			backNode->next = newNode;
			backNode = backNode->next;
		}
		queueSize++;
	}
	catch (bad_alloc exception) {
		cerr << "heap is full\n";
	}
}

template <class T>
void Queue<T>::pop() {
	//Pre: There are more than one item in queue.
	frontNode = frontNode->next;

	if (frontNode == NULL)
		backNode = NULL;

	queueSize--;
}

template <class T>
int Queue<T>::size() const {
	return queueSize;
}