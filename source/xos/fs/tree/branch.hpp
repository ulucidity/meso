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
///   Date: 1/8/2024
//////////////////////////////////////////////////////////////////////////
#ifndef XOS_FS_TREE_BRANCH_HPP
#define XOS_FS_TREE_BRANCH_HPP

#include "xos/tree/branch.hpp"
#include "xos/fs/os/directory/path.hpp"
#include "xos/fs/os/directory/entry.hpp"
#include "xos/fs/tree/leaf.hpp"

namespace xos {
namespace fs {
namespace tree {

typedef xos::tree::branchest<branch> branches;
typedef xos::tree::brancht<branch, branches, leaves, node> branch_extends;
typedef branch_extends::implements branch_implements;
/// class branch
class exported branch: virtual public branch_implements, public branch_extends {
public:
    typedef branch_implements implements;
    typedef branch_extends extends;
    typedef branch derives;

    typedef extends::string_t string_t;
    typedef string_t::char_t char_t;

    /// constructor / destructor
    branch(const branch &copy) {
        construct(copy);
    }
    branch() {
        construct();
    }
    virtual ~branch() {
        destruct();
    }

    /// clear / operator...
    branch(const string_t& path) {
        construct(path.chars());
    }
    branch(const char* path) {
        construct(path);
    }
    branch(const string_t& path, const fs::directory::entry& entry) {
        construct(path.chars(), entry);
    }
    branch(const char* path, const fs::directory::entry& entry) {
        construct(path, entry);
    }
    branch(const fs::directory::entry& entry) {
        construct(entry);
    }
    branch(const node& node) {
        construct(node);
    }
    virtual branch& clear() {
        extends::clear();
        got_branches_ = (true);
        leaves().delete_all();
        branches().delete_all();
    }
    virtual branch& operator = (const char* path) {
        clear();
        LOGGER_IS_LOGGED_INFO("this->set(" << path << ", fs::entry_type_directory)...");
        this->set(path, fs::entry_type_directory);
        got_branches_ = (false);
        return *this;
    }
    virtual branch& operator = (const fs::directory::entry& entry) {
        clear();
        LOGGER_IS_LOGGED_INFO("this->set(entry)...");
        this->set(entry);
        return *this;
    }
    virtual branch& operator = (const branch& copy) {
        clear();
        this->set(copy);
        return *this;
    }

    /// leaves / branches
    virtual tree::leaves& leaves() const {
        get_branches();
        return extends::leaves();
    }
    virtual tree::branches& branches() const {
        get_branches();
        return extends::branches();
    }
    virtual bool& got_branches() const {
        return (bool&)got_branches_;
    }

    /// clone
    virtual branch* clone(const node& parent, const node& node) const {
        return extends::clone<branch>(parent, node);
    }
    virtual branch* clone(const node& node) const {
        return new branch(node);
    }
    virtual branch* clone() const {
        return new branch(*this);
    }
    virtual operator branch* () const {
        return (branch*)this;
    }

protected:
    virtual tree::branches& get_branches() const {
        tree::branches& branches = extends::branches();
        tree::leaves& leaves = extends::leaves();
        bool& got_branches = this->got_branches();

        if (!(got_branches)) {
            const char_t* chars = 0;
            size_t length = 0;

            got_branches = (true);
            LOGGER_IS_LOGGED_INFO("(this->is_normal_directory())...");
            if ((this->is_normal_directory())) {
                const char_t* directory_separator_chars = 0;
                string_t name(this->path_name());

                if ((chars = name.has_chars(length))) {
                    if ((directory_separator_chars = this->directory_separator_chars()) 
                         && (chars[length-1] != directory_separator_chars[0])) {
                        name.append(directory_separator_chars);
                    }
                }
                LOGGER_IS_LOGGED_INFO("(chars = this->name(length))...");
                if ((chars = this->name(length))) {
                    fs::os::directory::path path;

                    name.append(chars, length);
                    LOGGER_IS_LOGGED_INFO("path.open(name = \"" << name << "\")...");
                    if ((path.open(name))) {
                        fs::os::directory::entry* entry = 0;

                        LOGGER_IS_LOGGED_INFO("(entry = path.get_first_entry())...");
                        if ((entry = path.get_first_entry())) {
                            branch* b = 0;
                            leaf* l = 0;
                            do {
                                LOGGER_IS_LOGGED_INFO("(entry->is_normal_directory())...");
                                if ((entry->is_normal_directory())) {
                                    LOGGER_IS_LOGGED_INFO("new branch(name = \"" << name << "\", *entry)...")
                                    if ((b = new branch(name, *entry))) {
                                        b->set_depth(this->depth()+1);
                                        branches.push_back(b);
                                    } else {
                                        LOGGER_IS_LOGGED_ERROR("...failed on new branch(name = \"" << name << "\", *entry)");
                                        break;
                                    }
                                } else {
                                    LOGGER_IS_LOGGED_INFO("(entry->is_directory())...");
                                    if (!(entry->is_directory())) {
                                        LOGGER_IS_LOGGED_INFO("new leaf(name = \"" << name << "\", *entry)...")
                                        if ((l = new leaf(name, *entry))) {
                                            l->set_depth(this->depth()+1);
                                            leaves.push_back(l);
                                        } else {
                                            LOGGER_IS_LOGGED_ERROR("...failed on new leaf(name = \"" << name << "\", *entry)");
                                            break;
                                        }
                                    }
                                }
                                LOGGER_IS_LOGGED_INFO("entry = path.get_next_entry()...");
                                entry = path.get_next_entry();
                            } while ((entry));
                        } else {
                            LOGGER_IS_LOGGED_INFO("...failed on (entry = path.get_first_entry())");
                        }
                        LOGGER_IS_LOGGED_INFO("path.close()...");
                        path.close();
                    } else {
                        LOGGER_IS_LOGGED_ERROR("...failed on path.open(name = \"" << name << "\")");
                    }
                } else {
                    LOGGER_IS_LOGGED_INFO("...failed on (chars = this->name(length))");
                }
            } else {
                LOGGER_IS_LOGGED_INFO("...failed on (this->is_normal_directory())");
            }
        }
        return branches;
    }

private:
    void construct(const char* path) {
        this->set(path, fs::entry_type_directory);
        got_branches_ = (false);
    }
    void construct(const char* path, const fs::directory::entry& entry) {
        this->set(path, entry);
        got_branches_ = (false);
    }
    void construct(const fs::directory::entry& entry) {
        this->set(entry);
        got_branches_ = (true);
    }
    void construct(const node& node) {
        this->set(node);
        got_branches_ = (true);
    }
    void construct(const branch& copy) {
        this->set(copy);
        got_branches_ = (true);
    }
    void construct() {
        got_branches_ = (true);
    }
    void destruct() {
        got_branches_ = (true);
        leaves().delete_all();
        branches().delete_all();
    }

protected:
    bool got_branches_;
}; /// class branch

} /// namespace tree 
} /// namespace fs 
} /// namespace xos 

#endif /// ndef XOS_FS_TREE_BRANCH_HPP
