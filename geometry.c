#include <stdio.h> 
#include <string.h>

int main() 
{
    char figure[10], circle[] = "circle", triangle[] = "triangle", polygon[] = "polygon";
    float r, perimeter, area;
    struct coord 
    {
        float x;
        float y;
    };
    
    struct coord Point1;
    struct coord Point2;
    
    while(1) 
    {
        printf("Enter input: ");
        getchar();
        int check = scanf(" %s (%f %f, %f)", figure, &Point1.x, &Point2.y, &r);
        getchar();
        
        if (check != 4) 
        {
            printf("Invalid input\n");
        }
        else if ((strcmp(figure, circle)) && (strcmp(figure, triangle)) && (strcmp(figure, polygon))) 
        {
            printf("Expected 'circle '\n");
        }
        else if (!strcmp(figure, circle))
        {
            perimeter=2*3.14*r;
            area = 3.14*r*r; 
            
            printf("%s(%.0f %.0f, %.1f)\n", figure, Point1.x, Point2.y, r);
            printf("the perimeter of the circle is %.4f\n", perimeter);
            printf("the area of the circle is %.4f\n", area);
        }
        printf(" \n");
    }
    return 0; 
}