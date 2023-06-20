// https://leetcode.com/problems/median-of-two-sorted-arrays/description/

class Solution
{
public:
    double findMedianSortedArrays(vector<int> &nums1, vector<int> &nums2)
    {

        int i{}, j{}, k(nums1.size() - 1);
        int s1 = nums1.size(), s2 = nums2.size();

        if (!s1)
        {
            if (s2 % 2)
            {
                return double(nums2[s2 / 2]);
            }
            else
            {
                return double(nums2[s2 / 2 - 1] + nums2[s2 / 2]) / 2;
            }
        }
        if (!s2)
        {
            if (s1 % 2)
            {
                return double(nums1[s1 / 2]);
            }
            else
            {
                return double(nums1[s1 / 2 - 1] + nums1[s1 / 2]) / 2;
            }
        }

        while (i < s1 && i <= k && j < s2)
        {
            if (nums1[i] >= nums2[j])
            {
                swap(nums1[k--], nums2[j++]);
            }
            else
            {
                i++;
            }
        }
        sort(nums1.begin(), nums1.end());
        sort(nums2.begin(), nums2.end());

        int mid = (s1 + s2) / 2;
        if ((s1 + s2) % 2)
        {
            if (s1 <= mid)
            {
                return nums2[mid - s1];
            }
            else
            {
                return nums1[mid];
            }
        }
        else
        {
            if (s1 < mid)
            {
                return double(nums2[mid - s1 - 1] + nums2[mid - s1]) / 2;
            }
            else
            {
                if (mid == s1)
                {
                    return double(nums1[mid - 1] + nums2[0]) / 2;
                }
                else
                {
                    return double(nums1[mid - 1] + nums1[mid]) / 2;
                }
            }
        }
    }
};