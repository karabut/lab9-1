#include <sys/types.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define COMMAXLEN 30
#define FAIL -1
#define DEFAULT 0
#define CHILDPROCESS 0

int main() {
    int waitConst = -1;
    pid_t process = fork();
    if (process == FAIL) {
        perror("Error in fork()");
    }

    if (process != CHILDPROCESS) {

        int check = wait(&waitConst);
        if(check == FAIL){
            perror("Error in wait");
        }

        int exitCode = WEXITSTATUS(waitConst);

        if(exitCode != 0){
            printf("Child process ended unsuccessfully \n");
            return EXIT_FAILURE;
        }

        printf("return code оf child = %d \n", exitCode);
        printf("Parent process is on\n");

    } else {
        int execlRet = DEFAULT;
        execlRet = execl("/bin/cat","cat", NULL);

        if(execlRet == FAIL)
        {
            perror("Error in cat");
            return EXIT_FAILURE;
        }
    }
}

