#include "PriorityQueue1.h"

void PriorityQueue1::swap(Node& a, Node& b) // Funkcja zamieniaj�ca zawarto�� dw�ch w�z��w
{
    Node temp = a;
    a = b;
    b = temp;
}

void PriorityQueue1::heapifyUp(int index) // Funkcja przywracaj�ca w�asno�� kopca w g�r� od danego indeksu
{
    while (index > 0 && heapArray[(index - 1) / 2].priority < heapArray[index].priority) {
        swap(heapArray[(index - 1) / 2], heapArray[index]);
        index = (index - 1) / 2;
    }
}
 
void PriorityQueue1::heapifyDown(int index) // Funkcja przywracaj�ca w�asno�� kopca w d� od danego indeksu
{
    int maxIndex = index;
    int leftChild = 2 * index + 1;
    int rightChild = 2 * index + 2;

    if (leftChild < size && heapArray[leftChild].priority > heapArray[maxIndex].priority)
        maxIndex = leftChild;

    if (rightChild < size && heapArray[rightChild].priority > heapArray[maxIndex].priority)
        maxIndex = rightChild;

    if (index != maxIndex) {
        swap(heapArray[index], heapArray[maxIndex]);
        heapifyDown(maxIndex);
    }
}

void PriorityQueue1::resizeHeapArray() { // Funkcja zmieniaj�ca rozmiar tablicy kopca
    int newCapacity = capacity * 2;
    Node* newHeapArray = new Node[newCapacity];
    for (int i = 0; i < capacity; ++i) {
        newHeapArray[i] = heapArray[i];
    }
    delete[] heapArray;
    heapArray = newHeapArray;
    capacity = newCapacity;
}

void PriorityQueue1::insert(int element, int priority) { // Wstawianie nowego elementu z okre�lonym priorytetem do kolejki
    if (size == capacity) {
        resizeHeapArray();
    }

    heapArray[size].element = element;
    heapArray[size].priority = priority;
    heapifyUp(size);
    size++;
}

int PriorityQueue1::extractMax() { // Usuwanie i zwracanie elementu o najwy�szym priorytecie z kolejki
    if (size == 0)
        throw std::underflow_error("Priority queue is empty");

    int maxElement = heapArray[0].element;
    heapArray[0] = heapArray[size - 1];
    size--;
    heapifyDown(0);

    return maxElement;
}

int PriorityQueue1::findMax() const { // Zwracanie elementu o najwy�szym priorytecie bez usuwania go z kolejki
    if (size == 0)
        throw std::underflow_error("Priority queue is empty");

    return heapArray[0].element;
}


void PriorityQueue1::modifyKey(int element, int newPriority) { // Modyfikowanie priorytetu danego elementu w kolejce
    int index = -1;
    for (int i = 0; i < size; i++) {
        if (heapArray[i].element == element) {
            index = i;
            break;
        }
    }

    if (index == -1)
        throw std::invalid_argument("Element not found");

    if (newPriority > heapArray[index].priority) {
        heapArray[index].priority = newPriority;
        heapifyUp(index);
    }
    else {
        heapArray[index].priority = newPriority;
        heapifyDown(index);
    }
}

void PriorityQueue1::queueState() const // Wy�wietlanie stanu kolejki (do cel�w diagnostycznych)
{
    for (int i = 0; i < size; i++) {
        std::cout << "Element: " << heapArray[i].element << " Priority: " << heapArray[i].priority << "\n";
    }
}

int PriorityQueue1::returnLos(int priority) const // Zwracanie losowego elementu o okre�lonym priorytecie w kolejce
{
    return 0; 
}
