class Node {
public:
    int key;
    int value;
    Node* next;
    Node* prev;

    Node(int key, int value) {
        this->key = key;
        this->value = value;
        next = prev = nullptr;
    }
};

class LRUCache {
    map<int, Node*> cache;
    Node* head;
    Node* tail;
    int capacity;

public:
    LRUCache(int capacity) {
        cache = map<int, Node*>();
        head = nullptr;
        tail = nullptr;
        this->capacity = capacity;
    }
    
    int get(int key) {
        if (cache.contains(key)) {
            attachStart(detachNode(cache[key]));
            return cache[key]->value;
        }
        return -1;
    }
    
    void put(int key, int value) {
        // cout << "put(" << key << ", " << value << "): ";
        Node* node;
        if (cache.contains(key)) {
            node = cache[key];
            node->value = value;
            attachStart(detachNode(cache[key]));
        } else {
            node = new Node(key, value);
            attachStart(node);
        }
        cache[key] = node;
        if (cache.size() > capacity) {
            cache.erase(tail->key);
            delete detachNode(tail);
        }
        // printList();
    }

private:
    Node* detachNode(Node* node) {
        auto prev = node->prev;
        auto next = node->next;
        if (prev != nullptr) {
            prev->next = next;
        } else {
            head = next;
        }
        if (next != nullptr) {
            next->prev = prev;
        } else {
            tail = prev;
        }
        node->prev = nullptr;
        node->next = nullptr;
        return node;
    }

    void attachStart(Node* node) {
        if (head == nullptr) {
            head = node;
            tail = node;
            return;
        }
        node->next = head;
        if (head != nullptr) {
            head->prev = node;
        }
        head = node;
    }

    void printList() {
        for (auto it = head; it != nullptr; it = it->next) {
            cout << "[" << it->key << ":" << it->value << "]->"; 
        }
        cout << "end\n";
    }
};