#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main (int argc, char **argv){

    double x;
    x = atof(argv[1]);

    if (x < 2){
        printf("Low CPU usage!\n");
    }
    else if(x > 10){
            printf("High CPU usage!\n");
    }
    else{
            printf("Moderate CPU usage!\n");
        }

    return 0;
}
