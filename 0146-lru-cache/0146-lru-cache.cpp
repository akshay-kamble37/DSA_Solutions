class Node{
public:
    int key;
    int value;
    Node* next;
    Node* prev;

    Node(int k,int v){
        key = k;
        value = v;
        next = nullptr;
        prev = nullptr;
    }
};

class LRUCache {
public:
    int size;
    unordered_map<int,Node*> mp;
    Node* head = new Node(-1,-1);
    Node* tail = new Node(-1,-1);

    LRUCache(int capacity) {
        size = capacity;
        mp.clear();

        head = new Node(-1,-1);
        tail = new Node(-1,-1);

        head -> next = tail;
        tail -> prev = head;
    }

    void remove(Node* node){
        node->prev->next = node->next;
        node->next->prev = node->prev;
    }

    void addlast(Node* node){
        node -> next = tail;
        node -> prev = tail->prev;

        tail->prev->next = node;
        tail->prev = node;
    }
    
    int get(int key){
        if(mp.find(key) == mp.end()) return -1;
        
        Node* recently = mp[key];

        remove(recently);
        addlast(recently);

        return recently->value;
    }
    
    void put(int key, int value) {
        if(mp.find(key) != mp.end()){

            Node* node = mp[key];
            node->value = value;
            
            remove(node);
            addlast(node);
            return ;

        }else if(mp.size() >= size){

            Node* temp = head ->next ;
            int del = temp->key;

            remove(temp);
            mp.erase(del);

            delete temp;
        }
        Node* new_one = new Node(key,value);
        addlast(new_one);
        mp[key] = new_one;
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */



//  class Node{
// public:
//     int key;
//     int value;
//     Node* prev;
//     Node* next;

//     Node(int k,int v){
//         key = k;
//         value = v;
//         prev = nullptr;
//         next = nullptr;
//     }    
// };


// class LRUCache {
// public:
//     int size;
//     int count = 0;
//     unordered_map<int,Node*> mp;
//     Node* head = new Node(-1,-1);
//     Node* tail = new Node(-1,-1);

//     void add(int k,int val){
//         if(count >= size){
//             if( mp.find(k) != mp.end()){
//                 if(tail -> prev == mp[k]){
//                     mp[k] -> value = val;
//                 }else{
//                     mp[k] -> prev -> next = mp[k] -> next;
//                     mp[k] -> next -> prev = mp[k] -> prev;
//                     mp[k] -> prev = tail -> prev;
//                     tail -> prev -> next = mp[k];
//                     mp[k] -> next = tail;
//                     tail -> prev = mp[k];

//                     mp[k]->value = val;
//                 }
//             }else{
//                 mp.erase(head->next->key);

//                 head->next->key = k;
//                 head->next->value = val;

//                 Node* temp = head->next;

//                 head->next = head->next->next;
//                 head->next->prev = head;
//                 temp -> prev = tail -> prev;
//                 tail -> prev -> next =temp;
//                 temp -> next = tail;
//                 tail -> prev = temp;

//                 mp[k] = temp;
//             }
//         }else{
//             Node* temp = new Node(k,val);

//             temp -> prev = tail -> prev ;
//             tail -> prev -> next = temp;
//             temp -> next = tail;
//             tail -> prev = temp;

//             mp[k] = temp;

//             count++;
//         }
        
//     }


//     LRUCache(int capacity) {
//         size = capacity;
//         mp.clear();
//         head -> next = tail;
//         tail -> prev = head;
//     }

//     int search(int key){
//         mp[key] -> prev -> next = mp[key] -> next;
//         mp[key] -> next -> prev = mp[key] -> prev;
//         mp[key] -> prev = tail -> prev;
//         tail -> prev -> next = mp[key];
//         mp[key] -> next = tail;
//         tail -> prev = mp[key];

//         return mp[key]->value;

//     }
    
//     int get(int key) {
//         if(mp.find(key) == mp.end()) return -1;
//         return search(key);
//     }
    
//     void put(int key, int value) {
//         add(key,value);
//     }
// };

// /**
//  * Your LRUCache object will be instantiated and called as such:
//  * LRUCache* obj = new LRUCache(capacity);
//  * int param_1 = obj->get(key);
//  * obj->put(key,value);
//  */