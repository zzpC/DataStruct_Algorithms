// LRUCache.h: 标准系统包含文件的包含文件，
// 或特定于项目的包含文件。

#pragma once

#include <iostream>

// TODO: 在此处引用程序需要的其他标头。

typedef struct _Node_ {

	int key;    //键  
	int value;  //数据  

	struct _Node_ *next;  //下一个节点  
	struct _Node_ *pre;   //上一个节点  

}CacheNode;

class LRUCache {

public:

	LRUCache(int cache_size = 10);  //构造函数，默认cache大小为10  
	~LRUCache();     //析构函数  


	int getValue(int key);             //获取值  
	bool putValue(int key, int value);  //写入或更新值   
	void displayNodes();               //辅助函数，显示所有节点  


private:

	int cache_size_;                   //cache长度  
	int cache_real_size_;              //目前使用的长度  
	CacheNode *p_cache_list_head;      //头节点指针  
	CacheNode *p_cache_list_near;      //尾节点指针  

	void detachNode(CacheNode *node);  //分离节点  
	void addToFront(CacheNode *node);  //将节点插入到第一个  

};