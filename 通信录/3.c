#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Address_Book.h"
#define LEN sizeof(struct People)

People *Delete_Records(People *head)
{
	People *p1,*p2;
	char a[30];
	int i;
	char sign='y';
	printf("\t\t*---------------------*\n");
	printf("\t\t|   1--Name           |\n");
	printf("\t\t|   2--Phone Number   |\n");
	printf("\t\t|   3--Email          |\n");
	printf("\t\t|   4--Address        |\n");
	printf("\t\t*---------------------*\n");
	printf("Please delete according to the above type.");
	while(sign=='Y'||sign=='y')
	{
	   for(;;)
	   {
		printf("please enter a number[1-4]:");
	    scanf("%d",&i);
	    if(i>0&&i<5)break;
	    else printf("The number you entered is incorrect！\n");
	   }
	   p1=p2=head;
	   switch(i)
	   {case 1:printf("Please enter the name of the contact you want to delete:");
	           scanf("%s",a);
	           for(;;)
	           {
	              if(strcmp(a,p1->name)==0)
	              {
			      printf("Delete success! \n");
		          if(head==p1){head=p1->next;}
		          else{p2->next=p1->next;}
		          break;
	              }
	              else{p2=p1; p1=p1->next;}
	              if(p1==NULL){printf("The name of the person you want to delete is not found in the address book！\n");break;}
	           }break;
	   case 2:printf("Please enter the phone number of the contact you want to delete:");
	           scanf("%s",a);
	           for(;;)
	           {
	              if(strcmp(a,p1->pnum)==0)
	              {
			      printf("Delete success! \n");
		          if(head==p1){head=p1->next;}
		          else{p2->next=p1->next;}
		          break;
	              }
	              else{p2=p1; p1=p1->next;}
	              if(p1==NULL){printf("The phone number of the person you want to delete is not found in the address book！\n");break;}
	           }break;
		case 3:printf("Please enter the email of the contact you want to delete:");
	           scanf("%s",a);
	           for(;;)
	           {
	              if(strcmp(a,p1->email)==0)
	              {
			      printf("Delete success! \n");
		          if(head==p1){head=p1->next;}
		          else{p2->next=p1->next;}
		          break;
	              }
	              else{p2=p1; p1=p1->next;}
	              if(p1==NULL){printf("The email of the person you want to delete is not found in the address book！\n");break;}
	           }break;
		case 4:printf("Please enter the address of the contact you want to delete:");
	           scanf("%s",a);
	           for(;;)
	           {
	              if(strcmp(a,p1->address)==0)
	              {
			      printf("Delete success! \n");
		          if(head==p1){head=p1->next;}
		          else{p2->next=p1->next;}
		          break;
	              }
	              else{p2=p1; p1=p1->next;}
	              if(p1==NULL){printf("The address of the person you want to delete is not found in the address book！\n");break;}
	           }break;
	    }
	   if(head==NULL)
	   {
		 printf("Your address book is empty。\n");
		 sign='n';
	   }
	   else
	   {
		  printf("Do you want to continue deleting?(Y/N)");
		  getchar();
		  scanf("%c",&sign);
	    }
    }
	system("pause");
	return(head);
}

void investigation()
{
	FILE *fp;
	char a[100];
	if((fp=fopen("investigation.txt","w"))==NULL)
	{
		printf("An error occurred ,which could not open this file!!");
		exit(0);
	}
	printf("We will collect some of your valuable suggestions, thank you for your cooperation.\n");
	fprintf(fp,"---------------------------------------------------Feedback----------------------------------------------------\n");
	printf("1.Full score of 10,how much do you want to give us?\n");
	printf("Score:");
	scanf("%s",a);
	fprintf(fp,"\t1.Full score of 10,how much do you want to give us?\n");
	fprintf(fp,"\tScore:");
	fprintf(fp,"\t%s",a);
	printf("2.Do you think we have some shortcomings?\n");
	scanf("%s",a);
	fprintf(fp,"\n\t2.Do you think we have some shortcomings?\n");
	fprintf(fp,"\t%s",a);
	printf("3.Could you please give us some advice on our shortcomings?\n");
	scanf("%s",a);
	fprintf(fp,"\n\t3.Could you please give us some advice on our shortcomings?\n");
	fprintf(fp,"\t%s",a);
	fprintf(fp,"\n---------------------------------------------------------------------------------------------------------------\n");
	printf("Thank you for your cooperation.\n");
	printf("Thank you for using! Goodbye! \n");
}

void Display_Records(People *head)
{
	People *p1;
	Rank_Records(head);
	p1=head;
	printf("+------------------------------------------------Address-Book----------------------------------------------------------+\n");
	printf("|     Number  Name          Age    Relation    Phone Number    Email               Address                             |\n");
	while(p1!=NULL)
	{
		printf("|     %-8d%-14s%-7d%-12s%-16s%-20s%-36s|",
			p1->num,p1->name,p1->age,p1->rela,p1->pnum,p1->email,p1->address);
		p1=p1->next;
		printf("\n");
	}
	printf("+----------------------------------------------------------------------------------------------------------------------+\n");
	system("pause");
}

void Inquire_Records(People *head)
{
	int i;
	char a[30];
	People *p1;
	Rank_Records(head);
	p1=head;
	printf("\t\t*---------------------*\n");
	printf("\t\t|   1--Name           |\n");
	printf("\t\t|   2--Phone Number   |\n");
	printf("\t\t|   3--Email          |\n");
	printf("\t\t|   4--Address        |\n");
	printf("\t\t*---------------------*\n");
	for(;;)
	{
		printf("please enter a number[1-4]:");
	    scanf("%d",&i);
	    if(i>0&&i<5)break;
	    else printf("The number you entered is incorrect！\n");
	}
	switch(i)
	{ case 1:printf("Please enter the name of the person you want to inquire：");
	         scanf("%s",a);
			 for(;;)
	        {
	           if(strcmp(a,p1->name)==0)
			   {
		           printf("+-----------------------------------------------address list-----------------------------------------------------------+\n");
	               printf("|     Number  Name          Age    Relation    Phone Number    Email               Address                             |\n");
				   printf("|     %-8d%-14s%-7d%-12s%-16s%-20s%-36s|\n",
		           p1->num,p1->name,p1->age,p1->rela,p1->pnum,p1->email,p1->address);
				   printf("+----------------------------------------------------------------------------------------------------------------------+\n");
				   break;
	           }
	            else{ p1=p1->next;}
	            if(p1==NULL){printf("Don't find the person you want to inquire in the address list！\n");break;}
	         }break;
	  case 2:printf("Please enter the phone number of the person you want to inquire：");
	         scanf("%s",a);
			 for(;;)
	        {
	           if(strcmp(a,p1->pnum)==0)
			   {
		           printf("+-----------------------------------------------address list-----------------------------------------------------------+\n");
	               printf("|     Number  Name          Age    Relation    Phone Number    Email               Address                             |\n");
				   printf("|     %-8d%-14s%-7d%-12s%-16s%-20s%-36s|\n",
		           p1->num,p1->name,p1->age,p1->rela,p1->pnum,p1->email,p1->address);
				   printf("+----------------------------------------------------------------------------------------------------------------------+\n");
				   break;
	           }
	            else{ p1=p1->next;}
	            if(p1==NULL){printf("Don't find the person you want to inquire in the address list！\n");break;}
	        }break;
	  case 3:printf("Please enter the email of the person you want to inquire：");
	         scanf("%s",a);
			 for(;;)
	        {
	           if(strcmp(a,p1->email)==0)
			   {
		           printf("+-----------------------------------------------address list-----------------------------------------------------------+\n");
	               printf("|     Number  Name          Age    Relation    Phone Number    Email               Address                             |\n");
				   printf("|     %-8d%-14s%-7d%-12s%-16s%-20s%-36s|\n",
		           p1->num,p1->name,p1->age,p1->rela,p1->pnum,p1->email,p1->address);
				   printf("+----------------------------------------------------------------------------------------------------------------------+\n");
				   break;
	           }
	            else{ p1=p1->next;}
	            if(p1==NULL){printf("Don't find the person you want to inquire in the address list！\n");break;}
	        }break;
	   case 4:printf("Please enter the address of the person you want to inquire：");
	         scanf("%s",a);
			 for(;;)
	        {
	           if(strcmp(a,p1->address)==0)
			   {
		           printf("+-----------------------------------------------address list-----------------------------------------------------------+\n");
	               printf("|     Number  Name          Age    Relation    Phone Number    Email               Address                             |\n");
				   printf("|     %-8d%-14s%-7d%-12s%-16s%-20s%-36s|\n",
		           p1->num,p1->name,p1->age,p1->rela,p1->pnum,p1->email,p1->address);
				   printf("+----------------------------------------------------------------------------------------------------------------------+\n");
				   break;
	           }
	            else{ p1=p1->next;}
	            if(p1==NULL){printf("Don't find the person you want to inquire in the address list！\n");break;}
	        }break;
	}
	system("pause");
}

void Swap_Records(People *a, People *b) {
	char sn[50]; 
	char sp[50]; 
	char se[50]; 
	char sm[50];
	int t;
	memset(sn, 0, sizeof(sn));
	memset(sp, 0, sizeof(sp));
	memset(se, 0, sizeof(se));
	memset(sm, 0, sizeof(sm));
	strcpy(sn, a->name);
	strcpy(a->name, b->name);
	strcpy(b->name, sn);
	strcpy(sp, a->pnum);
	strcpy(a->pnum, b->pnum);
	strcpy(b->pnum, sp);
	strcpy(se, a->email);
	strcpy(a->email, b->email);
	strcpy(b->email, se);
	strcpy(sm, a->address);
	strcpy(a->address, b->address);
	strcpy(b->address, sm);
	t = a->age;
	a->age = b->age;
	b->age = t;
}