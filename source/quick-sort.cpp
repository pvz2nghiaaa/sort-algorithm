#include <vector>
using namespace std;

void quickSort(vector<int> &nums, int low, int high)
{
    if (low >= high)
        return;

    int pivot = nums[high];
    int i = low;

    for (int j = low; j < high; j++)
    {
        if (nums[j] < pivot)
        {
            swap(nums[i], nums[j]);
            i++;
        }
    }

    swap(nums[i], nums[high]);

    quickSort(nums, low, i - 1);
    quickSort(nums, i + 1, high);
}

void quickSort(vector<int> &nums)
{
    quickSort(nums, 0, nums.size() - 1);
}

void quickSortOperationCount(vector<int> &nums, int &assignments, int &comparisions)
{
    assignments = comparisions = 0;
    quick_Sort_OC(nums, 0, nums.size() - 1, assignments, comparisions);
}

void quick_Sort_OC(vector<int> &nums, int low, int high, int &assignments, int &comparisions)
{
    if (++comparisions, low >= high)
        return;

    int pivot = nums[high];
    ++assignments;
    int i = low;
    ++assignments;

    ++assignments;
    for (int j = low; ++comparisions, j < high; j++, ++assignments)
    {
        if (++comparisions, nums[j] < pivot)
        {
            swap(nums[i], nums[j]);
            assignments += 3;
            i++;
            ++assignments;
        }
    }

    swap(nums[i], nums[high]);
    assignments += 3;

    quick_Sort_OC(nums, low, i - 1, assignments, comparisions);
    quick_Sort_OC(nums, i + 1, high, assignments, comparisions);
}