#ifndef PRIORITY_QUEUE_H_
#define PRIORITY_QUEUE_H_

struct priority_queue
{
    int* A;
    int heapsize;
    int length;

    priority_queue(int l)
    {
        length = l;
        heapsize = 0;
        A = new int[length+1];
    }
};

// Priority heap operations
int max(priority_queue &pq); // Undefined behavior when heapsize == 0
int extract_max(priority_queue &pq); // Undefined behavior when heapsize == 0
void insert(priority_queue &pq, int p); // Undefined behavior when heapsize >= length
void set_priority(priority_queue &pq, int i, int p);

// Auxiliary functions
bool down(priority_queue &pq, int i);
bool up(priority_queue &pq, int i);

// Extra functions
void print(priority_queue &pq);

// Auxiliary definitions
#define P(i) (i/2)
#define L(i) (2*i)
#define R(i) ((2*i)+1)

#endif