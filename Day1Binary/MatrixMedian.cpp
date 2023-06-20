// https://www.interviewbit.com/problems/matrix-median/
int cntLessEql(vector<int> &A, int midV)
{
    int cnt{};

    int low{}, high(A.size() - 1);

    while (low <= high)
    {
        int mid = (high - low) >> 1;
        mid += low;

        if (A[mid] <= midV)
            low = mid + 1;
        else
            high = mid - 1;
    }
    return low;
}

int Solution::findMedian(vector<vector<int>> &A)
{

    int low{}, high(1e9);
    int row(A.size()), col(A[0].size());

    while (low <= high)
    {
        int mid = (high - low) >> 1;
        mid += low;
        int cnt{};

        for (int i = 0; i < row; i++)
        {
            cnt += cntLessEql(A[i], mid);
        }

        if (cnt <= (row * col) / 2)
            low = mid + 1;
        else
            high = mid - 1;
    }
    return low;
}
