#include <iostream>
#include <gtest/gtest.h>
#include <vector>
#include <iostream>
#include "Sorting.cpp"

using namespace std;

class SortingTest : public ::testing::Test {
protected:
	vector<int> ascAges;
	vector<int> randAges;
	vector<int> desAges;
	vector<int> lrgAges;
	vector<int> sortedLrgAges;
	
	virtual void SetUp() {
		ascAges.push_back(10);
		ascAges.push_back(20);
		ascAges.push_back(30);
		
		randAges.push_back(20);
		randAges.push_back(30);
		randAges.push_back(10);
		
		desAges.push_back(30);
		desAges.push_back(20);
		desAges.push_back(10);
		
		lrgAges.push_back(50);
		lrgAges.push_back(5);
		lrgAges.push_back(60);
		lrgAges.push_back(60);
		lrgAges.push_back(-10);
		lrgAges.push_back(45);
		lrgAges.push_back(99);
		lrgAges.push_back(0);
		lrgAges.push_back(31);
		lrgAges.push_back(200);
		
		sortedLrgAges.push_back(-10);
		sortedLrgAges.push_back(0);
		sortedLrgAges.push_back(5);
		sortedLrgAges.push_back(31);
		sortedLrgAges.push_back(45);
		sortedLrgAges.push_back(50);
		sortedLrgAges.push_back(60);
		sortedLrgAges.push_back(60);
		sortedLrgAges.push_back(99);
		sortedLrgAges.push_back(200);
	}
};

TEST_F(SortingTest, ShouldReturnTheSameOrderIfAlreadySorted) {
	Sorting sorting;
	vector<int> sorted = sorting.selectionSort(ascAges);
	
	ASSERT_EQ(sorted.front(), ascAges.front());
	ASSERT_EQ(sorted.back(), ascAges.back());
}

TEST_F(SortingTest, ShouldReturnSortedIfNotSorted) {
	Sorting sorting;
	vector<int> sorted = sorting.selectionSort(randAges);
	
	ASSERT_EQ(10, sorted.front());
	ASSERT_EQ(30, sorted.back());
}

TEST_F(SortingTest, ShouldReturnAscendingSortedIfAlreadyDescending) {
	Sorting sorting;
	vector<int> sorted = sorting.selectionSort(desAges);
	
	ASSERT_EQ(10, sorted.front());
	ASSERT_EQ(30, sorted.back());
}

TEST_F(SortingTest, ShouldReturnSortedForLargeGroupOfNumber) {
	Sorting sorting;
	vector<int> actual = sorting.selectionSort(lrgAges);
	
	for (int idx = 0; idx < lrgAges.size(); idx++) {
		ASSERT_EQ(sortedLrgAges.at(idx), actual.at(idx));
	}
}

TEST_F(SortingTest, ShouldSwapVariableContents) {
	Sorting sorting;
	int a = 10, b = 20;
	
	sorting.swap(a, b);
	ASSERT_EQ(10, b);
	ASSERT_EQ(20, a);
}

// Use the Google Test main that is linked into the framework. It does something
// like this:
int main(int argc, char** argv) {
	testing::InitGoogleTest(&argc, argv);
	return RUN_ALL_TESTS();
}