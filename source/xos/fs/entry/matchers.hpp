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
///   File: matchers.hpp
///
/// Author: $author$
///   Date: 1/17/2024
//////////////////////////////////////////////////////////////////////////
#ifndef XOS_FS_ENTRY_MATCHERS_HPP
#define XOS_FS_ENTRY_MATCHERS_HPP

#include "xos/fs/entry/matcher/implement.hpp"
#include <list>

namespace xos {
namespace fs {
namespace entry {

/// class matcherst
template 
<class TMatcher = ::xos::fs::entry::matcher::implement,
 class TExtends = ::std::list<TMatcher*>, class TImplements = xos::logged>
class exported matcherst: virtual public TImplements, public TExtends {
public:
    typedef TImplements implements;
    typedef TExtends extends;
    typedef matcherst derives;

    typedef TMatcher matcher_t;
    typedef typename matcher_t::entry_t entry_t;

    /// constructor / destructor
    matcherst() {
        construct();
    }
    virtual ~matcherst() {
        destruct();
    }
private:
    matcherst(const matcherst &copy): extends(copy) {
    }
public:

    /// matches
    virtual bool matches(const entry_t& entry) const {
        bool matches = false;
        for (auto m: *this) {
            if (m) {
                if ((matches = m->matches(entry))) {
                    break;
                } else {
                }
            }
        }
        return matches;
    }
    
    /// push... / pop... / queue... / pull...
    virtual matcher_t* push_matcher(matcher_t* first) {
        if (first) { this->push_front(first); }
        return first;
    }
    virtual matcher_t* pop_matcher() {
        matcher_t* first = 0;
        if (!(this->empty())) {
            first = this->front();
            this->pop_front();
        }
        return first;
    }
    virtual matcher_t* queue_matcher(matcher_t* last) {
        if (last) { this->push_back(last); }
        return last;
    }
    virtual matcher_t* pull_matcher() {
        matcher_t* last = 0;
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

private:
    virtual void construct() {
    }
    virtual void destruct() {
    }

protected:
}; /// class matcherst
typedef matcherst<> matchers;

} /// namespace entry 
} /// namespace fs 
} /// namespace xos 

#endif /// ndef XOS_FS_ENTRY_MATCHERS_HPP
