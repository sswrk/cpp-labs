#include <stdlib.h>
#include <time.h>
#include <cstring>
#include <iterator>
#include <sstream>
#include "MyString.h"

using namespace std;

MyString::MyString(const char* str):str({}), str_size(strlen(str)) {
    size_t i = 0;
    while(i<strlen(str)) {
        if(i<initialBufferSize)
            arr[i] = str[i];
        else
            this->str+=str[i];
        i++;
    }
}
MyString::MyString(const string& str):str({}), str_size(str.length()) {
    size_t i;
    for(i=0; i<initialBufferSize && i<str.length(); i++)
        arr[i] = str[i];
    if(i>=initialBufferSize)
        this->str += str.substr(initialBufferSize);
}

char& MyString::operator[](size_t i) {
    if(i>=size()) throw out_of_range("Out of range");
    if(i<initialBufferSize) return arr[i];
    return str[i-initialBufferSize];
}

const char& MyString::operator[](size_t i) const {
    if(i>=size()) throw out_of_range("Out of range");
    if(i<initialBufferSize) return arr[i];
    return str[i-initialBufferSize];
}

MyString& MyString::operator+=(char c) {
    if(size()<initialBufferSize)
        arr[size()] = c;
    else
        str+=c;
    str_size++;
    return *this;
}

MyString& MyString::operator+=(const MyString& my_string) {
    for(size_t i=0; i<my_string.size(); i++) {
        if (size() < initialBufferSize)
            arr[size()] = my_string[i];
        else
            str += my_string[i];
        str_size++;
    }
    return *this;
}

bool MyString::operator==(const MyString& my_string) const {
    if(this->size()!=my_string.size()) return false;
    auto it = mismatch(begin(), end(), my_string.begin());
    return (it.first==end());
}

bool MyString::operator<(const MyString& my_string) const {
    auto iterator = mismatch(begin(), end(), my_string.begin(), my_string.end());
    if(iterator.first == end()) return false;
    if(iterator.second == my_string.end()) return true;
    return (*iterator.first<*iterator.second);
}

MyString::operator string() const {
    string result = arr;
    result+=str;
    return result;
}

void MyString::clear() {
    str_size = 0;
    for(int i=0; i<initialBufferSize; i++) arr[i] = '\0';
    str.clear();
}

void MyString::trim() {
    string s;
    iterator it = find_if_not(begin(), end(), ::isspace);
    reverse_iterator rit = find_if_not(rbegin(), rend(), ::isspace);
    s.resize(distance(it, rit.base()));
    copy(it, rit.base(), s.begin());
    *this = s;
}

void MyString::push_back(char c) {
    if(size()<initialBufferSize)
        arr[size()] = c;
    else
        str+=c;
    str_size++;
}

set<MyString> MyString::getUniqueWords() const {
    MyString my_string;
    const_iterator it = begin();
    const_iterator i = find_if(it, end(), ::isalpha);
    advance(it, distance(it, i));
    transform(it, find_if_not(it, end(), ::isalpha), back_inserter(my_string),::tolower);
    advance(it, my_string.size());
    set<MyString> result;
    while(it!=end()) {
        result.emplace(my_string);
        my_string.clear();
        i = find_if(it, end(), ::isalpha);
        advance(it, distance(it, i));
        transform(it, find_if_not(it, end(), ::isalpha), back_inserter(my_string), ::tolower);
        advance(it, my_string.size());
    }
    return result;
}

char random() {
    srand(time(nullptr));
    char a = rand()%26;
    if(rand()%2==0)
        a+=65;
    else
        a+=97;
    return a;
}

MyString MyString::generateRandomWord(size_t l) {
    MyString my_string;
    generate_n(back_inserter(my_string), l, random);
    return my_string;
}

bool MyString::startsWith(const string& s) const {
    const_iterator it = search(begin(), end(), s.begin(), s.end());
    return (it!=end() && it==begin());
}
bool MyString::endsWith(const string& s) const {
    reverse_iterator it = search(rbegin(), rend(), s.rbegin(), s.rend());
    return (it.base()!=begin() && it.base()==end());
}

map<MyString, size_t> MyString::countWordsUsage() const {
    const_iterator it = begin();
    map<MyString, size_t> result;
    while(it!=end()) {
        MyString my_string;
        const_iterator sit = find_if(it, end(), ::isalpha);
        advance(it, distance(it, sit));
        copy(it, find_if_not(it, end(), ::isalpha), back_inserter(my_string));
        advance(it, my_string.size());
        result[my_string]++;
    }
    return result;
}

MyString MyString::join(const vector<MyString>& s) const {
    MyString my_string(s[0]);
    for(size_t i=1; i<s.size(); i++){
        my_string+=*this;
        my_string+=s[i];
    }
    return my_string;
}
