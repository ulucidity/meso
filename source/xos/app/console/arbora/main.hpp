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
///   File: main.hpp
///
/// Author: $author$
///   Date: 1/4/2024, 1/31/2024
//////////////////////////////////////////////////////////////////////////
#ifndef XOS_APP_CONSOLE_ARBORA_MAIN_HPP
#define XOS_APP_CONSOLE_ARBORA_MAIN_HPP

#include "xos/app/console/arbora/main_opt.hpp"
#include "xos/fs/path_separator.hpp"
#include "xos/fs/path.hpp"
#include "xos/fs/entry/size.hpp"
#include "xos/fs/entry/time.hpp"
#include "xos/fs/entry/type.hpp"
#include "xos/fs/entry/extend.hpp"
#include "xos/fs/directory/entry.hpp"
#include "xos/fs/os/entry.hpp"
#include "xos/fs/os/directory/entry.hpp"
#include "xos/fs/os/directory/path.hpp"
#include "xos/fs/tree/searcher.hpp"

namespace xos {
namespace app {
namespace console {
namespace arbora {

/// class maint
template 
<class TEvents = xos::fs::tree::searcher_events, 
 class TExtends = xos::app::console::arbora::main_optt<>,  class TImplements = typename TExtends::implements>

class maint: virtual public TEvents, virtual public TImplements, public TExtends {
public:
    typedef TImplements implements;
    typedef TExtends extends;
    typedef maint derives;

    typedef typename extends::char_t char_t;
    typedef typename extends::end_char_t end_char_t;
    enum { end_char = extends::end_char };
    typedef typename extends::string_t string_t;
    typedef typename extends::reader_t reader_t;
    typedef typename extends::writer_t writer_t;
    typedef typename extends::file_t file_t;

    /// constructor / destructor
    maint(): run_(0) {
    }
    virtual ~maint() {
    }
private:
    maint(const maint &copy) {
        throw exception(exception_unexpected);
    }

protected:
    typedef typename extends::in_reader_t in_reader_t;
    typedef typename extends::out_writer_t out_writer_t;
    typedef typename extends::err_writer_t err_writer_t;

    //////////////////////////////////////////////////////////////////////////
    /// run
    int (derives::*run_)(int argc, char_t** argv, char_t** env);
    virtual int run(int argc, char_t** argv, char_t** env) {
        int err = 0;
        if ((run_)) {
            err = (this->*run_)(argc, argv, env);
        } else {
            err = extends::run(argc, argv, env);
        }
        return err;
    }

    //////////////////////////////////////////////////////////////////////////
    /// ...depth_first_directory_search_run
    virtual int depth_first_directory_search_run(int argc, char_t** argv, char_t** env) {
        int err = 0; const char_t* chars = 0; size_t length = 0;
        const string_t& arg_string = this->arg_string();

        if ((chars = arg_string.has_chars(length))) {
            ssize_t count = 0;
            xos::fs::tree::depth_first_searcher searcher(this);
            xos::fs::tree::branch branch;
            
            LOGGER_IS_LOGGED_INFO("0 <= (count = searcher.search(branch, " << chars << "))...");
            if (0 <= (count = searcher.search(branch, chars))) {
                LOGGER_IS_LOGGED_INFO("...0 <= (" << count << " = searcher.search(branch, " << chars << "))");
            } else {
                LOGGER_IS_LOGGED_ERROR("...failed on 0 <= (" << count << " = searcher.search(branch, " << chars << "))");
            }
        } else {
            if (!(err = extends::run(argc, argv, env))) {
            } else {
            }
        }
        return err;
    }
    /// ...breadth_first_directory_search_run
    virtual int breadth_first_directory_search_run(int argc, char_t** argv, char_t** env) {
        int err = 0; const char_t* chars = 0; size_t length = 0;
        const string_t& arg_string = this->arg_string();

        if ((chars = arg_string.has_chars(length))) {
            ssize_t count = 0;
            xos::fs::tree::breadth_first_searcher searcher(this);
            xos::fs::tree::branch branch;
            
            LOGGER_IS_LOGGED_INFO("0 <= (count = searcher.search(branch, " << chars << "))...");
            if (0 <= (count = searcher.search(branch, chars))) {
                LOGGER_IS_LOGGED_INFO("...0 <= (" << count << " = searcher.search(branch, " << chars << "))");
            } else {
                LOGGER_IS_LOGGED_ERROR("...failed on 0 <= (" << count << " = searcher.search(branch, " << chars << "))");
            }
        } else {
            if (!(err = extends::run(argc, argv, env))) {
            } else {
            }
        }
        return err;
    }
    /// ...depend_first_directory_search_run
    virtual int depend_first_directory_search_run(int argc, char_t** argv, char_t** env) {
        int err = 0; const char_t* chars = 0; size_t length = 0;
        const string_t& arg_string = this->arg_string();

        if ((chars = arg_string.has_chars(length))) {
            ssize_t count = 0;
            xos::fs::tree::depend_first_searcher searcher(this);
            xos::fs::tree::branch branch;
            
            LOGGER_IS_LOGGED_INFO("0 <= (count = searcher.search(branch, " << chars << "))...");
            if (0 <= (count = searcher.search(branch, chars))) {
                LOGGER_IS_LOGGED_INFO("...0 <= (" << count << " = searcher.search(branch, " << chars << "))");
            } else {
                LOGGER_IS_LOGGED_ERROR("...failed on 0 <= (" << count << " = searcher.search(branch, " << chars << "))");
            }
        } else {
            if (!(err = extends::run(argc, argv, env))) {
            } else {
            }
        }
        return err;
    }
    /// ...bottom_first_directory_search_run
    virtual int bottom_first_directory_search_run(int argc, char_t** argv, char_t** env) {
        int err = 0; const char_t* chars = 0; size_t length = 0;
        const string_t& arg_string = this->arg_string();

        if ((chars = arg_string.has_chars(length))) {
            ssize_t count = 0;
            xos::fs::tree::bottom_first_searcher searcher(this);
            xos::fs::tree::branch branch;
            
            LOGGER_IS_LOGGED_INFO("0 <= (count = searcher.search(branch, " << chars << "))...");
            if (0 <= (count = searcher.search(branch, chars))) {
                LOGGER_IS_LOGGED_INFO("...0 <= (" << count << " = searcher.search(branch, " << chars << "))");
            } else {
                LOGGER_IS_LOGGED_ERROR("...failed on 0 <= (" << count << " = searcher.search(branch, " << chars << "))");
            }
        } else {
            if (!(err = extends::run(argc, argv, env))) {
            } else {
            }
        }
        return err;
    }
    //////////////////////////////////////////////////////////////////////////

    //////////////////////////////////////////////////////////////////////////
    /// ...directory_entry_run
    virtual int directory_entry_run(int argc, char_t** argv, char_t** env) {
        int err = 0, optind = ::optind;
        const char_t* arg = 0;

        if ((argc > (optind)) && (arg = argv[optind]) && (arg[0])) {
            string_t arg_string(arg);
            const char_t* chars = 0;
            size_t length = 0;
            
            if ((chars = arg_string.has_chars(length))) {
                ::xos::fs::os::directory::path path;
                
                LOGGER_IS_LOGGED_INFO("(path.open(" << chars << ", "<< length << "))...");
                if ((path.open(chars, length))) {
                    ::xos::fs::os::directory::path::entry_t *entry = 0;
                    
                    LOGGER_IS_LOGGED_INFO("...(path.open(" << chars << ", "<< length << "))");
                    LOGGER_IS_LOGGED_INFO("(entry = path.get_first_entry())...");
                    if ((entry = path.get_first_entry())) {
                        LOGGER_IS_LOGGED_INFO("...(entry = path.get_first_entry())");
                        do {
                            all_output_directory_entry_run(arg_string, *entry, argc, argv, env);
                            LOGGER_IS_LOGGED_INFO("(entry = path.get_next_entry())...");
                            if ((entry = path.get_next_entry())) {
                                LOGGER_IS_LOGGED_INFO("...(entry = path.get_next_entry())");
                            } else {
                                LOGGER_IS_LOGGED_INFO("...failed on (entry = path.get_next_entry())");
                            }
                        } while (entry);
                    } else {
                        LOGGER_IS_LOGGED_INFO("...failed on (entry = path.get_first_entry())");
                    }
                    LOGGER_IS_LOGGED_INFO("(path.close())...");
                    if ((path.close())) {
                        LOGGER_IS_LOGGED_INFO("...(path.close())");
                    } else {
                        LOGGER_IS_LOGGED_INFO("...failed on (path.close())");
                    }
                } else {
                    LOGGER_IS_LOGGED_INFO("...failed on (path.open(" << chars << ", "<< length << "))");
                }
            } else {
            }
        } else {
            err = extends::run(argc, argv, env);
        }
        return err;
    }
    //////////////////////////////////////////////////////////////////////////

    //////////////////////////////////////////////////////////////////////////
    /// ...file_entry_run
    virtual int file_entry_run(int argc, char_t** argv, char_t** env) {
        int err = 0, optind = ::optind;
        const char_t* arg = 0;

        if ((argc > (optind)) && (arg = argv[optind]) && (arg[0])) {
            string_t arg_string(arg);
            const char_t* chars = 0;
            size_t length = 0;
            
            if ((chars = arg_string.has_chars(length))) {
                bool exists = false;
                ::xos::fs::os::entry entry;
                
                LOGGER_IS_LOGGED_INFO("(exists = entry.exists(\"" << chars << "\", " << length << "))...");
                if ((exists = entry.exists(chars, length))) {
                    ::xos::fs::entry::type_which which = ::xos::fs::entry::type_none;

                    LOGGER_IS_LOGGED_INFO("...(" << exists << " = entry.exists(\"" << chars << "\", " << length << "))");
                    LOGGER_IS_LOGGED_INFO("(::xos::fs::entry::type_none != (which = entry.type().which()))...");
                    if (::xos::fs::entry::type_none != (which = entry.type().which())) {
                        LOGGER_IS_LOGGED_INFO("...(::xos::fs::entry::type_none != (" << which << " = entry.type().which()))");
                        LOGGER_IS_LOGGED_INFO("!(::xos::fs::entry::type_directory != (" << which << ")))...");
                        if (!(::xos::fs::entry::type_directory != (which))) {
                            LOGGER_IS_LOGGED_INFO("...!(::xos::fs::entry::type_directory != (" << which << ")))");
                            if (!(err = this->all_directory_run(argc, argv, env))) {
                            } else {
                            }
                        } else {
                            LOGGER_IS_LOGGED_INFO("...failed on !(::xos::fs::entry::type_directory != (" << which << ")))");
                            LOGGER_IS_LOGGED_INFO("!(::xos::fs::entry::type_file != (" << which << ")))...");
                            if (!(::xos::fs::entry::type_file != (which))) {
                                LOGGER_IS_LOGGED_INFO("...!(::xos::fs::entry::type_file != (" << which << ")))");
                                if (!(err = this->all_output_file_entry_run(arg_string, entry, argc, argv, env))) {
                                } else {
                                }
                            } else {
                                LOGGER_IS_LOGGED_INFO("...failed on !(::xos::fs::entry::type_file != (" << which << ")))");
                            }
                        }
                    } else {
                        LOGGER_IS_LOGGED_INFO("...failed ob (::xos::fs::entry::type_none != (" << which << " = entry.type().which()))");
                    }
                } else {
                    LOGGER_IS_LOGGED_INFO("...failed on (" << exists << " = entry.exists(\"" << chars << "\", " << length << "))");
                }
            } else {
            }
        } else {
            err = extends::run(argc, argv, env);
        }
        return err;
    }
    //////////////////////////////////////////////////////////////////////////

    //////////////////////////////////////////////////////////////////////////
    /// ...file_path_run
    virtual int file_path_run(int argc, char_t** argv, char_t** env) {
        int err = 0, optind = ::optind;
        const char_t* arg = 0;

        if ((argc > (optind)) && (arg = argv[optind]) && (arg[0])) {
            string_t arg_string(arg);
            const char_t* chars = 0;
            size_t length = 0;
            
            if ((chars = arg_string.has_chars(length))) {
                ::xos::fs::path path(chars, length);
            } else {
            }
        } else {
            err = extends::run(argc, argv, env);
        }
        return err;
    }
    //////////////////////////////////////////////////////////////////////////

    //////////////////////////////////////////////////////////////////////////
    /// ...output_directory_entry_run
    virtual int output_directory_entry_run(string_t &path, ::xos::fs::os::directory::path::entry_t &entry, int argc, char_t** argv, char_t** env) {
        int err = 0;
        this->outlln(path.chars(), "/", entry.name(), null);
        return err;
    }
    virtual int before_output_directory_entry_run(string_t &path, ::xos::fs::os::directory::path::entry_t &entry, int argc, char_t** argv, char_t** env) {
        int err = 0;
        return err;
    }
    virtual int after_output_directory_entry_run(string_t &path, ::xos::fs::os::directory::path::entry_t &entry, int argc, char_t** argv, char_t** env) {
        int err = 0;
        return err;
    }
    virtual int all_output_directory_entry_run(string_t &path, ::xos::fs::os::directory::path::entry_t &entry, int argc, char_t** argv, char_t** env) {
        int err = 0;
        if (!(err = before_output_directory_entry_run(path, entry, argc, argv, env))) {
            int err2 = 0;
            err = output_directory_entry_run(path, entry, argc, argv, env);
            if ((err2 = after_output_directory_entry_run(path, entry, argc, argv, env))) {
                if (!(err)) err = err2;
            }
        }
        return err;
    }
    //////////////////////////////////////////////////////////////////////////

    //////////////////////////////////////////////////////////////////////////
    /// ...output_file_entry_run
    virtual int output_file_entry_run(string_t &path, ::xos::fs::os::entry &entry, int argc, char_t** argv, char_t** env) {
        int err = 0;
        this->outlln(path.chars(), "/", entry.name(), null);
        return err;
    }
    virtual int before_output_file_entry_run(string_t &path, ::xos::fs::os::entry &entry, int argc, char_t** argv, char_t** env) {
        int err = 0;
        return err;
    }
    virtual int after_output_file_entry_run(string_t &path, ::xos::fs::os::entry &entry, int argc, char_t** argv, char_t** env) {
        int err = 0;
        return err;
    }
    virtual int all_output_file_entry_run(string_t &path, ::xos::fs::os::entry &entry, int argc, char_t** argv, char_t** env) {
        int err = 0;
        if (!(err = before_output_file_entry_run(path, entry, argc, argv, env))) {
            int err2 = 0;
            err = output_file_entry_run(path, entry, argc, argv, env);
            if ((err2 = after_output_file_entry_run(path, entry, argc, argv, env))) {
                if (!(err)) err = err2;
            }
        }
        return err;
    }
    //////////////////////////////////////////////////////////////////////////

    //////////////////////////////////////////////////////////////////////////
    /// on_found...
    virtual event_handled_status on_found_branch(const xos::fs::tree::branch& b) {
        const xos::fs::tree::branch::char_t* name = 0; size_t name_length = 0;

        LOGGER_IS_LOGGED_INFO("(name = b.has_name(name_length))...");
        if ((name = b.has_name(name_length))) {
            LOGGER_IS_LOGGED_INFO("...(\"" << name << "\" = b.has_name(" << name_length << "))");
            this->outln(name);
        } else {
            LOGGER_IS_LOGGED_INFO("...unexpected on (name = b.has_name(" << name_length << "))");
        }
        return event_handled_success;
    }
    virtual event_handled_status on_found_leaf(const xos::fs::tree::leaf& l) {
        const xos::fs::tree::branch::char_t* name = 0; size_t name_length = 0;
        
        LOGGER_IS_LOGGED_INFO("(name = l.has_name(name_length))...");
        if ((name = l.has_name(name_length))) {
            LOGGER_IS_LOGGED_INFO("...(\"" << name << "\" = l.has_name(" << name_length << "))");
            this->outln(name);
        } else {
            LOGGER_IS_LOGGED_INFO("...unexpected on (name = l.has_name(" << name_length << "))");
        }
        return event_handled_success;
    }
    //////////////////////////////////////////////////////////////////////////

    //////////////////////////////////////////////////////////////////////////
protected:
}; /// class maint 
typedef maint<> main;

} /// namespace arbora 
} /// namespace console 
} /// namespace app 
} /// namespace xos 

#endif /// ndef XOS_APP_CONSOLE_ARBORA_MAIN_HPP
