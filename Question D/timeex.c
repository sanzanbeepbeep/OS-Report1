#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// I/O-bound operation: Reading and writing to a file
void ioBoundOperation() {
    FILE *file = fopen("io_file.txt", "w");
    if (file == NULL) {
        perror("File opening failed");
        return;
    }

    for (int i = 0; i < 100000; ++i) {
        fprintf(file, "This is line %d\n", i);
    }

    fclose(file);
}

// CPU-bound operation: Performing a large number of calculations
void cpuBoundOperation() {
    double result = 0.0;
    for (int i = 0; i < 100000000; ++i) {
        result += (double)i * i;
    }
}

int main() {
    clock_t start, end;
    double cpuTimeUsed, ioTimeUsed;

    // Measure time for I/O-bound operation
    start = clock();
    ioBoundOperation();
    end = clock();
    ioTimeUsed = ((double)(end - start)) / CLOCKS_PER_SEC;

    // Measure time for CPU-bound operation
    start = clock();
    cpuBoundOperation();
    end = clock();
    cpuTimeUsed = ((double)(end - start)) / CLOCKS_PER_SEC;

    printf("I/O-bound operation took %.4f seconds\n", ioTimeUsed);
    printf("CPU-bound operation took %.4f seconds\n", cpuTimeUsed);

    // Delete the file
    remove("io_file.txt");

    return 0;
}
