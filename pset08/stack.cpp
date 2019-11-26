//On my honor, I pledge that I have neither received nor provided improper assistance in
//the completion of this assignment.
//Signed: MinjiKim Section: 01 Student Number: 21600069
//  stack.cpp
//  Created by idebtor@gmail.com on December 12, 2018.
/*
* Description:	This program implements a stack using singly-linked list
* without a head structure and without sentinel nodes. It simply links
* node to node. The caller is responsible for maintaining the the first
* node (head) of the list. Most functions need the first node to work
* with the list and returns the first node of the list since it may be
* changed inside of the functions.
*/
#include <iomanip>
#include "stack.h"

// removes all the nodes from the list (which are destroyed),
// and leaving the container nullptr or its size to 0.
pNode clear(pNode p) {
	if (empty(p)) return nullptr;
	DPRINT(cout << "clear: ";);

	while(p != nullptr){
		delete p;
		p = p->next;
	}

	cout << "\n\tAll things are cleared.\n";
	return nullptr;
}

// returns the number of nodes in the list.
int size(pNode p) {
	if (empty(p)) return 0;
	int count = 0;
	while(p != nullptr){
		count++;
		p = p->next;
	}
	return count;
}

// returns true if the list is empty or no nodes.
// To remove all the nodes of a list, see clear().
bool empty(pNode p) {
	return p == nullptr;
}

// inserts a new node with val at the beginning of the list.
// This effectively increases the list size by N.
pNode push(pNode hp, int val, int N) {
	DPRINT(cout << ">push val=" << val << " N="<< N << endl;);
	if (N==1&&val!=0){
		pNode y = new Node;
		if (hp == nullptr){
			y->item = val;
			y->next =nullptr;
			hp = y;
		}else{
			y->item = val;
			y->next = hp;
			hp = y;
		}
	}else{
			for(int i = 0; i < N; i++){
				pNode y = new Node;
				if (hp == nullptr){
					y->item = i;
					y->next =nullptr;
					hp = y;
				}else{
					y->item = i;
					y->next = hp;
					hp = y;
				}
			}
	}


	DPRINT(cout << "<push size=" << size(hp) << endl;);
	return hp;
}

// removes the first node in the list and returns the new first node.
// This destroys the removed node, effectively reduces its size by N.
pNode pop(pNode hp, int N) {
	DPRINT(cout << ">pop size=" << size(hp) << " N="<< N << endl;);
	if (empty(hp)) return nullptr;

	int temp = size(hp);
	if(N == 1){
		Node* p = hp;
		hp = hp->next;
		delete p;
	}else if(N > 1){
		if(N>=temp){
			for(int i = 0; i < temp ; i++){
				Node* p = hp;
				hp = hp->next;
				delete p;
			}
		}else{
			for(int i = 0; i < N ; i++){
				Node* p = hp;
				hp = hp->next;
				delete p;
			}
		}

	}


	DPRINT(cout << "<pop size=" << size(hp) << endl;);
	return hp;
}

// returns the first node in the list. This does not destroy the node.
pNode top(pNode hp) {
	DPRINT(cout << ">top size=" << size(hp) << endl;);
	if (empty(hp)) return nullptr;
	//cout <<  "Top: " << hp->item << endl;
	return hp;
}

// shows the values of all the nodes in the list if all is true or
// the list size is less than or equal to pmax * 2. If there are more than
// (pmax * 2) nodes, then it shows only pmax number of nodes from
// the beginning and the end in the list.
void show(pNode hp, bool all, int pmax) {
	DPRINT(cout << "show(" << size(hp) << ")\n";);
	if (empty(hp)) {
		cout << "\n\tThe list is empty.\n";
		return;
	}
	pNode x = hp;
	while(x != nullptr){
		cout << " -> " << x->item ;
		x = x->next;
	}


}
