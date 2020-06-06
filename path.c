/*Implementation if DFS in 1D C array.
Date: 5.10.2019
Author: Harsh Mahajan
Reference: https://algs4.cs.princeton.edu/41graph/DepthFirstPaths.java.html
*/
#include<stdio.h>
#include<stdbool.h>

int find_path(int n, int m, int A[], int i, int j, int k, int l, int path [][2]) {
  if (A[i*m + j] == 1 || A[k*m + l] == 1){
      return -1;
  }
  if (i < 0 || n <= i){
      return -2;
  }
  if (j < 0 || m <= j){
      return -3;
  }

  int L = 0;

  while (true) {
    A[i*m+j] = -1;// marking every position we vist
    if (i == k && j == l) {//checking if destination was reached

      path[L][0]= k;
      path[L][1]= l;
      L++;

      break;
    }
    else if(0 <= i - 1 && A[(i - 1)*m + j] == 0 && (A[(i-1)*m + j] != -1)){
      //We check if the index is within the row/column, if a path exists(i.e., 0) and then mark the path.
      path[L][0] = i;
      path[L][1] = j;
      L++;
//We try and move up
      // printf("UP\n");

      i--;
  //similar operations will be done to try and move left, right and down.
    }
    else if(j + 1 < m && A[i*m + j + 1] == 0 && (A[i*m + j + 1] != -1)) {
      path[L][0] = i;
      path[L][1] = j;

      L++;

      // printf("  RIGHT\n");


      j++;
    }
    else if (i + 1 < n && A[(i + 1)*m + j] == 0 && (A[(i+1)*m + j] != -1)) {
      path[L][0] = i;
      path[L][1] = j;

      L++;

      // printf("  DOWN\n");


      i++;
    }
    else if(0 <= j - 1 && A[i*m + j - 1] == 0 && (A[i*m + j - 1] != -1)) {
      path[L][0] = i;
      path[L][1] = j;

      L++;

      // printf("  LEFT\n");

      j--;
    }
    else {
//Here, we either reach a dead end(i.e., 1) or the end of the row/column and we need to back trace our path.

      i = path[L - 1][0];
      j = path[L - 1][1];

      // printf("  BACK\n");

      path[L - 1][0]= 0;//we set the path to 0,0 so as it could be later over-written.
      path[L - 1][1]= 0;
      L--;
      if (L == 0){return -1;}// in this case, path does not exist.
    }
  }
  for (int col = 0; col < (m); col++){
    for (int row = 0; row < (n+1); row++){
      if (A[col*m + row] == -1){
        A[col*m + row] = 0;
      }
    }
  }
  return L;
}
/* This is the way i tested the code...*
int main() {
  int n = 3, m = 4, i= 0, j = 0, k = 1, l = 0;
  // int A[3*4] = {0,1,0,0,1,0,0,1,1,0,1,0};
  int B[5*6] = {1,1,1,1,0,1,
                0,0,0,0,0,0,
                1,1,1,1,0,1,
                0,0,0,0,0,1,
                0,0,1,0,1,1};
  int path[30][2] = {0};

  printf("\n=\n%d\n=\n", find_path(5, 6,  B,  1,  0,  3, 0, path));
  for (int i = 0; i < 30; i += 1) {
    printf("(%d, %d)\n", path[i][0], path[i][1]);
  }


  // printf("\n=\n%d\n=\n", find_path(3, 4,  A,  1,  1,  0,  3, path));
  // for (int i = 0; i < 12; i += 1) {
  //   printf("(%d, %d)\n", path[i][0], path[i][1]);
  // }
}*/
