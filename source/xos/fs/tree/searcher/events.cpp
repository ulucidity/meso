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
///   File: events.cpp
///
/// Author: $author$
///   Date: 1/8/2024
//////////////////////////////////////////////////////////////////////////
#include "xos/fs/tree/searcher/events.hpp"

#ifndef XOS_FS_TREE_SEARCHER_EVENTS_INSTANCE
/// #define XOS_FS_TREE_SEARCHER_EVENTS_INSTANCE 
#else /// ndef XOS_FS_TREE_SEARCHER_EVENTS_INSTANCE 
#endif /// ndef XOS_FS_TREE_SEARCHER_EVENTS_INSTANCE 

namespace xos {
namespace fs {
namespace tree {

/// class eventst
#ifdef XOS_FS_TREE_SEARCHER_EVENTS_INSTANCE
static searcher_events the_searcher_events;
#endif /// def XOS_FS_TREE_SEARCHER_EVENTS_INSTANCE 

} /// namespace tree 
} /// namespace fs 
} /// namespace xos 
