#include<iostream>
#include<string>
#include"sort.h"
#include"devide_conquer.h"
using namespace std;
int main() {
	/*vector<int> a{ 5,2,4,6,1,3 };
	Merge::merge_sort(a, 0, 5);
	print(a);*/
	VecInt a{ -1,-4,67,33,-90};
	auto answer = maximumSubarray::findMaxSubarray(a, 0, a.size() - 1);
	print(answer);
	return 0;
}