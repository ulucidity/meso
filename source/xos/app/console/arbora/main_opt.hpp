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
///   File: main_opt.hpp
///
/// Author: $author$
///   Date: 1/4/2024, 1/31/2024
//////////////////////////////////////////////////////////////////////////
#ifndef XOS_APP_CONSOLE_ARBORA_MAIN_OPT_HPP
#define XOS_APP_CONSOLE_ARBORA_MAIN_OPT_HPP

#include "xos/app/console/meso/version/main.hpp"

#define XOS_APP_CONSOLE_ARBORA_MAIN_DEPTH_FIRST_SEARCH_OPT "depth-first"
#define XOS_APP_CONSOLE_ARBORA_MAIN_DEPTH_FIRST_SEARCH_OPTARG_REQUIRED MAIN_OPT_ARGUMENT_NONE
#define XOS_APP_CONSOLE_ARBORA_MAIN_DEPTH_FIRST_SEARCH_OPTARG_RESULT 0
#define XOS_APP_CONSOLE_ARBORA_MAIN_DEPTH_FIRST_SEARCH_OPTARG ""
#define XOS_APP_CONSOLE_ARBORA_MAIN_DEPTH_FIRST_SEARCH_OPTUSE "search depth first"
#define XOS_APP_CONSOLE_ARBORA_MAIN_DEPTH_FIRST_SEARCH_OPTVAL_S "d"
#define XOS_APP_CONSOLE_ARBORA_MAIN_DEPTH_FIRST_SEARCH_OPTVAL_C 'd'
#define XOS_APP_CONSOLE_ARBORA_MAIN_DEPTH_FIRST_SEARCH_OPTION \
   {XOS_APP_CONSOLE_ARBORA_MAIN_DEPTH_FIRST_SEARCH_OPT, \
    XOS_APP_CONSOLE_ARBORA_MAIN_DEPTH_FIRST_SEARCH_OPTARG_REQUIRED, \
    XOS_APP_CONSOLE_ARBORA_MAIN_DEPTH_FIRST_SEARCH_OPTARG_RESULT, \
    XOS_APP_CONSOLE_ARBORA_MAIN_DEPTH_FIRST_SEARCH_OPTVAL_C}, \

#define XOS_APP_CONSOLE_ARBORA_MAIN_BREADTH_FIRST_SEARCH_OPT "breadth-first"
#define XOS_APP_CONSOLE_ARBORA_MAIN_BREADTH_FIRST_SEARCH_OPTARG_REQUIRED MAIN_OPT_ARGUMENT_NONE
#define XOS_APP_CONSOLE_ARBORA_MAIN_BREADTH_FIRST_SEARCH_OPTARG_RESULT 0
#define XOS_APP_CONSOLE_ARBORA_MAIN_BREADTH_FIRST_SEARCH_OPTARG ""
#define XOS_APP_CONSOLE_ARBORA_MAIN_BREADTH_FIRST_SEARCH_OPTUSE "search breadth first"
#define XOS_APP_CONSOLE_ARBORA_MAIN_BREADTH_FIRST_SEARCH_OPTVAL_S "b"
#define XOS_APP_CONSOLE_ARBORA_MAIN_BREADTH_FIRST_SEARCH_OPTVAL_C 'b'
#define XOS_APP_CONSOLE_ARBORA_MAIN_BREADTH_FIRST_SEARCH_OPTION \
   {XOS_APP_CONSOLE_ARBORA_MAIN_BREADTH_FIRST_SEARCH_OPT, \
    XOS_APP_CONSOLE_ARBORA_MAIN_BREADTH_FIRST_SEARCH_OPTARG_REQUIRED, \
    XOS_APP_CONSOLE_ARBORA_MAIN_BREADTH_FIRST_SEARCH_OPTARG_RESULT, \
    XOS_APP_CONSOLE_ARBORA_MAIN_BREADTH_FIRST_SEARCH_OPTVAL_C}, \

#define XOS_APP_CONSOLE_ARBORA_MAIN_DEPEND_FIRST_SEARCH_OPT "depend-first"
#define XOS_APP_CONSOLE_ARBORA_MAIN_DEPEND_FIRST_SEARCH_OPTARG_REQUIRED MAIN_OPT_ARGUMENT_OPTIONAL
#define XOS_APP_CONSOLE_ARBORA_MAIN_DEPEND_FIRST_SEARCH_OPTARG_RESULT 0
#define XOS_APP_CONSOLE_ARBORA_MAIN_DEPEND_FIRST_SEARCH_OPTARG ""
#define XOS_APP_CONSOLE_ARBORA_MAIN_DEPEND_FIRST_SEARCH_OPTUSE "search depend first"
#define XOS_APP_CONSOLE_ARBORA_MAIN_DEPEND_FIRST_SEARCH_OPTVAL_S "p::"
#define XOS_APP_CONSOLE_ARBORA_MAIN_DEPEND_FIRST_SEARCH_OPTVAL_C 'p'
#define XOS_APP_CONSOLE_ARBORA_MAIN_DEPEND_FIRST_SEARCH_OPTION \
   {XOS_APP_CONSOLE_ARBORA_MAIN_DEPEND_FIRST_SEARCH_OPT, \
    XOS_APP_CONSOLE_ARBORA_MAIN_DEPEND_FIRST_SEARCH_OPTARG_REQUIRED, \
    XOS_APP_CONSOLE_ARBORA_MAIN_DEPEND_FIRST_SEARCH_OPTARG_RESULT, \
    XOS_APP_CONSOLE_ARBORA_MAIN_DEPEND_FIRST_SEARCH_OPTVAL_C}, \

#define XOS_APP_CONSOLE_ARBORA_MAIN_BOTTOM_FIRST_SEARCH_OPT "bottom-first"
#define XOS_APP_CONSOLE_ARBORA_MAIN_BOTTOM_FIRST_SEARCH_OPTARG_REQUIRED MAIN_OPT_ARGUMENT_OPTIONAL
#define XOS_APP_CONSOLE_ARBORA_MAIN_BOTTOM_FIRST_SEARCH_OPTARG_RESULT 0
#define XOS_APP_CONSOLE_ARBORA_MAIN_BOTTOM_FIRST_SEARCH_OPTARG ""
#define XOS_APP_CONSOLE_ARBORA_MAIN_BOTTOM_FIRST_SEARCH_OPTUSE "search bottom first"
#define XOS_APP_CONSOLE_ARBORA_MAIN_BOTTOM_FIRST_SEARCH_OPTVAL_S "t::"
#define XOS_APP_CONSOLE_ARBORA_MAIN_BOTTOM_FIRST_SEARCH_OPTVAL_C 't'
#define XOS_APP_CONSOLE_ARBORA_MAIN_BOTTOM_FIRST_SEARCH_OPTION \
   {XOS_APP_CONSOLE_ARBORA_MAIN_BOTTOM_FIRST_SEARCH_OPT, \
    XOS_APP_CONSOLE_ARBORA_MAIN_BOTTOM_FIRST_SEARCH_OPTARG_REQUIRED, \
    XOS_APP_CONSOLE_ARBORA_MAIN_BOTTOM_FIRST_SEARCH_OPTARG_RESULT, \
    XOS_APP_CONSOLE_ARBORA_MAIN_BOTTOM_FIRST_SEARCH_OPTVAL_C}, \

///////////////////////////////////////////////////////////////////////
#define XOS_APP_CONSOLE_ARBORA_MAIN_OPTIONS_CHARS_EXTEND \
   XOS_APP_CONSOLE_ARBORA_MAIN_DEPTH_FIRST_SEARCH_OPTVAL_S \
   XOS_APP_CONSOLE_ARBORA_MAIN_BREADTH_FIRST_SEARCH_OPTVAL_S \
   XOS_APP_CONSOLE_ARBORA_MAIN_DEPEND_FIRST_SEARCH_OPTVAL_S \
   XOS_APP_CONSOLE_ARBORA_MAIN_BOTTOM_FIRST_SEARCH_OPTVAL_S \

#define XOS_APP_CONSOLE_ARBORA_MAIN_OPTIONS_OPTIONS_EXTEND \
   XOS_APP_CONSOLE_ARBORA_MAIN_DEPTH_FIRST_SEARCH_OPTION \
   XOS_APP_CONSOLE_ARBORA_MAIN_BREADTH_FIRST_SEARCH_OPTION \
   XOS_APP_CONSOLE_ARBORA_MAIN_DEPEND_FIRST_SEARCH_OPTION \
   XOS_APP_CONSOLE_ARBORA_MAIN_BOTTOM_FIRST_SEARCH_OPTION \

///////////////////////////////////////////////////////////////////////
#define XOS_APP_CONSOLE_ARBORA_MAIN_OPTIONS_CHARS \
   XOS_APP_CONSOLE_ARBORA_MAIN_OPTIONS_CHARS_EXTEND \
   XOS_APP_CONSOLE_VERSION_MAIN_OPTIONS_CHARS \

#define XOS_APP_CONSOLE_ARBORA_MAIN_OPTIONS_OPTIONS \
   XOS_APP_CONSOLE_ARBORA_MAIN_OPTIONS_OPTIONS_EXTEND \
   XOS_APP_CONSOLE_VERSION_MAIN_OPTIONS_OPTIONS \

///////////////////////////////////////////////////////////////////////
#define XOS_APP_CONSOLE_ARBORA_MAIN_ARGS "[directory]"
#define XOS_APP_CONSOLE_ARBORA_MAIN_ARGV "[directory] search directory",

namespace xos {
namespace app {
namespace console {
namespace arbora {

/// class main_optt
template 
<class TExtends = xos::app::console::meso::version::maint<>,  class TImplements = typename TExtends::implements>

class main_optt: virtual public TImplements, public TExtends {
public:
    typedef TImplements implements;
    typedef TExtends extends;
    typedef main_optt derives;

    typedef typename extends::char_t char_t;
    typedef typename extends::end_char_t end_char_t;
    enum { end_char = extends::end_char };
    typedef typename extends::string_t string_t;
    typedef typename extends::reader_t reader_t;
    typedef typename extends::writer_t writer_t;
    typedef typename extends::file_t file_t;

    /// constructor / destructor
    main_optt(): run_(0) {
    }
    virtual ~main_optt() {
    }
private:
    main_optt(const main_optt &copy) {
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
            int optind = ::optind;
            if ((argc > (optind))) {
                err = all_argv_run(argc, argv, env);
            } else {
                err = extends::run(argc, argv, env);
            }
        }
        return err;
    }

    //////////////////////////////////////////////////////////////////////////
    /// ...argv_run
    int (derives::*argv_run_)(int argc, char_t** argv, char_t** env);
    virtual int argv_run(int argc, char_t** argv, char_t** env) {
        int err = 0;
        if (argv_run_) {
            if (!(err = (this->*argv_run_)(argc, argv, env))) {
            } else {
            }
        } else {
            if (!(err = default_argv_run(argc, argv, env))) {
            } else {
            }
        }
        return err;
    }
    virtual int default_argv_run(int argc, char_t** argv, char_t** env) {
        int err = 0;
        if (!(err = all_file_entry_run(argc, argv, env))) {
        } else {
        }
        return err;
    }
    virtual int before_argv_run(int argc, char_t** argv, char_t** env) {
        int err = 0, optind = ::optind;
        const char_t* arg = 0;
        
        LOGGER_IS_LOGGED_INFO("((argc > (optind)) && (arg = argv[optind]) && (arg[0]))...");
        if ((argc > (optind)) && (arg = argv[optind]) && (arg[0])) {
            LOGGER_IS_LOGGED_INFO("...((argc > (" << optind << ")) && (arg = argv[" << optind << "]) && (arg[0]))");
            /*this->set_arg_string(arg);*/
            LOGGER_IS_LOGGED_INFO("!(err = on_arg_string_option(\"" << arg << "\", optind, argc, argv, env))...");
            if (!(err = on_arg_string_option(arg, optind, argc, argv, env))) {
                LOGGER_IS_LOGGED_INFO("...!(" << err << " = on_arg_string_option(\"" << arg << "\", optind, argc, argv, env))");
            } else {
                LOGGER_IS_LOGGED_INFO("...failed on !(" << err << " = on_arg_string_option(\"" << arg << "\", optind, argc, argv, env))");
            }
        } else {
            err = extends::run(argc, argv, env);
        }
        return err;
    }
    virtual int after_argv_run(int argc, char_t** argv, char_t** env) {
        int err = 0;
        return err;
    }
    virtual int all_argv_run(int argc, char_t** argv, char_t** env) {
        int err = 0;
        if (!(err = before_argv_run(argc, argv, env))) {
            int err2 = 0;
            err = argv_run(argc, argv, env);
            if ((err2 = after_argv_run(argc, argv, env))) {
                if (!(err)) err = err2;
            }
        }
        return err;
    }
    virtual int set_argv_run(int argc, char_t** argv, char_t** env) {
        int err = 0;
        run_ = &derives::all_argv_run;
        return err;
    }
    virtual int argv_run_set(int argc, char_t** argv, char_t** env) {
        int err = 0;
        return err;
    }
    virtual int unset_argv_run(int argc, char_t** argv, char_t** env) {
        int err = 0;
        run_ = 0;
        return err;
    }
    virtual int argv_run_unset(int argc, char_t** argv, char_t** env) {
        int err = 0;
        return err;
    }
    //////////////////////////////////////////////////////////////////////////

    //////////////////////////////////////////////////////////////////////////
    /// ...directory_run
    int (derives::*directory_run_)(int argc, char_t** argv, char_t** env);
    virtual int directory_run(int argc, char_t** argv, char_t** env) {
        int err = 0;
        if (directory_run_) {
            if (!(err = (this->*directory_run_)(argc, argv, env))) {
            } else {
            }
        } else {
            if (!(err = default_directory_run(argc, argv, env))) {
            } else {
            }
        }
        return err;
    }
    virtual int default_directory_run(int argc, char_t** argv, char_t** env) {
        int err = 0;
        if (!(err = all_directory_tree_run(argc, argv, env))) {
        } else {
        }
        return err;
    }
    virtual int before_directory_run(int argc, char_t** argv, char_t** env) {
        int err = 0;
        return err;
    }
    virtual int after_directory_run(int argc, char_t** argv, char_t** env) {
        int err = 0;
        return err;
    }
    virtual int all_directory_run(int argc, char_t** argv, char_t** env) {
        int err = 0;
        if (!(err = before_directory_run(argc, argv, env))) {
            int err2 = 0;
            err = directory_run(argc, argv, env);
            if ((err2 = after_directory_run(argc, argv, env))) {
                if (!(err)) err = err2;
            }
        }
        return err;
    }
    virtual int set_directory_run(int argc, char_t** argv, char_t** env) {
        int err = 0;
        run_ = &derives::all_directory_run;
        return err;
    }
    virtual int directory_run_set(int argc, char_t** argv, char_t** env) {
        int err = 0;
        return err;
    }
    virtual int unset_directory_run(int argc, char_t** argv, char_t** env) {
        int err = 0;
        run_ = 0;
        return err;
    }
    virtual int directory_run_unset(int argc, char_t** argv, char_t** env) {
        int err = 0;
        return err;
    }
    //////////////////////////////////////////////////////////////////////////

    //////////////////////////////////////////////////////////////////////////
    /// ...directory_tree_run
    int (derives::*directory_tree_run_)(int argc, char_t** argv, char_t** env);
    virtual int directory_tree_run(int argc, char_t** argv, char_t** env) {
        int err = 0;
        if (directory_tree_run_) {
            if (!(err = (this->*directory_tree_run_)(argc, argv, env))) {
            } else {
            }
        } else {
            if (!(err = default_directory_tree_run(argc, argv, env))) {
            } else {
            }
        }
        return err;
    }
    virtual int default_directory_tree_run(int argc, char_t** argv, char_t** env) {
        int err = 0;
        if (!(err = all_directory_search_run(argc, argv, env))) {
        } else {
        }
        return err;
    }
    virtual int before_directory_tree_run(int argc, char_t** argv, char_t** env) {
        int err = 0;
        return err;
    }
    virtual int after_directory_tree_run(int argc, char_t** argv, char_t** env) {
        int err = 0;
        return err;
    }
    virtual int all_directory_tree_run(int argc, char_t** argv, char_t** env) {
        int err = 0;
        if (!(err = before_directory_tree_run(argc, argv, env))) {
            int err2 = 0;
            err = directory_tree_run(argc, argv, env);
            if ((err2 = after_directory_tree_run(argc, argv, env))) {
                if (!(err)) err = err2;
            }
        }
        return err;
    }
    virtual int set_directory_tree_run(int argc, char_t** argv, char_t** env) {
        int err = 0;
        directory_run_ = &derives::all_directory_tree_run;
        return err;
    }
    virtual int directory_tree_run_set(int argc, char_t** argv, char_t** env) {
        int err = 0;
        return err;
    }
    virtual int unset_directory_tree_run(int argc, char_t** argv, char_t** env) {
        int err = 0;
        directory_run_ = 0;
        return err;
    }
    virtual int directory_tree_run_unset(int argc, char_t** argv, char_t** env) {
        int err = 0;
        return err;
    }
    //////////////////////////////////////////////////////////////////////////

    //////////////////////////////////////////////////////////////////////////
    /// ...directory_search_run
    int (derives::*directory_search_run_)(int argc, char_t** argv, char_t** env);
    virtual int directory_search_run(int argc, char_t** argv, char_t** env) {
        int err = 0;
        if (directory_search_run_) {
            if (!(err = (this->*directory_search_run_)(argc, argv, env))) {
            } else {
            }
        } else {
            if (!(err = depth_first_directory_search_run(argc, argv, env))) {
            } else {
            }
        }
        return err;
    }
    /// ...depth_first_directory_search_run
    virtual int depth_first_directory_search_run(int argc, char_t** argv, char_t** env) {
        int err = 0; const char_t* chars = 0; size_t length = 0;
        const string_t& arg_string = this->arg_string();
        if ((chars = arg_string.has_chars(length))) {
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
        } else {
            if (!(err = extends::run(argc, argv, env))) {
            } else {
            }
        }
        return err;
    }
    virtual int before_directory_search_run(int argc, char_t** argv, char_t** env) {
        int err = 0;
        return err;
    }
    virtual int after_directory_search_run(int argc, char_t** argv, char_t** env) {
        int err = 0;
        return err;
    }
    virtual int all_directory_search_run(int argc, char_t** argv, char_t** env) {
        int err = 0;
        if (!(err = before_directory_search_run(argc, argv, env))) {
            int err2 = 0;
            err = directory_search_run(argc, argv, env);
            if ((err2 = after_directory_search_run(argc, argv, env))) {
                if (!(err)) err = err2;
            }
        }
        return err;
    }
    virtual int set_directory_search_run(int argc, char_t** argv, char_t** env) {
        int err = 0;
        directory_tree_run_ = &derives::all_directory_search_run;
        return err;
    }
    virtual int directory_search_run_set(int argc, char_t** argv, char_t** env) {
        int err = 0;
        return err;
    }
    virtual int unset_directory_search_run(int argc, char_t** argv, char_t** env) {
        int err = 0;
        directory_tree_run_ = 0;
        return err;
    }
    virtual int directory_search_run_unset(int argc, char_t** argv, char_t** env) {
        int err = 0;
        return err;
    }
    /// ...depth_first_directory_search_...
    virtual int set_depth_first_directory_search_run(int argc, char_t** argv, char_t** env) {
        int err = 0;
        directory_search_run_ = &derives::depth_first_directory_search_run;
        return err;
    }
    virtual int depth_first_directory_search_run_set(int argc, char_t** argv, char_t** env) {
        int err = 0;
        return err;
    }
    virtual int unset_depth_first_directory_search_run(int argc, char_t** argv, char_t** env) {
        int err = 0;
        directory_search_run_ = 0;
        return err;
    }
    virtual int depth_first_directory_search_run_unset(int argc, char_t** argv, char_t** env) {
        int err = 0;
        return err;
    }
    /// ...breadth_first_directory_search_...
    virtual int set_breadth_first_directory_search_run(int argc, char_t** argv, char_t** env) {
        int err = 0;
        directory_search_run_ = &derives::breadth_first_directory_search_run;
        return err;
    }
    virtual int breadth_first_directory_search_run_set(int argc, char_t** argv, char_t** env) {
        int err = 0;
        return err;
    }
    virtual int unset_breadth_first_directory_search_run(int argc, char_t** argv, char_t** env) {
        int err = 0;
        directory_search_run_ = 0;
        return err;
    }
    virtual int breadth_first_directory_search_run_unset(int argc, char_t** argv, char_t** env) {
        int err = 0;
        return err;
    }
    /// ...depend_first_directory_search_...
    virtual int set_depend_first_directory_search_run(int argc, char_t** argv, char_t** env) {
        int err = 0;
        directory_search_run_ = &derives::depend_first_directory_search_run;
        return err;
    }
    virtual int depend_first_directory_search_run_set(int argc, char_t** argv, char_t** env) {
        int err = 0;
        return err;
    }
    virtual int unset_depend_first_directory_search_run(int argc, char_t** argv, char_t** env) {
        int err = 0;
        directory_search_run_ = 0;
        return err;
    }
    virtual int depend_first_directory_search_run_unset(int argc, char_t** argv, char_t** env) {
        int err = 0;
        return err;
    }
    /// ...bottom_first_directory_search_...
    virtual int set_bottom_first_directory_search_run(int argc, char_t** argv, char_t** env) {
        int err = 0;
        directory_search_run_ = &derives::bottom_first_directory_search_run;
        return err;
    }
    virtual int bottom_first_directory_search_run_set(int argc, char_t** argv, char_t** env) {
        int err = 0;
        return err;
    }
    virtual int unset_bottom_first_directory_search_run(int argc, char_t** argv, char_t** env) {
        int err = 0;
        directory_search_run_ = 0;
        return err;
    }
    virtual int bottom_first_directory_search_run_unset(int argc, char_t** argv, char_t** env) {
        int err = 0;
        return err;
    }
    //////////////////////////////////////////////////////////////////////////

    //////////////////////////////////////////////////////////////////////////
    /// ...directory_entry_run
    virtual int directory_entry_run(int argc, char_t** argv, char_t** env) {
        int err = 0;
        return err;
    }
    virtual int before_directory_entry_run(int argc, char_t** argv, char_t** env) {
        int err = 0;
        return err;
    }
    virtual int after_directory_entry_run(int argc, char_t** argv, char_t** env) {
        int err = 0;
        return err;
    }
    virtual int all_directory_entry_run(int argc, char_t** argv, char_t** env) {
        int err = 0;
        if (!(err = before_directory_entry_run(argc, argv, env))) {
            int err2 = 0;
            err = directory_entry_run(argc, argv, env);
            if ((err2 = after_directory_entry_run(argc, argv, env))) {
                if (!(err)) err = err2;
            }
        }
        return err;
    }
    virtual int set_directory_entry_run(int argc, char_t** argv, char_t** env) {
        int err = 0;
        run_ = &derives::all_directory_entry_run;
        return err;
    }
    virtual int directory_entry_run_set(int argc, char_t** argv, char_t** env) {
        int err = 0;
        return err;
    }
    virtual int unset_directory_entry_run(int argc, char_t** argv, char_t** env) {
        int err = 0;
        run_ = 0;
        return err;
    }
    virtual int directory_entry_run_unset(int argc, char_t** argv, char_t** env) {
        int err = 0;
        return err;
    }
    //////////////////////////////////////////////////////////////////////////

    //////////////////////////////////////////////////////////////////////////
    /// ...file_entry_run
    virtual int file_entry_run(int argc, char_t** argv, char_t** env) {
        int err = 0;
        return err;
    }
    virtual int before_file_entry_run(int argc, char_t** argv, char_t** env) {
        int err = 0;
        return err;
    }
    virtual int after_file_entry_run(int argc, char_t** argv, char_t** env) {
        int err = 0;
        return err;
    }
    virtual int all_file_entry_run(int argc, char_t** argv, char_t** env) {
        int err = 0;
        if (!(err = before_file_entry_run(argc, argv, env))) {
            int err2 = 0;
            err = file_entry_run(argc, argv, env);
            if ((err2 = after_file_entry_run(argc, argv, env))) {
                if (!(err)) err = err2;
            }
        }
        return err;
    }
    virtual int set_file_entry_run(int argc, char_t** argv, char_t** env) {
        int err = 0;
        run_ = &derives::all_file_entry_run;
        return err;
    }
    virtual int file_entry_run_set(int argc, char_t** argv, char_t** env) {
        int err = 0;
        return err;
    }
    virtual int unset_file_entry_run(int argc, char_t** argv, char_t** env) {
        int err = 0;
        run_ = 0;
        return err;
    }
    virtual int file_entry_run_unset(int argc, char_t** argv, char_t** env) {
        int err = 0;
        return err;
    }
    //////////////////////////////////////////////////////////////////////////

    //////////////////////////////////////////////////////////////////////////
    /// ...file_path_run
    virtual int file_path_run(int argc, char_t** argv, char_t** env) {
        int err = 0;
        return err;
    }
    virtual int before_file_path_run(int argc, char_t** argv, char_t** env) {
        int err = 0;
        return err;
    }
    virtual int after_file_path_run(int argc, char_t** argv, char_t** env) {
        int err = 0;
        return err;
    }
    virtual int all_file_path_run(int argc, char_t** argv, char_t** env) {
        int err = 0;
        if (!(err = before_file_path_run(argc, argv, env))) {
            int err2 = 0;
            err = file_path_run(argc, argv, env);
            if ((err2 = after_file_path_run(argc, argv, env))) {
                if (!(err)) err = err2;
            }
        }
        return err;
    }
    virtual int set_file_path_run(int argc, char_t** argv, char_t** env) {
        int err = 0;
        run_ = &derives::all_file_path_run;
        return err;
    }
    virtual int file_path_run_set(int argc, char_t** argv, char_t** env) {
        int err = 0;
        return err;
    }
    virtual int unset_file_path_run(int argc, char_t** argv, char_t** env) {
        int err = 0;
        run_ = 0;
        return err;
    }
    virtual int file_path_run_unset(int argc, char_t** argv, char_t** env) {
        int err = 0;
        return err;
    }
    //////////////////////////////////////////////////////////////////////////

    //////////////////////////////////////////////////////////////////////////
    /// on...option...
    /// ...
    /// on...depth_first_search_option...
    virtual int on_set_depth_first_search_option
    (const char_t* optarg, int optind, int argc, char_t**argv, char_t**env) {
        int err = 0;
        return err;
    }
    virtual int on_depth_first_search_option_set
    (const char_t* optarg, int optind, int argc, char_t**argv, char_t**env) {
        int err = 0;
        if (!(err = set_depth_first_directory_search_run(argc, argv, env))) {
            if (!(err = depth_first_directory_search_run_set(argc, argv, env))) {
            } else {
            }
        } else {
        }
        return err;
    }
    virtual int on_depth_first_search_option
    (int optval, const char_t* optarg, const char_t* optname,
     int optind, int argc, char_t**argv, char_t**env) {
        int err = 0;
        if (!(err = on_set_depth_first_search_option(optarg, optind, argc, argv, env))) {
            if (!(err = on_depth_first_search_option_set(optarg, optind, argc, argv, env))) {
            } else {
            }
        } else {
        }
        return err;
    }
    virtual const char_t* depth_first_search_option_usage(const char_t*& optarg, const struct option* longopt) {
        const char_t* chars = XOS_APP_CONSOLE_ARBORA_MAIN_DEPTH_FIRST_SEARCH_OPTUSE;
        optarg = XOS_APP_CONSOLE_ARBORA_MAIN_DEPTH_FIRST_SEARCH_OPTARG;
        return chars;
    }

    //////////////////////////////////////////////////////////////////////////
    /// on...breadth_first_search_option...
    virtual int on_set_breadth_first_search_option
    (const char_t* optarg, int optind, int argc, char_t**argv, char_t**env) {
        int err = 0;
        return err;
    }
    virtual int on_breadth_first_search_option_set
    (const char_t* optarg, int optind, int argc, char_t**argv, char_t**env) {
        int err = 0;
        if (!(err = set_breadth_first_directory_search_run(argc, argv, env))) {
            if (!(err = breadth_first_directory_search_run_set(argc, argv, env))) {
            } else {
            }
        } else {
        }
        return err;
    }
    virtual int on_breadth_first_search_option
    (int optval, const char_t* optarg, const char_t* optname,
     int optind, int argc, char_t**argv, char_t**env) {
        int err = 0;
        if (!(err = on_set_breadth_first_search_option(optarg, optind, argc, argv, env))) {
            if (!(err = on_breadth_first_search_option_set(optarg, optind, argc, argv, env))) {
            } else {
            }
        } else {
        }
        return err;
    }
    virtual const char_t* breadth_first_search_option_usage(const char_t*& optarg, const struct option* longopt) {
        const char_t* chars = XOS_APP_CONSOLE_ARBORA_MAIN_BREADTH_FIRST_SEARCH_OPTUSE;
        optarg = XOS_APP_CONSOLE_ARBORA_MAIN_BREADTH_FIRST_SEARCH_OPTARG;
        return chars;
    }

    /// on...depend_first_search_option...
    virtual int on_set_depend_first_search_option
    (const char_t* optarg, int optind, int argc, char_t**argv, char_t**env) {
        int err = 0;
        return err;
    }
    virtual int on_depend_first_search_option_set
    (const char_t* optarg, int optind, int argc, char_t**argv, char_t**env) {
        int err = 0;
        if (!(err = set_depend_first_directory_search_run(argc, argv, env))) {
            if (!(err = depend_first_directory_search_run_set(argc, argv, env))) {
            } else {
            }
        } else {
        }
        return err;
    }
    virtual int on_depend_first_search_option
    (int optval, const char_t* optarg, const char_t* optname,
     int optind, int argc, char_t**argv, char_t**env) {
        int err = 0;
        if (!(err = on_set_depend_first_search_option(optarg, optind, argc, argv, env))) {
            if (!(err = on_depend_first_search_option_set(optarg, optind, argc, argv, env))) {
            } else {
            }
        } else {
        }
        return err;
    }
    virtual const char_t* depend_first_search_option_usage(const char_t*& optarg, const struct option* longopt) {
        const char_t* chars = XOS_APP_CONSOLE_ARBORA_MAIN_DEPEND_FIRST_SEARCH_OPTUSE;
        optarg = XOS_APP_CONSOLE_ARBORA_MAIN_DEPEND_FIRST_SEARCH_OPTARG;
        return chars;
    }

    /// on...bottom_first_search_option...
    virtual int on_set_bottom_first_search_option
    (const char_t* optarg, int optind, int argc, char_t**argv, char_t**env) {
        int err = 0;
        return err;
    }
    virtual int on_bottom_first_search_option_set
    (const char_t* optarg, int optind, int argc, char_t**argv, char_t**env) {
        int err = 0;
        if (!(err = set_bottom_first_directory_search_run(argc, argv, env))) {
            if (!(err = bottom_first_directory_search_run_set(argc, argv, env))) {
            } else {
            }
        } else {
        }
        return err;
    }
    virtual int on_bottom_first_search_option
    (int optval, const char_t* optarg, const char_t* optname,
     int optind, int argc, char_t**argv, char_t**env) {
        int err = 0;
        if (!(err = on_set_bottom_first_search_option(optarg, optind, argc, argv, env))) {
            if (!(err = on_bottom_first_search_option_set(optarg, optind, argc, argv, env))) {
            } else {
            }
        } else {
        }
        return err;
    }
    virtual const char_t* bottom_first_search_option_usage(const char_t*& optarg, const struct option* longopt) {
        const char_t* chars = XOS_APP_CONSOLE_ARBORA_MAIN_BOTTOM_FIRST_SEARCH_OPTUSE;
        optarg = XOS_APP_CONSOLE_ARBORA_MAIN_BOTTOM_FIRST_SEARCH_OPTARG;
        return chars;
    }

    /// on...arg_string_option...
    virtual int on_set_arg_string_option
    (const char_t* optarg, int optind, int argc, char_t**argv, char_t**env) {
        int err = 0;
        LOGGER_IS_LOGGED_INFO("((optarg) && (optarg[0]))...");
        if ((optarg) && (optarg[0])) {
            LOGGER_IS_LOGGED_INFO("...((optarg) && (optarg[0]))");
            LOGGER_IS_LOGGED_INFO("this->set_arg_string(\"" << optarg << "\")...");
            this->set_arg_string(optarg);
        } else {
            LOGGER_IS_LOGGED_INFO("...failed on ((optarg) && (optarg[0]))");
        }
        return err;
    }
    virtual int on_arg_string_option_set
    (const char_t* optarg, int optind, int argc, char_t**argv, char_t**env) {
        int err = 0;
        if ((optarg) && (optarg[0])) {
        } else {
        }
        return err;
    }
    virtual int on_arg_string_option
    (const char_t* optarg, int optind, int argc, char_t**argv, char_t**env) {
        int err = 0;
        if ((optarg) && (optarg[0])) {
            if (!(err = on_set_arg_string_option(optarg, optind, argc, argv, env))) {
                if (!(err = on_arg_string_option_set(optarg, optind, argc, argv, env))) {
                } else {
                }
            } else {
            }
        } else {
        }
        return err;
    }
    /// ...
    /// on...option...
    //////////////////////////////////////////////////////////////////////////

    //////////////////////////////////////////////////////////////////////////
    /// ...option...
    /// ...
    /// on_option
    virtual int on_option
    (int optval, const char_t* optarg, const char_t* optname,
     int optind, int argc, char_t**argv, char_t**env) {
        int err = 0;
        switch(optval) {

        case XOS_APP_CONSOLE_ARBORA_MAIN_DEPTH_FIRST_SEARCH_OPTVAL_C:
            err = this->on_depth_first_search_option(optval, optarg, optname, optind, argc, argv, env);
            break;
        case XOS_APP_CONSOLE_ARBORA_MAIN_BREADTH_FIRST_SEARCH_OPTVAL_C:
            err = this->on_breadth_first_search_option(optval, optarg, optname, optind, argc, argv, env);
            break;

        case XOS_APP_CONSOLE_ARBORA_MAIN_DEPEND_FIRST_SEARCH_OPTVAL_C:
            err = this->on_depend_first_search_option(optval, optarg, optname, optind, argc, argv, env);
            break;
        case XOS_APP_CONSOLE_ARBORA_MAIN_BOTTOM_FIRST_SEARCH_OPTVAL_C:
            err = this->on_bottom_first_search_option(optval, optarg, optname, optind, argc, argv, env);
            break;

        default:
            err = extends::on_option(optval, optarg, optname, optind, argc, argv, env);
        }
        return err;
    }
    
    /// option_usage
    virtual const char_t* option_usage(const char_t*& optarg, const struct option* longopt) {
        const char_t* chars = "";
        switch(longopt->val) {

        case XOS_APP_CONSOLE_ARBORA_MAIN_DEPTH_FIRST_SEARCH_OPTVAL_C:
            chars = this->depth_first_search_option_usage(optarg, longopt);
            break;
        case XOS_APP_CONSOLE_ARBORA_MAIN_BREADTH_FIRST_SEARCH_OPTVAL_C:
            chars = this->breadth_first_search_option_usage(optarg, longopt);
            break;

        case XOS_APP_CONSOLE_ARBORA_MAIN_DEPEND_FIRST_SEARCH_OPTVAL_C:
            chars = this->depend_first_search_option_usage(optarg, longopt);
            break;
        case XOS_APP_CONSOLE_ARBORA_MAIN_BOTTOM_FIRST_SEARCH_OPTVAL_C:
            chars = this->bottom_first_search_option_usage(optarg, longopt);
            break;

        default:
            chars = extends::option_usage(optarg, longopt);
            break;
        }
        return chars;
    }

    /// options
    virtual const char_t* options(const struct option*& longopts) {
        static const char_t* chars = XOS_APP_CONSOLE_ARBORA_MAIN_OPTIONS_CHARS;
        static struct option optstruct[]= {
            XOS_APP_CONSOLE_ARBORA_MAIN_OPTIONS_OPTIONS
            {0, 0, 0, 0}};
        longopts = optstruct;
        return chars;
    }
    /// ...
    /// ...option...
    //////////////////////////////////////////////////////////////////////////

    //////////////////////////////////////////////////////////////////////////
    /// ...argument...
    ///
    /// arguments
    virtual const char_t* arguments(const char_t**& argv) {
        static const char_t* _args = XOS_APP_CONSOLE_ARBORA_MAIN_ARGS;
        static const char_t* _argv[] = {
            XOS_APP_CONSOLE_ARBORA_MAIN_ARGV
            0};
        argv = _argv;
        return _args;
    }
    /// ...
    /// ...argument...
    //////////////////////////////////////////////////////////////////////////

    //////////////////////////////////////////////////////////////////////////
    /// ...arg_string...
    /// ...
    virtual string_t& set_arg_string(const string_t& to) {
        string_t& arg_string = this->arg_string();
        arg_string.assign(to);
        return arg_string;
    }
    virtual string_t& set_arg_string(const char_t* to, size_t length) {
        string_t& arg_string = this->arg_string();
        arg_string.assign(to, length);
        return arg_string;
    }
    virtual string_t& set_arg_string(const char_t* to) {
        string_t& arg_string = this->arg_string();
        arg_string.assign(to);
        return arg_string;
    }
    virtual const string_t& get_arg_string() const {
        string_t& arg_string = this->arg_string();
        return arg_string;
    }
    virtual string_t& arg_string() const {
        string_t& arg_string = (string_t&)arg_string_;
        return arg_string;
    }
    /// ...
    /// ...arg_string...
    //////////////////////////////////////////////////////////////////////////

    //////////////////////////////////////////////////////////////////////////
protected:
    string_t arg_string_;
}; /// class main_optt 
typedef main_optt<> main_opt;

} /// namespace arbora 
} /// namespace console 
} /// namespace app 
} /// namespace xos 

#endif /// ndef XOS_APP_CONSOLE_ARBORA_MAIN_OPT_HPP
