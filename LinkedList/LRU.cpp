class LRU
{
public:
    class Node
    {
    public:
        int val;
        int key;
        Node *prev;
        Node *next;
        Node(int v, int k)
        {
            val = v;
            key = k;
        }
    };
    int cap;
    // hash map stores key and address of the Node
    unordered_map<int, Node *> m;
    Node *head = new Node(-1, -1);
    Node *tail = new Node(-1, -1);
    LRU(int capacity)
    {
        cap = capacity;
        head->next = tail;
        tail->prev = head;
    }
    // add a node after head
    void addNode(Node *node)
    {
        Node *temp = head->next;
        head->next = node;
        node->next = temp;
        node->prev = head;
        temp->prev = node;
    }
    // delete a node
    void deleteNode(Node *node)
    {
        Node *nodePrev = node->prev;
        Node *nodeNext = node->next;
        nodePrev->next = nodeNext;
        nodeNext->prev = nodePrev;
    }
    int get(int key)
    {
        // check if present in hashmap
        if (m.count(key))
        {
            Node *address = m[key];
            int answer = address->val;
            m.erase(key);
            deleteNode(address);
            addNode(address);
            m[key] = head->next;
            return answer;
        }
        return -1;
    }
    void put(int key, int value)
    {
        // if present already delete and move to the front
        if (m.count(key))
        {
            Node *address = m[key];
            m.erase(key);
            deleteNode(address);
        }
        // if full delete the lru
        if (m.size() == cap)
        {
            int k = tail->prev->key;
            m.erase(k);
            deleteNode(tail->prev);
        }
        // add the node
        addNode(new Node(key, value));
        m[key] = head->next;
    }
};