#include "MagicalContainer.hpp"

using namespace ariel;


MagicalContainer::PrimeIterator::PrimeIterator(MagicalContainer& container)
    : _container(container)
{
    _stepsNo = 0;
    _pElement = container._primeHead;
};


MagicalContainer::PrimeIterator::~PrimeIterator(){};


MagicalContainer::PrimeIterator::PrimeIterator(PrimeIterator& other)
    : _container(other._container)
{
    *this = other;
};


MagicalContainer::PrimeIterator& MagicalContainer::PrimeIterator::operator=(const PrimeIterator& other)
{
    _container = other._container;
    _pElement = other._pElement;
    _stepsNo = other._stepsNo;

    return *this;
};



MagicalContainer::PrimeIterator& MagicalContainer::PrimeIterator::operator++()
{
    if(_pElement != nullptr)
    {
        _pElement = _pElement->getPrimeNext();
        _stepsNo++;
    }
    else throw std::runtime_error("Cant move over the end");

    return *this;
};


int MagicalContainer::PrimeIterator::operator*()
{
    if(_pElement == nullptr) throw "Ilegal iterator";

    return _pElement->value();
};


bool MagicalContainer::PrimeIterator::operator!=(const PrimeIterator& other) const
{
    return _pElement != other._pElement;
};


bool MagicalContainer::PrimeIterator::operator==(const PrimeIterator& other) const
{
    return !(*this != other);
};


bool MagicalContainer::PrimeIterator::operator>(const PrimeIterator& other) const
{
    return _stepsNo > other._stepsNo;
};


bool MagicalContainer::PrimeIterator::operator<(const PrimeIterator& other) const
{
    return _stepsNo < other._stepsNo;
};


MagicalContainer::PrimeIterator MagicalContainer::PrimeIterator::begin()
{
    return PrimeIterator (_container);
};


MagicalContainer::PrimeIterator MagicalContainer::PrimeIterator::end()
{
    PrimeIterator it(_container);
    it._stepsNo = _container._size;
    it._pElement = nullptr;

    return it;
};
