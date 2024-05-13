#include "PriorityQueue.h"

class PriorityQueue1 : public PriorityQueue {
private:
    struct Node {
        int element;    // Element węzła
        int priority;   // Priorytet węzła
    };

    Node* heapArray;    // Tablica przechowująca kopiec
    int capacity;       // Pojemność tablicy
    int size;           // Aktualny rozmiar kopca

    void swap(Node& a, Node& b); // Zamienia zawartość dwóch węzłów

    void heapifyUp(int index);     // Przywraca własność kopca w górę od danego indeksu

    void heapifyDown(int index);     // Przywraca własność kopca w dół od danego indeksu

    void resizeHeapArray();     // Zmienia rozmiar tablicy kopca

public:
    PriorityQueue1() : size(0), capacity(1) {
        heapArray = new Node[capacity];
    }

    PriorityQueue1(int initialCapacity) : capacity(initialCapacity), size(0) {    // Konstruktor z możliwością określenia początkowej pojemności
        heapArray = new Node[capacity];
    }

    ~PriorityQueue1() {
        delete[] heapArray;
    }

    void insert(int element, int priority) override; // Wstawia nowy element z określonym priorytetem do kolejki

    int extractMax() override;     // Usuwa i zwraca element o najwyższym priorytecie z kolejki

    int findMax() const override;     // Zwraca element o najwyższym priorytecie bez usuwania go z kolejki

    void modifyKey(int element, int newPriority) override; // Modyfikuje priorytet danego elementu w kolejce

    int returnSize() const override {     // Zwraca aktualny rozmiar kolejki
        return size;
    }

    int returnLos(int priority) const override;     // Zwraca element o określonym priorytecie w kolejce

    void queueState() const override;     // Wyświetla stan kolejki (do celów diagnostycznych)
}; 
