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
///   File: dirent.hpp
///
/// Author: $author$
///   Date: 1/7/2024
//////////////////////////////////////////////////////////////////////////
#ifndef XOS_FS_POSIX_DIRECTORY_DIRENT_HPP
#define XOS_FS_POSIX_DIRECTORY_DIRENT_HPP

#include "xos/fs/posix/entry.hpp"
#include <dirent.h>

namespace xos {
namespace fs {
namespace posix {
namespace directory {

/// class direntt
template <class TExtends = extend, class TImplements = typename TExtends::implements>
class exported direntt: virtual public TImplements, public TExtends {
public:
    typedef TImplements implements;
    typedef TExtends extends;
    typedef direntt derives;

    typedef struct dirent struct_dirent_t;

    /// constructor / destructor
    direntt(const struct_dirent_t* struct_dirent): struct_dirent_(struct_dirent) {
    }
    direntt(const direntt &copy): struct_dirent_(copy.struct_dirent()) {
    }
    direntt(): struct_dirent_(0) {
    }
    virtual ~direntt() {
    }

    /// operator ...
    virtual direntt& operator = (const struct_dirent_t* struct_dirent) {
        struct_dirent_ = struct_dirent;
        return *this;
    }
    virtual const struct_dirent_t& operator -> () const { 
        return *struct_dirent_; 
    }
    virtual const struct_dirent_t& operator * () const { 
        return *struct_dirent_; 
    }
    virtual const struct_dirent_t* operator & () const { 
        return struct_dirent_; 
    }
    virtual operator const struct_dirent_t*() const { 
        return struct_dirent_; 
    }

protected:
    const struct_dirent_t* struct_dirent_;
}; /// class direntt
typedef direntt<> dirent_t;

} /// namespace directory 
} /// namespace posix 
} /// namespace fs 
} /// namespace xos 

#endif /// ndef XOS_FS_POSIX_DIRECTORY_DIRENT_HPP
