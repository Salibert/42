#include "List.hpp"
#include <iostream>

List::List(void) : _head(NULL), _tail(NULL) {}

List::List(List const & src) {
    *this = (src);
}

List::~List(void) {}

List & List::operator=(List const & rhs) {
    this->_head = rhs.getHead();
    this->_tail = rhs.getTail();
    return *this;
}

List::node * List::getHead(void) const {
    return this->_head;
}

List::node * List::getTail(void) const {
    return this->_tail;
}

void List::createNode(GameEntities *value)
{
    List::node *temp = new node;
    temp->data = value;
    temp->next = _head;
    _head = temp;
}

void List::display()
{
    List::node * temp = _head;
    while(temp != NULL)
    {
        std::cout << temp->data << "\t";
        temp = temp->next;
    }
}

void List::delete_first()
{
    List::node *temp= _head;
    _head=_head->next;
    delete temp;
}

void List::delete_position(int pos)
{
    List::node *current= _head;
    List::node *previous= NULL;

    for(int i=1;i<pos;i++)
    {
        previous=current;
        current=current->next;
    }
    previous->next=current->next;
}

void List::setHead(List::node * node) {
    this->_head = node;
    return;
}

void List::printList(WINDOW *win) const {
    List::node * temp = _head;
    while(temp != NULL)
    {
        temp->data->print(win);
        temp = temp->next;
    }
}

int List::len(List *list) {
    int i = 0;
    List::node* current = list->getHead();
    while(current != NULL) {
        current = current->next;
        i++;
    }
    return i;
}

List::node* List::deleteNode(List::node* node) {
    List::node* current = _head;
    List::node* previous = NULL;
    if (current == node) {
        this->setHead(current->next);
        if (current->data) {
            delete current->data;
            current->data = NULL;
        }
        delete current;
        current = NULL;
        return this->_head;
    }
    while(current) {
        if (current == node) {
                previous->next = current->next;
                if (current->data) {
                    delete current->data;
                    current->data = NULL;
                }
                delete current;
                current = NULL;
                return previous;
        }
        previous = current;
        current = current->next;
    }
    return NULL;
}

bool List::updatePlayer(GameEntities & player) {
    List::node* current = _head;
    while(current != NULL)
    {
        if (player.checkCollision(*current->data)) {
            if (current->data->getWeapon()->getDamage() >= player.getHp()) {
                current = this->deleteNode(current);
                return false;
            } else {
                player.setTotalScore(current->data->getScore());
                player.setHp(player.getHp() - current->data->getWeapon()->getDamage());
            }
            current = this->deleteNode(current);
            return true;
        }
        if (current)
            current = current->next;
    }
    return true;
}

void List::updateList(List *list) {
    List::node* current = _head;
    List::node* opponent;
    while(current != NULL)
    {
        current->data->move(current->data->getSpeed().x, current->data->getSpeed().y);
        if (current->data->getPosition().y < -20 || current->data->getPosition().y > GameEntities::MAX_Y) {
            current = this->deleteNode(current);
            continue;
        }
        opponent = list->getHead();
        while(opponent != NULL) {
            if (current->data->GameEntities::checkCollision(*opponent->data)) {
                if (current->data->getScore() == 0) {
                    if (current->data->getWeapon()->getDamage() >= opponent->data->getHp()) {
                        current->data->setTotalScore(opponent->data->getScore() * 2);                        
                        opponent = list->deleteNode(opponent);
                    } else {
                        current->data->setTotalScore(opponent->data->getScore());
                        opponent->data->setHp(opponent->data->getHp() - current->data->getWeapon()->getDamage());
                    }
                    current = this->deleteNode(current);
                } else {
                    if (current->data->getHp() <= opponent->data->getWeapon()->getDamage()) {
                        current->data->setTotalScore(opponent->data->getScore() * 2);
                        current = this->deleteNode(current);
                    } else {
                        current->data->setTotalScore(opponent->data->getScore());
                        current->data->setHp(current->data->getHp() - opponent->data->getWeapon()->getDamage());
                    }
                    opponent = list->deleteNode(opponent);
                }
                break;
            }
            opponent = opponent->next;
        }
        if (current)
            current = current->next;
    }
}

GameEntities * List::getRandomShooter(WINDOW *win) const {
    List::node * temp = _head;
    while(temp != NULL)
    {
        if (temp->data->getScore() != 0)
        {
            if ((rand() % 5) == 2)
            {
                return temp->data;
            }
        }
        temp = temp->next;
    }
    return 0;
}