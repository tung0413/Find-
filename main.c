
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

double trapezoid(double base1, double base2, double height)
{
    return (base1+base2)*height/2;
}

double side3 (double hypotenuse, double side)
{
    return sqrt(hypotenuse*hypotenuse-side*side);
}

double area(double i)
{
    double side=side3(2,2/i),base1=2,ans=0;
    for(double j=0;j<i;j++)
    {
        ans+=trapezoid(base1,side,2/i);
        base1=side;
        side=side3(2,(j+2)*2/i);
    }
    return ans;
}

int main()
{
    double ans=0,ans2;
    for(double i=2;;i=i*2)
    {
            ans2=ans;
            ans=area(i);
            if(ans-ans2<0.00001)
            {
                printf("%lf",ans);
                break;
            }
    }
}
