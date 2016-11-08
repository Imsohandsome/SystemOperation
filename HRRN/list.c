#include <stdio.h>
#include <malloc.h>
#include <string.h>
#include <stdbool.h>


typedef struct PCB  
{  
    int ID;                         //��ʶ�� 
	char* name;                     //���� 
    double Level;                   //���ȼ�  
    int ComeTime;                   //����ʱ��  
    int ServerTime;                 //����ʱ��  
    int FinishTime;                 //���ʱ��  
    int TurnoverTime;               //��תʱ��  
    double WeightedTurnoverTime;    //��Ȩ��תʱ��  
} PCB;  

typedef struct Node{
	PCB *data;
	struct Node *next;
} Node;
typedef struct Node *List;





//���PCB 
PCB * InsertPCB(char* name,int ComeTime,int ServerTime){
	PCB *p=(PCB*)malloc(sizeof(PCB));
	p->name=name;
	p->ComeTime=ComeTime;
	p->ServerTime=ServerTime;
	return p;
} 


//��ӽڵ� 
void InsertNode(PCB *p,List *list){
	Node *current=*list;
	Node *temp=(Node*)malloc(sizeof(Node));
	temp->data=p;
	temp->next=NULL;
	if(*list==NULL){
		*list=temp;
	}else{
		while(current->next!=NULL){
			current=current->next;
		}
		current->next=temp;
	}
		
} 
//ɾ���ڵ� 
bool DelectNode(List *list,Node *node){
	Node *current=*list;
	if(strcmp(current->data->name,node->data->name)==0){
		*list=node->next;
		free(node);
		return true; 
	}
	while(current->next!=NULL){
		if(current->next==node){
			current=node->next;
			free(node);
			return true;	
		}else{
			current=current->next;
		}
		return false;
	}
}