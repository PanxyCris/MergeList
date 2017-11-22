#include<iostream>
using namespace std;
struct Node{
	int data;
	Node *link;
	Node(Node *ptr = NULL){ link = ptr; }
	Node(const int&item, Node *ptr = NULL)
	{data = item; link = ptr;}		
};
Node *merge(Node*,Node*);//合并
Node *printin(int); //输入数字
void printout(Node*);//输出

Node *merge(Node *a, Node *b){
	Node *newhead;
	if (a->data <= b->data)//新链表的头结点
		newhead = a;
	else
		newhead = b;
	Node *prev1 = a, *prev2 = b;//作为保留结点
	while (a && b){
		if (prev1->data <= prev2->data){
			if (prev1->link == NULL)//最后一个节点时终止循环
				break;
			a = prev1->link;//预存下一个节点	
			if (prev1->link->data>prev2->data)//将两个结点连起来
				prev1->link = prev2;		
			prev1 = a;  //移动节点
		}
		else{		
			if (prev2->link == NULL)
				break;
			b = prev2->link;
			if (prev2->link->data>=prev1->data)
				prev2->link = prev1;
			prev2 = b; 
		}
	}
	if (prev1->link == NULL)	//a链表到尾部时
		prev1->link = prev2;
	else
		prev2->link = prev1;
	return newhead;
}

Node *printin(int n){
	Node *head = new Node();
	Node *p = head;
	for (int i = 0; i < n; i++){
		int temp;
		cin >> temp;
		Node *newNode = new Node(temp);
		p->link = newNode;
		p = p->link;
	}
	return head->link;
}

void printout(Node* head){
	Node*p = head;
	while (p){
		cout << p->data;
		if (p->link){
			cout << " ";
			p = p->link;
		}
		else
			break;
	}
}

int main(){
	int lena, lenb;
	cin >> lena >> lenb;
	if (lena&&lenb){
	Node *a = printin(lena);
    Node *b = printin(lenb);
    Node *c = merge(a, b);
	printout(c);
	}
}