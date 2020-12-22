#include <iostream>
#include <vector>
#include <stack>
#include <queue>
using namespace std;
typedef int element_type;

typedef struct treenode{
    element_type data;
    treenode*left;
    treenode*right;
    treenode():data(0),left(NULL),right(NULL){};
}treenode;

typedef struct tree_stack{
    treenode*node;
    int tag;
    tree_stack():node(NULL),tag(0){};
}treestack;

typedef struct tree_node{
    element_type data;
    tree_node*left;
    tree_node*right;
    int left_info;
    int right_info;
    tree_node():data(0),left(NULL),right(NULL),left_info(0),right_info(0){};
}tree_node;


void create_pre_tree(treenode*&x){
    element_type ch;
    cout<<"输入数字建树"<<endl;
    x = (treenode*)malloc(sizeof(treenode));
    cin>>ch;
    if(ch!=9999){
        x->data = ch;
        create_pre_tree(x->left);
        create_pre_tree(x->right);
    }
    else{
    x = NULL;}
}

treenode*add_node_info(element_type val){
    treenode*p = (treenode*)malloc(sizeof(treenode));
    p->data = val;
    p->left = NULL;
    p->right = NULL;
    return p;
}

treenode*find_node(treenode*node,element_type val){
    if(node==NULL){
        return NULL;
    }
    if(node->data==val){
        return node;
    }
    else{
        if(find_node(node->left,val)!=NULL){
            return find_node(node->left,val);
        }
        if(find_node(node->right,val)!=NULL)
            return find_node(node->right,val);
    }
    return NULL;

}


void insert_tree_ndupli(treenode*&node,element_type val,element_type node_val,int chos){
    treenode*ap = add_node_info(val);
    treenode*p;
    if(node==NULL){
        node = ap;
    }
    else{
        p = find_node(node,node_val);
        if(p==NULL){
            cout<<"找不到对应的根"<<endl;
            return ;
        }
        else{
            //p = find_node(node,node_val);
            if(p->left==NULL&&chos==0){
                p->left = ap;
            }
            else if(p->right==NULL&&chos==1){
                p->right=ap;
            }
            else{
                cout<<"根下的节点存在或非左右输入"<<endl;
                return ;
            }
        }

    }

}

void create_nodup_tree(treenode*&node){
    element_type val,node_val;int type_chos;
    val = 0;
    while(val!=9999){
        cout<<"输入根节点的值"<<endl;
        cin>> node_val;
        cout<<"输入节点的值"<<endl;
        cin>>val;
        cout<<"输入左右节点的值"<<endl;
        cin>>type_chos;
        insert_tree_ndupli(node,val,node_val,type_chos);
    }

}

tree_node* create_temp_tree_(){
    tree_node*p;
    tree_node*node = new tree_node;
    node->data = 1;
    node->left = new tree_node;
    node->right = new tree_node;
    node->right->data=3;
    p = node->left;
    p->data = 2;
    p->left = new tree_node;
    p = p->left;
    p->data = 4;
    p->left =new tree_node;
    p->left->data = 10;
    p->right =new tree_node;
    p =p->right;
    p->data = 8;
    p = node->right;
    p->right = new tree_node;
    p = p->right;
    p->data = 7;
    p->left = new tree_node;
    p->left->data = 9;
    return node;
}

treenode* create_temp_tree(){
    treenode*p;
    treenode*node = new treenode;
    node->data = 1;
    node->left = new treenode;
    node->right = new treenode;
    node->right->data=3;
    p = node->left;
    p->data = 2;
    p->left = new treenode;
    p = p->left;
    p->data = 4;
//    p->left =new treenode;
//    p->left->data = 10;
    p->right =new treenode;
    p =p->right;
    p->data = 8;
    p->right = new treenode;
    p->right->data = 10;
    p = node->right;
    p->right = new treenode;
    p = p->right;
    p->data = 7;
    p->left = new treenode;
    p->left->data = 9;
//    p->right = new treenode;
//    p->right->data = 13;
//    p->left->left = new treenode;
//    p->left->left->data = 11;
    return node;
}

void pre_out(treenode*node,vector<element_type>& record){
    if(node!=NULL){
        record.push_back(node->data);
        pre_out(node->left, record);
        pre_out(node->right,record);
    }
}

void in_out(treenode*node,vector<element_type>&record){
    if(node==NULL){
        return ;
    }
    in_out(node->left,record);
    record.push_back(node->data);
    in_out(node->right,record);
}

void post_out(treenode*node,vector<element_type>&record){
    if(node==NULL){
        return ;
    }
    post_out(node->left,record);
    post_out(node->right,record);
    record.push_back(node->data);
}


void print_vector(vector<element_type>x){
    for(int i = 0;i<x.size();i++){
        cout<<x[i]<<',';
    }
    cout<<endl;
}

void pre_travel(treenode*node,vector<element_type>&record){
    treenode*p = node;
    stack<treenode*>temp_tree_stack;
    while(p||!temp_tree_stack.empty()){
        if(p){
            record.push_back(p->data);
            temp_tree_stack.push(p);
            p = p->left;
        }
        else{
            p = temp_tree_stack.top();
            temp_tree_stack.pop();
            if (p->right) p=p->right;
            else p = NULL;
        }
    }


}


void in_travel(treenode*node,vector<element_type>&record){
    treenode*p;
    p = node;
    stack<treenode*> temp_tree_stack;
    while(p||!temp_tree_stack.empty()){
        if(p){
            temp_tree_stack.push(p);
            p = p->left;
        }
        else{
            p = temp_tree_stack.top();
            temp_tree_stack.pop();
            record.push_back(p->data);
            p = p->right;
        }
    }


}

void post_travel(treenode*node,vector<element_type>&record){
    treenode*p,*t;
    p = node;
    stack<treenode*>temp_tree_stack;
    while(p||!temp_tree_stack.empty()){
        if(p){
            temp_tree_stack.push(p);
            p = p->left;
        }
        else{
            p = temp_tree_stack.top();
            //temp_tree_stack.pop();
            if(p->right&&p->right!=t){
                p = p->right;
            }
            else{
                record.push_back(p->data);
                t = p;
                temp_tree_stack.pop();
                p = NULL;
            }
        }

    }
}


void pre_travell_visit(treenode*node,vector<element_type>&record) {
    treenode *p;
    stack<treenode*>temp_tree_stack;
    temp_tree_stack.push(node);
    while(!temp_tree_stack.empty()){
        p = temp_tree_stack.top();
        temp_tree_stack.pop();
        if(p){
        record.push_back(p->data);
        if(p->right) temp_tree_stack.push(p->right);
        if(p->left) temp_tree_stack.push(p->left);
        }
    }
}

void in_travell_visit(treenode*node,vector<element_type>&record) {
    treenode *p;
    stack<treenode*>temp_tree_stack;
    temp_tree_stack.push(node);
    while(!temp_tree_stack.empty()){
        p = temp_tree_stack.top();
        temp_tree_stack.pop();
        if(p){
            if(p->right) temp_tree_stack.push(p->right);
            temp_tree_stack.push(p);
            temp_tree_stack.push(NULL);
            if(p->left) temp_tree_stack.push(p->left);
        }
        else{
            p=temp_tree_stack.top();
            temp_tree_stack.pop();
            record.push_back(p->data);
            //p = NULL;
        }
    }

}


void post_travell_visit(treenode*node,vector<element_type>&record) {
    stack<treenode*>temp_tree_stack;
    treenode*p;
    temp_tree_stack.push(node);
    while(!temp_tree_stack.empty()){
        p = temp_tree_stack.top();
        temp_tree_stack.pop();
        if(p){
            temp_tree_stack.push(p);
            temp_tree_stack.push(NULL);
            if(p->right) temp_tree_stack.push(p->right);
            if(p->left) temp_tree_stack.push(p->left);
        }
        else{
            p = temp_tree_stack.top();
            temp_tree_stack.pop();
            record.push_back(p->data);
        }
    }
}

void level_travel(treenode*node,vector<element_type>&record){
    treenode *p;
    queue<treenode*>temp_tree_queue;
    temp_tree_queue.push(node);
    while(!temp_tree_queue.empty()){
        p = temp_tree_queue.front();
        temp_tree_queue.pop();
        record.push_back(p->data);
        if(p->left) temp_tree_queue.push(p->left);
        if(p->right) temp_tree_queue.push(p->right);
    }
}



//void test_length(int data_a[]){
//    //cout<<(data_a)
//    cout<<sizeof(data_a)<<endl;
//}
//void create_tree(treenode*&node,element_type data_a[]){
//    queue<treenode*>tree_temp;
//    treenode*p;
//    int i = 0;
//    int length_a = 4;
//    tree_temp.push(node);
//    while(!tree_temp.empty()){
//        p = tree_temp.front();
//        tree_temp.pop();
//        if(i<length_a&&data_a[i]!=-9999) {
//            //&p = (treenode*)malloc(sizeof(treenode));
//            //p = new treenode;
//            p->left = new treenode;
//            p->right = new treenode;
//            p->data = data_a[i];
//            tree_temp.push(p->left);
//            tree_temp.push(p->right);
//        }
//        else{
//            delete p;
//            p = NULL;
//        }
//        i++;
//    }
//}


void create_in_key_tree(tree_node*&node,tree_node*&pre){
    if(node==NULL){
        return ;
    }
    create_in_key_tree(node->left,pre);
    if(pre!=NULL&&pre->right==NULL){
        pre->right_info = 1;
        pre->right = node;
    }
    if(node->left==NULL){
        node->left_info = 1;
        node->left = pre;
    }
    pre = node;
    create_in_key_tree(node->right,pre);
}

void create_in_key(tree_node*node){
    tree_node *pre = NULL;
    create_in_key_tree(node,pre);
    pre->right = NULL;
    pre->right_info = 1;
}


void visit_in_key_tree(tree_node*&node,vector<element_type>&record){
    while(node!=NULL) {
        while ( node->left&&node->left_info == 0 ) {
            node = node->left;
        }

        record.push_back(node->data);
        while (node&&node->right_info == 1) {
            node = node->right;
            if (node != NULL) {
                record.push_back(node->data);
            }
        }
        if (node) node = node->right;
    }

}

void create_pre_key_tree(tree_node*&node,tree_node*&pre){
    if(node==NULL){
        return ;
    }
    if(pre!=NULL&&pre->right==NULL){
        pre->right_info = 1;
        pre->right = node;
    }
    if(node->left==NULL){
        node->left_info = 1;
        node->left = pre;
    }
    pre = node;
    if(node->left_info==0) create_pre_key_tree(node->left,pre);
    if(node->right_info==0)create_pre_key_tree(node->right,pre);
}

void create_pre_key(tree_node*node){
    tree_node *pre = NULL;
    create_pre_key_tree(node,pre);
    pre->right = NULL;
    pre->right_info = 1;
}

void visit_pre_key_tree(tree_node*&node,vector<element_type>&record) {
    while(node!=NULL){
    while(node&&node->left_info==0) {
        record.push_back(node->data);
        node = node->left;
    }
    record.push_back(node->data);
    node = node->right;
    while(node!=NULL){
        if(node->left!=NULL&&node->left_info==0){
            break;
        }
        else record.push_back(node->data); node = node->right;
    }
//    while(node!=NULL){
//        if(node->left_info==0&&node->left){
//            break;
//        }
//        record.push_back(node->data);
//        node = node->right;
//    }
    }
}


tree_node*inKey_post_front(tree_node*node){
    if(node->right_info==0){
        return node->right;
    }
    else if(node->left_info==0){
        return node->left;
    }
    else if(node->left==NULL){
        return NULL;
    }
    else{
        while(node->left&&node->left_info==1){
            node = node->left;
        }
        return node->left;
//        if(node->left!=NULL){
//            return node->left;
//        }
//        else{
//            return NULL;
//        }
    }

}


void invert_level(treenode*node,vector<element_type>&record){
    treenode*p;
    queue<treenode*>temp_tree_queue;
    stack<treenode*>temp_tree_stack;
    temp_tree_queue.push(node);
    while(!temp_tree_queue.empty()){
        p = temp_tree_queue.front();
        if(p->left) temp_tree_queue.push(p->left);
        if(p->right) temp_tree_queue.push(p->right);
        temp_tree_queue.pop();
        temp_tree_stack.push(p);
    }
    while(!temp_tree_stack.empty()){
        p = temp_tree_stack.top();
        record.push_back(p->data);
        temp_tree_stack.pop();
    }
}

int tree_height(treenode*node){
    if(node==NULL){
        return 0;
    }
    int l_height = tree_height(node->left);
    int r_height = tree_height(node->right);
    if(l_height>r_height){
        return l_height+1;
    }
    return r_height+1;
}


int tree_height_(treenode*node){
    if(node==NULL){
        return 0;
    }
    int level = 0;
    queue<treenode*> temp_tree_queue;
    temp_tree_queue.push(node);
    treenode*front = NULL;treenode*last = node;
    while(!temp_tree_queue.empty()){
        front = temp_tree_queue.front();
        temp_tree_queue.pop();
        if(front->left) temp_tree_queue.push(front->left);
        if(front->right) temp_tree_queue.push(front->right);
        if(front==last){
            level++;
            last=temp_tree_queue.back();
        }
    }
    return level;
}

treenode* pre_in_tree(vector<element_type>record_pre,vector<element_type>record_in,\
int pre_start,int pre_end,int in_start,int in_end)
        {
    treenode*root = new treenode;
    int i;
    root->data = record_pre[pre_start];
    for(i = in_start;i<=in_end;i++){
        if(record_in[i]==record_pre[pre_start]) break;
    }
    int right_len = in_end-i;
    int left_len =i-in_start;
    if(left_len>0){
        root->left = pre_in_tree(record_pre,record_in,pre_start+1,\
                pre_start+left_len,in_start,i-1);
    }
    else{
        root->left = NULL;
    }
    if(right_len>0){
        root->right = pre_in_tree(record_pre,record_in,pre_start+left_len+1,\
                pre_end,i+1,in_end);
    }
    else{
        root->right = NULL;
    }
    return root;
}



treenode* recreate_pre_in_tree(treenode*node){
    vector<element_type> record_pre;
    vector<element_type>record_in;
    pre_travell_visit(node,record_pre);
    in_travell_visit(node,record_in);
    element_type end_1 = record_pre.size()-1;element_type end_2 = record_in.size()-1;
    treenode*p =  pre_in_tree(record_pre,record_in,0,end_1,0,end_2);
    return p;
}


int complete_tree_wh(treenode*node){
    if(node==NULL){
        return 1;
    }
    treenode*p;
    queue<treenode*>temp_tree_queue;
    temp_tree_queue.push(node);
    while(!temp_tree_queue.empty()){
        p = temp_tree_queue.front();
        temp_tree_queue.pop();
        if(p){
            temp_tree_queue.push(p->left);
            temp_tree_queue.push(p->right);
        }
        else{
            p = temp_tree_queue.front();
            if(p){
                return 0;
            }
        }
    }
    return 1;

}



int num_of_two_node(treenode*node){
    if(node==NULL){
        return 0;
    }
    int ln = num_of_two_node(node->left);
    int rn = num_of_two_node(node->right);
    if(node->left!=NULL&&node->right!=NULL){
        return (ln+rn+1);
    }
    else{
        return ln+rn;
    }
}

void swap(treenode*&node){
    if(node==NULL){
        return;
    }
    else{
        swap(node->left);
        swap(node->right);
        treenode *temp = node->left;
        node->left = node->right;
        node->right = temp;
    }
}
class pre_k_cal{
private:
    int pre_cal = 0;
public:
    element_type pre_k(treenode*node,int k) {
        if (node == NULL) {
            return '*';
        }
        pre_cal++;
        if (pre_cal == k) {
            return node->data;
        }
        int ch = pre_k(node->left, k);
        if (ch != '*') {
            return ch;
        } else {
            ch = pre_k(node->right, k);
        }
        return ch;
    }


};

void delete_node(treenode*node){
    if(node!=NULL){
        delete_node(node->left);
        delete_node(node->right);
        free(node);
    }
}

void delete_search(treenode*&node,element_type x){
    if(node==NULL){
        return ;
    }
    queue<treenode*> temp_tree_queue;
    treenode*p;
    if(node->data==x){
        delete_node(node);
        exit(0);
    }
    temp_tree_queue.push(node);
    while(!temp_tree_queue.empty()){
        p = temp_tree_queue.front();
        temp_tree_queue.pop();
        if(p->left&&p->left->data==x){
            delete_node(p->left);
            p->left = NULL;
        }
        else if(p->left){
            temp_tree_queue.push(p->left);
        }
        if(p->right&&p->right->data==x){
            delete_node(p->right);
            p->right=NULL;
        }
        else if(p->right){
            temp_tree_queue.push(p->right);
        }
    }
}



void post_travel_tree_stack(treenode*&root,vector<element_type>&record,int x){
    tree_stack s[100];
    treenode*p = root;
    int top = -1 ;
    while(p!=NULL||top>=0) {
        while (p != NULL&&p->data!=x) {
            s[++top].node = p;
            s[top].tag = 0;
            p = p->left;
        }
        if (p&&p->data == x){
            for (int i = top; i >= 0; i--) {
                record.push_back(s[top].node->data);
                return;
            }
    }
        while((top>=0)&&s[top].tag==1){
            top--;
            //record.push_back(s[top--].node->data);
        }
        if(s[top].tag==0){
            s[top].tag=1;
            p = s[top].node->right;
        }
    }

}

treenode*acestor(treenode*p,treenode*q,treenode*root){
    tree_stack s[100];
    tree_stack s_stemp[100];
    treenode*rec;
    rec = root;
    int top = -1;
    int top1 = -1;
    rec = root;
    int flag=0;
    while(rec!=NULL||top>=0){
        //while(rec!=NULL&&rec!=p&&rec!=q)
        {
            while(rec!=NULL){
            s[++top].node = rec;
            s[top].tag = 0;
            rec =rec->left;}

        while(top>=0&&s[top].tag==1){
            if((s[top].node==p||s[top].node==q)&&flag==0){
                for(int i = top;i>=0;i--){
                    s_stemp[i] = s[i];
                }
                top1 = top;
                flag =1;

            }
             else if((s[top].node==q||s[top].node==p)&&flag==1){
                for(int i = top1;i>=0;i--){
                    for(int j = top;j>=0;j--){
                        if(s[j].node==s_stemp[i].node){
                            return s[i].node;
                        }
                    }
                }
            }
            top--;
        }
        if(top>=0){
            s[top].tag = 1;
            rec = s[top].node->right;
        }
    }
    }
}


int width_tree(treenode*node){
    if(node==NULL){
        return 0;
    }
    int level = 0;
    int max_level;
    treenode*p;treenode*q;
    q = node;
    queue<treenode*>temp_tree_queue;
    temp_tree_queue.push(node);
    while(!temp_tree_queue.empty()){
        p = temp_tree_queue.front();
        temp_tree_queue.pop();
        level++;
        if(p->left!=NULL){
            temp_tree_queue.push(p->left);
        }
        if(p->right!=NULL){
            temp_tree_queue.push(p->right);
        }
        if(p==q){
            max_level = max(level,max_level);
            q = temp_tree_queue.back();
            level = 0;
        }
    }
    return max_level;

}


struct tree_level{
    treenode* data[100];
    int level[100];
    int front=-1;
    int rear=-1;
};

int tree_width_version_2(treenode*node){
    if(node==NULL){
        return 0;
    }
    tree_level s;
    int l = 0;
    treenode*p;
    s.front =-1;s.rear = 0;
    s.data[s.rear]=node;
    s.level[s.rear] = 1;
    while(s.front<s.rear){
        s.front++;
        p = s.data[s.front];
        l = s.level[s.front];
        if(p->left!=NULL){
            s.data[++s.rear] = p->left;
            s.level[s.rear] = l+1;
        }
        if(p->right!=NULL){
            s.data[++s.rear] = p->right;
            s.level[s.rear] = l+1;
        }
    }
    int n = 0;int max_level = 0;int level_count = 0;
    int  k = s.level[n];
    while(n<=s.rear) {
        level_count = 0;
        k = s.level[n];
        while (n<=s.rear&&k==s.level[n]) {
            if (s.level[n] == k) {
                n++;
                level_count++;
            }
        }
        if(level_count>max_level){
            max_level = level_count;
        }
    }
    return max_level;
}


typedef struct linklist{
    element_type data;
    linklist*right;
} linklist;

//linklist*head,*pre=NULL;
//linklist* in_leaf_tree(treenode*node) {
//    if (node) {
//        in_leaf_tree(node->left);
//        if (node->left == NULL && node->right == NULL) {
//            if (pre == NULL) {
//                head = new linklist;
//                head->data  = node->data;
//                pre = head;
//            } else {
//                pre->right = new linklist;
//                pre->right->data = node->data;
//                pre = pre->right;
//            }
//        }
//        in_leaf_tree(node->right);
//        pre->right = NULL;
//    }
//    return head;
//}

linklist*head,*pre=NULL;
linklist* in_leaf_tree(treenode*node) {
    queue<treenode*>temp_tree_queue;
    treenode*p;
    temp_tree_queue.push(node);
    while(!temp_tree_queue.empty()){
        p = temp_tree_queue.front();
        temp_tree_queue.pop();
        if(p->left==NULL&&p->right==NULL){
            if(pre==NULL){
                head = new linklist;
                head->data = p->data;
                pre = head;
            }
            else{
                pre->right = new linklist;
                pre->right->data = p->data;
                pre = pre->right;
            }
        }
        if(p->left)temp_tree_queue.push(p->left);
        if(p->right)temp_tree_queue.push(p->right);
    }
    pre->right = NULL;
    return head;
}


void print_linknode(linklist*head){
    while(head!=NULL){
        cout<<head->data<<",";
        head = head->right;
    }
}


void convert_pre_post(element_type pre_[],int pre_l,int pre_e,\
                      element_type post_[],int post_l,int post_e){
    if(pre_e>=pre_l){
    int mid = (pre_e-pre_l)/2;
    post_[post_e] = pre_[pre_l];
    convert_pre_post(pre_,pre_l+1,pre_l+mid,post_,post_l,post_l+mid-1);
        convert_pre_post(pre_,pre_l+mid+1,pre_e,post_,post_l+mid,post_e-1);
}
}        
int similar(treenode*node1,treenode*node2){
    if(node1==NULL&&node2==NULL){
        return 1;
    }
    else if(node1==NULL||node2==NULL){
        return 0;
    }
    else{
        int left = similar(node1->left,node2->left);
        int right = similar(node1->right,node2->right);
        return left&&right;
    }
}


//static int weight = 0;
int weight_tree(treenode*node,int deep){
    static int weight = 0;
    if(node->right==NULL&&node->left==NULL){
        weight += deep*node->data;
    }
    if (node->left!=NULL){
        weight_tree(node->left,deep+1);
    }
    if(node->right!=NULL){
        weight_tree(node->right,deep+1);
    }
    return weight;
}

int level_weight_tree(treenode*node){
    queue<treenode*>temp_tree_queue;
    treenode*end;treenode*temp_end;treenode*p;
    temp_tree_queue.push(node);
    temp_end = end = node;
    int deep = 0;int sum_weight = 0;
    while(!temp_tree_queue.empty()){
        p = temp_tree_queue.front();
        temp_tree_queue.pop();
        if(p->left==NULL&&p->right==NULL){
            sum_weight+=deep*p->data;
        }
        if(p->left!=NULL){
            temp_tree_queue.push(p->left);
            temp_end = p->left;
        }
        if(p->right!=NULL){
            temp_tree_queue.push(p->right);
            temp_end = p->right;
        }
        if(p==end){
            deep++;
            end = temp_end;
        }
    }

    return sum_weight;
}


typedef struct node{
    string data;
    struct node*left,*right;
}bitree;



void create_bitree(bitree*&node){
    node = new bitree;
    node->data = "*";
    node->left = new bitree;
    node->left->data = "+";
    node->left->left = new bitree ;
    node->left->left->data = "a";
    node->left->right = new bitree ;
    node->left->right->data = "b";
    node->right = new bitree ;
    node->right->data = "*";
    node->right->left = new bitree ;
    node->right->left->data = "c";
    node->right->right = new bitree ;
    node->right->right->data = "-";
    node->right->right->right = new bitree ;
    node->right->right->right->data = "d";

}

void cout_bitree(bitree*node,int deep){
    if(node==NULL){
        return ;
    }
    if(node->left==NULL&&node->right==NULL){
        cout<<node->data;
    }
    else{
        if(deep>0){
            cout<<'(';
        }
        cout_bitree(node->left,deep+1);
        cout<<node->data;
        cout_bitree(node->right,deep+1);
        if(deep>0){
        cout<<')';}
    }


}



int leave_nums(treenode*node){
    if(node==NULL){
        return NULL;
    }
    if(node->left==NULL){
        return 1+leave_nums(node->right);
    }
    else{
        return leave_nums(node->left)+leave_nums(node->right);
    }

}

int moritree_depth(treenode*node){
    if(node==NULL){
        return 0;
    }
    int sl = moritree_depth(node->left)+1;
    int sr = moritree_depth(node->right);
    if(sl>sr){
        return sl;
    }
    else{
        return sr;
    }

}


void create_bro_tree(treenode*&t,element_type e[],int degree[],int n){
    treenode*point = new treenode[100];
    for(int i = 0;i<n;i++){
        point[i].data = e[i];
        point[i].left = point[i].right = NULL;
    }
    int d,k=0;
    for(int i = 0;i<n;i++){
        d = degree[i];
        if(d){
            k++;
            point[i].left = &point[k];
            for(int j=1;j<d;j++){
                point[k].right = &point[k+1];
                k++;
            }
        }

    }
    t = &point[0];
    delete[] point;


}

  struct TreeNode {
      int val;
      TreeNode *left;
      TreeNode *right;
      int count;
      TreeNode() : val(0), left(nullptr), right(nullptr),count(1) {}
      TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
      TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
  };

typedef struct Tree_Stack{
    TreeNode*node;
    int tree_info;
    Tree_Stack():node(NULL),tree_info(0){}
    Tree_Stack(TreeNode*q,int i):node(q),tree_info(i){}
};

class Solution {
public:
    vector<int> postorderTraversal(TreeNode *root) {
        vector<int> result;
        Tree_Stack s[100];
        int top = -1;
        while(top>=0||root!=NULL){
            while(root!=NULL){
                s[++top].node = root;
                root = root->left;
                s[top].tree_info = 0;
            }
            while(top>=0&&s[top].tree_info==1){
                result.push_back(s[top].node->val);
                top--;
            }
            if(top>=0){
                s[top].tree_info = 1;
                root = s[top].node->right;
            }

        }
        return result;

    }

    bool verify(vector<int>& postorder,int i,int j){
        int p = i;
        if(i>=j){
            return true;
        }
        while(postorder[i]<postorder[j]){
            i++;
        }
        int m = i;
        while (postorder[i]>postorder[j]){
            i++;
        }
        return (i==j)&&verify(postorder,p,m-1)&&verify(postorder,m,j-1);
    }

//    bool verifyPostorder(vector<int>& postorder) {
//        int post_end = postorder.size();
//        return verify(postorder,0,post_end-1);
//    }

    bool verifyPostorder(vector<int>& postorder) {
        int root = INT_MAX;
        int end = postorder.size()-1;
        stack<int>Tree_Stack;
        for(int i =end;i>=0;i--){
            if(postorder[i]>root){
                return false;
            }
            while(!Tree_Stack.empty()&&postorder[i]<Tree_Stack.top()){
                root = Tree_Stack.top();
                Tree_Stack.pop();
            }
            Tree_Stack.push(postorder[i]);

        }
        return true;
    }
};





//class Solution {
//public:
//    TreeNode *lowestCommonAncestor(TreeNode *root, TreeNode *p, TreeNode *q) {
//        TreeNode*left;
//        TreeNode*right;
//        if(root==NULL||root==p||root==q){
//            return root;
//        }
//        left = lowestCommonAncestor(root->left,p,q);
//        right = lowestCommonAncestor(root->right,p,q);
//        if(left&&right){
//            return root;
//        }
//        else if(left&&!right){
//            return left;
//        }
//        else if(right&&!left){
//            return right;
//        }
//        else{
//            return NULL;
//        }
//    }
//
//};

//class Solution {
//public:
//    vector<int> preorderTraversal(TreeNode* root) {
//        vector<int> record;
//        stack<TreeNode*>tree_stack;
//        while(!tree_stack.empty()||root!=NULL){
//            if(root){
//                record.push_back(root->val);
//                tree_stack.push(root);
//                root = root->left;
//            }
//            else{
//                root = tree_stack.top();
//                tree_stack.pop();
//                root = root->right;
//            }
//        }
//        return record;
//
//    }
//};



//class Solution {
////private:
////    int ww = 0;
//public:
//    int kthLargest(TreeNode *root, int k) {
//        static int ww = 0;
//        int c;
//        if(root==NULL){
//            return '*';
//        }
//        c = kthLargest(root->right,k);
//        ww++;
//        if(ww==k){
//            return root->val;
//        }
//        if(c=='*') {
//            c = kthLargest(root->left, k);
//        }
//        return c;
//
//
//    }
//};





//class Solution{
//public:
//    vector<int> inorderTraversal(TreeNode* root) {
//        vector<int>record;
//        stack<TreeNode*>tree_stack;
//        while(!tree_stack.empty()||root!=NULL){
//            while(root){
//                tree_stack.push(root);
//                root = root->left;
//            }
//            if(root==NULL){
//                root = tree_stack.top();
//                tree_stack.pop();
//                record.push_back(root->val);
//                root = root->right;
//            }
//        }
//        return record;
//    }
//};


//class Solution{
//public:
//    vector<int> inorderTraversal(TreeNode* root) {
//        vector<int>record;
//        stack<TreeNode*>tree_stack;
//        tree_stack.push(root);
//        if(root==NULL){
//            return record;
//        }
//        while(!tree_stack.empty()){
//            root = tree_stack.top();
//            tree_stack.pop();
//            if(root){
//                if(root->right){
//                    tree_stack.push(root->right);
//                }
//                tree_stack.push(root);
//                tree_stack.push(NULL);
//                if(root->left){
//                    tree_stack.push(root->left);
//                }
//
//            }
//            else{
//                root = tree_stack.top();
//                tree_stack.pop();
//                record.push_back(root->val);
//            }
//
//        }
//        return record;
//
//    }
//};



//class Solution {
//public:
//    vector<int> inorderTraversal(TreeNode* root) {
//        stack<TreeNode*>root_temp;
//        vector<int>in_result;
//        while(root||!root_temp.empty()){
//            if(root){
//                root_temp.push(root);
//                root= root->left;
//            }
//            else{
//                root = root_temp.top();
//                root_temp.pop();
//                in_result.push_back(root->val);
//                root =root->right;
//            }
//        }
//        return in_result;
//    }
//};

//class Solution{
//public:
//    vector<int> inorderTraversal(TreeNode* root) {
//        stack<TreeNode*>temp_node;
//        TreeNode*pp;
//        vector<int>in_result;
//        temp_node.push(root);
//        while(!temp_node.empty()){
//            pp = temp_node.top();
//            temp_node.pop();
//            if(pp) {
//                if(pp->right) temp_node.push(pp->right);
//                temp_node.push(pp);
//                temp_node.push(NULL);
//                if(pp->left) temp_node.push(pp->left);
//            }
//            else{
//                pp = temp_node.top();
//                in_result.push_back(pp->val);
//                temp_node.pop();
//            }
//        }
//        return in_result;
//
//    }
//};

//class Solution {
//private:
//    int ww = 0;
//public:
//    int kthLargest(TreeNode* root, int k) {
//        //static int ww = 0;
//        if(root==NULL){
//            return '*';
//        }
//        int ch = kthLargest(root->right,k);
//        ww++;
//        if(ww==k){
//            return root->val;
//        }
//        if(ch=='*'){
//        return kthLargest(root->left,k);
//        }
//        else{
//            return ch;
//        }
//
//    }
//};
//class Solution {
//public:
//    vector<int> postorderTraversal(TreeNode* root) {
//        stack<TreeNode*>post_stack;
//        vector<int>post_result;
//        TreeNode*p;
//        while(root||!post_stack.empty()){
//            if(root){
//                post_stack.push(root);
//                root = root->left;
//            }
//            else{
//                root = post_stack.top();
//                if(root->right&&root->right!=p){
//                    root = root->right;
//                }
//                else{
//                    post_stack.pop();
//                    post_result.push_back(root->val);
//                    p = root;
//                    root = NULL;
//                }
//            }
//        }
//        return post_result;
//    }
//};

int pred = -32767;

int judge_bst(TreeNode*node){
    int b1,b2;
    if(node==NULL){
        return 1;
    }
    b1 = judge_bst(node->left);
    if(b1==0||pred>=node->val){
        return 0;
    }
    pred = node->val;
    b2 = judge_bst(node->right);
    return b2;
}


int level(TreeNode*node,TreeNode*bt){
    TreeNode*t;
    t = bt;
    int n = 0;
    while((t!=NULL)&&(t->val!=node->val)){
        if(t->val<node->val){
            t = t->right;
        }
        else if(t->val>node->val){
            t = t->left;
        }
        n++;
    }
    if(t==NULL){
        return 0;
    }
    return n;

}

int judge_leve_bst(TreeNode*node,int& jn,int &hn){
     int nleft=0;int nright = 0;int hl = 0;int hr = 0;
         if(node==NULL){
             jn = 1;
             hn = 0;
         }
         else if(node->left==NULL&&node->right==NULL){
             jn = 1;
             hn = 1;
         }
         else {
             judge_leve_bst(node->left, nleft, hl);
             judge_leve_bst(node->right, nright, hr);
             hn = max(hl,hr)+1;
             if (abs(hl - hr) > 1) {
                 jn = 0 ;
             } else {
                 jn = nleft&&nright;
             }
         }
         return jn;
}

int min_value_bst(TreeNode*p){
    while(p->left!=NULL){
        p = p->left;
    }
    return p->val;
}
int max_value_bst(TreeNode*p){
    while(p->right!=NULL){
        p = p->right;
    }
    return p->val;
}


void output_max_k_bst(TreeNode*node,int k){
    if(node==NULL){
        return ;
    }
    output_max_k_bst(node->right,k);
    if(node->val>=k){
        cout<<node->val<<' ';
    }
    output_max_k_bst(node->left,k);

}

TreeNode* search_small(TreeNode*node,int k){
    if(k<1||k>node->count){
        return NULL;
    }
    if(node->left==NULL){
        if(k==1){
            return node;
        }
        else{
            return search_small(node->right,k-1);
        }
    }
    else{
        if(node->left->count==k-1){
            return node;
        }
        else if(node->left->count>k-1){
            return search_small(node->left,k);
        }
        else if(node->left->count<k-1){
            return search_small(node->right,k-(node->left->count)-1);
        }

    }



}
//int add(int weight){
//    static int add_ = 0;
//    if(weight>4){
//        return add_;
//    }
//    add_++;
//    add(weight+1);
//    return add_;
//}
//int main() {
////    bitree* root__;
//    treenode*root;
//    tree_node*root_;
////    tree_node*p;
////    create_bitree(root__);
////    //cout_bitree(root__,0);
////    cout<<endl;
//    root_ = create_temp_tree_();
////    p = root_->left->left->left;
////    create_in_key(root_);
////    if(inKey_post_front(p)){
////    cout<<inKey_post_front(p)->data<<endl;}
////    root = create_temp_tree();
//    vector<int> record;
////    visit_in_key_tree(root_,record);
////    print_vector(record);
////    record.erase(record.begin(),record.end());
////
////    int c = weight_tree(root,0);
////    cout<<c<<endl;
////    cout<<level_weight_tree(root)<<endl;
////    cout<<leave_nums(root)<<endl;
////    cout<<moritree_depth(root)<<endl;
////
////    treenode*pp;
////    int aa[6] = {1,2,3,4,5,6};
////    int bb[6] = {3,0,1,1,0,0};
////    create_bro_tree(pp,aa,bb,6);
////    in_travell_visit(pp,record);
////    print_vector(record);
////    record.erase(record.begin(),record.end());
////    cout<<endl;
//    TreeNode*roott = new TreeNode(5);
//    roott->count =6;
//    TreeNode*left = new TreeNode(3);
//    roott->left = left;
//    left->count =3;
//    TreeNode*rightt = new TreeNode(6);
//    roott->right = rightt;
//    rightt->count = 2;
//    TreeNode*righttt = new TreeNode(7);
//    roott->right->right = righttt;
//    righttt->count = 1;
//    roott->left->left = new TreeNode(2);
//    roott->left->right = new TreeNode(4);
//    roott->left->left->count = 1;
//    roott->left->right->count = 1;
//
//    vector<int> result;
//    //int result;
//    Solution a;
//    result = a.postorderTraversal(roott);
//    //cout<< result;
//    print_vector(result);
//    vector<int> test = {4, 6, 12, 8, 16, 14, 10};
//    cout<<a.verifyPostorder(result)<<endl;
//    cout<<judge_bst(roott)<<endl;
//    cout<<level(roott->left->left,roott)<<endl;
//    int hn = 0;
//    int jn = 0;
//    cout<<judge_leve_bst(roott,hn,jn)<<endl;
//    cout<<min_value_bst(roott)<<endl;
//    cout<<max_value_bst(roott)<<endl;
//    output_max_k_bst(roott,3);
//    cout<<endl;
//    TreeNode*pp;
//    pp = search_small(roott,5);
//    cout<<pp->val<<endl;
////    visit_in_key_tree(root_,record);
////    print_vector(record);
////    record.erase(record.begin(),record.end());
//create_pre_key(root_);
//    visit_pre_key_tree(root_,record);
////    invert_level(root,record);
//    print_vector(record);
//}
//    record.erase(record.begin(),record.end());
//    cout<<tree_height(root)<<endl;
//    cout<<tree_height(root)<<endl;
//    treenode *p = recreate_pre_in_tree(root);
//    pre_out(p,record);
//    print_vector(record);
//    record.erase(record.begin(),record.end());
//    in_out(p,record);
//    print_vector(record);
//    record.erase(record.begin(),record.end());
//    cout<<complete_tree_wh(p)<<endl;
//    cout<<num_of_two_node(p)<<endl;
//    //swap(p);
//    pre_out(p,record);
//    print_vector(record);
//    record.erase(record.begin(),record.end());
//    pre_k_cal a;
//    cout<<a.pre_k(p,3)<<endl;
//    //delete_search(p,2);
//    pre_out(p,record);
//    print_vector(record);
//    record.erase(record.begin(),record.end());
//    post_travel_tree_stack(p,record,3);
//    print_vector(record);
//    record.erase(record.begin(),record.end());
//    treenode*p1 = p->left->left->left;
//    treenode*p2 = p->left->left->right;
//    cout<<acestor(p1,p2,p)->data<<endl;
//    cout<<INT_MAX<<endl;
//    cout<<width_tree(p)<<endl;
//    cout<<tree_width_version_2(p)<<endl;
//    element_type record_post[100];
//    element_type record_pre[100] = {1,2,4,5,3,6,7};
//    //print_vector(record);
//    convert_pre_post(record_pre,0,6,record_post,0,6);
//    for(int i = 0;i<=6;i++){
//        cout<<record_post[i]<<",";
//    }
//    cout<<endl;
//    record.erase(record.begin(),record.end());
//    in_leaf_tree(p);
//    print_linknode(head);
//    cout<<endl;
//    cout<<similar(root,p)<<endl;
//    pre_out(root,record);
//    print_vector(record);
//    record.erase(record.begin(),record.end());
//    in_out(root,record);
//    print_vector(record);
//    record.erase(record.begin(),record.end());
//    post_out(root,record);
//    print_vector(record);
//    record.erase(record.begin(),record.end());
//    pre_travel(root,record);
//    print_vector(record);
//    record.erase(record.begin(),record.end());
//    in_travel(root,record);
//    print_vector(record);
//    record.erase(record.begin(),record.end());
//    post_travel(root,record);
//    print_vector(record);
//    record.erase(record.begin(),record.end());
//    pre_travell_visit(root,record);
//    print_vector(record);
//    record.erase(record.begin(),record.end());
//    in_travell_visit(root,record);
//    print_vector(record);
//    record.erase(record.begin(),record.end());
//    post_travell_visit(root,record);
//    print_vector(record);
//    record.erase(record.begin(),record.end());
//    level_travel(root,record);
//    print_vector(record);
//    record.erase(record.begin(),record.end());



//    int a[6] = {1, 2, 3, 4, 5, 6};
//    vector<int> c(a, a + 4);
//    c.pop_back();
//    vector<int>b(3,2);
//    int test_b[] = {5,6,7};
//    b.insert(b.begin()+1,2,3);
//    for(int i = 0;i<b.size();i++){
//        cout<<b[i]<<',';
//    }
//    cout<<endl;
//    stack<int>test_k;
//    for(int i = 1;i<5;i++){
//        test_k.push(i);
//    }
//    while(!test_k.empty()){
//        cout<<test_k.top()<<',';
//        test_k.pop();
//    }
//
    //create_tree(root,dataa);
    //create_pre_tree(root);
//    create_nodup_tree(root_1);
//    //record_in = inorderTraversal(root);

    //print_vector(record_in);


//    vector<int> test_a;
//    test_a.push_back(1);
//    test_a.push_back(2);
//    test_a.push_back(3);
//    vector<int> test_b(test_a.begin(), test_a.begin() + 3);
//    for(vector<int>::iterator it = test_b.begin();it<test_b.end();it++){
//        cout<<*it<<',';
//    }
//    int a[6] = {1, 2, 3, 4, 5, 6};
//    vector<int> b;
//    vector<int> c(a, a + 4);
//    for (vector<int>::iterator it = c.begin(); it < c.end(); it++)
//        b.push_back(*it);
//
//    sort(b.begin(),b.end());
//    for (vector<int>::iterator it = b.begin(); it < b.end(); it++) {
//        cout << *it << ',';
//    }

