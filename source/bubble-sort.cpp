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

void bubble_Sort_OperationCount(vector<int> &nums, int &assignments, int &comparisons)
{
    assignments = comparisons = 0;

    int n = nums.size();
    ++assignments;
    bool unsorted = true;
    ++assignments;
    int idx = 0;
    ++assignments;

    while (++comparisons, unsorted)
    {
        unsorted = false;
        ++assignments;
        idx++;
        ++assignments;

        ++assignments;
        for (int i = 0; ++comparisons, i < n - idx; i++, ++assignments)
        {
            if (++comparisons, nums[i] > nums[i + 1])
            {
                swap(nums[i], nums[i + 1]);
                assignments += 3;
                unsorted = true;
                ++assignments;
            }
        }
    }
}