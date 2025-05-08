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
///   File: leaf.hpp
///
/// Author: $author$
///   Date: 1/21/2024
//////////////////////////////////////////////////////////////////////////
#ifndef XOS_APP_CONSOLE_ARCHA_LEAF_HPP
#define XOS_APP_CONSOLE_ARCHA_LEAF_HPP

#include "xos/app/console/archa/node.hpp"
#include "xos/tree/leaf.hpp"

namespace xos {
namespace app {
namespace console {
namespace archa {

typedef xos::tree::leaft<branch, node> leaf_extends;
typedef leaf_extends::implements leaf_implements;

/// class leaf
class exported leaf: virtual public leaf_implements, public leaf_extends {
public:
    typedef leaf_implements implements;
    typedef leaf_extends extends;
    typedef leaf derives;

    /// constructor / destructor
    leaf(const string_t& path, const string_t& name, fs::entry_type type) {
        construct(path.chars(), name.chars(), type);
    }
    leaf(const string_t& path, const fs::directory::entry& entry) {
        construct(path.chars(), entry);
    }
    leaf(const char* path, const char* name, fs::entry_type type) {
        construct(path, name, type);
    }
    leaf(const char* path, const fs::directory::entry& entry) {
        construct(path, entry);
    }
    leaf(const fs::directory::entry& entry) {
        construct(entry);
    }
    leaf(const leaf &copy) {
        construct(copy);
    }
    leaf() {
        construct();
    }
    virtual ~leaf() {
        destruct();
    }

protected:
    /// construct / destruct
    void construct(const char* path, const char* name, fs::entry_type type) {
        construct();
        this->set(path, name, type);
    }
    void construct(const char* path, const fs::directory::entry& entry) {
        construct(entry);
        this->set(path);
    }
    void construct(const fs::directory::entry& entry) {
        extends::construct(entry);
        construct();
    }
    void construct() {
    }
    void destruct() {
    }

protected:
}; /// class leaf

} /// namespace archa 
} /// namespace console 
} /// namespace app 
} /// namespace xos 

#endif /// ndef XOS_APP_CONSOLE_ARCHA_LEAF_HPP
