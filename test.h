#pragma once
#include<stdio.h>
#include<string.h>
#include<assert.h>
#include <stdlib.h>     /* qsort */

#define SIZE 3
#define NAME 10
#define SEX 2
#define NUMBER 11
#define PLACE 20

typedef struct person
{
	char name[NAME];
	int age;
	char sex[SEX];
	char tele[NUMBER];
	char add [PLACE];
}person;
//����contact�е�data��sz �߶Ȱ󶨣����Է�һ��
typedef struct contact
{
	person *data;//!!!!����ֻ�ŵ�ַ���������������棬�����ַȷ�����¿ռ����ȥ���������������
	int sz;
	int max;
}contact;
void add_num(contact* con);
void del_num(contact* con);
void modi_num(contact* con);
void show_num(contact* con);
void sort_num(contact* con);
void find_num(contact* con);
void init_con(contact* con);
void exit_num(contact* con);
