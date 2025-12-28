#include <stdio.h>

int josephus(int n, int k) {
    int result = 0; 

    for (int i = 2; i <= n; i++) {
        result = (result + k) % i;
    }

    return result + 1;
}

int main() {
    int n = 3; 
    int k = 7; 
    int survivor = josephus(n, k);
    printf("The safe position is: %d\n", survivor);

    return 0;
}

