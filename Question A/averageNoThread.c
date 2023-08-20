#include <stdio.h>
#include <stdlib.h>

int main() {
    int N;
    unsigned int sumOfAllNumber = 0, average;
    scanf( "%d", &N );
    unsigned *numbers= ( unsigned * )malloc( N * sizeof( unsigned ) );
    for ( int i = 0; i < N; i++ ) {
        scanf( "%u", &numbers[ i ] );
    }
    for ( int i = 0; i < N; i++ ) {
        sumOfAllNumber += numbers[ i ];
    }
    average = sumOfAllNumber / N;
    printf( "%u", average );
    free( numbers );
    return 0;
}