#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define _CRT_SECURE_NO_WARNINGS



//typedef int element;
int move = 0;
typedef struct {
	char name[100];
}element;


typedef struct Listnode {
	element data;
	struct Listnode* link;
}Listnode;


void error(char* message) {
	fprintf(stderr, "%s\n", message);
	return;
}

//�ϴ� ������.
Listnode* insert_first(Listnode* head, element value) {
	Listnode* p = (Listnode*)malloc(sizeof(Listnode));
	p->data = value;
	p->link = head->link;
	head->link = p;
	return head;
}

Listnode* insert(Listnode* head, Listnode* pre, element value) {


	Listnode* p = (Listnode*)malloc(sizeof(Listnode));
	p->data = value;
	p->link = pre->link;
	pre->link = p;
	return head;

}


Listnode* delete_first(Listnode* head) {

	Listnode* removed;
	if (head == NULL) {
		error("����Ʈ�� ������ϴ�.");
		return NULL;
	}
	removed = head;
	head = removed->link;
	free(removed);
	return head;

}

Listnode* delete(Listnode* head, Listnode* pre) {
	Listnode* removed;
	if (head == NULL) {
		error("����Ʈ�� ������ϴ�.");
	}
	removed = pre->link;//���� ��尡 ����Ű�� ���� �ּ� �� ���ǰ� pre�� ����Ű�� ���� ��� 
	pre->link = removed->link;
	free(removed);
	return head;

}

void print_list(Listnode* head) {
	printf("List: ");
	for (Listnode* p = head->link; p != NULL; p = p->link) {//head �� data ���� head�� ����Ű�� ���� data�� �־����

		printf("%s->", p->data.name);//value����!!!!!

	}
	printf("\n");
}
//pre�� ã�� 
Listnode* finding(Listnode* head, int index) { //pre�� ��ȯ�ؾ��� 
	int i;
	Listnode* f = (Listnode*)malloc(sizeof(Listnode));
	Listnode* p;
	for (p = head, i = 0; p != NULL; p = p->link, i++) {//fidning�Լ��� �����Ͱ� null�� �ɶ������� ����
		move++;
		if (index == -1) {//-1�ΰ���SELECT���� �̸� ó���س���
			return f;
		}
		else if (index == i) {
			return p;

		}
		f = p;//for �������� �� node����� 

		/*
		else if (index==1) {//���� ��ħ 1ġ�� pre�ϱ� 0�� ��ȯ�Ϸ���

			f = p;
			return f;
		}
		*/
		// ��ũ����


	}
	return f;


}

int countNode(Listnode* head) {
	int count = -1;
	Listnode* p = head;
	while (p->link != NULL) {


		p = p->link;
		count++;
	}
	return count;
}
Listnode* search(Listnode* head, element val) {
	Listnode* p = head;
	Listnode* f = (Listnode*)malloc(sizeof(Listnode));
	if (p->data.name == NULL) return NULL;


	while (p->link != NULL) {


		if (strcmp(p->data.name, val.name) == 0) return f;//string �� �Լ��ֱ�
		f = p;
		p = p->link;

	}
	return NULL;
}

void init(Listnode* head) {
	element val;
	strcpy_s(val.name, 100, "Peach");
	insert_first(head, val);

	strcpy_s(val.name, 100, "Banna");
	insert_first(head, val);
	strcpy_s(val.name, 100, "Raspberry");
	insert_first(head, val);
	strcpy_s(val.name, 100, "Guava");
	insert_first(head, val);
	strcpy_s(val.name, 100, "Plum");
	insert_first(head, val);
	strcpy_s(val.name, 100, "Cherry");
	insert_first(head, val);
	strcpy_s(val.name, 100, "Grape");
	insert_first(head, val);
	strcpy_s(val.name, 100, "Apple");
	insert_first(head, val);
	strcpy_s(val.name, 100, "Orange");
	insert_first(head, val);
	strcpy_s(val.name, 100, "Mango");
	insert_first(head, val);



}

void select(Listnode* head, Listnode* dhead, int inputSel) {
	int inputPos;
	char inputVal[100];
	Listnode* t;
	element val;
	Listnode* tmp = (Listnode*)malloc(sizeof(Listnode));
	switch (inputSel) {
	case 1:
		printf("enter the fruit:");

		scanf_s("%s", inputVal, sizeof(char) * 100);
		printf("enter the position:");
		scanf_s("%d", &inputPos);



		strcpy_s(val.name, 100, inputVal);
		if (search(head, val) != NULL) {//�ش� ���� �ִٴ� ��
			printf("�ش簪�� �̹� �ֽ��ϴ�.\n");
			return;
		}

		//inputVal�� �ʿ��Ѱ�?
		if (inputPos - 1 > countNode(head)) {
			printf("the last index is %d. Insert at the end of the list\n", countNode(head));
			t = finding(head, countNode(head) + 1);
			insert(head, t, val);
			//t = finding(head, inputPos);//move ó����
		}
		else {
			t = finding(head, inputPos);
			insert(head, t, val);//����ü�ȿ� �ִ´�.
		}


		//printf("Move along the Link: %d \n", move - 1);//finding�� �־���ϳ� .. ������
		//insert();
		break;



	case 2:



		printf("fruit name to delete :");
		scanf_s("%s", inputVal, sizeof(char) * 100);

		strcpy_s(val.name, 100, inputVal);


		t = search(head, val);//search�� pre�� ��ȯ
		//printf("search debuging %s\n", t->data.name);

		tmp = t->link;//search�� pre node�� ��ȯ �׷��� ������带 ��ȯ�ϰ� �� 
		insert_first(dhead, tmp->data);

		printf("%s has been deleted\n", tmp->data.name);
		delete(head, t);//�ڿ��ִ°� ������ 

		//printf("Move along the Link: %d\n ", move - 1);//������


		break;
	case 3:

		print_list(head);
		printf("Deleted ");
		print_list(dhead);
		break;
	case 4:
		exit(1);
		break;
	}
}

int main(void)
{

	Listnode* head;
	head = (Listnode*)malloc(sizeof(Listnode));
	head->link = NULL;//****************
	//��������Ʈ head
	Listnode* dhead;
	dhead = (Listnode*)malloc(sizeof(Listnode));
	dhead->link = NULL;


	int exit = 1;
	int inputSel;
	init(head);
	while (exit) {
		move = 0;

		printf("(1) Insert new Fruit\n");
		printf("(2) Delete the fruit\n");
		printf("(3) Print deleted fruits\n");
		printf("(4) Exit\n");
		printf("Enter the menu:");
		scanf_s("%d", &inputSel);
		if (inputSel < 5 && inputSel>0) {
			select(head, dhead, inputSel);
		}
		else {

			printf("not correct number! try again\n");
		}
		printf("\n");



	}

}