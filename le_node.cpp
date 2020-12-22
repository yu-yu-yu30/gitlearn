#include <iostream>
#include <vector>
#include <map>
#include <string>
using namespace std;
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

ListNode* node_list(int n){
    int x;
    ListNode*s,*p,*head;
    int start;
    start = 0;
    while(n>0){
        scanf("%d",&x);
        s = (ListNode*)malloc(sizeof(ListNode));
        s->val = x;
        if (start==0){
            p =head = s;
            start = 1;
        }
        else{
        p->next = s;
        p = s;}
        n--;
    }
    p->next = NULL;
return head;
}


class KInverse {
public:
    ListNode* inverse(ListNode* head, int k) {
        // write code here
        int num = 0;int xnum;
        ListNode*p = head;
        ListNode*q,*r;
        while(p){
            p = p->next;
            num++;
        }
        xnum = num-num%k;
        ListNode*pnode = new ListNode(0);
        ListNode*temp_head = pnode;
        p = head;q = p->next;
        num = 0;
        for(num=0;num<xnum;num++){
            q = p->next;
            p->next = pnode->next;
            pnode->next = p;
            p = q;
            if ((num+1)%k==0){
                int j = k;
                while(j>0){
                    pnode = pnode->next;
                    j--;
                }
            }
        }
        pnode->next = p;
        return temp_head->next;
    }
};

//class KInverse {
//public:
//    ListNode* inverse(ListNode* head, int k) {
//        ListNode*p = head;ListNode*r;
//        int num = 0;
//        while(p&&num<k){
//            p = p->next;
//            num++;
//        }
//        if (num<k){
//            return head;
//        }
//        p = head;
//        ListNode*q = NULL;
//        while(num>0){
//            r = p->next;
//            p->next = q;
//            q = p;
//            p = r;
//            num--;
//        }
//        head->next = inverse(r,k);
//        return q;
//
//    }
//};

//class Solution {
//public:
//    ListNode* reverseBetween(ListNode* head, int m, int n) {
//        ListNode*pre,*p,*temp_head,*temp_tail,*q,*r;
//        pre  = NULL;
//        p = head;
//        while(m>1){
//            pre = p;
//            p = p->next;
//            m--;
//            n--;
//        }
//        temp_head = pre;
//        temp_tail = p;
//
//        while(n>0){
//            q = p->next;
//            p->next = pre;
//            pre = p;
//            p = q;
//            n--;
//        }
//        if(temp_head==NULL){
//            head = pre;
//        }
//        else{
//            temp_head->next = pre;
//        }
//        temp_tail->next = p;
//        return head;
//    }
//
//
//
//class KInverse {
//private:
//    ListNode*cur;
//    ListNode*temp;
//public:
//    ListNode* inverse(ListNode* head, int k) {
//        cur = head;
//        int num = 0;
//        while (num<k&&cur){
//            cur = cur->next;
//            num++;
//        }
//        if (num==k){
//            temp = inverse(cur,k);
//            while(num>0){
//                cur = head->next;
//                head->next = temp;
//                temp = head;
//                num--;
//                if (num>0){
//                    head = cur;
//                }
//            }
//
//        }
//        return head;
//
//    }
//};
//







//class KInverse {
//public:
//    ListNode* inverse(ListNode* head, int k) {
//        // write code here
//        if(head==NULL||k<2)
//            return head;
//        ListNode* p=head;
//        int count=0;
//        while(p!=NULL)
//        {
//            count++;
//            p=p->next;
//        }
//        ListNode* root=new ListNode(0);
//        p = root;
//        int cnt = (count % k) ? (count-(count%k)-1) : (count-1);
//        for(int i=0;i<=cnt;i++){
//            ListNode *node = new ListNode(head->val);
//            node->next = p->next;
//            p->next = node;
//            if ((i+1)%k==0) {
//                int j = k;
//                while (j--) {
//                    p = p->next;
//                }
//            }
//            ListNode *tmp = head;
//            head = head->next;
//            delete tmp;
//        }
//        p->next = head;
//        return root->next;
//
//    }
//};

//m,n之间的链表反转
//class Solution {
//
//private:
//    ListNode*left,*right;
//    int flag = 0;
//    int temp;
//public:
//    void recurverse(int m,int n){
//        if(n==1){
//            return ;
//        }
//        if(m>1){
//            left = left->next;
//        }
//        right = right->next;
//        recurverse(m-1,n-1);
//
//        if (left==right or right->next == left){
//            flag = 1;
//            return ;
//        }
//        if (flag==0){
//        temp = left->val;
//        left->val = right->val;
//        right->val = temp;
//        left = left->next;
//        }
//
//    }
//
//    ListNode* reverseBetween(ListNode* head, int m, int n) {
//        left = head;right = head;
//        recurverse(m,n);
//        return head;
//    }
//
//
//    void print_node(ListNode* l){
//        ListNode*next_node;
//        next_node = l;
//        while (next_node!=NULL){
//            cout<<next_node->val<<" ";
//            next_node = next_node->next;
//        }
//        cout<<endl;
//    }
//
//};

//复杂链表的定义
class Node{
public:
    int val;
    Node*next;
    Node*random;

    Node(int _val){
        val = _val;
        next = NULL;
        random = NULL;
    }
};




//复杂链表的复制问题
//unordered_map
class Solution {
public:
    Node* copyRandomList(Node* head) {

        map<Node*,Node*> nmap;
        Node*t = head;
        while(t){
            nmap[t] = new Node(t->val);
            t = t->next;
        }
        t = head;
        while(t){
            if (t->next) {
                nmap[t]->next =nmap[t->next];
            }
            if(t->random){
                nmap[t]->random = nmap[t->random];
            }
        t = t->next;
        }
        return nmap[head];
    }

};



//class Solution {
//public:
//    Node*clone_next(Node*head){
//        Node*p = head;
//        while (p){
//            Node*s = (Node*)malloc(sizeof(Node));
//            s->val = p->val;
//            s->next = p->next;
//            p->next = s;
//            p = s->next;
//        }
//        return head;
//    }
//
//    Node* clone_random(Node* head) {
//        Node*p = head;
//        Node*q;
//        while(p) {
//            q = p->next;
//            q->random = p->random?p->random->next : NULL;
//            p = q->next;
//        }
//        return head;
//    }
//    Node* clone_final(Node* head){
//        if (head==NULL){
//            return head;
//        }
//        Node*p,*q,*chead;
//
//        p = head;
//        chead = q= p->next;
//        p->next = q?q->next:NULL;
//        p = q?q->next:NULL;
//
//        while(p){
//            q->next = p->next;
//            q = q->next;
//            p->next = q?q->next:NULL;
//            p = q->next;
//
//        }
//        return chead;
//
//    }
//    Node* copyRandomList(Node *head){
//        head = clone_next(head);
//        head = clone_random(head);
//        head = clone_final(head);
//        return head;
//
//
//    }
//    void print_node(ListNode* l){
//        ListNode*next_node;
//        next_node = l;
//        while (next_node!=NULL){
//            cout<<next_node->val<<" ";
//            next_node = next_node->next;
//        }
//        cout<<endl;
//    }
//};
//


//int main(){
//    ListNode*head;
//    Solution a;
//
//    head = node_list(6);
//
//
//    //a.print_node(head);
//
//    //Solution a;
//    //KInverse b;
//    //head = b.inverse(head,3);
//    //a.print_node(head);
//    //a.reverseBetween(head,2,4);
//    //a.print_node(head);
//
//    return 0;
//}