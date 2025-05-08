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
///   File: branch.hpp
///
/// Author: $author$
///   Date: 1/21/2024
//////////////////////////////////////////////////////////////////////////
#ifndef XOS_APP_CONSOLE_ARCHA_BRANCH_HPP
#define XOS_APP_CONSOLE_ARCHA_BRANCH_HPP

#include "xos/app/console/archa/leaf.hpp"
#include "xos/tree/search.hpp"
#include "xos/fs/os/directory/entry.hpp"
#include "xos/fs/os/directory/path.hpp"

namespace xos {
namespace app {
namespace console {
namespace archa {

typedef xos::tree::leavest<leaf> leaves;
typedef xos::tree::branchest<branch> branches;
typedef xos::tree::brancht<branch, branches, leaves, node> branch_extends;
typedef branch_extends::implements branch_implements;

/// class branch
class exported branch: virtual public branch_implements, public branch_extends {
public:
    typedef branch_implements implements;
    typedef branch_extends extends;
    typedef branch derives;

    /// constructor / destructor
    branch(const string_t& path, const string_t& name, fs::entry_type type) {
        construct(path.chars(), name.chars(), type);
    }
    branch(const string_t& path, const fs::directory::entry& entry) {
        construct(path.chars(), entry);
    }
    branch(const string_t& path) {
        construct(path.chars());
    }
    branch(const char* path, const char* name, fs::entry_type type) {
        construct(path, name, type);
    }
    branch(const char* path, const fs::directory::entry& entry) {
        construct(path, entry);
    }
    branch(const char* path) {
        construct(path);
    }
    branch(const fs::directory::entry& entry) {
        construct(entry);
    }
    branch(const branch &copy) {
        construct(copy);
    }
    branch() {
        construct();
    }
    virtual ~branch() {
        destruct();
    }

    /// ...leaves / ...branches
    virtual archa::leaves& leaves() const {
        get_branches();
        return extends::leaves();
    }
    virtual archa::branches& branches() const {
        get_branches();
        return extends::branches();
    }
    virtual archa::branches& get_branches() const {
        archa::branches& branches = extends::branches();
        archa::leaves& leaves = extends::leaves();
        bool& got_branches = this->got_branches();

        if (!(got_branches)) {
            const char_t* chars = 0;
            size_t length = 0;

            got_branches=(true);
            if ((fs::entry_type_directory == (this->type())) && (!this->is_circular())) {
                const char_t* directory_separator_chars = 0;
                string_t name(this->path_name());

                if ((chars = name.has_chars(length))) {
                    fs::os::directory::path path;

                    if ((chars = this->has_name(length))) {
                        if ((directory_separator_chars = this->directory_separator_chars()) 
                             && (chars[length-1] != directory_separator_chars[0])) {
                            name.append(directory_separator_chars);
                        }
                        name.append(chars, length);
                    }
                    LOGGER_IS_LOGGED_INFO("path.open(name = \"" << name << "\")...");
                    if ((path.open(name))) {
                        fs::os::directory::entry* entry = 0;
    
                        if ((entry = path.get_first_entry())) {
                            branch* b = 0;
                            leaf* l = 0;
                            do {
                                if ((fs::entry_type_directory == (entry->type())) && (!entry->is_circular())) {
                                    LOGGER_IS_LOGGED_INFO("new branch(name = \"" << name << "\", *entry)...")
                                    if ((b = new branch(name, *entry))) {
                                        branches.push_back(b);
                                    } else {
                                        LOGGER_IS_LOGGED_ERROR("...failed on new branch(name = \"" << name << "\", *entry)");
                                        break;
                                    }
                                } else {
                                    if (fs::entry_type_directory != (entry->type())) {
                                        LOGGER_IS_LOGGED_INFO("new leaf(name = \"" << name << "\", *entry)...")
                                        if ((l = new leaf(name, *entry))) {
                                            leaves.push_back(l);
                                        } else {
                                            LOGGER_IS_LOGGED_ERROR("...failed on new leaf(name = \"" << name << "\", *entry)");
                                            break;
                                        }
                                    }
                                }
                                entry = path.get_next_entry();
                            } while ((entry));
                        }
                        path.close();
                    } else {
                        LOGGER_IS_LOGGED_ERROR("...failed on path.open(name = \"" << name << "\")");
                    }
                }
            }
        }
        return branches;
    }
    virtual bool& got_branches() const {
        return (bool&)got_branches_;
    }

private:
    /// construct / destruct
    void construct(const char* path, const char* name, fs::entry_type type) {
        construct();
        this->set(path, name, type);
    }
    void construct(const char* path, const fs::directory::entry& entry) {
        construct(entry);
        this->set(path);
    }
    void construct(const char* path) {
        construct();
        this->set(path);
        this->set_is_directory();
    }
    void construct(const fs::directory::entry& entry) {
        construct();
        this->set(entry);
    }
    void construct() {
        got_branches_=(false);
    }
    void destruct() {
    }

protected:
    bool got_branches_;
}; /// class branch

} /// namespace archa 
} /// namespace console 
} /// namespace app 
} /// namespace xos 

#endif /// ndef XOS_APP_CONSOLE_ARCHA_BRANCH_HPP
