
#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <pthread.h>


int main() {
    
    uint64_t tid;
    pthread_threadid_np(NULL, &tid);

    printf("My process id is: %d\n", getpid());
    printf("Thread id is: %llu\n", tid);

    return 0;
}