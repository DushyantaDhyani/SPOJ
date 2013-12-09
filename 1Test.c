#include<stdio.h>
#include<stdlib.h>
int main()
{
	int num;
	while(1)
	{
		scanf("%d",&num);
		if(num==42){
			exit(0);
		}
		else{
			printf("%d\n",num);
		}
	}
	return 0;
}
