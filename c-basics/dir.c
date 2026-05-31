#include <dirent.h>
#include <stdio.h>

int main() 
{
    int z = 1;
    DIR *dir = opendir("/Users/dwivedysaurabh/");
    struct dirent *e;
    while((e = readdir(dir))) {
        printf("%d: %s\n", z, e->d_name);
        z++;
    }
    closedir(dir);
    return 0;

}
