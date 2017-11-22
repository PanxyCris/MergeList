#include<iostream>
using namespace std;
struct Node{
	int data;
	Node *link;
	Node(Node *ptr = NULL){ link = ptr; }
	Node(const int&item, Node *ptr = NULL)
	{data = item; link = ptr;}		
};
Node *merge(Node*,Node*);//�ϲ�
Node *printin(int); //��������
void printout(Node*);//���

Node *merge(Node *a, Node *b){
	Node *newhead;
	if (a->data <= b->data)//�������ͷ���
		newhead = a;
	else
		newhead = b;
	Node *prev1 = a, *prev2 = b;//��Ϊ�������
	while (a && b){
		if (prev1->data <= prev2->data){
			if (prev1->link == NULL)//���һ���ڵ�ʱ��ֹѭ��
				break;
			a = prev1->link;//Ԥ����һ���ڵ�	
			if (prev1->link->data>prev2->data)//���������������
				prev1->link = prev2;		
			prev1 = a;  //�ƶ��ڵ�
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
	if (prev1->link == NULL)	//a����β��ʱ
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