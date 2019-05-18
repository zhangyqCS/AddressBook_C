struct People {
	int num;		
	char name[40];		
	int age;
	char rela[40];
	char pnum[40];
	char email[40];
	char address[50];
	struct People *next;
}; 

typedef struct People People;

People *Delete_Records(People *head);
People *Add_Records(People *head);
People *Input_Records();
People * Read_Records();
void Modification_Records(People *head);
void Rank_Records(People *head);
void Display_Records(People *head);
void Save_Records(People *head);
void Inquire_Records(People *head);
void Help();
void Statistic_Records(People *head);
void Swap_Records(People *p1, People *p2);
void Sort_Records(People *head);
void investigation();
void About_Us();
int Select_Menu();
