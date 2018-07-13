#ifndef LRUCACHE_H
#define LRUCACHE_H
typedef struct _Node_{

    int key;    //键
    int value;  //数据

    struct _Node_ *next;  //下一个节点
    struct _Node_ *pre;   //上一个节点

}CacheNode;

class LRUCache
{
public:
    LRUCache(int size=10);
    ~LRUCache();
    int getValue(int key);
    bool putValue(int key,int value);
    void displayNodes();

private:
    int cache_size;
    int cache_real_size;
    CacheNode *p_cache_list_head;      //头节点指针
    CacheNode *p_cache_list_near;      //尾节点指针

    void detachNode(CacheNode *node);  //分离节点
    void addToFront(CacheNode *node);  //将节点插入到第一个
};

#endif // LRUCACHE_H
