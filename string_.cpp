#include <iostream>;
#include<vector>;
using namespace std;

typedef struct st{
    char *ch;
    int lenth;
    st():lenth(0),ch((char*)malloc(sizeof(char)*12)){};
}sstring;


int length_sstring(sstring a){
    int i = 0;
    char*p = a.ch;
    //i = strlen(a.ch);
    while(p[i]!='\0'){
        i++;
    }
    return i;
}

void create_string(sstring &a){
    cout<<"plese input string:";
    cin>>a.ch;
    a.lenth = length_sstring(a);
}

void StrAssign(sstring&a,char assign[]){
    int length = strlen(assign);
    int i = 0;
    char*p = a.ch;
    a.lenth = length;
    while(assign[i]!='\0'){
        *p++ = assign[i];
        i++;
    }
}

void StrCopy(sstring&a,sstring b){
    a.lenth = b.lenth;
    a.ch = b.ch;
}

bool StrEmpty(sstring a){
    if(a.lenth==0){
        return true;
    }
    return false;
}

bool StrCompare(sstring a,sstring b){
    char*p = a.ch;
    char*q = b.ch;
    while(*p&&*q){
        if(*p!=*q){
            return (*p>*q)?1:-1;
        }
        p++;
        q++;
    }
    if(*p&&!*q){
        return 1;
    }
    if(*q&&!*p)
    {
    return -1;}
    return 0;
}


void print_sstring(sstring a){
    int i = 0;
    while(a.ch[i]){
        cout<<a.ch[i];
        i++;
    }
    cout<<endl;
}

void SubString(sstring&s,sstring a,int pos,int len){
    int lenth = pos+len;
    char*p = s.ch;
    if (a.lenth<lenth){
        cout<<"lenth is not enough,please retry.."<<endl;
        exit(0);
    }
    for(int i = pos;i<lenth;i++){
        *p++ = a.ch[i];
    }
    *p = '\0';
    s.lenth = len;
}

void Concat(sstring&a,char aa[],char bb[]){
    char*p = a.ch;
    string x = aa;string y = bb;
    x.append(y);
    for (int i = 0;i<x.length();i++){
        *p++ = x[i];
    }
    a.lenth = x.length();
}



int Index(sstring a,sstring t){
    int len_a = length_sstring(a);
    int len_t = length_sstring(t);
    sstring temp;
    if(len_t>len_a){
        cout<<"no result here.."<<endl;
        exit(0);
    }
    int i = 0;
    while(i<=len_a-len_t){
        SubString(temp,a,i,len_t);
        if(StrCompare(temp,t)==0){
            return i;
        }
        i++;
    }
    return -1;

}

void Clear_String(sstring&a){
    a.lenth = 0;
    a.ch = "\0";
}


void Destroy_String(sstring&a){
    delete [] a.ch;
    a.lenth = -1;
}


void get_next(sstring a,int next[]){
    int i = 0; int j = -1;
    next[0] = -1;
    while(i<a.lenth){
        if(j==-1||(j>=0&&a.ch[i]==a.ch[j]))
        {
            i++;
            j++;
            if(a.ch[i]==a.ch[j]){
                next[i] = next[j];
            }
            else{
            next[i] = j;}
        }
        else{
            j = next[j];
        }
    }
}

int index_kmp(sstring a,sstring t,int next[]){
    int i = 0; int j = 0;
    while(i<a.lenth&&j<t.lenth){
        if(j==-1||(j>=0&&a.ch[i]==t.ch[j])){
            i++;
            j++;
        }
        else{
            j = next[j];
        }

    }
    if(j>=t.lenth){
        return i-t.lenth;
    }
    else{
        return -1;
    }
}



//int main(){
//    sstring a;
//    sstring b;
//    create_string(a);
//    create_string(b);
//    int next[30];
//    //SubString(b,a,0,2);
//    //Concat(a,"dd s","vv");
//    cout<<a.lenth<<endl;
//    print_sstring(a);
//    //StrAssign(a,"sda");
//    //cout<<StrCompare(a,b)<<endl;
//    print_sstring(b);
//    get_next(b,next);
//    //cout<<Index(a,b)<<endl;
//    //Destroy_String(a);
//    cout<<index_kmp(a,b,next)<<endl;
//    return 0;
//}