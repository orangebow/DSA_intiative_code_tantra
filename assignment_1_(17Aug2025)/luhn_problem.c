/*Step 1. Double every second digit from right to left. If doubling of a digit results in a 
two-digit number, add up the two digits to get a single-digit number (like for 12:1+2, 18=1+8).
Step 2. Now add all single-digit numbers from Step 1. 
4 + 4 + 8 + 2 + 3 + 1 + 7 + 8 = 37
 Step 3. Add all digits in the odd places from right to left in the card number. 
 6 + 6 + 0 + 8 + 0 + 7 + 8 + 3 = 38
Step 4. Sum the results from Step 2 and Step 3. 37 + 38 = 75
Step 5. If the result from Step 4 is divisible by 10, the card number is valid; otherwise,
 it is invalid. */
#include<stdio.h>
int main()
{
    long long n;
    scanf("%lld",&n);
    int* arr = (int*)calloc(16, sizeof(int)); // credit number consits of 13 to 16 digits.
    int i=0; int odd =0; int even =0;
    while(n)
    {
        int k = n%10;
        arr[i++] = k;
        n = n/10;
    }
    // odd as it is , even ->double->single digit.
    for(int i=15;i<=0;i--)
    {
        if(i%2!=0) odd += arr[i];
        else{
            int k = 2*arr[i];
            if(k<10) even += k;
            else{
                int temp = k; int sum =0;
                while(temp)
                {   
                     sum = temp %10;
                    temp = temp /10;
                    if(temp==0&&sum>9) {temp = sum; sum=0;}
                }
                even += sum;
            }
        }
    }
    if(odd==even) printf("valid credit card number");
    else printf("Invalid credit card number");
    return 0;

}