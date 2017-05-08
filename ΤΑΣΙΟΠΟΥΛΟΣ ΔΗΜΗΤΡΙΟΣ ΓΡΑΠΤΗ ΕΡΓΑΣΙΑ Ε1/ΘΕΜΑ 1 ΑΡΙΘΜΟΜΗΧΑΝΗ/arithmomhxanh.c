// ΘΕΜΑ 1: ΑΡΙΘΜΟΜΗΧΑΝΗ
// Επεξήγηση και αναλυτικός σχολιασμός των θεμάτων για το ΘΕΜΑ 1 υπάρχει στο αρχείο: ΕΠΕΞΗΓΗΣΕΙΣ ΘΕΜΑΤΩΝ.doc

#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    printf("Dwse arithmo praxi arithmo: ");
    float a, b, d;
    char c;
    scanf("%f %c %f", &a, &c, &b);
    if ((b == 0) && (c == '/'))
    {
        printf("H diairesh me to mhden den einai efikth\n");
        return -1;
    }
    if ((c != '+') && (c != '-') && (c != '*') && (c != '/'))
    {
        printf("Dwse enan apo tous telestes +, - , *, / gia prosthesi, afairesh, pollaplasiasmo kai diairesh antistoixa\n");
        return -2;
    }
    if (c == '+')
    {
        d = a + b;
    }
    else if (c == '-')
    {
        d = a - b;
    }
    else if (c == '*')
    {
        d = a * b;
    }
    else
    {
        d = a / b;
    }
    printf ("Apotelesma = %.2f\n", d);
    return 0;
}
