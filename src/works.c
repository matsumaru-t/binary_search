#include <stdio.h>

int n;
int k;
int A[100000];

int p(int m){
  int sum = 0;
  int cnt = 0;
  for (int j = 0; j < n; j++){
    if (A[j] > m) return 0;
    if (sum + A[j] > m){
      sum = A[j];
      cnt++;
    }else{
      sum += A[j];
    }
  }
  return cnt < k;
}

int main(){
  int i, lb, ub;
  scanf("%d%d", &n, &k);
  for(i = 0; i < n; i++){
    scanf("%d", &A[i]);
  }

  lb = 0;
  ub = 1000000000;
  while (ub - lb > 1){
    int m = (ub + lb) / 2;
    if (p(m)) ub = m;
    else lb = m;
  }

  printf("%d\n",ub);

  return 0;
}
