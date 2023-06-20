// https://leetcode.com/problems/search-in-rotated-sorted-array/description/

class Solution
{
public:
    int search(vector<int> &nums, int target)
    {
        int low{}, high(nums.size() - 1);

        while (low <= high)
        {
            int mid = (high - low) >> 1;
            mid += low;

            if (nums[mid] == target)
                return mid;
            else if (nums[low] <= nums[mid])
            {
                if (nums[low] <= target && target <= nums[mid])
                {
                    high = mid - 1;
                }
                else
                {
                    low = mid + 1;
                }
            }
            else
            {
                if (nums[mid] <= target && target <= nums[high])
                {
                    low = mid + 1;
                }
                else
                {
                    high = mid - 1;
                }
            }
        }
        return -1;
    }
};