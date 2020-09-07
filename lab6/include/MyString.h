#ifndef MYSTRING_H
#define MYSTRING_H

#include <iostream>
#include <functional>
#include <vector>
#include <map>
#include <set>
#include <iterator>

using namespace std;

class MyString {
public:
    const static int initialBufferSize = 20;
private:
    char arr[initialBufferSize]{};
    string str;
    size_t str_size = 0;
public:
    MyString():str({}) { str.clear(); }
    MyString(const char* text);
    MyString(const string& text);

    auto size() const { return str_size; }
    auto capacity() const { return initialBufferSize + str.capacity(); }
    bool empty() const { return str_size == 0; }

    char& operator[](size_t i);
    const char& operator[](size_t i) const;

    struct iterator {
        typedef forward_iterator_tag iterator_category;
        typedef iterator self_type;
        typedef char value_type;
        typedef char* pointer;
        typedef char& reference;
        typedef size_t difference_type;

        MyString* myString;
        size_t position;

        explicit iterator(MyString& myString, size_t position):myString(&myString), position(position) {}
        self_type& operator++() { position++; return *this; }
        self_type& operator--() { position--; return *this; }
        difference_type operator-(const iterator anotherIt) { return this->position - anotherIt.position; }
        self_type operator+(size_t pos) { position+=pos; return *this; }
        reference operator*() const { return (*myString)[position]; }
        pointer operator->() const { return &(*myString)[position]; }
        bool operator==(const iterator anotherIt) const { return this->position==anotherIt.position; }
        bool operator!=(const iterator anotherIt) const { return this->position!=anotherIt.position; }
    };

    struct const_iterator {
        typedef forward_iterator_tag iterator_category;
        typedef const_iterator self_type;
        typedef const char value_type;
        typedef const char* pointer;
        typedef const char& reference;
        typedef size_t difference_type;

        const MyString* myString;
        size_t position;

        explicit const_iterator(const MyString& myString, size_t position):myString(&myString), position(position) {}
        self_type& operator++() { position++; return *this; }
        self_type& operator--() { position--; return *this; }
        difference_type operator-(const const_iterator& anotherIt) { return this->position - anotherIt.position; }
        self_type operator+(size_t pos) { position+=pos; return *this; }
        reference operator*() const { return (*myString)[position]; }
        pointer operator->() const { return &(*myString)[position]; }
        bool operator==(const const_iterator& anotherIt) const { return this->position == anotherIt.position; }
        bool operator!=(const const_iterator anotherIt) const { return this->position != anotherIt.position; }
    };

    typedef char value_type;
    iterator begin() { return iterator(*this, 0); }
    iterator end() { return iterator(*this, size()); }
    const_iterator begin() const { return const_iterator(*this, 0); }
    const_iterator end() const { return const_iterator(*this, size()); }
    const_iterator cbegin() const { return const_iterator(*this, 0); }
    const_iterator cend() const { return const_iterator(*this, size()); }
    reverse_iterator<iterator> rbegin() { return reverse_iterator(iterator(*this, (int)size())); }
    reverse_iterator<iterator> rend() { return reverse_iterator(iterator(*this, 0)); }
    reverse_iterator<const_iterator> rbegin() const { return reverse_iterator(const_iterator(*this, (int)size())); }
    reverse_iterator<const_iterator> rend() const { return reverse_iterator(const_iterator(*this, 0)); }

    friend ostream& operator<<(ostream& os, const MyString& my_string) { for(size_t i=0; i<my_string.size(); i++) os<<my_string[i]; return os; }
    friend istream& operator>>(istringstream& is, MyString& my_string) { my_string = is.str(); return is; }
    MyString& operator+=(char c);
    MyString& operator+=(const MyString& my_string);
    bool operator==(const MyString& my_string) const;
    bool operator!=(const MyString& my_string) const { return !((*this)==my_string); }
    bool operator<(const MyString& my_string) const;
    explicit operator string() const;

    void clear();
    void trim();
    void push_back(char c);
    void toLower() { transform(begin(), end(), begin(), ::tolower); }
    static MyString generateRandomWord(size_t l);
    set<MyString> getUniqueWords() const;
    bool startsWith(const string& s) const;
    bool endsWith(const string& s) const;
    map<MyString, size_t> countWordsUsage() const;
    MyString join(const vector<MyString>& s) const;
    bool all_of(const function<int(int)>& fn) const { return std::all_of(begin(), end(), fn); }
};


#endif //MYSTRING_H