#include <iostream>
#include <algorithm>
#include <cctype>
#include <cstring>
#include <vector>
#include <chrono>
#include <fstream>
#include "def.h"

using namespace std;

int pos_argv = 0; // the position after algorithms' name in argv[] 
int mode = -1; // 0: algorithm mode / 1: compare mode

// algorithm
char* algorithm1Name = nullptr;
char* algorithm2Name = nullptr;
int IDAlgorithm1 = -1;
int IDAlgorithm2 = -1;
const char* algorithmPrototypeName[] = {
	"bubble-sort", "shaker-sort", "quick-sort", 
	"selection-sort", "heap-sort", "merge-sort", 
	"insertion-sort", "binary-insertion-sort", "shell-sort",
	"counting-sort", "radix-sort", "flash-sort"
};	
const char* algorithmName[] = {
	"Bubble Sort", "Shaker Sort", "Quick Sort",
	"Selection Sort", "Heap Sort", "Merge Sort",
	"Insertion Sort", "Binary Insertion Sort", "Shell Sort",
	"Counting Sort", "Radix Sort", "Flash Sort"
};
void (*const listSort[])(vector<int>&) = {
	bubble_sort, shakerSort, quickSort, 
	selectionSort, heapSort, mergeSort, 
	insertionSort, binaryInsertionSort, shellSort, 
	nullptr, nullptr, nullptr
};
void (*const listSortOperationsCount[])(vector<int>&, long long&, long long&) = { 
	bubbleSortOperationCount, shakerSortOperationCount, quickSortOperationCount,
	selectionSortOperationsCount, heapSortOperationsCount, mergeSortOperationsCount,
	insertionSortOperationsCount, binaryInsertionSortOperationsCount, shellSortOperationsCount, 
	nullptr, nullptr, nullptr
};

// input parameter
int input_size = -1;
int chosenInputOrder = -1;
const char* input_order[] = { "-rand", "-sorted", "-rev", "-nsorted" };
const char* input_order_name[] = { "Randomize", "Sorted", "Reversed", "Nearly Sorted" };
const char* input_txt_name[] = { "input_1.txt", "input_3.txt", "input_4.txt", "input_2.txt" };
const int sizes[] = { 10000, 30000, 50000, 100000, 300000, 500000 };

// output parameter
int chosenOutputParameter = 2;
const char* output_parameter[] = { "-time", "-comp", "-both" };

// file name
char* inputFile = nullptr;

// store sorted vector (result)
vector<int> sorted_result;

void findAlgorithmUsed() {
	// process algorithm used from algorithm names
	for (int i = 0; i < 12; i++) {
		if (algorithm1Name && strcmp(algorithm1Name, algorithmPrototypeName[i]) == 0)
			IDAlgorithm1 = i;
		if (algorithm2Name && strcmp(algorithm2Name, algorithmPrototypeName[i]) == 0)
			IDAlgorithm2 = i;
	}
}

vector<int> readInputFile() {
	ifstream fin(inputFile);
	int n;
	fin >> n;
	vector<int> nums(n);
	for (int i = 0; i < n; i++)
		fin >> nums[i];
	fin.close();
	return nums;
}

// 0: random / 1: sorted / 2: reverse sorted / 3: nearly sorted
vector<int> generateDataVector(int n, int dataType) {
	vector<int> nums(n);
	GenerateData(nums.data(), n, dataType);
	return nums;
}

int executionTimeAlgorithm(int algorithmID, vector<int> nums) {
	auto start = chrono::high_resolution_clock::now();
	listSort[algorithmID](nums);
	auto end = chrono::high_resolution_clock::now();
	auto duration = chrono::duration_cast<chrono::milliseconds>(end - start);
	sorted_result = nums;
	return duration.count();
}

long long comparisionsAlgorithm(int algorithmID, vector<int> nums) {
	long long comparisons = 0, assignments = 0;
	listSortOperationsCount[algorithmID](nums, assignments, comparisons);
	return comparisons;
}

void outputSortedResult() {
	ofstream fout("output.txt");
	int n = sorted_result.size();
	fout << n << "\n";
	for (int i = 0; i < n; i++)
		fout << sorted_result[i] << ' ';
	fout.close();
}

void outputGeneratedInput(vector<int>&nums, const char* fileName) {
	ofstream fout(fileName);
	int n = nums.size();
	fout << n << "\n";
	for (int i = 0; i < n; i++)
		fout << nums[i] << ' ';
	fout.close();
}

void algorithmMode() {
	printf("ALGORITHM MODE\nAlgorithm: %s\n", algorithmName[IDAlgorithm1]);
	if (inputFile) {
		vector<int> nums = readInputFile();
		int n = nums.size();
		printf("Input file: %s\nInput size: %d\n", inputFile, n);
		printf("------------------------------\n");
		if (chosenOutputParameter == 0 || chosenOutputParameter == 2) { // calculate running time
			int realTime = executionTimeAlgorithm(IDAlgorithm1, nums);
			printf("Running time: %d\n", realTime);
		}
		if (chosenOutputParameter == 1 || chosenOutputParameter == 2) { // calculate number of operations
			long long comparisions = comparisionsAlgorithm(IDAlgorithm1, nums);
			printf("Comparisions: %lld\n", comparisions);
		}
		outputSortedResult();
		return;
	}
	if (input_size == -1) {
		return void(printf("Error: Required input size!"));
	}
	if (chosenInputOrder >= 0) {
		vector<int> nums = generateDataVector(input_size, chosenInputOrder);
		int n = nums.size();
		printf("Input size: %d\nInput order: %s\n", n, input_order_name[chosenInputOrder]);
		printf("------------------------------\n");
		if (chosenOutputParameter == 0 || chosenOutputParameter == 2) { // calculate running time
			int realTime = executionTimeAlgorithm(IDAlgorithm1, nums);
			printf("Running time: %d\n", realTime);
		}
		if (chosenOutputParameter == 1 || chosenOutputParameter == 2) { // calculate number of operations
			long long comparisions = comparisionsAlgorithm(IDAlgorithm1, nums);
			printf("Comparisions: %lld\n", comparisions);
		}
		outputSortedResult();
		outputGeneratedInput(nums, "input.txt");
		return;
	}
	printf("Input size: %d\n", input_size);
	for (int inputOrder = 0; inputOrder < 4; inputOrder++) {
		vector<int> nums = generateDataVector(input_size, inputOrder);
		int n = nums.size();
		printf("\nInput order: %s\n", input_order_name[inputOrder]);
		printf("------------------------------\n");
		if (chosenOutputParameter == 0 || chosenOutputParameter == 2) { // calculate running time
			int realTime = executionTimeAlgorithm(IDAlgorithm1, nums);
			printf("Running time: %d\n", realTime);
		}
		if (chosenOutputParameter == 1 || chosenOutputParameter == 2) { // calculate number of operations
			long long comparisions = comparisionsAlgorithm(IDAlgorithm1, nums);
			printf("Comparisions: %lld\n", comparisions);
		}
		outputGeneratedInput(nums, input_txt_name[inputOrder]);
	}
}

void comparisonMode() {
	printf("COMPARE MODE\nAlgorithm: %s | %s\n", algorithmName[IDAlgorithm1], algorithmName[IDAlgorithm2]);
	if (inputFile) {
		vector<int> nums = readInputFile();
		int n = nums.size();
		printf("Input file: %s\nInput size: %d\n", inputFile, n);
		printf("------------------------------\n");
		if (chosenOutputParameter == 0 || chosenOutputParameter == 2) { // calculate running time
			int realTime1 = executionTimeAlgorithm(IDAlgorithm1, nums);
			printf("Running time: %d | ", realTime1);
			int realTime2 = executionTimeAlgorithm(IDAlgorithm2, nums);
			printf("%d\n", realTime2);
		}
		if (chosenOutputParameter == 1 || chosenOutputParameter == 2) { // calculate number of operations
			long long comparisions1 = comparisionsAlgorithm(IDAlgorithm1, nums);
			printf("Comparisions: %lld | ", comparisions1);
			long long comparisions2 = comparisionsAlgorithm(IDAlgorithm2, nums);
			printf("%lld\n", comparisions2);
		}
		return;
	}
	if (chosenInputOrder >= 0) {
		if (input_size == -1) {
			return void(printf("Error: Required input size!"));
		}
		vector<int> nums = generateDataVector(input_size, chosenInputOrder);
		int n = nums.size();
		printf("Input size: %d\nInput order: %s\n", n, input_order_name[chosenInputOrder]);
		printf("------------------------------\n");
		if (chosenOutputParameter == 0 || chosenOutputParameter == 2) { // calculate running time
			int realTime1 = executionTimeAlgorithm(IDAlgorithm1, nums);
			printf("Running time: %d | ", realTime1);
			int realTime2 = executionTimeAlgorithm(IDAlgorithm2, nums);
			printf("%d\n", realTime2);
		}
		if (chosenOutputParameter == 1 || chosenOutputParameter == 2) { // calculate number of operations
			long long comparisions1 = comparisionsAlgorithm(IDAlgorithm1, nums);
			printf("Comparisions: %lld | ", comparisions1);
			long long comparisions2 = comparisionsAlgorithm(IDAlgorithm2, nums);
			printf("%lld\n", comparisions2);
		}
		outputGeneratedInput(nums, "input.txt");
	}
	else {
		printf("Error: Input order invalid or not included!");
	}
}

void modeExecution() {
	if (mode == 0)
		algorithmMode();
	else comparisonMode();
}

int main(int argc, char* argv[]) {
	// check mode
	if (strcmp(argv[1], "-a") == 0) {
		algorithm1Name = argv[2];
		pos_argv = 3;
		mode = 0;
	}
	else if (strcmp(argv[1], "-c") == 0) {
		algorithm1Name = argv[2];
		algorithm2Name = argv[3];
		pos_argv = 4;
		mode = 1;
	}
	else {
		cout << "Error: No recognized mode found!";
		return 0;
	}

	// input_size / input_parameter / output_parameter
	while (pos_argv < argc) {
		if (all_of(argv[pos_argv], argv[pos_argv] + strlen(argv[pos_argv]), ::isdigit)) { // is a number, thus, input size
			input_size = atoi(argv[pos_argv]);
		}
		else if (argv[pos_argv][0] == '-') { // - indicates mode
			for (int i = 0; i < 4; i++)
				if (strcmp(argv[pos_argv], input_order[i]) == 0) {
					chosenInputOrder = i;
					break;
				}
			for (int i = 0; i < 3; i++)
				if (strcmp(argv[pos_argv], output_parameter[i]) == 0) {
					chosenOutputParameter = i;
					break;
				}
		}
		else { // input file's name
			if (fopen(argv[pos_argv], "r"))
				inputFile = argv[pos_argv];
			else {
				printf("Error: Input file not found!");;
				return 0;
			}
		}
		++pos_argv;
	}

	findAlgorithmUsed();
	modeExecution();
	printf("\n");

	return 0;
}