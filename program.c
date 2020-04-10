#include<stdio.h>
#include<pthread.h>
//global variables
int a[50],n,i;

void *Average()
{
	int sum=0;
        float avg;
	printf("enter the no of elements in the array: ");
	scanf("%d",&n);
        printf("Enter the elements of the array: ");
	for(i=0;i<n;i++)
	{
		scanf("%d",&a[i]);
	}
	for(i=0;i<n;i++)
		{
			sum=sum+a[i];
		}
        avg=sum/n;
	printf("The average value is: %f",avg);
}
void *Minimum()
{


	int t=a[0];
	for(int i=1;i<n;i++)
		{
			if(t>a[i])
			{
			t=a[i];
			}
		}
	printf("\nThe Minimum  value is: %d",t);
}
void *Maximum()
{
        int t=a[0];
	for(int i=1;i<n;i++)
		{
			if(t<a[i])
			{
			t=a[i];
			}
		}
	printf("\nThe Maximum  value is: %d\n",t);
	}
int main()
{
int n,i;
        //average
        pthread_t k1;
        pthread_create(&k1,NULL,&Average,NULL);
	pthread_join(k1,NULL);
	//minimum
        pthread_t k2;
	pthread_create(&k2,NULL,&Minimum,NULL);
        pthread_join(k2,NULL);
	//maximum
        pthread_t k3;
	pthread_create(&k3,NULL,&Maximum,NULL);
        pthread_join(k3,NULL);
}
