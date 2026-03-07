#include <vector>

void bubble_sort(std::vector<int> &arr, int n)
{
    bool unsorted = true;
    int idx = 0;
    while (unsorted)
    {
        unsorted = false;
        idx++;

        for (int i = 0; i < n - idx; i++)
        {
            if (arr[i] > arr[i + 1])
            {
                std::swap(arr[i], arr[i + 1]);
                unsorted = true;
            }
        }
    }
}