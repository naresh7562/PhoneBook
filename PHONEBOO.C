#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<conio.h>
#include"st.h"
#define line(n) for(;n>=0;n--) { printf("-");}
typedef struct phonebook
{
char name[20];
char number[14];
}phone;
typedef struct newdata
{
char new_name[20];
char new_number[14];
}data;
void accept()
{
	phone *pb;
	int i,range,n=30;
FILE *fp;
	fp=fopen("pbdbs.txt","wb+");
if(fp==NULL)
{
printf("file not open ");
getch();
exit(0);
}
printf("How many contact you want to enter\n");
line(n);
printf("\n");
scanf("%d",&range);
pb=(phone *)calloc(range,sizeof(phone));
for(i=0;i<range;i++)
{
printf("\nEnter name\n");
fflush(stdin);
fgets((pb)->name,20,stdin);
printf("\nenter number\n");
scanf("%s",(pb)->number);
fwrite(pb,sizeof( phone),1,fp);
}
fclose(fp);
free(pb);
}// accept function close


/*---------------- function for update contact----------------------------------------*/
void update()
{
	phone *pb;
	data *d;
	int i,f,size,n=30;
	FILE *fp;
	char search[20];

fp=fopen("pbdbs.txt","rb+");
if(fp==NULL)
{
printf("error");
}
printf("Enter name to be searched\n");
line(n);
printf("\n");
fflush(stdin);
fgets(search,20,stdin);
while(fread(pb,sizeof(phone),1,fp))
{
f=st_cm(search,pb->name);
if(f==1)
{

	size=ftell(fp);
	fseek(fp,size-sizeof(phone),0);
	printf("new name\n");
	fgets(d->new_name,20,stdin);
	printf("new number\n");
	fgets(d->new_number,14,stdin);
	fwrite(d,sizeof(data),1,fp);
	break;
}
}// while for reading file content
if(f==0)
    printf("contact not found");
fclose(fp);
}// update function close
/* -------------opening wildcard_search----------------------------------------*/
void wildcard_search()
{
int i,n=30;
	FILE *fp;
	phone *pb;
	char ch_search;
fp=fopen("pbdbs.txt","rb ");
printf("Enter char to be searched\n");
line(n);
printf("\n");
fflush(stdin);
scanf("%c",&ch_search);
while(fread(pb,sizeof(phone),1,fp))
{
for(i=0;i<1;i++)
{
if(ch_search==pb->name[i])
{
fputs(pb->name,stdout);
printf("%s",pb->number);
}
}
}
fclose(fp);
}// wildcard_search function close

/*---------------------opening display contact  ----------------------------------------*/
void display()
{
	phone *pb;
	FILE *fp;
fp=fopen("pbdbs.txt","rb");
if(fp==NULL)
{
printf("file missing");
getch();
exit(0);
}
while(fread(pb,sizeof(phone),1,fp))
{

fputs(pb->name,stdout);
fputs(pb->number,stdout);
printf("\n");

}
fclose(fp);
} //close display function

/*--------------------------delete function defination----------*/
void delete()
{
int f,i,n=30;
phone *pb;
char name[20];
FILE *fp,*fp1;
fp=fopen("pbdbs.txt","rb+");
fp1=fopen("temp.txt","wb+");
if(fp1==NULL)
printf ("insufficent memory");
printf("Enter contact name to be deleted\n");
line(n);
printf("\n");
fflush(stdin);
fgets(name,20,stdin);
while(fread(pb,sizeof(phone),1,fp))
{
f=st_cm(name,pb->name);
if(f==0)
{
fwrite(pb,sizeof(phone),1,fp1);
}
}
fclose(fp);
fclose(fp1);
remove("pbdbs.txt");
rename("temp.txt","pbdbs.txt");


}// delete function defination close








void main()
{
int range,i,choice,ch_ire=0,n=30;
do
{
clrscr();
printf("\n 1.create new contact \t 2.update existing contact  \t 3.delete");
printf("\n 4.searching \t 5.display\n" );
line(n);
printf("\n");
scanf("%d",&choice);

/* -----------------------------------------------switch case start -----------------------------*/
switch(choice)
{
/*--------------------------------------------------case 1 opening creating contact----------------------------------------*/
case 1:
accept();
break;
/*------------------------------------------------case 2 opening update contact----------------------------------------*/
case 2:
update();
break;
case 3:
delete();
break;
/*------------------------------------------case 4 opening wildcard searching----------------------------------------*/
case 4:
wildcard_search();
break;
/*-----------------------------------------case 5 opening display existing ----------------------------------------*/
case 5:
display();
break;
/*--------------------------------------------default case opening----------------------------------------*/
default :
printf("\n \n incorrect choice try again");
break;
} // switch case end
printf("\n1. to continue 0 to exit");
printf("\n");
scanf("%d",&ch_ire);
}while(ch_ire);
getch();

} // main function end
