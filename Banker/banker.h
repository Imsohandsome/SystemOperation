#define false 0
#define true !false

//系统中所有进程数量
#define PROCESSES_NUMBER	5
typedef int bool;

typedef struct {
	int	A;
	int	B;
	int	C;
}RESOURCE;

//最大需求矩阵
RESOURCE Max[PROCESSES_NUMBER] = 
{
	{7,5,3},
	{3,2,2},
	{9,0,2},
	{2,2,2},
	{4,3,3}
};

//已分配资源数矩阵
RESOURCE Allocation[PROCESSES_NUMBER] = 
{
	{0,1,0},
	{2,0,0},
	{3,0,2},
	{2,1,1},
	{0,0,2}
};

//需求矩阵
RESOURCE Need[PROCESSES_NUMBER] = 
{
	{7,4,3},
	{1,2,2},
	{6,0,0},
	{0,1,1},
	{4,3,1}
};

//可用资源向量
RESOURCE Available = {3,3,2};

//记录安全序列 
int safe[PROCESSES_NUMBER];