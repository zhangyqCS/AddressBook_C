#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Address_Book.h"
#define LEN sizeof(struct People)

int flag;

People *Read_Records() {
	FILE *fp;
	char filename[20];
	People *p1, *p2, *head = NULL;
	int i;
	printf("Please input the filename:");
	scanf("%s", filename);
	if((fp = fopen(filename, "r")) == NULL) {
		printf("Can't open the file!\n\n");
		printf("Please enter again!\n");
		system("pause");
		return head; 
	}
	flag = 0;
	p1 = p2 = (People *)malloc(LEN);
	if(fread(p1, LEN, 1, fp) != 1) {
		printf("You don't save anything in this file!");
		return head;
	}
	for(i = 1;!feof(fp); i++) {
		if(i == 1) head = p1;
		else p2->next = p1;
		p2 = p1;
		p1 = (People *)malloc(LEN);
		fread(p1, LEN, 1, fp);
	}
	p2->next = NULL;
	fclose(fp);
	printf("Read success!\n");
	system("pause");
	return head;
}

People *Input_Records() {
	People *p1, *p2;
	People *head;
	int d;
	char ch = 'Y';
	int n = 0;
	flag = 0;
	printf("Please input the records to the address-book:\n");
	p1 = p2 = (People *)malloc(LEN);
	printf("Name:");
	scanf("%s", p1->name);
	printf("Age:");
	scanf("%d", &p1->age);
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
	if(d == 1) strcpy(p1->rela, "Classmate");
	if(d == 2) strcpy(p1->rela, "Colleague");
	if(d == 3) strcpy(p1->rela, "Relative");
	if(d == 4) strcpy(p1->rela, "Teacher");
	if(d == 5) strcpy(p1->rela, "Others");
	printf("Phonenumber:");
	scanf("%s", p1->pnum);
	printf("E-mail:");
	scanf("%s", p1->email);
	printf("Address:");
	scanf("%s", p1->address);
	while(ch == 'Y' || ch == 'y') {
		printf("Continue to input ?[Y/N]:");
	    getchar();
        ch=getchar();
		n += 1;
		p1->num = n;
		if(n == 1) head = p1;
		else p2->next = p1;
		p2 = p1;
		if(ch != 'Y' && ch != 'y') break;
		p1 = (People *)malloc(LEN);
		printf("Name:");
	    scanf("%s", p1->name);
	    printf("Age:");
	    scanf("%d", &p1->age);
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
	if(d == 1) strcpy(p1->rela, "Classmate");
	if(d == 2) strcpy(p1->rela, "Colleague");
	if(d == 3) strcpy(p1->rela, "Relative");
	if(d == 4) strcpy(p1->rela, "Teacher");
	if(d == 5) strcpy(p1->rela, "Others");
	    printf("Phonenumber:");
	    scanf("%s", p1->pnum);
	    printf("E-mail:");
	    scanf("%s", p1->email);
	    printf("Address:");
	    scanf("%s", p1->address);
	}
	p2->next = NULL;
	system("pause");
	return head;
}

void Modification_Records(People *head) {				//      change
	int m;
	char s[20];
	int num;
	People *p0 = head;
	printf("\t\nPlease select the number (1-4):\n");
    printf("\t*-----------------------*\n");
    printf("\t|1------Name            |\n");
    printf("\t|2------Phone Number    |\n");
    printf("\t|3------Number          |\n");
    printf("\t|4------Return          |\n");
    printf("\t*-----------------------*\n");
    printf("Enter the number:\n");
    scanf("%d", &m);
    while(m != 1 && m != 2 && m != 3 && m != 4) {  
		printf("Error! Please enter again!\n");
		scanf("%d", &m);
	}

	if(m == 1) { 
		printf("Please enter the name of the record you want to modification:"); 
		scanf("%s", s); 
		while(p0 != NULL) {
			if(strcmp(p0->name, s) == 0) {
				printf("Name: "); 
				scanf("%s", p0->name);
				printf("Age: "); 
				scanf("%d", &p0->age);
				printf("Relationship: "); 
				scanf("%s", p0->rela);
				printf("Phone Number: "); 
				scanf("%s", p0->pnum);
				printf("Email: "); 
				scanf("%s", p0->email);
				printf("Mailing Address: "); 
				scanf("%s", p0->address);
				break;
			}
			p0 = p0->next;
			if(p0 == NULL) 
				printf("Can't find the record!\n");
		}
	}

	if(m == 2) { 
		printf("Please enter the phone number of the record you want to modification:"); 
		scanf("%s", s); 
		while(p0 != NULL) {
			if(strcmp(p0->pnum, s) == 0) {
				printf("Name: "); 
				scanf("%s", p0->name);
				printf("Age: "); 
				scanf("%d", &p0->age);
				printf("Relationship: "); 
				scanf("%s", p0->rela);
				printf("Phone Number: "); 
				scanf("%s", p0->pnum);
				printf("Email: "); 
				scanf("%s", p0->email);
				printf("Mailing Address: "); 
				scanf("%s", p0->address);
				break;
			}
			p0 = p0->next;
			if(p0 == NULL) 
				printf("Can't find the record!\n");
		}
	}

	if(m ==3) {
		printf("Please enter the number of the record you want to modification:"); 
		scanf("%d", &num); 
		while(p0 != NULL) {
			if(p0->num == num) {
				printf("Name: "); 
				scanf("%s", p0->name);
				printf("Age: "); 
				scanf("%d", &p0->age);
				printf("Relationship: "); 
				scanf("%s", p0->rela);
				printf("Phone Number: "); 
				scanf("%s", p0->pnum);
				printf("Email: "); 
				scanf("%s", p0->email);
				printf("Mailing Address: "); 
				scanf("%s", p0->address);
				break;
			}
			p0 = p0->next;
			if(p0 == NULL) 
				printf("Can't find the record!\n");
		}
	}
	system("pause");
}

int main() {
	People *head = NULL;
	int i, m;
	system("color F0");
	flag = 1;
	while(flag) {
		system("cls");
		printf("Do you want to load historical records ?\n");
		printf("+-----------------------------+\n");
		printf("|1 Load the histirical records|\n");
		printf("|2 Input new records          |\n");
		printf("+-----------------------------+\n");
		printf("Enter the number:");
		scanf("%d", &m);
		while(m != 1 && m != 2) {
			printf("Error! Please enter again!\n");
			scanf("%d", &m);
		}
		if(m == 1) 
			head = Read_Records();
		else 
			head = Input_Records();
	}
	for(;;) { 
		switch(Select_Menu()) { 
			case 1:				//	creat address-book                        
				Inquire_Records(head);
				break; 
			case 2:				//	dispaly records	                       
				Display_Records(head);
				break;
			case 3:				//	delele records
				head = Delete_Records(head);
				break; 
			case 4:				//	add records
				head = Add_Records(head);
				break;
			case 5:
				Modification_Records(head);
				break;
			case 6:				//	sort
				Statistic_Records(head);  
				break;
			case 7:
				Sort_Records(head);
				break;
			case 8:				//	save records 
				Save_Records(head);	
				break;
			case 9:
				Help();
				break;
			case 10:
				About_Us();
				break;
			case 0:				//	quit
				printf("*--------------------------------------*\n");
				printf("| 1.Would you like give us a feedback? |\n");
				printf("| 2.Exit                               |\n");
				printf("*--------------------------------------*\n");
				for(;;) {
					printf("please enter a number[1-2]:");
					scanf("%d", &i);
					if(i>0 && i<3) break;
					else printf("The number you entered is incorrect！\n");
				}
				if(i == 2)
					printf("\nThank you for using! Goodbye! \n");  
				else 
					investigation();
				exit(0);
		} 
	}
	return 0;
}


