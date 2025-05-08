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
///   Date: 1/17/2024
//////////////////////////////////////////////////////////////////////////
#ifndef XOS_FS_ENTRY_BASE_MATCHER_HPP
#define XOS_FS_ENTRY_BASE_MATCHER_HPP

#include "xos/fs/entry/matcher/extend.hpp"

namespace xos {
namespace fs {
namespace entry {
namespace base {

/// class matchert
template <class TExtends = xos::fs::entry::matcher::extend, class TImplements = typename TExtends::implements>
class exported matchert: virtual public TImplements, public TExtends {
public:
    typedef TImplements implements;
    typedef TExtends extends;
    typedef matchert derives;

    typedef implements matcher_t;
    typedef typename implements::entry_t entry_t;
    typedef typename implements::string_t string_t;
    typedef typename string_t::char_t char_t;
    typedef typename string_t::end_char_t end_char_t;
    enum { end_char = string_t::end_char };

    /// constructor / destructor
    matchert(const string_t& match): extends(match) {
    }
    matchert(const char_t* match): extends(match) {
    }
    matchert(const char_t* match, size_t length): extends(match, length) {
    }
    matchert(const matchert &copy): extends(copy) {
    }
    matchert() {
    }
    virtual ~matchert() {
    }

    /// ...match...
    virtual matcher_t* new_matcher(const char_t* match, size_t length) const {
        matcher_t* matcher = new derives(match, length);
        return matcher;
    }
    virtual bool matches(const entry_t& entry) const {
        bool matches = false;
        const char_t* chars = 0; size_t length = 0;

        LOGGER_IS_LOGGED_INFO("(chars = entry.has_base(length))...");
        if ((chars = entry.has_base(length))) {
            const string_t& match = this->match(); int unequal = 0;

            LOGGER_IS_LOGGED_INFO("...(\"" << chars << "\" = entry.has_base(" << length << "))");
            LOGGER_IS_LOGGED_INFO("(matches = (!(unequal = match.compare(\"" << chars << "\", " << length << "))))...");
            if ((matches = (!(unequal = match.compare(chars))))) {
                LOGGER_IS_LOGGED_INFO("...(matches = (!(unequal = match.compare(\"" << chars << "\", " << length << "))))");
            } else {
                LOGGER_IS_LOGGED_INFO("...failed on (matches = (!(unequal = match.compare(\"" << chars << "\", " << length << "))))");
            }
        } else {
            LOGGER_IS_LOGGED_INFO("...failed on (chars = entry.has_base(" << length << "))");
        }
        return matches;
    }
    
protected:
}; /// class matchert
typedef matchert<> matcher;

} /// namespace base 
} /// namespace entry 
} /// namespace fs 
} /// namespace xos 

#endif /// ndef XOS_FS_ENTRY_BASE_MATCHER_HPP
