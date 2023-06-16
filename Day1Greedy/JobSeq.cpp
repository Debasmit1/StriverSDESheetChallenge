// https://practice.geeksforgeeks.org/problems/job-sequencing-problem-1587115620/1#

class Solution
{
    bool static cmp(Job &a, Job &b)
    {
        return (a.profit > b.profit);
    }

public:
    // Function to find the maximum profit and the number of jobs done.
    vector<int> JobScheduling(Job arr[], int n)
    {
        // your code here
        sort(arr, arr + n, cmp);
        int maxiD = 0;
        for (int i = 0; i < n; i++)
        {
            maxiD = max(maxiD, arr[i].dead);
        }

        int slot[maxiD + 1];

        for (int i = 1; i <= maxiD; i++)
        {
            slot[i] = -1;
        }

        int cntJ{}, jobJ{};

        for (int i = 0; i < n; i++)
        {
            for (int j = arr[i].dead; j > 0; j--)
            {
                if (slot[j] == -1)
                {
                    slot[j] = arr[i].id;
                    cntJ++;
                    jobJ += arr[i].profit;
                    break;
                }
            }
        }
        return {cntJ, jobJ};
    }
};
