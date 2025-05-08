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
///   File: leaf.hpp
///
/// Author: $author$
///   Date: 1/2/2024
//////////////////////////////////////////////////////////////////////////
#ifndef XOS_TREE_LEAF_HPP
#define XOS_TREE_LEAF_HPP

#include "xos/tree/leaves.hpp"

namespace xos {
namespace tree {

/// class leaft
template <class TBranch, class TExtends = extend, class TImplements = implement>
class exported leaft: virtual public TImplements, public TExtends {
public:
    typedef TImplements implements;
    typedef TExtends extends;
    typedef leaft derives;
    
    typedef TBranch branch_t;

    /// constructor / destructor
    leaft(const leaft &copy): branch_(copy.branch()) {
    }
    leaft(): branch_(0) {
    }
    virtual ~leaft() {
    }

    /// ...branch
    virtual branch_t*& set_branch(branch_t* to) {
        branch_t*& branch = this->branch();
        branch = to;
        return branch;
    }
    virtual branch_t* get_branch() const {
        branch_t* branch = this->branch();
        return branch;
    }
    virtual branch_t*& branch() const {
        return (branch_t*&)branch_;
    }

protected:
    branch_t* branch_;
}; /// class leaft
///typedef leaft<> leaf;

} /// namespace tree 
} /// namespace xos 

#endif /// ndef XOS_TREE_LEAF_HPP
