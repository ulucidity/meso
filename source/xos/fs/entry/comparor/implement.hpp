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
///   Date: 1/25/2024
//////////////////////////////////////////////////////////////////////////
#ifndef XOS_FS_ENTRY_COMPAROR_IMPLEMENT_HPP
#define XOS_FS_ENTRY_COMPAROR_IMPLEMENT_HPP

#include "xos/fs/entry/implement.hpp"
#include "xos/base/logged.hpp"

namespace xos {
namespace fs {
namespace entry {
namespace comparor {

/// class implementt
template <class TEntry = xos::fs::entry::implement, class TImplements = xos::logged>
class exported implementt: virtual public TImplements {
public:
    typedef TImplements implements;
    typedef implementt derives;

    typedef derives comparor_t;
    typedef TEntry entry_t;
    typedef typename entry_t::string_t string_t;
    typedef typename string_t::char_t char_t;
    typedef typename string_t::end_char_t end_char_t;
    enum { end_char = string_t::end_char };

    /// constructor / destructor
    virtual ~implementt() {
    }

    /// ...comparor... / ...compare...
    virtual comparor_t* new_comparor() const {
        comparor_t* comparor = 0;
        return comparor;
    }
    virtual bool compares(int &unequal, const entry_t& entry, const string_t &path, const entry_t& to_entry, const string_t &to_path) const {
        bool compares = false;
        return compares;
    }
    virtual int compare(const entry_t& entry, const string_t &path, const entry_t& to_entry, const string_t &to_path) const {
        int unequal = 0;
        return unequal;
    }

protected:
}; /// class implementt
typedef implementt<> implement;

} /// namespace comparor 
} /// namespace entry 
} /// namespace fs 
} /// namespace xos 

#endif /// ndef XOS_FS_ENTRY_COMPAROR_IMPLEMENT_HPP
