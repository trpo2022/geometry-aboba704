#include <libgeometry/print.h>
#include <libgeometry/read.h>
#include <ctype.h>
#include <stdio.h>

int main() {
    char str[50], circle[] = "circle", rad[10];
    int i, n;
    float r, p, s;
    
    again: while (1) {
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
            printCircle(str, rad);
            break;
        }
    }
    return 0;
}