#include <stdlib.h>
#include <stdio.h>
#include <errno.h>
#include <unistd.h>
#include <pthread.h>
 #include <time.h>
#define xm 600
#define ym 600


int iterator=0;
int *str;
pthread_mutex_t	mutex=PTHREAD_MUTEX_INITIALIZER;
void *bal(void *argc) {
    int num = * (int *)argc;
 
    int x, y;
    int  dy, dx;
printf("Ball number %d", num);
    dx = rand() % 20+5;
    dy = rand() % 20+5;
    
    x = rand() % 500 + 10;
    y = rand() % 500 + 10;
    printf("Ball number %d is runing, dx=%d, dy,==%d, x=%d,y=%d \n", num,dx,dy,x,y);
sleep(1);
while (y >= 0)
{
    x = x + dx;
    y = y + dy;
    if (y >= ym) {
        y = ym;
        dy = dy * (-1);
        }
    if (x >= xm) {
        x = xm;
        dx = dx * (-1);
        }

    if (x <= 0) {
        x = 0;
        dx = dx * (-1);
    }
    pthread_mutex_lock(&mutex);
   printf("Ball number %d", num);
   printf(": X = %d ", x);
   printf(" Y = %d \n", y);
    pthread_mutex_unlock(&mutex);
    usleep(100000);
    }
    pthread_mutex_lock(&mutex);
    str[iterator]=num;
    iterator++;
     pthread_mutex_unlock(&mutex);
    pthread_exit(NULL);
}

int main(){
	int  result,count;
	
    printf("Inter count ball: ");
    scanf("%d",&count);
    pthread_t thread[count-1];
	  int statusmas[count-1];
    str=statusmas;

    for(int i=1;i<(count+1);i++){
	result = pthread_create(&thread[(i-1)], NULL, bal, &i);
	if (result != 0) {
		printf("Eror Creating the %d thread",i);
		return EXIT_FAILURE;
	    }
    printf("Creating the %d thread\n",i);
    usleep(100000); 
    }
    for(int i=1;i<(count+1);i++){
	result = pthread_join(thread[(i-1)], NULL);
	if (result != 0) {
		printf("Eror Joining the %d thread",i);
		return EXIT_FAILURE;
	}

	}
    for(int i=0;i<iterator;i++)
    {
     printf("The ball %d completed the work under the number %d\n",str[i],(i+1));
    }
	printf("Done\n");
	return EXIT_SUCCESS;
}
