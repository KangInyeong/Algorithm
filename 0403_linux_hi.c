#include<stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <string.h>
#include <unistd.h>
#include <stdlib.h>

int main(){
    int fd = open("./test.txt" , O_RDWR, 0);
    if(fd<0){
          printf("FILE OPEN ERROR\n");
          exit(1);
    }

    char buf[1000] = {0,};
    int filesize = read(fd, buf, 1000-1);
    close(fd);

    int num;
    scanf("input number: %d", &num);
    
    fd = open("./test.txt", O_RDWR | O_TRUNC, 0);
    if(fd<0){
          printf("FILE OPEN ERROR\n");
          exit(1);
    }

    int cnt = 1;
    char newstr[1000] = {0,};
    char tmp[10] = {0,};
    int i = 0;
    int idx = lseek(fd, i, SEEK_CUR);
    read(fd, tmp, 9);
    printf("%d %s\n", idx; tmp);
    strcat(newstr, tmp);
    i += 9;

    while(idx < filesize){
        if(cnt == num){
            i += 9;
            cnt++;
        }
        memset(tmp, 0, sizeof(tmp));
        idx = lseek(fd, i, SEEK_CUR);
        read(fd, tmp, 9);
        printf("%d %s\n", idx, tmp);    
        strcat(newstr, tmp);
        i += 9;
        cnt++;
    }

    printf("newstr : %s", newstr);
    close(fd);

    return 0;
}
