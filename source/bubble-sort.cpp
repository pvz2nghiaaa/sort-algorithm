#include <vector>
using namespace std;

void bubble_sort(vector<int> &arr)
{
    int n = arr.size();
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
                swap(arr[i], arr[i + 1]);
                unsorted = true;
            }
        }
    }
}
