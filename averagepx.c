#include<omp.h>
#include<stdio.h>
#include<stdlib.h>

int main()
{
    int N;
    unsigned int sumOfAllNumber = 0, average;
    //Thread ที่ใช้
    int ThreadNum = 4;
    unsigned int *sumOfEachThread = ( unsigned int * )malloc( ThreadNum * sizeof( unsigned int ) );
    scanf( "%d", &N );
    unsigned int *number = ( unsigned * )malloc( N * sizeof( unsigned ) );
    for( int i = 0; i < N; i++ )
    {
        // รับค่าตัวเลข
        scanf( "%u", &number[i] );
    }

    #pragma omp parallel num_threads( ThreadNum )
    {
        // id ของ Thread นั้นๆ
        int id = omp_get_thread_num();
        // จำนวน Thread ทั้งหมด
        int numThread = omp_get_num_threads();
        unsigned int sum = 0;
        for( int i = id; i < N; i += numThread )
        {
            sum += number[i];
        }
        // บันทึกผลรวมของแต่ละ Thread
        sumOfEachThread[id] = sum;
        //printf( "Thread %d : %u\n", id, sum );


        // รอให้ทุก Thread ทำงานเสร็จ
        #pragma omp barrier
        // ทำงาน Thread เดียว
        #pragma omp single
        {
            for( int i = 0; i < ThreadNum; i++ )
            {
                sumOfAllNumber += sumOfEachThread[i];
            }
            average = sumOfAllNumber / N;
            printf( "%u\n", average );
        }
    }
    free( number );
    return 0;
}