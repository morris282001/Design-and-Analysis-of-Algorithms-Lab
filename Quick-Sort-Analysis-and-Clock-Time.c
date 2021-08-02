//To Sort a given set of elements using the Quicksort method and determine the time required to sort the elements. Repeat the experiment for different values of n, the number of elements in the list to be sorted and plot a graph of the time taken versus n. The elements can be read from a file or can be generated using the random number generator.
  
#include<stdio.h>
#include<time.h>
void quicksort(int number[25],int first,int last){
   int i, j, pivot, temp;
   if(first<last){
      pivot=first;
      i=first;
      j=last;
      while(i<j){
         while(number[i]<=number[pivot]&&i<last)
            i++;
         while(number[j]>number[pivot])
            j--;
         if(i<j){
            temp=number[i];
            number[i]=number[j];
            number[j]=temp;
         }
      }
      temp=number[pivot];
      number[pivot]=number[j];
      number[j]=temp;
      quicksort(number,first,j-1);
      quicksort(number,j+1,last);
   }
}
int main(){
   int i, count, number[1500];
clock_t start, end;
     double cpu_time_used;
     start = clock();
     
   printf("Enter number of elements ");
   scanf("%d",&count);
   for(i=0;i<count;i++)
      number[i]=random();
   quicksort(number,0,count-1);
   printf("Order of Sorted elements: \n");
   for(i=0;i<count;i++)
      printf(" %d\n",number[i] );
      end = clock();
     cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC;
printf("\ntime used: %f",cpu_time_used);
   return 0;
}
