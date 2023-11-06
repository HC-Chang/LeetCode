/*
 * @lc app=leetcode id=1845 lang=c
 *
 * [1845] Seat Reservation Manager
 */

// @lc code=start
typedef struct
{
    int *heap;
    int heapSize;
} SeatManager;

SeatManager *seatManagerCreate(int n)
{
    SeatManager *seats = malloc(sizeof(SeatManager));
    seats->heapSize = n;
    seats->heap = malloc(sizeof(int) * n);
    for (int i = 0; i < n; i++)
        seats->heap[i] = i + 1;

    return seats;
}

int seatManagerReserve(SeatManager *seatManager)
{
    int *heap = seatManager->heap;
    int result = heap[0];
    heap[0] = heap[seatManager->heapSize - 1];
    seatManager->heapSize--;
    int upper = 0;
    int lower = 2 * upper + 1;
    int tmp;
    while (lower < seatManager->heapSize)
    {
        if (lower + 1 < seatManager->heapSize && heap[lower + 1] < heap[lower])
            lower++;
        if (heap[upper] < heap[lower])
            break;
        if (heap[upper] > heap[lower])
        {
            tmp = heap[upper];
            heap[upper] = heap[lower];
            heap[lower] = tmp;
        }
        upper = lower;
        lower = 2 * upper + 1;
    }
    return result;
}

void seatManagerUnreserve(SeatManager *seatManager, int seatNumber)
{
    int *heap = seatManager->heap;
    heap[seatManager->heapSize++] = seatNumber;
    int lower = seatManager->heapSize - 1;
    int upper = (lower + 1) / 2 - 1;
    int tmp;
    while (upper >= 0)
    {
        if (lower + 1 < seatManager->heapSize && heap[lower + 1] < heap[lower])
            lower++;
        if (heap[upper] < heap[lower])
            break;
        if (heap[upper] > heap[lower])
        {
            tmp = heap[upper];
            heap[upper] = heap[lower];
            heap[lower] = tmp;
        }
        lower = upper;
        upper = (lower + 1) / 2 - 1;
    }
}

void seatManagerFree(SeatManager *obj)
{
    free(obj->heap);
    free(obj);
}

/**
 * Your SeatManager struct will be instantiated and called as such:
 * SeatManager* obj = seatManagerCreate(n);
 * int param_1 = seatManagerReserve(obj);

 * seatManagerUnreserve(obj, seatNumber);

 * seatManagerFree(obj);
*/
// @lc code=end

// Note: heap