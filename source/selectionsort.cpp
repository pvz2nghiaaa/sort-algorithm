#include <vector>

using namespace std;

void selectionSort(vector<int>& nums)
{
    int n = (int)nums.size();

    for (int i = 0; i < n - 1; i++)
    {
        int minIdx = i;
        for (int j = i + 1; j < n; j++)
            if (nums[minIdx] > nums[j])
                minIdx = j;
        swap(nums[i], nums[minIdx]);
    }
}

void selectionSortOperationsCount(vector<int>& nums, int& assignments, int& comparisons)
{
    assignments = 0;
    comparisons = 0;

    int n = (int)nums.size();
    ++assignments;

    ++assignments;
    for (int i = 0; ++comparisons && i < n - 1; i++, ++assignments)
    {
        int minIdx = i;
        ++assignments;

        ++assignments;
        for (int j = i + 1; ++comparisons && j < n; j++, ++assignments)
            if (++comparisons && nums[minIdx] > nums[j])
            {
                minIdx = j;
                ++assignments;
            }
        swap(nums[i], nums[minIdx]);
        assignments += 3;
    }
}