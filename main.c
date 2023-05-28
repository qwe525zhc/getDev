#include <stdio.h>
#include "stu.h"

void saveStudent(struct Student *ptr)
{
   FILE  *fp = fopen("mystudent.txt", "w");
   printf("!\n");
   printf("!\n");

   if(fp==NULL)
   {
	  printf("open error\n");
	  return ;
   }
   int  ret = fwrite(ptr,  sizeof(struct Student),  5, fp);
   if(5==ret)
   {
	  printf("write success\n");
   }
   else
	 printf("write error\n");
   fclose(fp);
}
void readStudent(struct Student *ptr)
{
    FILE  *fp = fopen("mystudent.txt", "r");
	if(NULL==fp)
	{
	   printf("read fail\n");
	   return ;
	}
	int ret = fread(ptr, sizeof(struct Student), 5, fp);
	fclose(fp);
}
void updateStudent(int n, float s)
{
    FILE *fp = fopen("mystudent.txt", "r+");
	if(fp==NULL)
	{
	   printf("update student fail\n");
	   return ;
	}
	fseek(fp,  n*sizeof(struct Student), SEEK_SET);
	struct Student temp;
	fread(&temp, sizeof(struct Student), 1, fp);
	temp.score = s;
	fseek(fp,  n*sizeof(struct Student), SEEK_SET);
	fwrite(&temp, sizeof(struct Student), 1, fp);
	fclose(fp);

}
int  main()
{
    int i ;
	struct  Student  as[5]={{12,"zhang", 79.5},{7, "li", 91.5},{18, "wang", 67.5},\
	                        {9, "wu", 51.5},{14,"zhao", 89.5}};
	struct  Student  newas[5] ;
	saveStudent(as);
    readStudent(newas);
    
	for(int i=0; i<5; i++)
	  printf("id=%d, name=%s, score=%f\n", newas[i].id, newas[i].name, newas[i].score);
    
    int n ;
	float s;
	printf("please input id of student: ");
	scanf("%d", &n);
	printf("please input new score of student: ");
	scanf("%f", &s);
	updateStudent( n, s );

    readStudent(newas);
    
	for(int i=0; i<5; i++)
	  printf("id=%d, name=%s, score=%f\n", newas[i].id, newas[i].name, newas[i].score);
    

}
