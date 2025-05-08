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
///   File: find.hpp
///
/// Author: $author$
///   Date: 1/22/2024
//////////////////////////////////////////////////////////////////////////
#ifndef XOS_APP_CONSOLE_ARCHA_FIND_HPP
#define XOS_APP_CONSOLE_ARCHA_FIND_HPP

#include "xos/app/console/archa/branch.hpp"
#include "xos/tree/find.hpp"
#include "xos/base/logged.hpp"

namespace xos {
namespace app {
namespace console {
namespace archa {

typedef logged find_implements;

/// class find
class exported find: virtual public find_implements {
public:
    typedef find_implements implements;
    typedef find derives;

    typedef archa::branch branch_t;
    typedef archa::leaf leaf_t;
    typedef archa::node node_t;
    
    /// constructor / destructor
    virtual ~find() {
    }

    /// ...found...
    virtual branch_t* found(branch_t* b) {
        return 0;
    }
    virtual leaf_t* found(leaf_t* l) {
        return 0;
    }

protected:
}; /// class find

} /// namespace archa 
} /// namespace console 
} /// namespace app 
} /// namespace xos 

#endif /// ndef XOS_APP_CONSOLE_ARCHA_FIND_HPP
