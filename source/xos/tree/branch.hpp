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
///   File: branch.hpp
///
/// Author: $author$
///   Date: 1/2/2024
//////////////////////////////////////////////////////////////////////////
#ifndef XOS_TREE_BRANCH_HPP
#define XOS_TREE_BRANCH_HPP

#include "xos/tree/branches.hpp"

namespace xos {
namespace tree {

/// class brancht
template <class TBranch, class TBranches, class TLeaves, class TExtends = extend, class TImplements = implement>
class exported brancht: virtual public TImplements, public TExtends {
public:
    typedef TImplements implements;
    typedef TExtends extends;
    typedef brancht derives;

    typedef TBranch branch_t;
    typedef TBranches branches_t;
    typedef TLeaves leaves_t;
    typedef typename leaves_t::leaf_t leaf_t;

    /// constructor / destructor
    brancht(const brancht &copy): branch_(copy.branch()) {
    }
    brancht(): branch_(0) {
    }
    virtual ~brancht() {
    }

    /// push... / pop... / queue... / pull...
    virtual branch_t* push_branch(branch_t* first) {
        return branches_.push_branch(first);
    }
    virtual branch_t* pop_branch() {
        return branches_.pop_branch();
    }
    virtual branch_t* queue_branch(branch_t* last) {
        return branches_.queue_branch(last);
    }
    virtual branch_t* pull_branch() {
        return branches_.pull_branch();
    }
    virtual branch_t* first_branch() const {
        return branches_.first_branch();
    }
    virtual branch_t* last_branch() const {
        return branches_.last_branch();
    }
    virtual branch_t* set_branch(branch_t* to) {
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
    virtual branches_t& branches() const {
        return (branches_t&)branches_;
    }

    /// push... / pop... / queue... / pull...
    virtual leaf_t* push_leaf(leaf_t* first) {
        return leaves_.push_leaf(first);
    }
    virtual leaf_t* pop_leaf() {
        return leaves_.pop_leaf();
    }
    virtual leaf_t* queue_leaf(leaf_t* last) {
        return leaves_.queue_leaf(last);
    }
    virtual leaf_t* pull_leaf() {
        return leaves_.pull_leaf();
    }
    virtual leaves_t& leaves() const {
        return (leaves_t&)leaves_;
    }

protected:
    branch_t* branch_;
    branches_t branches_;
    leaves_t leaves_;
}; /// class brancht
///typedef brancht<> branch;

} /// namespace tree 
} /// namespace xos 

#endif /// ndef XOS_TREE_BRANCH_HPP
