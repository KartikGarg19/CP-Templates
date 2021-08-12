// Longest increasing sub-sequence
#include<iostream>
#include<vector>
#include<set>
using namespace std;

int main(){
    vector<int> a = {1, 2, 5, 6, 4};
    set<int> s;
    for(int i=0; i<a.size(); i++){
        s.insert(a[i]);
        auto it = s.upper_bound(a[i]);
        if(it != s.end()) s.erase(it);
    }
    cout<<s.size()<<endl;  // Length of Longest increasing sub-sequence

    vector<int> b = {1, 2, 1, 5, 7, 6, 5, 4};
    multiset<int> ms;
    for(int i=0; i<b.size(); i++){
        ms.insert(b[i]);
        auto it = ms.upper_bound(b[i]);
        if(it != ms.end()) ms.erase(it);
    }
    cout<<ms.size()<<endl;  // Length of Longest non-decreasing sub-sequence

    return 0;
}