#include <stdio.h>                                          // ΘΕΜΑ 4: ΣΥΣΤΗΜΑ ΚΑΤΑΓΡΑΦΗΣ ΚΡΑΤΗΜΕΝΩΝ ΘΕΣΕΩΝ
#include <stdlib.h>                                         // Επεξήγηση και αναλυτικός σχολιασμός των θεμάτων για το ΘΕΜΑ 4
                                                            // υπάρχει στο αρχείο: ΕΠΕΞΗΓΗΣΕΙΣ ΘΕΜΑΤΩΝ.doc
#define MAX 53

int main()
{
    FILE* arxeio = fopen("bus.txt", "r");
    if (arxeio == NULL)
    {
        printf("To arxeio den yparxei\n");
        return 1;
    }
    FILE* exagwgh;
    int xwrhtikothta;
    char stoixeia[10];
    char c;
    int i = 0, found;
    int synolo, thesh, akyr, anazhthsh;
    while (((c = fgetc(arxeio)) != EOF) && (c != '\n') && (i <10))
    {
        stoixeia[i] = c;
        i++;
    }
    fclose(arxeio);
    if (i == 10)
    {
        xwrhtikothta = (stoixeia[8] - '0') * 10 + (stoixeia[9] - '0');
    }
    else
    {
        xwrhtikothta = (stoixeia [8] - '0');
    }

    int j;
    for (j = 0; j < i; j++)
    {
        putchar(stoixeia[j]);
    }
    printf("\n\n");
    int diair = ((xwrhtikothta - 5) / 4);
    int mod = ((xwrhtikothta - 5) % 4);
    if (xwrhtikothta > MAX)
    {
        printf ("H xwrhtikothta tou lewforeiou ypervainei ton megisto arithmo thesewn\n");
        return 1;
    }
    if (!((diair >= 0) && (mod == 0)))
    {
        printf("H xwrhtikothta tou lewforeiou de symvadizei me thn provlepomeni katanomh twn thesewn\n");
        return 2;
    }
    int bus[xwrhtikothta];
    for (i = 0; i < xwrhtikothta; i++)
    {
        bus[i] = 0;
    }
    int loop = 1;
    int choice;
    while (loop)
    {
        printf("* * * * * * * * * * * *\n\n");
        printf("EPILOGES PROGRAMMATOS\n");
        printf("1 -> Emfanish kenwn thesewn kai to plhthos tous\n");
        printf("2 -> Krathsh sygkekrimenhs theshs\n");
        printf("3 -> Krathsh prwths kenhs theshs sto parathyro\n");
        printf("4 -> Akyrwsh krathshs\n");
        printf("5 -> Anazhthsh krathmenhs theshs\n");
        printf("6 -> Lista krathmenwn thesewn\n");
        printf("7 -> Emfanish sxediagrammatos lewforeiou\n");
        printf("8 -> Exagwgh sxediagrammatos lewforeiou se arxeio\n");
        printf("0 -> Termatismos programmatos\n\n");
        printf("* * * * * * * * * * * *\n\n");
        printf("EPILOGH: ");
        scanf("%d", &choice);
        switch (choice)
        {
            case 1:
                printf("KENES THESEIS\n");
                synolo = 0;
                for (i = 0; i < xwrhtikothta; i++)
                {
                    if (bus[i] == 0)
                    {
                        printf("%d ", i + 1);
                        synolo++;
                    }
                }
                printf("\nSynolikos arithmos kenwn thesewn: %d\n\n", synolo);
                break;
            case 2:
                printf("Dwste ton arithmo ths theshs pou epithymeite gia krathsh: ");
                scanf("%d", &thesh);
                if ((thesh > xwrhtikothta) || (thesh <= 0))
                {
                    printf("Arithmos theshs ektos oriwn\n\n");
                    break;
                }
                if (bus[thesh-1] == 1)
                {
                    printf("H sygkekrimenh thesh einai krathmenh\n\n");
                    break;
                }
                bus[thesh-1] = 1;
                printf("H krathsh theshs egine epityxws!\n\n");
                break;
            case 3:
                found = 0;
                for (i = 0, j = 0; (4 + 4 * j) < (xwrhtikothta - 4); i++, j++)
                {
                    if (bus[(1+4*i)-1] == 0)
                    {
                        bus[(1+4*i)-1] = 1;
                        printf("Egine krathsh sth thesh: %d\n\n", 1+4*i);
                        found = 1;
                        break;
                    }
                    if (bus[(4+4*j)-1] == 0)
                    {
                        bus[(4+4*j)-1] = 1;
                        printf("Egine krathsh sth thesh: %d\n\n", 4+4*j);
                        found = 1;
                        break;
                    }
                }
                if (found)
                {
                    break;
                }
                if (bus[xwrhtikothta-5] == 0)
                {
                    bus[xwrhtikothta-5] = 1;
                    printf("Egine krathsh sth thesh: %d\n\n", xwrhtikothta-4);
                    break;
                }
                if (bus[xwrhtikothta-1] == 0)
                {
                    bus[xwrhtikothta-1] = 1;
                    printf("Egine krathsh sth thesh: %d\n\n", xwrhtikothta);
                    break;
                }
                printf ("Den yparxoun kenes theseis sto parathyro\n\n");
                break;
            case 4:
                printf("Dwste ton arithmo ths theshs pou epithymeite na akyrwsete: ");
                scanf("%d", &akyr);
                if ((akyr > xwrhtikothta) || (akyr <= 0))
                {
                    printf("Arithmos theshs ektos oriwn\n\n");
                    break;
                }
                if (bus[akyr-1] == 0)
                {
                    printf("Den yparxei krathsh sth sygkekrimenh thesh\n\n");
                    break;
                }
                bus[akyr-1] = 0;
                printf("H akyrwsh ths theshs egine epityxws!\n\n");
                break;
            case 5:
                printf("Dwste ton arithmo pou thelete na anazhthsete: ");
                scanf("%d", &anazhthsh);
                if ((anazhthsh > xwrhtikothta) || (anazhthsh <= 0))
                {
                    printf("Arithmos theshs ektos oriwn\n\n");
                    break;
                }
                if (bus[anazhthsh-1] == 1)
                {
                    printf("H sygkekrimenh thesh einai krathmenh\n\n");
                    break;
                }
                else
                {
                    printf("Den yparxei krathsh sth sygkekrimenh thesh\n\n");
                    break;
                }
            case 6:
                printf("Oi krathmenes theseis einai oi exhs:\n");
                for (i = 0; i < xwrhtikothta; i++)
                {
                    if (bus[i] == 1)
                    {
                        printf("%d ", i + 1);
                    }
                }
                printf("\n\n");
                break;
            case 7:
                for (i = 0; i < 7; i++)
                {
                    printf("%c", stoixeia[i]);
                }
                printf("\n\n");
                for (i = 1; i < xwrhtikothta - 4; i++)
                {
                    if (bus[i-1] == 0)
                    {
                        printf("_");
                    }
                    else
                    {
                        printf("*");
                    }
                    if (((i % 2) == 0) && ((i % 4) != 0))
                    {
                        printf(" ");
                    }
                    if ((i % 4) == 0)
                    {
                        printf("\n");
                    }
                }
                while (i <= xwrhtikothta)
                {
                    if (bus[i-1] == 0)
                    {
                        printf("_");
                    }
                    else
                    {
                        printf("*");
                    }
                    i++;
                }
                printf("\n\n");
                break;
            case 8:
                exagwgh = fopen("layout.txt", "w");
                for (i = 0; i < 7; i++)
                {
                    c = stoixeia[i];
                    fputc(c, exagwgh);
                }
                fputc('\n', exagwgh);
                for (i = 1; i < xwrhtikothta - 4; i++)
                {
                    if (bus[i-1] == 0)
                    {
                        c = '_';
                        fputc(c, exagwgh);
                    }
                    else
                    {
                        c = '*';
                        fputc(c, exagwgh);
                    }
                    if (((i % 2) == 0) && ((i % 4) != 0))
                    {
                        c = ' ';
                        fputc(c, exagwgh);
                    }
                    if ((i % 4) == 0)
                    {
                        c = '\n';
                        fputc(c, exagwgh);
                    }
                }
                while (i <= xwrhtikothta)
                {
                    if (bus[i-1] == 0)
                    {
                        c = '_';
                        fputc(c, exagwgh);
                    }
                    else
                    {
                        c = '*';
                        fputc(c, exagwgh);
                    }
                    i++;
                }
                fclose(exagwgh);
                break;
            case 0:
                loop = 0;
                break;
        }
    }
    return 0;
}
