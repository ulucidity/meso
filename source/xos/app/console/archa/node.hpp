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
///   File: node.hpp
///
/// Author: $author$
///   Date: 1/21/2024
//////////////////////////////////////////////////////////////////////////
#ifndef XOS_APP_CONSOLE_ARCHA_NODE_HPP
#define XOS_APP_CONSOLE_ARCHA_NODE_HPP

#include "xos/tree/search.hpp"
#include "xos/fs/os/directory/entry.hpp"

namespace xos {
namespace app {
namespace console {
namespace archa {

class node;
class leaf;
class branch;
typedef fs::entry::type_which entry_type;
typedef fs::directory::entry entry;
typedef entry node_extends;
typedef node_extends::implements node_implements;

/// class node
class exported node: virtual public node_implements, public node_extends {
public:
    typedef node_implements implements;
    typedef node_extends extends;
    typedef node derives;

    /// constructor / destructor
    node(const string_t& path, const string_t& name, fs::entry_type type) {
        construct(path.chars(), name.chars(), type);
    }
    node(const string_t& path, const fs::directory::entry& entry) {
        construct(path.chars(), entry);
    }
    node(const char* path, const char* name, fs::entry_type type) {
        construct(path, name, type);
    }
    node(const char* path, const fs::directory::entry& entry) {
        construct(path, entry);
    }
    node(const fs::directory::entry& entry) {
        construct(entry);
    }
    node(const node &copy) {
        construct(copy);
    }
    node() {
        construct();
    }
    virtual ~node() {
        destruct();
    }

    /// set
    using extends::set;
    node& set(const char* path, const char* name, fs::entry_type type) {
        this->set_path_name(path, name);
        this->set_path(path);
        this->set_name(name);
        this->set_type(type);
        return *this;
    }
    node& set(const char* path) {
        this->set_path_name(path);
        return *this;
    }

protected:
    /// construct / destruct
    void construct(const char* path, const char* name, fs::entry_type type) {
        construct();
        this->set_path_name(path, name);
        this->set_path(path);
        this->set_name(name);
        this->set_type(type);
    }
    void construct(const char* path, const fs::directory::entry& entry) {
        construct(entry);
        this->set_path_name(path);
    }
    void construct(const fs::directory::entry& entry) {
        construct();
        this->set(entry);
    }
    void construct() {
    }
    void destruct() {
    }

protected:
}; /// class node

} /// namespace archa 
} /// namespace console 
} /// namespace app 
} /// namespace xos 

#endif /// ndef XOS_APP_CONSOLE_ARCHA_NODE_HPP
