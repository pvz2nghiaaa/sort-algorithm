#include <sorts.h>

void countingSort(vector<int>& nums, int exp){
	vector<int> output(nums.size());    
	vector<int> cnt(10, 0);
	for (int i = 0; i < nums.size(); i++)
		cnt[(nums[i] /exp) % 10]++;
	for (int i = 1; i < 10; i++)
		cnt[i] += cnt[i-1];
	for (int i = nums.size()-1; i >= 0; i--){
		cnt[(nums[i] / exp) % 10]--;
		output[cnt[(nums[i] / exp) % 10]] = nums[i];
	}
	nums = output;
}

void radixSort(vector<int>& nums) {
	int mx = -1;
	for (int i = 0; i < nums.size(); i++){
		if (mx < nums[i])
			mx = nums[i];
	}
	for (int i = 1; i <= mx; i *= 10)
		countingSort(nums, i);
}

void countingSortOperationsCount(vector<int>& nums, int exp, int& assignments, int& comparisons){
	vector<int> output(nums.size()); assignments += nums.size();
	vector<int> cnt(10, 0); assignments += 10;
	assignments++;
	for (int i = 0; ++comparisons && i < nums.size(); i++, assignments++)
		cnt[(nums[i] /exp) % 10]++, assignments++;
	assignments++;
	for (int i = 1; ++comparisons && i < 10; i++, assignments++)
		cnt[i] += cnt[i-1], assignments++;
	assignments++;
	for (int i = nums.size()-1; ++comparisons && i >= 0; i--, assignments++){
		cnt[(nums[i] / exp) % 10]--; assignments++;
		output[cnt[(nums[i] / exp) % 10]] = nums[i]; assignments++;
	}
	nums = output; assignments += nums.size();
}
void radixSortOperationsCount(vector<int>& nums, int& assignments, int& comparisons){
	assignments = comparisons = 0;
	int mx = -1; assignments++;
	assignments++;
	for (int i = 0; ++comparisons && i < nums.size(); i++, assignments++){
		if (++comparisons && mx < nums[i])
			mx = nums[i];
	}
	assignments++; // i = 1
	for (int i = 1; comparisons && i <= mx; i *= 10, assignments++)
		countingSortOperationsCount(nums, i, assignments, comparisons);
}