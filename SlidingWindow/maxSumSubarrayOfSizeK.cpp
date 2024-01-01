#include<iostream>
#include<vector>
using namespace std;

long maximumSumSubarray1(int K, vector<int> &Arr , int N){
    long sum=0, ans=0;
    int i=0;
    while(i<N){
        sum += Arr[i++];
        if(i >= K) ans = max(sum, ans), sum -= Arr[i-K];
    }
    return ans;
}

long maximumSumSubarray2(int k, vector<int> &Arr , int N){
    long sum = 0, res = 0;
    for(int i=0; i<k; i++){
        sum += Arr[i];
    }
    
    res = sum;
    for(int i=k; i<N; i++){
        sum += Arr[i];
        sum -= Arr[i-k];
        res = max(res, sum);
    }
    return res;
}

int main(){
    int n = 5;
    vector<int> arr = {100, 200, 300, 400};
    int k = 3;

    cout<<maximumSumSubarray1(k, arr, n)<<endl;
    cout<<maximumSumSubarray2(k, arr, n)<<endl;
    return 0;
}