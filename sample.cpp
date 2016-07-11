#ifndef LINKEDLIST_HPP
#define LINKEDLIST_HPP

#include <stdlib.h>
#include <bits/stdc++.h>

using namespace std;

template <typename Object>
class Linkedlist
{
  private:    
    // The basic doubly linked Linkedlist node.
    // Nested inside of Linkedlist, can be public
    // because the Node is itself private
    struct Node
    {
        Object  _data;
        Node   *_prev;
        Node   *_next;

        Node( const Object & d = Object( ), Node * p = NULL, Node * n = NULL )
          : _data( d ), _prev( p ), _next( n ) { }
    };

  public:




  public:
    Linkedlist( )
      { init( ); }

    ~Linkedlist( )
    {
        clear( );
        delete _head;
        delete _tail;
    }

    Linkedlist( const Linkedlist & rhs )
    {
        init( );
        *this = rhs;
    }

    const Linkedlist & operator= ( const Linkedlist & rhs )
    {
        if( this == &rhs )
            return *this;
        clear( );
        for( const_iterator itr = rhs.begin( ); itr != rhs.end( ); ++itr )
            push_back( *itr );
        return *this;
    }

    // Return iterator representing beginning of Linkedlist.
    // Mutator version is first, then accessor version.
    iterator begin( )
      { return iterator( _head->_next ); }

    const_iterator begin( ) const
      { return const_iterator( _head->_next ); }

    // Return iterator representing endmarker of Linkedlist.
    // Mutator version is first, then accessor version.
    iterator end( )
      { return iterator( _tail ); }

    const_iterator end( ) const
      { return const_iterator( _tail ); }

    // Return number of elements currently in the Linkedlist.
    int size( ) const
      { return _size; }

    // Return true if the Linkedlist is empty, false otherwise.
    bool empty( ) const
      { return size( ) == 0; }

    void clear( )
    {
        while( !empty( ) )
            pop_front( );
    }

    // front, back, push_front, push_back, pop_front, and pop_back
    // are the basic double-ended queue operations.
    Object & front( )
      { return *begin( ); }

    const Object & front( ) const
      { return *begin( ); }

    Object & back( )
      { return *--end( ); }

    const Object & back( ) const
      { return *--end( ); }

    void push_front( const Object & x )
      { insert( begin( ), x ); }

    void push_back( const Object & x )
      { insert( end( ), x ); }

    void pop_front( )
      { erase( begin( ) ); }

    void pop_back( )
      { erase( --end( ) ); }

    // Insert x before itr.
    iterator insert( iterator itr, const Object & x )
    {
        Node *p = itr.current;
        _size++;
        return iterator( p->_prev = p->_prev->_next = new Node( x, p->_prev, p ) );
    }

    // Erase item at itr.
    iterator erase( iterator itr )
    {
        Node *p = itr.current;
        iterator retVal( p->_next );
        p->_prev->_next = p->_next;
        p->_next->_prev = p->_prev;
        delete p;
        _size--;

        return retVal;
    }

    iterator erase( iterator start, iterator end )
    {
        for( iterator itr = start; itr != end; )
            itr = erase( itr );

        return end;
    }

  private:
    int   _size;
    Node *_head;
    Node *_tail;

    void init( )
    {
        _size = 0;
        _head = new Node;
        _tail = new Node;
        _head->_next = _tail;
        _tail->_prev = _head;
    }
};

#endif