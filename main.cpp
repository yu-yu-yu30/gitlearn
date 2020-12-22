#include <iostream>
#include <vector>
using namespace std;
#define maxlenth 50
//#define int element_type

typedef struct sqlist{
    int data[maxlenth];
    int lenth;
}sqlist;

struct seqlist{
    int*data;
    int lenth,max_lenth;
};
bool add_value(sqlist&l,int i,int value)
{
    if (i>l.lenth+1|| i<1){
        return false;
    }
    else if(l.lenth>maxlenth){
        return false;
    }
    else{
        for (int j=l.lenth;j>=i;j--)
        {
            l.data[j]=l.data[j-1];
        }
        l.data[i-1] = value;
        l.lenth++;
        return true;
    }
};

int delete_min_value(sqlist&l){
    int index_value=0;
    int min_value = l.data[0];
    if (l.lenth<=0){
        return false;
    }
    else{
        for (int i=1;i<l.lenth;i++)
        {
            if (l.data[i]<min_value){
                min_value = l.data[i];
                index_value = i;
            }
        }
        l.data[index_value] = l.data[l.lenth-1];
        l.lenth--;
        return min_value;
    }
}
bool delete_value(sqlist&l,int i,int &e)
{
    if (i<1||i>=l.lenth+1) {
        return false;
    }
    else if (l.lenth<1){
        return false;
    }
    e = l.data[i-1];
    for (int j=i;j<l.lenth;j++){
        l.data[j-1] = l.data[j];
    }
    l.lenth--;
    return true;
};

void reverse(sqlist&l)
{
    for (int i=0;i<l.lenth/2;i++)
    {
        int temp = l.data[i];
        l.data[i] = l.data[l.lenth-1-i];
        l.data[l.lenth-1-i] = temp;
    }
    for (int i=0;i<l.lenth;i++)
    {
        cout<<l.data[i]<<" ";
    }
    cout<<endl;
}
void print_value(sqlist&l){
    if (l.lenth<=0){
        cout<<"no list here";
    }
    else{
        for(int i=0;i<l.lenth;i++){
            cout<<l.data[i]<<" ";
        }
        cout<<endl;
    }

}
bool change_value(sqlist&l){
    if (l.lenth<=0){
        return false;
    }
    for (int i = 0;i<l.lenth/2;i++){
        int temp = l.data[i];
        l.data[i] = l.data[l.lenth-1-i];
        l.data[l.lenth-1-i] = temp;
    }
    return true;
}

void delete_x(sqlist&l,int x){
    int k = 0;
    for (int i=0;i<l.lenth;i++){
        if(l.data[i]==x){
            k++;
        }
        else{
            l.data[i-k] = l.data[i];
        }
    }
    l.lenth = l.lenth-k;
}
bool delete_s_t(sqlist&l,int s,int t){
    if (s>=t||l.lenth<1){
        return false;
    }
    else{
        int i=0;
        while (l.data[i]<s){
            i++;
        }
        if (i>=l.lenth){
            return false;
        }
        int j = i;
        for (j=i;l.data[j]<=t;j++);
        for (;j<l.lenth;j++,i++){
            l.data[i] = l.data[j];
        }
        l.lenth = i;
        //l.lenth = l.lenth-(j-i);

    }
}

bool delete_s_t_no_turn(sqlist&l,int s,int t){
    if(s>=t){
        return false;
    }
    if(l.lenth>maxlenth){
        return false;
    }
    else{
        int k = 0;
        for(int i=0;i<l.lenth;i++){
            if (l.data[i]>=s&&l.data[i]<=t){
                k++;
            }
            else{
                l.data[i-k] =l.data[i];
            }
        }
        l.lenth-=k;
    }
}

bool delete_dupicate(sqlist&l){
    int i = 0;
    int j = 1;
    while (j<l.lenth){
        if(l.data[j]==l.data[i]){
            j++;
        }
        else {
            l.data[++i] = l.data[j];
            j++;
        }
    }
    l.lenth = i+1;
}

bool delete_dupicate_second(sqlist&l){
    int i,j;
    for  (i=0,j=1;j<l.lenth;j++){
        if (l.data[j]!=l.data[i]){
            l.data[++i] = l.data[j];
        }
    }
    l.lenth = i+1;

}

bool merge_a_b(sqlist&a,sqlist&b,sqlist&c){
    if (a.lenth+b.lenth>maxlenth){
    return false;
    }
    else{

        int i=0;int j=0;int k=0;
        while(i<a.lenth&&j<b.lenth){
            if (a.data[i]<b.data[j]){
                c.data[k++] = a.data[i++];
            }
            else{
                c.data[k++] = b.data[j++];
            }

        }
       for(i;i<a.lenth;i++){
            c.data[k++] = a.data[i];
        }
        for (j;j<b.lenth;j++){
            c.data[k++] = b.data[j];
        }
        c.lenth = k;
       return true;
    }

}

bool reverse_sqlist(sqlist&a,int left,int right){
    if (left>=right||right>maxlenth){
        return false;
    }
    else{
        int mid,dis_mid,temp;
        mid = (left+right)/2;
        dis_mid = mid-left+1;
        for (int i=0;i<dis_mid;i++){
            temp = a.data[left+i];
            a.data[left+i] = a.data[right-i];
            a.data[right-i] = temp;
        }
        return true;
    }
}

bool search_add_x(sqlist&a,int x){
    int left = 0;int right = a.lenth-1;int mid;int temp;
    while (left<=right){
        mid = (left+right)/2;
        if (a.data[mid]<x){
            left = mid+1;
        }
        else if(a.data[mid]>x){
            right = mid-1;
        }
        else if (a.data[mid]==x&&mid<a.lenth-1){
            temp = a.data[mid];
            a.data[mid] = a.data[mid+1];
            a.data[mid+1] = temp;
            return true;
        }
        else{
            return true;
        }
    }
    for (int n = a.lenth-1;n>right;n--){
        a.data[n+1] = a.data[n];
    }
    a.data[right+1] = x;
    return true;

}


void exchange_sqlist(sqlist&a,int m,int n){
    reverse_sqlist(a,0,a.lenth-1);
    reverse_sqlist(a,0,m-1);
    reverse_sqlist(a,m,m+n-1);

}

int marjority(sqlist&a){
    int temp = a.data[0];
    int count = 1;
    for (int i=1;i<a.lenth;i++){
        if (count==0){
            temp = a.data[i];
            count =1;
        }
        if (a.data[i]==temp) {
            count++;
        }
        else{
            count--;
        }
    }
    if (count>0){
        count = 0;
        for (int i=0;i<a.lenth;i++){
            if (a.data[i]==temp){
                count++;
            }
        }
        if (count>a.lenth/2){
            return temp;
        }
    }
    return -1;
}

int min_value(sqlist&a){
    int *b;
    b = (int*)malloc(sizeof(int)*a.lenth);
    for (int i = 0;i<a.lenth;i++){
        if (a.data[i]>0&&a.data[i]<=a.lenth){
            b[a.data[i]-1]=1;
        }
    }
    int i = 0;
    for (i=0;i<a.lenth;i++){
        if (b[i]==0){
            return i+1;
        }
    }
    return i+1;
}

//int main()
//{
////
////    cout<<"Hello, World!"<<endl;
////    cout<<"here is test"<<endl;
////    int delete_e;
////    sqlist a = {{3,2,3,1,4,3,3},7};
////    //memset(a.data,0,sizeof(a.data));
////    //a.lenth = maxlenth;
////    add_value(a,1,10);
////    add_value(a,7,2);
////    delete_value(a,4,delete_e);
////    cout<<delete_e<<endl;
////    print_value(a);
////    delete_min_value(a);
////    print_value(a);
////    delete_x(a,3);
////    print_value(a);
//
//    //reverse(a);
//    sqlist a = {{2,3,3,3,6,7},6};
//    sqlist b = {{1,2,6},3};
//    sqlist c ={{},50};
//    delete_s_t_no_turn(a,6,7);
//    delete_dupicate_second(a);
//    print_value(a);
//    merge_a_b(a,b,c);
//    print_value(c);
//    exchange_sqlist(c,2,3);
//    print_value(c);
//    sqlist d = {{1,2,3,2},4};
//    //search_add_x(d,6);
//    print_value(d);
//    //int x = marjority(d);
//    int x = min_value(d);
//    cout <<x<<endl;
//    return 0;
//}


