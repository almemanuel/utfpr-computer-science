#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    int die[6] = {500, 99, 102, 97, 104, 98}; // i + 1 = die number

    int abs_frequence = 0;
    for(int i = 0; i < sizeof(die) / sizeof(die[0]); i++) {
        abs_frequence += die[i];
    }

    float rel_frequence[6];
    for(int i = 0; i < sizeof(die) / sizeof(die[0]); i++){
        rel_frequence[i] = (float)die[i] / abs_frequence;
    }

    float ac_rel_frequence[6];
    for(int i = 0; i < sizeof(die) / sizeof(die[0]); i++){
        ac_rel_frequence[i] = 0;
        for(int j = 0; j <= i; j++){
            ac_rel_frequence[i] += rel_frequence[j];
        }
    }

    printf("Initial Parameters\nDie\t\tAbsolut\t\tRelative\t\tAc\n");
    for(int i = 0; i < sizeof(die) / sizeof(die[0]); i++) {
        printf("%d\t\t%d\t\t%f\t\t%.3f\n", i + 1, die[i], rel_frequence[i], ac_rel_frequence[i]);
    }

    printf("\nSimulating die...\n");

    // simulator
    srand(time(NULL));
    int sim_die[6] = {0};
    int n = 100000000;
    for(int i = 0; i < n; i++){
        float random = (float)rand() / (float)(RAND_MAX);
        for(int j = 0; j < sizeof(ac_rel_frequence) / sizeof(ac_rel_frequence[0]); j++) {
            if((j == 5) | random < ac_rel_frequence[j]) {
                sim_die[j]++;
                break;
            }
        }
    }

    float sim_rel_frequence[6];
    for(int i = 0; i < sizeof(sim_die) / sizeof(sim_die[0]); i++){
        sim_rel_frequence[i] = (float)sim_die[i] / n;
    }

    printf("Die\t\tAbsolut\t\tRelative\n");
    for(int i = 0; i < sizeof(die) / sizeof(die[0]); i++) {
        printf("%d\t\t%d\t\t%f\n", i + 1, sim_die[i], sim_rel_frequence[i]);
    }

    return 0;
}