//ΓΡΑΠΤΗ ΕΡΓΑΣΙΑ Ε2 - ΘΕΜΑ 1: Νέο σύστημα καταγραφής κρατημένων θέσεων
//Επεξήγηση και αναλυτικός σχολιασμός για το ΘΕΜΑ 1 υπάρχει στο αρχείο: ΕΠΕΞΗΓΗΣΕΙΣ ΘΕΜΑΤΩΝ Ε2.doc

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
            char onom_epwn[40];
            unsigned short phone[10];
            unsigned int seat;
    } thesh;

void readfile(thesh* pbus, char* pstoix, int* pxwr);
void emfanisi_kenwn(thesh table[], int megethos);
int eggrafh(thesh* pointer);
void anazhthsh(thesh table[], int megethos);
int diagrafh(thesh* pointer);
void lista_krathmenwn(thesh table[], int megethos);
void writefile(thesh table1[], char table2[], int megethos);
int telos(void);

int main()
{

    thesh bus[53];
    thesh* p;
    thesh* p1;
    char* p2;
    int* p3;

    char stoixeia[11];
    int xwrhtikothta;
    p1 = bus;
    p2 = stoixeia;
    p3 = &xwrhtikothta;
    readfile(p1, p2, p3);
    int position, eggr, diagr;

   int loop = 1;
   int choice;
   while (loop)
   {
        printf("* * * * * * * * * * * *\n\n");
        printf("EPILOGES PROGRAMMATOS\n");
        printf("1 -> Emfanish kenwn thesewn kai to plhthos tous\n");
        printf("2 -> Krathsh sygkekrimenhs theshs\n");
        printf("3 -> Anazhthsh krathmenhs theshs\n");
        printf("4 -> Akyrwsh krathshs\n");
        printf("5 -> Lista krathmenwn thesewn\n");
        printf("0 -> Termatismos programmatos\n\n");
        printf("* * * * * * * * * * * *\n\n");
        printf("EPILOGH: ");
        scanf("%d", &choice);
        switch (choice)
        {
            case 1:
                emfanisi_kenwn(bus, xwrhtikothta);
                break;
            case 2:
                do
                {
                    printf("\nDwste ton arithmo ths theshs pou thelete na kanete krathsh: ");
                    scanf ("%d", &position);
                    if ((position <= 0) || (position > xwrhtikothta))
                    {
                        printf("Arithmos ektos oriwn!\n");
                    }
                } while ((position <= 0) || (position > xwrhtikothta));
                p = &bus[position-1];
                eggr = eggrafh(p);
                if (eggr == 0)
                {
                    printf("\nH thesh %d einai hdh krathmenh!\n\n", position);
                }
                else if (eggr == 1)
                {
                    printf("\nEgine epityxhs krathsh sth thesh %d!\n\n", position);
                }
                break;
            case 3:
                anazhthsh(bus, xwrhtikothta);
                break;
            case 4:
                do
                {
                    printf("\nDwste ton arithmo ths theshs pou thelete na akyrwsete: ");
                    scanf ("%d", &position);
                    if ((position <= 0) || (position > xwrhtikothta))
                    {
                        printf("Arithmos ektos oriwn!\n");
                    }
                } while ((position <= 0) || (position > xwrhtikothta));
                p = &bus[position-1];
                diagr = diagrafh(p);
                if (diagr == 0)
                {
                    printf("\nDen yparxei krathsh sth thsh %d!\n\n", position);
                }
                else if (diagr == 1)
                {
                    printf("\nEgine epityxhs akyrwsh ths krathshs sth thesh %d!\n\n", position);
                }
                break;
            case 5:
                lista_krathmenwn(bus, xwrhtikothta);
                break;
            case 0:
                writefile(bus, stoixeia, xwrhtikothta);
                loop = telos();
                break;
        }
   }

    return 0;
}

void readfile(thesh* pbus, char* pstoix, int* pxwr)
{
   FILE* arxeio = fopen("bus.txt", "r");
    if (arxeio == NULL)
    {
        printf("To arxeio den yparxei\n");
        return;
    }
    int i = 0;
    int j, x, k, nspace;
    unsigned int arithmos;
    char c, temp_seat[3], temp_phone[11], temp_onom_epwn[40];

    while ((c = fgetc(arxeio)) != '\n' && (c != EOF))
    {
        *(pstoix + i) = c;
        i++;
    }
    for (j = 0; j < i; j++)
    {
        putchar(*(pstoix+j));
    }
    printf("\n\n");
    if (i == 10)
    {
        *pxwr = (*(pstoix + 8) - '0') * 10 + (*(pstoix + 9) - '0');
    }
    else if (i == 9)
    {
        *pxwr = (*(pstoix + 8) - '0');
    }
    *(pstoix + i) = '\0';

    for (i = 0; i < 53; i++)
    {
        (pbus + i)->onom_epwn[0] = '\0';
        (pbus + i)->seat = i + 1;
    }
    char line[54];
    if (c != EOF)
    {
        while ((c = fgetc(arxeio)) != EOF)
        {
            x = 0;
            while ((c != '\n') && (c != EOF))
            {
                line[x] = c;
                x++;
                c = fgetc(arxeio);
            }
            line[x] = '\0';

            if (strlen(line)!= 0)
            {

                k = 0;
                nspace = 0;
                while (nspace < 2)
                {
                    if (line[k] == ' ')
                    {
                        nspace++;
                    }
                    temp_onom_epwn[k] = line[k];

                    k++;
                }
                temp_onom_epwn[k-1] = '\0';

                i = 0;
                while (line[k] != ' ')
                {
                    temp_seat[i] = line[k];

                    k++;
                    i++;

                }
                temp_seat[i] = '\0';

                arithmos = atoi(temp_seat);

                k++;
                for (i = 0; i < 10; i++)
                {
                   temp_phone[i] = line[k];
                   k++;

                }
                temp_phone[i] = '\0';

                strcpy((pbus + arithmos - 1)->onom_epwn, temp_onom_epwn);

                (pbus + arithmos - 1)->seat = arithmos;
                for (i = 0; i < strlen(temp_phone); i++)
                {
                    (pbus + arithmos - 1)->phone[i] = temp_phone[i] - '0';
                }
            }
        }
    }
    fclose(arxeio);
}

void emfanisi_kenwn(thesh table[], int megethos)
{
    int i;
    int counter = 0;
    printf("OI KENES THESEIS EINAI OI EKSHS:");
    for (i = 0; i < megethos; i++)
    {
        if (strcmp(table[i].onom_epwn, "\0") == 0)
        {
            printf("%d ", table[i].seat);
            counter++;
        }
    }
    printf("\n");
    printf("SYNOLIKOS ARITHMOS KENWN THESEWN: %d\n", counter);
    printf("\n");
}

int eggrafh(thesh* pointer)
{
    char buffer[40];
    char thlefwno [11];
    int a, i;
    if (strcmp(pointer->onom_epwn, "\0") == 0)
    {
        printf("Dwste to onomatepwnymo sto opoio tha ginei h krathsh\nsth morfh Epitheto Onoma: ");
        fflush(stdin);
        fgets(buffer, 40, stdin);
        a = strlen(buffer);
        if (buffer[a-1] == '\n')
        {
            strncpy(pointer->onom_epwn, buffer, (a - 1));
            pointer->onom_epwn[a-1] = '\0';
        }
        else
        {
            strcpy(pointer->onom_epwn, buffer);
        }
        printf("Dwste to thlefwno sas: ");
        fflush(stdin);
        fgets(thlefwno, 11, stdin);
        for (i = 0; i < strlen(thlefwno); i++)
        {
            pointer->phone[i] = thlefwno[i] - '0';
        }
        return 1;
    }
    return 0;
}

void anazhthsh(thesh table[], int megethos)
{
    int epilogh;
    char firlasname[40];
    char buffer[40];
    int a, i, j;
    int found = 0;
    int thlfound = 0;
    char thlefwno[11];
    unsigned short number[10];
    do
    {
        printf("Epilexte me poio krithrio epithymeite na kanete anazhthsh ths theshs\n");
        printf("(1 gia onomatepwnymo / 2 gia arithmo thlefwnou): ");
        scanf("%d", &epilogh);
    } while ((epilogh != 1) && (epilogh != 2));
    if (epilogh == 1)
    {

        printf("\nDwste onomatepwnymo:");
        fflush(stdin);
        fgets(buffer, 40, stdin);
        a = strlen(buffer);
        if (buffer[a-1] == '\n')
        {
            strncpy(firlasname, buffer, (a - 1));
            firlasname[a-1] = '\0';
        }
        else
        {
            strcpy(firlasname, buffer);
        }
        for (i = 0; i < megethos; i++)
        {
            if (strcmp(firlasname, table[i].onom_epwn) == 0)
            {
                printf("\nH thesh %d einai krathmenh sto onomatepwnymo: %s\n\n", table[i].seat, firlasname);
                found = 1;
            }
        }
    }
    else
    {
        printf("\nDwste arithmo thlefwnou:");
        fflush(stdin);
        fgets(thlefwno, 11, stdin);
        for (i = 0; i < strlen(thlefwno); i++)
        {
            number[i] = thlefwno[i] - '0';
        }
        for (i = 0; i < megethos; i++)
        {
            thlfound = 1;
            for (j = 0; j < 10; j++)
            {
                if (table[i].phone[j] != number[j])
                {
                    thlfound = 0;
                    break;
                }
            }
            if (thlfound == 1)
            {
                found = 1;
                printf("\nH thesh %d einai krathmenh sto thlefwno: %s\n\n", table[i].seat, thlefwno);
            }
        }


    }
    if (found == 0)
    {
        printf("\nDen yparxei krathmenh thesh me ta stoixeia pou anazhtate!\n\n");
    }

}

int diagrafh(thesh* pointer)
{
    int i;
    if (strcmp(pointer->onom_epwn, "\0") != 0)
    {
       strcpy(pointer->onom_epwn, "\0");
       for (i = 0; i < 9; i++)
       {
           pointer->phone[i] = 0;
       }
       return 1;
    }
    return 0;
}

void lista_krathmenwn(thesh table[], int megethos)
{
    int krathmenes = 0;
    char tel[11];
    int i,j;
    for (i = 0; i < megethos; i++)
    {
        if (strcmp(table[i].onom_epwn, "\0") != 0)
        {
            krathmenes = 1;
        }
    }
    if (krathmenes == 0)
    {
        printf("\nDen yparxoun krathmenes theseis!\n\n");
    }
    else
    {
        printf("\nOi krathmenes theseis einai oi ekshs:\n\n");
        for (i = 0; i < megethos; i++)
        {
            if (strcmp(table[i].onom_epwn, "\0") != 0)
            {
                for (j = 0; j < 10; j++)
                {
                    tel[j] = table[i].phone[j] + '0';
                }
                tel[10] = '\0';
                printf("%s %s %d\n", table[i].onom_epwn, tel, table[i].seat);
            }
        }
        printf("\n");
    }
}

void writefile(thesh table1[], char table2[], int megethos)
{
    int i,j;
    FILE* arxeio = fopen("bus.txt", "w");
    if (arxeio == NULL)
    {
        printf("Adynamia eggrafhs sto arxeio\n");
        return ;
    }
    fputs(table2, arxeio);
    fputc('\n', arxeio);
    for (i = 0; i < megethos; i++)
    {
        if (strcmp(table1[i].onom_epwn, "\0") != 0)
        {
            fputs(table1[i].onom_epwn, arxeio);
            fputc(' ', arxeio);
            if (table1[i].seat < 10)
            {
                fputc((table1[i].seat + '0'), arxeio);
            }
            else
            {
                fputc((table1[i].seat / 10 + '0'), arxeio);
                fputc((table1[i].seat % 10 + '0'), arxeio);
            }
            fputc(' ', arxeio);
            for (j = 0; j < 10; j++)
            {
                fputc((table1[i].phone[j] + '0'), arxeio);
            }
            fputc('\n', arxeio);
        }
    }
}

int telos (void)
{
    return 0;
}
