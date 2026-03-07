#include <vector>
using namespace std;

void shakerSort(vector<int> &nums)
{
    if (nums.empty())
        return;

    bool swapped = true;
    int start = 0;
    int end = nums.size() - 1;

    while (swapped)
    {

        swapped = false;

        for (int i = start; i < end; ++i)
        {
            if (nums[i] > nums[i + 1])
            {
                swap(nums[i], nums[i + 1]);
                swapped = true;
            }
        }

        if (!swapped)
            break;

        swapped = false;
        --end;

        for (int i = end - 1; i >= start; --i)
        {
            if (nums[i] > nums[i + 1])
            {
                swap(nums[i], nums[i + 1]);
                swapped = true;
            }
        }
        ++start;
    }
}

void shakerSortOperationCount(vector<int> &nums, int &assignments, int &comparisions)
{
    ++assignments;
    if (nums.empty())
        return;

    bool swapped = true;
    ++assignments;
    int start = 0;
    ++assignments;
    int end = nums.size() - 1;
    ++assignments;

    ++comparisions;
    while (swapped)
    {

        swapped = false;
        ++assignments;

        ++assignments;
        for (int i = start; ++comparisions, i < end; ++i, ++assignments)
        {
            if (++comparisions, nums[i] > nums[i + 1])
            {
                swap(nums[i], nums[i + 1]);
                assignments += 3;
                swapped = true;
                ++assignments;
            }
        }

        ++assignments;
        if (!swapped)
            break;

        swapped = false;
        ++assignments;
        --end;
        ++assignments;

        ++assignments;
        for (int i = end - 1; ++comparisions, i >= start; --i, ++assignments)
        {
            if (++comparisions, nums[i] > nums[i + 1])
            {
                swap(nums[i], nums[i + 1]);
                assignments += 3;
                swapped = true;
                ++assignments;
            }
        }
        ++start;
        ++assignments;

        ++comparisions;
    }
}