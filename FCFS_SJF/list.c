#include <stdio.h>
#include <malloc.h>
#include <string.h>
#include <stdbool.h>


typedef struct PCB  
{  
    int work_id;                     //��ʶ�� 
	char name[20];                   //���� 
    double Level;                    //���ȼ�  
    int submit_time_h;               //�ύʱ��h���� 
    int submit_time_m;               //�ύʱ����Ӳ� 
    int run_time;                    //����ʱ��h����                    
    int space;                       //�洢�ռ�  
} PCB;  

typedef struct Node{
	PCB *data;
	struct Node *next;
} Node;
typedef struct Node *List;





//���PCB 
PCB * InsertPCB(int work_id,char name[20],int submit_time_h,int submit_time_m,int run_time,int space){
	PCB *p=(PCB*)malloc(sizeof(PCB));
	//p->name=name;
	p->work_id=work_id;
	strcpy(p->name,name) ;
	p->submit_time_h=submit_time_h;
	p->submit_time_m=submit_time_m;
	p->run_time=run_time;
	p->space=space; 
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
//��ӽڵ� 
void Insert(List *List,Node * node){
	//static Node temp;
	PCB *p;
	p=InsertPCB(node->data->work_id,node->data->name,node->data->submit_time_h,
	node->data->submit_time_m,node->data->run_time,node->data->space);
	InsertNode(p,List);
	
	//Node * temp=(Node*)malloc(sizeof(Node));
//	temp->data=node->data
//	temp->next=NULL;
//	Node *current=*List;
//	temp->next=NULL;
//	if(*List==NULL)
//		*List=temp;
//	else{
//		while(current->next!=NULL){
//			current=current->next;
//		}
//			
//		current->next=temp;
	//}
}
//�жϽڵ��Ƿ���������
bool IsExit(List * list,Node * node){
	Node * current=*list;
	while(current!=NULL){
		if(current->data->work_id==node->data->work_id)
			return true;
		current=current->next; 
	}
	return false;
} 
//ɾ���ڵ� 
bool DelectNode(List * PList,Node *node){
	List current = *PList;
	List temp;
	if(current->data->work_id==node->data->work_id){
		*PList=current->next;
		free(current);
		return true; 
	}
	while(current!=NULL){
		if(current->data->work_id==node->data->work_id){
			break;
		}
		temp=current;
		current=current->next;
	}
	temp->next=current->next;
	free(current);
	return true;
}
