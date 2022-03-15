#include<stdio.h>
#include<pthread.h>
int a[50],n,min,max;
float avg;
void *thread_avg();
void *thread_min();
void *thread_max();

void *parent()
{
    pthread_t th2;
    pthread_t th3;
    pthread_t th4;
	scanf("%d",&n);
	for(int i=0;i<n;i++){
	    scanf("%d",&a[i]);}
	pthread_create(&th4,NULL,&thread_avg,NULL);
    pthread_join(th4,NULL);
    printf("The average value is %.2f",avg);
	pthread_create(&th2,NULL,&thread_min,NULL);
    pthread_join(th2,NULL);
    printf("\nThe minimum value is %d",min);
	pthread_create(&th3,NULL,&thread_max,NULL);
    pthread_join(th3,NULL);
    printf("\nThe maximum value is %d",max);


    return 0;

}
void *thread_avg()
{
    float sum = 0;
    for(int i=0;i<n;i++)
        sum=sum+a[i];
    avg=sum/n;
    return NULL;
}
void *thread_min()
{
	int temp=a[0];
	for(int i=1;i<n;i++)
		{
			if(temp>a[i])
			{
			temp=a[i];
			}
		}
    min=temp;
    return NULL;

}
void *thread_max()
{
	int temp=a[0];
	for(int i=1;i<n;i++)
		{
			if(temp<a[i])
			{
			temp=a[i];
			}
		}
    max=temp;
    return NULL;
}

int main()
{
    int n,i;
    pthread_t th1;

	n=pthread_create(&th1,NULL,&parent,NULL);
	pthread_join(th1,NULL);
	
}
