#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#define SIZE 256

int main() {
    
    const char *envs[] = {"HOME", "SHELL", "JAVA", "PYTHON"}; // array of pointers to null terminated c-strings
    int sz = sizeof(envs)/sizeof(envs[0]);
    int orig_sz = sz;
    char *env_copies[sz];
    for(int i = 0; i < sz; i++) {
        env_copies[i] = malloc(SIZE); // env_copies[i] is a pointer to null terminated c-string
        if(env_copies[i] == NULL) {
            perror("Error allcating memory");
            return 1;
        }
    }
    // populate env_copies
    const char *path; // to hold the path to the env var
    const char **p_envs = envs; // to walk through envs array
    char **p_envcopies = env_copies; // to walk through the env_copies array which will hold the env var paths
    while(sz--) {
        path = getenv(*p_envs); // we deref p_envs to the actual string pointed to by the addr in the array
        if(NULL == path) {
            printf("Env %s not set\n", *p_envs);
        } else {
            printf("Env: %s=%s\n", *p_envs, path);
            strncpy(*p_envcopies, path, SIZE - 1);
            (*p_envcopies)[SIZE-1] = '\0';
            p_envcopies++;
            //p_envs++;
        }
        p_envs++;

    }

    // free

    for(int i = 0; i < orig_sz; i++) {
        free(env_copies[i]);
    }

    return 0;

}