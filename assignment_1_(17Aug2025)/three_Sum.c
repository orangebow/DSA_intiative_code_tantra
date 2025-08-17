#include<stdio.h>
#include<stdlib.h>
//return all the triplets that adds to the zero.
// -1e5 <= arr[i] <= 1e5;
typedef struct triad{
    int nums[3];
}triad;
int cmp(const void* a, const void* b) {
   
    int* val_a = (int*)a;
    int* val_b = (int*)b;
    return (*val_a - *val_b);
}
int main()
{
    int n;
    scanf("%d",&n);
    int* arr = (int*)calloc(n, sizeof(int));
    for(int i=0; i<n;i++) scanf("%d",&arr[i]);
    triad* result = (triad*)calloc(n, sizeof(triad));
    //sort the array; 
    qsort(arr,n,sizeof(int),cmp);
    int res =0;
    for(int i=0;i<n;i++)
    {
        if(i>0 && arr[i]==arr[i-1]) continue;

        int j = i+1; int k = n-1;
        while(j<k){
            int total = arr[i]+arr[j]+arr[k];
            if(total>0) k--;
            else if(total<0)j++;
            else{
                    result[res].nums[0]=i;
                    result[res].nums[1]=j;
                    result[res].nums[2]=k;
                    res++;
                    j++;
                    while(arr[j]==arr[j-1]&&j<k) j++;
            }
        }

    }
    // our answer is stored in result array;
    return 0;
    

}