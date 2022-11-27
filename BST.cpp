#include<iostream>
using namespace std;

typedef struct node 
{
    int data;
    struct node *lchild;
    struct node *rchild; 
}NODE,*PNODE,**PPNODE;

void Insert(PPNODE Head,int no)
{
    PNODE newn = new NODE;
    newn->data = no;
    newn->lchild = NULL;
    newn->rchild = NULL;

    if(*Head == NULL)
    {
        *Head = newn;
    }
    else
    {
        PNODE temp = *Head;
        while(1)        // Unconditional loop       for(;;)
        {
            if(no == (temp->data))
            {
                delete newn;
                break;
            }
            else if(no > (temp->data))
            {
                if(temp->rchild == NULL)
                {
                    temp->rchild = newn;
                    break;
                }
                temp = temp->rchild;    
            }
            else if(no < (temp->data))
            {
                if(temp->lchild == NULL)
                {
                    temp->lchild = newn;
                    break;
                }
                temp = temp->lchild;
            }
        }
    }
}

bool Search(PNODE Head,int no)
{
    bool flag = false;

    if(Head == NULL)
    {
        return flag;
    }
    else
    {
        while(Head != NULL)
        {
            if(Head->data == no)
            {
                flag = true;
                break;
            }
            else if(no > Head->data)
            {
                Head = Head->rchild;
            }
            else if(no < Head->data)
            {
                Head = Head->lchild;
            }
        }
        return flag;
    }
}

int Count(PNODE Head)
{
    static int iCnt;
    if(Head != NULL)
    {
        iCnt++;
        Count(Head->lchild);
        Count(Head->rchild);
    }
    return iCnt;
}

int CountLeaf(PNODE Head)
{
    static int iCnt;
    if(Head != NULL)
    {
        if((Head->lchild == NULL)  && (Head->rchild == NULL))
        {
            iCnt++;
        }
        CountLeaf(Head->lchild);
        CountLeaf(Head->rchild);
    }
    return iCnt;
}

int CountParent(PNODE Head)
{
    static int iCnt;
    if(Head != NULL)
    {
        if((Head->lchild != NULL)  || (Head->rchild != NULL))
        {
            iCnt++;
        }
        CountParent(Head->lchild);
        CountParent(Head->rchild);
    }
    return iCnt;
}



int main()
{
    int no = 0,iret = 0;
    bool bret = false;
    PNODE first = NULL;
    
    Insert(&first,51);
    Insert(&first,21);
    Insert(&first,101);
    //Insert(&first,55);
    //Insert(&first,75);
    //Insert(&first,20);

    cout<<"Enter number to search\n";
    cin>>no;

    bret = Search(first,no);
    if(bret == true)
    {
        cout<<"Number is there\n";
    }
    else
    {
        cout<<"Number is not there\n";
    }

    iret = Count(first);
    cout<<"Elements inside tree : "<<iret<<"\n";

    iret = CountLeaf(first);
    cout<<"Number of leaf nodes are : "<<iret<<"\n";
    
    iret = CountParent(first);
    cout<<"Number of parent node are : "<<iret<<"\n";
    
    return 0;
}