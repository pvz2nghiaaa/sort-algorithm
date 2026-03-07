#include <vector>
using namespace std;

void binaryInsertionSort(vector<int>& nums){
    for (int i = 1; i < nums.size(); i++){
        int key = nums[i];
        int left = 0, right = i - 1;
        while(left <= right){
            int mid = (left + right) >> 1;
            if (key < nums[mid])
                right = mid - 1;
            else left = mid + 1;
        }
        for (int j = i - 1; j >= left; j--)
            nums[j + 1] = nums[j];
        nums[left] = key;
    }
}
void binaryInsertionSortOperationsCount(vector<int>& nums, long long& assignments, long long& comparisons){
    assignments = comparisons = 0;
    ++assignments; // before loop
    for (int i = 1; ++comparisons && i < nums.size(); i++, ++assignments){
        int key = nums[i]; ++assignments;
        int left = 0, right = i - 1;assignments += 2;
        while(++comparisons && left <= right){
            int mid = (left + right) >> 1;++assignments;
            if (++comparisons && key < nums[mid])
                right = mid - 1, ++assignments;
            else left = mid + 1, ++assignments;
        }
        ++assignments; // before loop
        for (int j = i - 1; ++comparisons && j >= left; ++assignments, j--)
            nums[j + 1] = nums[j], ++assignments;
        nums[left] = key; ++assignments;
    }
}
