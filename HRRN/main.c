#include <stdio.h>
#include <stdbool.h>
#include "list.c"
/* run this program using the console pauser or add your own getch, system("pause") or input loop */

//�������� 
void insert();
//�������ȼ� 
void GetPriority(List * PList,int time);
int HRRN(List * PList);
int main(int argc, char** argv) {
	List * PList;
	* PList=NULL;
	insert(PList);
	HRRN(PList);
	return 0;
}
//�������� 
void insert(List * PList){
	PCB * P;
		do{
		char name;
		int comeTime;
		int severTime;
		char judge;
		
		printf("%s","\n�����������\n");
		scanf("%c",&name);
		printf("%s","��������̵���ʱ��\n");
		scanf("%d",&comeTime);
		printf("%s","��������̷���ʱ��\n") ; 
		scanf("%d",&severTime);
		P=InsertPCB(name,comeTime,severTime);
		InsertNode(P,PList);
		while(getchar()!='\n') 
			continue;
		printf("%s","������������� y/n\n"); 
		scanf("%c",&judge);
		while(getchar()!='\n') 
			continue;
		if(judge=='n'){
			//printf("yes");
			break;
		}else{
			//printf("no");
			continue;
		}
	}while(true);
} 
// ����Ӧ���㷨 
int HRRN(List * PList){
	int time=0;
	Node * temp;
	temp=*PList;
	Node * current;
	current=*PList;	
	while((*PList)->next != NULL){
		
		if(time==0){                                //��ʼʱֻ��Ҫ�Ƚϵ���ʱ�伴�� 
			while(current->next	!=NULL){
				current=current->next;
				//�����ȷ��� 
				if(temp->data->ComeTime>current->data->ComeTime)
					temp=current;
				//ͬʱ�������ҵ����	
				else if(temp->data->ComeTime==current->data->ComeTime&&temp->data->ServerTime>current->data->ServerTime)
					temp=current;				
			}
			
			printf("������:%c\n",temp->data->name);
			printf("����ʱ��:%d\n",time);
			printf("����ʱ��:%d\n",temp->data->ServerTime);
			time=temp->data->ComeTime+temp->data->ServerTime;
			DelectNode(PList,temp);	
		}else{
			while(current->next	!=NULL){
	 			current=current->next; 
	 			//����Ȩ�ߵ��ȷ��� 
		 		if(temp->data->Level<current->data->Level)
			 		temp=current;
		 		//��ͬ����Ȩ �����ȷ��� 
				 else if(temp->data->Level==current->data->Level&&temp->data->ComeTime>current->data->ComeTime)
				 	temp=current;
 			}
 			
			printf("\n������:%c\n",temp->data->name);
			printf("����ʱ��:%d\n",time);
			printf("����ʱ��:%d\n",temp->data->ServerTime);
			time = time+temp->data->ServerTime;
			DelectNode(PList,temp);  
		} 
		GetPriority(PList,time);
		temp = current = * PList;		
	}
	printf("������:%c\n",temp->data->name);
	printf("����ʱ��:%d\n",time);
	printf("����ʱ��:%d\n",temp->data->ServerTime);
	time=temp->data->ComeTime+temp->data->ServerTime;
	DelectNode(PList,temp);	
}
void GetPriority(List * PList,int time){
	Node * current;
	current=*PList;
	while (current->next!=NULL){
		if(current->data->ComeTime<=time){
			current->data->Level=1+(double)(time-current->data->ComeTime)/(double)(current->data->ServerTime);
			
		}else{
			current->data->Level=9999.0;
		}
		current=current->next;
		
	} 
		if(current->data->ComeTime<=time){
			current->data->Level=1+(double)(time-current->data->ComeTime)/(double)(current->data->ServerTime);
			current=current->next;
		}else{
			current->data->Level=9999.0;
		} 
} 