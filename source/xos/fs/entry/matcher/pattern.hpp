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
///   File: pattern.hpp
///
/// Author: $author$
///   Date: 1/19/2024
//////////////////////////////////////////////////////////////////////////
#ifndef XOS_FS_ENTRY_MATCHER_PATTERN_HPP
#define XOS_FS_ENTRY_MATCHER_PATTERN_HPP

#include "xos/fs/entry/string.hpp"
#include "xos/fs/entry/matchers.hpp"
#include "xos/fs/entry/all/matcher.hpp"
#include "xos/fs/entry/none/matcher.hpp"
#include "xos/fs/entry/name/matcher.hpp"
#include "xos/fs/entry/base/matcher.hpp"
#include "xos/fs/entry/extension/matcher.hpp"

namespace xos {
namespace fs {
namespace entry {
namespace matcher {

/// class patternt
template 
<class TMatchers = ::xos::fs::entry::matchers, 
 class TAllMatcher = ::xos::fs::entry::all::matcher, 
 class TNoneMatcher = ::xos::fs::entry::none::matcher, 
 class TNameMatcher = ::xos::fs::entry::name::matcher, 
 class TBaseMatcher = ::xos::fs::entry::base::matcher, 
 class TExtensionMatcher = ::xos::fs::entry::extension::matcher, 
 class TExtends = ::xos::fs::entry::string, class TImplements = typename TExtends::implements>
class exported patternt: virtual public TImplements, public TExtends {
public:
    typedef TImplements implements;
    typedef TExtends extends;
    typedef patternt derives;

    typedef TMatchers matchers_t;
    typedef TAllMatcher all_matcher_t;
    typedef TNoneMatcher none_matcher_t;
    typedef TNameMatcher name_matcher_t;
    typedef TBaseMatcher base_matcher_t;
    typedef TExtensionMatcher extension_matcher_t;
    typedef typename TMatchers::matcher_t matcher_t;
    
    typedef typename extends::string_t string_t;
    typedef typename extends::char_t char_t;
    typedef typename extends::end_char_t end_char_t;
    enum { end_char = extends::end_char };

    /// constructor / destructor
    patternt(const patternt &copy): extends(copy) {
        construct();
    }
    patternt(const string_t &copy): extends(copy) {
        construct();
    }
    patternt(const char_t* chars, size_t length): extends(chars, length) {
        construct();
    }
    patternt(const char_t* chars): extends(chars) {
        construct();
    }
    patternt(const wchar_t* chars, size_t length): extends(chars, length) {
        construct();
    }
    patternt(const wchar_t* chars): extends(chars) {
        construct();
    }
    patternt() {
        construct();
    }
    virtual ~patternt() {
        destruct();
    }

    /// ...new_matcher
    matcher_t* (derives::*new_matcher_)();
    virtual matcher_t* new_matcher() {
        matcher_t* matcher = 0;
        if (new_matcher_) {
            if (!(matcher = (this->*new_matcher_)())) {
            } else {
            }
        } else {
            if (!(matcher = default_new_matcher())) {
            } else {
            }
        }
        return matcher;
    }
    virtual matcher_t* default_new_matcher() {
        matcher_t* matcher = 0;
        if (!(matcher = all_new_matcher())) {
        } else {
        }
        return matcher;
    }
    virtual matcher_t* all_new_matcher() {
        matcher_t* matcher = 0;
        if (!(matcher = new all_matcher_t())) {
        } else {
        }
        return matcher;
    }
    virtual matcher_t* none_new_matcher() {
        matcher_t* matcher = 0;
        if (!(matcher = new none_matcher_t())) {
        } else {
        }
        return matcher;
    }
    virtual matcher_t* name_new_matcher() {
        matcher_t* matcher = 0;
        if (!(matcher = new name_matcher_t(name()))) {
        } else {
        }
        return matcher;
    }
    virtual matcher_t* base_new_matcher() {
        matcher_t* matcher = 0;
        if (!(matcher = new base_matcher_t(base()))) {
        } else {
        }
        return matcher;
    }
    virtual matcher_t* extension_new_matcher() {
        matcher_t* matcher = 0;
        if (!(matcher = new extension_matcher_t(extension()))) {
        } else {
        }
        return matcher;
    }
protected:
    virtual int unset_matcher() {
        int err = 0;
        new_matcher_ = 0;
        return err;
    }
    virtual int set_all_new_matcher() {
        int err = 0;
        new_matcher_ = &derives::all_new_matcher;
        return err;
    }
    virtual int set_none_new_matcher() {
        int err = 0;
        new_matcher_ = &derives::none_new_matcher;
        return err;
    }
    virtual int set_name_new_matcher() {
        int err = 0;
        new_matcher_ = &derives::name_new_matcher;
        return err;
    }
    virtual int set_base_new_matcher() {
        int err = 0;
        new_matcher_ = &derives::base_new_matcher;
        return err;
    }
    virtual int set_extension_new_matcher() {
        int err = 0;
        new_matcher_ = &derives::extension_new_matcher;
        return err;
    }
    
    /// parse
    virtual void parse() {
        int unequal = 0;
        const char_t& wildcard_char = this->wildcard_char();
        string_t wildcard(&wildcard_char, 1);
        const char_t* base_chars = 0;

        LOGGER_IS_LOGGED_INFO("(base_chars = has_base())...");
        if ((base_chars = has_base())) {
            const char_t* extension_chars = 0;
            string_t base(base_chars);

            LOGGER_IS_LOGGED_INFO("...(\"" << base_chars << "\" = has_base())");
            LOGGER_IS_LOGGED_INFO("(extension_chars = has_extension())...");
            if ((extension_chars = has_extension())) {
                string_t extension(extension_chars);

                LOGGER_IS_LOGGED_INFO("...(\"" << extension_chars << "\" = has_extension())");
                LOGGER_IS_LOGGED_INFO("!(unequal = base.compare(\"" << wildcard << "\"))...");
                if (!(unequal = base.compare(wildcard))) {
                    /// '*'...
                    LOGGER_IS_LOGGED_INFO("...!(unequal = base.compare(\"" << wildcard << "\"))");
                    LOGGER_IS_LOGGED_INFO("!(unequal = extension.compare(\"" << wildcard << "\"))...");
                    if (!(unequal = extension.compare(wildcard))) {
                        /// '*''.''*'
                        LOGGER_IS_LOGGED_INFO("...!(unequal = extension.compare(\"" << wildcard << "\"))");
                        LOGGER_IS_LOGGED_INFO("set_all_new_matcher()...");
                        set_all_new_matcher();
                    } else {
                        /// '*''.'base
                        LOGGER_IS_LOGGED_INFO("set_extension_new_matcher()...");
                        set_extension_new_matcher();
                    }
                } else {
                    /// base...
                    LOGGER_IS_LOGGED_INFO("!(unequal = base.compare(\"" << wildcard << "\"))...");
                    if (!(unequal = extension.compare(wildcard))) {
                        /// base'.''*'
                        LOGGER_IS_LOGGED_INFO("...!(unequal = base.compare(\"" << wildcard << "\"))");
                        LOGGER_IS_LOGGED_INFO("set_base_new_matcher()...");
                        set_base_new_matcher();
                    } else {
                        /// base'.'base
                        LOGGER_IS_LOGGED_INFO("set_name_new_matcher()...");
                        set_name_new_matcher();
                    }
                }
            } else {
                LOGGER_IS_LOGGED_INFO("!(unequal = base.compare(\"" << wildcard << "\"))...");
                if (!(unequal = base.compare(wildcard))) {
                    /// '*'
                    LOGGER_IS_LOGGED_INFO("...!(unequal = base.compare(\"" << wildcard << "\"))");
                    LOGGER_IS_LOGGED_INFO("set_all_new_matcher()...");
                    set_all_new_matcher();
                } else {
                    /// base
                    LOGGER_IS_LOGGED_INFO("set_base_new_matcher()...");
                    set_base_new_matcher();
                }
            }
        } else {
            const char_t* name_chars = 0;

            LOGGER_IS_LOGGED_INFO("(name_chars = has_name())...");
            if ((name_chars = has_name())) {
                string_t name(name_chars);

                LOGGER_IS_LOGGED_INFO("...(\"" << name_chars << "\" = has_name())");
                if (!(unequal = name.compare(wildcard))) {
                    /// '*'
                    LOGGER_IS_LOGGED_INFO("...!(unequal = name.compare(\"" << wildcard << "\"))");
                    LOGGER_IS_LOGGED_INFO("set_all_new_matcher()...");
                    set_all_new_matcher();
                } else {
                    /// name
                    LOGGER_IS_LOGGED_INFO("set_name_new_matcher()...");
                    set_name_new_matcher();
                }
            } else {
            }
        }
    }

    /// ...name.../...base.../...extension...
    /// ...
    virtual void separate_name() {
        const char_t* chars = name_.c_str();
        size_t length = name_.length();

        LOGGER_IS_LOGGED_INFO("chars = \"" << chars << "\"[" << length << "]");
        if ((0 < length)) {
            size_t i = length - 1; const char_t* p = chars + i;
            const char_t extension_separator_char = this->extension_separator_char();

            LOGGER_IS_LOGGED_INFO("extension_separator_char = " << char_to_string(extension_separator_char) << "");
            for (char_t c = *p; 0 < i; --i, --p, c = *p) {
                if ((extension_separator_char == c)) {
                    if ((0 < i)) {
                        if ((i != 1) || (extension_separator_char != *chars)) {
                            LOGGER_IS_LOGGED_INFO("set_base(\"" << chars<< "\", " << i << ")...");
                            set_base(chars, i);
                        }
                    }
                    if ((i+1 < length)) {
                        LOGGER_IS_LOGGED_INFO("set_extension(\"" << p+1 << "\", " << length-i-1 << ")...");
                        set_extension(p+1, length-i-1);
                    }
                    LOGGER_IS_LOGGED_INFO("(chars = has_extension(length))...");
                    if ((chars = has_extension(length))) {
                        LOGGER_IS_LOGGED_INFO("...(\"" << chars<< "\" = has_extension(" << length << "))");
                    } else {
                        LOGGER_IS_LOGGED_INFO("...failed on (chars = has_extension(" << length << "))");
                    }
                    break;
                }
            }
        }
    }
    /// ...name...
    virtual const char_t* set_name(const char_t* chars, size_t length) {
        name_.assign(chars, length);
        return name_.c_str();
    }
    virtual const char_t* set_name(const char_t* chars) {
        name_.assign(chars);
        return name_.c_str();
    }
    virtual const char_t* set_name() {
        name_.assign(this->c_str());
        return name_.c_str();
    }
    virtual const char_t* has_name(size_t& length) const {
        if ((length = name_.length())) {
            return name_.c_str();
        }
        return 0;
    }
    virtual const char_t* has_name() const {
        if ((name_.length())) {
            return name_.c_str();
        }
        return 0;
    }
    virtual const char_t* name(size_t& length) const {
        length = name_.length();
        return name_.c_str();
    }
    virtual const char_t* name() const {
        return name_.c_str();
    }
    /// ...base...
    virtual const char_t* set_base(const char_t* chars, size_t length) {
        base_.assign(chars, length);
        return base_.c_str();
    }
    virtual const char_t* set_base(const char_t* chars) {
        base_.assign(chars);
        return base_.c_str();
    }
    virtual const char_t* has_base(size_t& length) const {
        if ((length = base_.length())) {
            return base_.c_str();
        }
        return 0;
    }
    virtual const char_t* has_base() const {
        if ((base_.length())) {
            return base_.c_str();
        }
        return 0;
    }
    virtual const char_t* base(size_t& length) const {
        length = base_.length();
        return base_.c_str();
    }
    virtual const char_t* base() const {
        return base_.c_str();
    }
    /// ...extension...
    virtual const char_t* set_extension(const char_t* chars, size_t length) {
        extension_.assign(chars, length);
        return extension_.c_str();
    }
    virtual const char_t* set_extension(const char_t* chars) {
        extension_.assign(chars);
        return extension_.c_str();
    }
    virtual const char_t* has_extension(size_t& length) const {
        if ((length = extension_.length())) {
            return extension_.c_str();
        }
        return 0;
    }
    virtual const char_t* has_extension() const {
        if ((extension_.length())) {
            return extension_.c_str();
        }
        return 0;
    }
    virtual const char_t* extension(size_t& length) const {
        length = extension_.length();
        return extension_.c_str();
    }
    virtual const char_t* extension() const {
        return extension_.c_str();
    }
    virtual const char_t& extension_separator_char() const {
        static const char_t extension_separator_char = ((char_t)'.');
        return extension_separator_char;
    }
    virtual const char_t& wildcard_char() const {
        static const char_t wildcard_char = ((char_t)'*');
        return wildcard_char;
    }
    /// ...
    /// ...name.../...base.../...extension...

protected:
    virtual void construct() {
        unset_matcher();
        set_name();
        separate_name();
        parse();
    }
    virtual void destruct() {
    }
    
protected:
    string_t name_, base_, extension_;
}; /// class patternt
typedef patternt<> pattern;

} /// namespace matcher 
} /// namespace entry 
} /// namespace fs 
} /// namespace xos 

#endif /// ndef XOS_FS_ENTRY_MATCHER_PATTERN_HPP
