#include <stdio.h>
#include <string.h>

typedef struct
{
    int x;
    int y;
}Point;

int main(void)
{
    Point point = {3, 4};

printf("Enter x and y coordinate of a point (Eg: 1 -1): ");
scanf("%d %d", &point.x, &point.y);
if (point.x > 0)
{
    if (point.y > 0)
    {
        printf("The (%d, %d) is in Quadrant I", point.x, point.y);
    }
    else if (point.y < 0)
    {
        printf("The (%d, %d) is in Quadrant IV", point.x, point.y);
    }
    else
    {
        printf("The (%d, %d) is in both Quadrant I & Quadrant IV", point.x, point.y);
    }
}
else if (point.x < 0)
{
    if (point.y > 0)
    {
        printf("The (%d, %d) is in Quadrant II", point.x, point.y);
    }
    else if (point.y < 0)
    {   
        printf("The (%d, %d) is in Quadrant III", point.x, point.y);
    }
    else
    {
        printf("The (%d, %d) is in Quadrant II & Quadrant III", point.x, point.y);
    }
}
else
{
    printf("The (%d, %d) is at the origin", point.x, point.y);
}
}