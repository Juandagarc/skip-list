#include "skip-list.hh" // Include the header file
#include <iostream> 
#include <cstdlib> // for srand and rand
#include <ctime> // for time

using namespace std;

/**
 * @brief Construct a new Skip Node:: Skip Node object
 * 
 * @param val
 * @param level
 */

SkipNode::SkipNode(int val, int level) : value(val), next(level, nullptr) {}

/**
 * @brief Construct a new Skip List:: Skip List object
 *
 * @param maxLvl
 */

SkipList::SkipList(int maxLvl) : maxLevel(maxLvl), curLevel(1) {
    head = new SkipNode(0, maxLevel);
    srand(time(nullptr));
}

SkipList::~SkipList() {
    SkipNode* cur = head;
    while (cur != nullptr) {
        SkipNode* temp = cur;
        cur = cur->next[0];
        delete temp;
    }
}

int SkipList::randomLevel() {
    int lvl = 1;
    while (((double)rand() / RAND_MAX) < 0.5&& lvl < maxLevel)
        lvl++;
    return lvl;
}

void SkipList::insert(int val) {
    vector<SkipNode*> update(maxLevel, nullptr);
    SkipNode* cur = head;

    for (int i = curLevel - 1; i >= 0; i--) {
        while (cur->next[i] != nullptr && cur->next[i]->value < val)
            cur = cur->next[i];
        update[i] = cur;
    }

    int newNodeLevel = randomLevel();
    if (newNodeLevel > curLevel) {
        for (int i = curLevel; i < newNodeLevel; i++)
            update[i] = head;
        curLevel = newNodeLevel;
    }

    SkipNode* newNode = new SkipNode(val, newNodeLevel);
    for (int i = 0; i < newNodeLevel; i++) {
        newNode->next[i] = update[i]->next[i];
        update[i]->next[i] = newNode;
    }
}

bool SkipList::search(int val) {
    SkipNode* cur = head;
    for (int i = curLevel - 1; i >= 0; i--) {
        while (cur->next[i] != nullptr && cur->next[i]->value < val)
            cur = cur->next[i];
    }
    if (cur->next[0] != nullptr && cur->next[0]->value == val)
        return true;
    return false;
}

void SkipList::display() {
    for (int i = curLevel - 1; i >= 0; i--) {
        SkipNode* cur = head->next[i];
        cout << "Level " << i + 1 << ": ";
        while (cur != nullptr) {
            cout << cur->value << " ";
            cur = cur->next[i];
        }
        cout << endl;
    }
}
