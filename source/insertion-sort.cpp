#include <vector>
using namespace std;

void insertionSort(vector<int>& nums) {
    for (int i = 1; i < nums.size(); i++){
        int key = nums[i];
        int j = i - 1;
        while(j >= 0 && nums[j] > key){
            nums[j + 1] = nums[j];
            --j;
        }
        nums[j + 1] = key;
    }
}
void insertionSortOperationsCount(vector<int>& nums, int& assignments, int& comparisons) {
    assignments = comparisons = 0;
    ++assignments; // before loop
    for (int i = 1; ++comparisons && i < nums.size(); i++, ++assignments){
        int key = nums[i]; ++assignments;
        int j = i - 1; ++assignments;
        while(++comparisons && j >= 0 && ++comparisons && nums[j] > key){
            nums[j + 1] = nums[j]; ++assignments;
            --j;++assignments;
        }
        nums[j + 1] = key; ++assignments;
    }
}
