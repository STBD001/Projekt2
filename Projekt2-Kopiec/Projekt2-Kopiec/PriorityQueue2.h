#include "PriorityQueue.h"
#include "Node.h"
class PriorityQueue2 : public PriorityQueue {
private:
    Node* head;
    int size;

public:
    PriorityQueue2() : head(nullptr), size(0) {}

    ~PriorityQueue2() {
        while (head != nullptr) {
            Node* temp = head;
            head = head->next;
            delete temp;
        }
    }

    void insert(int element, int priority) override;

    int extractMax() override;

    int findMax() const override;

    void modifyKey(int element, int newPriority) override;

    int returnSize() const override {
        return size;
    }

    void queueState() const override;

    //int priorityOnList(int random) const override;

    int returnLos(int priority)const override;
   
};
