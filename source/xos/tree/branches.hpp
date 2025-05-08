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
///   File: branches.hpp
///
/// Author: $author$
///   Date: 1/2/2024
//////////////////////////////////////////////////////////////////////////
#ifndef XOS_TREE_BRANCHES_HPP
#define XOS_TREE_BRANCHES_HPP

#include "xos/tree/range.hpp"

namespace xos {
namespace tree {

/// class branchest
template <class TBranch, class TExtends = ::std::list<TBranch*>, class TImplements = implement>
class exported branchest: virtual public TImplements, public TExtends {
public:
    typedef TImplements implements;
    typedef TExtends extends;
    typedef branchest derives;

    typedef TBranch branch_t;
    typedef reverse_ranget<branchest> reverse_range_t;    

    /// constructor / destructor
    branchest() {
    }
    virtual ~branchest() {
    }
private:
    branchest(const branchest &copy): extends(copy) {
    }
public:

    /// push... / pop... / queue... / pull...
    virtual branch_t* push_branch(branch_t* first) {
        if (first) { this->push_front(first); }
        return first;
    }
    virtual branch_t* pop_branch() {
        branch_t* first = 0;
        if (!(this->empty())) {
            first = this->front();
            this->pop_front();
        }
        return first;
    }
    virtual branch_t* queue_branch(branch_t* last) {
        if (last) { this->push_back(last); }
        return last;
    }
    virtual branch_t* pull_branch() {
        branch_t* last = 0;
        if (!(this->empty())) {
            last = this->back();
            this->pop_back();
        }
        return last;
    }
    virtual branch_t* first_branch() const {
        branch_t* first = 0;
        if (!(this->empty())) {
            first = this->front();
        }
        return first;
    }
    virtual branch_t* last_branch() const {
        branch_t* last = 0;
        if (!(this->empty())) {
            last = this->back();
        }
        return last;
    }

    /// delete...
    virtual void delete_all() {
        for (auto b: *this) {
            if (b) {
                delete b;
                b = 0;
            }
        }
        this->clear();
    }

    static reverse_range_t reverse_iterate(branchest& branches) {
        return reverse_range_t(branches);
    }

protected:
}; /// class branchest
///typedef branchest<> branches;

} /// namespace tree 
} /// namespace xos 

#endif /// ndef XOS_TREE_BRANCHES_HPP
