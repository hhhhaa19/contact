#pragma once
#include<stdio.h>
#include<string.h>
#include<assert.h>
#include <stdlib.h>     /* qsort */

#define SIZE 100
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
//由于contact中的data与sz 高度绑定，所以放一起
typedef struct contact
{
	person data[SIZE];
	int sz;
}contact;
void add_num(contact* con);
void del_num(contact* con);
void modi_num(contact* con);
void show_num(contact* con);
void sort_num(contact* con);
void find_num(contact* con);
void init_con(contact* con);
