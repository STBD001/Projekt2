#include <iostream>
using namespace std;

class PriorityQueue {
private:

	struct Node
	{
		int value; //Wartość elementu 
		int priority; //Piorytet elementu
		Node(int v, int p) : value(v), priority(p) {}
	};
	Node** heapArray; //Tablica wskażników na elementy kopca
	int capacity; //Pojemność kopca
	int size; //Bieżący rozmiar kopca

	void swapNodes(Node*& a, Node*& b) {
		Node* temp = a;
		a = b;
		b = temp;
	}

	void heapifUp(int index) {
		if (index <= 0) return;
		int parentIndex = (index - 1) / 2;
		if (heapArray[index]->priority > heapArray[parentIndex]->priority) {
			swapNodes(heapArray[index], heapArray[parentIndex]);
			heapifUp(parentIndex);
		}
	}

	void heapifDown(int index) {
		int leftChild = 2 * index + 1;
		int rightChild = 2 * index + 2;
		int largest = index;

		if (leftChild<size && heapArray[leftChild]->priority > heapArray[largest]->priority)
			largest = leftChild;

		if (rightChild<size && heapArray[rightChild]->priority > heapArray[largest]->priority)
			largest = rightChild;

		if (largest != index) {
			swapNodes(heapArray[index], heapArray[largest]);
			heapifDown(largest);
		}
	}

public:
	PriorityQueue(int capacity) :capacity(capacity), size(0) {
		heapArray = new Node * [capacity];
	}

	~PriorityQueue() {
		for (int i = 0; i < size; ++i) {
			delete heapArray[i];
		}
		delete[] heapArray;
	}

	void insert(int e, int p) {
		if (size >= capacity) {
			cout << "Queue is full!\n";
			return;
		}
		heapArray[size] = new Node(e, p);
		heapifUp(size);
		size++;
	}

	int extractMax() {
		if (size == 0) {
			cout << "Kolejka jest pusta!" << endl;
			return 0; 
		}
		int maxValue = heapArray[0]->value;
		delete heapArray[0];
		heapArray[0] = heapArray[size - 1];
		size--;
		heapifDown(0);
		return maxValue;
	}

	int peek() const {
		if (size == 0) {
			cout << "Queue is full\n";
			return 0;
		}
		return heapArray[0]->value;
	}

	void modifyKey(int e, int p) {
		int index = -1;
		for (int i = 0; i < size; ++i) {
			if (heapArray[i]->value == e) {
				index = i;
				break;
			}
		}
		if (index == -1) {
			std::cerr << "Element nie został znaleziony!\n";
			return;
		}

		int oldPriority = heapArray[index]->priority;
		heapArray[index]->priority = p;
		if (p > oldPriority) {
			heapifUp(index);
		}
		else {
			heapifDown(index);
		}
	}

	int getSize() const {
		return size;
	}
};

int main()
{
	PriorityQueue test(10);

	test.insert(5, 2);
	test.insert(10, 1);
	test.insert(15, 3);

	cout << "Element o najwiekszy priorytet: " << test.peek() << endl;
	cout << "Rozmiar kolejki: " << test.getSize() << endl;

	test.modifyKey(10, 4);

	cout << "Element o najwiekszym priorytecie po modyfikacji: " << test.peek() << endl;

	cout << "Usuniety element o największym priorytecie: " << test.extractMax() << endl;

	cout << "Nowy element o najwiekszym priorytecie: " << test.peek() << endl;
	cout << "Rozmiar kolejki: " << test.getSize() << endl;
}

