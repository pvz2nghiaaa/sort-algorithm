#include <vector>
using namespace std;

void shellSort(vector<int>& nums){
    int n = nums.size();
    for (int gap = n / 2; gap > 0; gap >>= 1){
        for (int i = gap; i < n; i++){
            int key = nums[i];
            int j = i - gap;
            while(j >= 0 && nums[j] > key){
                nums[j + gap] = nums[j];
                j -= gap;
            }
            nums[j + gap] = key;
        }
    }
}
void shellSortOperationsCount(vector<int>& nums, int& assignments, int& comparisons){
    assignments = comparisons = 0;
    int n = nums.size();+assignments;
    ++assignments; // before loop
    for (int gap = n / 2; ++comparisons && gap > 0; gap >>= 1, ++assignments){
        ++assignments; // before loop
        for (int i = gap; ++comparisons && i < n; i++, ++assignments){
            int key = nums[i]; ++assignments;
            int j = i - gap; ++assignments;
            while(++comparisons && j >= 0 && ++comparisons &&  nums[j] > key){
                nums[j + gap] = nums[j]; ++assignments;
                j -= gap; ++assignments;
            }
            nums[j + gap] = key; ++assignments;
        }
    }
}
