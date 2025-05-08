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
///   File: find.hpp
///
/// Author: $author$
///   Date: 1/3/2024
//////////////////////////////////////////////////////////////////////////
#ifndef XOS_TREE_FIND_HPP
#define XOS_TREE_FIND_HPP

#include "xos/tree/branch.hpp"

namespace xos {
namespace tree {

/// class findt
template <class TBranch, class TFind, class TExtends = extend, class TImplements = implement>
class exported findt: virtual public TImplements, public TExtends {
public:
    typedef TImplements implements;
    typedef TExtends extends;
    typedef findt derives;

    typedef typename TBranch::leaf_t leaf_t;
    typedef TBranch branch_t;
    typedef TFind find_t;
    
    /// constructor / destructor
    findt(find_t& find, branch_t& b): find_(find) {
        this->search(&b);
    }
    findt(const findt &copy): find_(copy.find()) {
    }
    findt(): find_(this_find_) {
    }
    virtual ~findt() {
    }

    /// ...found...
    virtual branch_t* found(branch_t* b) {
        find_t& find = this->find();
        return find.found(b);
    }
    virtual leaf_t* found(leaf_t* l) {
        find_t& find = this->find();
        return find.found(l);
    }
    virtual find_t& find() const {
        return (find_t&)find_;
    }

protected:
    find_t this_find_, &find_;
}; /// class findt
///typedef findt<> find;

} /// namespace tree 
} /// namespace xos 

#endif /// ndef XOS_TREE_FIND_HPP
