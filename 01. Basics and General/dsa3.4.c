#include <stdio.h>

int lcm_643(int x, int y)
{
    static int a = 1;    
    if(a%x == 0 && a%y == 0)
    {
        return a;
    }
    else
    {
        a++;
        lcm_643(x,y);
        return a;
    }
}

int gcd_643(int x, int y)
{
    if (x==0)
       return y;
    return gcd_643(y%x,x);   
}

int main()
{
    int x, y, ch;
    printf("\nEnter two numbers\n");
    scanf("%d%d", &x, &y);
    printf("\nEnter your choice(1 or 2)\n1.LCM\n2.GCD\n");
    scanf("%d", &ch);
    
    switch (ch)
    {
        case 1 : printf("The LCM of the two numbers is: %d", lcm_643(x,y));
                 break;
        case 2 : printf("The GCD of the two numbers is: %d", gcd_643(x,y));
                 break;
        default: printf("Wrong input");
                 break;
    }
    return 0;
}

