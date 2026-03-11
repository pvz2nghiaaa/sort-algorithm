#include <vector>

using namespace std;

vector<int> tmpNums;

void mergeRange(vector<int>& nums, int l, int mid, int r)
{
    int i = l;
    int j = mid + 1;

    int curIdx = 0;
    while (i <= mid && j <= r)
    {
        if (nums[i] <= nums[j])
            tmpNums[curIdx++] = nums[i++];
        else
            tmpNums[curIdx++] = nums[j++];
    }
    while (i <= mid)
        tmpNums[curIdx++] = nums[i++];
    while (j <= r)
        tmpNums[curIdx++] = nums[j++];

    for (curIdx = l; curIdx <= r; curIdx++)
        nums[curIdx] = tmpNums[curIdx - l];
}

void mergeSort(vector<int>& nums, int l, int r)
{
    if (l >= r)
        return;

    int mid = l + ((r - l) >> 1);
    mergeSort(nums, l, mid);
    mergeSort(nums, mid + 1, r);
    
    return mergeRange(nums, l, mid, r);
}

void mergeSort(vector<int>& nums)
{
    int l = 0;
    int r = (int)nums.size() - 1;
    tmpNums.assign(r - l + 1, 0);
    return mergeSort(nums, l, r);
}

void mergeRangeOperationsCount(vector<int>& nums, int l, int mid, int r, long long& assignments, long long& comparisons)
{
    int i = l;
    ++assignments;
    int j = mid + 1;
    ++assignments;

    int curIdx = 0;
    ++assignments;
    while (++comparisons && i <= mid && ++comparisons && j <= r)
    {
        if (++comparisons && nums[i] <= nums[j])
        {
            tmpNums[curIdx++] = nums[i++];
            assignments += 3;
        }
        else
        {
            tmpNums[curIdx++] = nums[j++];
            assignments += 3;
        }
    }
    while (++comparisons && i <= mid)
    {
        tmpNums[curIdx++] = nums[i++];
        assignments += 3;
    }
    while (++comparisons && j <= r)
    {
        tmpNums[curIdx++] = nums[j++];
        assignments += 3;
    }

    for (curIdx = l, ++assignments; ++comparisons && curIdx <= r; curIdx++, ++assignments)
    {
        nums[curIdx] = tmpNums[curIdx - l];
        ++assignments;
    }
}

void mergeSortOperationsCount(vector<int>& nums, int l, int r, long long& assignments, long long& comparisons)
{
    if (++comparisons && l >= r)
        return;

    int mid = l + ((r - l) >> 1);
    ++assignments;
    mergeSortOperationsCount(nums, l, mid, assignments, comparisons);
    mergeSortOperationsCount(nums, mid + 1, r, assignments, comparisons);
    
    return mergeRangeOperationsCount(nums, l, mid, r, assignments, comparisons);
}

void mergeSortOperationsCount(vector<int>& nums, long long& assignments, long long& comparisons)
{
    assignments = 0;
    comparisons = 0;

    int l = 0;
    ++assignments;
    int r = (int)nums.size() - 1;
    ++assignments;

    tmpNums.assign(r - l + 1, 0);
    assignments += (r - l + 1);
    return mergeSortOperationsCount(nums, l, r, assignments, comparisons);
}