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
///   File: nodes.cpp
///
/// Author: $author$
///   Date: 1/2/2024
//////////////////////////////////////////////////////////////////////////
#include "xos/tree/nodes.hpp"

#ifndef XOS_TREE_NODES_INSTANCE
/// #define XOS_TREE_NODES_INSTANCE 
#else /// ndef XOS_TREE_NODES_INSTANCE 
#endif /// ndef XOS_TREE_NODES_INSTANCE 

namespace xos {
namespace tree {

/// class nodest
#ifdef XOS_TREE_NODES_INSTANCE
static nodes the_nodes;
#endif /// def XOS_TREE_NODES_INSTANCE 

} /// namespace tree 
} /// namespace xos 
