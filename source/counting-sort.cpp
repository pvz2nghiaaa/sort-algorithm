#include <vector>
using namespace std;

void countingSort(vector<int>& nums){
	int maxElement = 0;
	for (int i = 0; i < nums.size(); i++)
		if (nums[i] > maxElement)
			maxElement = nums[i];
	vector<int> cnt(maxElement + 1, 0);
	for (int i = 0; i < nums.size(); i++)
		cnt[nums[i]]++;
	int j = 0;
	for (int i = 0; i <= maxElement; i++){
		while (cnt[i] > 0){
			nums[j++] = i;
			cnt[i]--;
		}
	}
}
void countingSortOperationsCount(vector<int>& nums, long long& assignments, long long& comparisons){
	assignments = comparisons = 0;	
	int maxElement = 0; ++assignments;
	 ++assignments; // before loop
	for (int i = 0; ++comparisons && i < nums.size(); i++, ++assignments)
		if (++comparisons && nums[i] > maxElement)
			maxElement = nums[i], ++assignments;
	vector<int> cnt(maxElement + 1, 0); assignments += maxElement + 1;
	 ++assignments; // before loop
	for (int i = 0; ++comparisons && i < nums.size(); i++, ++assignments)
		cnt[nums[i]]++, ++assignments;
	int j = 0; ++assignments;
	 ++assignments; // before loop
	for (int i = 0; ++comparisons && i <= maxElement; i++, ++assignments){
		while (++comparisons && cnt[i] > 0){
			nums[j++] = i; assignments += 2; // j++ &  nums[j] = i;
			cnt[i]--; ++assignments;
		}
	}
}