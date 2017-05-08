//ΓΡΑΠΤΗ ΕΡΓΑΣΙΑ Ε2 - ΘΕΜΑ 3: Υλοποίηση Παραλλαγής Παιχνιδιού SET
//Επεξήγηση και αναλυτικός σχολιασμός για το ΘΕΜΑ 1 υπάρχει στο αρχείο: ΕΠΕΞΗΓΗΣΕΙΣ ΘΕΜΑΤΩΝ Ε2.doc


#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

typedef struct {
            char name[17];
            unsigned char score;
            char id;
            } paixths;

typedef struct {
            char xrwma;
            char sxhma;
            int arithmos;
            char yfh;
            } karta;


int getNextCard(karta* pkartes, karta* ptemp);
void gameTable(karta* pplegma, karta* pkartes);
int elegxosSet(karta p1, karta p2, karta p3);


int main()
{
    paixths players[3];
    strcpy(players[0].name, "Marina Andreou");
    players[0].score = 0;
    players[0].id = 'a';
    strcpy(players[1].name, "Kostas Grammenos");
    players[1].score = 0;
    players[1].id = 'g';
    strcpy(players[2].name, "Maria Perdika");
    players[2].score = 0;
    players[2].id = 'p';
    char xrwmata[] = {'r', 'g', 'b'};
    char sxhmata[] = {'c', 't', 'r'};
    int arithmoi[] = {1, 2, 3};
    char yfes[] = {'b', 'h', 'e'};
    karta kartes[81];
    int i, j, k, m;
    int x = 0;
    char energos;
    int idActivecur;
    int synt[3][2];
    int points;
    for (i = 0; i < 3; i++)
    {
        for(j = 0; j < 3; j++)
        {
            for (k = 0; k < 3; k++)
            {
                for (m = 0; m < 3; m++)
                {
                    kartes[x].xrwma = xrwmata[i];
                    kartes[x].sxhma = sxhmata[j];
                    kartes[x].arithmos = arithmoi[k];
                    kartes[x].yfh = yfes[m];
                    x++;
                }
            }
        }
    }
    srand(time(NULL));
    karta* pkartes = kartes;
    karta plegma[3][4];
    karta p1, p2, p3;
    karta* pplegma = plegma[0];
    gameTable(pplegma, pkartes);

    while((players[0].score < 10) && (players[1].score < 10) && (players[2].score < 10))
    {
        printf("\nEisagete id gia epilogh energou paixth h ton arithmo 0 gia termatismo tou paixnidiou\n");
        printf("(Me ton xarakthra '!' mporeite na provallete kainourgia 12ada): ");
        fflush(stdin);
        scanf("%c", &energos);
        if (energos == '0')
        {
            break;
        }

        if (energos == '!')
        {
            gameTable(pplegma, pkartes);
            continue;
        }

        for (i = 0; i < 3; i++)
        {
            if (players[i].id == energos)
            {
                idActivecur = i;
                break;
            }
        }

        do
        {
            printf("\nEisagete syntentagmenes prwths kartas tou set sth morfh: grammh sthlh: ");
            fflush(stdin);
            scanf("%d %d", &synt[0][0], &synt[0][1]);
        }
        while (!((synt[0][0] >= 1) && (synt[0][0] <= 3) && (synt[0][1] >= 1 ) && (synt[0][1] <= 4)));

        do
        {
            printf("\nEisagete syntentagmenes deuterhs kartas tou set sth morfh: grammh sthlh: ");
            fflush(stdin);
            scanf("%d %d", &synt[1][0], &synt[1][1]);
        }
        while (!((synt[1][0] >= 1) && (synt[1][0] <= 3) && (synt[1][1] >= 1 ) && (synt[1][1] <= 4)));

        do
        {
            printf("\nEisagete syntentagmenes triths kartas tou set sth morfh: grammh sthlh: ");
            fflush(stdin);
            scanf("%d %d", &synt[2][0], &synt[2][1]);
        }
        while (!((synt[2][0] >= 1) && (synt[2][0] <= 3) && (synt[2][1] >= 1 ) && (synt[2][1] <= 4)));

        p1 = plegma[synt[0][0] - 1][synt[0][1] - 1];
        p2 = plegma[synt[1][0] - 1][synt[1][1] - 1];
        p3 = plegma[synt[2][0] - 1][synt[2][1] - 1];

        points = elegxosSet(p1, p2, p3);

        if (points == 2)
        {
            printf("\nSygxarhthria oi kartes autes apoteloun set!!!\n");
            players[idActivecur].score += points;
            gameTable(pplegma, pkartes);
        }
        else
        {
            printf("\nOi kartes autes den apoteloun set prospathiste ksana...\n");
            if (players[idActivecur].score > 0)
            {
                players[idActivecur].score += points;
            }
        }

    }

    for (i = 0; i < 3; i++)
    {
        if (players[i].score == 10)
        {
            printf("O nikhths einai o %s!\n", players[i].name );
        }
    }

    printf("\nAPOTELESMATA PAIXTWN:\n");
    printf("ONOMA PAIXTH\tVATHMOLOGIA\n");
    for (i = 0; i < 3; i++)
    {
        printf("%s %d\n", players[i].name, players[i].score);
    }

    return 0;
}

int getNextCard(karta* pkartes, karta* ptemp)
{
    int a = rand() % 81;
    *ptemp = *(pkartes + a);
    return a;
}

void gameTable(karta* pplegma, karta* pkartes)
{
    karta temp;
    karta* ptemp = &temp;
    int deck[12];
    int a, i, j;
    int same;
    for (i = 0; i < 12; i++)
    {
        do
        {
            same = 0;
            a = getNextCard(pkartes, ptemp);
            for (j = 0; j <= i; j++)
            {
                if (a == deck[j])
                {
                    same = 1;
                }
            }
        } while (same == 1);
        deck[i] = a;
        *(pplegma + i) = *ptemp;
    }
    for (i = 0; i < 12; i++)
    {
        printf("[%c", (pplegma+i)->xrwma);
        printf("%c", (pplegma+i)->sxhma);
        printf("%d", (pplegma+i)->arithmos);
        printf("%c] ", (pplegma+i)->yfh);
        if ((i == 3) || (i == 7))
        {
            printf("\n");
        }
    }
    printf("\n\n");
}

int elegxosSet(karta p1, karta p2, karta p3)
{
    int set = 2;
    if (((p1.xrwma == p2.xrwma) && (p2.xrwma == p3.xrwma) && (p1.xrwma == p3.xrwma)) || ((p1.xrwma != p2.xrwma) && (p2.xrwma != p3.xrwma) && (p1.xrwma != p3.xrwma)))
    {
        ;
    }
    else
    {
        return -1;
    }
    if (((p1.sxhma == p2.sxhma) && (p2.sxhma == p3.sxhma) && (p1.sxhma == p3.sxhma)) || ((p1.sxhma != p2.sxhma) && (p2.sxhma != p3.sxhma) && (p1.sxhma != p3.sxhma)))
    {
        ;
    }
    else
    {
        return -1;
    }
    if (((p1.arithmos == p2.arithmos) && (p2.arithmos == p3.arithmos) && (p1.arithmos == p3.arithmos)) || ((p1.arithmos != p2.arithmos) && (p2.arithmos != p3.arithmos) && (p1.arithmos != p3.arithmos)))
    {
        ;
    }
    else
    {
        return -1;
    }
    if (((p1.yfh == p2.yfh) && (p2.yfh == p3.yfh) && (p1.yfh == p3.yfh)) || ((p1.yfh != p2.yfh) && (p2.yfh != p3.yfh) && (p1.yfh != p3.yfh)))
    {
        ;
    }
    else
    {
        return -1;
    }
    return set;
}
