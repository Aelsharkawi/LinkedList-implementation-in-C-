#include <iostream>
using namespace std;

template <class type>

class linkedlist
{                                                //  head                       tail
    struct node                                 //  _________________        ______________
    {                                          //  |  item   |  next |----->| item  | next |-------->NULL                                 // |_________|________|
        type item;                            //    _________________        ______________
        node *next;
    };
    node *head;
    node *tail;
    int length;
public:
    linkedlist()
    {head = NULL; tail = NULL; length=0;}  //default constructor.
    bool isempty(){return length==0;} // function check linkedlist have item or not.

    void addnodefirst(type data)
    {
        node *newnode = new node;
        newnode->item = data;
        if(isempty())
        {
            head = tail = newnode;
            newnode->next =NULL;
        }
        else
        {
            newnode->next = head;
            head = newnode;
        }
       length++;
    }

    void addnodelast(type data)
    {
        node *newnode = new node;
        newnode->item = data;
        if(isempty())
        {
            head = tail = newnode;
            newnode->next =NULL;
        }
        else
        {
            tail->next = newnode;
            newnode->next = NULL;
            tail = newnode;
        }
       length++;
    }

    void add_node_at_pos(type data, int pos)
    {
        node *newnode = new node;
        newnode->item = data;
        if(pos < 0 || pos > length){cout<<"Out of range!\n";}
        else
        {
            if(pos == 0)
            {
                addnodefirst(data);
            }
            else if(pos == length)
            {
                addnodelast(data);
            }
            else
            {
                node *cur = head;
                for(int i=0; i<pos-1; i++)
                {
                    cur = cur->next;
                }
                newnode->next = cur->next;
                cur->next = newnode;
            }
        }
       length++;
    }

    void print()
    {
        if(isempty()){cout<<"Linked List is empty!\n";}
        else
        {
            node *temp = head;
            while (temp != NULL)
            {      
                cout<<temp->item<<endl;
                temp = temp->next;
            }
        }
    }
};

int main()
{
    linkedlist <int> l ;
    l.print();
    l.addnodefirst(10);
    l.addnodefirst(15);
    l.addnodefirst(20);
    l.print();
    cout<<"--------\n";
    l.addnodelast(5);
    l.addnodelast(1);
    l.print();
    cout<<"----------\n";
    l.add_node_at_pos(99,0);
    l.print();
    cout<<"-----------\n";
    l.add_node_at_pos(99,99);
}