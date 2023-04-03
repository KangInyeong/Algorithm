#include<stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <string.h>
#include <unistd.h>
#include <stdlib.h>

int main(){
    int fd = open("./test.txt" , O_RDWR, 0);
    
    char buf[1000] = {0,};
    int filesize = read(fd, buf, 1000-1);
    close(fd);

    fd = open("./test.txt", O_RDWR, 0);
    int num;
    scanf("input number: %d", &num);
    
    int flag = 0;
    char newtxt[1000] = {0,};
    while(flag < filesize){
        char sentence[20] = {0,};
        char tmp[2] = {0,};
        int i = 0;
        int flag = 0;
        while(strcmp(tmp, "\n") != 0){
            read(fd, tmp, 1);
            //if(atoi(tmp) >= 1 && atoi(tmp) <= 100){
            //    flag = 0;
            //    if(atoi(tmp) == num){
            //        flag = 1;
            //        printf("hello");
            //    }
            //}
            //if(flag == 0){
            if(atoi(tmp) == num){
                printf("4dk\n");
            }
                sentence[i] = tmp[0];
                i++;
            //}

        }
        //read(fd, tmp, 1);
        //if(strcmp(tmp, "\n") == 0){
        //    printf("ehlej\n");
        //}
        
        printf("%s\n", sentence);
        flag += i;

    }
    close(fd);

    return 0;
}
