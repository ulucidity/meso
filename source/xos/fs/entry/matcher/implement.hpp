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
///   File: implement.hpp
///
/// Author: $author$
///   Date: 1/16/2024
//////////////////////////////////////////////////////////////////////////
#ifndef XOS_FS_ENTRY_MATCHER_IMPLEMENT_HPP
#define XOS_FS_ENTRY_MATCHER_IMPLEMENT_HPP

#include "xos/fs/entry/implement.hpp"
#include "xos/base/logged.hpp"

namespace xos {
namespace fs {
namespace entry {
namespace matcher {

/// class implementt
template <class TEntry = xos::fs::entry::implement, class TImplements = xos::logged>
class exported implementt: virtual public TImplements {
public:
    typedef TImplements implements;
    typedef implementt derives;

    typedef derives matcher_t;
    typedef TEntry entry_t;
    typedef typename entry_t::string_t string_t;
    typedef typename string_t::char_t char_t;
    typedef typename string_t::end_char_t end_char_t;
    enum { end_char = string_t::end_char };

    /// constructor / destructor
    virtual ~implementt() {
    }

    /// ...match...
    virtual matcher_t* new_matcher(const char_t* match, size_t length) const {
        matcher_t* matcher = 0;
        return matcher;
    }
    virtual bool matches(const entry_t& entry) const {
        return false;
    }
    
protected:
}; /// class implementt
typedef implementt<> implement;

} /// namespace matcher 
} /// namespace entry 
} /// namespace fs 
} /// namespace xos 

#endif /// ndef XOS_FS_ENTRY_MATCHER_IMPLEMENT_HPP
