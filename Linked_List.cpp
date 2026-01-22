//! Linked List in C++

#include <iostream>
#include <iomanip>
#include <map>

//* class/ structure for node
class Node {
public: 

    int data;
    Node* next;

    //^ constructor (initialize an empty list)
    Node(int val) {
        data = val;
        next = NULL;
    }

};

//* class/ structure for List
class SinglyLinkedList {
    //~ head nd tail pointers
    Node* head;
    Node* tail;
    int size = 0;

public:

    //^ constructor
    SinglyLinkedList() {
        head = tail = NULL; //~ initialize head nd tail as NULL
    }

    //? getter for head
    Node* getHead() {
        return head;
    }

    //^ function for push front
    void pushFront(int val) {
        //? creating new node with help of new kw
        Node* newNode = new Node(val); // dynamic

        //& syntax 2 : for static object creation
        //? Node newNode(val); // static

        //todo check if LL is empty or not
        if(head == NULL) {
            head = tail = newNode;
        }

        else {
            newNode -> next = head; //~ point newNode of next to head for connection

            head = newNode; //~ update head pointer to newNode
        }

        std :: cout << "\nvalue : " << val << " push on front succesfully";
        size++;
    }

    //^ function for pushback
    void pushBack(int val) {

        Node* newNode = new Node(val);

        //todo if lL is empty?
        if(head == NULL) {
            head = tail = newNode;
        }
        else {
            tail -> next = newNode;
            tail = newNode;
        }
        std :: cout << "\nvalue : " << val << " push on back succesfully";
        size++;
    }

    //^ insert at a position in LL
    void insert(int val, int pos) {
        if(pos < 0) {
            std :: cout << "invalid position!\n";
            return;
        }

        if(pos == 0) {
            pushFront(val);
            return;
        }

        Node* temp = head;

        for(int i=0; i<pos-1; i++) {
            temp = temp -> next;
        }
    
        Node* newNode = new Node(val);

        //~ assign next of temp to next of newNode
        newNode -> next = temp -> next;

        //~ the next of temp is pointing to newNode
        temp -> next = newNode;

        std :: cout << "\nvalue : " << val << " inserted at" << "position " << pos << "succesfully";
        size++;
    }

    //^ function for pop front
    void popFront() {

        if(head == NULL) {
            std :: cout << "List is already empty!\n";
            return;
        }

        Node* temp = head;
        head = head -> next;
        temp -> next = NULL;
        delete temp;

        std :: cout << "front value deleted succesfully";
        size--;
    }

    //^ function for pop back
    void popBack() {
        if(head == NULL) {
            std :: cout << "list is empty";
            return;
        }

        Node* temp = head;

        while(temp -> next != tail) {
            if(temp == NULL) {
                std :: cout << "invalid position\n";
                return;
            }

            temp = temp -> next;
        }

        temp -> next = NULL;
        delete tail;
        tail = temp;

        std :: cout << "back value deleted succesfully";
        size--;        
    }

    //^ funtion to print LL
    void printLL() {

        Node* temp = head; //~ initialize temp from head(start)

        std :: cout << "\n\n";
        while(temp != NULL) {
            std :: cout << temp -> data << " -> ";
            temp = temp -> next;
        }
        std :: cout << "NULL\nsize :    " << size << "\n\n";
    }

    //^ search in linked list
    void searchLL() {
        Node* temp = head;

        int key;
        std :: cout << "enter target :  ";
        std :: cin >> key;

        int pos = 0;
        while(temp != NULL) {
            if(temp -> data == key) {
                std :: cout << "target found at position :  " << pos << "\n";
            }
            temp = temp -> next;
            pos ++;
        }
    }

    //^ function for printing (with structure)
    void printLinkedList() {
        Node* temp = head;

        std :: cout << "\nLinked List : \n";
        // print top border for all nodes
        while (temp != nullptr)
        {
            std :: cout << "+------+     ";
            temp = temp->next;
        }
        std :: cout << std :: endl;

        // print data inside each node
        temp = head;
        while (temp != nullptr)
        {
            std :: cout << "|  " << temp->data;
            if (temp->data < 10) std :: cout << "   ";  // spacing for single digits
            else if (temp->data < 100) std ::  cout << "  ";
            else std :: cout << " ";
            std :: cout << "| --> ";
            temp = temp->next;
        }
        std :: cout << "NULL" << std :: endl;

        // print bottom border for all nodes
        temp = head;
        while (temp != nullptr)
        {
            std :: cout << "+------+     ";
            temp = temp->next;
        }
        std :: cout << std :: endl;
    }

    //^ function for printing with address
    void printList() {

        Node* temp = head;

        std :: cout << "\n=== Linked List Structure ===\n\n";

        while (temp != nullptr)
        {
            // print top border
            std :: cout << "+----------------------------------------+\n";

            // print data and next pointer (address)
            std :: cout << "| data: " << std :: setw(3) << temp->data
                << " | next: " << temp->next << " |\n";

            // print bottom border
            std :: cout << "+----------------------------------------+\n";

            // print arrow to next node
            if (temp->next != nullptr)
                std :: cout << "              |\n              v\n";
            else
                std :: cout << "              |\n             NULL\n";

            // move to next node
            temp = temp->next;
        }

        std :: cout << std :: endl;
    }

    //^ reverse Linked List : leetcode 206
    void reverse() {

        //! create three pointers
        Node* prev = NULL;
        Node* crt = head;
        Node* next = NULL;

        //? 4 steps to reverse a LL
        while(crt != NULL) {
            //* 1) make next = crt -> next
            next = crt -> next;

            //* 2) set crt -> next = prev
            crt -> next = prev;

            //* 3) update prev to crt
            prev = crt;

            //* 4) update crt to next
            crt = next;

        }
        head = prev; //~ updating head
    }

    //^ middle of linked list : leetcode 876
    void middle() {

        Node* temp = head;
        int mid  = size/2 +1;
        
        for(int i=1; i<mid; i++) {
            temp = temp -> next;
        }

        while(temp != NULL) {
            std :: cout << temp -> data << " ";
            temp = temp -> next;
        }
        std :: cout << "\n";

    }

    //^ middle of LL (opttimized using slow & fast pointers)
    void middleSF() {
        Node* slow = head;
        Node* fast = head;

        while(fast != NULL && fast -> next != NULL) {
            slow = slow -> next;
            fast = fast -> next -> next;
        }

        std :: cout << "middle node : " << slow -> data;
    }

    //^ cycle/loop in LL : leetcode 141
    bool cycleLL() {

        Node* slow = head;
        Node* fast = head;

        while(fast != NULL && fast -> next != NULL) {
            
            slow = slow -> next;
            fast = fast -> next -> next;
            if(slow == fast) {
                return true;
            }
        }
        return false;
    }

    //^ detect cycle/ loop in LL : leetcode 142
    Node *detectCycle() {

        Node* slow = head;
        Node* fast = head;
        bool isCycle = false;

        while(fast != NULL && fast -> next != NULL) {
            
            slow = slow -> next;
            fast = fast -> next -> next;
            if(slow == fast) {
                isCycle = true;
                break;
            }
        }
        if(!isCycle) {
            return NULL;
        }

        slow = head;
        Node* prev = NULL;
        while(slow != fast) {
            slow = slow -> next;
            prev = fast;
            fast = fast -> next;
        }

        prev -> next = NULL;
        return slow;
    }

    //^ merge two sorted lists : leetcode 21
    void mergeList(Node* head1, Node* head2) {

        SinglyLinkedList sorted;

        //* sort nodes based on data 
        while(head1 != NULL && head2 != NULL) {

            if((head1 -> data) <= (head2 -> data)) {
                sorted.pushBack(head1 -> data);
                head1 = head1 -> next;
            }
            
            else {
                sorted.pushBack(head2 -> data);
                head2 = head2 -> next;
            }
        }

        //* sort remaining nodes
        while(head1 != NULL) {
            sorted.pushBack(head1 -> data);
            head1 = head1 -> next;
        }

        while(head2 != NULL) {
            sorted.pushBack(head2 -> data);
            head2 = head2 -> next;
        }

        sorted.printLinkedList();
    }

    //* merge LL using recrusion
    void mergeLL_rec(Node* head1, Node* head2, SinglyLinkedList& sorted) {


        if(head1 == NULL && head2 == NULL) {
            sorted.printLinkedList();
            return;
        }

        if(head1 == NULL) {
            sorted.pushBack(head2->data);
            mergeLL_rec(NULL, head2->next, sorted);
        }

        else if(head2 == NULL) {
            sorted.pushBack(head1->data);
            mergeLL_rec(head1->next, NULL, sorted);
        }

        else if((head1 -> data) <= (head2 -> data)) {
            sorted.pushBack(head1 -> data);
            mergeLL_rec(head1 -> next, head2, sorted);
        }

        else {
            sorted.pushBack(head2 -> data);
            mergeLL_rec(head1, head2 -> next, sorted);
        }
    }

    //^ copy list with random pointer : leetcode 138
    void copyLL() {

        SinglyLinkedList copy;

        Node* newHead = new Node(head -> data);
        copy.pushBack(newHead -> data);

        //* two pointers for traversing old and new LL
        Node* oldTemp = head -> next;
        Node* newTemp = newHead;

        while(oldTemp != NULL) {
            Node* copyNode = new Node(oldTemp -> data);
            copy.pushBack(copyNode -> data);

            newTemp -> next = copyNode;

            oldTemp = oldTemp -> next;
            newTemp = newTemp -> next;
        }

        copy.printLinkedList();
    }

    bool hasCycle(ListNode *head) {
        
        //^ map for tracking visited
        std :: unordered_map<ListNode*, bool> visited;

        ListNode* temp = head;
        while(temp != NULL) {
            visited[temp] = false;
            temp = temp -> next;
        }

        ListNode* it = head;
        while(it != NULL) {
            visited[it] = true;

            if(visited[it->next] == true) {
                return true;
            }
            it = it -> next;
        }
        return false;
    }


    //^ add two linked lists 
    void addLL(Node* head1, Node* head2) {
        SinglyLinkedList sum;

        while(head1 != NULL && head2 != NULL) {
            int val = (head1 -> data) + (head2 -> data);

            if(val < 10) {
                sum.pushBack(val);
            }
            else {
                sum.pushBack(val % 10);
            }

            head1 = head1 -> next;
            head2 = head2 -> next;
        }
        sum.printLinkedList();
    }

    //^ add two numbers : leetcode 2
    void addTwo() {
        
    }

    //^ palindrome linked list : leetcode 234

    //todo   7 8 6 5 6 8 7
    void isPalindrome(SinglyLinkedList list) {
        SinglyLinkedList copy;

        Node* temp = list.getHead();
        while(temp != NULL) {
            copy.pushBack(temp -> data);
            temp = temp -> next;
        }

        list.reverse();

        Node* h1 = copy.getHead();
        Node* h2 = list.getHead();

        bool palind = true;
        while(h1 != NULL && h2 != NULL) {
            if((h1 -> data) != (h2 -> data)) {
                palind = false;
                break;
            }
            h1 = h1 -> next;
            h2 = h2 -> next;
        }
        if(palind) {
            std :: cout << "\n\npalindrome";
        }
        else {
            std :: cout << "\n\nnot palindrome";
        }
    }

    //^ reverse nodes in k-Group
    Node* reverseKgroups(Node* h,int k) {
        SinglyLinkedList revK;

        //* check if k nodes exist in our LL
        Node* temp = h;
        int cnt = 0;
        while(cnt < k) {

            if(temp == NULL) {
                return h;
            }
            temp = temp -> next;

        }

        //& recursively call for rest of LL
        Node* prevNode = reverseKgroups(temp,k);

        //* update temp
        temp = h; cnt = 0;

        //& reverse current group
        while(cnt < k) {
            Node* next = temp -> next;
            temp -> next = prevNode;

            prevNode = temp;
            temp = next;

            cnt++;
        }
        return prevNode;
    }

    //^ remove duplicate from sorted list
    void removeDupl() {

        Node* temp = head;
        
        while(temp != NULL && (temp -> next) != NULL ) {

            if((temp-> data) == ((temp -> next) -> data) && temp -> next != NULL) {

                Node* dupl = temp -> next;
                temp -> next = dupl -> next;
                dupl -> next = NULL;

                std :: cout << "\nduplicate " << dupl -> data <<  " removed...\n";
            }

            temp = temp -> next;
        }
    }

    //^ swap nodes in pairs : leetcode 24
    Node* swapNodes(Node* h) {

        //* check if only one or zero nodes in LL
        if(h == NULL || h -> next == NULL) {
            return h;
        }

        //* creating pointers for traversal & connection
        Node* first = head;
        Node* second = head -> next;

        Node* prev = NULL; 

        //& loop for rearranging connections
        while(first != NULL && second != NULL) {
            Node* third = second -> next;

            //todo reverse connections
            second -> next = first;
            first -> next = third;

            //todo check if prev is NULL
            if(prev != NULL) {
                prev -> next = second;
            }
            else {
                h = second;
            }

            //todo update values
            prev = first;
            first = third;
            if(third != NULL) {
                second = third -> next;
            }
            else {
                second = NULL;
            }
        }
        return h;
    }

    //^ LRU cache : leetcode 146
    
};

class D_Node {
public:

    int data;
    D_Node* next;
    D_Node* prev;
    D_Node* child;

    //^ constructor
    D_Node(int val) {
        data = val;
        prev = next = child = NULL;
    }

};

class DoublyLinkedList {

    D_Node* head;
    D_Node* tail;

public:

    //^ constructor
    DoublyLinkedList() {
        std :: cout << "Doubly Linked List Created!\n";
        head = tail = NULL;
    }

    D_Node* getHead() {
        return head;
    }

    //^ push front
    void pushFront(int val) {

        //! creating new node
        D_Node* newNode = new D_Node(val);

        //todo check if LL is empty or not
        if(head == NULL) {
            head = tail = newNode;
        }

        else {
            newNode -> next = head; //~ connect newNode to head

            head -> prev = newNode; //~ connect head to newNode

            head = newNode; //~ update head
        }
        std :: cout << "\nvalue : " << val << " pushed on front";
    }

    //^ push back function
    void pushBack(int val) {

        D_Node* newNode = new D_Node(val);

        if(head == NULL) {
            head = tail = newNode;
        }

        else {
            tail -> next = newNode;
            newNode -> prev = tail;

            tail = newNode;
            tail -> next = NULL;
        }
        std :: cout << "\nvalue : " << val << " pushed on back";
    }

    void popFront() {

        if(head == NULL) {
            std :: cout << "\nLinked List is empty";
            return;
        }

        D_Node* temp = head;
        head = head -> next;
        
        if(head == NULL) {
            head -> prev = NULL;
        }

        temp -> next = NULL;
        delete temp;

        std :: cout << "\nfront value deleted";
    }    

    void popback() {

        if(head == NULL) {
            std :: cout << "\nLinked List is empty";
            return;
        }

        D_Node* temp = tail;

        tail = tail -> prev;

        if(tail != NULL) {
            tail -> next = NULL;
        }

        temp -> prev = NULL;
        delete temp;

        std :: cout << "\nback value deleted";
    }

    //^ print DLL
    void printDLL() {

        D_Node* temp = head;
        std :: cout << "\n\nDoubly Linked List :    \nNULL <=> ";
        while(temp != NULL) {
            std :: cout << temp -> data << " <=> ";
            temp = temp -> next;
        }
        std :: cout << "NULL\n";

    }

    //^ Push a node at the back of DLL, optionally attach a child list
    void pushBackWithChild(int val, D_Node* childHead = NULL) {
        
        //* Create new node
        D_Node* newNode = new D_Node(val);

        //* If list is empty, initialize head and tail
        if(head == NULL) {
            head = tail = newNode;
        } 
        else {
            //* Link newNode after tail
            tail->next = newNode;
            newNode->prev = tail;

            //* Update tail
            tail = newNode;
        }

        //* Attach child if provided
        if(childHead != NULL) {
            newNode-> child = childHead;
        }

        std::cout << "\nvalue : " << val << " pushed on back";
        if(childHead != NULL) std::cout << " with child attached";

    }

    static void printMultiLevelDLL(D_Node* node, int level = 0) {
        D_Node* temp = node;

        while(temp != NULL) {
            // Indent based on level
            for(int i = 0; i < level; i++) std::cout << "    ";

            // Print current node's data
            std::cout << temp->data;

            // If child exists, print arrow and recurse
            if(temp->child != NULL) {
                std::cout << " ↓\n";
                printMultiLevelDLL(temp->child, level + 1);
            } else {
                std::cout << "\n";
            }

            temp = temp->next;
        }

        if(level == 0) std::cout << "⇉ End of multilevel DLL\n";
    }

    //^ flatten doubly LL : leetcode 430 (recursion)
    D_Node* flatten(D_Node* h) {
        if(h == NULL) return h;

        D_Node* crt = h;

        while(crt != NULL) {
            if(crt -> child != NULL) {
                //& flatten child nodes
                D_Node* next = crt -> next;
                crt -> next = flatten(crt -> child);

                crt -> next -> prev = crt;
                crt -> child = NULL;

                //& find tail
                while(crt != NULL) {
                    crt = crt -> next;
                }

                //& attach tail with next ptr
                if(next != NULL) {
                    crt -> next = next;
                    next -> prev = crt;
                }
            } 
            crt = crt -> next;
        }
    }

};

//! circular linked list : head = tail -> next

class cNode {
public:

    int data;
    cNode* next;

    //^ constructor
    cNode(int val) {
        data = val;
        next = NULL;
    }

};

class CircularLinkedList {

    cNode* head;
    cNode* tail;

public:

    //^ constructor
    CircularLinkedList() {
        std :: cout << "Circular Linked List Created!\n";
        head = tail = NULL;
    }

    //^ insert at head
    void insertH(int val) {

        cNode* newNode = new cNode(val);

        //todo if List is empty
        if(tail == NULL) {
            head = tail = newNode;
            tail -> next = head;
        }

        else {
            newNode -> next = head;
            head = newNode;
            tail -> next = head;
        }
        std :: cout << "value : " << val << " inserted at head\n";
    }

    //^ insert at tail
    void insertT(int val) {
        
        cNode* newNode = new cNode(val);

        //todo if list is empty
        if(head == NULL) {
            head = tail = newNode;
            tail -> next = head;
        }

        else  {
            newNode -> next = head;
            tail -> next = newNode;
            tail = newNode;
        }
    }

    //^ delete at head
    void deleteHead() {

        //* if list is empty
        if(head == NULL) {
            std :: cout << "list is empty\n";
            return;
        }

        //* single Node case
        if(head == tail) {
            delete head;
            head = tail = NULL;
        }

        cNode* temp = head; //~ store address of head
        head = head -> next; //~ update head
        tail -> next = head; //~ circular connection
        temp -> next = NULL; //~ break the connection
        delete temp; //~ delete temp (1st node)

    }

    //^ delete at tail
    void deleteTail() {

        //* if list is empty
        if(head == NULL) {
            std :: cout << "list is empty\n";
            return;
        }

        //* single Node case
        if(head == tail) {
            delete head;
            head = tail = NULL;
        }


        cNode* temp = tail; //~ store address of tail
        //& loop for prev node
        cNode* prev = head;
        while(prev -> next != tail) {
            prev = prev -> next;
        }
        tail = prev; //~ update tail
        tail -> next = head; //~ circular connection
        temp -> next = NULL; //~ break connection
        delete temp; //~ delete last node
        
    }

    //^ travese on circular linked list
    void printCLL() {

        if(head == NULL) {
            std :: cout << "list is empty!\n";
            return;
        }

        std :: cout << "\n\n" << head -> data << " -> ";

        cNode* temp = head -> next;
        while(temp != head) {

            std :: cout << temp -> data << " -> ";
            temp = temp -> next;

        }
        std :: cout << temp -> data << std :: endl;

    }
};

int main() {

    std :: cout << "\n";

    SinglyLinkedList list;

    list.pushBack(10);
    list.pushBack(20);
    list.pushBack(30);
    list.pushBack(40);
    list.pushBack(50);
    list.pushBack(60);

    list.printLinkedList();

    list.;

    
    list.printLinkedList();

    std :: cout << "\n\n";

    return 0;
    
}