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
///   File: type.hpp
///
/// Author: $author$
///   Date: 1/5/2024
//////////////////////////////////////////////////////////////////////////
#ifndef XOS_FS_ENTRY_TYPE_HPP
#define XOS_FS_ENTRY_TYPE_HPP

#include "xos/fs/entry/time.hpp"

#define XOS_FS_ENTRY_TYPE_WHICH_NAME_NONE "none"
#define XOS_FS_ENTRY_TYPE_WHICH_NAME_FILE "file"
#define XOS_FS_ENTRY_TYPE_WHICH_NAME_DIRECTORY "directory"
#define XOS_FS_ENTRY_TYPE_WHICH_NAME_SYMBOLIC_LINK "symbolic-link"
#define XOS_FS_ENTRY_TYPE_WHICH_NAME_HARD_LINK "hard-link"
#define XOS_FS_ENTRY_TYPE_WHICH_NAME_BLOCK_DEVICE "block-device"
#define XOS_FS_ENTRY_TYPE_WHICH_NAME_CHAR_DEVICE "char-device"
#define XOS_FS_ENTRY_TYPE_WHICH_NAME_PIPE "pipe"
#define XOS_FS_ENTRY_TYPE_WHICH_NAME_SOCKET "socket"

namespace xos {
namespace fs {
namespace entry {

/// enum type_which
typedef int type_which;
enum {
    type_none = 0,

    type_file          = 1,
    type_directory     = (type_file << 1),
    type_symbolic_link = (type_directory << 1),
    type_hard_link     = (type_symbolic_link << 1),
    type_block_device  = (type_hard_link << 1),
    type_char_device   = (type_block_device << 1),
    type_pipe          = (type_char_device << 1),
    type_socket        = (type_pipe << 1),

    first_type = type_file,
    last_type = type_socket,
    next_type = (last_type << 1),

    type_any = (next_type - 1)
};/// enum type_which

/// class typet
template <class TExtends = extend, class TImplements = typename TExtends::implements>
class exported typet: virtual public TImplements, public TExtends {
public:
    typedef TImplements implements;
    typedef TExtends extends;
    typedef typet derives;

    /// constructor / destructor
    typet(const type_which& which): which_(which) {
    }
    typet(const typet &copy): which_(copy.which()) {
    }
    typet(): which_(type_none) {
    }
    virtual ~typet() {
    }

    /// clear...
    virtual typet& clear() {
        which_ = type_none;
        return *this;
    }
    virtual typet& operator = (type_which which) {
        which_ = which;
        return *this;
    }
    virtual typet& operator |= (type_which which) {
        which_ |= which;
        return *this;
    }
    virtual typet& operator &= (type_which which) {
        which_ &= which;
        return *this;
    }

    /// name / which
    virtual const char* name() const {
        return name(which_);
    }
    virtual operator const char* () const {
        return name(which_);
    }
    virtual type_which which() const {
        return which_;
    }
    virtual operator type_which() const {
        return which_;
    }

    /// name / of
    static const char* name(type_which of) {
        switch (of) {
        case type_file          : return XOS_FS_ENTRY_TYPE_WHICH_NAME_FILE;
        case type_directory     : return XOS_FS_ENTRY_TYPE_WHICH_NAME_DIRECTORY;
        case type_symbolic_link : return XOS_FS_ENTRY_TYPE_WHICH_NAME_SYMBOLIC_LINK;
        case type_hard_link     : return XOS_FS_ENTRY_TYPE_WHICH_NAME_HARD_LINK;
        case type_block_device  : return XOS_FS_ENTRY_TYPE_WHICH_NAME_BLOCK_DEVICE;
        case type_char_device   : return XOS_FS_ENTRY_TYPE_WHICH_NAME_CHAR_DEVICE;
        case type_pipe          : return XOS_FS_ENTRY_TYPE_WHICH_NAME_PIPE;
        case type_socket        : return XOS_FS_ENTRY_TYPE_WHICH_NAME_SOCKET;
        }
        return XOS_FS_ENTRY_TYPE_WHICH_NAME_NONE;
    }
    static type_which of(const char* name) {
        return type_none;
    }

protected:
    type_which which_;
}; /// class typet
typedef typet<> type;

} /// namespace entry 

/// enum entry_type_which
typedef entry::type_which entry_type_which;
enum {
    entry_type_none = entry::type_none,
    entry_type_file = entry::type_file,
    entry_type_directory = entry::type_directory,
};/// enum entry_type_which
typedef entry::type entry_type;

} /// namespace fs 
} /// namespace xos 

#endif /// ndef XOS_FS_ENTRY_TYPE_HPP
