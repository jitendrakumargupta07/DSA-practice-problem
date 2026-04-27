class LRUCache {
private: 
    struct Node{
      int key;
      int val;
      Node* next;
      Node* prev;

      Node(int key, int val) : key(key), val(val), 
      next(nullptr), prev(nullptr) {}
    };  
    unordered_map<int, Node*> map;
    Node* MRU;
    Node* LRU;
    int capacity;
    void addNode(Node* newNode){
      Node* tmp = MRU->next;
      MRU->next = newNode;
      newNode->prev = MRU;
      newNode->next = tmp;
      tmp->prev = newNode;
    }
    void deleteNode(Node* node){
      Node* prev = node->prev;
      Node* next = node->next;
      prev->next = next;
      next->prev = prev;
    }
public:
    LRUCache(int capacity) {
      this->capacity = capacity;
      map = unordered_map<int, Node*>();
      MRU = new Node(-1, -1);
      LRU = new Node(-1, -1);
      MRU->next = LRU;
      LRU->prev = MRU; 
    }
    
    int get(int key) {
        if(map.find(key) == map.end()){
          return -1;
        }
        put(key, map[key]->val);
        return map[key]->val;
    }
    
    void put(int key, int value) {
        if(map.find(key) != map.end()){
           Node* node = map[key];
           deleteNode(node);
           node->val=value;
           addNode(node);
           map[key]=MRU->next;
        }
        else
        {
          if(map.size() == capacity){
            Node* prev = LRU->prev;
            deleteNode(prev);
            map.erase(prev->key);
            delete prev;
          }
          Node* newNode = new Node(key, value);
          addNode(newNode);
          map[key] = MRU->next;
        }
    }
};