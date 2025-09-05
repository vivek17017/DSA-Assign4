#include<iostream>
using namespace std;
struct node
    {
        int data;
        node *next;
    };
class SLL{
    private:
    node *start;
    node *ptr;
    public:
    SLL(){
        start=nullptr;
    }
    void insert_data_begining(int element){
       
            node *temp=new node;
            temp->data=element;
            temp->next=start;
            start=temp;
            

        
    }
    void insert_data_end(int element){
        
            node *temp=new node;
            temp->data=element;
            temp->next=NULL;
            node *t;
            if(start==nullptr)
            start=temp;
            else{
                t=start;
                while (t->next!=nullptr)
                {
                    t=t->next;
                }
                t->next=temp;
                
            }

        
    }
    node* search_item(int e){
        node *ptr=start;
        while(ptr!=NULL)
        {
            if(ptr->data==e)
            return ptr;
            else
            ptr=ptr->next;
        }
        return nullptr;
    }
    void print_all_data(){
        node*ptr=start;
        while(ptr->next!=NULL)
        {
            cout<<ptr->data<<endl;
            ptr=ptr->next;
        }
        cout<<ptr->data<<endl;
    }
    void insertAfter(node*,int);
    void deleteFirstNode(){
        if(start!=nullptr)
        {
        node *temp=start;
        start=start->next;
        delete temp;
    }
    }
    void deleteLastNode(){
        if(start!=nullptr)
        {
             node *t;
                
                if(start->next==nullptr){
                    delete start;
                    start=nullptr;
                }
                else
            {
                t=start;
                while (t->next->next!=nullptr)
                {
                    t=t->next;
                }
                delete t->next;
                t->next=nullptr;   
            }
        }
    }
    void deleteSpecificNode(node *temp){
        if(temp!=nullptr){
        node *t=search_item(temp->data);
        if(t==temp){
            t=start;
            if(start==temp){
                start=start->next;
                delete temp;

            }
            else{
            while (t->next!=temp)
            {
                /* code */
                t=t->next;
            }
            t->next=temp->next;
            delete temp;
            
        }
    }
        }

    }
    ~SLL(){
        while (start!=nullptr)
        {
            deleteFirstNode();
        }
        
    }
  
    
};
void SLL::insertAfter(node *temp,int data){
    if(temp!=nullptr){
        //check if temp
        node *t=start;
        while (t!=nullptr)
        {
            if(t==temp)
            break;
            t=t->next;
        }
        if(t==nullptr)
        cout<<"Specified node is not belog to list";
        else{
            t=new node;
            t->data=data;
            t->next=temp->next;
            temp->next=t;
        }
        
    }
}
int main(){
    SLL arr;
    arr.insert_data_begining(1);
    arr.insert_data_begining(2);
    arr.insert_data_begining(3);
    arr.insert_data_begining(4);
    cout<<"search result: "<<arr.search_item(4)<<endl;
    arr.insert_data_begining(5);
    arr.insert_data_end(10);
    arr.insert_data_begining(6);
    arr.insert_data_begining(7);
    arr.insert_data_begining(8);
    arr.insert_data_end(11);
    arr.insert_data_begining(9);
    arr.insert_data_end(12);
    arr.print_all_data();
    cout<<arr.search_item(98);
    
}