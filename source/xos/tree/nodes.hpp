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
///   File: nodes.hpp
///
/// Author: $author$
///   Date: 1/2/2024
//////////////////////////////////////////////////////////////////////////
#ifndef XOS_TREE_NODES_HPP
#define XOS_TREE_NODES_HPP

#include "xos/tree/range.hpp"

namespace xos {
namespace tree {

/// class nodest
template 
<class TBranch, class TLeaf, class TNode, class TStream, 
 class TExtends = ::std::list<TNode*>, class TImplements = implement>
class exported nodest: virtual public TImplements, public TExtends {
public:
    typedef TImplements implements;
    typedef TExtends extends;
    typedef nodest derives;

    typedef TBranch branch_t;
    typedef TLeaf leaf_t;
    typedef TNode node_t;
    typedef TStream stream_t;

    /// constructor / destructor
    nodest() {
    }
    virtual ~nodest() {
    }
private:
    nodest(const nodest &copy): extends(copy) {
    }
public:

    /// push... / pop... / queue... / pull...
    virtual node_t* push_node(node_t* first) {
        if (first) { this->push_front(first); }
        return first;
    }
    virtual node_t* pop_node() {
        node_t* first = 0;
        if (!(this->empty())) {
            first = this->front();
            this->pop_front();
        }
        return first;
    }
    virtual node_t* queue_node(node_t* last) {
        if (last) { this->push_back(last); }
        return last;
    }
    virtual node_t* pull_node() {
        node_t* last = 0;
        if (!(this->empty())) {
            last = this->back();
            this->pop_back();
        }
        return last;
    }

    /// delete...
    virtual void delete_all() {
        for (auto n: *this) {
            if (n) {
                delete n;
                n = 0;
            }
        }
        this->clear();
    }

    /// write / read
    virtual ssize_t write(stream_t& to) const {
        ssize_t count = 0, amount = 0;
        for (auto n: *this) {
            if (n) {
                if (0 < (amount = n->write(to))) {
                    count += amount;
                } else {
                    if (0 > (amount)) {
                        return amount;
                    }
                }
            }
        }
        return count;
    }
    virtual ssize_t read(node_t& n, stream_t& from) {
        ssize_t count = 0, amount = 0;
        branch_t* b = 0;
        leaf_t* l = 0;
        delete_all();
        do {
            if (0 < (amount = n.read(from))) {
                if ((b = ((branch_t*)n))) {
                    if ((b = b->clone())) {
                        queue_node(b);
                    } else {
                        count = amount = -1;
                    }
                } else {
                    if ((l = ((leaf_t*)n))) {
                        if ((l = l->clone())) {
                            queue_node(l);
                        } else {
                            count = amount = -1;
                        }
                    } else {
                        count = amount = -1;
                    }
                }
            }
        } while (0 < (amount));
        if (0 > (count)) {
            delete_all();
        }
        return count;
    }

protected:
}; /// class nodest
///typedef nodest<> nodes;

} /// namespace tree 
} /// namespace xos 

#endif /// ndef XOS_TREE_NODES_HPP
