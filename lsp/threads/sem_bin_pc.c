#include <pthread.h>
#include<stdio.h>
#include<semaphore.h>

sem_t pro,con;
char buff[5];
int counter;
void *producer(void *arg)
{
    int in=0;
    char ch='A';
    while(1)
    {
        /*while(counter==5);
          buff[in]=ch;
          in=(in+1)%5;
          ch++;
          if(in==0)
          {
          ch='A';
          printf("producer:%s\n",buff);
          }
          counter++;*/
        sem_wait(&pro);
        for(in=0;in<5;in++)
        {
            buff[in]=ch;
            ch++;
        }
        ch='A';
        printf("pro:%s\n",buff);
        sem_post(&con);
    }
    pthread_exit("I am done");
}


void *consumer(void *arg)
{
    char temp[5];
    int out=0;
    while(1)
    {
        /* while(counter==0);
           temp[out]=buff[out];
           out=(out+1)%5;
           if(out==0)          //without semaphore synchroning with global variable
           {
           printf("consumer:%s\n",temp);
           }
           counter--;
           }*/
    //using binary semaphore synchronization
    sem_wait(&con);
    for(out=0;out<5;out++)
    {
        temp[out]=buff[out];
    }
    printf("con:%s\n",temp);
    sem_post(&pro);
}
pthread_exit("consumer is done");
}

int main()
{
    pthread_t thread1,thread2;
    sem_init(&pro,1,1);
    sem_init(&con,1,0);
    int ret=pthread_create(&thread1,NULL,producer,NULL);
    if(ret!=0)
    {
        perror("thread creation fail");
    }
    ret=pthread_create(&thread2,NULL,consumer,NULL);
    if(ret!=0)
        perror("thread creation failure");
    void *retval,*retval2;
    pthread_join(thread1,&retval);
    pthread_join(thread2,&retval2);
    printf("%s\n",(char *)retval);
    printf("%s\n",(char *)retval2);


}

