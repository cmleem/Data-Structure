#include <stdio.h>
#include <stdlib.h>
#pragma warning (disable: 4996)

//자료구조 실습 집합 1번 부분집합 문제
//헤더, 트레일러 이중 연결리스트
//member() 함수 구현
typedef struct node {
	char elem;
	struct node* prev, * next;
}NODE;

typedef struct list {
	NODE* header, * trailer;
	int n;
}LIST;

NODE* get_node() {
	return (NODE*)malloc(sizeof(NODE));
}

void init_list(LIST* L) { //리스트 초기화
	L->header = get_node();
	L->trailer = get_node();
	L->header->next = L->trailer;
	L->trailer->prev = L->header;
	L->n = 0;
}

void addLast(LIST* L, char e) { //리스트 마지막에 노드 추가
	NODE* q = get_node();

	NODE* p = L->trailer;
	q->elem = e;
	q->next = p;
	q->prev = p->prev;
	p->prev->next = q;
	p->prev = q;
	
	L->n++;
}

char get(LIST* L, int r) { // 리스트 조회
	NODE* p = L->header;

	for (int i = 0; i < r; i++) {
		p = p->next;
	}
	//return p->elem;
}

char delete(LIST* L, int r) {
	NODE* p = L->header;

	for (int i = 0; i < r; i++) {
		p = p->next;
	}
	char e = p->elem;
	p->prev->next = p->next;
	p->next->prev = p->prev;
	L->n--;
	//return e;
}

void free_list(LIST* L) { //메모리 해제
	NODE* p = L->header->next;
	NODE* q = p;
	for (int i = 0; i < L->n; i++) {
		q = p->next;
		free(p);
		p = q;
	}
	free(L->header);
	free(L->trailer);
}

int main() {
	LIST A, B;
	init_list(&A);
	init_list(&B);

	int sizeOfA, sizeOfB;

	scanf("%d", &sizeOfA);
	if (sizeOfA != 0) {
		for (int i = 0; i < sizeOfA) {
			int num = 0;
			scanf("%d", &num);
			add(&L, num);
		}
	}




	return 0;
}
