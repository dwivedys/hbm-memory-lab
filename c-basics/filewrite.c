#include <stdio.h>
#include <stdlib.h>
int main() {
    FILE *fp = fopen("test", "w+");
    if(!fp) {
        perror("Error opening file");
        exit(1);
    }
    
    const char * const msg = "What might be a good idea is to keep trying";
    char *msg2 = "some message";
    msg = msg2;
    // fprintf - into file pointer using format string write content from msg
    //fprintf(fp, "%s", msg);
    
    // fputs message into file pointer
    fputs(msg, fp);
    
    rewind(fp);
    
    char buf[1024];
    while(fgets(buf, sizeof(buf), fp)) {
        printf("%s", buf);
    }
    printf("\n");
    fclose(fp);

    return 0;

}