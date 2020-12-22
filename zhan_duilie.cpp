#include <iostream>
#include <vector>
#include <map>
using namespace std;
#define maxsize 20
typedef char element_type;

typedef struct node{
    char data;
    node*next;
}node,*lnode;



typedef struct Linknode{
    element_type data;
    struct Linknode*next;
}Linknode;



typedef struct{
    element_type data[maxsize];
    int top;
} sqstack;

typedef struct{
    element_type stack[maxsize];
    int top[2];
} sq;

typedef struct sqlist{
    element_type data[maxsize];
    int front,rear;
    int flag;
}sqlist;

typedef struct sqlink{
    Linknode*front;
    Linknode*rear;
}sqlink;



class sq_question{
private:
    sqlink sq;
public:
    void init(){
        sq.front = sq.rear = (Linknode*)malloc(sizeof(Linknode));
        sq.rear->next = sq.front;
    }
    bool is_empty(){
        if (sq.front==sq.rear){
            return true;
        }
        return false;
    }

    bool is_full(){
        if(sq.rear->next == sq.front){
            return true;
        }
        return false;
    }
    bool enqueque(element_type x){
        if(this->is_full()){
            Linknode* s = (Linknode*)malloc(sizeof(Linknode));
            sq.rear->data = x;
            sq.rear->next = s;
            s->next = sq.front;
            sq.rear = s;
            return true;
        }

        else{
            sq.rear->data = x;
            sq.rear = sq.rear->next;
            return true;
        }
    }

    bool dequeque(element_type&x){
        if (this->is_empty()){
            cout<<"队列空"<<endl;
            return false;
        }
        else{
            x = sq.front->data;
            cout<<"队列出 "<<x<<endl;
            sq.front = sq.front->next;
            return true;

        }

    }
    void print_list(){
        Linknode*q;
        q = sq.front;
        while (q&&q!=sq.rear){
            cout<<q->data<<" ";
            q = q->next;
        }
        cout<<endl;

    }


};


class sq_link{
private:
    sqlink sq;
public:
    void init(){
        sq.front = sq.rear = (Linknode*)malloc(sizeof(Linknode));
        sq.front->next = NULL;
    }
    void enqueue(element_type x){
        Linknode*s = (Linknode*)malloc(sizeof(Linknode));
        s->data = x;
        cout<<"入队数 "<<x<<endl;
        sq.rear->next = s;s->next = NULL;
        sq.rear = s;
    }
    bool dequeue(element_type&x){
        if(sq.rear==sq.front){
            return false;
        }
        Linknode*s = sq.front->next;
        sq.front->next = s->next;
        if(sq.rear==s){
            sq.rear = sq.front;
        }
        x = s->data;
        cout<<"出队数 "<<x<<endl;
        free(s);
        return true;
    }
};


class sq_list{
private:
    sqlist q;

public:
    void init(){
        q.front = q.rear = 0;
        q.flag = 0;
    }
    bool is_empty(){
        if(q.front == q.rear){
            return true;
        }
        return false;
    }

    bool enqueque(element_type x){
        if((q.rear+1)%maxsize==q.front){
            cout<<"队列满"<<endl;
            return false;
        }
        q.data[q.rear] = x;
            q.rear = (q.rear+1)%maxsize;
        cout<<"队列入数"<<x<<endl;
        return true;

    }

    bool dequeque(element_type&x){
        if(q.rear==q.front){
            cout<<"队列空"<<endl;
            return false;
        }
        x = q.data[q.front];
        cout<<"队列出数"<<x<<endl;
        q.front = (q.front+1)%maxsize;
        return true;

    }
    bool enqueque_1(element_type x){
        if(q.flag==1&&q.front==q.rear){
            cout<<"队列满"<<endl;
            return false;
        }
        q.flag = 1;
        q.data[q.rear] = x;
        q.rear = (q.rear+1)%maxsize;
        return true;
    }

    bool dequeque_1(element_type&x){
        if(q.flag==0&&q.front==q.rear){
            cout<<"队列空"<<endl;
            return false;
        }
        q.flag = 0;
        x = q.data[q.front];
        q.front = (q.front+1)%maxsize;
        return true;
    }

    void print_list(){
        int i = q.front%maxsize;
        while(i!=q.rear){
            cout<<q.data[i]<<' ';
            (i++)%maxsize;
        }
        cout<<endl;

    }
};

//shuangxiang
//class stack_sq{
//private:
//    sq s;
//public:
//    void init_stack(){
//        s.top[0] = -1;
//        s.top[1] = maxsize;
//    }
//    bool push(int i,element_type x){
//        if(i<0||i>1){
//            cout<<"栈序号不对"<<endl;
//            return false;}
//        if(s.top[1]-s.top[0]==1){
//            cout<<"栈满"<<endl;
//            return false;
//        }
//        switch (i) {
//            case 0:s.stack[++s.top[0]]=x;break;
//            case 1:s.stack[--s.top[1]]=x;
//        }
//        return true;
//    }
//
//    element_type pop(int i){
//        if(i<0||i>1){
//            cout<<"栈序号不对"<<endl;
//            return -1;}
//        switch(i){
//            case 0:
//                if(s.top[0]==-1){
//                    cout<<"栈空"<<endl;
//
//                    return -1;
//                }
//                else{
//                    return s.stack[s.top[0]--];
//                }
//            case 1:
//                if(s.top[1]==maxsize){
//                    cout<<"栈空"<<endl;
//                    return -1;
//                }
//                else{
//                    return s.stack[s.top[1]++];
//                }
//        }
//
//
//    }
//
//};





class stack_solve{
private:
    sqstack sq;
public:
    void init_stack(){
        sq.top = -1;
    }
    bool stack_full(){
        if(sq.top==maxsize-1){
            return true;
        }
        return false;
    }

    bool stack_empty(){
        if (sq.top==-1){
            return true;
        }
        return false;
    }

    bool push(element_type x){
        if (sq.top==maxsize-1){
            return false;
        }
        sq.data[++sq.top] = x;
        return true;
    }

    bool pop(element_type&x){
        if(sq.top==-1){
            return false;
        }
        x = sq.data[sq.top--];
        return true;
    }

    bool gettop(element_type&x){
        if(sq.top==-1){
            return false;
        }
        x = sq.data[sq.top];
        return true;

    }

    void print_stack(){
        if (sq.top!=-1) {
            for (int i = 0; i < sq.top + 1; i++) {
                cout << sq.data[i] << " ";
            }
        }
        cout<<endl;


    }


};





bool judge(char a[]){
    int k= 0;
    int i=0;
    while(a[i]!='\0'){
        if(a[i]=='I'){
            k++;
        }
        else{
            k--;
        }
        if(k<0){
            return false;
        }
        i++;

    }
    if (k>0){
        return false;
    }
    return true;

}

lnode build_data_list(int k){
    lnode s,p,head;
    char x;
    int i = 0;
    while (k>0){
        cin>>x;
        s = (node*)malloc(sizeof(node));
        s->data = x;
        if (i==0){
            head =p = s;
            i = 1;
        }
        else{
            p->next = s;
            p = s;
        }
        k--;

    }
    p->next = NULL;
    return head;


}

int long_lnode(lnode s){
    lnode p;
    p = s;
    int i = 0;
    while(p){
        i++;
        p = p->next;
    }
    return i;
}

void print_lnode(lnode s){
    lnode p = s;
    while(p){
        cout<<p->data<<" ";
        p = p->next;
    }
    cout<<endl;
}
bool judge_symmetry(lnode s){
    int n = long_lnode(s);
    lnode p = s;
    int i = 0;
    char temp_s[n/2];
    for(i=0;i<n/2;i++){
        temp_s[i] = p->data;
        p = p->next;

    }
    if(n%2==1){
        p = p->next;
    }
    i--;
    while(p){
        if(p->data!=temp_s[i]){
            break;}

        p = p->next;
        i--;
    }
    if(i==-1){
        return true;
    }
    return false;

}


void inverse(sq_list s){
    element_type x;
    stack_solve q;
    //s.init();
    q.init_stack();
    while(!s.is_empty()){
        s.dequeque(x);
        q.push(x);
    }
    while(!q.stack_empty()){
        q.pop(x);
        s.enqueque(x);
        //cout<<x<<" ";
    }
    while(!s.is_empty()){
        s.dequeque(x);
    }
}

bool bracket_check(stack_solve a,char*str){
    int i = 0;char s;
    a.init_stack();
    while (str[i]!='\0'){
        switch(str[i]){
            case '{':a.push(str[i]);break;
            case '[':a.push(str[i]);break;
            case '(':a.push(str[i]);break;
            case '}':a.pop(s);
            if (s!='{'){
                return false;
            }
            break;

            case ']':a.pop(s);
                if (s!='['){
                    return false;
                }
                break;
            case ')':a.pop(s);
                if (s!='('){
                    return false;
                }
                break;
        }
    i++;


    }
    if(!a.stack_empty()){
        return false;
    }
    return true;


}


class sq_list_solve{
private:
    stack_solve s_in;
    stack_solve q_out;
public:
    void init(){
        s_in.init_stack();
        q_out.init_stack();
    }
    bool enqueque(element_type x){
        if(!s_in.stack_full()){
            s_in.push(x);
            return true;
        }
        if(s_in.stack_full()&&q_out.stack_empty()){
            element_type i;
            while(!s_in.stack_empty()){
            s_in.pop(i);
            q_out.push(i);
            }
            s_in.push(x);
            return true;
        }
        if (s_in.stack_full()&&!q_out.stack_empty())
        {
            cout<<"队列满"<<endl;
            return false;
        }
    }

    bool dequeque(element_type&x){
        if(!q_out.stack_empty()){
            q_out.pop(x);
            cout<<x<<endl;
            return true;
        }
        else if(s_in.stack_empty()){
        cout<<"队列空"<<endl;
        return false;
        }
        else{
            element_type i;
            while(!s_in.stack_empty()){
                s_in.pop(i);
                q_out.push(i);
            }

            q_out.pop(x);
            cout<<x<<endl;
            return true;
        }

    }

    bool empty(){
        if(s_in.stack_empty()&&q_out.stack_empty()){
            return true;
        }
        return false;
    }

};


double p(int n,double x){
     struct f{
        int no;
        double val;
    };
    f fun[maxsize];int top = -1;
//    for(i=n;i>=2;i--){
//        top++;
//        fun[top].no = i;
//    }
int fv0 = 1;int fv1 = 2*x;
for(int i = 0;i<=n-2;i++){
    fun[i].val =2*x*fv1-2*(i+1)*fv0;
    fv0 = fv1;fv1 = fun[i].val;
}
if(n==0){
    return fv0;
}
return fv1;

}


double fp(int n,double x){
    struct p{
        int no;
        double val;
    };
    p pp[maxsize];
    int top = -1;int i;
    for(i = n;i>=2;i--){
        pp[++top].no = i;
    }
    int pv0 = 1;int pv1 = 2*x;
    while (top>=0){
        pp[top].val = 2*x*pv1-2*(pp[top].no-1)*pv0;
        pv0 = pv1;
        pv1 = pp[top].val;
        top--;
    }
    if(n==0){
        return pv0;
    }
    return pv1;


}



void train_arrange(char*train){
    stack_solve a;
    a.init_stack();
    char*m=train;char*nm = train;char c;
    int i = 0;int j = 0;

//    while(*m){
//        char cc = *m;
//        if(*m=='H'){
//            a.push(*m);
//        }
//        else{
//            *(nm++) = *m;
//        }
//        m++;
//    }
while(m[i]!='\0'){
    if(m[i]=='H'){
        a.push(m[i]);
    }
    else{
        nm[j++] = m[i];
    }
    i++;
}
    while(!a.stack_empty()){
        a.pop(c);
        //*(nm++) = c;
        nm[j++] = c;
    }
}

void manager(sq_list h_c,sq_list k_c,sq_list&s) {
    int i = 0;
    int j = 0;
    element_type x;
    while (j < 10) {
        if (!k_c.is_empty() && i < 4) {
            k_c.dequeque(x);
            s.enqueque(x);
            i++;
            j++;
        }
        else if (!h_c.is_empty() && i == 4) {
            h_c.dequeque(x);
            s.enqueque(x);
            j++;
            i = 0;
        }
        else{
            while(i<4&&!h_c.is_empty()){
                h_c.dequeque(x);
                s.enqueque(x);
                i++;
                j++;
            }
            i = 0;

        }
        if (h_c.is_empty() && k_c.is_empty()) {
            j = 11;
        }
    }
}


//int main(){
//    cout<<fp(0,2.5)<<endl;
//    cout<<p(0,2.5)<<endl;
//
////    stack_solve a;
////    int x;
////    a.init_stack();
////    a.push(1);
////    a.push(2);
////    a.pop(x);
////    a.print_stack();
////    cout<<endl;
////    cout<<x;
////    lnode s = build_data_list(2);
////    print_lnode(s);
////    cout<<judge_symmetry(s)<<endl;
//    //cout<<judge("IIIOOIOO")<<endl;
////    stack_sq a;
////    a.init_stack();
////    a.push(1,2);
////    a.push(0,1);
////    cout<<a.push(0,1);
////
////    cout<<endl;
////    stack_solve a;
////    sq_list b;
////    int x ;
////    b.enqueque(1);
////    b.enqueque(2);
////    b.enqueque(3);
////    inverse(b);
////    b.enqueque_1(3);
//    //b.dequeque_1(x);
//    //cout<<"数字为"<<x<<endl;
//    //int x;
////    sq_list_solve a;
////    a.init();
////    a.enqueque(1);
////    a.enqueque(2);
////    a.dequeque(x);
////    a.enqueque(3);
////    a.enqueque(4);
////    a.enqueque(5);a.enqueque(7);
////    a.enqueque(6);
////    a.enqueque(6);
////    a.dequeque(x);
////    a.dequeque(x);
////    a.dequeque(x);
////    a.dequeque(x);
////    a.dequeque(x);
////    a.dequeque(x);
////    a.dequeque(x);
////    a.dequeque(x);
////    sq_link a;
////    int x;
////    a.init();
////    a.enqueue(1);
////    a.enqueue(2);
////    a.dequeue(x);
////    a.dequeue(x);
////    a.dequeue(x);
////sq_question a;
////int x;
////a.init();
////a.enqueque(1);
////a.enqueque(2);
////a.enqueque(3);
////a.print_list();
////a.dequeque(x);
////a.dequeque(x);
////a.print_list();
//////a.dequeque(x);
//////a.dequeque(x);
////a.enqueque(5);
////a.enqueque(4);
////a.enqueque(4);
////a.enqueque(4);
////a.print_list();
////
//double c = rand()%1001;
//cout<<c<<endl;
//stack_solve a;
//cout<<bracket_check(a,"{{{}}}")<<endl;
//char train[12] ="HHLLLH";
//train_arrange(train);
//cout<<train<<endl;
//sq_list h_c;
//sq_list k_c;
//sq_list s;
//s.init();h_c.init();k_c.init();
//int ii;
//while(ii <9){
//    k_c.enqueque('k');
//    ii++;
//}
//ii = 0;
//while(ii<3){
//    h_c.enqueque('h');
//    ii++;
//}
//manager(h_c,k_c,s);
//s.print_list();
//cout<<0;
//    return 0;
//}
//
