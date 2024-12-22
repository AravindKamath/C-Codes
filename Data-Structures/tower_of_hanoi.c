#include <stdio.h>
#include <stdlib.h>

void tower_of_hanoi(int n, char source, char temp, char destination) {
    if (n == 1) {
        printf("Move disk %d from %c to %c\n", n, source, destination);
        return;
    }
    else {
        tower_of_hanoi(n - 1, source, destination, temp);
        printf("Move disk %d from %c to %c\n", n, source, destination);
        tower_of_hanoi(n - 1, temp, source, destination);
    }
}

void main() {
    int n = 3;
    tower_of_hanoi(n, 'A', 'B', 'C');
}
