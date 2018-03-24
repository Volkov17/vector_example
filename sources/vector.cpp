#include <algorithm>
#include <cassert>

#include "vector.hpp"

vector_t::vector_t()
{
	elements_=nullptr;
	size_=0; 
	capacity_=0;
}

vector_t::vector_t(vector_t const & other)
{
	elements_ = new int [other.capacity_];
	for ( int i =0; i<other.size_; i++)
		elements_[i] = other.elements_[i];
	size_ = other.size_;
 	capacity_ = other.capacity_;
	
}

vector_t & vector_t::operator =(vector_t const & other)
{
	if ( this!= &other){
		if (elements_!=nullptr){
			delete [] elements_;
		}
		elements_=new int[other.capacity_];
		for (int i=0; i<other.size_;i++)
			elements_[i] = other.elements_[i];
		size_ = other.size_;
 		capacity_ = other.capacity_;
	}
	return *this;
}

bool vector_t::operator ==(vector_t const & other) const
{
	if (size_ != other.size_) 
	  return false;  
	for (int i = 0; i < size_; i++) 
		if (elements_[i] != other.elements_[i]) 
			return false;
	return true;					
}

vector_t::~vector_t()
{
	delete [] elements_;
}

std::size_t vector_t::size() const
{
    return size();
}

std::size_t vector_t::capacity() const
{
    return capacity();
}

void vector_t::push_back(int value)
{
	if (capacity_==0){
		capacity_=1;
		size_=1;
		elements_=new int [capacity_];
		elements_[size_-1]=value;
	}
	else 
	{
		if (capacity_==size_){
		vector_t copy( *this );
 		delete [] elements_;
		capacity_ = 2 * capacity_;
 		elements_ = new int [capacity_];
 		for (int i = 0;i < size_;i++ )
 		{
 			this->elements_[i]=copy.elements_[i];
		}
		size_++;		
 		elements_[size_ - 1] = value;
 	}
 	else
 	{
 		size_++;
 		elements_[size_ - 1] = value;
 	}
}

void vector_t::pop_back()
{
	if (size_)
	{
		size_--;
		if (size_ <= ( capacity_ / 4 ))
		{
			capacity_ = capacity_ / 2;
			int * el = new int [capacity_];
			for (size_t i = 0; i < size_; i++)
			{
				el[i] = elements_[i];
			}
			
			delete[]elements_;

			elements_ = el;
		}
	}
	else
	{
		std::cout << "empty";
	}
	
}

int & vector_t::operator [](std::size_t index)
{
	return elements_[0];
}

int vector_t::operator [](std::size_t index) const
{
	return 0;
}

bool operator !=(vector_t const & lhs, vector_t const & rhs)
{
	return true;
}
