#ifndef SKIPLIST_HH
#define SKIPLIST_HH

#include <vector>

class SkipNode {
public:
    int value;
    std::vector<SkipNode*> next;

    SkipNode(int val, int level);
};

class SkipList {
private:
    int maxLevel;
    int curLevel;
    SkipNode* head;

    int randomLevel();

public:
    SkipList(int maxLvl);
    ~SkipList();

    void insert(int val);
    bool search(int val);
    void display();
};

#endif
