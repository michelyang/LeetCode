//
//  main.cpp
//  LeetCode-Array
//
//  Created by Xuewen on 1/24/17.
//  Copyright © 2017 Xuewen. All rights reserved.
//
/*
 * TwoSum.cpp
 *
 *  Created on: Jan 23, 2017
 *      Author: xuewen
 *
 Given an array of integers, return indices of the two numbers such that they add up to
 a specific target.
 You may assume that each input would have exactly one solution.
 Example:
 Given nums = [2, 7, 11, 15], target = 9,
 Because nums[0] + nums[1] = 2 + 7 = 9,
 return [0, 1].
 */
#include <iostream>
#include <vector>
#include <map>

using namespace std;

class TwoSum {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int> result;
        map<int, int> hm;
        for (int i = 0; i < nums.size(); i++) {
            if (hm.find(nums[i]) != hm.end()) {
                result.push_back(hm[nums[i]]);
                result.push_back(i);
            } else
                hm[target-nums[i]] = i;
        }
        return result;
    }
};

class MedianOfTwoSortedArray {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int m = (int) nums1.size();  // size_type to int, size_type can cover all the range of size, while int can't
        int n = (int) nums2.size();
        int mid = (m + n) / 2;
        if ((m+n) % 2)
            return (double) findKthNum(nums1, m, nums2, n, mid+1);
        else
            return 0.5 * ((double) findKthNum(nums1, m, nums2, n, mid) + (double) findKthNum(nums1, m, nums2, n, mid+1));
    }
    
    int findKthNum(vector<int>& nums1, int m, vector<int>& nums2, int n, int k) {
        if (m == 0) return nums2[k-1];
        if (n == 0) return nums1[k-1];
        int i = m / 2, j = n / 2;
        if (nums1[i] <= nums2[j]) {
            if (k > i+j+1)
                return findKthNum(nums1, m-i-1, nums2, n, k-i-1);
            else
                return findKthNum(nums1, m, nums2, j, k);
        } else {
            if (k > i+j+1)
                return findKthNum(nums1, m, nums2, n-j-1, k-j-1);
            else
                return findKthNum(nums1, i, nums2, n, k);
        }
    }
};


int main(int argc, const char * argv[]) {
    // two sum
    vector<int> nums;
    int target = 9;
    nums.push_back(2);
    nums.push_back(7);
    nums.push_back(11);
    nums.push_back(15);
    TwoSum ts;
    vector<int> result = ts.twoSum(nums, target);
    cout << result[0] << ' ' << result[1];
    
    // median of sorted arrays
    MedianOfTwoSortedArray m;
    vector<int> nums1, nums2, nums3;
    nums1.push_back(1);
    nums1.push_back(3);
    nums2.push_back(2);
    nums3.push_back(2);
    nums3.push_back(4);
    double median = m.findMedianSortedArrays(nums1, nums2);
    cout << median << endl;
    return 0;
}

