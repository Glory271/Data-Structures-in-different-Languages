#include<iostream>

struct ListNode{
    int val;
    struct ListNode *next;
    ListNode(int x):val(x),next(nullptr){} 
};

void insert(ListNode *n0,ListNode *p){
    if(n0==nullptr || p==nullptr){
        return;
    }
    p->next=n0->next;
    n0->next=p;
}

void remove(ListNode *n0){
    if(n0==nullptr || n0->next==nullptr){
        return;
    }

    ListNode *p=n0->next;
    n0->next=p->next;
    delete p;
}

ListNode *access(ListNode *head,int idx){
    ListNode *current=head;
    for(int i=0;i<idx;i++){
        if(current==nullptr){
            return nullptr;
        }
        current =current->next;
    }
    return current;
}

int find(ListNode *head,int target){
    int idx=0;
    ListNode *current=head;
    while(current !=nullptr){
        if(current->val==target){
            return idx;
        }
        current=current->next;
        idx++;
    }
    return -1;
}

void printList(ListNode *head){
    ListNode *current=head;
    while(current!=nullptr){
        std::cout<<current->val;
        if(current->next!=nullptr){
            std::cout<<"->";
        }
        current=current->next;
    }
    std::cout<<std::endl;
}

void freeList(ListNode *head){
    ListNode *current =head;
    while(current!=nullptr){
        ListNode *temp=current;
        current=current->next;
        delete temp;
    }
}

int main(){
    std::cout<<"==测试用例1:基础操作==="<<std::endl;
    ListNode *head=new ListNode(1);
    ListNode *n2=new ListNode(2);
    ListNode *n3=new ListNode(3);

    head->next=n2;
    n2->next=n3;
    
    std::cout<<"原始链表：";
    printList(head);

    ListNode *node=access(head,1);
    if(node){
        std::cout<<"访问索引1"<<node->val<<std::endl;
    }

    int idx=find(head,3);
    std::cout<<"查找值3的索引:"<<idx<<std::endl;
    
    ListNode *n4=new ListNode(4);
    insert(head,n4);
    std::cout<<"插入后链表:";
    printList(head);

    freeList(head);

    std::cout<<"\n===测试用例2:边界情况==="<<std::endl;
    ListNode *empty=nullptr;

    idx=find(empty,1);
    std::cout<<"空链表查找结果:"<<idx<<std::endl;

    ListNode *result=access(empty,0);
    std::cout<<"空链表访问结果:"<<(result==nullptr? "nullptr":"有值")<<std::endl;

    std::cout<<"\n===测试用例3:单节点链表==="<<std::endl;
    ListNode *single=new ListNode(10);

    std::cout<<"单节点链表：";
    printList(single);

    ListNode *newNode=new ListNode(20);
    insert(single,newNode);
    
    std::cout<<"插入后:";
    printList(single);

    remove(single);
    std::cout<<"删除后:";
    printList(single);

    std::cout<<"\n===测试用例4:越界访问==="<<std::endl;
    ListNode *list=new ListNode(100);
    list->next=new ListNode(200);

    ListNode *outofBound=access(list,5);
    std::cout<<"越界访问结果："<<(outofBound==nullptr? "nullptr":"有值")<<std::endl;
    
    freeList(list);

    return 0;
}