#include "priority_queue.h"

#include <algorithm> // for std::swap
#include <iostream>

int max(priority_queue &pq)
{
    if (pq.heapsize > 0) return pq.A[1];
    return pq.A[0];
}

int extract_max(priority_queue &pq)
{
    if (pq.heapsize == 0) return pq.A[0];

    int m = pq.A[1];
    std::swap(pq.A[1], pq.A[pq.heapsize]);
    pq.heapsize -= 1;
    down(pq,1);
    return m;
}

void insert(priority_queue &pq, int p)
{
    if (pq.heapsize < pq.length)
    {
        pq.heapsize += 1;
        pq.A[pq.heapsize] = p;
        up(pq, pq.heapsize);
    }
}

void set_priority(priority_queue &pq, int i, int p)
{
    if (1 <= i and i <= pq.heapsize)
    {
        pq.A[i] = p;
        if (not up(pq,i)) down(pq,i);
    }
}

bool down(priority_queue &pq, int i)
{
    int j = L(i);
    if (j <= pq.heapsize)
    {
        if (j+1 <= pq.heapsize and pq.A[j+1] > pq.A[j]) j++;

        if (pq.A[i] < pq.A[j])
        {
            std::swap(pq.A[i], pq.A[j]);
            down(pq,j);
            return true;
        }
    }
    else return false;
}

bool up(priority_queue &pq, int i)
{
    int j = P(i);
    if (j >= 1 and pq.A[i] > pq.A[j])
    {
        std::swap(pq.A[i], pq.A[j]);
        up(pq,j);
        return true;
    }
    else return false;
}

void print(priority_queue &pq)
{
    std::cout << "\n";
    for (int i = 1; i <= pq.heapsize; ++i)
    {
        std::cout << pq.A[i] << " ";
    }
    std::cout << "\n";
}