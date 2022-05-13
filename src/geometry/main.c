#include <libgeometry/intersections.h>
#include <libgeometry/print.h>
#include <libgeometry/read.h>
#include <ctype.h>
#include <stdio.h>

int main()
{
    char str[50], circle[] = "circle", rad1[10], rad2[10], x1[10], y1[10], x2[10], y2[10];
    int i, n, numOfCircles = 0;
    
    again: while (numOfCircles < 2) {
        printf("Input data: ");
        inputString(str);
        
        for (i = 0; i < 6; i++) {
            if (tolower(str[i]) == circle[i])
                continue;
            else {
                printf("Expected 'circle', try again!\n");
                goto again;
            }
        }
        
        if (str[i] == ' ') {
            printf("Expected no ' ' after circle, try again!\n");
            goto again;
        }
        
        if (str[i] != '(') {
            printf("Expected '(' after circle, try again!\n");
            goto again;
        } else
            i++;
        
        if (!isdigit(str[i])) {
            printf("Expected number after '(', try again!\n");
            goto again;
        } else
            i++;
        
        for (n = 0; isdigit(str[i]) || str[i] == '.'; i++, n++) {
            if (numOfCircles == 0)
                x1[n] = str[i - 1];
            else
                x2[n] = str[i - 1];
        }
        if (numOfCircles == 0)
            x1[n] = str[i - 1];
        else
            x2[n] = str[i - 1];
        
        if (str[i] != ' ') {
            printf("Expected ' ' after X coordninate, try again!\n");
            goto again;
        } else
            i++;

        for (; isdigit(str[i]) || str[i] == '.'; i++) {
            if (numOfCircles == 0)
                y1[n] = str[i - 1];
            else
                y2[n] = str[i - 1];
        }
        
        if (str[i] != ',') {
            printf("Expected ',' after Y coordninate, try again!\n");
            goto again;
        } else
            i++;
        
        if (str[i] != ' ') {
            printf("Expected ', ' after Y coordninate, try again!\n");
            goto again;
        } else
            i++;
        
        if (!isdigit(str[i])) {
            printf("Expected number after ', ', try again!\n");
            goto again;
        } else
            i++;
        
        for (n = 0; isdigit(str[i]) || str[i] == '.'; i++, n++) {
            if (numOfCircles == 0)
                rad1[n] = str[i - 1];
            else
                rad2[n] = str[i - 1];
        }
        if (numOfCircles == 0)
            rad1[n] = str[i - 1];
        else
            rad2[n] = str[i - 1];

        if (str[i] != ')') {
            printf("Expected ')' after Radius, try again!\n");
            goto again;
        } else {
            printCircle(str, rad1);
            numOfCircles++;
            if (numOfCircles == 2)
                printIntersection(intersection(x1, y1, x2, y2, rad1, rad2));
            break;
        }
    }
    return 0;
}
