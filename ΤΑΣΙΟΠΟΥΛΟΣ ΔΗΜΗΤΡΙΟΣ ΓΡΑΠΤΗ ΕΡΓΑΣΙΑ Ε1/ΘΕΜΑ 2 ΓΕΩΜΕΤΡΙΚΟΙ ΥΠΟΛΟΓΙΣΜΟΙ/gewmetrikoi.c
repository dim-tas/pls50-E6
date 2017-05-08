#include <stdio.h>                              // ΘΕΜΑ 2: ΓΕΩΜΕΤΡΙΚΟΙ ΥΠΟΛΟΓΙΣΜΟΙ
#include <stdlib.h>                             // Επεξήγηση και αναλυτικός σχολιασμός των θεμάτων για το ΘΕΜΑ 2
#include <math.h>                               // υπάρχει στο αρχείο: ΕΠΕΞΗΓΗΣΕΙΣ ΘΕΜΑΤΩΝ.doc

#define PI 3.14

float square(float side);
float parallel(float length, float width);
float triangle(float side_a, float side_b);
float circle(float radius);


int main(void)
{
    float pleura_t, mhkos_p, platos_p, pleura_a, pleura_b, aktina, perim;
    int epilogh;
    int loop = 1;
    while (loop)
    {
        printf("Epilexte ena sxhma gia ypologismo emvadou h to 0 gia exodo apo to programma\n\n");
        printf("0-> EXODOS\n1-> Tetragwno\n2-> Parallilogrammo\n3-> Orthogwnio Trigwno\n4-> Kyklos\n\n");
        printf("Epilogh: ");
        scanf(" %d", &epilogh);
        if (epilogh == 0)
        {
            break;
        }
        else if (epilogh == 1)
        {
            printf("Dwste to mhkos ths pleuras tou tetragwnou: ");
            scanf(" %f", &pleura_t);
            perim = square(pleura_t);
            printf("H perimetros tou tetragwnou einai: %.2f\n\n", perim);
        }
        else if (epilogh == 2)
        {
            printf("Dwste to mhkos tou parallilogrammou: ");
            scanf(" %f", &mhkos_p);
            printf("Dwste to platos tou parallilogrammou: ");
            scanf(" %f", &platos_p);
            perim = parallel(mhkos_p, platos_p);
            printf("H perimetros tou parallilogrammou einai: %.2f\n\n", perim);
        }
        else if (epilogh == 3)
        {
            printf("Dwste to mhkos ths prwths katheths pleuras tou trigwnou: ");
            scanf(" %f", &pleura_a);
            printf("Dwste to mhkos ths deuterhs katheths pleuras tou trigwnou: ");
            scanf(" %f", &pleura_b);
            perim = triangle(pleura_a, pleura_b);
            printf("H perimetros tou trigwnou einai: %.2f\n\n", perim);
        }
        else if (epilogh == 4)
        {
            printf("Dwste to mhkos ths aktinas tou kyklou: ");
            scanf(" %f", &aktina);
            perim = circle(aktina);
            printf("H perimetros tou kyklou einai: %.2f\n\n", perim);
        }
    }

    return 0;
}

float square(float side)
{
    return 4 * side;
}

float parallel(float length, float width)
{
    return (2 * length) + (2 * width);
}

float triangle(float side_a, float side_b)
{
    float ypotein = sqrt((side_a * side_a) + (side_b * side_b));
    return ypotein + side_a + side_b;
}

float circle(float radius)
{
    return 2 * PI * radius;
}
