#include <stdio.h>
#include <stdbool.h>
#include "list.c";
/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int SCFC(List * PList);
void insert(List * PList);

int main(int argc, char** argv) {
	List  PList;
	PList=NULL;
//	char a[20]="ja";
//	char b[20]="jb";
//	char c[20]="jc";
//	char d[20]="jd";
//	char e[20]="je";
//	PCB* ja;
//	PCB* jb;
//	PCB* jc;
//	PCB* jd;
//	PCB* je;
//	ja=InsertPCB(1,a,2,40,20,30);
//	jb=InsertPCB(2,b,2,50,30,15);
//	jc=InsertPCB(3,c,2,55,10,90);
//	jd=InsertPCB(4,d,3,0,24,10);
//	je=InsertPCB(5,e,3,5,6,60);
//	InsertNode(ja,&PList);
//	InsertNode(jb,&PList);
//	InsertNode(jc,&PList);
//	InsertNode(jd,&PList);
//	InsertNode(je,&PList);
	insert(PList);
	SCFC(&PList);
	return 0;
}


void insert(List * PList){
	PCB* p; 
	do{
		int work_id,submit_time_h,submit_time_m,run_time,space;
		char name[20];
		char judge;
		printf("������������ҵ��ţ���ҵ���ƣ��ύʱ�䣬����ʱ�䣬�洢�ռ�\n��ʽ�磺1 JA 2:30 20 130\n");
		scanf("%d %s %d:%d %d %d",&work_id,name,&submit_time_h,&submit_time_m,&run_time,&space);
		p=InsertPCB(work_id,name,submit_time_h,submit_time_m,run_time,space);
		InsertNode(p,PList);
		while(getchar()!='\n') 
			continue;
		printf("%s","������������� y/n\n"); 
		scanf("%c",&judge);
		
		if(judge=='n'){
			//printf("yes");
			break;
		}else{
			//printf("no");
			continue;
		}
	}while(true);
}


int SJF(List * PList){
	//����һ���ݴ���� 
	List SList;
	SList=NULL;
	
	Node * temp;
	temp=*PList;
	Node * current;
	current=*PList;	
	
	//Ѱ�������ύ�Ľ���
	while(current->next	!=NULL){
		current=current->next; 
		if((temp->data->submit_time_h>current->data->submit_time_h)||
			((temp->data->submit_time_h==current->data->submit_time_h)&&(temp->data->submit_time_m>current->data->submit_time_m))){
			temp=current;
		}
	} 
	
	static int time_h,time_m,run_time;
	
	//������ȵ�����̵��ύʱ�� 
	if(*PList!=NULL){
		time_h=temp->data->submit_time_h;
		time_m=temp->data->submit_time_m;
	}
	//�ûس�ʼֵ 
	temp=*PList;
	current=*PList;	
	int wait_time=0;
	while((*PList)->next!=NULL){
		//�ݴ��������ӽڵ� 
		while(current!=NULL){
			if((current->data->submit_time_h<time_h)||
			((current->data->submit_time_h==time_h)&&(current->data->submit_time_m<=time_m))) {
				//�жϽڵ��Ƿ����ݴ������ 
				if(!IsExit(&SList,current))
				//�����������Ľڵ�������ݴ���� 
					Insert(&SList,current);
			}
			current=current->next;	
		}
		//��Ϊ�ݴ���г�ʼֵ 
		temp=current=SList;
		//�����ҵ���� 
		while(current->next	!=NULL){
			current=current->next;
			if(temp->data->run_time>current->data->run_time)
				temp=current; 
		}
		wait_time=(time_h-temp->data->submit_time_h)*60+(time_m-temp->data->submit_time_m);
		time_h=(time_m+temp->data->run_time)/60+time_h; 
		time_m=(time_m+temp->data->run_time)%60;	
		printf("��ҵ���:%d\n��ҵ��:%s\n�ύʱ��: %d:%d\n����ʱ��:%d\n�洢�ռ�:%d\n�ȴ�ʱ��:%d\n",
				temp->data->work_id,temp->data->name,temp->data->submit_time_h,temp->data->submit_time_m,
				temp->data->run_time,temp->data->space,wait_time);			
		
		DelectNode(PList,temp);	
		DelectNode(&SList,temp);
						
		temp = current = * PList;
	}
	wait_time=wait_time+run_time-((temp->data->submit_time_h-time_h)*60+(temp->data->submit_time_m-time_m));
	printf("��ҵ���:%d\n��ҵ��:%s\n�ύʱ��: %d:%d\n����ʱ��:%d\n�洢�ռ�:%d\n�ȴ�ʱ��:%d\n",
				temp->data->work_id,temp->data->name,temp->data->submit_time_h,temp->data->submit_time_m,
				temp->data->run_time,temp->data->space,wait_time);	
}

int SCFC(List * PList){
	Node * temp;
	temp=*PList;
	Node * current;
	current=*PList;	
	static int time_h,time_m,run_time;
	if(*PList!=NULL){
		time_h=temp->data->submit_time_h;
		time_m=temp->data->submit_time_m;
		run_time=0;
	}
	int wait_time=0;
	while((*PList)->next!=NULL){
		
		while(current->next	!=NULL){
			current=current->next;
			//�����ȷ��� 
			if((temp->data->submit_time_h>current->data->submit_time_h)||
				((temp->data->submit_time_h==current->data->submit_time_h)&&(temp->data->submit_time_m>current->data->submit_time_m))){
				temp=current;
			}
		}
		wait_time=wait_time+run_time-((temp->data->submit_time_h-time_h)*60+(temp->data->submit_time_m-time_m));
		run_time=temp->data->run_time;
		time_h=temp->data->submit_time_h;
		time_m=temp->data->submit_time_m;
				
		printf("��ҵ���:%d\n��ҵ��:%s\n�ύʱ��: %d:%d\n����ʱ��:%d\n�洢�ռ�:%d\n�ȴ�ʱ��:%d\n",
				temp->data->work_id,temp->data->name,temp->data->submit_time_h,temp->data->submit_time_m,
				temp->data->run_time,temp->data->space,wait_time);	
		DelectNode(PList,temp);						
		temp = current = * PList;
	}
	wait_time=wait_time+run_time-((temp->data->submit_time_h-time_h)*60+(temp->data->submit_time_m-time_m));
	printf("��ҵ���:%d\n��ҵ��:%s\n�ύʱ��: %d:%d\n����ʱ��:%d\n�洢�ռ�:%d\n�ȴ�ʱ��:%d\n",
				temp->data->work_id,temp->data->name,temp->data->submit_time_h,temp->data->submit_time_m,
				temp->data->run_time,temp->data->space,wait_time);	
}
int minSpace(List * PList){
	//����һ���ݴ���� 
	List SList;
	SList=NULL;
	
	Node * temp;
	temp=*PList;
	Node * current;
	current=*PList;	
	
	//Ѱ�������ύ�Ľ���
	while(current->next	!=NULL){
		current=current->next; 
		if((temp->data->submit_time_h>current->data->submit_time_h)||
			((temp->data->submit_time_h==current->data->submit_time_h)&&(temp->data->submit_time_m>current->data->submit_time_m))){
			temp=current;
		}
	} 
	
	static int time_h,time_m,run_time;
	
	//������ȵ�����̵��ύʱ�� 
	if(*PList!=NULL){
		time_h=temp->data->submit_time_h;
		time_m=temp->data->submit_time_m;
	}
	//�ûس�ʼֵ 
	temp=*PList;
	current=*PList;	
	int wait_time=0;
	while((*PList)->next!=NULL){
		//�ݴ��������ӽڵ� 
		while(current!=NULL){
			if((current->data->submit_time_h<time_h)||
			((current->data->submit_time_h==time_h)&&(current->data->submit_time_m<=time_m))) {
				//�жϽڵ��Ƿ����ݴ������ 
				if(!IsExit(&SList,current))
				//�����������Ľڵ�������ݴ���� 
					Insert(&SList,current);
			}
			current=current->next;	
		}
		//��Ϊ�ݴ���г�ʼֵ 
		temp=current=SList;
		//�����ҵ���� 
		while(current->next	!=NULL){
			current=current->next;
			if(temp->data->space>current->data->space)
				temp=current; 
		}
		wait_time=(time_h-temp->data->submit_time_h)*60+(time_m-temp->data->submit_time_m);
		time_h=(time_m+temp->data->run_time)/60+time_h; 
		time_m=(time_m+temp->data->run_time)%60;	
		printf("��ҵ���:%d\n��ҵ��:%s\n�ύʱ��: %d:%d\n����ʱ��:%d\n�洢�ռ�:%d\n�ȴ�ʱ��:%d\n",
				temp->data->work_id,temp->data->name,temp->data->submit_time_h,temp->data->submit_time_m,
				temp->data->run_time,temp->data->space,wait_time);			
		
		DelectNode(PList,temp);	
		DelectNode(&SList,temp);
						
		temp = current = * PList;
	}
	wait_time=wait_time+run_time-((temp->data->submit_time_h-time_h)*60+(temp->data->submit_time_m-time_m));
	printf("��ҵ���:%d\n��ҵ��:%s\n�ύʱ��: %d:%d\n����ʱ��:%d\n�洢�ռ�:%d\n�ȴ�ʱ��:%d\n",
				temp->data->work_id,temp->data->name,temp->data->submit_time_h,temp->data->submit_time_m,
				temp->data->run_time,temp->data->space,wait_time);	
}