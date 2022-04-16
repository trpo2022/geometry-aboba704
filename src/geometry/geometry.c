#include <ctype.h>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    char str[50], circle[] = "circle", rad[10];
    int i, n;
    float r, p, s;
    
    again: while (1) {
        printf("Input data: ");
        fgets(str, 50, stdin);
        
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
        
        for (; isdigit(str[i]) || str[i] == '.'; i++)
            ;
        
        if (str[i] != ' ') {
            printf("Expected ' ' after X coordninate, try again!\n");
            goto again;
        } else
            i++;

        for (; isdigit(str[i]) || str[i] == '.'; i++)
        ;
        
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
        
        for (n = 0; isdigit(str[i]) || str[i] == '.'; i++, n++)
            rad[n] = str[i - 1];
        rad[n] = str[i - 1];
        

        if (str[i] != ')') {
            printf("Expected ')' after Radius, try again!\n");
            goto again;
        } else {
            printf("%s", str);
            r = atof(rad);
            p = 2 * 3.14 * r;
            s = 3.14 * r * r;
            printf("Perimeter: %.2f\nArea: %.2f", p, s);
            break;
        }
    }
    return 0;
}