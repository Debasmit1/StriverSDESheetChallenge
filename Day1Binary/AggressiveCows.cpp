// https://www.codingninjas.com/codestudio/problems/aggressive-cows_1082559?utm_source=striver&utm_medium=website&utm_campaign=codestudio_a_zcourse&leftPanelTab=1
bool check(vector<int> &stalls, int mid, int k)
{
    int cnt(1), low(stalls[0]);

    for (int i = 1; i < stalls.size(); i++)
    {
        if (stalls[i] - low >= mid)
        {
            cnt++;
            low = stalls[i];
        }
    }
    if (cnt >= k)
        return 1;
    else
        return 0;
}

int aggressiveCows(vector<int> &stalls, int k)
{
    //    Write your code here.
    sort(stalls.begin(), stalls.end());

    int low(1), high(stalls[stalls.size() - 1] - stalls[0]);

    while (low <= high)
    {
        int mid = (high - low) >> 1;
        mid += low;

        if (check(stalls, mid, k))
        {
            low = mid + 1;
        }
        else
        {
            high = mid - 1;
        }
    }
    return high;
}