#include <stdio.h>
struct Distance_643
{
  int km;
  float m;
};

void dist(struct Distance_643 Dist1, struct Distance_643 Dist2, struct Distance_643 sum)
{ 
    sum.km = Dist1.km + Dist2.km;
    sum.m = Dist1.m + Dist2.m;
	  while (sum.m >= 1000)
	  {
	    sum.m = sum.m - 1000;
	    sum.km++;
	  }

  printf("Sum is %d km, %.1f m\n", sum.km, sum.m);
}

int main()
{
  struct Distance_643 Dist1, Dist2 , sum;  
  
  printf("Enter km and m for 1st distance: \n");
  scanf("%d %f", &Dist1.km, &Dist1.m);

  printf("Enter km and m for 2nd distance: \n");
  scanf("%d %f", &Dist2.km, &Dist2.m);
  
  dist(Dist1,Dist2,sum);
  return 0;
}


