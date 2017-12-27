#define _GNU_SOURCE
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
struct details{
	char fn[100];
	char ln[100];
	char phn[100];
	char name[100];
};

static int lc;
static char file_name[100];
struct details d[200];
static int i1;

int line_count(char* file_name)
{
             
	FILE *fp = fopen(file_name,"r");
	int ch=0;
	int lines=0;

	while(!feof(fp))
	{
	ch = fgetc(fp);
	if(ch == '\n')
	lines++;
	}
	return lines;
}



void create(FILE* fp)
{
	i1=0;
	lc=0;
	char * line = (char*) malloc(sizeof(char));
	size_t len = 0;
	ssize_t read;
	const char a_delim;
	strcpy(file_name,"input.txt");

	printf("enter file name:");
	gets(file_name);
	lc=line_count(file_name);	
	fp = fopen(file_name, "r");
	//fp=fopen(file_name,'r');
	if (fp == NULL)
	exit(EXIT_FAILURE);

	while ((read = getline(&line, &len, fp)) != -1) 
	{
	//printf("%s\n", line);
	char* name = strtok(line, ",");
	char*  ph=strtok(line-name,"\n");
	//char* fname = strtok(name, " ");
	//char* lname =strtok(line-fname,",");
	//strcpy(d[i1].fn, fname);
	//strcpy(d[i1].ln, lname);
	strcpy(d[i1].name, name);
	strcpy(d[i1].phn, ph);
	i1++;	

	}

	fclose(fp);
	if (line)
	free(line);
	// exit(EXIT_SUCCESS);
}


void sort_contact()
{	int i,j;
	char temp1[100];
	char temp2[100];
	for(i=0; i <=lc ; i++){
	for(j=i+1; j<= lc; j++)
	{
	if(strcmp(d[i].name,d[j].name) > 0)
	{
	strcpy(temp1,d[i].name);	strcpy(temp2,d[i].phn);
	strcpy(d[i].name,d[j].name);	strcpy(d[i].phn,d[j].phn);
	strcpy(d[j].name,temp1);	strcpy(d[j].phn,temp2);
	}
	}	

	}
}

void search(char* name)
{	int j=0;
	for( j=0; j<= lc; j++) 

	{
	if(strcmp(d[j].name,name) == 0)
	{	
	printf("name:%s",d[j].name);
	printf("phone:%s",d[j].phn);
	}
	}
}




insert(char* name_ins,char* phone_ins)
{
	lc++;int s;	
	strcpy(d[lc-1].name,name_ins);
	strcpy(d[lc-1].phn,phone_ins);

	printf("inserted entry\n");
	sort_contact();
	for(s=0;s<=lc+1;s++)
	{
	printf("name: %s\n", d[s].name);
	//printf("lastname: %s\n", d[j].ln);
	printf("ph: %s\n\n", d[s].phn);

	}
}

delete(char* name1)
{
	search(name1);
	printf("entry deleted");
}


int main(void)
{
	FILE * fp;
	int choice; char name_to_search[100];
	char fname_ins[100];
	char lname_ins[100];
	char phone_ins[100];
	char name_ins[100];
	create(fp);
	printf("select choice:\n1.sort\n2.search\n3.insert\n4.delete\n");
	scanf("%d",&choice);
	switch(choice)
	{
	case 1:
	sort_contact(); 
int s;
	for(s=0;s<lc;s++)
	{
	printf("name: %s\n", d[s].name);
	//printf("lastname: %s\n", d[j].ln);
	printf("ph: %s\n\n", d[s].phn);

	}
	break;
	case 2: 

	printf("enter the full name:");
	scanf("%s",name_to_search);
	search(name_to_search);
	break;

	case 3:
	printf("enter first  name:");
	scanf("%s",fname_ins);
	printf("enter last  name:");
	scanf("%s",fname_ins);
	printf("enter the phone number:");
	scanf("%s",phone_ins);
	strcpy(name_ins,fname_ins);
	strcat(name_ins,"\t");
	strcat(name_ins,lname_ins);
	insert(name_ins,phone_ins);
	break;

	case 4:

	printf("enter first  name:");
	scanf("%s",fname_ins);
	printf("enter last  name:");
	scanf("%s",fname_ins);
	strcpy(name_ins,fname_ins);
	strcat(name_ins,"\t");
	strcat(name_ins,lname_ins);

	delete(name_ins);
	}
}
