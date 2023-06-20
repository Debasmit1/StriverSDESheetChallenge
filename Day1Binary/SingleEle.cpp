// https://leetcode.com/problems/single-element-in-a-sorted-array/description/

// O(n)time complexity

class Solution
{
public:
    int singleNonDuplicate(vector<int> &nums)
    {
        for (int i = 0; i < nums.size() - 1; i++)
        {
            if (nums[i] != nums[i + 1])
                return nums[i];
            else
                i++;
        }
        return nums[nums.size() - 1];
    }
};

// Using XOR

class Solution
{
public:
    int singleNonDuplicate(vector<int> &nums)
    {
        int ele{};
        for (int i = 0; i < nums.size(); i++)
        {
            ele = ele ^ nums[i];
        }
        return ele;
    }
};

// Using Binary Search

class Solution
{
public:
    int singleNonDuplicate(vector<int> &nums)
    {
        int low{}, high(nums.size() - 2);
        while (low <= high)
        {
            int mid = (high - low) >> 1;
            mid += low;
            if (mid % 2 == 0)
            {
                if (nums[mid] != nums[mid + 1])
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
                if (nums[mid] != nums[mid + 1])
                {
                    low = mid + 1;
                }
                else
                {
                    high = mid - 1;
                }
            }
        }
        return nums[low];
    }
};