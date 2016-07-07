/* Copyright (c) 2011 Khaled Mamou (kmamou at gmail dot com)
 All rights reserved.
 
 
 Redistribution and use in source and binary forms, with or without modification, are permitted provided that the following conditions are met:
 
 1. Redistributions of source code must retain the above copyright notice, this list of conditions and the following disclaimer.
 
 2. Redistributions in binary form must reproduce the above copyright notice, this list of conditions and the following disclaimer in the documentation and/or other materials provided with the distribution.
 
 3. The names of the contributors may not be used to endorse or promote products derived from this software without specific prior written permission.
 
 THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 */
#pragma once
#ifndef VHACD_CIRCULAR_LIST_H
#define VHACD_CIRCULAR_LIST_H
#include <stdlib.h>

namespace VHACD
{
    //!    CircularListElement class.
    template <typename T> class CircularListElement
    {
    public:
		CircularListElement(const T& data) {this->_data = data;}
		CircularListElement(void){}
		~CircularListElement(void){}

        T&                                    GetData() { return this->_data; }
        const T&                              GetData() const { return this->_data; }
        CircularListElement<T>*&              GetNext() { return this->_next; }
        CircularListElement<T>*&              GetPrev() { return this->_prev; }
        const CircularListElement<T>*&        GetNext() const { return this->_next; }
        const CircularListElement<T>*&        GetPrev() const { return this->_prev; }        

    private:
        T                                      _data;
        CircularListElement<T>*                _next; 
        CircularListElement<T>*                _prev;

		CircularListElement(const CircularListElement& rhs);
    };

    //!    CircularList class.
    template <typename T> class CircularList
    {
    public:
		CircularList()
		{ 
			this->_head = 0; 
			this->_size = 0;
		}
		CircularList(const CircularList& rhs);		
		~CircularList(void) { Clear(); }

        auto GetHead() -> CircularListElement<T>*& { return this->_head;}
        auto GetHead() -> const CircularListElement<T>* const { return this->_head; }
        auto IsEmpty() -> bool const { return (this->_size == 0); }
        auto GetSize() -> size_t const { return this->_size; }
        auto GetData() -> const T& const { return this->_head->GetData(); }
        auto GetData() -> T& { return this->_head->GetData();}
        auto Delete() -> bool;
        auto Delete(CircularListElement<T>* element) -> bool;
        auto Add(const T* data = 0) -> CircularListElement<T>*;
        auto Add(const T& data) -> CircularListElement<T>*;
        auto Next() -> bool;
        auto Prev() -> bool;
        auto Clear() -> void { while(Delete());};
        auto operator=(const CircularList& rhs) -> const CircularList&;

    private:
        CircularListElement<T>* _head;        //!< a pointer to the head of the circular list
        size_t					_size;        //!< number of element in the circular list
    };
}
#include "vhacdCircularList.inl"
#endif // VHACD_CIRCULAR_LIST_H