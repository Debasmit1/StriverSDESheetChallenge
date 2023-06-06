// https://www.interviewbit.com/problems/repeat-and-missing-number-array/

vector<int> Solution::repeatedNumber(const vector<int> &A) {
    vector<int>len1(2,0),A1(A.size());
    A1=A;
    int n1=A.size();
    for(int i=0;i<n1;i++){
        if(A1[abs(A1[i])-1]<0)len1[0]=abs(A1[i]);
        else A1[abs(A1[i])-1]*=-1;
    }
    int x=-1;
    for(int i=0;i<n1;i++){
        if(A1[i]==n1)x=i+1;
        else if(A1[i]>0)len1[1]=i+1;
    }
    if(len1[1]==0)len1[1]=x;
    return len1;
}
