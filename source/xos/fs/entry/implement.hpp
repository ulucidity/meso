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
///   Date: 1/26/2024
//////////////////////////////////////////////////////////////////////////
#ifndef XOS_FS_ENTRY_IMPLEMENT_HPP
#define XOS_FS_ENTRY_IMPLEMENT_HPP

#include "xos/fs/entry/type.hpp"
#include "xos/fs/entry/time.hpp"
#include "xos/fs/entry/size.hpp"
#include "xos/base/logged.hpp"
#include "xos/fs/entry/string.hpp"

namespace xos {
namespace fs {
namespace entry {

/// class implementt
template <class TString = fs::entry::string, class TImplements = xos::logged>
class exported implementt: virtual public TImplements {
public:
    typedef TImplements implements;
    typedef implementt derives;

    typedef TString string_t;
    typedef typename string_t::char_t char_t;
    typedef typename string_t::end_char_t end_char_t;
    enum { end_char = string_t::end_char };

    /// constructor / destructor
    virtual ~implementt() {
    }

    /// exists
    virtual entry_type exists(const char* chars, size_t length) {
        return entry_type_none;
    }
    virtual entry_type exists(const char* chars) {
        return entry_type_none;
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
    virtual entry_time_when set_times_to_set(const derives& e, bool is_local = false) {
        return time_when_none;
    }
    virtual entry_time_when set_times_to_set
    (const time& time_modified, const time& time_accessed,
     const time& time_changed, const time& time_created, bool is_local = false) {
        return time_when_none;
    }
    virtual entry_time_when set_times_set() {
        return time_when_none;
    }

    /// ...path_name...
    virtual const char_t* set_path_name(const char_t* chars, size_t length) {
        return 0;
    }
    virtual const char_t* set_path_name(const char_t* chars) {
        return 0;
    }
    virtual const char_t* has_path_name(size_t& length) const {
        return 0;
    }
    virtual const char_t* has_path_name() const {
        return 0;
    }
    virtual const char_t* path_name(size_t& length) const {
        return 0;
    }
    virtual const char_t* path_name() const {
        return 0;
    }

    /// ...path...
    virtual const char_t* set_path(const char_t* chars, size_t length) {
        return 0;
    }
    virtual const char_t* set_path(const char_t* chars) {
        return 0;
    }
    virtual const char_t* has_path(size_t& length) const {
        return 0;
    }
    virtual const char_t* has_path() const {
        return 0;
    }
    virtual const char_t* path(size_t& length) const {
        return 0;
    }
    virtual const char_t* path() const {
        return 0;
    }

    /// ...name...
    virtual const char_t* set_name(const char_t* chars, size_t length) {
        return 0;
    }
    virtual const char_t* set_name(const char_t* chars) {
        return 0;
    }
    virtual const char_t* has_name(size_t& length) const {
        return 0;
    }
    virtual const char_t* has_name() const {
        return 0;
    }
    virtual const char_t* name(size_t& length) const {
        return 0;
    }
    virtual const char_t* name() const {
        return 0;
    }
    /// ...base...
    virtual const char_t* set_base(const char_t* chars, size_t length) {
        return 0;
    }
    virtual const char_t* set_base(const char_t* chars) {
        return 0;
    }
    virtual const char_t* has_base(size_t& length) const {
        return 0;
    }
    virtual const char_t* has_base() const {
        return 0;
    }
    virtual const char_t* base(size_t& length) const {
        return 0;
    }
    virtual const char_t* base() const {
        return 0;
    }
    /// ...extension...
    virtual const char_t* set_extension(const char_t* chars, size_t length) {
        return 0;
    }
    virtual const char_t* set_extension(const char_t* chars) {
        return 0;
    }
    virtual const char_t* has_extension(size_t& length) const {
        return 0;
    }
    virtual const char_t* has_extension() const {
        return 0;
    }
    virtual const char_t* extension(size_t& length) const {
        return 0;
    }
    virtual const char_t* extension() const {
        return 0;
    }
    /// ...separator...
    virtual char_t& set_extension_separator(const char_t& to) {
        char_t& extension_separator = this->extension_separator();
        extension_separator = to;
        return extension_separator;
    }
    virtual char_t& extension_separator() const {
        static char_t extension_separator = '.';
        return (char_t&)extension_separator;
    }
    virtual const char* volume_separator_chars() const {
        return ":";
    }
    virtual const char* volume_directory_separator_chars() const {
        return "\\";
    }
    virtual const char* directory_separator_chars() const {
        return "/";
    }

    /// ...hidden...
    virtual bool set_is_hidden(bool is_hidden = true) {
        return false;
    }
    virtual bool is_hidden() const {
        return false;
    }
    /// ...size
    virtual entry_size_t set_size(entry_size_t size) {
        return 0;
    }
    virtual entry_size_t size() const {
        return 0;
    }

    /// ...type...
    virtual const entry_type& set_type(const entry_type& type) {
        const entry_type& type_ = this->type();
        return type_;
    }
    virtual const entry_type& type() const {
        static const entry_type type_;
        return type_;
    }
    /// ...is_directory
    virtual bool set_is_directory(bool to = true) {
        return false;
    }
    virtual bool is_directory() const {
        return false;
    }

    /// ...time...
    virtual const entry_time_when& set_times(const entry_time_when& times) {
        const entry_time_when& times_ = this->times();
        return times_;
    }
    virtual const entry_time_when& times() const {
        static const entry_time_when times_;
        return times_;
    }
    /// ...time_modified
    virtual const time& set_time_modified(const time& to) {
        const time& time_modified_ = this->time_modified();
        return time_modified_;
    }
    virtual const time& time_modified() const {
        static const time time_modified_;
        return time_modified_;
    }
    /// ...time_accessed
    virtual const time& set_time_accessed(const time& to) {
        const time& time_accessed_ = this->time_accessed();
        return time_accessed_;
    }
    virtual const time& time_accessed() const {
        static const time time_accessed_;
        return time_accessed_;
    }
    /// ...time_changed
    virtual const time& set_time_changed(const time& to) {
        const time& time_changed_ = this->time_changed();
        return time_changed_;
    }
    virtual const time& time_changed() const {
        static const time time_changed_;
        return time_changed_;
    }
    /// ...time_created
    virtual const time& set_time_created(const time& to) {
        const time& time_created_ = this->time_created();
        return time_created_;
    }
    virtual const time& time_created() const {
        static const time time_created_;
        return time_created_;
    }

    /// ...time_when...
    virtual const time* has_time_when(const entry_time_when& when) const {
        return 0;
    }
    virtual const time* has_time_when(time_when_which which) const {
        return 0;
    }
    virtual const time* time_when(const entry_time_when& when) const {
        return 0;
    }
    virtual const time* time_when(time_when_which which) const {
        return 0;
    }

    /// on_set...
    virtual void on_set_is_hidden() {
    }
    virtual void on_set_path_name() {
    }
    virtual void on_set_path() {
    }
    virtual void on_set_name() {
    }
    virtual void on_set_base() {
    }
    virtual void on_set_extension() {
    }
    virtual void on_set_size() {
    }
    virtual void on_set_type() {
    }

protected:
}; /// class implementt
typedef implementt<> implement;

} /// namespace entry 
} /// namespace fs 
} /// namespace xos 

#endif /// ndef XOS_FS_ENTRY_IMPLEMENT_HPP
