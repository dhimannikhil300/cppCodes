#include<iostream>
#include<vector>
#include<queue>
using namespace std;

vector<long long> printFirstNegativeInteger(long long int A[], long long int N, long long int K) {
    vector<long long> ans;
    queue<long long > que;
    
    int j=0;
    while(j<N){
        if(A[j] < 0) que.push(A[j]);
        j++;
        if(j >= K){
            ans.push_back(que.empty() ? 0 : que.front());
            if(!que.empty() && que.front() == A[j-K]) que.pop();
        } 
    }
    return ans;
 }

int main(){
    long long int a[] = {-8, 2, 3, -6, 10};
    int n =5;
    int k = 2;

    vector<long long> ans = printFirstNegativeInteger(a, n, k);
    for(auto i: ans){
        cout<<i<<" ";
    }

    return 0;
}