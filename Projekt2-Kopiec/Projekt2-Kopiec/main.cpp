#include <iostream>
#include <stdexcept>
#include <cstdlib> // rand()
#include <ctime>   
#include <chrono>

#include "PriorityQueue1.h"
#include "PriorityQueue2.h"
int main() {
    srand(time(nullptr)); // Initialize random seed

    int choice = 2;
    //std::cout << "Choose the priority queue type:" << std::endl;
    //std::cout << "1. Priority Queue (Heap)" << std::endl;
    //std::cout << "2. Priority Queue (List)" << std::endl;
    //std::cin >> choice;

    PriorityQueue* pq = nullptr;
    const int zakres[] = { 10000,20000,30000,40000,50000,60000,70000,80000, 90000,100000 };

    for (int k = 0; k < 10; k++) {
        int numRandom = zakres[k];

        if (choice == 1)
            pq = new PriorityQueue1(numRandom);
        else if (choice == 2)
            pq = new PriorityQueue2();

        /*auto start = std::chrono::high_resolution_clock::now();
        for (int i = 0; i < numRandom; ++i) {
            int element = rand() % zakres[k];
            int priority = rand() % zakres[k] * 3;
            pq->insert(element, priority);
        }
        auto end = std::chrono::high_resolution_clock::now();
        auto elapsedSeconds = end - start;
        std::cout << "Time taken to insert random elements into PriorityQueue: " << elapsedSeconds.count() << " seconds" << std::endl;
        */
        
        for (int i = 0; i < numRandom; ++i) {
            int element = rand() % numRandom;
            int priority = rand() % numRandom * 3;
            pq->insert(element, priority);
        }

        //auto start_quick = std::chrono::high_resolution_clock::now();
        //    pq->extractMax();
        //auto end_quick = std::chrono::high_resolution_clock::now();
        //std::chrono::duration<double, std::milli> time_heap = end_quick - start_quick;
        //std::cout << time_heap.count() << std::endl;
        /*
        auto start_quick2 = std::chrono::high_resolution_clock::now();
            pq->findMax();
        auto end_quick2 = std::chrono::high_resolution_clock::now();
        std::chrono::duration<double, std::milli> time_heap2 = end_quick2 - start_quick2;
        std::cout << time_heap2.count() << std::endl;

        */

        int priority = rand() % numRandom * 3;
        int elem = rand() % numRandom;
        int newPriority = rand() % numRandom * 3;  
        pq->insert(elem, priority);

        auto start_quick3 = std::chrono::high_resolution_clock::now();
             //pq->modifyKey(pq->returnLos(priority),priority);
            //pq->modifyKey(elem, newPriority);
            pq->insert(elem, newPriority);
        auto end_quick3 = std::chrono::high_resolution_clock::now();
        std::chrono::duration<double, std::milli> time_heap3 = end_quick3 - start_quick3;
        std::cout << time_heap3.count() << std::endl;

        
        //int element = rand() % zakres[k];
        //int priority = rand() % zakres[k] * 3;

        //auto start_quick = std::chrono::high_resolution_clock::now();
        //    pq->insert(element, priority);
        //auto end_quick = std::chrono::high_resolution_clock::now();

        //std::chrono::duration<double, std::milli> time_heap = end_quick - start_quick;
        //std::cout << time_heap.count() << " "  << pq->returnSize() << std::endl;
        delete pq;      
    }

    return 0;
}
//srand(time(NULL));
//    PriorityQueue* test;
//    test = new PriorityQueue1(20);
//    for (int i = 0; i < 20; i++) {
//        int pr = rand() % 10;
//        test->insert(i, pr);
//    }
//    test->queueState();
//    std::cout << "\n\n\n===========\n\n\n";
//    test->insert(999, 0);
//    test->queueState();
//    std::cout << "\n\n\n===========\n\n\n";
//    std::cout<<test->findMax();
    //PriorityQueue* test;

    //test = new PriorityQueue1;
    //for (int i = 0; i < 20; i++) {
    //    test->insert(i, i);
    //}
    //std::cout << "=====================================\n";
    //std::cout << "size of queue: " << test->returnSize() << "\n";
    //std::cout << "Find-max: " << test->findMax() << "\n ";
    //std::cout << "Extract-max: " << test->extractMax() << "\n";
    //std::cout << "Find-max: " << test->findMax() << "\n ";
    //test->modifyKey(0, 100);
    //std::cout << "Modified key of max to 100: ";
    //std::cout << "Find-max: " << test->findMax() << "\n ";
    //test->queueState();
    //    
    ////test->queueState();
    //std::cout << "size of queue: " << test->returnSize() << "\n";
