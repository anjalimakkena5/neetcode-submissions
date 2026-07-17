class Node{
    public:
    int key;
    int value;
    Node* next;
    Node* prev;
    Node(int key,int value){
        this->key=key;
        this->value=value;
        next=nullptr;
        prev=nullptr;
    }
};
class LRUCache {
public:
    void insertAfterHead(Node* node){
        Node* temp=head->next;
        node->next=temp;
        node->prev=head;
        head->next=node;
        temp->prev=node;

    }
    void deleteNode(Node* node){
        Node* prevNode=node->prev;
        Node* nextNode=node->next;
        prevNode->next=nextNode;
        nextNode->prev=prevNode;
    }
    map<int,Node*>mpp;
    Node* head=new Node(-1,-1);
    Node* tail=new Node(-1,-1);
    int size;
    LRUCache(int capacity) {
        size=capacity;
        head->next=tail;
        tail->prev=head;
    }
    
    int get(int key) {
        if(mpp.find(key)==mpp.end()) return -1;
        Node* node=mpp[key];
        deleteNode(node);
        insertAfterHead(node);
        return node->value;
    }
    
    void put(int key, int value) {
        if(mpp.find(key)!=mpp.end()){
            Node* node=mpp[key];
            node->value=value;
            deleteNode(node);
            insertAfterHead(node);
        }
        else{
            if(mpp.size()==size){
                Node* node=tail->prev;
                mpp.erase(node->key);
                deleteNode(node);

            }
            Node* node=new Node(key,value);
            mpp[key]=node;
            insertAfterHead(node);
        }
    }
};
