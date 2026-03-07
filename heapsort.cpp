#include <vector>

using namespace std;

void heapify(vector<int>& nums, int n, int pos)
{
    int largest = pos;

    int leftChild = pos * 2 + 1;
    if (leftChild >= n)
        return;
    if (nums[leftChild] > nums[largest])
        largest = leftChild;

    int rightChild = pos * 2 + 2;
    if (rightChild < n)
    {
        if (nums[rightChild] > nums[largest])
            largest = rightChild;
    }

    if (largest != pos)
    {
        swap(nums[pos], nums[largest]);
        if (largest <= n / 2 - 1)
            heapify(nums, n, largest);
    }
}

void heapSort(vector<int>& nums) 
{
    int n = (int)nums.size();
    
    for (int i = n / 2 - 1; i >= 0; i--)
        heapify(nums, n, i);

    for (int i = n - 1; i > 0; i--)
    {
        swap(nums[0], nums[i]);
        heapify(nums, i, 0);
    }
}

void heapifyOperationsCount(vector<int>& nums, int n, int pos, int& assignments, int& comparisons)
{
    int largest = pos;
    ++assignments;

    int leftChild = pos * 2 + 1;
    ++assignments;
    if (++comparisons && leftChild >= n)
        return;
    if (++comparisons && nums[leftChild] > nums[largest])
    {
        largest = leftChild;
        ++assignments;
    }

    int rightChild = pos * 2 + 2;
    ++assignments;
    if (++comparisons && rightChild < n)
    {
        if (++comparisons && nums[rightChild] > nums[largest])
        {
            largest = rightChild;
            ++assignments;
        }
    }

    if (++comparisons && largest != pos)
    {
        swap(nums[pos], nums[largest]);
        assignments += 3;
        if (++comparisons && largest <= n / 2 - 1)
            heapifyOperationsCount(nums, n, largest, assignments, comparisons);
    }
}

void heapSortOperationsCount(vector<int>& nums, int& assignments, int& comparisons) 
{
    assignments = 0;
    comparisons = 0;

    int n = (int)nums.size();
    ++assignments;
    
    ++assignments;
    for (int i = n / 2 - 1; ++comparisons && i >= 0; i--, ++assignments)
        heapifyOperationsCount(nums, n, i, assignments, comparisons);

    ++assignments;
    for (int i = n - 1; ++comparisons && i > 0; i--, ++assignments)
    {
        swap(nums[0], nums[i]);
        assignments += 3;
        heapify(nums, i, 0);
    }
}