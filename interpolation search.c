// Search a key element in a given set of elements using interpolation search and determine the time required.
// Repeat the experiment for different values of n and plot a graph of the time taken to search a key in different positions
// versus n(n is the number of elements in the list).
// The elements can be read from file or can be generated using the random number generator.

// Analyze the time efficiency of each of these methods and compare their performances by referring the graphs plotted.

#include <stdio.h>
#include<stdlib.h>
#include<time.h>
#define MAX 1000

void delay(int msec)
{
    clock_t goal = msec + clock();
    while(goal> clock());

}

int interpolationSearch(int arr[], int n, int x)
{

    int start = 0, end = (n - 1);

    while (start <= end && x >= arr[start] && x <= arr[end])
    {
        if (start == end)
        {
            if (arr[start] == x) return start;
            return -1;
        }

        int pos = start + (((double)(end - start) /
            (arr[end] - arr[start])) * (x - arr[start]));

        if (arr[pos] == x)
            return pos;


        if (arr[pos] < x)
            start = pos + 1;

        else
            end = pos - 1;
    }
    return -1;
}

void sort(int a[], int n)
 {
   int i, j, temp;
   for(i=0;i<n-1;i++)
   {
     for(j=i+1;j<n;j++)
      {
       if(a[i]>a[j])
        {
          temp=a[i];
          a[i]=a[j];
          a[j]=temp;
        }
      }
   }
 }

int main()
{


	int arr[200000],n,x;
	clock_t start, end;
    double time;

	printf("Enter the array size:");
    scanf("%d",&n);
    printf("\nElements are:\n");

    for(int i=0; i<n; i++)
    {
        arr[i] = rand() % MAX;

        for(int j=0; j<=(i-1); ++j)
            {
                if (arr[i] != arr[j])
                    {
                        continue;
                    }
                else
                    {
                        arr[i] = rand() % MAX;
                        printf("%d\t", arr[i]);
                    }
            }
    }

    for(int i=0;i<n;i++){
        printf("%d  ",arr[i]);
    }

    sort(arr,n);
    printf("\nAfter Sorting array :\n");

    for(int i=0;i<n;i++)
    {

        printf("%d\t", arr[i]);
    }
    printf ("\nEnter the Element to be Searched:\n");

	scanf("%d",&x);
	start=clock();
	int index = interpolationSearch(arr,n,x);
    end=clock();

	if (index == -1){
		printf("Element not found.");
	}
	else{

		printf("Element found at index %d", index);
		time=(double)(end-start)/CLK_TCK;
        printf("\n Time taken = %f", time);
	}
	return 0;
}


//INTERPOLATION SEARCH
