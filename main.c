#include HEADER
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <time.h>
#include <limits.h>

int main(void)
{
#if defined(PI)
    printf("pid: %d\n", getpid());
    sleep(10);
    compute_pi_baseline(50000000);
#elif defined(MATRIX)
    static int array[10000][10000] = {0};
    matrix(10000,10000,array);
#elif defined(BRANCH)
    srand(time(NULL));
    int src1[100000], src2[100000];
    int dst[200000] = {0};
    int i;
    
    for (i = 0; i < 100000; i++) {
        src1[i] = i + rand() % 10;
        src2[i] = i + rand() % 10;
    }
    merge(src1, src2, dst, 100000);
#endif
    return 0;

}


