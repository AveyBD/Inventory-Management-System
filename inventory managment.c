#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<math.h>
#define Inventory struct Invent

void add(FILE * fp);
void modify(FILE * fp);
void display(FILE * fp);
void Indivisual(FILE *fp);
void title();
struct Invent
{
    char name[100];
    int id;
    float price;
};
int main()
{
    FILE * fp;
    Inventory s;
    int option;
    char another;

    if((fp=fopen("db.txt","rb+"))==NULL)
    {
        if((fp=fopen("db.txt","wb+"))==NULL)
        {
            printf("Can't create or open Database.");
            return 0;
        }
    }

    title();
    printf("\n\t\t\t");
    printChar('*',40);
    printf("\n\t");
    printf("\n\n\t\t\t\t1. Add inventory");
    printf("\n\n\t\t\t\t2. Display Inventory List");
    printf("\n\n\t\t\t\t3. Search Inventory");
    printf("\n\n\t\t\t\t4. Exit\n\t");
    printf("\n\n\t\t\t\tEnter Your Option :--> ");
    scanf("%d",&option);

    switch(option)
    {
    case 1:
        add(fp);
        break;
    case 2:
        display(fp);
        break;
    case 3:
        Indivisual(fp);
        break;
    case 4:
        return 1;
        break;
    default:
        printf("\n\t\tNo Action Detected");
        printf("\n\t\tPress Any Key\n\n\n");
        getch();
        system("pause");
    }
    return 1;

}

void add(FILE * fp)
{
    system("cls");
    title();
    char another='y';
    Inventory s;
    int i;
    float price;
    fseek(fp,0,SEEK_END);
    while(another=='y'||another=='Y')
    {
        printf("\n\n\t\tInventory_id: ");
        scanf("%d",&s.id);
        printf("\n\n\t\tName: ");
        fflush(stdin);
        fgets(s.name,100,stdin);
        s.name[strlen(s.name)-1]='\0';
        printf("\n\n\t\tPrice: ");
        scanf("%f", &s.price);
        fwrite(&s,sizeof(s),1,fp);
        printf("\n\n\t\tDo you want to continue?(Y/N)?");
        fflush(stdin);
        another=getchar();
        if(another=='N'||another=='n')
        {
            system("cls");
            main();
        }
    }
}
void display(FILE * fp)
{
    system("cls");
    title();
    Inventory s;
    int i,siz=sizeof(s);
    char another;
    rewind(fp);

    while((fread(&s,siz,1,fp))==1)
    {
        printf("\n\n\t\tInventory_id : %d",s.id);
        printf("\n\t\tNAME : %s",s.name);
        printf("\n\n\t\tPrice: %.2f", s.price);
    }
    printf("\n\n\t");
    printf("Press 'x' to Return: ");
    fflush(stdin);
    another=getchar();
    if(another=='x'||another=='X')
    {
        system("cls");
        main();
    }
}

void Indivisual(FILE *fp)
{
    system("cls");
    title();
    int tempid,flag,siz,i;
    Inventory s;
    char another='y';

    siz=sizeof(s);

    while(another=='y'||another=='Y')
    {
        printf("\n\n\tEnter ID Number: ");
        scanf("%d",&tempid);

        rewind(fp);

        while((fread(&s,siz,1,fp))==1)
        {
            if(s.id==tempid)
            {
                flag=1;
                break;
            }
        }

        if(flag==1)
        {
            printf("\n\n\t\tID : %d",s.id);
            printf("\n\t\tNAME : %s",s.name);
            printf("\n\n\t\tPrice: %f", s.price);


        }
        else printf("\n\n\t\t!!!! ERROR RECORD NOT FOUND !!!!");


        printf("\n\n\t\tShow another Inventory information? (Y/N)?");
        fflush(stdin);
        another=getchar();
        if(another=='N'||another=='n')
        {
            system("cls");
            main();
        }
    }
}

void title()
{
    printf("\n\n\t");
    printChar('=',19);
    printf("Inventory Management System");
    printChar('=',19);
    system("COLOR 03");
}
void printChar(char ch,int n)
{
    while(n--)
    {
        putchar(ch);
    }
}
