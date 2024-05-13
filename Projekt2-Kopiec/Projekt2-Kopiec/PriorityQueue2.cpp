#include "PriorityQueue2.h"

// idealnie bez size????
void PriorityQueue2::insert(int element, int priority) {
    Node* newNode = new Node(element, priority); // basic insert in LinkedList
    //tu bys rozumial ze sie bagowalo przy pustej, skoro nie dodajemy w konstruktorze zadnej Node to sprawdz czy lista jest 
    // pusta ALBO dodajemy Node z wyzszym priorytetem
    if (head == nullptr ) { // || priority > head->priority 
        newNode->next = head;
        head = newNode;
    }
    // jesli nie to standardowe dodanie z listy
    else {
        Node* current = head;
        while (current->next != nullptr) { //&& current->next->priority >= priority
            // ew sasiad po prawej moze miec priorytet wiekszy niz nasz dlatego --^
            current = current->next;
        }
        newNode->next = current->next;
        current->next = newNode;
    }
    size++;
}

//int PriorityQueue2::extractMax() {

//    // prosty pop pierwszy element
//    //    Node* temp = *head;  
//    //    (*head) = (*head)->next;
//    //    free(temp);
//    Node* temp = head;
//    int maxElement = temp->value;
//    head = head->next;
//    delete temp;
//    size--;
//    return maxElement;
//}
int PriorityQueue2::extractMax() {

    Node* current = head;
    Node* maxNode = head;
    int maxPriority = head->priority;

    // defaultny za traversing listą i znalezienie maksymalnego, w każdym razie całą listę przeszuka
    while (current != nullptr) {
        if (current->priority > maxPriority) {
            maxPriority = current->priority;
            maxNode = current;
        }
        current = current->next;
    }

    int maxElement = maxNode->value;

    if (maxNode == head) {
        head = head->next;
    }
    else {
        current = head;
        while (current->next != maxNode) {
            current = current->next;
        }
        current->next = maxNode->next;
    }

    delete maxNode;
    size--;
    return maxElement;
}

//int PriorityQueue2::findMax() const {
//    if (size == 0)// (head=nullptr)
//        throw std::underflow_error("Priority queue is empty");
//
//    return head->value;
//}

int PriorityQueue2::findMax() const {

    Node* current = head;
    int maxPriority = head->priority;
    int maxElement = head->value;

    while (current != nullptr) {
        if (current->priority > maxPriority) {
            maxPriority = current->priority;
            maxElement = current->value;
        }
        current = current->next;
    }

    return maxElement;
}

void PriorityQueue2::modifyKey(int element, int newPriority) {
    Node* current = head;
    while (current != nullptr && current->value != element) {
        current = current->next;
    }
    // dojdzie do momentu gdy "prawdopodobnie" current->value = element i obw 2 przypadki
    
    //jakby nie znalazlo
    if (current == nullptr)
        throw std::invalid_argument("Element not found");
    //throw w tym sensie wywali program??? i nie dojdzie do następnej linijki

    // znalazlo i sie zamienia
    current->priority = newPriority;
}

void PriorityQueue2::queueState() const
{
    // tak podstawowo bo bralem kod z projektu 1 w przesuwaniu się listą
    // moim zdaniem nie trzeba jeszcze uwzgledniac tu priorytetow
    Node* current = head;
    while (current != nullptr) {

        std::cout << "ELEMENT: "<< current->value << " PRIORITY: " << current->priority << " \n";    
        current = current->next;
    }
   
}

//int PriorityQueue2::priorityOnList(int random) const
//{
//    return 0;
//}

int PriorityQueue2::returnLos(int priority)const
{

    //value by priority
    Node* current = head;
    while (current != nullptr && current->priority != priority) {
        current = current->next;
        if (current->priority = priority) {
            return current->value;
        }
    }
    // nie widze przypadku w ktorym do tego by nie doszlo tho
    return 0;

}
