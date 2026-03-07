#include <vector>

void quickSort(std::vector<int> &nums, int low, int high)
{
    if (low >= high)
        return;

    int pivot = nums[high];
    int i = low;

    for (int j = low; j < high; j++)
    {
        if (nums[j] < pivot)
        {
            std::swap(nums[i], nums[j]);
            i++;
        }
    }

    std::swap(nums[i], nums[high]);

    quickSort(nums, low, i - 1);
    quickSort(nums, i + 1, high);
}
