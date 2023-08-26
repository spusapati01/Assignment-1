#include <stdio.h>
#include <math.h> 
#include <limits.h>  
int main() 
{    
 int n = 0, k = 0;   
  while ((n <= 2) || (n >= 12)) 
{        
 printf ("Enter integer n such that 2 < n < 12: ");  
 scanf ("%d", &n);   
  }   
  while (k <= 10)
 {        
 printf ("Enter upper limit k for x and y (k > 10): "); 
        scanf ("%d", &k);    
 }          
int miss = INT_MAX;    
 double relativMiss = INT_MAX;   
       for (int x = 10; x <= k; x++)        
 for (int y = 10; y <= k; y++)
 {            
 long lhs = (int) (pow (x, n) + pow (y, n)); 
            if (lhs < 0) 
{                 
printf ("OVERFLOW ERROR!! Choose lower values of n and k");                 
return 0; 
            }  
           int z = (int) pow (lhs, 1.0/n);
             int diff = lhs - pow (z, n); 
            if ((pow (z + 1, n) - lhs) < diff)
 {                 
diff = pow (z + 1, n) - lhs; 
                z++; 
            }    
         double relDiff = 100. * diff / lhs;  
           if (relDiff < relativMiss)
 {                
 miss = diff;  
               relativMiss = relDiff; 
                printf ("x = %d, y = %d, z = %d, miss = %d, relative miss = %.6f%%\n", x, y, z, diff, relDiff);  
           }       
  }     
 return 0; 
}