# include <stdio.h>
struct student
{
char name[20];
int roll_no;
int marks;
}s[20];
void create (struct student s[],int n);
void display (struct student s[],int n);
int search (struct student s[], int n, int key);
void Delete (struct student s[], int n, int pos);
void modify (struct student s[],int n);
void append (struct student s[],int n);
int main()
{
int i,n,ch,pos,key;
printf("\n----Menu----\n1.Create\n2.Display\n3.Search\n4.Delete\n5.Modify\n6.Append");
printf("\nEnter no of records");
scanf("%d",&n);
do
{
printf("\nEnter your choice");
scanf("%d",&ch);
switch(ch)
{
case 1: create(s,n);
break;
case 2: display(s,n);
break;
case 3: printf("\nEnter the record to be search (roll_no):");
scanf("%d",&key);

pos=search(s,n,key);
if (pos==-1)
printf("\nRecord not found");
else
printf("\nRecord is found at %d",pos+1);
break;
case 4: printf("\nEnter the roll no to delete");
scanf("%d",&key);
pos=search(s,n,key);
if (pos==-1)
printf("\nRecord not found");

else
{
Delete(s,n,pos);
n--;
}
break;
case 5:modify(s,n);
break;
case 6:append(s,n);
case 7: break;
}
} while(ch!=8);

}
void create (struct student s[],int n)
{
int i;
printf("\nEnter the data i.e. name, roll no and marks\n");
for (i=0;i<n;i++)
scanf("%s%d%d",&s[i].name,&s[i].roll_no,&s[i].marks);

}
void display (struct student s[],int n)
{
int i;
printf("\n Name Roll_No Marks\n");
for (i=0;i<n;i++)
printf("%s\t%d\t%d\n",s[i].name,s[i].roll_no,s[i].marks);
}
int search (struct student s[], int n, int key)
{
int i;
for (i=0;i<n;i++)
if (s[i].roll_no==key)
return (i);
return (-1);
}
void Delete (struct student s[], int n, int pos)
{
int i;
for (i=pos+1;i<n;i++)
s[i-1]=s[i];
}
void modify (struct student s[],int n)
{
int i,key;
printf("\nEnter the roll no whose data is to be modified: ");
scanf("%d",&key);
i=search(s,n,key);
printf("\nEnter new name roll_no and marks");
scanf("%s%d%d",&s[i].name,&s[i].roll_no,&s[i].marks);
}

void append (struct student s[],int n)
{
n++;
printf("\nEnter name, roll_no and marks");
scanf("%s%d%d",&s[n].name,&s[n].roll_no,&s[n].marks);

}