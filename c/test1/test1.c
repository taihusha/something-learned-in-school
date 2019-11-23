#include<stdio.h>
#include<stdlib.h>
#define PI 3.14159
int main() {
   int f;
   short p, k,newint;
   float r;
   double c  , s;

/* for task 1 */
   printf("Input  Fahrenheit:");
   scanf("%d", &f);
   c = ((double)5/9)*(f-32);
   printf( " \n %d (F) = %.2f (C)\n\n",f,c);

   /* for task 2 */
   printf("input the radius r:");
   scanf("%f", &r);
   s=r*r*PI;
   printf("\nThe acreage is %.2f\n\n",s);

   /* for task 3 */
   printf("input hex int k, p :");
   scanf("%hx %hx", &k, &p );
   newint = (p&0xff00)|(((k&0xff00)>>8)&0xff00);
   printf("new int = %hx\n\n",newint);
   system("pause");
   return 0;
}
