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
///   File: searcher.hpp
///
/// Author: $author$
///   Date: 1/8/2024
//////////////////////////////////////////////////////////////////////////
#ifndef XOS_FS_TREE_SEARCHER_HPP
#define XOS_FS_TREE_SEARCHER_HPP

#include "xos/tree/search.hpp"
#include "xos/fs/tree/searcher/events.hpp"
#include "xos/fs/tree/branch.hpp"

namespace xos {
namespace fs {
namespace tree {

typedef xos::tree::breadth_first_searcht<branch, branches, leaves> breadth_first_search;
typedef xos::tree::depth_first_searcht<branch, branches, leaves> depth_first_search;
typedef xos::tree::depend_first_searcht<branch, branches, leaves> depend_first_search;
typedef xos::tree::bottom_first_searcht<branch, branches, leaves> bottom_first_search;

/// class searchert
template 
<class TSearched = depth_first_search,
 class TExtends = searcher_events_extend, class TImplements = typename TExtends::implements>
class exported searchert: virtual public TImplements, public TExtends {
public:
    typedef TImplements implements;
    typedef TExtends extends;
    typedef searchert derives;

    typedef TSearched searched;
    
    /// constructor / destructor
    searchert(searcher_events* events): extends(events) {
    }
    searchert(const searchert &copy) {
    }
    searchert() {
    }
    virtual ~searchert() {
    }

    /// search
    virtual ssize_t search(branch& b, const char_t* path) {
        ssize_t count = 0;
        LOGGER_IS_LOGGED_INFO("((path) && (path[0]))...");
        if ((path) && (path[0])) {
            LOGGER_IS_LOGGED_INFO("count = search(b = (" << path << "))...");
            count = search(b = (path));
        } else {
            LOGGER_IS_LOGGED_INFO("...failed on ((path) && (path[0]))");
        }
        return count;
    }
    virtual ssize_t search(branch& b) {
        ssize_t count = 0;
        LOGGER_IS_LOGGED_INFO("xos::tree::findt<branch, derives, searched> search(*this, b)...");
        xos::tree::findt<branch, derives, searched> search(*this, b);
        return count;
    }
    
    /// found
    virtual branch* found(branch* b) {
        if ((b)) {
            LOGGER_IS_LOGGED_INFO("(event_handled_success != (this->on_found_branch(*b)))...");
            if (event_handled_success != (this->on_found_branch(*b))) {
                return b;
            }
        }
        for (auto l: b->leaves()) {
            if ((found(l))) {
                return b;
            }
        }
        return 0;
    }
    virtual leaf* found(leaf* l) {
        if ((l)) {
            LOGGER_IS_LOGGED_INFO("(event_handled_success != (this->on_found_leaf(*l)))...");
            if (event_handled_success != (this->on_found_leaf(*l))) {
                return l;
            }
        }
        return 0;
    }

protected:
}; /// class searchert
typedef searchert<> searcher;

typedef searchert<breadth_first_search> breadth_first_searcher;
typedef searchert<depth_first_search> depth_first_searcher;
typedef searchert<depend_first_search> depend_first_searcher;
typedef searchert<bottom_first_search> bottom_first_searcher;

} /// namespace tree 
} /// namespace fs 
} /// namespace xos 

#endif /// ndef XOS_FS_TREE_SEARCHER_HPP
