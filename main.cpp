#include "priority_queue.h"

#include <iostream>

int main(int argc, char const *argv[])
{    
    priority_queue pq(20);
    for (int i = 0; i < 5; ++i)
    {
        insert(pq,i);
        print(pq);
    }
    std::cout << "hp = " << pq.heapsize;
    set_priority(pq, 2, 5);
    print(pq);
    set_priority(pq,1,1);
    print(pq);
    set_priority(pq,5,3);
    print(pq);
    extract_max(pq);
    print(pq);
    return 0;
}