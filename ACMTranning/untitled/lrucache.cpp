#include "lrucache.h"

LRUCache::LRUCache(int size)
{
    cache_size=size;
    cache_real_size=0;
    p_cache_list_head=new CacheNode();
    p_cache_list_near=new CacheNode();
    p_cache_list_head->next=p_cache_list_near;
    p_cache_list_head->pre=nullptr;
    p_cache_list_near->pre=p_cache_list_head;
    p_cache_list_near->next=nullptr;
}
LRUCache::~LRUCache()
{
    CacheNode *p;
    p=p_cache_list_head->next;
    while(p!=nullptr)
    {
        delete p->pre;
        p=p->next;
    }

    delete p_cache_list_near;

}

void LRUCache::detachNode(CacheNode *node)
{
    node->pre->next=node->next;
    node->next->pre=node->pre;
}

void LRUCache::addToFront(CacheNode *node)
{
    node->next=p_cache_list_head->next;
    p_cache_list_head->next->pre=node;
    p_cache_list_head->next=node;
    node->pre=p_cache_list_head;
}


int LRUCache::getValue(int key)
{
    CacheNode *p=p_cache_list_head->next;
    while(p->next!=nullptr)
    {

        if(p->key == key) //catch node
        {

            detachNode(p);
            addToFront(p);
            return p->value;
        }
        p=p->next;
    }
    return -1;
}

bool LRUCache::putValue(int key,int value)
{
    CacheNode *p=p_cache_list_head->next;
    while(p->next!=nullptr)
    {


        if(p->key == key) //catch node
        {
            p->value=value;
            getValue(key);
            return true;
        }
        p=p->next;
    }


    if(cache_real_size_ >= cache_size_)
    {
        cout << "free" <<endl;
        p=p_cache_list_near->pre->pre;
        delete p->next;
        p->next=p_cache_list_near;
        p_cache_list_near->pre=p;
    }

    p=new CacheNode();//(CacheNode *)malloc(sizeof(CacheNode));

    if(p==nullptr)
        return false;

    addToFront(p);
    p->key=key;
    p->value=value;

    cache_real_size_++;

    return true;
}


void LRUCache::displayNodes()
{
    CacheNode *p=p_cache_list_head->next;

    while(p->next!=nullptr)
    {
        cout << " Key : " << p->key << " Value : " << p->value << endl;
        p=p->next;

    }
    cout << endl;

}
