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
        if(x=='A')
        {
            GetArr();
            ShortestPaths();
        }
        else if(x== 'B')
        {
            scanf("%d",&i);
            scanf("%d", &j);
            printf("%s\n", (mat[i][j] > 0) ? "True" : "False");
        }
        else if(x == 'C')
        {
            scanf("%d",&i);
            printf("%d\n", (mat[i][j] == 0) ? -1 : mat[i][j]);
        }
    }
    return 0;
}
