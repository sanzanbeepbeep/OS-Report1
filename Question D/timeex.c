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

    // Write 1GB of data (approx. 1024 * 1024 * 1024 bytes)
    const long long fileSize = 1024LL * 1024LL * 1024LL;
    const int bufferSize = 1024;  // Buffer size for writing (1KB)
    char buffer[bufferSize];

    for (long long i = 0; i < fileSize; i += bufferSize) {
        fwrite(buffer, sizeof(char), bufferSize, file);
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
