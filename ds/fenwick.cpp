#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int N = 1e6 + 4;
vector<int> tree(N, 0);
int bitMask;

//read outputs commulative frequency at index idx
int read(int idx) {
  int sum = 0;
  while (idx > 0) {
    sum += tree[idx];
    idx -= (idx & -idx);
  }
  return sum;
}

//update adds val at index idx of frequency
void update(int idx, int val) {
  while (idx <= N) {
    tree[idx] += val;
    idx += (idx & -idx);
  }
}

//readSingle outputs actual frequency at position idx
int readSingle(int idx) {
  int sum = tree[idx];
  if (idx > 0) {
    int z = idx - (idx & -idx);
    idx--;
    while (idx != z) { 
      sum -= tree[idx];
      idx -= (idx & -idx);
    }
  }
  return sum;
}

//scale scales(divides) all frequencies by a factor of c
void scale(int c) {
  for (int i = 1; i <= N; i++)
    tree[i] = tree[i] / c;
}

//bitMask - initially it is the greatest bit of N
//find Finds index with given cumulative frequency
int find(int cumFre) {
  int idx = 0;

  while (bitMask != 0) {
    int tIdx = idx + bitMask;
    bitMask >>= 1;
    if (tIdx > N)
      continue;
    if (cumFre == tree[tIdx])
      return tIdx;
    else if (cumFre > tree[tIdx]) {
      idx = tIdx;
      cumFre -= tree[tIdx];
    }
  }
  if (cumFre != 0)
    return -1;
  else
    return idx;
}

int main(){
     
}