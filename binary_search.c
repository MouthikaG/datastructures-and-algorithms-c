#include <stdio.h>
int main() {
    int n,key,low=0,high,mid;
    scanf("%d",&n);
    int arr[n];
    for(int i=0;i<n;i++) scanf("%d",&arr[i]);
    scanf("%d",&key);
    high=n-1;
    while(low<=high){
        mid=(low+high)/2;
        if(arr[mid]==key){
            printf("Found\n"); return 0;
        }
        if(key<arr[mid]) high=mid-1;
        else low=mid+1;
    }
    printf("Not found\n");
}

