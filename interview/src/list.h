
typedef struct NODE{
	int data;
	struct NODE *Next;
}Node,*pList;

void reserveList(pList headList);
pList creatList();