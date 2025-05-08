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
///   File: stat.hpp
///
/// Author: $author$
///   Date: 1/6/2024
//////////////////////////////////////////////////////////////////////////
#ifndef XOS_FS_POSIX_ENTRY_STAT_HPP
#define XOS_FS_POSIX_ENTRY_STAT_HPP

#include "xos/fs/posix/entry/type.hpp"
#include <sys/stat.h>

namespace xos {
namespace fs {
namespace posix {

/// class entry_statt
template <class TExtends = extend, class TImplements = typename TExtends::implements>
class exported entry_statt: virtual public TImplements, public TExtends {
public:
    typedef TImplements implements;
    typedef TExtends extends;
    typedef entry_statt derives;

    typedef struct stat struct_stat_t;

    /// constructor / destructor
    entry_statt(const entry_statt &copy): extends(copy) {
        construct(copy);
    }
    entry_statt() {
        construct();
    }
    virtual ~entry_statt() {
        destruct();
    }

    /// struct_stat
    virtual struct_stat_t& struct_stat() const { 
        return (struct_stat_t&)struct_stat_; 
    }
    virtual struct_stat_t* operator & () const { 
        return (struct_stat_t*)&struct_stat_; 
    }
    virtual operator struct_stat_t&() const { 
        return (struct_stat_t&)struct_stat_; 
    }

private:
    virtual void construct(const entry_statt &copy) {
        ::memcpy(&struct_stat_, &copy.struct_stat(), sizeof(struct_stat_));
    }
    virtual void construct() {
        ::memset(&struct_stat_, 0, sizeof(struct_stat_));
    }
    virtual void destruct() {
    }

protected:
    struct_stat_t struct_stat_;
}; /// class entry_statt
typedef entry_statt<> entry_stat;

} /// namespace posix 
} /// namespace fs 
} /// namespace xos 

#endif /// ndef XOS_FS_POSIX_ENTRY_STAT_HPP
