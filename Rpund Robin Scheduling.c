Skip to content
Search or jump to…

Pull requests
Issues
Marketplace
Explore
 
@morris282001 
morris282001
/
Round-robin-scheduling
1
00
Code
Issues
Pull requests
Actions
Projects
Wiki
Security
Insights
Settings
Create code
 main
@morris282001
morris282001 committed on Jun 20 
1 parent 86f4f2c commit cfb7adcbc0e3af2c8c3041a42e89576f6bf4610a
Showing  with 91 additions and 0 deletions.
 91  code 
@@ -0,0 +1,91 @@
#include<stdio.h>
#include<stdlib.h>
void main() {
 int  j, q, i, n, ts, temp;
 float awt;
 float att;
 int bt[10], wt[10], te[10], rt[10], at[10],tt[10];
 j = 0;
 //system("cls");
 printf("enter number of process :\t");
 scanf("%d", & n);
 printf("\n enter brust time and arrival time\n");
 for (i = 0; i < n; i++) {
   printf("P%d  \nbrust time ", i + 1);
   scanf("%d", & bt[i]);
   printf("ariavl time   :  ");
   scanf("%d", & at[i]);
   te[i] = 0;
   wt[i] = 0;
 }
 for (i = 0; i < n; i++) {
   for (j = i + 1; j < n; j++) {
     if (at[i] > at[j]) {
       temp = at[i]; //sorting according to arrival time
       at[i] = at[j];
       at[j] = temp;
       temp = bt[i];
       bt[i] = bt[j];
       bt[j] = temp;
     }
   }
 }
 printf("\n enter time slice\t");
 scanf("%d", & ts);
 q = 0;
 //system("cls");
 printf("\nprocess      :");
 for (i = 0; i < n; i++) {
   printf("  %d", i + 1);
 }
 printf("\nBrust time   :");
 for (i = 0; i < n; i++) {
   printf("  %d", bt[i]);
   rt[i] = bt[i];
 }
 printf("\nArrival time :");
 for (i = 0; i < n; i++) {
   printf("  %d", at[i]);
 }
 printf("\n Gaint chart \n");
 j = 0;

 while (j <= n) {
   j++;
   for (i = 0; i < n; i++) {
     if (rt[i] == 0) continue;
     if (rt[i] > ts) {
       printf("\n %d\t P%d", q, i + 1);
       q = q + ts;
       rt[i] = rt[i] - ts;
       te[i] = te[i] + 1;
     } else {
       printf("\n %d\t P%d", q, i + 1);
       wt[i] = q - te[i] * ts;
       q = q + rt[i];
       rt[i] = rt[i] - rt[i];
     }
   }
 } //end of while
 awt=0;
 printf("\n Process   Waiting time");
 for (i = 0; i < n; i++) {
   wt[i] = wt[i] - at[i];
   printf("\n P%d      :   %d", i + 1, wt[i]);
   awt = awt + wt[i];
 }

 printf("\ntotal waiting time %f", awt);
 printf("\n Avg wainting time %f ", awt / n);
 att=0;
  printf("\n Process   Turnaround time");
 for (i = 0; i < n; i++) {
   tt[i] = wt[i] + bt[i];
   printf("\n P%d      :   %d", i + 1,tt[i]);
   att = att + tt[i];
 }

 printf("\n total turnaround time: %f", att);
 printf("\n Avg turnaround time: %f ", att / n);
 getch();
}
0 comments on commit cfb7adc
@morris282001
 
 
Leave a comment

Attach files by dragging & dropping, selecting or pasting them.
 You’re receiving notifications because you’re watching this repository.
© 2021 GitHub, Inc.
Terms
Privacy
Security
Status
Docs
Contact GitHub
Pricing
API
Training
Blog
About
Loading complete
