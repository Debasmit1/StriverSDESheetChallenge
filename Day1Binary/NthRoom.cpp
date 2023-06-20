// https://www.codingninjas.com/codestudio/problems/1062679?topList=striver-sde-sheet-problems&utm_source=striver&utm_medium=website&leftPanelTab=1

int NthRoot(int n, int m)
{
    // Write your code here.
    long long low(1), high(m);
    while (low <= high)
    {
        long long mid = (high - low) >> 1;
        mid += low;
        if (pow(mid, n) < m)
        {
            low = mid + 1;
        }
        else if (pow(mid, n) > m)
        {
            high = mid - 1;
        }
        else
        {
            return mid;
        }
    }
    return -1;
}