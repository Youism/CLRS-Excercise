#pragma once
#include<iostream>
#include<vector>
#include<limits>

using std::vector;
using VecInt=vector<int>;
struct maximumSubarray
{
	static  VecInt findMaxCrossingSubarray(VecInt& a, int lower, int mid, int higher) {
		int maxLeft=0;
		int sum = 0;
		auto leftSum = std::numeric_limits<int>::min();
		for (int i = mid; i >= lower; i--)
		{
			sum += a.at(i);
			if (sum > leftSum)
			{
				leftSum = sum;
				maxLeft = i;
			}
		}
		int maxRight=0;
		sum = 0;
		auto rightSum = std::numeric_limits<int>::min();
		for (int i = mid + 1; i <= higher; i++)
		{
			sum += a.at(i);
			if (sum > rightSum)
			{
				rightSum = sum;
				maxRight = i;
			}
		}
		VecInt ret{ maxLeft,maxRight,leftSum + rightSum };
		return ret;
	};

	static VecInt findMaxSubarray(VecInt& a, int low, int high) {
		//base part
		if (high == low) {
			VecInt vec={ low,high,a.at(low) };
			return vec;
		}
		//recurrence part
		else
		{

			int mid = (low + high) / 2;
			VecInt left=findMaxSubarray(a, low, mid);
			VecInt right = findMaxSubarray(a, mid + 1, high);
			//conquer part
			VecInt cross = findMaxCrossingSubarray(a, low, mid, high);
			//返回最大的SUM
			if (left.at(2) >= right.at(2) &&left.at(2)>= cross.at(2))
				return left;
			if (right.at(2) >= left.at(2)&&right.at(2) >= cross.at(2))
				return right;
			else
				return cross;
		}

	}
};