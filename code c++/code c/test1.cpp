#include <stdio.h>
#include <stdlib.h>
#include <math.h>

void nhap(int *n, int **a, int **b) {
    FILE *f = fopen("input.txt", "r");
    if (f == NULL) {
        perror("Failed to open file");
        exit(EXIT_FAILURE);
    }

    fscanf(f, "%d", n);
    *a = (int *)calloc(*n, sizeof(int));
    *b = (int *)calloc(*n, sizeof(int));

    for (int i = 0; i < *n; i++) {
        fscanf(f, "%d %d", (*a + i), (*b + i));
    }

    fclose(f);

    for (int i = 0; i < *n; i++) {
        printf("%d %d \n", (*a)[i], (*b)[i]);
    }
}

void tim_max(int n, int a[], int b[]) {
    float c,d=10000000;
    for (int i = 0; i < n; i++) {
        if ((a[i] % 2 == 0 && b[i] % 2 != 0) || (a[i] % 2 != 0 && b[i] % 2 == 0)) {
          c=sqrt(pow(a[i],2)+pow(b[i],2));
          if (d>c)
          {
            d=c;
          }
          
        }
    }printf("%f",d);
}

int main() {
    int n;
    int *a;
    int *b;
    nhap(&n, &a, &b);
    tim_max(n, a, b);
    free(a);
    free(b);  
  
    return 0;
}
