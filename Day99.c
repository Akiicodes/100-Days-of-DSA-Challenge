/*Problem: Given a target distance and cars’ positions & speeds, compute the number of car fleets reaching the destination.
Sort cars by position in descending order and calculate time to reach target.*/
//Solution:
#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int position;
    double time;
} Car;

int compare(const void* a, const void* b) {
    Car* c1 = (Car*)a;
    Car* c2 = (Car*)b;

    return c2->position - c1->position;
}

int carFleet(int target, int* position, int positionSize, int* speed) {

    Car cars[positionSize];

    for (int i = 0; i < positionSize; i++) {

        cars[i].position = position[i];

        cars[i].time = (double)(target - position[i]) / speed[i];
    }

    qsort(cars, positionSize, sizeof(Car), compare);

    int fleets = 0;
    double maxTime = 0;

    for (int i = 0; i < positionSize; i++) {

        if (cars[i].time > maxTime) {

            fleets++;
            maxTime = cars[i].time;
        }
    }

    return fleets;
}

int main() {

    int target, n;

    scanf("%d", &target);

    scanf("%d", &n);

    int position[n];
    int speed[n];

    for (int i = 0; i < n; i++)
        scanf("%d", &position[i]);

    for (int i = 0; i < n; i++)
        scanf("%d", &speed[i]);

    printf("%d\n", carFleet(target, position, n, speed));

    return 0;
}