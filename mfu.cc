#include<bits/stdc++.h>
using namespace std;
int h,f;
void mfu(int arr[], int n, int capacity){
    unordered_map<int,int> mp;
    set<int> S;
    for(int i = 0; i < capacity; i++){
        f++;
        S.insert(arr[i]);
        mp[arr[i]] = 1;
    }
    for(int i = capacity; i < n; i++){
        auto it = S.find(arr[i]);
        if(it != S.end()){
            h++;
            mp[arr[i]]++;
        }
        else{
            f++;
            int ind = INT_MIN;
            for(auto x: mp){
                if(x.second > ind) ind = x.second;
            }
            mp.erase(arr[ind]);
            mp[arr[i]] = 1;
            S.erase(arr[ind]);
            S.insert(arr[i]);
        }
    }
}
int main(){
    int n, capacity;
    cin >> n >> capacity;
    int *arr = new int[n];
    for(int i = 0; i < n; i++) cin >> arr[i];
    mfu(arr,n,capacity);
    cout << "Page Faults -  " << f << '\n' << "Hit - " << h << '\n';
}
