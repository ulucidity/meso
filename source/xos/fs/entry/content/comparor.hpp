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
#ifndef XOS_FS_ENTRY_CONTENT_COMPAROR_HPP
#define XOS_FS_ENTRY_CONTENT_COMPAROR_HPP

#include "xos/fs/entry/comparor/extend.hpp"
#include "xos/io/crt/file/reader.hpp"

namespace xos {
namespace fs {
namespace entry {
namespace content {

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

        LOGGER_IS_LOGGED_INFO("(compares = (0 != (unequal = compare(entry, path, to_entry, to_path)))}...");
        if ((compares = (0 != (unequal = compare(entry, path, to_entry, to_path))))) {
            LOGGER_IS_LOGGED_INFO("...(" << compares << " = (0 != (" << unequal << " = compare(entry, path, to_entry, to_path))))");
        } else {
            LOGGER_IS_LOGGED_INFO("...failed on (" << compares << " = (0 != (" << unequal << " = compare(entry, path, to_entry, to_path))))");
        }
        return compares;
    }
    virtual int compare(const entry_t& entry, const string_t &path, const entry_t& to_entry, const string_t &to_path) const {
        int unequal = 0;
        size_t path_length = 0;
        const char_t *path_chars = 0;

        LOGGER_IS_LOGGED_INFO("(path_chars = path.has_chars(path_length))...");
        if ((path_chars = path.has_chars(path_length))) {
            size_t to_path_length = 0;
            const char_t *to_path_chars = 0;

            LOGGER_IS_LOGGED_INFO("...(\"" << path_chars << "\" = path.has_chars(" << path_length << "))");
            LOGGER_IS_LOGGED_INFO("(to_path_chars = to_path.has_chars(to_path_length))...");
            if ((to_path_chars = to_path.has_chars(to_path_length))) {
                ::xos::io::crt::file::reader reader;

                LOGGER_IS_LOGGED_INFO("...(\"" << to_path_chars << "\" = to_path.has_chars(" << to_path_length << "))");
                LOGGER_IS_LOGGED_INFO("(reader.open(\"" << path_chars << "\"))...");
                if ((reader.open(path_chars))) {
                    ::xos::io::crt::file::reader to_reader;

                    LOGGER_IS_LOGGED_INFO("...(reader.open(\"" << path_chars << "\"))");
                    LOGGER_IS_LOGGED_INFO("(to_reader.open(\"" << to_path_chars << "\"))...");
                    if ((to_reader.open(to_path_chars))) {
                        LOGGER_IS_LOGGED_INFO("...(to_reader.open(\"" << to_path_chars << "\"))");
                        LOGGER_IS_LOGGED_INFO("(unequal = compare(reader, to_reader))...");
                        if ((unequal = compare(reader, to_reader))) {
                            LOGGER_IS_LOGGED_INFO("...(unequal = compare(reader, to_reader))");
                        } else {
                            LOGGER_IS_LOGGED_INFO("...failed on (unequal = compare(reader, to_reader))");
                        }
                        LOGGER_IS_LOGGED_INFO("(to_reader.close())...");
                        if ((to_reader.close())) {
                            LOGGER_IS_LOGGED_INFO("...(to_reader.close())");
                        } else {
                            LOGGER_IS_LOGGED_INFO("...failed on (to_reader.close())");
                        }
                    } else {
                        LOGGER_IS_LOGGED_INFO("...failed on (to_reader.open(\"" << to_path_chars << "\"))");
                        LOGGER_IS_LOGGED_INFO("unequal = 1...");
                        unequal = 1;
                    }
                    LOGGER_IS_LOGGED_INFO("(reader.close())...");
                    if ((reader.close())) {
                        LOGGER_IS_LOGGED_INFO("...(reader.close())");
                    } else {
                        LOGGER_IS_LOGGED_INFO("...failed on (reader.close())");
                    }
                } else {
                    ::xos::io::crt::file::reader to_reader;

                    LOGGER_IS_LOGGED_INFO("...failed on (reader.open(\"" << path_chars << "\"))");
                    LOGGER_IS_LOGGED_INFO("(to_reader.open(\"" << to_path_chars << "\"))...");
                    if ((to_reader.open(to_path_chars))) {
                        LOGGER_IS_LOGGED_INFO("...(to_reader.open(\"" << to_path_chars << "\"))");
                        LOGGER_IS_LOGGED_INFO("unequal = -1...");
                        unequal = -1;
                        LOGGER_IS_LOGGED_INFO("(to_reader.close())...");
                        if ((to_reader.close())) {
                            LOGGER_IS_LOGGED_INFO("...(to_reader.close())");
                        } else {
                            LOGGER_IS_LOGGED_INFO("...failed on (to_reader.close())");
                        }
                    } else {
                        LOGGER_IS_LOGGED_INFO("...failed on (to_reader.open(\"" << to_path_chars << "\"))");
                    }
                }
            } else {
                LOGGER_IS_LOGGED_INFO("...failed on (to_path_chars = to_path.has_chars(" << to_path_length << "))");
            }
        } else {
            LOGGER_IS_LOGGED_INFO("...failed on (path_chars = path.has_chars(" << path_length << "))");
        }
        return unequal;
    }
    virtual int compare(::xos::io::crt::file::reader &reader, ::xos::io::crt::file::reader &to_reader) const {
        int unequal = 0;
        ssize_t amount = 0, to_amount = 0;
        char c = 0, to_c = 0;

        do {
            if ((0 < (amount = reader.read(&c, 1)))) {
                if ((0 < (to_amount = to_reader.read(&to_c, 1)))) {
                    if ((c > to_c)) {
                        LOGGER_IS_LOGGED_INFO("...(c = " << c << " > to_c = " << to_c << ")");
                        LOGGER_IS_LOGGED_INFO("unequal = 1...");
                        unequal = 1;
                        break;
                    } else {
                        if ((c < to_c)) {
                            LOGGER_IS_LOGGED_INFO("...(c = " << c << " < to_c = " << to_c << ")");
                            LOGGER_IS_LOGGED_INFO("unequal = -1...");
                            unequal = -1;
                            break;
                        } else {
                        }
                    }
                } else {
                    LOGGER_IS_LOGGED_INFO("...failed on (0 < (" << to_amount << " = to_reader.read(&to_c, 1)");
                    LOGGER_IS_LOGGED_INFO("unequal = 1...");
                    unequal = 1;
                    break;
                }
            } else {
                LOGGER_IS_LOGGED_INFO("...failed on (0 < (" << amount << " = reader.read(&c, 1)");
                if ((0 < (to_amount = to_reader.read(&to_c, 1)))) {
                    LOGGER_IS_LOGGED_INFO("unequal = -1...");
                    unequal = -1;
                } else {
                    LOGGER_IS_LOGGED_INFO("...failed on (0 < (" << to_amount << " = to_reader.read(&to_c, 1)");
                }
            }
        } while ((0 < amount));
        return unequal;
    }

protected:
}; /// class comparort
typedef comparort<> comparor;

} /// namespace content 
} /// namespace entry 
} /// namespace fs 
} /// namespace xos 

#endif /// ndef XOS_FS_ENTRY_CONTENT_COMPAROR_HPP
