// https://www.interviewbit.com/problems/allocate-books/
bool check(vector<int> &A, int pages, int &B)
{
    int cnt{};
    int nos{};

    for (int i = 0; i < A.size(); i++)
    {
        if (A[i] + nos > pages)
        {
            cnt++;
            nos = A[i];
            if (nos > pages)
                return 0;
        }
        else
        {
            nos += A[i];
        }
    }
    if (cnt < B)
        return 1;
    return 0;
}

int solve(vector<int> &A, int B)
{
    int low = A[0];
    int high{}, maxi{};
    for (int i = 0; i < A.size(); i++)
    {
        high += A[i];
        maxi = max(maxi, A[i]);
        low = min(low, A[i]);
    }
    if (A.size() == B)
        return maxi;

    while (low <= high)
    {
        int mid = (high - low) >> 1;
        mid += low;

        if (check(A, mid, B))
        {
            high = mid - 1;
        }
        else
        {
            low = mid + 1;
        }
    }

    return low;
}

int Solution::books(vector<int> &A, int B)
{

    if (A.size() < B)
        return -1;

    return solve(A, B);
}
