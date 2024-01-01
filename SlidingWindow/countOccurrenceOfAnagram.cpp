// https://practice.geeksforgeeks.org/problems/count-occurences-of-anagrams5839/1
#include<iostream>
#include<unordered_map>
using namespace std;

int search(string pat, string txt) {
    unordered_map<char, int> charCount;
    int distict = 0, ans = 0, j=0;
    
    for(auto i: pat) charCount[i]++;
    distict = charCount.size();
    
    while(j<txt.size()){
        charCount[txt[j]]--;
        if(charCount[txt[j++]] == 0) distict--;
        if(j >= pat.size()){
            if(distict==0) ans++;
            charCount[txt[j-pat.size()]]++;
            if(charCount[txt[j-pat.size()]]==1) distict++;
        }
    }
    return ans;
}

int main(){
    string pat = "aaba", txt = "aabaabaa";
    cout<<search(pat, txt);

    return 0;
}