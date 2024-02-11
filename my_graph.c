#include <stdio.h>
#include <math.h>
#include "my_mat.h"
#include "my_mat.c"
#define N 10

int main(){
int i, j;
char x='1';

while (x !='D'){
scanf("%c", &x);
if(x=='A'){
GetArr();
ShortestPaths();
}

if(x=='B'){
scanf("%d",&i);
scanf("%d", &j);
if(mat[i][j] >0){
printf("True\n");
}
else{
printf("False\n");
}
}

if(x=='C'){
scanf("%d",&i);
scanf("%d", &j);
if(mat[i][j]==0){
printf("-1\n");
}
else{
printf("%d\n", mat[i][j]);
}
}
}
}

