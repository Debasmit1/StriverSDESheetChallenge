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

// Using Binary Solution

class Solution
{

    double solve(vector<int> nums1, vector<int> nums2, int m, int n)
    {
        if (m > n)
            return solve(nums2, nums1, n, m);
        int median = (m + n + 1) / 2;
        int low{}, high(m);
        if (m == 0)
        {
            if (n % 2 == 0)
            {
                return double(nums2[median - 1] + nums2[median]) / 2.0;
            }
            else
            {
                return double(nums2[median - 1]);
            }
        }

        while (low <= high)
        {
            int mid = (high - low) >> 1;
            mid += low;
            int cut1 = mid;
            int cut2 = median - mid;

            int l1 = (cut1 == 0) ? INT_MIN : nums1[cut1 - 1];
            int l2 = (cut2 == 0) ? INT_MIN : nums2[cut2 - 1];
            int r1 = (cut1 == m) ? INT_MAX : nums1[cut1];
            int r2 = (cut2 == n) ? INT_MAX : nums2[cut2];

            if (l1 <= r2 && l2 <= r1)
            {
                if ((n + m) % 2 == 0)
                {
                    return double((max(l1, l2) + min(r1, r2)) / 2.0);
                }
                else
                {
                    return double(max(l1, l2));
                }
            }
            else if (l1 > r2)
            {
                high = mid - 1;
            }
            else
            {
                low = mid + 1;
            }
        }

        return double(0.0);
    }

public:
    double findMedianSortedArrays(vector<int> &nums1, vector<int> &nums2)
    {
        int s1 = nums1.size(), s2 = nums2.size();
        double ans = solve(nums1, nums2, s1, s2);
        return ans;
    }
};