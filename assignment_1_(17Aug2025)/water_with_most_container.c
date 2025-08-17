#include<stdio.h>
int maxArea(int* height, int heightSize) {
    int ans = 0;
       int low = 0;
       int high = heightSize-1;
       while(low<high)
       {
        int dist1 = height[low] < height[high]?height[low]:height[high];
        int dist2 = (high - low);
        int curr_area = dist1 * dist2;
        ans = ans> curr_area?ans:curr_area;
        if(height[low]> height[high]) high--;
        else low ++;

       }
       return ans;
    
}
int main()
{
  int n; scanf("%d",&n);
  int* arr = (int*)calloc(n, sizeof(int));
  for(int i=0;i<n;i++) scanf("%d",&arr[i]);
  maxArea(arr, n);
}