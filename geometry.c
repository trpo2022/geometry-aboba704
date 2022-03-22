#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main() {
    char str[50], circle[] = "circle";
    int i;
    
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
        
        for (; isdigit(str[i]) || str[i] == '.'; i++)
        ;

        if (str[i] != ')') {
            printf("Expected ')' after Radius, try again!\n");
            goto again;
        } else {
            printf("%s", str);
            break;
        }
    }
    return 0; 
}