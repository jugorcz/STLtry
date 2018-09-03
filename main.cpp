#include <iostream>
#include <array>
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

int main()
{
    cout << "Hello again!\n";
    arrayClass();
    return 0;
}