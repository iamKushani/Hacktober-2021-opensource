
#include<stdio.h>
#include<stdlib.h>

int main()
{
    int n,u,v,min=999,mincost=0,cost[10][10],visited[10]={0},i,j,a,b,count=1;

    printf("Enter the number of vertex\n");
    scanf("%d",&n);

    printf("Enter the cost matrix.(Put 999 for Infinity)\n");
    for(i=1;i<=n;i++)
    {
        for(j=1;j<=n;j++)
        {
            scanf("%d",&cost[i][j]);
            if(cost[i][j]==0)
                cost[i][j]=999;
        }
    }
    visited[1]=1;

    printf("The edges of the Spanning tree are:\n");
    while(count<n)
    {
        min=999;
        for(i=1;i<=n;i++)
        {
            for(j=1;j<=n;j++)
            {
                if(cost[i][j] < min)
                {
                    if(visited[i]==0)
                        continue;
                    else
                    {
                        min=cost[i][j];
                        a=u=i;
                        b=v=j;
                    }
                }
            }
        }
         if(visited[u]==0 || visited[v]==0)
            {
                count++;
                printf("Edge(%d,%d) = %d\n",a,b,min);
                mincost +=min;
                visited[b]=1;
            }
            cost[a][b]=cost[b][a]=999;

    }
    printf("The minimum cost = %d\n",mincost);
    return 0;
}
