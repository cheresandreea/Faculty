#include <stdio.h>
int relatively_prime(int a, int b)
{
    int number_divisors = 0, i;
    for (i=2; i<= a; i++)
        if (a%i == 0 && b%i == 0)
            number_divisors ++;
    return number_divisors;
}

int citire(int n, int v[])
{
    int i;
    for (i=0; i<n; i++)
        scanf("%d", &v[i]);
}

int afisare(int n, int v[])
{
    int i;
    for (i=0; i<n; i++)
        printf("%d", v[i]);
}

int lungime_maxima(int n, int v[])
{
    int vector_final[100];
    int st = 0;
    int sum, i, lg, lgmax, k, j;
    int sum_fin; 
    sum_fin = v[0];
    for (i=0; i<n; i++)
        lg ++;
        sum = sum + v[i];
        if (sum < v[i])
            lg = 1;
            sum = v[i];
        if (sum >= sum_fin)
            sum_fin = sum;
            if (lg > lgmax)
            {
                lgmax = lg;
                k = 0;
                for (j=st; j<i; j++)
                    vector_final [k] = v[j];
                    k++;
                st = i;
                sum = 0;
                lg = 0;
                    
            }
    return lgmax;
        
}
       

int main()
{
    //a. Determine all the numbers smaller than a given natural and non-null number n 
    //and that are relatively prime to n.
    //b. Given a vector of numbers, find the longest contiguous subsequence with the maximum sum.
    

    //for (i=0; i<=n; i++)
        //printf("%d", i);
    int a = 11;
    int b = 15;
    if (relatively_prime(a,b) > 0)
        printf("Not relative prime!");
    else
        printf("Relative prime!");
    
    int n, i;
    scanf("%d",&n);
    printf("%d", n);
    int v[100];
    //int x[10];
    citire(n, v);
    afisare(n,v);
    prinf(" ");
    printf("%d", lungime_maxima(n,v));            

    if (relatively_prime(a,b) > 0)
        printf("Not relative prime!");
    else
        printf("Relative prime!");
        
    //int v[10] = {1,-2,3,-14,5,6,7,-8,9,0};
    //int x[10];
 

    
            
    
    return 0;
}
