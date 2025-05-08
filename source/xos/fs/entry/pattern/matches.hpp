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
///   File: matches.hpp
///
/// Author: $author$
///   Date: 1/20/2024
//////////////////////////////////////////////////////////////////////////
#ifndef XOS_FS_ENTRY_PATTERN_MATCHES_HPP
#define XOS_FS_ENTRY_PATTERN_MATCHES_HPP

#include "xos/fs/entry/string.hpp"
#include "xos/fs/entry/matchers.hpp"

namespace xos {
namespace fs {
namespace entry {
namespace pattern {

/// class matchest
template 
<class TMatchers = ::xos::fs::entry::matchers, 
 class TExtends = ::xos::fs::entry::string, class TImplements = typename TExtends::implements>
class exported matchest: virtual public TImplements, public TExtends {
public:
    typedef TImplements implements;
    typedef TExtends extends;
    typedef matchest derives;

    typedef TMatchers matchers_t;
    typedef typename TMatchers::matcher_t matcher_t;

    typedef typename extends::string_t string_t;
    typedef typename extends::char_t char_t;
    typedef typename extends::end_char_t end_char_t;
    enum { end_char = extends::end_char };

    /// constructor / destructor
    matchest(const matchest &copy): extends(copy) {
        construct();
    }
    matchest(const string_t &copy): extends(copy) {
        construct();
    }
    matchest(const char_t* chars, size_t length): extends(chars, length) {
        construct();
    }
    matchest(const char_t* chars): extends(chars) {
        construct();
    }
    matchest(const wchar_t* chars, size_t length): extends(chars, length) {
        construct();
    }
    matchest(const wchar_t* chars): extends(chars) {
        construct();
    }
    matchest() {
        construct();
    }
    virtual ~matchest() {
        destruct();
    }

    /// parse
    virtual void parse(matchers_t& matchers, const matcher_t& matcher) {
        const char_t* chars = 0; size_t length = 0;

        LOGGER_IS_LOGGED_INFO("(chars = this->has_chars(length))...");
        if ((chars = this->has_chars(length))) {
            const char_t separator_char = this->separator_char();
            char_t index_char = 0; size_t index = 0;
            const char_t* first = 0; const char_t* last = 0; 

            LOGGER_IS_LOGGED_INFO("...(\"" << chars << "\" = this->has_chars(" << length << "))");
            for (first = chars, last = chars, index = 0; index < length; ++index, ++last) {
                if ((separator_char == (index_char = (*last)))) {
                    LOGGER_IS_LOGGED_INFO("...(separator_char == (index_char = (*last)))");
                    if ((first < last)) {
                        match(matchers, matcher, first, (last - first));
                    }
                    first = last + 1;
                }
            }
            if ((first < last)) {
                match(matchers, matcher, first, (last - first));
            }
        } else {
        }
    }
protected:
    virtual void match(matchers_t& matchers, const matcher_t& matcher, const char_t* chars, size_t length) {
        if ((chars) && (length)) {
            matcher_t* new_matcher = 0;

            LOGGER_IS_LOGGED_INFO("(new_matcher = matcher.new_matcher(\"" << chars << "\", " << length << "))...");
            if ((new_matcher = matcher.new_matcher(chars, length))) {
                LOGGER_IS_LOGGED_INFO("...(new_matcher = matcher.new_matcher(\"" << chars << "\", " << length << "))");
                LOGGER_IS_LOGGED_INFO("matchers.queue_matcher(new_matcher)...");
                matchers.queue_matcher(new_matcher);
            } else {
            }
        } else {
        }
    }

protected:
    /// separator_char
    virtual const char_t& separator_char() const {
        static const char_t separator_char = ((char_t)';');
        return separator_char;
    }

protected:
    virtual void construct() {
    }
    virtual void destruct() {
    }
    
protected:
}; /// class matchest
typedef matchest<> matches;

} /// namespace pattern 
} /// namespace entry 
} /// namespace fs 
} /// namespace xos 

#endif /// ndef XOS_FS_ENTRY_PATTERN_MATCHES_HPP
