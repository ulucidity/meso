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
///   Date: 1/6/2024
//////////////////////////////////////////////////////////////////////////
#ifndef XOS_FS_POSIX_ENTRY_TYPE_HPP
#define XOS_FS_POSIX_ENTRY_TYPE_HPP

#include "xos/fs/posix/entry/time.hpp"
#include "xos/fs/entry/type.hpp"

namespace xos {
namespace fs {
namespace posix {

/// enum entry_type
typedef xos::fs::entry::type entry_type;
enum {
    entry_type_none          = xos::fs::entry::type_none,
    entry_type_file          = xos::fs::entry::type_file,
    entry_type_directory     = xos::fs::entry::type_directory,
    entry_type_symbolic_link = xos::fs::entry::type_symbolic_link,
    entry_type_hard_link     = xos::fs::entry::type_hard_link,
    entry_type_block_device  = xos::fs::entry::type_block_device,
    entry_type_char_device   = xos::fs::entry::type_char_device,
    entry_type_pipe          = xos::fs::entry::type_pipe,
    entry_type_socket        = xos::fs::entry::type_socket,
};/// enum entry_type

} /// namespace posix 
} /// namespace fs 
} /// namespace xos 

#endif /// ndef XOS_FS_POSIX_ENTRY_TYPE_HPP
