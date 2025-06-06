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
///   File: os.hpp
///
/// Author: $author$
///   Date: 1/6/2024
//////////////////////////////////////////////////////////////////////////
#ifndef XOS_FS_OS_OS_HPP
#define XOS_FS_OS_OS_HPP

#include "xos/platform/os.hpp"

namespace xos {
namespace fs {

namespace apple { namespace ios {} namespace osx {} namespace mach {} } /// namespace apple
namespace microsoft { namespace windows { namespace crt {} } } /// namespace microsoft
namespace oracle { namespace solaris {} } /// namespace oracle
namespace google { namespace android {} } /// namespace google
namespace mach {} /// namespace mach
namespace linux {} /// namespace linux
namespace posix {} /// namespace posix

namespace os {

#if defined(WINDOWS)  
namespace os = microsoft::windows;
#elif defined(APPLEOSX)  
namespace os = apple::osx;
#elif defined(APPLEIOS)  
namespace os = apple::ios;
#elif defined(SOLARIS)  
namespace os = oracle::solaris;
#elif defined(MACH)  
namespace os = mach;
#elif defined(LINUX)  
namespace os = linux;
#else /// defined(LINUX)  
namespace os = posix;
#endif /// defined(LINUX) 

} /// namespace os 
} /// namespace fs 
} /// namespace xos 

#endif /// ndef XOS_FS_OS_OS_HPP
