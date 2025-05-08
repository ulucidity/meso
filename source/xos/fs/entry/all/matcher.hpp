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
///   File: matcher.hpp
///
/// Author: $author$
///   Date: 1/16/2024
//////////////////////////////////////////////////////////////////////////
#ifndef XOS_FS_ENTRY_ALL_MATCHER_HPP
#define XOS_FS_ENTRY_ALL_MATCHER_HPP

#include "xos/fs/entry/matcher/extend.hpp"

namespace xos {
namespace fs {
namespace entry {
namespace all {

/// class matchert
template <class TExtends = xos::fs::entry::matcher::extend, class TImplements = typename TExtends::implements>
class exported matchert: virtual public TImplements, public TExtends {
public:
    typedef TImplements implements;
    typedef TExtends extends;
    typedef matchert derives;

    typedef typename implements::entry_t entry_t;
    typedef typename implements::string_t string_t;
    typedef typename string_t::char_t char_t;
    typedef typename string_t::end_char_t end_char_t;
    enum { end_char = string_t::end_char };

    /// constructor / destructor
    matchert(const matchert &copy): extends(copy) {
    }
    matchert() {
    }
    virtual ~matchert() {
    }

    /// matches
    virtual bool matches(const entry_t& entry) const {
        return true;
    }
    
protected:
}; /// class matchert
typedef matchert<> matcher;

} /// namespace all 
} /// namespace entry 
} /// namespace fs 
} /// namespace xos 

#endif /// ndef XOS_FS_ENTRY_ALL_MATCHER_HPP
