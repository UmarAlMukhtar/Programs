//LINEAR SEARCH :
#include <stdio.h>

int linear_search(int [],int,int);

int main() {
	int a[10],n,key,i,index;
	printf("enter the size of the array\n");
	scanf("%d",&n);
	printf("enter the elements into the array\n");
	for(i=0;i<n;i++)
		scanf("%d",&a[i]);
	printf("enter the key value to be found\n");
	scanf("%d",&key);
	index=linear_search(a,n,key);
	if(index == -1)
		printf("sorry, key value cannot be found\n");
	else
		printf("%d is found at index %d\n",key,index);
	return 0;
}

int linear_search(int a[],int n,int key) {
	int i;
	for(i=0;i<n;i++) {
		if(a[i] == key)
		return i;
	}
	return -1;
}
