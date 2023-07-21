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
//��鲢����
int check_add(contact* con)
{
	if (con->sz < con->max)
		return 0;
	else
	{
		person* pst;
		pst = (person*)realloc(con->data, sizeof(person) * (SIZE + 1));
		if (NULL == pst)
		{
			perror("add_num");
			return -1;
		}
		con->max++;
		printf("���ݳɹ�\n");
	}
}
void add_from(contact* con)
{
	assert(con);
	printf("���Ƚ���ȡ�Ѵ��ڵ�ͨѶ¼\n");
	FILE* pf = fopen("contact.txt", "r");
	if (pf == NULL)
	{
		perror("fopen");
		return;
	}
	else
	{
		while (fread(con->data + con->sz, sizeof(person), 1, pf))
		{
			con->sz++;
		}
	}
	fclose(pf);
	pf = NULL;
}
void add_num(contact * con)
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
	con->sz++;
}
void del_num(contact* con)
{
	assert(con);
	printf("please input the name you want to delete\n");
	char tag[NAME];
	scanf("%s", tag);
	int i = Find_by_name(con, tag);
	memmove(&(con->data[i]), &(con->data[i + 1]),sizeof(person));//ע����߲���con->data,data�Ѿ���ɵ�ַ��
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
	 person*personA = (person*)p1;
	 person* personB =(person*)p2;
	 return strcmp(personA->name, personB->name);
}

void sort_num(contact* con)
{
	assert(con);
	printf("��������ΪҪ������\n");
	qsort(con->data, con->sz,sizeof(person),cam_by_name);
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
	assert(con);
	con->max = SIZE;
	con->sz = 0;
	con->data = (person*)malloc(sizeof(person) * SIZE);
	if (NULL == con->data)
	{
		perror("init_con");
		return;
	}
	add_from(con);
}
//search by name ,if name is found,return index,else return 0
void exit_num(contact* con)
{
	FILE* pf=fopen("contact.txt", "w");
	if (pf == NULL)
	{
		perror("fopen");
		return;
	}
	while (con->sz--)
	{
		fwrite(con->data+con->sz, 1, sizeof(person), pf);
		
	}
	fclose(pf);
	free(con->data);
	con->data = NULL;
	pf = NULL;
	printf("����ɹ�\n");

}

