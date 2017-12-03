/* -------------------------------------------------------------------------  
    Problem 4.1.5
    One Pass Statistics Algorithm (Non-Welford)
 * ------------------------------------------------------------------------- 
 */

#include <stdio.h>                             
#include <math.h>                                


  int main(void)
{
  long    index;
  double  data;
  double  sum = 0.0;
  double sqsum = 0.0;
  double cbsum = 0.0;
  double s;
  double q;
  double mean;

  scanf("%lf\n", &data);
  if (!feof(stdin)) {
    index  = 1;
  }
  else 
    index = 0;

  while (!feof(stdin)) {
    scanf("%lf\n", &data);
    index++;
    sum += data;
    sqsum += data * data;
    cbsum += data * data * data;


  }

  if (index > 0) {
    //get mean
    mean = sum / index;
    //get standard dev
    s = sqsum / index;
    s = s - (mean * mean);
    s = sqrt(s);
    //get skew
    q = cbsum - (3 * mean * sqsum);
    q = q / index;
    q = q + (2 * (mean * mean * mean));
    q = q / (s * s * s);
    q = cbrt(q);


    printf("\nfor a sample of size %ld\n", index);
    printf("mean ................. = %7.3f\n", mean);
    printf("standard deviation ... = %7.3f\n", s);
    printf("skew ................. = %7.3f\n", q);
  }

  return (0);
}
