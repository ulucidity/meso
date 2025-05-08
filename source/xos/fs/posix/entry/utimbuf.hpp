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
///   File: utimbuf.hpp
///
/// Author: $author$
///   Date: 1/6/2024
//////////////////////////////////////////////////////////////////////////
#ifndef XOS_FS_POSIX_ENTRY_UTIMBUF_HPP
#define XOS_FS_POSIX_ENTRY_UTIMBUF_HPP

#include "xos/fs/posix/entry/stat.hpp"
#include <utime.h>

namespace xos {
namespace fs {
namespace posix {

/// class entry_utimbuft
template <class TExtends = extend, class TImplements = typename TExtends::implements>
class exported entry_utimbuft: virtual public TImplements, public TExtends {
public:
    typedef TImplements implements;
    typedef TExtends extends;
    typedef entry_utimbuft derives;

    typedef struct utimbuf struct_utimbuf_t;

    /// constructor / destructor
    entry_utimbuft(const entry_utimbuft &copy): extends(copy) {
        construct(copy);
    }
    entry_utimbuft() {
        construct();
    }
    virtual ~entry_utimbuft() {
        destruct();
    }

    /// utimbuf
    virtual struct_utimbuf_t& utimbuf() const { 
        return (struct_utimbuf_t&)struct_utimbuf_; 
    }
    virtual struct_utimbuf_t* operator & () const { 
        return (struct_utimbuf_t*)&struct_utimbuf_; 
    }
    virtual operator struct_utimbuf_t&() const { 
        return (struct_utimbuf_t&)struct_utimbuf_; 
    }

private:
    /// construct / destruct
    virtual void construct(const entry_utimbuft &copy) {
        ::memcpy(&struct_utimbuf_, &copy.utimbuf(), sizeof(struct_utimbuf_));
    }
    virtual void construct() {
        ::memset(&struct_utimbuf_, 0, sizeof(struct_utimbuf_));
    }
    virtual void destruct() {
    }

protected:
    struct_utimbuf_t struct_utimbuf_;
}; /// class entry_utimbuft
typedef entry_utimbuft<> entry_utimbuf;

} /// namespace posix 
} /// namespace fs 
} /// namespace xos 

#endif /// ndef XOS_FS_POSIX_ENTRY_UTIMBUF_HPP
