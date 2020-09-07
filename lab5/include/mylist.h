#ifndef MY_LIST_H
#define MY_LIST_H

#include <iterator>
#include <memory>

using namespace std;

template <class T>
class MyList{
protected:
    struct Node{
        T data;
        unique_ptr<Node> next;
    public:
        Node(T data) : data(data), next(nullptr) {}
    };
    unique_ptr<Node> head;
private:
    int list_size;
public:
    MyList():list_size(0), head(nullptr){};
    MyList(const MyList&) = delete;
    MyList & operator=(const MyList&) = delete;
    inline int size() const{ return list_size; }
    inline T front(){ return this->head->data; };
    T pop_front();
    void push_front(T data);
    void remove(T data);
    typedef T value_type;
    class Iterator:public iterator<forward_iterator_tag, int>{
    private:
        Node * node;
    public:
        explicit Iterator():node(this->head){};
        explicit Iterator(Node * node):node(node){};
        Iterator& operator++(){
            if(node!=nullptr) node = node->next.get();
            return *this;
        }
        inline bool operator==(Iterator it) const{ return node == it.node; }
        inline bool operator!=(Iterator it) const{ return node != it.node; }
        T& operator*() const { return node->data; }
        T* operator->() const { return &(node->data); }
    };
    Iterator begin() const{ return Iterator(this->head.get()); }
    Iterator end() const{ return Iterator(nullptr); }
    template <class C>
    friend ostream& operator<<(ostream& os, const MyList<C>& list);
};

template <class T>
T MyList<T>::pop_front(){
    if(head == nullptr)
        throw out_of_range("Poza zakresem!");
    T result = head->data;
    head = move(head->next);
    list_size--;
    return result;
}

template <class T>
void MyList<T>::push_front(T data){
    auto node = make_unique<Node>(data);
    if(head!=nullptr)
        node->next = move(head);
    head = move(node);
    list_size++;
}

template <class T>
void MyList<T>::remove(T data){
    while(head && head->data == data)
        head = std::move(head->next);
    if(head!=nullptr){
        Node *node = head.get();
        while (node->next) {
            if (node->next->data == data)
                node->next = std::move(node->next->next);
            else
                node = node->next.get();
        }
    }
}

template <class T>
ostream& operator<<(ostream &os, const MyList<T>& list){
    for(T data:list) os<<data<< " ";
    return os;
}

#endif // MY_LIST_H