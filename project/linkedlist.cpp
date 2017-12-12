#include  "linkedlist.h"
#include <stdlib.h>
#include <cstring>

/////////////////////////////////////////
// Node(Base)
Node::Node(Node* next, NodeType node)
:pNext(next), node_type(node)
{
    
}

/////////////////////////////////////////
// IntegerNode(Derived) => Node값들을 받아옴. Integer값으로..
IntegerNode::IntegerNode()
:Node(nullptr, INT_NODE)
{
    
}

IntegerNode::IntegerNode(int val, Node* next)
:Node(next, INT_NODE), value(val)
{
    
}

int IntegerNode::get_value()
{
    return value;
}

void IntegerNode::set_value(int val)
{
    value = val;
}

/////////////////////////////////////////
// StringNode(Derived) => Node값들을 받아오고, String값으로..
StringNode::StringNode()
:Node(nullptr, STRING_NODE)
{
    
}

StringNode::StringNode(char* val, Node* next)
:Node(next, STRING_NODE)
{
    value = new char[strlen(val)+1];
    strcpy(value, val);
    value[strlen(val)] = '\0';
}

StringNode::~StringNode()
{
    delete []value;
}

char* StringNode::get_value()
{
    return value;
}

void StringNode::set_value(char* val)
{
    if(value != val)
    {
        delete []value;
        value = new char[strlen(val)+1];
        strcpy(value, val);
        value[strlen(val)] = '\0';
    }
}

/////////////////////////////////////////
// LinkedList Manager (리스트들 관리함)
linkedlist::linkedlist()
:pHead(nullptr)
{
    
}



//앞에 정수값 넣는다. , val은 숫자, pHead는 순서
void linkedlist::InsertToFront(int val)
{
    IntegerNode* inode = new IntegerNode(val, pHead);
    pHead = inode;
}

//뒤에 정수값 넣는다.
void linkedlist::InsertToBack(int val)
{
    if(isEmpty())
    {
        InsertToFront(val);
    }
    else
    {
        Node* last_node = find_prev_node(nullptr);
        
        IntegerNode* inode = new IntegerNode(val, nullptr);
        last_node->set_next(inode);
    }
}

// 숫자일 시에, 앞부분에서 지운다.
int linkedlist::RemoveFromFront_Integer()
{
    int temp = 0;
    if(!isEmpty())
    {
        Node* cur = pHead;
        IntegerNode* inode = static_cast<IntegerNode*>(cur);
        temp = inode -> get_value();
        
        pHead = cur->get_next();
        
        delete cur;
    }
    return temp;
}

//숫자일 시에, 뒷부분에서 지운다.
int linkedlist::RemoveFromBack_Integer()
{
    int temp = 0;
    if(!isEmpty())
    {
        if(pHead->get_next() == nullptr)
        {
            IntegerNode* inode = static_cast<IntegerNode*>(pHead);
            temp = inode->get_value();
            
            delete inode;
            
            pHead = nullptr;
        }
        else
        {
            Node* last_node = find_prev_node(nullptr);
            Node* prev_node = find_prev_node(last_node);
            prev_node -> set_next(nullptr);
            IntegerNode* inode = static_cast<IntegerNode*>(last_node);
            temp = inode -> get_value();
            
            delete inode;
        }
    }
    return temp;
}

//char값일 시에, 앞부분에 넣는다.
void linkedlist::InsertToFront(char* val)
{
    StringNode* inode = new StringNode(val, pHead);
    pHead = inode;
}

//char일 시에, 뒷부분에 넣는다.
void linkedlist::InsertToBack(char* val)
{
     if(isEmpty())
    {
        InsertToFront(val);
    }
    else
    {
        Node* last_node = find_prev_node(nullptr);
        
        StringNode* inode = new StringNode(val, nullptr);
        last_node->set_next(inode);
    }
}

//char일 시에, 앞부분에 스트링값을 지운다.
char* linkedlist::RemoveFromFront_String()
{
    char* temp;
    return temp;
}

//char일 시에, 뒷부분에서 지운다.
char* linkedlist::RemoveFromBack_String()
{
    char* temp;
    return temp;
}

//빈 리스트면 pHead가 nullptr을 반환한다.
bool linkedlist::isEmpty()
{
    return pHead == nullptr? true:false;
}

//cur값에 pHead를 대입, 그리고 cur값과 next 값이 일치할 시에, 빈 리스트이기에, nullptr값을 반환한다.
//cur 값을 다음 node로 옮겼을 때에, next값과 같지 않거나, cur 값이 nullptr이 아닐 때는 cur를 다음 node로 옮기게 된다.
Node* linkedlist::find_prev_node(Node* next)
{
    Node* cur = pHead;
    if(next == cur)
    {
        return nullptr;
    }
    
    while(cur->get_next() != next && cur != nullptr )
    {
        cur = cur->get_next();
    }
    
    return cur;
}

//linkedlist 내에 값들을 반환한다.
void linkedlist::print(std::ostream& os)
{
    for(Node* cur = pHead; cur != nullptr; cur = cur->get_next())
    {
        if(cur->get_node_type() == INT_NODE)
        {
            IntegerNode* node = static_cast<IntegerNode*>(cur);
            os << node->get_value()<<" ";
        }
        else if(cur->get_node_type() == STRING_NODE)
        {
            StringNode* node = static_cast<StringNode*>(cur);
            os << node -> get_value() << " ";
        }
    }
    os << std::endl;
}

void linkedlist::InsertNextTo(int find_val, int val)
{
    
     if(isEmpty())
    {
        InsertToFront(val);
    }
    
    else{
Node *cur = pHead;
int temp;
IntegerNode* Icur = static_cast<IntegerNode*>(cur);
temp = Icur->get_value();
while(temp != find_val && Icur != nullptr )
    {
        cur = static_cast<Node*>(Icur);
        cur = cur->get_next();
        Icur = static_cast<IntegerNode*>(cur);
        temp = Icur->get_value();
    }
    if (temp == find_val){
    cur = cur->get_next();
    
    Node* cur2 = cur->get_next();
    Node* inode = new IntegerNode(val, cur2);
    Icur->set_next(inode);
    }
    
    else{
        InsertToBack(val);
    }
}
}

void linkedlist::InsertNextTo(char* find_val, char* val)
{
    
}

void linkedlist::RemoveNode(int val)
{
    
}

void linkedlist::RemoveNode(char* val)
{
    
}

Node* linkedlist::find_node(int val)
{
    
}

Node* linkedlist::find_node(char* val)
{
    
}

/*
설명:
pNext => 해당 노드 뒤의 노드.
next => 해당 노드 뒤의 노드를 설정하기 위해서 우리가 넣는 값.(set_next에서 사용)
pHead => 맨 앞에 node(node Type)
*/