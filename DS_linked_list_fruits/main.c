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

//일단 사용안함.
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
		error("리스트가 비었습니다.");
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
		error("리스트가 비었습니다.");
	}
	removed = pre->link;//전에 노드가 가르키는 곳의 주소 즉 전의것 pre가 가리키는 다음 노드 
	pre->link = removed->link;
	free(removed);
	return head;

}

void print_list(Listnode* head) {
	printf("List: ");
	for (Listnode* p = head->link; p != NULL; p = p->link) {//head 의 data 말고 head가 가리키는 곳의 data를 넣어야함

		printf("%s->", p->data.name);//value주의!!!!!

	}
	printf("\n");
}
//pre를 찾기 
Listnode* finding(Listnode* head, int index) { //pre를 반환해야함 
	int i;
	Listnode* f = (Listnode*)malloc(sizeof(Listnode));
	Listnode* p;
	for (p = head, i = 0; p != NULL; p = p->link, i++) {//fidning함수는 포인터가 null값 될때까지만 간다
		move++;
		if (index == -1) {//-1인경우는SELECT에서 미리 처리해놓음
			return f;
		}
		else if (index == i) {
			return p;

		}
		f = p;//for 마지막에 전 node저장용 

		/*
		else if (index==1) {//여기 고침 1치면 pre니까 0을 반환하려고

			f = p;
			return f;
		}
		*/
		// 링크무브


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


		if (strcmp(p->data.name, val.name) == 0) return f;//string 비교 함수넣기
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
		if (search(head, val) != NULL) {//해당 값이 있다는 말
			printf("해당값이 이미 있습니다.\n");
			return;
		}

		//inputVal이 필요한가?
		if (inputPos - 1 > countNode(head)) {
			printf("the last index is %d. Insert at the end of the list\n", countNode(head));
			t = finding(head, countNode(head) + 1);
			insert(head, t, val);
			//t = finding(head, inputPos);//move 처리용
		}
		else {
			t = finding(head, inputPos);
			insert(head, t, val);//구조체안에 넣는다.
		}


		//printf("Move along the Link: %d \n", move - 1);//finding에 넣어야하나 .. 과제용
		//insert();
		break;



	case 2:



		printf("fruit name to delete :");
		scanf_s("%s", inputVal, sizeof(char) * 100);

		strcpy_s(val.name, 100, inputVal);


		t = search(head, val);//search는 pre를 반환
		//printf("search debuging %s\n", t->data.name);

		tmp = t->link;//search는 pre node를 반환 그래서 다음노드를 반환하게 함 
		insert_first(dhead, tmp->data);

		printf("%s has been deleted\n", tmp->data.name);
		delete(head, t);//뒤에있는게 지워짐 

		//printf("Move along the Link: %d\n ", move - 1);//과제용


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
	//삭제리스트 head
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