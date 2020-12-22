#include <iostream>;
#include <vector>;
using namespace std;


typedef struct node{
    int data;
    struct node*next;
}lnode,*linklist;

typedef struct llnode{
    int data;
    int fre=1;
    struct llnode*next;
    struct llnode*pre;
}llnode,*llinklist;

int lenth_link(linklist l){
    linklist p;
    int k = 0;
    p = l->next;
    while(p){
        p=p->next;
        k++;
    }
    return k;
}



linklist list_delete_duplicate(linklist&l,int n){
    linklist p,q,r;
    int *a,m;
    a = (int*)malloc(sizeof(int)*(n+1));
    for(int i=0;i<n+1;i++){
        *(a+i) = 0;
    }
    p = l;
    while(p->next!=NULL){
        q = p->next;
        m = q->data;
        m = m>0?m:-m;
        if(*(a+m)==0){
            *(a+m)=1;
            p = q;
            q = q->next;
        }
        else{
            p->next = q->next;
            r = q;
            q = q->next;
            free(r);
        }
    }
    return l;

}


linklist list_find_common(linklist&a,linklist&b){
    int la,lb;
    linklist p = a,q =b;
    p = a,q = b;
    la = lenth_link(a);
    lb = lenth_link(b);
    if(la>lb){
        while(la>lb){
            p = p->next;
            la--;
        }
    }
    else if(lb>la){
        while(lb>la){
            q = q->next;
            lb--;
        }
    }
    while(p->next!=NULL&&p->next!=q->next){
        p = p->next;
        q = q->next;
    }
    return p->next;


}



llinklist tail_insert_ll(llnode*&l,int n){
    llnode*p,*q;
    p = l;
    int x;
    while(n>0) {
        scanf("%d", &x);
        q = (llnode *) malloc(sizeof(llnode));
        q->data = x;
        p->next = q;
        q->pre = p;
        p = q;
        n--;
    }
    q->next = NULL;
    l->pre = NULL;
    return l;

}

bool llist_eqal(llinklist&l){
    if(l==NULL){
        return false;
    }
    llinklist p,q;
    p = l->next,q = l->pre;
    while(q->next!=p&&p!=q){
        if(p->data==q->data){
            p = p->next;
            q = q->pre;
        }
        else{
            return false;
        }
    }
    return true;
}


linklist list_huan(linklist&l){
    linklist fast,slow;
    fast = slow = l;
    while(fast->next!=NULL&&slow!=NULL){
        if (fast==slow){
            break;
        }
        fast = fast->next->next;
        slow = slow->next;
    }
    if(fast->next==NULL||slow==NULL){
        return NULL;
    }
    fast = l;
    while(fast!=slow){
        fast = fast->next;
        slow = slow->next;
    }
    return fast;

}





llinklist locate(llinklist&l,int k){
    llinklist p,q;
    p = l->next;
    while(p&&p->data!=k){
        p = p->next;
    }
    if(p->data!=k){
        cout<<"no node value is k"<<endl;
        exit(0);
    }
    else{
        p->fre++;
        q = p->pre;
        if (p->next!=NULL) p->next->pre = p->pre;
        p->pre->next = p->next;
        while(q!=l&&q->fre<=p->fre){
            q = q->pre;
        }
        p->next = q->next;
        q->next->pre = p;
        q->next = p;
        p->pre = q;
        return l;



    }
}



linklist head_insert(lnode*&l){
    lnode*s; int x;
    l->next = l;
    scanf("%s",&x);
    while (x!='`'){
        s = (lnode*)malloc(sizeof(node));
        s->data = x;
        s->next = l->next;
        l->next = s;
        scanf("%d",&x);
    }
    return l;

}

linklist link(linklist &h1,linklist &h2){
    linklist p,q;
    p=h1,q = h2;
    while(p->next!=h1){
        p = p->next;
    }
    while(q->next!=h2){
        q = q->next;
    }
    p->next = h2;
    q->next = h1;
    return h1;

}

void del_all_xunhuan(linklist &l)
{
    linklist p,pre,minp,minpre;
    pre = l,p = l->next;
    while(l->next!=l){
        pre = l,p = l->next;
        minp=p,minpre = pre;
        while(p!=l){
            if(p->data<minp->data){
                minp = p;
                minpre = pre;
            }
            pre = p;
            p = p->next;
        }
        cout<<minp->data<<" ";
        minpre->next = minp->next;
        free(minp);
    }
    free(l);

}

linklist tail_insert(lnode*l,int n){
    lnode*q;lnode*p; int x;
    q = l;
    //scanf("%s",&x);
    while(n>0){
        n--;
        scanf("%d",&x);
        p = (lnode*)malloc(sizeof(lnode));
        p->data = x;
        q->next = p;
        q = q->next;
    }
    q->next = NULL;
    return l ;
}

bool list_last_k(linklist&l,int k){
    linklist p,q;
    p = q = l->next;
    int i=0;
    while (p!=NULL){
        if(i<k){
            i++;
        }
        else{
            q = q->next;
        }
        p=p->next;
    }
    if (i<k){
        return 0 ;
    }
    else{
        printf("the last k number is %d",q->data);
        cout<<endl;
        return 1;
    }
}


lnode* search_by_num(linklist l,int i){
    if (i<0){
        return NULL;
    }
    int j = 0;
    linklist p=l;
    while(p&&j<i){
        j++;
        p = p->next;
    }
    return p;
}

lnode* search_by_elem(lnode*l,int k){
    linklist p=l->next;
    while(p&&p->data!=k){
        p = p->next;
    }
    return p;
}


bool delete_by_num(lnode*&l,int k){
    lnode*p,*q;
    p = search_by_num(l,k-1);
    if (p!=NULL){
        q =p->next;
        p->next = q->next;
        free(q);
        return true;
    }
    return false;

}
void del_by_num_1(linklist &l,int k){
    if (l==NULL){
        return ;
    }
    if (l->data==k){
        linklist p;
        p = l;
        l =l->next;
        free(p);
        del_by_num_1(l,k);
    }
    else {
        del_by_num_1(l->next, k);
    }
}

void del_by_num_2(linklist l,int k){
    linklist p,q,t;
    p=l;
    q = p->next;
    while (q!=NULL){
        if(q->data==k){
            t = q;
            p->next = q->next;
            q = q->next;
            free(t);
        }
        else{
        p = p->next;q = q->next;}
    }
}



bool insert_by_num(lnode*&l,int k,int insert){
    linklist p,s;
    p =search_by_num(l,k);
    s = (lnode*)malloc(sizeof(node));
    s->data = insert;
    if (p!=NULL){
        s->next = p->next;
        p->next = s;
        s->data =p->data;
        p->data = insert;
    }
    return false;
}


linklist inverse_node(linklist&l){
    linklist head;
    if(l==NULL||l->next==NULL){
        return l;
    }
    linklist p;
    p = inverse_node(l->next);
    linklist t = l->next;
    t->next = l;
    l->next = NULL;

    return p;
}


linklist print_reverse_node(linklist l){
    if(l==NULL){
        return l;
    }
    if(l->next!=NULL){
        print_reverse_node(l->next);
    }
    if (l!=NULL){
        cout<<l->data<<" ";
    }

}

linklist del_min_node(linklist&l){
    linklist p,q,min_p,min_q,t;
    int min_data;
    if(l==NULL){
        return l;
    }
    min_p=p = l->next;min_q = q = l;
    min_data = p->data;
    while(p){
        if(p->data<min_data){
            min_q = q;
            min_p = p;
            min_data = p->data;
        }
        q = p;p=p->next;
    }
    t = min_p;
    min_q->next = min_p->next;
    free(t);
    return l;


}

//头插法对带有头节点的链表进行反转
linklist reverse_by_node_1(linklist &l){
    linklist p,q;
    if (l==NULL||l->next==NULL){
        return l;
    }
    p = l->next;q = p->next;
    l->next = NULL;
    while(p){
        q = p->next;
        p->next = l->next;
        l->next = p;
        p = q;
    }
    return l;
}

//设置三个指针对带有头节点的链表进行反转

linklist reverse_by_node_2(linklist&l){
    if(l==NULL||l->next ==NULL){
        return NULL;
    }
    linklist p,q,r;
    p = l->next;q = p->next;
    p->next = NULL;
    while(q){
        r = q->next;
        q->next = p;
        p = q;
        q = r;

    }
    l->next = p;
    return l;
}

void list_change(linklist&l){
    linklist p,q,r,s;
    p = q = l;
    while (p->next!=NULL){
        p = p->next;
        q = q->next;
        if (p->next!=NULL){
            p = p->next;
        }
    }
    //逆置lianbiao
    p = q->next;
    r = p->next;
    q->next = NULL;
    p->next = NULL;
    while(r!=NULL){
        s = r->next;
        r->next = p;
        p = r;
        r = s;
    }
    r = l->next;
    while(p){
        s = p->next;
        p->next = r->next;
        r->next = p;
        r= p->next;
        p = s;
    }
    return ;
}



void sort(linklist&l){
    linklist p,q,head;
    if(l==NULL||l->next==NULL){
        return ;
    }
    p = l->next,q = p->next;
    p->next = NULL;
    p = q;
    while(p){
        head = l;
        q = p->next;
        while(head->next&&head->next->data<p->data){
            head = head->next;
        }
        p->next = head->next;
        head->next =p;
        p = q;
    }
}


void del_s_t(linklist&l,int s,int t){
    if (l==NULL){
        return ;
    }
    linklist p,q,d_q;
    p = l,q = l->next;
    while(q) {
        if (q && (q->data > s && q->data < t)) {
            p->next = q->next;
            q = q->next;
            d_q = q;
            free(d_q);
        } else {
            p = q;
            q = q->next;
        }
    }
}


linklist common_list(linklist l1,linklist l2){
    int ll1,ll2,diff;
    ll1 = lenth_link(l1);
    ll2 = lenth_link(l2);
    l1 = l1->next,l2 = l2->next;
    if (ll1>ll2){
        diff = ll1-ll2;
        while (diff--){
            l1 = l1->next;
        }
    }
    else if(ll2>ll1){
        diff = ll2-ll1;
        while(diff--){
            l2 = l2->next;
        }
    }
    while(l1)
    {
        if(l1==l2){
            return l1;
        }
        else{
            l1 = l1->next;
            l2 = l2->next;
        }
    }
    return NULL;
}

void print_by_sort(linklist&l){
    if(l==NULL){
        return ;
    }
    linklist p=l,q=l->next,small_p,small_q;
    int small_num;
    while(l->next){
        p = l,q = l->next;
        small_p=p,small_q = q;
        small_num=q->data;
        while(q){
            if (q->data<small_num){
                small_p = p,small_q=q;
                small_num = q->data;
            }
            p=q;
            q = q->next;
        }
        cout<<small_num<<" ";
        small_p->next = small_q->next;
        free(small_q);
    }
}
linklist discre(linklist&a){
    linklist b;
    lnode *aa,*bb,*p;
    int i = 0;
    b = (linklist)malloc(sizeof(lnode));
    aa = a,bb=b,p = aa->next;
    aa->next = NULL;
    while(p){
        i++;
        if (i%2==1){
            aa->next = p;
            aa = aa->next;
        }
        else if(i%2==0){
            bb->next = p;
            bb = bb->next;
        }
        p = p->next;
    }
    aa->next = NULL;
    bb->next = NULL;
    return b;
}

linklist discre_2(linklist&a){
    if(a==NULL){
        return NULL;
    }
    lnode*aa,*q,*p;
    linklist b = (linklist)malloc(sizeof(lnode));
    aa = a,b->next =NULL;
    p = a->next;
    a->next = NULL;
    while (p){
        aa->next = p;
        aa = p;
        p = p->next;
        if(p){
            q = p->next;
            p->next = b->next;
            b->next = p;
            p = q;
        }
    }
    aa->next = NULL;
    return b;

}

void del_duplicate(linklist&l){
    if(l==NULL||l->next==NULL){
        return ;
    }
    linklist p,q,t;
    p = l->next;
    while(p->next!=NULL){
        q = p->next;
        if(q->data==p->data){
            p->next = q->next;
            free(q);
        }
        else{
            p = p->next;
        }
    }

}

linklist merge(linklist&a,linklist&b){
    linklist p,q,r,aa;
    aa = a;
    q = b->next;
    p = a->next;
    a->next = NULL;
    while (p&&q){
        if(p->data<=q->data){
            r = p->next;
            p->next = a->next;
            a->next = p;
            p = r;
        }
        else if(q->data<p->data){
            r = q->next;
            q->next = a->next;
            a->next = q;
            q = r;
        }
    }
    if(p){
        q = p;
    }
    while(q){
        r = q->next;
        q->next = a->next;
        a->next = q;
        q = r;
    }
    free(b);
    return a;
}


linklist list_union(linklist&a,linklist&b){
    if(a->next==NULL||b->next==NULL){
        return NULL;
    }
    lnode*p,*aa,*bb,*head;
    aa = a->next,bb = b->next,head = a;
    while(aa&&bb){
        if(aa->data==bb->data){
            p =bb;
            head->next = aa;
            head = aa;
            bb = bb->next;
            aa = aa->next;
            free(p);
        }
        else if(aa->data<bb->data){
            p = aa;
            aa = aa->next;
            free(p);
        }
        else if(aa->data>bb->data){
            p = bb;
            bb = bb->next;
            free(p);
        }}
        while(aa){
            p = aa;
            aa = aa->next;
            free(aa);
        }
        while(bb){
            p = bb;
            bb = bb->next;
            free(bb);
        }
        free(b);
        head->next = NULL;
        return a;

}

bool list_involve(linklist&a,linklist&b){
    if(a==NULL||b==NULL){
        return false;
    }
    linklist head,aa,bb;
    head =aa=a->next,bb=b->next;
    while(aa&&bb){
        if(aa->data==bb->data){
            aa = aa->next;
            bb = bb->next;
        }
        else{
            head = head->next;
            aa = head;
            bb = b->next;
        }
    }
    if (bb==NULL){
        return true;
    }
    else{
    return false;}

}


linklist get_common(linklist&a,linklist&b){
    if(a->next==NULL||b->next==NULL){
        return NULL;
    }
    linklist c = (linklist)malloc(sizeof(lnode));
    lnode*cc=c;
    linklist p,q;
    p = a->next;
    q = b->next;
    while (p&&q){
        if (p->data<q->data){
            p = p->next;
        }
        else if(q->data<p->data){
            q = q->next;
        }
        else{
            linklist s = (linklist)malloc(sizeof(lnode));
            s->data = p->data;
            cc->next = s;
            cc = cc->next;
            p=p->next;
            q = q->next;
        }
    }

        cc->next = NULL;
        return c;

}

//当循环链表或非循环链表时修改循环条件
void print_node(linklist l){
    lnode*next_node;
    next_node = l->next;
    while (next_node!=NULL){
        cout<<next_node->data<<" ";
        next_node = next_node->next;
    }
    cout<<endl;
}


//Definition for singly-linked list.
  struct ListNode {
      int val;
      ListNode *next;
      ListNode(int x) : val(x), next(NULL) {}
  };

class Solution {
public:
    ListNode* reverseBetween(ListNode* head, int m, int n) {
        ListNode*pre,*p,*temp_head,*temp_tail,*q,*r;
        pre = p = head;
        while(m>1){
            pre = pre->next;
            p = p->next;
            m--;
            n--;
        }
        temp_head = pre;
        temp_tail = p;
        while(n>0){
            q = p->next;
            p->next = pre;
            pre = p;
            p = q;
            n--;
        }




    }
};

//int main(){
////    int k;
////    llinklist s;
////    llinklist p = (llnode*)malloc(sizeof(llnode));
////    tail_insert_ll(p,5);
////    print_node(p);
////    //cout<<llist_eqal(p)<<endl;
////    while(true){
////        scanf("%d",&k);
////        s = locate(p,k);
////        print_node(p);
////    }
//    linklist l,l2;
//    linklist temp;
//    l = (linklist)malloc(sizeof(lnode));
//    l2 = (linklist)malloc(sizeof(lnode));
//    tail_insert(l,5);
//    //tail_insert(l2,3);
//    print_node(l);
//    //list_delete_duplicate(l,20);
//    list_change(l);
//    print_node(l);
////    temp = l2->next;
////    temp->next->next->next = l->next;
////    print_node(l);
////    print_node(l2);
////    linklist c = list_find_common(l,l2);
////    print_node(c);
//    //cout<<list_last_k(l,2)<<endl;
////    head_insert(l);
////    head_insert(l2);
////    print_node(l);
////    print_node(l2);
////    link(l,l2);
////    print_node(l);
////    del_all_xunhuan(l);
//
////    tail_insert(l);
////    l2 = (linklist)malloc(sizeof(lnode));
////    tail_insert(l2);
//    //print_node(l);
////    delete_by_num(l,2);
////    print_node(l);
////    insert_by_num(l,1,8);
//    //print_node(l);
//    //del_by_num_1(l,2);
//    //print_node(l);
////    print_reverse_node(l);
////    cout<<endl;
//    //l = del_min_node(l);
//    //print_node(l);
////    l = reverse_by_node_2(l);
//    //print_node(l);
//    //print_by_sort(l);
////    linklist b = discre_2(l);
//    //del_duplicate(l);
////    print_node(b);
////    print_node(l);
////    print_node(l2);
////    cout<<list_involve(l,l2)<<endl;
//    //linklist c = get_common(l,l2);
//    //linklist d = list_union(l,l2);
//    //print_node(c);
//    //print_node(d);
////    l = merge(l,l2);
////    print_node(l);
//    //sort(l);
//    //del_s_t(l,3,5);
////    linklist l2 = (lnode*)malloc(sizeof(lnode));
////    linklist pp = (lnode*)malloc(sizeof(lnode));
////    pp->data = 90;
////    pp->next = l->next;
////    l2->next = pp;
////    linklist t = common_list(l,l2);
////    print_node(t);
//
////    linklist p = inverse_node(l);
////    print_node(p);
////    cout<<lenth_link(l)<<endl;
////    temp = search_by_num(l,2);
////    if (temp){cout<<temp->data<<endl;}
//}