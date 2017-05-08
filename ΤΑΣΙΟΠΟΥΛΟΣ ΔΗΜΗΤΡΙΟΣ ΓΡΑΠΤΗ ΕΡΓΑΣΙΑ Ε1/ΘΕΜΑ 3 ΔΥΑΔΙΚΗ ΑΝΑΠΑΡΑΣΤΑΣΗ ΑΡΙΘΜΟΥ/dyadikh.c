#include <stdio.h>                                          // ΘΕΜΑ 3: ΔΥΑΔΙΚΗ ΑΝΑΠΑΡΑΣΤΑΣΗ ΑΡΙΘΜΟΥ
#include <stdlib.h>                                         // Επεξήγηση και αναλυτικός σχολιασμός των θεμάτων για το ΘΕΜΑ 3
                                                            // υπάρχει στο αρχείο: ΕΠΕΞΗΓΗΣΕΙΣ ΘΕΜΑΤΩΝ.doc
int main()
{
    const int m = 2;
    int mod, arithmos;
    char modc;
    do
    {
        printf("Dwste thetiko akeraio arithmo: ");
        scanf("%d", &arithmos);
        if (arithmos < 0)
        {
            printf("O arithmos pou dwsate einai arnhtikos\n");
        }
        if (arithmos == 0)
        {
            printf("O arithmos pou dwsate einai mhden\n");
        }
    } while (arithmos <= 0);
    while (arithmos != 0)
    {
        mod = arithmos % m;
        arithmos = arithmos / m;
        modc = (mod == 0) ? '0' : '1';
        putchar(modc);
    }
    printf("\n");

    return 0;
}
