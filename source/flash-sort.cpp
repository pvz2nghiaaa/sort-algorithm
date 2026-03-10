#include <vector>
using namespace std;


void flashSort(vector<int>& nums){
    int n = nums.size();
    if (n <= 1) return;

    int minVal = nums[0], maxVal = nums[0];
    for (int i = 1; i < n; i++) {
        minVal = min(minVal, nums[i]);
        maxVal = max(maxVal, nums[i]);
    }

    if (minVal == maxVal) return;


    int m = 0.45 * n;
    if (m < 1) m = 1;

    vector<int> L(m, 0);

    for (int i = 0; i < n; i++) {
        int k = (long long)(nums[i] - minVal) * (m - 1) / (maxVal - minVal);
        L[k]++;
    }

    for (int i = 1; i < m; i++)
        L[i] += L[i - 1];

    // Flash Phase
    int move = 0;
    int j = 0;
    int k = m - 1;

    while (move < n - 1) {

        while (j >= L[k]) {
            j++;
            k = (long long)(nums[j] - minVal) * (m - 1) / (maxVal - minVal);
        }

        int flash = nums[j];

        while (j != L[k]) {

            k = (long long)(flash - minVal) * (m - 1) / (maxVal - minVal);
            int pos = --L[k];
            swap(flash, nums[pos]);

            move++;
        }
    }

    for (int i = 1; i < n; i++){
        int j = i-1;
        int key = nums[i];
        while (j >= 0 && nums[j] > key){
            nums[j+1] = nums[j];
            j--;
        }
        nums[j+1] = key;
    }


}
void flashSortOperationsCount(vector<int>& nums, long long& assignments, long long& comparisons){
    int n = nums.size(); assignments++;
    if (++comparisons && n <= 1) return;

    int minVal = nums[0], maxVal = nums[0]; assignments += 2;
    assignments++;
    for (int i = 1; ++comparisons && i < n; i++, assignments++){
        if (++comparisons && minVal > nums[i]){
            minVal = nums[i]; 
            assignments++; 
        }
        if (++comparisons && maxVal < nums[i]){
            maxVal = nums[i]; 
            assignments++; 
        }
    }

    if (++comparisons && minVal == maxVal) return;

    int m = 0.45 * n; assignments++;
    if (++comparisons && m < 1) {
        m = 1; assignments++;
    }
    vector<int> L(m, 0); assignments += m;


    assignments++;
    for (int i = 0; ++comparisons && i < n; i++, assignments++){
        int k = (long long)(nums[i] - minVal) * (m - 1) / (maxVal - minVal); assignments++;
        L[k]++; assignments++;
    }
    assignments++;
    for (int i = 1; ++comparisons && i < m; i++, assignments++)
        L[i] += L[i - 1], assignments++;

    // Flash Phase
    int move = 0; assignments++;
    int j = 0; assignments++;
    int k = m - 1; assignments++;

    while (++comparisons && move < n - 1) {

        while (++comparisons && j >= L[k]) {
            j++; assignments++;
            k = (long long)(nums[j] - minVal) * (m - 1) / (maxVal - minVal); assignments++;
        }

        int flash = nums[j]; assignments++;

        while (++comparisons && j != L[k]) {

            k = (long long)(flash - minVal) * (m - 1) / (maxVal - minVal); assignments++;
            int pos = --L[k]; assignments++;
            swap(flash, nums[pos]); assignments += 3;

            move++; assignments++;
        }
    }

    assignments++;
    for (int i = 1; ++comparisons && i < n; i++, assignments++){
        int j = i-1; assignments++;
        int key = nums[i]; assignments++;
        while (++comparisons && j >= 0 && ++comparisons && nums[j] > key){
            nums[j+1] = nums[j]; assignments++;
            j--; assignments++;
        }
        nums[j+1] = key; assignments++;
    }
}
