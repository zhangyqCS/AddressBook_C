#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Address_Book.h"
#define LEN sizeof(struct People)

char str[5][15]={"Classmate","Colleague","Relative","Teacher","Others"};

People *Add_Records(People *head)
{
	char ch='Y';
	int d;
	People *p1,*p2,*add;
	p1=p2=add=head;
	while(p1!=NULL)
	{
		p2=p1;
		p1=p1->next;
	}
	printf("Please enter the records:\n");
	add=(struct People *)malloc(LEN);
	printf("Name:");
	scanf("%s",add->name);
	printf("Age:");
	scanf("%d",&add->age);
	printf("Relationship:\n");
	printf("*---------------------*\n");
	printf("|   1--Classmate      |\n");
	printf("|   2--Colleague      |\n");
	printf("|   3--Relative       |\n");
	printf("|   4--Teacher        |\n");
	printf("|   5--Others         |\n");
	printf("*---------------------*\n");
	scanf("%d", &d);
	while(d != 1 && d != 2 &&d != 3 &&d != 4 &&d != 5) {
		printf("Please enter again!\n");
		scanf("%d", &d);
	}
	if(d == 1) strcpy(add->rela, "Classmate");
	if(d == 2) strcpy(add->rela, "Colleague");
	if(d == 3) strcpy(add->rela, "Relative");
	if(d == 4) strcpy(add->rela, "Teacher");
	if(d == 5) strcpy(add->rela, "Others");
	printf("Phonenumber:");
	scanf("%s",add->pnum);
	printf("E-mail:");
	scanf("%s",add->email);
	printf("Address:");
	scanf("%s",add->address);
	p2->next=add;
	p2=add;
	add->next=NULL;
	Rank_Records(head);
	printf("Continue to add?[Y/N]:");
	getchar();
	ch=getchar();	
    while(ch=='Y')
	{
	    add=(struct People *)malloc(LEN);
		printf("Name:");
	    scanf("%s",add->name);
	    printf("Age:");
	    scanf("%d",&add->age);
	    printf("Relationship:\n");
		printf("*---------------------*\n");
		printf("|   1--Classmate      |\n");
		printf("|   2--Colleague      |\n");
		printf("|   3--Relative       |\n");
		printf("|   4--Teacher        |\n");
		printf("|   5--Others         |\n");
		printf("*---------------------*\n");
		scanf("%d", &d);
		while(d != 1 && d != 2 &&d != 3 &&d != 4 &&d != 5) {
			printf("Please enter again!\n");
			scanf("%d", &d);
	}
	if(d == 1) strcpy(add->rela, "Classmate");
	if(d == 2) strcpy(add->rela, "Colleague");
	if(d == 3) strcpy(add->rela, "Relative");
	if(d == 4) strcpy(add->rela, "Teacher");
	if(d == 5) strcpy(add->rela, "Others");
	    printf("Phonenumber:");
	    scanf("%s",add->pnum);
	    printf("E-mail:");
	    scanf("%s",add->email);
	    printf("Address:");
	    scanf("%s",add->address);
		p2->next=add;
		p2=add;
		add->next=NULL;
	    Rank_Records(head);
		printf("Continue to add?[Y/N]:");
	    getchar();
		ch=getchar();
	}
	system("pause");
	return (head);
}

int Select_Menu()
{
	int ch;
	do{
	system("cls");
	printf("\n\n");
	printf("                        Address-Book                           \n");
	printf("+-------------------------------------------------------------+\n");
	printf("|  1.Inquire                                                  |\n");
	printf("|  2.Display                                                  |\n");
	printf("|  3.Delete                                                   |\n");
	printf("|  4.Add               *       *   *********   *        *     |\n");
	printf("|  5.Modification      * *     *   *           *        *     |\n");
	printf("|  6.Statistic         *   *   *   *********   *        *     |\n");
	printf("|  7.Sort              *     * *   *           *        *     |\n");
	printf("|  8.Save              *       *   *********     ******       |\n");
	printf("|  9.Help                                                     |\n");
	printf("|  10.About                                                   |\n");
	printf("|  0.Exit                                                     |\n");
	printf("+-------------------------------------------------------------+\n");
	printf("Please select the services you need[0-10]:");
	scanf("%d",&ch);
	}while((ch<0)||(ch>10));
	return (ch);
}

void Help()
{
	FILE *openfp;
	char ch;
	if((openfp=fopen("Help.txt","r"))==NULL)
	{
		printf("Error!!Can't open this file!!\n");
		exit(0);
	}
	while(!feof(openfp))
	{
		ch=fgetc(openfp);
		putchar(ch);
	}
	printf("\n");
	system("pause");
}

void About_Us()
{
	int num=1;
	system("cls");
	printf("\n*---------------------*\n");
	printf("| 1.About our team    |\n");
	printf("| 2.Team numbers      |\n");
	printf("| 0.Exit              |\n");
	printf("*---------------------*\n");
	while(num!=0)
	{
		printf("Input your seletc[0-2]:");
		scanf("%d",&num);
		switch(num)
		{
	case 1:
		printf("\n*------------------------------------------------------------------*\n");
		printf("| The name of our team: NEU_Three Idiots                           |\n");
		printf("| The time of set up:   2017.2.23                                  |\n");
		printf("| Our colleague:        Northeast University.                      |\n");
		printf("| Our class:            College of computers and engineering 1605. |\n");
		printf("*------------------------------------------------------------------*\n");
		break;
	case 2:
		printf("*-------------------------------------------*\n");
		printf("| Name           Gender  Age   Student's ID |\n");
		printf("| ChenHongchao   man     19    20164436     |\n");
		printf("| ZhangYaqiang   man     18    20164382     |\n");
		printf("| CaoYue         man     18    20164417     |\n");
		printf("*-------------------------------------------*\n");
		break;
	     }
	}
	system("pause");
}

void Statistic_Records(People *head)
{
	int i=0,cnt=0,s[4]={0,25,50,100};
	char ch,str[5][15]={"Classmate","Colleague","Relative","Teacher","Others"};
	struct People *p1,*p2;
	p1=p2=head;
	printf("\n+--------------------------------+\n");
	printf("| 1.Statistic by Age             |\n");
	printf("| 2.Statistic by Relation        |\n");
	printf("+--------------------------------+\n");
	for(;;)
	{
		printf("Please select the services you need[1/2]:");
		getchar();
	    scanf("%c",&ch);
	    if(ch>'0'&&ch<'3')break;
	    else printf("The number you entered is incorrect！\n");
	}
	if(ch=='1')
	{
		for(i=0;i<3;i++)
		{
		  p1=head;cnt=0;
		  printf("\nAge between %d-%d:\n",s[i],s[i+1]);
		  printf("+---------------------------------------------------------------------------------------------------------------------+\n");
	      printf("|Number    Name            Age    Relation   Phonrnumber     E-mail               Address     \t\t\t      |\n");
		  while(p1!=NULL)
		  {
			if((p1->age>s[i])&&(p1->age<=s[i+1]))
			{
				printf("|%-10d%-16s%-7d%-11s%-16s%-21s%-36s|\n",p1->num,p1->name,p1->age,p1->rela,p1->pnum,p1->email,p1->address);
				cnt++;
			}
			p1=p1->next;
		  }
		  printf("+-------------------------------------------------Number: %d-----------------------------------------------------------+\n",cnt);
	   }
	}
	else if(ch=='2')
	{
	   for(i=0;i<5;i++)
	   {
		printf("\n%s:\n",str[i]);
		printf("+---------------------------------------------------------------------------------------------------------------------+\n");
		printf("|Number    Name            Age    Relation   Phonrnumber     E-mail               Address     \t\t\t      |\n");
		while(p1!=NULL)
		{
			if(strcmp(p1->rela,str[i])==0)
			{
				printf("|%-10d%-16s%-7d%-11s%-16s%-21s%-36s|\n",p1->num,p1->name,p1->age,p1->rela,p1->pnum,p1->email,p1->address);
				cnt++;
			}
			p1=p1->next;
		}
		printf("+-------------------------------------------------Number: %d-----------------------------------------------------------+\n",cnt);
		p1=head;cnt=0;
	   }
	}
	system("pause");
}

void Rank_Records(People *head)
{
	int cnt=1;
	People *p1;
	p1=head;
	while(p1!=NULL)
	{
		p1->num=cnt;
		cnt++;
		p1=p1->next;
	}
}

void Sort_Records(People *head) {
	People *p0 = head, *p1, *p2;
	for(p0 = head; p0 != NULL; p0 = p0->next) {
		p2 = p0;
		for(p1 = p0->next; p1 != NULL; p1 = p1->next) {
			if((strcmp(p2->name, p1->name) > 0))
				Swap_Records(p2, p1);
		}
	}
	printf("Sort success! (sort by alphabetical order)\n");
	Rank_Records(head);
	system("pause");
}

void Save_Records(People *head)
{
	FILE *fp;
	char filename[10], ch;
	People *p1;
	Rank_Records(head);
	printf("Please enter the filename of the address-book to be saved:");
	scanf("%s",filename);
	if((fp=fopen(filename,"w"))==NULL)
	{
		printf("An error occurred ,which could not open this file!!\n");
		return;
	}
	p1=head;
	while(p1!=NULL)
	{
		fwrite(p1,LEN,1,fp);
		p1=p1->next;
	}
	printf("Save success!\n");
	fclose(fp);
	printf("Do you want to back up the file? (Y/N)\n");
	getchar();
	scanf("%c", &ch);
	if(ch == 'Y' || ch == 'y')
	{
		if((fp=fopen("backup.txt","w+"))==NULL)
	   {
		printf("An error occurred ,which could not open this file!!\n");
		return;
	   }
	   p1=head;
	   while(p1!=NULL)
	   {
		fwrite(p1,LEN,1,fp);
		p1=p1->next;
	   }
	   printf("Backup success!\n");
	   fclose(fp);
	
	}
	system("pause");
}

