#include <vector>
using namespace std;

void quickSort(vector<int> &nums, int low, int high)
{
    while (low < high) {
        swap(nums[(low + high) / 2], nums[high]);
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
        if (i - low < high - i) {
            quickSort(nums, low, i - 1);
            low = i + 1;
        }
        else {
            quickSort(nums, i + 1, high);
            high = i - 1;
        }
    }
}

void quickSort(vector<int> &nums)
{
    quickSort(nums, 0, nums.size() - 1);
}

void quick_Sort_OC(vector<int> &nums, int low, int high, long long &assignments, long long &comparisions)
{
    while (++comparisions && low < high) {
        swap(nums[(low + high) / 2], nums[high]); assignments += 3;
        int pivot = nums[high]; ++assignments;
        int i = low; ++assignments;

        ++assignments; // before loop
        for (int j = low; ++comparisions && j < high; j++, ++assignments)
        {
            if (++comparisions && nums[j] < pivot)
            {
                swap(nums[i], nums[j]); assignments += 3;
                i++; ++assignments;
            }
        }

        swap(nums[i], nums[high]); assignments += 3;
        if (++comparisions && i - low < high - i) {
            quick_Sort_OC(nums, low, i - 1, assignments, comparisions);
            low = i + 1; ++assignments;
        }
        else {
            quick_Sort_OC(nums, i + 1, high, assignments, comparisions);
            high = i - 1; assignments;
        }
    }
}

void quickSortOperationCount(vector<int> &nums, long long &assignments, long long &comparisions)
{
    assignments = comparisions = 0;
    quick_Sort_OC(nums, 0, nums.size() - 1, assignments, comparisions);
}
