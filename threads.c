#include<stdio.h>
#include<pthread.h>
#include<sys/wait.h>
#include<unistd.h>


void* foo(void* arg){
    pid_t pid = getpid();
    printf("This Thread is of process : %d \n", pid);
    int *a;
    *a = 5;
    void *ret = (void*)a; 
    int *ar = arg;
    printf("%d Dude\n", ar[0]);
    return ret;
}

int main(){
    int i= 0 ;
    pid_t cid, pid; 
    void*  res;
    pthread_t tid;
    int ar[] = {3, 4, 5, 6, 7, 8};
    void* arg = (void*)ar;
    printf("%lu\n", sizeof(int));
    printf("Threading\n");
    pid=fork();
    if (pid == 0){
        pthread_create(&tid, NULL, foo, arg);
        for (i = 0; i< 5; i++){
            printf("Exec Child %d ......\n", getpid());
            sleep(1);
        }
    }

    if (pid != 0){
        pthread_create(&tid, NULL, foo, arg);
        for (i = 0; i< 5; i++){
            printf("Exec parent %d ......\n", getpid());
            sleep(1);
        }
    }
    
    pthread_join(tid, &res);
    int* ap = (int*)res;
    printf("%d Dude returned\n", *ap);
    return 0;
}