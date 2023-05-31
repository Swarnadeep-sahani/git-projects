#include<stdio.h>

void knapsack(int v[],int w[],int n,int W)
{
    int k[20][20],i,j;
    for ( i = 0; i <= n ; i++)
    {
        for ( j = 0; j <= W; j++)
        {
           if (i==0 || j==0) // if i & j both are zero then
           {
            k[i][j]=0;
           }
           else if (j<w[i])
           {
              k[i][j]=k[i-1][j]; // fill the above value
           }
           else
           {
            if(k[i-1][j]>k[i-1][j-w[i]]+v[i])
               k[i][j]=k[i-1][j];  // fill the above value
               else
                 k[i][j]=k[i-1][j-w[i]]+v[i];  // else fill the second term
           }
        } 
    }
    for ( i = 0; i <= n; i++) // for printing the 2 d table
    {
        for ( j = 0; j <= W; j++)
        {
            printf("  %d",k[i][j]);
        }
        printf("\n");
    }
    printf("---------------------");
    printf("\nMaximum possible profit = %d",k[n][W]);
    printf("\n-------------------");
}

void main()
{
    int v[20],w[20],i,j,n,W;
    printf("No of objects:\n");
    scanf("%d",&n);
    printf("\nCapacity of knapsack:\n");
    scanf("%d",&W);
    for(i=1;i<=n;i++)
    {
       printf("Enter weight and value of objects %d: ",i);
       scanf("%d%d",&w[i],&v[i]);
    }
    knapsack(v,w,n,W);
}