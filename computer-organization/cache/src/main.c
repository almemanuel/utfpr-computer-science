#include <sys/time.h>
#include <stdio.h>
#include <stdlib.h>

struct pix {
    unsigned int r, g, b;
};

int test1(int size) {
    struct pix color[size][size];

    // test 1
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            color[i][j].r = (
                color[i][j].r +
                color[i][j].g +
                color[i][j].b
            ) / 3;
        }
    }

    return 0;
}

int test2(int size) {
    struct pix color[size][size];

    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            color[j][i].r = (
                color[j][i].r +
                color[j][i].g +
                color[j][i].b
            ) / 3;
        }
    }

    return 0;
}

int main(){
    double ti, tf;
    struct timeval initial_time, final_time;
    FILE *fp = fopen("table.csv", "w");

    printf("RGB TO GREYSCALE CONVERSION SIMULATOR\n");
    printf("Random Mode\n");
    int total_to_generate = rand() % 100 + 1;
    int size;
    int test[2];
    double time1, time2;
    int count = 0;
    do {
        printf(" [*] %d/%d tests generated\n", count, total_to_generate);
        size = rand() % 100 + 1;
        printf("  -  Size: %d\n", size);

        gettimeofday(&initial_time, NULL);

        test[0] = test1(size);

        gettimeofday(&final_time, NULL);

        tf =(double)final_time.tv_usec + (double)final_time.tv_sec * 1000000.0;
        ti =(double)initial_time.tv_usec + (double)initial_time.tv_sec * 1000000.0;
        time1 = tf - ti / 1000;
        printf("  -  Time from test 1: %.3fms\n", time1);

        gettimeofday(&initial_time, NULL);

        test[1] = test2(size);

        gettimeofday(&final_time, NULL);
        tf =(double)final_time.tv_usec + (double)final_time.tv_sec * 1000000.0;
        ti =(double)initial_time.tv_usec + (double)initial_time.tv_sec * 1000000.0;
        time2 = tf - ti / 1000;
        printf("  -  Time from test 2: %.3fms\n", time2);

        fprintf(fp, "%d, %.3f, %.3f\n", size, time1, time2);

        count++;
    } while (count < total_to_generate);

    fclose(fp);

    return 0;
}