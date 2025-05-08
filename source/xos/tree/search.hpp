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
///   File: search.hpp
///
/// Author: $author$
///   Date: 1/3/2024
//////////////////////////////////////////////////////////////////////////
#ifndef XOS_TREE_SEARCH_HPP
#define XOS_TREE_SEARCH_HPP

#include "xos/tree/find.hpp"
#include "xos/base/logged.hpp"
#include "xos/base/logger.hpp"

namespace xos {
namespace tree {

//////////////////////////////////////////////////////////////////////////
/// class searcht
template <class TBranch, class TExtends = xos::extended::logged, class TImplements = typename TExtends::implements>
class exported searcht: virtual public TImplements, public TExtends {
public:
    typedef TImplements implements;
    typedef TExtends extends;
    typedef searcht derives;

    typedef typename TBranch::leaf_t leaf_t;
    typedef TBranch branch_t;

    /// constructor / destructor
    searcht() {
    }
    virtual ~searcht() {
    }
private:
    searcht(const searcht &copy): extends(copy) {
    }
public:

    /// search... / found...
    virtual void search(branch_t* b) {
    }
    virtual branch_t* found(branch_t* b) { 
        return 0; 
    }
    virtual leaf_t* found(leaf_t* l) { 
        return 0; 
    }

protected:
}; /// class searcht
///typedef searcht<> search;

//////////////////////////////////////////////////////////////////////////
/// class breadth_first_searcht
template 
<class TBranch, class TBranches, class TLeaves, class TSearch = searcht<TBranch>, 
 class TExtends = brancht<TBranch, TBranches, TLeaves, TSearch>, class TImplements = implement>
class exported breadth_first_searcht: virtual public TImplements, public TExtends {
public:
    typedef TImplements implements;
    typedef TExtends extends;
    typedef breadth_first_searcht derives;

    typedef TBranch branch_t;
    typedef TBranches branches_t;
    
    /// constructor / destructor
    breadth_first_searcht() {}
    breadth_first_searcht(branch_t* v) { this->search(v); }
    virtual ~breadth_first_searcht() {}
private:
    breadth_first_searcht(const breadth_first_searcht &copy) {}
public:

    /// search...
    virtual void search(branch_t* v) {
        LOGGER_IS_LOGGED_INFO("if (v) {...");
        if (v) {
            LOGGER_IS_LOGGED_INFO("do {...");
            do {
                LOGGER_IS_LOGGED_INFO("if (this->found(v)) {...");
                if (this->found(v)) { 
                    LOGGER_IS_LOGGED_INFO("break...");
                    break; 
                }
                LOGGER_IS_LOGGED_INFO("for (auto b: v->branches()) {...");
                for (auto b: v->branches()) {
                    LOGGER_IS_LOGGED_INFO("this->queue_branch(b)...");
                    this->queue_branch(b);
                }
                LOGGER_IS_LOGGED_INFO("} while ((v = this->pop_branch()))...");
            } while ((v = this->pop_branch()));
        }
    }

protected:
}; /// class breadth_first_searcht
///typedef breadth_first_searcht<> breadth_first_search;

//////////////////////////////////////////////////////////////////////////
/// class depth_first_searcht
template 
<class TBranch, class TBranches, class TLeaves, class TSearch = searcht<TBranch>, 
 class TExtends = brancht<TBranch, TBranches, TLeaves, TSearch>, class TImplements = implement>
class exported depth_first_searcht: virtual public TImplements, public TExtends {
public:
    typedef TImplements implements;
    typedef TExtends extends;
    typedef depth_first_searcht derives;

    typedef TBranch branch_t;
    typedef TBranches branches_t;
    
    /// constructor / destructor
    depth_first_searcht() {}
    depth_first_searcht(branch_t* v) {this->search(v);
    }
    virtual ~depth_first_searcht() {}
private:
    depth_first_searcht(const depth_first_searcht &copy) {}
public:

    /// search...
    virtual void search(branch_t* v) {
        LOGGER_IS_LOGGED_INFO("if (v) {...");
        if (v) {
            LOGGER_IS_LOGGED_INFO("do {...");
            do {
                LOGGER_IS_LOGGED_INFO("if (this->found(v)) {...");
                if (this->found(v)) { 
                    LOGGER_IS_LOGGED_INFO("...break");
                    break; 
                }
                LOGGER_IS_LOGGED_INFO("for (auto b: branches_t::reverse_iterate(v->branches())) {...");
                for (auto b: branches_t::reverse_iterate(v->branches())) {
                    LOGGER_IS_LOGGED_INFO("this->push_branch(b)...");
                    this->push_branch(b);
                }
                LOGGER_IS_LOGGED_INFO("...} while ((v = this->pop_branch()))");
            } while ((v = this->pop_branch()));
        }
    }

protected:
}; /// class depth_first_searcht
///typedef depth_first_searcht<> depth_first_search;

//////////////////////////////////////////////////////////////////////////
/// class depend_first_searcht
template 
<class TBranch, class TBranches, class TLeaves, class TSearch = searcht<TBranch>, 
 class TExtends = brancht<TBranch, TBranches, TLeaves, TSearch>, class TImplements = implement>
class exported depend_first_searcht: virtual public TImplements, public TExtends {
public:
    typedef TImplements implements;
    typedef TExtends extends;
    typedef depend_first_searcht derives;

    typedef TBranch branch_t;
    typedef TBranches branches_t;
    
    /// constructor / destructor
    depend_first_searcht() {}
    depend_first_searcht(branch_t* v) {this->search(v);
    }
    virtual ~depend_first_searcht() {}
private:
    depend_first_searcht(const depend_first_searcht &copy) {}
public:

    /// search...
    virtual void search(branch_t* v) {
        LOGGER_IS_LOGGED_INFO("if (v) {...");
        if (v) {
            branches_t& stack = this->stack();
            LOGGER_IS_LOGGED_INFO("do {...");
            do {
                LOGGER_IS_LOGGED_INFO("stack.push_branch(v)...");
                stack.push_branch(v);
                LOGGER_IS_LOGGED_INFO("for (auto b: v->branches()) {...");
                for (auto b: v->branches()) {
                    LOGGER_IS_LOGGED_INFO("this->push_branch(b)...");
                    this->push_branch(b);
                }
                LOGGER_IS_LOGGED_INFO("...} while ((v = this->pop_branch()))...");
            } while ((v = this->pop_branch()));
            LOGGER_IS_LOGGED_INFO("while ((v = stack.pop_branch())) {...");
            while ((v = stack.pop_branch())) {
                LOGGER_IS_LOGGED_INFO("if (this->found(v)) {...");
                if (this->found(v)) { 
                    LOGGER_IS_LOGGED_INFO("break...");
                    break; 
                }
            }
        }
    }
    virtual branches_t& stack() const {
        return (branches_t&)stack_;
    }

protected:
    branches_t stack_;
}; /// class depend_first_searcht
///typedef depend_first_searcht<> depend_first_search;

//////////////////////////////////////////////////////////////////////////
/// class bottom_first_searcht
template 
<class TBranch, class TBranches, class TLeaves, class TSearch = searcht<TBranch>, 
 class TExtends = brancht<TBranch, TBranches, TLeaves, TSearch>, class TImplements = implement>
class exported bottom_first_searcht: virtual public TImplements, public TExtends {
public:
    typedef TImplements implements;
    typedef TExtends extends;
    typedef bottom_first_searcht derives;

    typedef TBranch branch_t;
    typedef TBranches branches_t;
    
    /// constructor / destructor
    bottom_first_searcht() {}
    bottom_first_searcht(branch_t* v) {this->search(v);
    }
    virtual ~bottom_first_searcht() {}
private:
    bottom_first_searcht(const bottom_first_searcht &copy) {}
public:

    /// search...
    virtual void search(branch_t* v) {
        LOGGER_IS_LOGGED_INFO("if (v) {...");
        if (v) {
            branches_t& stack = this->stack();
            LOGGER_IS_LOGGED_INFO("stack.push_branch(v)...");
            stack.push_branch(v);
            LOGGER_IS_LOGGED_INFO("do {...");
            do {
                LOGGER_IS_LOGGED_INFO("for (auto b: v->branches()) {...");
                for (auto b: v->branches()) {
                    LOGGER_IS_LOGGED_INFO("this->push_branch(b)...");
                    this->push_branch(b);
                }
                LOGGER_IS_LOGGED_INFO("for (auto b: branches_t::reverse_iterate(v->branches())) {...");
                for (auto b: branches_t::reverse_iterate(v->branches())) {
                    LOGGER_IS_LOGGED_INFO("stack.push_branch(b);...");
                    stack.push_branch(b);
                }
                LOGGER_IS_LOGGED_INFO("...} while ((v = this->pop_branch()))...");
            } while ((v = this->pop_branch()));
            LOGGER_IS_LOGGED_INFO("while ((v = stack.pop_branch())) {...");
            while ((v = stack.pop_branch())) {
                LOGGER_IS_LOGGED_INFO("if (this->found(v)) {...");
                if (this->found(v)) { 
                    LOGGER_IS_LOGGED_INFO("break...");
                    break; 
                }
            }
        }
    }
    virtual branches_t& stack() const {
        return (branches_t&)stack_;
    }

protected:
    branches_t stack_;
}; /// class bottom_first_searcht
///typedef bottom_first_searcht<> bottom_first_search;

} /// namespace tree 
} /// namespace xos 

#endif /// ndef XOS_TREE_SEARCH_HPP
