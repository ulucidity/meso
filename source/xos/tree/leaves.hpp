//////////////////////////////////////////////////////////////////////////
/// Copyright (c) 1988-2024 $organization$
///
/// This software is provided by the author and contributors ``as is'' 
/// and any express or implied warranties, including, but not limited to, 
/// the implied warranties of merchantability and fitness for a particular 
/// purpose are disclaimed. In no event shall the author or contributors 
/// be liable for any direct, indirect, incidental, special, exemplary, 
/// or consequential damages (including, but not limited to, procurement 
/// of substitute goods or services; loss of use, data, or profits; or 
/// business interruption) however caused and on any theory of liability, 
/// whether in contract, strict liability, or tort (including negligence 
/// or otherwise) arising in any way out of the use of this software, 
/// even if advised of the possibility of such damage.
///
///   File: leaves.hpp
///
/// Author: $author$
///   Date: 1/2/2024
//////////////////////////////////////////////////////////////////////////
#ifndef XOS_TREE_LEAVES_HPP
#define XOS_TREE_LEAVES_HPP

#include "xos/tree/range.hpp"

namespace xos {
namespace tree {

/// class leavest
template <class TLeaf, class TExtends = ::std::list<TLeaf*>, class TImplements = implement>
class exported leavest: virtual public TImplements, public TExtends {
public:
    typedef TImplements implements;
    typedef TExtends extends;
    typedef leavest derives;

    typedef TLeaf leaf_t;

    /// constructor / destructor
    leavest() {
    }
    virtual ~leavest() {
    }
private:
    leavest(const leavest &copy): extends(copy) {
    }
public:
    
    /// push... / pop... / queue... / pull...
    virtual leaf_t* push_leaf(leaf_t* first) {
        if (first) { this->push_front(first); }
        return first;
    }
    virtual leaf_t* pop_leaf() {
        leaf_t* first = 0;
        if (!(this->empty())) {
            first = this->front();
            this->pop_front();
        }
        return first;
    }
    virtual leaf_t* queue_leaf(leaf_t* last) {
        if (last) { this->push_back(last); }
        return last;
    }
    virtual leaf_t* pull_leaf() {
        leaf_t* last = 0;
        if (!(this->empty())) {
            last = this->back();
            this->pop_back();
        }
        return last;
    }

    /// delete...
    virtual void delete_all() {
        for (auto l: *this) {
            if (l) {
                delete l;
                l = 0;
            }
        }
        this->clear();
    }

protected:
}; /// class leavest
///typedef leavest<> leaves;

} /// namespace tree 
} /// namespace xos 

#endif /// ndef XOS_TREE_LEAVES_HPP
