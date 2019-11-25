
typedef struct NODE{
	int data;
	struct NODE *Next;
}Node,*pList;

void reserveList(pList headList);
pList creatList();
int moreThanHalfNum(int *array,int length);
int moreThanHalfNumber1(int *array,int length);