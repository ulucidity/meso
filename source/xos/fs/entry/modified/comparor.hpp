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
///   File: comparor.hpp
///
/// Author: $author$
///   Date: 1/25/2024
//////////////////////////////////////////////////////////////////////////
#ifndef XOS_FS_ENTRY_MODIFIED_COMPAROR_HPP
#define XOS_FS_ENTRY_MODIFIED_COMPAROR_HPP

#include "xos/fs/entry/comparor/extend.hpp"

namespace xos {
namespace fs {
namespace entry {
namespace modified {

/// class comparort
template <class TExtends = xos::fs::entry::comparor::extend, class TImplements = typename TExtends::implements>
class exported comparort: virtual public TImplements, public TExtends {
public:
    typedef TImplements implements;
    typedef TExtends extends;
    typedef comparort derives;

    typedef implements comparor_t;
    typedef typename implements::entry_t entry_t;
    typedef typename implements::string_t string_t;
    typedef typename string_t::char_t char_t;
    typedef typename string_t::end_char_t end_char_t;
    enum { end_char = string_t::end_char };

    /// constructor / destructor
    comparort(const comparort &copy): extends(copy) {
    }
    comparort() {
    }
    virtual ~comparort() {
    }

    /// ...comparor... / ...compare...
    virtual comparor_t* new_comparor() const {
        comparor_t* comparor = new derives();
        return comparor;
    }
    virtual bool compares(int &unequal, const entry_t& entry, const string_t &path, const entry_t& to_entry, const string_t &to_path) const {
        bool compares = false;

        LOGGER_IS_LOGGED_INFO("(compares = (0 < (unequal = compare(entry, path, to_entry, to_path)))}...");
        if ((compares = (0 < (unequal = compare(entry, path, to_entry, to_path))))) {
            LOGGER_IS_LOGGED_INFO("...(" << compares << " = (0 < (" << unequal << " = compare(entry, path, to_entry, to_path))))");
        } else {
            LOGGER_IS_LOGGED_INFO("...failed on (" << compares << " = (0 < (" << unequal << " = compare(entry, path, to_entry, to_path))))");
        }
        return compares;
    }
    virtual int compare(const entry_t& entry, const string_t &path, const entry_t& to_entry, const string_t &to_path) const {
        int unequal = 0;
        const ::xos::fs::entry::time_when_which time_when_modified = ::xos::fs::entry::time_when_modified;
        const ::xos::fs::entry::time *time_modified = 0;
        
        LOGGER_IS_LOGGED_INFO("(time_modified = entry.has_time_when(time_when_modified))...");
        if ((time_modified = entry.has_time_when(time_when_modified))) {
            const ::xos::fs::entry::time &modified = *time_modified;
            const ::xos::fs::entry::time *to_time_modified = 0;
            
            LOGGER_IS_LOGGED_INFO("...(time_modified = entry.has_time_when(time_when_modified))");
            LOGGER_IS_LOGGED_INFO("(to_time_modified = to_entry.has_time_when(time_when_modified))...");
            if ((to_time_modified = to_entry.has_time_when(time_when_modified))) {
                const ::xos::fs::entry::time &to_modified = *to_time_modified;

                LOGGER_IS_LOGGED_INFO("...(to_time_modified = to_entry.has_time_when(time_when_modified))");
                LOGGER_IS_LOGGED_INFO("(unequal = (modified != to_modified))...");
                if ((unequal = (modified != to_modified))) {
                    LOGGER_IS_LOGGED_INFO("...(" << unequal << " = (modified != to_modified))");
                } else {
                    LOGGER_IS_LOGGED_INFO("...failed on (" << unequal << " = (modified != to_modified))");
                }
            } else {
                LOGGER_IS_LOGGED_INFO("...failed on (to_time_modified = to_entry.has_time_when(time_when_modified))");
            }
        } else {
            LOGGER_IS_LOGGED_INFO("...failed on (time_modified = entry.has_time_when(time_when_modified))");
        }
        return unequal;
    }

protected:
}; /// class comparort
typedef comparort<> comparor;

} /// namespace modified 
} /// namespace entry 
} /// namespace fs 
} /// namespace xos 

#endif /// ndef XOS_FS_ENTRY_MODIFIED_COMPAROR_HPP
