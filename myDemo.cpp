#include <iostream>
#include "sources/MagicalContainer.hpp"

using namespace ariel;
using std::cout;
using std::cin;
using std::endl;

int main()
{
    MagicalContainer container;
    int size = 0;
    int currNum;

    cout << "How many elements would you like to put in the container?" << endl;
    cout << "Your answer: "; cin >> size;

    for(int i = 0; i < size; i++)
    {
        cout << "[" << i+1 << "] enter a number: "; cin >> currNum;
        container.addElement(currNum);
    }

    cout << "Your container contains " << container.size() << " elements." << endl;

    MagicalContainer::AscendingIterator asc_it(container);
    for(auto it = asc_it.begin(); it != asc_it.end(); ++it)
    {
        cout << *it << " ";
    }
    cout << endl;

    MagicalContainer::SideCrossIterator sdc_it(container);
    for(auto it = sdc_it.begin(); it != sdc_it.end(); ++it)
    {
        cout << *it << " ";
    }
    cout << endl;

    MagicalContainer::PrimeIterator prm_it(container);
    for(auto it = prm_it.begin(); it != prm_it.end(); ++it)
    {
        cout << *it << " ";
    }
    cout << endl;

    return 0;
}
