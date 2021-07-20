#include <stdlib.h>
#include <stdio.h>

void print(int *arr,int len){
	int i;
	for(i=0;i<len;i++)
		printf("%d\t",arr[i]);
	putchar('\n');
}
int sum_arr(int *arr,int len){
	int i;
	int sum = 0;
	for(i=0;i<len;i++)
		sum+=arr[i];
	return sum;
}
void dice_rec(int *arr,int len,int index,int sum){
	if(index<len-1)
		dice_rec(arr,len,index+1,sum);
	else if(sum_arr(arr,len)==sum)
		print(arr,len);
	if(arr[index]<6){
		arr[index]++;
		dice_rec(arr,len,index,sum);
	}
	arr[index]=1;
}
void run(){
	int amount_dices;
	int sum;
	int *arr;
	int i;
	printf("Enter amount of dices\n");
	scanf("%d",&amount_dices);
	printf("Enter sum\n");
	scanf("%d",&sum);
	arr=(int*)malloc(sizeof(int)*amount_dices);
	for(i=0;i<amount_dices;i++)
		arr[i]=1;
	printf("All posible combinations of %d dices with sum %d\n",amount_dices,sum);
	dice_rec(arr,amount_dices,0,sum);
}
void main(){
	run();
}
