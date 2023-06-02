#include "MagicalContainer.hpp"

using namespace ariel;


MagicalContainer::AscendingIterator::AscendingIterator(MagicalContainer& container)
    : _container(container)
{
    _stepsNo = 0;
    _pElement =  _container._head;
};


MagicalContainer::AscendingIterator::~AscendingIterator(){};


MagicalContainer::AscendingIterator::AscendingIterator(AscendingIterator& other)
    : _container(other._container)
{
    *this = other;
};


MagicalContainer::AscendingIterator& MagicalContainer::AscendingIterator::operator=(const AscendingIterator& other)
{
    if(&_container != &other._container) throw std::runtime_error("Containers are not the same");

    _container = other._container;
    _pElement = other._pElement;
    _stepsNo = other._stepsNo;

    return *this;
};


MagicalContainer::AscendingIterator& MagicalContainer::AscendingIterator::operator++()
{
    if(_pElement != nullptr)
    {
        _pElement = _pElement->getAscNext();
        _stepsNo++;
    }
    else throw std::runtime_error("Cant move over the end");

    return *this;
};


int MagicalContainer::AscendingIterator::operator*()
{
    if(_pElement == nullptr) throw "Ilegal iterator";

    return _pElement->value();
};


bool MagicalContainer::AscendingIterator::operator!=(const AscendingIterator& other) const
{
    return _pElement != other._pElement;
};


bool MagicalContainer::AscendingIterator::operator==(const AscendingIterator& other) const
{
    return !(*this != other);
};


bool MagicalContainer::AscendingIterator::operator>(const AscendingIterator& other) const
{
    return _stepsNo > other._stepsNo;
};


bool MagicalContainer::AscendingIterator::operator<(const AscendingIterator& other) const
{
    return _stepsNo < other._stepsNo;
};


MagicalContainer::AscendingIterator MagicalContainer::AscendingIterator::begin()
{
    return AscendingIterator(_container);
};


MagicalContainer::AscendingIterator MagicalContainer::AscendingIterator::end()
{
    AscendingIterator it(_container);
    it._stepsNo = _container._size;
    it._pElement = nullptr;
    return it;
};
