#define CATCH_CONFIG_MAIN
#include "catch.hpp"

#include <vector>
#include <map>

using namespace std;

class Solution
{
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int nums1Size = nums1.size();
        int nums2Size = nums2.size();
        if (nums1Size == 0 && nums2Size == 0)
        {
            return 0.0;
        }

        int mergedSize = nums1Size + nums2Size;
        vector<int> nums(mergedSize);
        int i = 0;
        int j = 0;
        int cur = 0;

        // O(n) approach:
        // Merge arrays, find center point(s) and average if needed
        while (i < nums1Size || j < nums2Size)
        {
            if (i >= nums1Size)
            {
                nums[cur++] = nums2[j++];
            }
            else if (j >= nums2Size)
            {
                nums[cur++] = nums1[i++];
            }
            else
            {
                if (nums1[i] < nums2[j])
                {
                    nums[cur++] = nums1[i++];
                }
                else
                {
                    nums[cur++] = nums2[j++];
                }
            }
        }

        int middle = static_cast<int>(mergedSize / 2);
        if (mergedSize % 2 == 0)
        {
            return (nums[middle - 1] + nums[middle]) / 2.0;
        }

        return nums[middle];
    }
};

TEST_CASE("MedianOfSortedArrays", "[tests]")
{
    Solution solution;
    vector<int> nums1;
    vector<int> nums2;

    SECTION("LeetCode Sample Input #1")
    {
        nums1 = { 1, 3 };
        nums2 = { 2 };
        REQUIRE(solution.findMedianSortedArrays(nums1, nums2) == 2.0);
    }

    SECTION("LeetCode Sample Input #2")
    {
        nums1 = { 1, 2 };
        nums2 = { 3, 4 };
        REQUIRE(solution.findMedianSortedArrays(nums1, nums2) == 2.5);
    }

    SECTION("One Array Empty")
    {
        nums1 = { };
        nums2 = { 3, 4 };
        REQUIRE(solution.findMedianSortedArrays(nums1, nums2) == 3.5);
    }

    SECTION("Both Arrays Empty")
    {
        nums1 = {};
        nums2 = {};
        REQUIRE(solution.findMedianSortedArrays(nums1, nums2) == 0.0);
    }
}