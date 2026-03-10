#include <vector>
using namespace std;

void countingSort(vector<int>& nums){
	vector<int> cnt((1 << 15), 0);
	for (int i = 0; i < nums.size(); i++)
		cnt[nums[i]]++;
	int j = 0;
	for (int i = 0; i < (1 << 15); i++){
		while (cnt[i] > 0){
			nums[j++] = i;
			cnt[i]--;
		}
	}
}
void countingSortOperationsCount(vector<int>& nums, long long& assignments, long long& comparisons){
	assignments = comparisons = 0;
	vector<int> cnt((1 << 15), 0); assignments += (1 << 15);

	assignments++; // int i = 0
	for (int i = 0; ++comparisons && i < nums.size(); i++, assignments++)
		cnt[nums[i]]++, assignments++;
	
	int j = 0; assignments++;
	assignments++; // int i = 0
	for (int i = 0; ++comparisons && i < (1 << 15); i++, assignments++){
		while (++comparisons && cnt[i] > 0){
			nums[j++] = i; assignments += 2; // j++ && nums[j] = i
			cnt[i]--; assignments++;
		}
	}
}