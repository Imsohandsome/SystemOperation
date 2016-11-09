#include <stdio.h>
#include <malloc.h>
#include <string.h>
#include <stdbool.h>


typedef struct PCB  
{  
    int ID;                         //��ʶ�� 
	char name;                     //���� 
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
PCB * InsertPCB(char name,int ComeTime,int ServerTime){
	PCB *p=(PCB*)malloc(sizeof(PCB));
	//p->name=name;
	p->name=name;
	p->ComeTime=ComeTime;
	p->ServerTime=ServerTime;
	return p;
} 


//��ӽڵ� 
void InsertNode(PCB *p,List *PList){
	Node *current=*PList;
	Node *temp=(Node*)malloc(sizeof(Node));
	temp->data=p;
	temp->next=NULL;
	if(*PList==NULL){
		*PList=temp;
	}else{
		while(current->next!=NULL){
			current=current->next;
		}
		current->next=temp;
	}
		
} 
//ɾ���ڵ� 
bool DelectNode(List * PList,Node *node){
	Node *current = *PList;
	if(current->data->name==node->data->name){
		*PList=node->next;
		free(node);
		return true; 
	}
	while(current->next!=NULL){
		
		if(current->next->data->name==node->data->name){
			current->next=node->next;
			free(node);
			return true;	
		}
		free(node);
	}
}