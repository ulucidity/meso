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
///   File: path.hpp
///
/// Author: $author$
///   Date: 1/5/2024
//////////////////////////////////////////////////////////////////////////
#ifndef XOS_FS_PATH_HPP
#define XOS_FS_PATH_HPP

#include "xos/fs/path_separator.hpp"

namespace xos {
namespace fs {

/// class patht
template 
<class TString = char_string, class TEvents = path_separator_eventst<TString>, class TSeparator = path_separatort<TEvents>,
 class TExtends = TString, class TImplements = typename TExtends::implements>
class exported patht: virtual public TEvents, virtual public TImplements, public TExtends {
public:
    typedef TImplements implements;
    typedef TExtends extends;
    typedef patht derives;

    typedef TSeparator separator_t;
    typedef typename separator_t::events_t events_t;
    typedef typename events_t::string_t string_t;
    typedef typename string_t::char_t char_t;
    typedef typename string_t::end_char_t end_char_t;
    enum { end_char = string_t::end_char };

    /// constructor / destructor
    patht(const wchar_t* chars, size_t length): extends(chars, length) {
        construct();
        separate();
    }
    patht(const char* chars, size_t length): extends(chars, length) {
        construct();
        separate();
    }
    patht(const wchar_t* chars): extends(chars) {
        construct();
        separate();
    }
    patht(const char* chars): extends(chars) {
        construct();
        separate();
    }
    patht(const patht &copy): extends(copy) {
        construct(copy);
        separate();
    }
    patht() {
        construct();
    }
    virtual ~patht() {
        destruct();
    }

    /// separate
    virtual patht& separate(const wchar_t* chars, size_t length) {
        this->assign(chars, length);
        separate();
        return *this;
    }
    virtual patht& separate(const char* chars, size_t length) {
        this->assign(chars, length);
        separate();
        return *this;
    }
    virtual patht& separate(const wchar_t* chars) {
        this->assign(chars);
        separate();
        return *this;
    }
    virtual patht& separate(const char* chars) {
        this->assign(chars);
        separate();
        return *this;
    }
    virtual patht& separate() {
        separator_t separator(*this);
        const char_t* chars = 0;
        size_t length = 0;

        LOGGER_IS_LOGGED_INFO("clear_parts()...");
        clear_parts();

        LOGGER_IS_LOGGED_INFO("(chars = this->has_chars(length))...");
        if ((chars = this->has_chars(length))) {

            LOGGER_IS_LOGGED_INFO("separator.separate(chars = \"" << chars << "\", length = " << length << ")...");
            if (!(separator.separate(chars, length))) {
                LOGGER_IS_LOGGED_ERROR("...failed on separator.separate(chars = \"" << chars << "\", length = " << length << ")");
                clear_parts();
            } else {
            }
        } else {
            LOGGER_IS_LOGGED_INFO("...failed on (chars = this->has_chars(length))");
        }
        return *this;
    }

    /// assign
    using extends::assign;
    virtual patht& assign(const wchar_t* chars, size_t length) {
        return *this;
    }
    virtual patht& assign(const wchar_t* chars) {
        return *this;
    }

    /// ...clear...
    virtual patht& clear() {
        clear_parts();
        extends::clear();
        return *this;
    }
    virtual patht& clear_parts() {
        is_network_ = is_root_ = is_root_directory_ = false;
        host_.clear();
        volume_.clear();
        directory_.clear();
        file_path_.clear();
        file_base_path_.clear();
        file_name_.clear();
        file_base_.clear();
        file_extension_.clear();
        return *this;
    }

    /// ...host... / ...volume... / ...directory...
    virtual const string_t& set_host(const char_t* chars, size_t length) {
        host_.assign(chars, length);
        return host_;
    }
    virtual const string_t& set_host(const char_t* chars) {
        host_.assign(chars);
        return host_;
    }
    virtual const string_t& host() const {
        return host_;
    }

    virtual const string_t& set_volume(const char_t* chars, size_t length) {
        volume_.assign(chars, length);
        return volume_;
    }
    virtual const string_t& set_volume(const char_t* chars) {
        volume_.assign(chars);
        return volume_;
    }
    virtual const string_t& volume() const {
        return volume_;
    }

    virtual const string_t& set_directory(const char_t* chars, size_t length) {
        directory_.assign(chars, length);
        return directory_;
    }
    virtual const string_t& set_directory(const char_t* chars) {
        directory_.assign(chars);
        return directory_;
    }
    virtual const string_t& directory() const {
        return directory_;
    }

    /// ...file...
    virtual const string_t& set_file_path(const char_t* chars, size_t length) {
        file_path_.assign(chars, length);
        return file_path_;
    }
    virtual const string_t& set_file_path(const char_t* chars) {
        file_path_.assign(chars);
        return file_path_;
    }
    virtual const string_t& file_path() const {
        return file_path_;
    }

    virtual const string_t& set_file_base_path(const char_t* chars, size_t length) {
        file_base_path_.assign(chars, length);
        return file_base_path_;
    }
    virtual const string_t& set_file_base_path(const char_t* chars) {
        file_base_path_.assign(chars);
        return file_base_path_;
    }
    virtual const string_t& file_base_path() const {
        return file_base_path_;
    }

    virtual const string_t& set_file_name(const char_t* chars, size_t length) {
        file_name_.assign(chars, length);
        return file_name_;
    }
    virtual const string_t& set_file_name(const char_t* chars) {
        file_name_.assign(chars);
        return file_name_;
    }
    virtual const string_t& file_name() const {
        return file_name_;
    }

    virtual const string_t& set_file_base(const char_t* chars, size_t length) {
        file_base_.assign(chars, length);
        return file_base_;
    }
    virtual const string_t& set_file_base(const char_t* chars) {
        file_base_.assign(chars);
        return file_base_;
    }
    virtual const string_t& file_base() const {
        return file_base_;
    }

    virtual const string_t& set_file_extension(const char_t* chars, size_t length) {
        file_extension_.assign(chars, length);
        return file_extension_;
    }
    virtual const string_t& set_file_extension(const char_t* chars) {
        file_extension_.assign(chars);
        return file_extension_;
    }
    virtual const string_t& file_extension() const {
        return file_extension_;
    }

    /// ...is...
    virtual bool& set_is_network(bool to) {
        return (bool&)is_network_;
    }
    virtual bool& is_network() const {
        return (bool&)is_network_;
    }
    virtual bool& set_is_root(bool to) {
        return (bool&)is_root_;
    }
    virtual bool& is_root() const {
        return (bool&)is_root_;
    }
    virtual bool& set_is_root_directory(bool to) {
        return (bool&)is_root_directory_;
    }
    virtual bool& is_root_directory() const {
        return (bool&)is_root_directory_;
    }

    /// ...separator
    virtual const char_t& volume_name_separator() const {
        return volume_name_separator_;
    }
    virtual const char_t& volume_directory_separator() const {
        return volume_directory_separator_;
    }
    virtual const char_t& directory_separator() const {
        return directory_separator_;
    }
    virtual const char_t& extension_separator() const {
        return extension_separator_;
    }

protected:
    /// on...
    virtual void on_host(const char_t* chars, size_t length) {
        host_.assign(chars, length);
        LOGGER_IS_LOGGED_INFO("...host = \"" << host_ << "\"");
    }
    virtual void on_volume(const char_t* chars, size_t length) {
        volume_.assign(chars, length);
        LOGGER_IS_LOGGED_INFO("...volume = \"" << volume_ << "\"");
    }
    virtual void on_root_directory() {
        directory_assign(&directory_separator_, 1);
        LOGGER_IS_LOGGED_INFO("...directory = \"" << directory_ << "\"");
    }
    virtual void on_current_directory() {
        on_append_directory();
        directory_append(&extension_separator_, 1);
        LOGGER_IS_LOGGED_INFO("...directory = \"" << directory_ << "\"");
    }
    virtual void on_parent_directory() {
        on_append_directory();
        directory_append(&extension_separator_, 1);
        directory_append(&extension_separator_, 1);
        LOGGER_IS_LOGGED_INFO("...directory = \"" << directory_ << "\"");
    }
    virtual void on_directory_name(const char_t* chars, size_t length) {
        on_append_directory();
        directory_append(chars, length);
        LOGGER_IS_LOGGED_INFO("...directory = \"" << directory_ << "\"");
    }
    virtual void on_file_name(const char_t* chars, size_t length) {
        on_append_base();
        file_base_path_.append(chars, length);
        file_name_.assign(chars, length);
        LOGGER_IS_LOGGED_INFO("...base = \"" << file_base_path_ << "\"");
        LOGGER_IS_LOGGED_INFO("...file name = \"" << file_name_ << "\"");
    }
    virtual void on_file_base(const char_t* chars, size_t length) {
        on_append_base();
        file_base_path_.append(chars, length);
        file_name_.assign(chars, length);
        file_base_.assign(chars, length);
        LOGGER_IS_LOGGED_INFO("...base = \"" << file_base_path_ << "\"");
        LOGGER_IS_LOGGED_INFO("...file base = \"" << file_base_ << "\"");
    }
    virtual void on_file_extension(const char_t* chars, size_t length) {
        file_name_.append(&extension_separator_, 1);
        file_name_.append(chars, length);
        file_extension_.assign(chars, length);
        LOGGER_IS_LOGGED_INFO("...file extension = \"" << file_extension_ << "\"");
    }

    /// on_append...
    virtual void on_append_directory() {
        const char_t* d_chars; size_t d_length;
        if ((d_chars = directory_.c_str()) && (d_length = directory_.length())) {
            if (directory_separator_ != (d_chars[d_length-1])) {
                directory_.append(&directory_separator_, 1);
            }
        }
        on_append_path();
        on_append_base();
    }
    virtual void on_append_path() {
        const char_t* d_chars; size_t d_length;
        if ((d_chars = file_path_.c_str()) && (d_length = file_path_.length())) {
            if (directory_separator_ != (d_chars[d_length-1])) {
                file_path_.append(&directory_separator_, 1);
            }
        }
    }
    virtual void on_append_base() {
        const char_t* d_chars; size_t d_length;
        if ((d_chars = file_base_path_.c_str()) && (d_length = file_base_path_.length())) {
            if (directory_separator_ != (d_chars[d_length-1])) {
                file_base_path_.append(&directory_separator_, 1);
            }
        }
    }

    /// directory...
    virtual void directory_assign(const char_t* chars, size_t length) {
        directory_.assign(chars, length);
        file_path_.assign(chars, length);
        file_base_path_.assign(chars, length);
    }
    virtual void directory_append(const char_t* chars, size_t length) {
        directory_.append(chars, length);
        file_path_.append(chars, length);
        file_base_path_.append(chars, length);
    }

private:
    virtual void construct(const patht& copy) {
        volume_name_separator_ = copy.volume_name_separator();
        volume_directory_separator_ = copy.volume_directory_separator();
        directory_separator_ = copy.directory_separator();
        extension_separator_ = copy.extension_separator();
        is_network_ = is_root_ = is_root_directory_ = false;
    }
    virtual void construct() {
        volume_name_separator_ = ((char_t)':');
        volume_directory_separator_ = ((char_t)'\\');
        directory_separator_ = ((char_t)'/');
        extension_separator_ = ((char_t)'.');
        is_network_ = is_root_ = is_root_directory_ = false;
    }
    virtual void destruct() {
    }

protected:
    char_t volume_name_separator_, volume_directory_separator_, 
           directory_separator_, extension_separator_;
    bool is_network_, is_root_, is_root_directory_;
    string_t host_, volume_, directory_,
             file_path_, file_base_path_,
             file_name_, file_base_, file_extension_;
}; /// class patht
typedef patht<> path;

} /// namespace fs 
} /// namespace xos 

#endif /// ndef XOS_FS_PATH_HPP
