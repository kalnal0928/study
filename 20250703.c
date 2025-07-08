#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int k;
    struct Node* np;
}SL;

SL* head = NULL;  // 초기화 추가

// 함수 선언 추가
void insNode();
void findNode();
void PrnNode();
void delNode();
SL* mNode();

int main(int argc, char* argv[]) {
    int sel;

    while (1) {
        printf("Menu, 1.insert 2.delete 3.Print 4. Find 5. exit.....");
        scanf("%d", &sel);
        switch (sel)
        {
        case 1:
            insNode();
            break;

        case 2:
            delNode();
            break;

        case 3:
            PrnNode();
            break;

        case 4:
            findNode();
            break;

        case 5:
            exit(0);

        default:
            printf("\n Try Again....\n");
        }
    }
    return 0;
}

SL* mNode()
{
    int item;
    SL* temp;
    printf("Type Number...");
    scanf("%d", &item);

    temp = (SL*)malloc(sizeof(SL));
    temp->k = item;
    temp->np = NULL;  // 새 노드의 다음을 NULL로 초기화

    return temp;
}

void insNode()
{
    int item;
    SL *t, *next;
    
    t = mNode();  // mNode 함수를 사용하여 새 노드 생성
    printf("Type Number...");
    scanf("%d", &item);

    t = (SL*)malloc(sizeof(SL));
    t->k = item;
    t->np = NULL;  // 새 노드의 다음을 NULL로 초기화

    if(head == NULL){
        head = t;
    }
    else {
        next = head;
        while (next->np != NULL) {
            next = next->np;
        }
        next->np = t;  // 마지막 노드에 새 노드 연결
    }
    printf("Node inserted successfully!\n");
}


void delNode()
{
    SL *next, *post;
    int fdata;

    next=head;
    post=head;

    if(head == NULL)
        printf("not exist data...\n");

    else{
        printf("\n find data?///");
        scanf("%d", &fdata);

        if(head ->np == NULL){
            if(fdata==head->k){
                head=NULL;
                printf("deleted data...\n");
                free(next);
            }
        }
        else{
            while(next->np !=NULL){
                if(fdata != next->k){
                    post=next;
                    next=next->np;
                }
                else {
                    if(head==next){
                        head=next->np;
                        printf("deleted data...\n");
                        free(next);
                    }
                    else{
                        post->np=next->np;
                        printf("deleted data...\n");
                        free(next);
                    }
                    return; 
                }
            }
            if(fdata == next->k){
                post ->np=NULL;
                printf("deleted data...\n");
                free(next);
            }else{
                printf("not exist data......\n");
            }
        }
    }
}

void PrnNode(){
    SL *next;

    if(head == NULL)
        printf("\n... Not exist a data\n");
    else {
        next = head;
        while(next -> np != NULL){
            printf("%d -> ", next->k);
            next = next->np;
        }
        printf("%d\n", next->k);  // 마지막 노드 출력
    }
}

void findNode()
{
    int fdata;
    SL *next;

    printf("Type Number...");
    scanf("%d", &fdata);

    if(head == NULL){
        printf("not exist data......\n");
        return;
    }

    next = head;
    while(next != NULL){
        if(fdata == next->k){
            printf("Found data...\n");
            return;
        }
        next = next->np;
    }
    printf("Not Found data...\n");
}

