
typedef struct ListNode{
	int data;
	struct ListNode *next;
}Node,*pList;

void reserveList(pList headList);
pList creatList();

/*给定一个链表，删除链表的倒数第 n 个节点，并且返回链表的头结点。*/
struct ListNode* removeNthFromEnd(struct ListNode* head, int n);

/*反转链表*/
struct ListNode* reverseList(struct ListNode* head);

/*合并两个排序的链表*/
struct ListNode* mergeTwoLists(struct ListNode* l1, struct ListNode* l2);

/*判断回文链表*/
bool isPalindrome(struct ListNode* head);