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
///   File: patterns.hpp
///
/// Author: $author$
///   Date: 1/20/2024
//////////////////////////////////////////////////////////////////////////
#ifndef XOS_FS_ENTRY_MATCHER_PATTERNS_HPP
#define XOS_FS_ENTRY_MATCHER_PATTERNS_HPP

#include "xos/fs/entry/matcher/pattern.hpp"
#include "xos/fs/entry/matchers.hpp"

namespace xos {
namespace fs {
namespace entry {
namespace matcher {

/// class patternst
template 
<class TMatchers = ::xos::fs::entry::matchers, 
 class TMatcher = ::xos::fs::entry::matcher::implement, 
 class TPattern = ::xos::fs::entry::matcher::pattern,
 class TExtends = ::xos::fs::entry::string, class TImplements = typename TExtends::implements>
class exported patternst: virtual public TImplements, public TExtends {
public:
    typedef TImplements implements;
    typedef TExtends extends;
    typedef patternst derives;

    typedef TMatchers matchers_t;
    typedef TMatcher matcher_t;
    typedef TPattern pattern_t;

    typedef typename extends::string_t string_t;
    typedef typename extends::char_t char_t;
    typedef typename extends::end_char_t end_char_t;
    enum { end_char = extends::end_char };

    /// constructor / destructor
    patternst(const patternst &copy): extends(copy) {
        construct();
    }
    patternst(const string_t &copy): extends(copy) {
        construct();
    }
    patternst(const char_t* chars, size_t length): extends(chars, length) {
        construct();
    }
    patternst(const char_t* chars): extends(chars) {
        construct();
    }
    patternst(const wchar_t* chars, size_t length): extends(chars, length) {
        construct();
    }
    patternst(const wchar_t* chars): extends(chars) {
        construct();
    }
    patternst() {
        construct();
    }
    virtual ~patternst() {
        destruct();
    }

    /// parse
    virtual void parse(matchers_t& matchers) {
        const char_t* chars = 0; size_t length = 0;

        LOGGER_IS_LOGGED_INFO("(chars = this->has_chars(length))...");
        if ((chars = this->has_chars(length))) {
            const char_t separator_char = this->separator_char();
            char_t index_char = 0; size_t index = 0;
            const char_t* first = 0; const char_t* last = 0; 
            matcher_t* matcher = 0;

            LOGGER_IS_LOGGED_INFO("...(\"" << chars << "\" = this->has_chars(" << length << "))");
            for (first = chars, last = chars, index = 0; index < length; ++index, ++last) {
                if ((separator_char == (index_char = (*last)))) {
                    LOGGER_IS_LOGGED_INFO("...(separator_char == (index_char = (*last)))");
                    if ((first < last)) {
                        pattern(matchers, first, (last - first));
                    }
                    first = last + 1;
                }
            }
            if ((first < last)) {
                pattern(matchers, first, (last - first));
            }
        } else {
        }
    }
protected:
    virtual void pattern(matchers_t& matchers, const char_t* chars, size_t length) {
        pattern_t pattern(chars, length);
        matcher_t* matcher = 0;

        LOGGER_IS_LOGGED_INFO("...pattern = \"" << pattern << "\"");
        LOGGER_IS_LOGGED_INFO("(matcher = pattern.new_matcher())...");
        if ((matcher = pattern.new_matcher())) {
            LOGGER_IS_LOGGED_INFO("matchers.queue_matcher(matcher)...");
            matchers.queue_matcher(matcher);
        }
    }

protected:
    /// separator_char
    virtual const char_t& separator_char() const {
        static const char_t separator_char = ((char_t)';');
        return separator_char;
    }

protected:
    /// construct / destruct
    virtual void construct() {
    }
    virtual void destruct() {
    }
    
protected:
}; /// class patternst
typedef patternst<> patterns;

} /// namespace matcher 
} /// namespace entry 
} /// namespace fs 
} /// namespace xos 

#endif /// ndef XOS_FS_ENTRY_MATCHER_PATTERNS_HPP
