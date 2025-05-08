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
///   File: extend.hpp
///
/// Author: $author$
///   Date: 1/26/2024
//////////////////////////////////////////////////////////////////////////
#ifndef XOS_FS_ENTRY_EXTEND_HPP
#define XOS_FS_ENTRY_EXTEND_HPP

#include "xos/fs/entry/implement.hpp"
#include "xos/base/logger.hpp"

namespace xos {
namespace fs {
namespace entry {

/// class extendt
template 
<class TImplement = xos::fs::entry::implement, 
 class TExtends = xos::extended::loggedt<TImplement>, class TImplements = typename TExtends::implements>
class exported extendt: virtual public TImplements, public TExtends {
public:
    typedef TImplements implements;
    typedef TExtends extends;
    typedef extendt derives;

    typedef typename implements::string_t string_t;
    typedef typename string_t::char_t char_t;
    typedef typename string_t::end_char_t end_char_t;
    enum { end_char = string_t::end_char };

    /// constructor / destructor
    extendt(const extendt &copy): extends(copy) {
        construct(copy);
    }
    extendt() {
        construct();
    }
    virtual ~extendt() {
        destruct();
    }

    /// exists
    virtual entry_type exists(const char* chars, size_t length) {
        const string_t path(chars, length);
        return exists(path);
    }
    virtual entry_type exists(const char* chars) {
        const string_t path(chars);
        return exists(path);
    }
    virtual entry_type exists(const wchar_t* chars, size_t length) {
        return entry_type_none;
    }
    virtual entry_type exists(const wchar_t* chars) {
        return entry_type_none;
    }
    virtual entry_type exists(const string_t& path) {
        return entry_type_none;
    }

    /// ...times_to_set...
    virtual entry_time_when set_times_to_set(const extendt& e, bool is_local = false) {
        entry_time_when times = time_when_none;
        const time& time_modified = e.time_modified();
        const time& time_accessed = e.time_accessed();
        const time& time_changed = e.time_changed();
        const time& time_created = e.time_created();
        times = set_times_to_set
        (time_modified, time_accessed,
         time_changed, time_created, is_local);
        return times;
    }
    virtual entry_time_when set_times_to_set
    (const time& time_modified, const time& time_accessed,
     const time& time_changed, const time& time_created,
     bool is_local = false) {
        entry_time_when times = time_when_none;
        return times;
    }
    virtual entry_time_when set_times_set() {
        entry_time_when times = time_when_none;
        return times;
    }

    /// ...path_name...
    template <typename tchar_t>
    const char_t* set_path_namet(const tchar_t* path, const tchar_t* name) {
        path_name_.clear();
        if ((path) && (path[0])) {
            path_name_.append(path);
            if ((name) && (name[0])) {
                const char *directory_separator_chars = this->directory_separator_chars();
                path_name_.append(directory_separator_chars);
            }
        }
        if ((name) && (name[0])) {
            path_name_.append(name);
        }
        return path_name();
    }
    virtual const char_t* set_path_name(const char* path, const char* name) {
        set_path_namet<char>(path, name);
        return path_name();
    }
    virtual const char_t* set_path_name(const char* to, size_t length) {
        path_name_.assign(to, length);
        return path_name();
    }
    virtual const char_t* set_path_name(const char* to) {
        path_name_.assign(to);
        return path_name();
    }
    virtual const char_t* set_path_name(const wchar_t* path, const wchar_t* name) {
        return path_name();
    }
    virtual const char_t* set_path_name(const wchar_t* to, size_t length) {
        return path_name();
    }
    virtual const char_t* set_path_name(const wchar_t* to) {
        return path_name();
    }
    virtual const char_t* has_path_name(size_t& length) const {
        return path_name_.has_chars(length);
    }
    virtual const char_t* has_path_name() const {
        return path_name_.has_chars();
    }
    virtual const char_t* path_name(size_t& length) const {
        return path_name_.chars(length);
    }
    virtual const char_t* path_name() const {
        return path_name_.chars();
    }

    /// ...path...
    virtual const char_t* set_path(const char_t* chars, size_t length) {
        path_.assign(chars, length);
        this->on_set_path();
        return path_.c_str();
    }
    virtual const char_t* set_path(const char_t* chars) {
        path_.assign(chars);
        this->on_set_path();
        return path_.c_str();
    }
    virtual const char_t* has_path(size_t& length) const {
        if ((length = path_.length())) {
            return path_.c_str();
        }
        return 0;
    }
    virtual const char_t* has_path() const {
        if ((path_.length())) {
            return path_.c_str();
        }
        return 0;
    }
    virtual const char_t* path(size_t& length) const {
        length = path_.length();
        return path_.c_str();
    }
    virtual const char_t* path() const {
        return path_.c_str();
    }

    /// ...name...
    virtual const char_t* set_name(const char_t* chars, size_t length) {
        name_.assign(chars, length);
        this->on_set_name();
        return name_.c_str();
    }
    virtual const char_t* set_name(const char_t* chars) {
        name_.assign(chars);
        this->on_set_name();
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
    virtual void separate_name() {
        const char_t* chars = name_.c_str();
        size_t length = name_.length();

        LOGGER_IS_LOGGED_INFO("chars = \"" << chars << "\"[" << length << "]");
        if ((0 < length)) {
            size_t i = length - 1; const char_t* p = chars + i;
            const char_t extension_separator = this->extension_separator();

            LOGGER_IS_LOGGED_INFO("extension_separator = " << char_to_string(extension_separator) << "");
            for (char_t c = *p; 0 < i; --i, --p, c = *p) {
                if ((extension_separator == c)) {
                    if ((0 < i)) {
                        if ((i != 1) || (extension_separator != *chars)) {
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
    /// ...base...
    virtual const char_t* set_base(const char_t* chars, size_t length) {
        base_.assign(chars, length);
        this->on_set_base();
        return base_.c_str();
    }
    virtual const char_t* set_base(const char_t* chars) {
        base_.assign(chars);
        this->on_set_base();
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
        this->on_set_extension();
        return extension_.c_str();
    }
    virtual const char_t* set_extension(const char_t* chars) {
        extension_.assign(chars);
        this->on_set_extension();
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

    /// ...hidden...
    virtual bool set_is_hidden(bool is_hidden = true) {
        is_hidden_ = is_hidden;
        this->on_set_is_hidden();
        return is_hidden_;
    }
    virtual bool is_hidden() const {
        return is_hidden_;
    }
    virtual entry_size_t set_size(entry_size_t size) {
        size_ = size;
        this->on_set_size();
        return size_;
    }
    virtual entry_size_t size() const {
        return size_;
    }

    /// ...type...
    virtual const entry_type& set_type(const entry_type& type) {
        type_ = type;
        this->on_set_type();
        return type_;
    }
    virtual const entry_type& type() const {
        return type_;
    }
    virtual bool set_is_directory(bool to = true) {
        entry_type type((to)?(entry_type_directory):(entry_type_file));
        set_type(type);
        return is_directory();
    }
    virtual bool is_directory() const {
        if ((entry_type_directory == (entry_type_directory & (this->type().which())))) {
            return true;
        }
        return false;
    }

    /// ...time...
    virtual const entry_time_when& set_times(const entry_time_when& times) {
        times_ = times;
        return times_;
    }
    virtual const entry_time_when& times() const {
        return times_;
    }
    virtual const time& set_time_modified(const time& to) {
        times_ |= time_when_modified;
        time_modified_ = to;
        return time_modified_;
    }
    virtual const time& time_modified() const {
        return time_modified_;
    }
    virtual const time& set_time_accessed(const time& to) {
        times_ |= time_when_accessed;
        time_accessed_ = to;
        return time_accessed_;
    }
    virtual const time& time_accessed() const {
        return time_accessed_;
    }
    virtual const time& set_time_changed(const time& to) {
        times_ |= time_when_changed;
        time_changed_ = to;
        return time_changed_;
    }
    virtual const time& time_changed() const {
        return time_changed_;
    }
    virtual const time& set_time_created(const time& to) {
        times_ |= time_when_created;
        time_created_ = to;
        return time_created_;
    }
    virtual const time& time_created() const {
        return time_created_;
    }

    /// ...time_when...
    virtual const time* has_time_when(const entry_time_when& when) const {
        const time_when_which which = when.which();
        return has_time_when(which);
    }
    virtual const time* has_time_when(time_when_which which) const {
        if (which == (times_.has_which(which))) {
            return time_when(which);
        }
        return 0;
    }
    virtual const time* time_when(const entry_time_when& when) const {
        const time_when_which which = when.which();
        return time_when(which);
    }
    virtual const time* time_when(time_when_which which) const {
        switch (which) {
        case time_when_modified:
            return &time_modified_;
            break;
        case time_when_accessed:
            return &time_accessed_;
            break;
        case time_when_changed:
            return &time_changed_;
            break;
        case time_when_created:
            return &time_created_;
            break;
        }
        return 0;
    }

    /// set... / clear...
    virtual extendt& set(const extendt& copy) {
        path_=(copy.path()), name_=(copy.name()), is_hidden_=(copy.is_hidden()),
        size_=(copy.size()), type_=(copy.type()), times_=(copy.times()),
        time_modified_=(copy.time_modified()), time_accessed_=(copy.time_accessed()),
        time_changed_=(copy.time_changed()), time_created_=(copy.time_created());
        return *this;
    }
    virtual extendt& clear() {
        is_hidden_ = false;
        size_ = 0;
        type_.clear();
        times_.clear();
        time_modified_.clear();
        time_accessed_.clear();
        time_changed_.clear();
        time_created_.clear();
        path_name_.clear();
        path_.clear();
        name_.clear();
        base_.clear();
        extension_.clear();
        return *this;
    }

private:
    void construct(const extendt& copy) {
        path_name_=(copy.path_name()), path_=(copy.path()), name_=(copy.name()), is_hidden_=(copy.is_hidden()),
        size_=(copy.size()), type_=(copy.type()), times_=(copy.times()),
        time_modified_=(copy.time_modified()), time_accessed_=(copy.time_accessed()),
        time_changed_=(copy.time_changed()), time_created_=(copy.time_created());
    }
    void construct() {
        is_hidden_=(false), size_=(0), type_=(entry_type_none), times_=(time_when_none),
        time_modified_=(time_when_modified), time_accessed_=(time_when_accessed),
        time_changed_=(time_when_changed), time_created_=(time_when_created);
    }
    void destruct() {
        path_name_.clear();
        name_.clear();
        path_.clear();
    }

protected:
    string_t path_name_, path_, name_, base_, extension_;
    bool is_hidden_;
    entry_size_t size_;
    entry_type type_;
    entry_time_when times_;
    time time_modified_, time_accessed_, time_changed_, time_created_;
}; /// class extendt
typedef extendt<> extend;

} /// namespace entry 
} /// namespace fs 
} /// namespace xos 

#endif /// ndef XOS_FS_ENTRY_EXTEND_HPP
