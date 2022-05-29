#include <stdio.h>

// KLASSEN & STRUKTUREN:
struct zyklische_Liste_Node
{
    int index;
    zyklische_Liste_Node* next;

    zyklische_Liste_Node(int index_val)
    {
        index = index_val;
    }
    
    zyklische_Liste_Node(int index_val, zyklische_Liste_Node* next_val)
    {
        index = index_val; next = next_val;
    }
};

class zyklische_Liste
{
    public:
    zyklische_Liste_Node* head;

    zyklische_Liste(zyklische_Liste_Node* head_val)
    {
        head = head_val;
    }

    void loeschen(zyklische_Liste_Node* ptr)    //ptr->next wird geloeschet
    {
        struct zyklische_Liste_Node* buff = ptr->next->next;
        // delete ptr->next; (nicht verwendet weil kein heap benutzt - nur Simulation)
        ptr->next = buff;
    }

    int josephus(int n, int k) // n: Groesse der Liste, k: Anfangspunkt,
    {                          // return: Index ueberlebende (Josephus)
        static zyklische_Liste_Node* ptr = head;
        if(n==1)
        {
            head = ptr;
            // head am Ende anpassen:
            return head->index;
        }
        else
        {
            for(int i=1; i<k-1; i++)
            {
                // ptr zeigt auf Element links des zu loeschenden Element:
                ptr = ptr->next;
            }
            printf("%d\n", ptr->next->index);
            loeschen(ptr);
            // ptr auf naechsten Element verschoeben damit gleiche Schrittweite
            ptr = ptr->next;
            return josephus(n-1,k); 
        }
    }
};

// TEST:
int main()
{
    // Listenelemente erzeugen:
    zyklische_Liste_Node e7 = zyklische_Liste_Node(7);
    zyklische_Liste_Node e6 = zyklische_Liste_Node(6, &e7);
    zyklische_Liste_Node e5 = zyklische_Liste_Node(5, &e6);
    zyklische_Liste_Node e4 = zyklische_Liste_Node(4, &e5);
    zyklische_Liste_Node e3 = zyklische_Liste_Node(3, &e4);
    zyklische_Liste_Node e2 = zyklische_Liste_Node(2, &e3);
    zyklische_Liste_Node e1 = zyklische_Liste_Node(1, &e2);
    e7.next = &e1;
    //Liste erzeugen:
    zyklische_Liste l1 = zyklische_Liste(&e1);

    printf("Josephus war in der Position %d.\n", l1.josephus(7,3) );

    return 0;
}