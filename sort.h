#ifndef SORT_H
#define SORT_H
#include<vector>
#include<limits>

struct Merge
{
	template<typename Comparable>
	static void merge(std::vector<Comparable>& a,size_t lower, size_t  mid, size_t  higher) {
		const size_t n1 = mid - lower + 1;
		const size_t n2 = higher - mid;
		std::vector<Comparable> left(n1+1),right(n2+1);
		for (int i = 0; i < n1; ++ i) {
			left[i] = a[lower + i]; 
		}
		for (int i = 0; i < n2; ++ i) {
			right[i]=a[mid+i+1];
		}
		auto max = std::numeric_limits<Comparable> ::max();
		left[n1]=max;
		right[n2]=max;
		size_t m = 0,n = 0;

		//这里hgier 是下标不是长度！所以应该＝
		for (size_t i = lower; i <= higher; i++)
		{
			if (left[n] <= right[m]) a[i] = left[n++];
			else
			{
				a[i] = right[m++];
			}
		
		}
	
	}

	template<typename Comparable>
	static void merge_sort(std::vector<Comparable>& a, size_t lower, size_t higher) {
		if (lower < higher) {
			size_t mid = (lower + higher) / 2;
			merge_sort(a, lower, mid);
			merge_sort(a, mid+1,higher);
			merge(a, lower, mid, higher);
		}
	}
};

template<typename T>
inline void print(const T& a)
{
	for (const auto& i : a)
		std::cout << i << " ";
	std::cout << "\n";
}

#endif // !SORT_H
