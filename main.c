#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main() {
    char type[5];
    char number[9];
    int decimal = 0;
    int i;
    int nextVal = 128;

    printf("enter type(b->d,d->b): ");
    scanf("%s",type);


    if (strncmp(type, "b->d", 4) == 0) {
        
        printf("enter binary number: ");
        scanf("%s", number);

        for (i=0;i<8;i++) {
            if (number[i] == '1' || number[i] == 1) {
                decimal+=nextVal;
            }

            nextVal /= 2;
        }
        printf("%s in binary: %d", number, decimal);
    } else if (strncmp(type, "d->b", 4) == 0) {
        
        printf("enter decimal number: ");
        scanf("%s", number);

        int decimalNumber=atoi(number);

        if (decimalNumber>255 || decimalNumber<0) {
            printf("Invalid.");
        } else {
            char binary[9];
            
            if (decimalNumber > 0) {
                for (i=0;i<8;i++) {
                    if (decimalNumber-nextVal > -1) {
                        binary[i] = '1';
                        decimalNumber=decimalNumber-nextVal;
                    } else {
                        binary[i] = '0';
                    }
            
                    nextVal /= 2;

                }

                printf("%s", binary);
            }
        }
    }

        
    return 0;
}