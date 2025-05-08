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
///   File: entry.hpp
///
/// Author: $author$
///   Date: 1/7/2024
//////////////////////////////////////////////////////////////////////////
#ifndef XOS_FS_OS_DIRECTORY_ENTRY_HPP
#define XOS_FS_OS_DIRECTORY_ENTRY_HPP

#include "xos/fs/os/os.hpp"

#if defined(WINDOWS)  
#include "xos/fs/microsoft/windows/directory/entry.hpp"
#elif defined(APPLEOSX)  
#include "xos/fs/apple/osx/directory/entry.hpp"
#elif defined(APPLEIOS)  
#include "xos/fs/apple/ios/directory/entry.hpp"
#elif defined(SOLARIS)  
#include "xos/fs/oracle/solaris/directory/entry.hpp"
#elif defined(MACH)  
#include "xos/fs/mach/directory/entry.hpp"
#elif defined(LINUX)  
#include "xos/fs/linux/directory/entry.hpp"
#else /// defined(LINUX)  
#include "xos/fs/posix/directory/entry.hpp"
#endif /// defined(LINUX) 

namespace xos {
namespace fs {
namespace os {
namespace directory {

typedef fs::os::os::directory::entry entry;

} /// namespace directory 
} /// namespace os 
} /// namespace fs 
} /// namespace xos 

#endif /// ndef XOS_FS_OS_DIRECTORY_ENTRY_HPP
