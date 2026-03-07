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
    return quickSort(nums, 0, nums.size() - 1);
}
