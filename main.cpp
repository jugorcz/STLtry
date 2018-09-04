#include <iostream>
#include <array>
#include <vector>
#include <deque>
using namespace std;


/* SEQUENCE CONTAINERS */
/* array 
 * Arrays are fixed-size sequence containers: they hold a specific number of elements ordered in a strict linear sequence.
 *
 *
 */
void arrayClass()
{
    array<int,5> myArray = {1, 3, 5, 7, 9};
    cout << ".begin() " << *myArray.begin() << endl;  //begin returns iterator 
    //cout << *myArray.end() << endl;  //wrong! out of range 
    auto iterator = myArray.end();
    iterator--;
    cout << ".end() " << *iterator << endl;

    cout << ".rbegin() " << *myArray.rbegin() << endl;
    auto riterator = myArray.rend();
    riterator--;
    cout << ".rend() " << *riterator << endl;

    int size = myArray.size();
    cout << ".size() " << size << endl;

    myArray.at(1)++;
    cout << "myArray.at(1)++ -> " << myArray.at(1) << endl;

    int front = myArray.front();
    cout << ".front() " << front << endl; //front returns reference 
    cout << ".back() " << myArray.back() << endl;
}

void vectorClass()
{
    vector<int> vect;
    for(int i = 0; i < 5; i++) vect.push_back(i);

    vect.resize(2);
    vect.resize(8,100);
    vect.resize(12);

    for(vector<int>::iterator it = vect.begin(); it != vect.end(); ++it)
        cout << " " << *it;
    cout << endl;

    cout << ".capacity() " << vect.capacity() << endl;
    cout << ".size() " << vect.size() << endl;
    cout << ".max_size() " << vect.max_size() << endl;

    vect.shrink_to_fit();
    cout << ".capacity() after .shrink_to_fit() " << vect.capacity() << endl;

    //------------------------------------------------------
    vector<int> vect2;
    vect2.assign(7,100);

    vector<int>::iterator it;
    it = vect2.begin() + 1;

    vector<int> vect3;
    vect3.assign(it, vect2.end() - 1); 

    for(vector<int>::iterator it2 = vect2.begin(); it2 != vect2.end(); ++it2)
        cout << " " << *it2;
    cout << endl;

    it = vect3.begin();
    it = vect3.insert(it, 234);

    cout << ".insert(it, 243) ";
    for(vector<int>::iterator it3 = vect3.begin(); it3 != vect3.end(); ++it3)
        cout << " " << *it3;
    cout << endl;

    vect3.erase(vect3.begin() + 1);
    cout << ".erase(.begin() + 1) ";
    for(vector<int>::iterator it3 = vect3.begin(); it3 != vect3.end(); ++it3)
        cout << " " << *it3;
    cout << endl;
}

/*
 * deque (usually pronounced like "deck") is an irregular acronym of double-ended queue. Double-ended queues are sequence containers with dynamic sizes that can be expanded or contracted on both ends (either its front or its back).
 * While vectors use a single array that needs to be occasionally reallocated for growth, the elements of a deque can be scattered in different chunks of storage, with the container keeping the necessary information internally to provide direct access to any of its elements in constant time and with a uniform sequential interface (through iterators).
 */

void dequeClass()
{
    int tab[] = { 1, 3, 5, 7};
    deque<int> queue(tab, tab + sizeof(tab)/sizeof(int));

    deque<int>::iterator it = queue.begin();
    while(it != queue.end())
        cout << *it++ << " ";
    cout << endl;

    cout << "dque.size() " << queue.size() << endl;
    queue.push_front(1234);

    cout << "dque.push_front(1234) ";
    it = queue.begin();
    while(it != queue.end())
        cout << *it++ << " ";
    cout << endl;

    //epmlace returns: An iterator that points to the newly emplaced element.
    auto it2 = queue.emplace(queue.begin() + 1, 77);
    queue.emplace(it2, 88);
    queue.emplace(queue.end(), 99);

    cout << "dque.enplace() ";
    it = queue.begin();
    while(it != queue.end())
        cout << *it++ << " ";
    cout << endl;


}

int main()
{
    cout << "Hello again!\n";
    arrayClass();
    vectorClass();
    dequeClass();
    return 0;
}