#include <iostream>
using namespace std;

// using templete to can using any data type
template <class type>

class linkedlist
{     
    //this struct to can create nodes have 2 values      //  head                       tail
    struct node                                         //  _________________        ______________
    {                                                  //  |  item   |  next |----->| item  | next |-------->NULL                                 // |_________|________|
        type item;                                    //    _________________        ______________
        node *next;
    };
    node *head; // pointer to tell us the beginning of list
    node *tail; // pointer to tell us this is the end of list
    int length;
public:
    linkedlist()
    {head = NULL; tail = NULL; length=0;}  //default constructor.
    bool isempty(){return length==0;} // function check linkedlist have item or not.
    //function to add new node in the beginning of list
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
    //function to add new node in last of list
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
    //function to add any node at any loc.
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

    //function to removing element from beginning of list
    void removefirst()
    {
        if(isempty()){cout<<"Can not delete!, Linkedlist is empty!\n";}
        else if(length == 1)
        {
            delete head;
            head = tail = NULL;
        }
        else
        {
            node *cur = head;
            head = head->next;;
            delete cur;    
        }
        length--;
    }
    //function to removing element from end of list
    void removelast()
    {
        if(isempty()){cout<<"Can not delete!, Linkedlist is empty!\n";}
        else if(length == 1)
        {
            delete head;
            head = tail = NULL;
        }
        else
        {
            node *cur = head->next;
            node *prev = head;
            while(cur != tail)
            {
                prev = cur;
                cur = cur->next;
            }
            delete cur;
            prev->next = NULL;
            tail = prev;
        }
        length--;
    }

    void remove(type data) // function to remmove specific node
    {
        if(isempty()){cout<<"Can not delete!, Linkedlist is empty!\n";}
        node *cur, *prev;
        if(head->item == data)
        {
            cur = head;
            head = head->next;
            delete cur;
            if(length == 0){tail = NULL;}
        }
        else
        {
            cur = head->next;
            prev = head;
            while (cur != NULL)
            {
                if(cur->item == data) break;
                prev = cur;
                cur = cur->next;
            }
        if(cur == NULL){cout<<"Data not founded!\n";}
        else
        {
            prev->next = cur->next;
            if(tail == cur){tail = prev;}
            delete cur;
            length--;
        }
            
        }

    }
    // this function reverse all nodes of list
    void reverselist()
    {
        node *prev, *cur, *next;
        prev = NULL;
        cur = head;
        next = cur->next;
        while (next != NULL)
        {
            next = cur->next;
            cur->next = prev;
            prev = cur;
            cur = next;
        }
        head = prev;
    }
    //function to search for any element in linkedlist
    void search(type data)
    {
        node *cur = head;
        int pos = 0;
        while (cur != NULL)
        {
            if(cur->item == data){cout<<"Element ["<<cur->item<<"] founded in postition: "<<pos<<"\n"; break;}
            pos++;
            cur = cur->next;
        }
        if(cur == NULL){cout<<"Element not found!\n";}
    }

    //function to print all list.
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
    //declare object from linkedlist class
    linkedlist <int> l ;
    l.print();
    l.addnodefirst(10);
    l.addnodelast(15);
    l.addnodelast(20);
    l.addnodelast(30);
    l.addnodelast(40);
    l.addnodelast(50);
    l.print();
    cout<<"-----------\n";
//     l.remove(30);
//     l.print();
//     cout<<"----------\n";
//     l.remove(20);
//     l.print();
//    cout<<"---------\n";
//    l.remove(50);
//    l.print();
    //l.reverselist();
   // l.print();
    cout<<"--------------\n";
    l.search(300);

}