#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <pthread.h>
float negative = 1;
double n;
double patrat(double x) {
    return x*x;
}

void *functie1(void *vargp) {
    if( n < 0 ) {
        negative = -1;
        n = n * (-1);
    }
    return NULL;
}

void *functie2(void *vargp) {
    double mid;
    double start = 0, end = n;

    double e = 0.000001;
    double error = n;
    if(n < 1) {
        start = 0;
        end = 1;
    }
    while (error > e)
    {
        mid = (start + end)/2;
        double root = mid*mid;

        if (root > n) {
            end = mid;
            error = (root - n);
        }
        else {
            start = mid;
            error =  (n - root);
        }
    }
    printf("%lf",negative*mid);
    return NULL;
}

int main(){
    printf("Introduce n de la tastatura:\n");
    scanf("%lf",&n);
    pthread_t id1,id2;
    pthread_create(&id1, NULL, functie1, NULL);
    pthread_join(id1, NULL);
    pthread_create(&id2, NULL, functie2, NULL);
    pthread_join(id2, NULL);
    return 0;
}
