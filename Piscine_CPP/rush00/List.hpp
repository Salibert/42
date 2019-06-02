#ifndef CPP_LIST_H
#define CPP_LIST_H

#include "GameEntities.hpp"

class List {

public:
    struct node
    {
        GameEntities *data;
        node *next;
    };
    List(void);
    List(List const &src);
    ~List(void);
    List &operator=(List const &rhs);

    int len(List *list);
    node *getHead(void) const;
    node *getTail(void) const;
    void setHead(List::node * node);
    void createNode(GameEntities *value);
    void display();
    node* deleteNode(node* node);
    void delete_first();
    void delete_position(int pos);
    bool updatePlayer(GameEntities & player);
    void printList(WINDOW *win) const;
    void updateList(List *list);
    GameEntities * getRandomShooter(WINDOW *win) const;

private:
    node *_head;
    node *_tail;
};

#endif