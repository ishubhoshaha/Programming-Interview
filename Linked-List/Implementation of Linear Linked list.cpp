#include<iostream>
#include<cstdlib>
#include<cstdio>
using namespace std;
typedef struct node
{
    int info;
    struct node *next_node_address;
};
node *head,*lst;
void TravarseList()
{
    node *temp;
    temp=head;
    while(temp!=NULL)
    {
        cout<<temp->info<<" ";
        temp=temp->next_node_address;
    }
    cout<<endl;
}
void at_begin()
{
    cout<<"Please, Insert Data:"<<endl;
    lst=(node *)malloc(sizeof(node));
    cin>>lst->info;
    if(head==NULL)
    {
        head=lst;
        head->next_node_address=NULL;
    }
    else
    {
        lst->next_node_address=head;
        head=lst;
    }
}
void at_middle()
{
    node *temp;
    temp=head;
    lst=(node *)malloc(sizeof(node));
    int data;
    cout<<"Enter the number which u want to insert into list:";
    cin>>lst->info;
    cout<<"Now the list contain:";
    TravarseList();
    cout<<"Choose Data from the current list, where u want to insert your desire number: ";
    int searching_item;
    cin>>searching_item;
    while(temp->next_node_address!=NULL)
    {
        if(temp->info==searching_item)
        {
            lst->next_node_address=temp->next_node_address;
            temp->next_node_address=lst;
            break;
        }
        temp=temp->next_node_address;
    }
}
void at_end()
{
    node *temp,*l;
    cout<<"Please, Insert Data:"<<endl;
    lst=(node *)malloc(sizeof(node));
    cin>>lst->info;
    if(head==NULL)
    {
        //cout<<"S:";
        head=lst;
        head->next_node_address=NULL;
    }
    else
    {
        temp=head;
        while(temp!=NULL)
        {
            if(temp->next_node_address==NULL)
            {
                temp->next_node_address=lst;
                lst->next_node_address=NULL;
                break;
            }
            temp=temp->next_node_address;
        }
    }
}
void del_from_begin()
{
    node *temp;
    if(head==NULL)
    {
        cout<<"Sorry! List is empty.\n";
    }
    else
    {
        temp=head->next_node_address;
        free(head);
        head=temp;
        cout<<"Deleted...";
    }

}
void del_by_item(int item)
{
    node *temp1,*temp2;
    temp1=head;
    while(temp1!=NULL)
    {
        if(temp1==NULL)
        {
            cout<<"List is Empty."<<endl;
            return ;
        }
        else
        {

            if(temp1->info==item)
            {
                temp2->next_node_address=temp1->next_node_address;
                free(temp1);
                break;
            }
            temp2=temp1;
            temp1=temp1->next_node_address;
            cout<<"Deleted...";
        }

    }
}
void del_from_end()
{
    node *temp1,*temp2;
    temp1=head;
    if(head==NULL)
    {
        cout<<"Sorry! List is empty.\n";
    }
    else
    {
        while(temp1!=NULL)
        {
            if(temp1->next_node_address==NULL)
            {
                free(temp1);
                temp2->next_node_address=NULL;
                break;
            }
            temp2=temp1;
            temp1=temp1->next_node_address;

        }
        cout<<"Deleted...";
    }

}
void insertion_menu()
{

    char i_ch='a';
    while(i_ch!='n')
    {
        cout<<endl;
        int ins_choice;
        cout<<"1.Insert Data at the begin of the list."<<endl
            <<"2.Insert data at middle of the list."<<endl
            <<"3.Insert data at the end of the list."<<endl
            <<"Enter ur choice: ";
        cin>>ins_choice;
        switch(ins_choice)
        {
        case 1:
            at_begin();
            cout<<"Now the list contains"<<endl;
            TravarseList();
            cout<<endl;
            break;
        case 2:
            at_middle();
            cout<<"Now the list contains"<<endl;
            TravarseList();
            cout<<endl;
            break;
        case 3:
            at_end();
            cout<<"Now the list contains"<<endl;
            TravarseList();
            cout<<endl;
            break;
        }
        cout<<"Want to Continue data Insertion?(For no press 'n'): ";
        cin>>i_ch;
        cout<<endl<<endl;
    }
}
void deletion_menu()
{
    char d_ch='a';
    while(d_ch!='n')
    {
        cout<<endl;
        int del_choice;
        cout<<"1.Delete Data at the begin of the list."<<endl
            <<"2.Delete data at middle of the list."<<endl
            <<"3.Delete data at the end of the list."<<endl
            <<"Enter ur choice: ";
        cin>>del_choice;
        switch(del_choice)
        {
        case 1:
            del_from_begin();
            cout<<"Now the list contains"<<endl;
            TravarseList();
            cout<<endl;
            break;
        case 2:
            int item;
            cout<<"Which Number you want to delete.";
            cin>>item;
            del_by_item(item);
            cout<<"Now the list contains"<<endl;
            TravarseList();
            cout<<endl;
            break;
        case 3:
            del_from_end();
            cout<<"Now the list contains"<<endl;
            TravarseList();
            cout<<endl;
            break;
        }

        cout<<"Want to Continue data deletion?(For no press 'n'): ";
        cin>>d_ch;
        cout<<endl<<endl;
    }
}
int main()
{

    int n;
    head=NULL;
    char ch;
    while(ch!='n')
    {
            int root_choice;
            cout<<"1.Insert data into list."<<endl
                <<"2.Delete data from the list."<<endl
                <<"3.Exit."<<endl
                <<"Enter your Choice: ";
            cin>>root_choice;
            switch(root_choice)
            {
            case 1:
                insertion_menu();
                break;
            case 2:
                deletion_menu();
                break;
            case 3:
                exit(0);
                break;
            }//end of the root swtch
            cout<<"Want to go back at root menu?(For no press 'n':): ";
            cin>>ch;
            cout<<endl<<endl;
    }//root_loop ending
    return 0;
}
