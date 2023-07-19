#define _CRT_SECURE_NO_WARNINGS 1
#include"test.h"
int Find_by_name(contact* con,char tag[])
{
; assert(con);
	int i = 0;
	for (i = 0; i < con->sz; i++)
	{
		if (strcmp(con->data[i].name, tag) == 0)
		{
			return i;
		}
	}
	return -1;
}
void add_num(contact *con)
{
	assert(con);

	if (con->sz < SIZE)
	{
		printf("����������\n");
		scanf("%s", con->data[con->sz].name);
		printf("����������\n");
		scanf("%d", &(con->data[con->sz].age));
		printf("�������Ա�\n");
		scanf("%s", con->data[con->sz].sex);
		printf("������绰����\n");
		scanf("%s", con->data[con->sz].tele);
		printf("�������ַ\n");
		scanf("%s", con->data[con->sz].add);
	}
	else
	{
		printf("����\n");
	}
	con->sz++;
}
void del_num(contact* con)
{
	assert(con);
	printf("please input the name you want to delete\n");
	char tag[NAME];
	scanf("%s", tag);
	int i = Find_by_name(con, tag);
	memmove(&(con->data[i]), &(con->data[i + 1]),sizeof(con->data));
	con->sz--;
	printf("delete successfully!\n");

}
void modi_num(contact* con)
{
	assert(con);
	printf("please input the name you want to modify\n");
	char tag[NAME];
	scanf("%s", tag);
	int i= Find_by_name(con, tag);
	if (i==-1)
	{
		printf("the targat name cannot be found\n");
	}
	else
	{
		printf("����������\n");
		scanf("%s", con->data[i].name);
		printf("����������\n");
		scanf("%d", &(con->data[i].age));
		printf("�������Ա�\n");
		scanf("%s", con->data[i].sex);
		printf("������绰����\n");
		scanf("%s", con->data[i].tele);
		printf("�������ַ\n");
		scanf("%s", con->data[i].add);
		printf("�޸ĳɹ�\n");
	}
}
void show_num(contact* con)
{
	assert(con);
	int i = con->sz;
	printf("%-20s\t%s\t%-4s\t%-15s\t%-10s\n", "name", "age", "sexual", "telephone", "address");
	for (i = 0; i < con->sz; i++)
	{
		printf("%-20s\t%d\t%-4s\t%-15s\t%-10s\n", 
			con->data[i].name, 
			con->data[i].age, 
			con->data[i].sex,
			con->data[i].tele, 
			con->data[i].add);
	}
}
//���ֵ�÷���ѧϰ����������
 int cam_by_name(const void* p1, const void*p2)
{
	 return strcmp(((contact*)p1)->data[0].name, ((contact*)p2)->data[1].name);
}

void sort_num(contact* con)
{
	assert(con);
	printf("��������ΪҪ������\n");
	qsort(&con, con->sz,sizeof(con->data),cam_by_name);
	show_num(con);
}

void find_num(contact* con)
{
	assert(con);
	printf("please input the name you want to find\n");
	char tag[NAME];
	scanf("%s", tag);
	int i = Find_by_name(con,tag);
	if (i==-1)
	{
		printf("the targat name cannot be found\n");
	}
	else
	{
		printf("%-20s\t%s\t%-4s\t%-15s\t%-10s\n", "name", "age", "sexual", "telephone", "address");
		printf("%-20s\t%d\t%-4s\t%-15s\t%-10s\n", 
			con->data[i].name,
			con->data[i].age,
			con->data[i].sex,
			con->data[i].tele,
			con->data[i].add);
	}

}
void init_con(contact* con)
{
	/*con->sz = 0;
	con->data[con->sz].name = ;*/
	//һ�������ñȽϸ��ӣ�����ʹ��memset
	memset(con->data, 0, sizeof(person));
	con->sz = 0;

}
//search by name ,if name is found,return index,else return 0


