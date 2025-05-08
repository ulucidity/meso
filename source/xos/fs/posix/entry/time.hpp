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
///   File: time.hpp
///
/// Author: $author$
///   Date: 1/6/2024
//////////////////////////////////////////////////////////////////////////
#ifndef XOS_FS_POSIX_ENTRY_TIME_HPP
#define XOS_FS_POSIX_ENTRY_TIME_HPP

#include "xos/fs/posix/entry/size.hpp"
#include "xos/fs/entry/time.hpp"

namespace xos {
namespace fs {
namespace posix {

/// enun time_when
typedef xos::fs::entry::time_when time_when;
enum {
    time_when_none     = xos::fs::entry::time_when_none,
    time_when_modified = xos::fs::entry::time_when_modified,
    time_when_accessed = xos::fs::entry::time_when_accessed,
    time_when_changed  = xos::fs::entry::time_when_changed,
    time_when_created  = xos::fs::entry::time_when_created
};/// enum time_when
typedef xos::fs::entry::time entry_time;

} /// namespace posix 
} /// namespace fs 
} /// namespace xos 

#endif /// ndef XOS_FS_POSIX_ENTRY_TIME_HPP
