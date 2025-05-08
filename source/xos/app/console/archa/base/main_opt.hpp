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
///   Date: 1/21/2024, 1/29/2024
//////////////////////////////////////////////////////////////////////////
#ifndef XOS_APP_CONSOLE_ARCHA_BASE_MAIN_OPT_HPP
#define XOS_APP_CONSOLE_ARCHA_BASE_MAIN_OPT_HPP

#include "xos/app/console/framework/version/main.hpp"

//////////////////////////////////////////////////////////////////////////
#define XOS_APP_CONSOLE_ARCHA_MAIN_MATCH_ALL_PATTERN "*"
#define XOS_APP_CONSOLE_ARCHA_MAIN_MATCH_NONE_PATTERN ""
#define XOS_APP_CONSOLE_ARCHA_MAIN_MATCH_FINDER_PATTERN ".DS_Store;*._DS_Store"

#define XOS_APP_CONSOLE_ARCHA_MAIN_FIND_PATTERN \
    XOS_APP_CONSOLE_ARCHA_MAIN_MATCH_ALL_PATTERN

#define XOS_APP_CONSOLE_ARCHA_MAIN_MATCH_PATTERN \
    XOS_APP_CONSOLE_ARCHA_MAIN_MATCH_ALL_PATTERN

#define XOS_APP_CONSOLE_ARCHA_MAIN_SKIP_PATTERN \
    XOS_APP_CONSOLE_ARCHA_MAIN_MATCH_FINDER_PATTERN

//////////////////////////////////////////////////////////////////////////
#define XOS_APP_CONSOLE_ARCHA_MAIN_COPY "udcp"
#define XOS_APP_CONSOLE_ARCHA_MAIN_BEFORE " \""
#define XOS_APP_CONSOLE_ARCHA_MAIN_BETWEEN "\" \""
#define XOS_APP_CONSOLE_ARCHA_MAIN_AFTER "\""

#define XOS_APP_CONSOLE_ARCHA_MAIN_BEFORE_FOUND \
    XOS_APP_CONSOLE_ARCHA_MAIN_COPY \
    XOS_APP_CONSOLE_ARCHA_MAIN_BEFORE

#define XOS_APP_CONSOLE_ARCHA_MAIN_BETWEEN_FOUND \
    XOS_APP_CONSOLE_ARCHA_MAIN_BETWEEN

#define XOS_APP_CONSOLE_ARCHA_MAIN_AFTER_FOUND \
    XOS_APP_CONSOLE_ARCHA_MAIN_AFTER

//////////////////////////////////////////////////////////////////////////
#define XOS_APP_CONSOLE_ARCHA_MAIN_FIND_OPTARG "[string[;...]]"

#define XOS_APP_CONSOLE_ARCHA_MAIN_FIND_NAME_OPT "find-name"
#define XOS_APP_CONSOLE_ARCHA_MAIN_FIND_NAME_OPTARG_REQUIRED MAIN_OPT_ARGUMENT_OPTIONAL
#define XOS_APP_CONSOLE_ARCHA_MAIN_FIND_NAME_OPTARG_RESULT 0
#define XOS_APP_CONSOLE_ARCHA_MAIN_FIND_NAME_OPTARG XOS_APP_CONSOLE_ARCHA_MAIN_FIND_OPTARG
#define XOS_APP_CONSOLE_ARCHA_MAIN_FIND_NAME_OPTUSE "find name(s)"
#define XOS_APP_CONSOLE_ARCHA_MAIN_FIND_NAME_OPTVAL_S "n::"
#define XOS_APP_CONSOLE_ARCHA_MAIN_FIND_NAME_OPTVAL_C 'n'
#define XOS_APP_CONSOLE_ARCHA_MAIN_FIND_NAME_OPTION \
   {XOS_APP_CONSOLE_ARCHA_MAIN_FIND_NAME_OPT, \
    XOS_APP_CONSOLE_ARCHA_MAIN_FIND_NAME_OPTARG_REQUIRED, \
    XOS_APP_CONSOLE_ARCHA_MAIN_FIND_NAME_OPTARG_RESULT, \
    XOS_APP_CONSOLE_ARCHA_MAIN_FIND_NAME_OPTVAL_C}, \

#define XOS_APP_CONSOLE_ARCHA_MAIN_FIND_BASE_OPT "find-base"
#define XOS_APP_CONSOLE_ARCHA_MAIN_FIND_BASE_OPTARG_REQUIRED MAIN_OPT_ARGUMENT_OPTIONAL
#define XOS_APP_CONSOLE_ARCHA_MAIN_FIND_BASE_OPTARG_RESULT 0
#define XOS_APP_CONSOLE_ARCHA_MAIN_FIND_BASE_OPTARG XOS_APP_CONSOLE_ARCHA_MAIN_FIND_OPTARG
#define XOS_APP_CONSOLE_ARCHA_MAIN_FIND_BASE_OPTUSE "find base(s)"
#define XOS_APP_CONSOLE_ARCHA_MAIN_FIND_BASE_OPTVAL_S "a::"
#define XOS_APP_CONSOLE_ARCHA_MAIN_FIND_BASE_OPTVAL_C 'a'
#define XOS_APP_CONSOLE_ARCHA_MAIN_FIND_BASE_OPTION \
   {XOS_APP_CONSOLE_ARCHA_MAIN_FIND_BASE_OPT, \
    XOS_APP_CONSOLE_ARCHA_MAIN_FIND_BASE_OPTARG_REQUIRED, \
    XOS_APP_CONSOLE_ARCHA_MAIN_FIND_BASE_OPTARG_RESULT, \
    XOS_APP_CONSOLE_ARCHA_MAIN_FIND_BASE_OPTVAL_C}, \

#define XOS_APP_CONSOLE_ARCHA_MAIN_FIND_EXTENSION_OPT "find-extension"
#define XOS_APP_CONSOLE_ARCHA_MAIN_FIND_EXTENSION_OPTARG_REQUIRED MAIN_OPT_ARGUMENT_OPTIONAL
#define XOS_APP_CONSOLE_ARCHA_MAIN_FIND_EXTENSION_OPTARG_RESULT 0
#define XOS_APP_CONSOLE_ARCHA_MAIN_FIND_EXTENSION_OPTARG XOS_APP_CONSOLE_ARCHA_MAIN_FIND_OPTARG
#define XOS_APP_CONSOLE_ARCHA_MAIN_FIND_EXTENSION_OPTUSE "find extension(s)"
#define XOS_APP_CONSOLE_ARCHA_MAIN_FIND_EXTENSION_OPTVAL_S "e::"
#define XOS_APP_CONSOLE_ARCHA_MAIN_FIND_EXTENSION_OPTVAL_C 'e'
#define XOS_APP_CONSOLE_ARCHA_MAIN_FIND_EXTENSION_OPTION \
   {XOS_APP_CONSOLE_ARCHA_MAIN_FIND_EXTENSION_OPT, \
    XOS_APP_CONSOLE_ARCHA_MAIN_FIND_EXTENSION_OPTARG_REQUIRED, \
    XOS_APP_CONSOLE_ARCHA_MAIN_FIND_EXTENSION_OPTARG_RESULT, \
    XOS_APP_CONSOLE_ARCHA_MAIN_FIND_EXTENSION_OPTVAL_C}, \

//////////////////////////////////////////////////////////////////////////
#define XOS_APP_CONSOLE_ARCHA_MAIN_PATTERN_STRING "{ name | name.* | *.name | * }"
#define XOS_APP_CONSOLE_ARCHA_MAIN_PATTERN_OPTARG \
    "[" XOS_APP_CONSOLE_ARCHA_MAIN_PATTERN_STRING "[;...]" "]"

#define XOS_APP_CONSOLE_ARCHA_MAIN_FIND_PATTERN_OPT "find"
#define XOS_APP_CONSOLE_ARCHA_MAIN_FIND_PATTERN_OPTARG_REQUIRED MAIN_OPT_ARGUMENT_OPTIONAL
#define XOS_APP_CONSOLE_ARCHA_MAIN_FIND_PATTERN_OPTARG_RESULT 0
#define XOS_APP_CONSOLE_ARCHA_MAIN_FIND_PATTERN_OPTARG XOS_APP_CONSOLE_ARCHA_MAIN_PATTERN_OPTARG
#define XOS_APP_CONSOLE_ARCHA_MAIN_FIND_PATTERN_OPTUSE "find pattern(s)"
#define XOS_APP_CONSOLE_ARCHA_MAIN_FIND_PATTERN_OPTVAL_S "f::"
#define XOS_APP_CONSOLE_ARCHA_MAIN_FIND_PATTERN_OPTVAL_C 'f'
#define XOS_APP_CONSOLE_ARCHA_MAIN_FIND_PATTERN_OPTION \
   {XOS_APP_CONSOLE_ARCHA_MAIN_FIND_PATTERN_OPT, \
    XOS_APP_CONSOLE_ARCHA_MAIN_FIND_PATTERN_OPTARG_REQUIRED, \
    XOS_APP_CONSOLE_ARCHA_MAIN_FIND_PATTERN_OPTARG_RESULT, \
    XOS_APP_CONSOLE_ARCHA_MAIN_FIND_PATTERN_OPTVAL_C}, \

#define XOS_APP_CONSOLE_ARCHA_MAIN_MATCH_PATTERN_DEFAULT "*"
#define XOS_APP_CONSOLE_ARCHA_MAIN_MATCH_PATTERN_OPT "match"
#define XOS_APP_CONSOLE_ARCHA_MAIN_MATCH_PATTERN_OPTARG_REQUIRED MAIN_OPT_ARGUMENT_OPTIONAL
#define XOS_APP_CONSOLE_ARCHA_MAIN_MATCH_PATTERN_OPTARG_RESULT 0
#define XOS_APP_CONSOLE_ARCHA_MAIN_MATCH_PATTERN_OPTARG XOS_APP_CONSOLE_ARCHA_MAIN_PATTERN_OPTARG
#define XOS_APP_CONSOLE_ARCHA_MAIN_MATCH_PATTERN_OPTUSE "match pattern(s)"
#define XOS_APP_CONSOLE_ARCHA_MAIN_MATCH_PATTERN_OPTVAL_S "m::"
#define XOS_APP_CONSOLE_ARCHA_MAIN_MATCH_PATTERN_OPTVAL_C 'm'
#define XOS_APP_CONSOLE_ARCHA_MAIN_MATCH_PATTERN_OPTION \
   {XOS_APP_CONSOLE_ARCHA_MAIN_MATCH_PATTERN_OPT, \
    XOS_APP_CONSOLE_ARCHA_MAIN_MATCH_PATTERN_OPTARG_REQUIRED, \
    XOS_APP_CONSOLE_ARCHA_MAIN_MATCH_PATTERN_OPTARG_RESULT, \
    XOS_APP_CONSOLE_ARCHA_MAIN_MATCH_PATTERN_OPTVAL_C}, \

#define XOS_APP_CONSOLE_ARCHA_MAIN_SKIP_PATTERN_DEFAULT ""
#define XOS_APP_CONSOLE_ARCHA_MAIN_SKIP_PATTERN_OPT "skip"
#define XOS_APP_CONSOLE_ARCHA_MAIN_SKIP_PATTERN_OPTARG_REQUIRED MAIN_OPT_ARGUMENT_OPTIONAL
#define XOS_APP_CONSOLE_ARCHA_MAIN_SKIP_PATTERN_OPTARG_RESULT 0
#define XOS_APP_CONSOLE_ARCHA_MAIN_SKIP_PATTERN_OPTARG XOS_APP_CONSOLE_ARCHA_MAIN_PATTERN_OPTARG
#define XOS_APP_CONSOLE_ARCHA_MAIN_SKIP_PATTERN_OPTUSE "skip pattern(s)"
#define XOS_APP_CONSOLE_ARCHA_MAIN_SKIP_PATTERN_OPTVAL_S "k::"
#define XOS_APP_CONSOLE_ARCHA_MAIN_SKIP_PATTERN_OPTVAL_C 'k'
#define XOS_APP_CONSOLE_ARCHA_MAIN_SKIP_PATTERN_OPTION \
   {XOS_APP_CONSOLE_ARCHA_MAIN_SKIP_PATTERN_OPT, \
    XOS_APP_CONSOLE_ARCHA_MAIN_SKIP_PATTERN_OPTARG_REQUIRED, \
    XOS_APP_CONSOLE_ARCHA_MAIN_SKIP_PATTERN_OPTARG_RESULT, \
    XOS_APP_CONSOLE_ARCHA_MAIN_SKIP_PATTERN_OPTVAL_C}, \

//////////////////////////////////////////////////////////////////////////
#define XOS_APP_CONSOLE_ARCHA_MAIN_BREADTH_FIRST_SEARCH_OPT "breadth-first-search"
#define XOS_APP_CONSOLE_ARCHA_MAIN_BREADTH_FIRST_SEARCH_OPTARG_REQUIRED MAIN_OPT_ARGUMENT_NONE
#define XOS_APP_CONSOLE_ARCHA_MAIN_BREADTH_FIRST_SEARCH_OPTARG_RESULT 0
#define XOS_APP_CONSOLE_ARCHA_MAIN_BREADTH_FIRST_SEARCH_OPTARG ""
#define XOS_APP_CONSOLE_ARCHA_MAIN_BREADTH_FIRST_SEARCH_OPTUSE "search source breadth first"
#define XOS_APP_CONSOLE_ARCHA_MAIN_BREADTH_FIRST_SEARCH_OPTVAL_S "b"
#define XOS_APP_CONSOLE_ARCHA_MAIN_BREADTH_FIRST_SEARCH_OPTVAL_C 'b'
#define XOS_APP_CONSOLE_ARCHA_MAIN_BREADTH_FIRST_SEARCH_OPTION \
   {XOS_APP_CONSOLE_ARCHA_MAIN_BREADTH_FIRST_SEARCH_OPT, \
    XOS_APP_CONSOLE_ARCHA_MAIN_BREADTH_FIRST_SEARCH_OPTARG_REQUIRED, \
    XOS_APP_CONSOLE_ARCHA_MAIN_BREADTH_FIRST_SEARCH_OPTARG_RESULT, \
    XOS_APP_CONSOLE_ARCHA_MAIN_BREADTH_FIRST_SEARCH_OPTVAL_C}, \

#define XOS_APP_CONSOLE_ARCHA_MAIN_DEPTH_FIRST_SEARCH_OPT "depth-first-search"
#define XOS_APP_CONSOLE_ARCHA_MAIN_DEPTH_FIRST_SEARCH_OPTARG_REQUIRED MAIN_OPT_ARGUMENT_NONE
#define XOS_APP_CONSOLE_ARCHA_MAIN_DEPTH_FIRST_SEARCH_OPTARG_RESULT 0
#define XOS_APP_CONSOLE_ARCHA_MAIN_DEPTH_FIRST_SEARCH_OPTARG ""
#define XOS_APP_CONSOLE_ARCHA_MAIN_DEPTH_FIRST_SEARCH_OPTUSE "search source depth first"
#define XOS_APP_CONSOLE_ARCHA_MAIN_DEPTH_FIRST_SEARCH_OPTVAL_S "d"
#define XOS_APP_CONSOLE_ARCHA_MAIN_DEPTH_FIRST_SEARCH_OPTVAL_C 'd'
#define XOS_APP_CONSOLE_ARCHA_MAIN_DEPTH_FIRST_SEARCH_OPTION \
   {XOS_APP_CONSOLE_ARCHA_MAIN_DEPTH_FIRST_SEARCH_OPT, \
    XOS_APP_CONSOLE_ARCHA_MAIN_DEPTH_FIRST_SEARCH_OPTARG_REQUIRED, \
    XOS_APP_CONSOLE_ARCHA_MAIN_DEPTH_FIRST_SEARCH_OPTARG_RESULT, \
    XOS_APP_CONSOLE_ARCHA_MAIN_DEPTH_FIRST_SEARCH_OPTVAL_C}, \

#define XOS_APP_CONSOLE_ARCHA_MAIN_DEPEND_FIRST_SEARCH_OPT "depend-first-search"
#define XOS_APP_CONSOLE_ARCHA_MAIN_DEPEND_FIRST_SEARCH_OPTARG_REQUIRED MAIN_OPT_ARGUMENT_NONE
#define XOS_APP_CONSOLE_ARCHA_MAIN_DEPEND_FIRST_SEARCH_OPTARG_RESULT 0
#define XOS_APP_CONSOLE_ARCHA_MAIN_DEPEND_FIRST_SEARCH_OPTARG ""
#define XOS_APP_CONSOLE_ARCHA_MAIN_DEPEND_FIRST_SEARCH_OPTUSE "search source depend first"
#define XOS_APP_CONSOLE_ARCHA_MAIN_DEPEND_FIRST_SEARCH_OPTVAL_S "p"
#define XOS_APP_CONSOLE_ARCHA_MAIN_DEPEND_FIRST_SEARCH_OPTVAL_C 'p'
#define XOS_APP_CONSOLE_ARCHA_MAIN_DEPEND_FIRST_SEARCH_OPTION \
   {XOS_APP_CONSOLE_ARCHA_MAIN_DEPEND_FIRST_SEARCH_OPT, \
    XOS_APP_CONSOLE_ARCHA_MAIN_DEPEND_FIRST_SEARCH_OPTARG_REQUIRED, \
    XOS_APP_CONSOLE_ARCHA_MAIN_DEPEND_FIRST_SEARCH_OPTARG_RESULT, \
    XOS_APP_CONSOLE_ARCHA_MAIN_DEPEND_FIRST_SEARCH_OPTVAL_C}, \

#define XOS_APP_CONSOLE_ARCHA_MAIN_BOTTOM_FIRST_SEARCH_OPT "bottom-first-search"
#define XOS_APP_CONSOLE_ARCHA_MAIN_BOTTOM_FIRST_SEARCH_OPTARG_REQUIRED MAIN_OPT_ARGUMENT_NONE
#define XOS_APP_CONSOLE_ARCHA_MAIN_BOTTOM_FIRST_SEARCH_OPTARG_RESULT 0
#define XOS_APP_CONSOLE_ARCHA_MAIN_BOTTOM_FIRST_SEARCH_OPTARG ""
#define XOS_APP_CONSOLE_ARCHA_MAIN_BOTTOM_FIRST_SEARCH_OPTUSE "search source bottom first"
#define XOS_APP_CONSOLE_ARCHA_MAIN_BOTTOM_FIRST_SEARCH_OPTVAL_S "t"
#define XOS_APP_CONSOLE_ARCHA_MAIN_BOTTOM_FIRST_SEARCH_OPTVAL_C 't'
#define XOS_APP_CONSOLE_ARCHA_MAIN_BOTTOM_FIRST_SEARCH_OPTION \
   {XOS_APP_CONSOLE_ARCHA_MAIN_BOTTOM_FIRST_SEARCH_OPT, \
    XOS_APP_CONSOLE_ARCHA_MAIN_BOTTOM_FIRST_SEARCH_OPTARG_REQUIRED, \
    XOS_APP_CONSOLE_ARCHA_MAIN_BOTTOM_FIRST_SEARCH_OPTARG_RESULT, \
    XOS_APP_CONSOLE_ARCHA_MAIN_BOTTOM_FIRST_SEARCH_OPTVAL_C}, \

///////////////////////////////////////////////////////////////////////
#define XOS_APP_CONSOLE_ARCHA_BASE_MAIN_OPTIONS_CHARS_EXTEND \
   XOS_APP_CONSOLE_ARCHA_MAIN_FIND_NAME_OPTVAL_S \
   XOS_APP_CONSOLE_ARCHA_MAIN_FIND_BASE_OPTVAL_S \
   XOS_APP_CONSOLE_ARCHA_MAIN_FIND_EXTENSION_OPTVAL_S \
   XOS_APP_CONSOLE_ARCHA_MAIN_FIND_PATTERN_OPTVAL_S \
   XOS_APP_CONSOLE_ARCHA_MAIN_MATCH_PATTERN_OPTVAL_S \
   XOS_APP_CONSOLE_ARCHA_MAIN_SKIP_PATTERN_OPTVAL_S \
   XOS_APP_CONSOLE_ARCHA_MAIN_DEPTH_FIRST_SEARCH_OPTVAL_S \
   XOS_APP_CONSOLE_ARCHA_MAIN_BREADTH_FIRST_SEARCH_OPTVAL_S \
   XOS_APP_CONSOLE_ARCHA_MAIN_DEPEND_FIRST_SEARCH_OPTVAL_S \
   XOS_APP_CONSOLE_ARCHA_MAIN_BOTTOM_FIRST_SEARCH_OPTVAL_S \

#define XOS_APP_CONSOLE_ARCHA_BASE_MAIN_OPTIONS_OPTIONS_EXTEND \
   XOS_APP_CONSOLE_ARCHA_MAIN_FIND_NAME_OPTION \
   XOS_APP_CONSOLE_ARCHA_MAIN_FIND_BASE_OPTION \
   XOS_APP_CONSOLE_ARCHA_MAIN_FIND_EXTENSION_OPTION \
   XOS_APP_CONSOLE_ARCHA_MAIN_FIND_PATTERN_OPTION \
   XOS_APP_CONSOLE_ARCHA_MAIN_MATCH_PATTERN_OPTION \
   XOS_APP_CONSOLE_ARCHA_MAIN_SKIP_PATTERN_OPTION \
   XOS_APP_CONSOLE_ARCHA_MAIN_DEPTH_FIRST_SEARCH_OPTION \
   XOS_APP_CONSOLE_ARCHA_MAIN_BREADTH_FIRST_SEARCH_OPTION \
   XOS_APP_CONSOLE_ARCHA_MAIN_DEPEND_FIRST_SEARCH_OPTION \
   XOS_APP_CONSOLE_ARCHA_MAIN_BOTTOM_FIRST_SEARCH_OPTION \

///////////////////////////////////////////////////////////////////////
#define XOS_APP_CONSOLE_ARCHA_BASE_MAIN_OPTIONS_CHARS \
   XOS_APP_CONSOLE_ARCHA_BASE_MAIN_OPTIONS_CHARS_EXTEND \
   XOS_APP_CONSOLE_FRAMEWORK_VERSION_MAIN_OPTIONS_CHARS \

#define XOS_APP_CONSOLE_ARCHA_BASE_MAIN_OPTIONS_OPTIONS \
   XOS_APP_CONSOLE_ARCHA_BASE_MAIN_OPTIONS_OPTIONS_EXTEND \
   XOS_APP_CONSOLE_FRAMEWORK_VERSION_MAIN_OPTIONS_OPTIONS \

///////////////////////////////////////////////////////////////////////
#define XOS_APP_CONSOLE_ARCHA_BASE_MAIN_ARGS "[source] [target]"
#define XOS_APP_CONSOLE_ARCHA_BASE_MAIN_ARGV "[source] source directory/file","[target] target directory/file",

namespace xos {
namespace app {
namespace console {
namespace archa {
namespace base {

/// class main_optt
template 
<class TExtends = xos::app::console::framework::version::maint<>,  class TImplements = typename TExtends::implements>

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
    main_optt()
    : run_(0), 
      skip_pattern_(XOS_APP_CONSOLE_ARCHA_MAIN_SKIP_PATTERN),
      match_pattern_(XOS_APP_CONSOLE_ARCHA_MAIN_MATCH_PATTERN),
      find_pattern_(XOS_APP_CONSOLE_ARCHA_MAIN_FIND_PATTERN),
      copy_(XOS_APP_CONSOLE_ARCHA_MAIN_COPY),
      before_(XOS_APP_CONSOLE_ARCHA_MAIN_BEFORE),
      before_found_(XOS_APP_CONSOLE_ARCHA_MAIN_BEFORE_FOUND),
      between_found_(XOS_APP_CONSOLE_ARCHA_MAIN_BETWEEN_FOUND),
      after_found_(XOS_APP_CONSOLE_ARCHA_MAIN_AFTER_FOUND) {
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
    /// ...directory_search_run
    /// ...
    /// ...directory_search_run
    int (derives::*directory_search_run_)(const string_t& source, int argc, char_t** argv, char_t** env);
    virtual int directory_search_run(const string_t& source, int argc, char_t** argv, char_t** env) {
        int err = 0;
        if (directory_search_run_) {
            if (!(err = (this->*directory_search_run_)(source, argc, argv, env))) {
            } else {
            }
        } else {
            if (!(err = default_directory_search_run(source, argc, argv, env))) {
            } else {
            }
        }
        return err;
    }
    virtual int default_directory_search_run(const string_t& source, int argc, char_t** argv, char_t** env) {
        int err = 0;
        if (!(err = depth_first_directory_search_run(source, argc, argv, env))) {
        } else {
        }
        return err;
    }
    virtual int before_directory_search_run(const string_t& source, int argc, char_t** argv, char_t** env) {
        int err = 0;
        return err;
    }
    virtual int after_directory_search_run(const string_t& source, int argc, char_t** argv, char_t** env) {
        int err = 0;
        return err;
    }
    virtual int all_directory_search_run(const string_t& source, int argc, char_t** argv, char_t** env) {
        int err = 0;
        if (!(err = before_directory_search_run(source, argc, argv, env))) {
            int err2 = 0;
            err = directory_search_run(source, argc, argv, env);
            if ((err2 = after_directory_search_run(source, argc, argv, env))) {
                if (!(err)) err = err2;
            }
        }
        return err;
    }
    //////////////////////////////////////////////////////////////////////////
    /// ...depth_first_directory_search_run
    virtual int depth_first_directory_search_run(const string_t& source, int argc, char_t** argv, char_t** env) {
        int err = 0;
        return err;
    }
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
    //////////////////////////////////////////////////////////////////////////
    /// ...breadth_first_directory_search_run
    virtual int breadth_first_directory_search_run(const string_t& source, int argc, char_t** argv, char_t** env) {
        int err = 0;
        return err;
    }
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
    //////////////////////////////////////////////////////////////////////////
    /// ...depend_first_directory_search_run
    virtual int depend_first_directory_search_run(const string_t& source, int argc, char_t** argv, char_t** env) {
        int err = 0;
        return err;
    }
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
    //////////////////////////////////////////////////////////////////////////
    /// ...bottom_first_directory_search_run
    virtual int bottom_first_directory_search_run(const string_t& source, int argc, char_t** argv, char_t** env) {
        int err = 0;
        return err;
    }
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
    /// ...
    /// ...directory_search_run
    //////////////////////////////////////////////////////////////////////////

    //////////////////////////////////////////////////////////////////////////
    /// ...search_run
    /// ...
    /// ...target_search_run
    virtual int target_search_run(const string_t &target, const string_t &source, int argc, char_t** argv, char_t** env) {
        int err = 0;
        LOGGER_IS_LOGGED_INFO("err = all_source_search_run(target, source, argc, argv, env)...");
        err = all_source_search_run(source, argc, argv, env);
        return err;
    }
    virtual int before_target_search_run(const string_t &target, const string_t &source, int argc, char_t** argv, char_t** env) {
        int err = 0;
        return err;
    }
    virtual int after_target_search_run(const string_t &target, const string_t &source, int argc, char_t** argv, char_t** env) {
        int err = 0;
        return err;
    }
    virtual int all_target_search_run(const string_t &target, const string_t &source, int argc, char_t** argv, char_t** env) {
        int err = 0;
        if (!(err = before_target_search_run(target, source, argc, argv, env))) {
            int err2 = 0;
            err = target_search_run(target, source, argc, argv, env);
            if ((err2 = after_target_search_run(target, source, argc, argv, env))) {
                if (!(err)) err = err2;
            }
        }
        return err;
    }
    //////////////////////////////////////////////////////////////////////////
    /// ...source_search_run
    virtual int source_search_run(const string_t& source, int argc, char_t** argv, char_t** env) {
        int err = 0;
        return err;
    }
    virtual int before_source_search_run(const string_t& source, int argc, char_t** argv, char_t** env) {
        int err = 0;
        return err;
    }
    virtual int after_source_search_run(const string_t& source, int argc, char_t** argv, char_t** env) {
        int err = 0;
        return err;
    }
    virtual int all_source_search_run(const string_t& source, int argc, char_t** argv, char_t** env) {
        int err = 0;
        if (!(err = before_source_search_run(source, argc, argv, env))) {
            int err2 = 0;
            err = source_search_run(source, argc, argv, env);
            if ((err2 = after_source_search_run(source, argc, argv, env))) {
                if (!(err)) err = err2;
            }
        }
        return err;
    }
    /// ...
    /// ...search_run
    //////////////////////////////////////////////////////////////////////////

    //////////////////////////////////////////////////////////////////////////
    /// ...target_run / ...source_run
    /// ...
    /// ...target_run
    virtual int target_run(const string_t &target, const string_t &source, int argc, char_t** argv, char_t** env) {
        const char_t* chars = 0; size_t length = 0;
        int err = 0;
        LOGGER_IS_LOGGED_INFO("(chars = target.has_chars(length))...");
        if ((chars = target.has_chars(length))) {
            LOGGER_IS_LOGGED_INFO("...(\"" << chars << "\" = target.has_chars(" << length << "))");
            LOGGER_IS_LOGGED_INFO("(chars = source.has_chars(length))...");
            if ((chars = source.has_chars(length))) {
                LOGGER_IS_LOGGED_INFO("...(\"" << chars << "\" = source.has_chars(" << length << "))");
                LOGGER_IS_LOGGED_INFO("err = all_target_search_run(target, source, argc, argv, env)...");
                err = all_target_search_run(target, source, argc, argv, env);
            } else {
                LOGGER_IS_LOGGED_INFO("...failed on (chars = source.has_chars(" << length << "))");
                LOGGER_IS_LOGGED_INFO("err = extends::run(argc, argv, env)...");
                err = extends::run(argc, argv, env);
            }
        } else {
            LOGGER_IS_LOGGED_INFO("...failed on (chars = target.has_chars(" << length << "))");
            LOGGER_IS_LOGGED_INFO("err = extends::run(argc, argv, env)...");
            err = extends::run(argc, argv, env);
        }
        return err;
    }
    virtual int before_target_run(const string_t &target, const string_t &source, int argc, char_t** argv, char_t** env) {
        int err = 0;
        return err;
    }
    virtual int after_target_run(const string_t &target, const string_t &source, int argc, char_t** argv, char_t** env) {
        int err = 0;
        return err;
    }
    virtual int all_target_run(const string_t &target, const string_t &source, int argc, char_t** argv, char_t** env) {
        int err = 0;
        if (!(err = before_target_run(target, source, argc, argv, env))) {
            int err2 = 0;
            err = target_run(target, source, argc, argv, env);
            if ((err2 = after_target_run(target, source, argc, argv, env))) {
                if (!(err)) err = err2;
            }
        }
        return err;
    }
    //////////////////////////////////////////////////////////////////////////
    /// ...source_run
    virtual int source_run(const string_t &source, int argc, char_t** argv, char_t** env) {
        const char_t* chars = 0; size_t length = 0;
        int err = 0;

        LOGGER_IS_LOGGED_INFO("(chars = source.has_chars(length))...");
        if ((chars = source.has_chars(length))) {
            LOGGER_IS_LOGGED_INFO("...(chars = source.has_chars(length))");
            LOGGER_IS_LOGGED_INFO("err = all_source_search_run(source, argc, argv, env)...");
            err = all_source_search_run(source, argc, argv, env);
        } else {
            LOGGER_IS_LOGGED_INFO("...failed on (chars = source.has_chars(length))");
            LOGGER_IS_LOGGED_INFO("err = extends::run(argc, argv, env);...");
            err = extends::run(argc, argv, env);
        }
        return err;
    }
    virtual int before_source_run(const string_t &source, int argc, char_t** argv, char_t** env) {
        int err = 0;
        return err;
    }
    virtual int after_source_run(const string_t &source, int argc, char_t** argv, char_t** env) {
        int err = 0;
        return err;
    }
    virtual int all_source_run(const string_t &source, int argc, char_t** argv, char_t** env) {
        int err = 0;
        if (!(err = before_source_run(source, argc, argv, env))) {
            int err2 = 0;
            err = source_run(source, argc, argv, env);
            if ((err2 = after_source_run(source, argc, argv, env))) {
                if (!(err)) err = err2;
            }
        }
        return err;
    }
    /// ...
    /// ...target_run / ...source_run
    //////////////////////////////////////////////////////////////////////////

    //////////////////////////////////////////////////////////////////////////
    /// ...file_search_run
    /// ...
    int (derives::*file_search_run_)(const string_t& source, int argc, char_t** argv, char_t** env);
    virtual int file_search_run(const string_t& source, int argc, char_t** argv, char_t** env) {
        int err = 0;
        if (file_search_run_) {
            if (!(err = (this->*file_search_run_)(source, argc, argv, env))) {
            } else {
            }
        } else {
            if (!(err = default_file_search_run(source, argc, argv, env))) {
            } else {
            }
        }
        return err;
    }
    virtual int default_file_search_run(const string_t& source, int argc, char_t** argv, char_t** env) {
        int err = 0;
        if (!(err = output_info_file_search_run(source, argc, argv, env))) {
        } else {
        }
        return err;
    }
    virtual int before_file_search_run(const string_t& source, int argc, char_t** argv, char_t** env) {
        int err = 0;
        return err;
    }
    virtual int after_file_search_run(const string_t& source, int argc, char_t** argv, char_t** env) {
        int err = 0;
        return err;
    }
    virtual int all_file_search_run(const string_t& source, int argc, char_t** argv, char_t** env) {
        int err = 0;
        if (!(err = before_file_search_run(source, argc, argv, env))) {
            int err2 = 0;
            err = file_search_run(source, argc, argv, env);
            if ((err2 = after_file_search_run(source, argc, argv, env))) {
                if (!(err)) err = err2;
            }
        }
        return err;
    }
    //////////////////////////////////////////////////////////////////////////
    /// ...output_info_file_search_run
    virtual int output_info_file_search_run(const string_t& path, int argc, char_t** argv, char_t** env) {
        int err = 0;
        this->outln(path);
        return err;
    }
    virtual int set_output_info_file_search_run(int argc, char_t** argv, char_t** env) {
        int err = 0;
        file_search_run_ = &derives::output_info_file_search_run;
        return err;
    }
    virtual int output_info_file_search_run_set(int argc, char_t** argv, char_t** env) {
        int err = 0;
        return err;
    }
    virtual int unset_output_info_file_search_run(int argc, char_t** argv, char_t** env) {
        int err = 0;
        file_search_run_ = 0;
        return err;
    }
    virtual int output_info_file_search_run_unset(int argc, char_t** argv, char_t** env) {
        int err = 0;
        return err;
    }
    /// ...
    /// ...file_search_run
    //////////////////////////////////////////////////////////////////////////

    //////////////////////////////////////////////////////////////////////////
    /// ...output_find...run
    /// ...
    /// ...output_find_name_run
    virtual int output_find_name_run(int argc, char_t** argv, char_t** env) {
        const string_t &find_name = this->find_name();
        int err = 0;
        this->outln(find_name);
        return err;
    }
    virtual int before_output_find_name_run(int argc, char_t** argv, char_t** env) {
        int err = 0;
        return err;
    }
    virtual int after_output_find_name_run(int argc, char_t** argv, char_t** env) {
        int err = 0;
        return err;
    }
    virtual int all_output_find_name_run(int argc, char_t** argv, char_t** env) {
        int err = 0;
        if (!(err = before_output_find_name_run(argc, argv, env))) {
            int err2 = 0;
            err = output_find_name_run(argc, argv, env);
            if ((err2 = after_output_find_name_run(argc, argv, env))) {
                if (!(err)) err = err2;
            }
        }
        return err;
    }
    virtual int set_output_find_name_run(int argc, char_t** argv, char_t** env) {
        int err = 0;
        run_ = &derives::all_output_find_name_run;
        return err;
    }
    virtual int output_find_name_run_set(int argc, char_t** argv, char_t** env) {
        int err = 0;
        return err;
    }
    virtual int unset_output_find_name_run(int argc, char_t** argv, char_t** env) {
        int err = 0;
        run_ = 0;
        return err;
    }
    virtual int output_find_name_run_unset(int argc, char_t** argv, char_t** env) {
        int err = 0;
        return err;
    }
    //////////////////////////////////////////////////////////////////////////
    /// ...output_find_base_run
    virtual int output_find_base_run(int argc, char_t** argv, char_t** env) {
        const string_t &find_base = this->find_base();
        int err = 0;
        this->outln(find_base);
        return err;
    }
    virtual int before_output_find_base_run(int argc, char_t** argv, char_t** env) {
        int err = 0;
        return err;
    }
    virtual int after_output_find_base_run(int argc, char_t** argv, char_t** env) {
        int err = 0;
        return err;
    }
    virtual int all_output_find_base_run(int argc, char_t** argv, char_t** env) {
        int err = 0;
        if (!(err = before_output_find_base_run(argc, argv, env))) {
            int err2 = 0;
            err = output_find_base_run(argc, argv, env);
            if ((err2 = after_output_find_base_run(argc, argv, env))) {
                if (!(err)) err = err2;
            }
        }
        return err;
    }
    virtual int set_output_find_base_run(int argc, char_t** argv, char_t** env) {
        int err = 0;
        run_ = &derives::all_output_find_base_run;
        return err;
    }
    virtual int output_find_base_run_set(int argc, char_t** argv, char_t** env) {
        int err = 0;
        return err;
    }
    virtual int unset_output_find_base_run(int argc, char_t** argv, char_t** env) {
        int err = 0;
        run_ = 0;
        return err;
    }
    virtual int output_find_base_run_unset(int argc, char_t** argv, char_t** env) {
        int err = 0;
        return err;
    }
    //////////////////////////////////////////////////////////////////////////
    /// ...output_find_extension_run
    virtual int output_find_extension_run(int argc, char_t** argv, char_t** env) {
        const string_t &find_extension = this->find_extension();
        int err = 0;
        this->outln(find_extension);
        return err;
    }
    virtual int before_output_find_extension_run(int argc, char_t** argv, char_t** env) {
        int err = 0;
        return err;
    }
    virtual int after_output_find_extension_run(int argc, char_t** argv, char_t** env) {
        int err = 0;
        return err;
    }
    virtual int all_output_find_extension_run(int argc, char_t** argv, char_t** env) {
        int err = 0;
        if (!(err = before_output_find_extension_run(argc, argv, env))) {
            int err2 = 0;
            err = output_find_extension_run(argc, argv, env);
            if ((err2 = after_output_find_extension_run(argc, argv, env))) {
                if (!(err)) err = err2;
            }
        }
        return err;
    }
    virtual int set_output_find_extension_run(int argc, char_t** argv, char_t** env) {
        int err = 0;
        run_ = &derives::all_output_find_extension_run;
        return err;
    }
    virtual int output_find_extension_run_set(int argc, char_t** argv, char_t** env) {
        int err = 0;
        return err;
    }
    virtual int unset_output_find_extension_run(int argc, char_t** argv, char_t** env) {
        int err = 0;
        run_ = 0;
        return err;
    }
    virtual int output_find_extension_run_unset(int argc, char_t** argv, char_t** env) {
        int err = 0;
        return err;
    }
    /// ...
    /// ...output_find...run
    //////////////////////////////////////////////////////////////////////////

    //////////////////////////////////////////////////////////////////////////
    /// ...output...pattern_run
    /// ...
    /// ...output_find_pattern_run
    virtual int output_find_pattern_run(int argc, char_t** argv, char_t** env) {
        const string_t &find_pattern = this->find_pattern();
        int err = 0;
        this->outln(find_pattern);
        return err;
    }
    virtual int before_output_find_pattern_run(int argc, char_t** argv, char_t** env) {
        int err = 0;
        return err;
    }
    virtual int after_output_find_pattern_run(int argc, char_t** argv, char_t** env) {
        int err = 0;
        return err;
    }
    virtual int all_output_find_pattern_run(int argc, char_t** argv, char_t** env) {
        int err = 0;
        if (!(err = before_output_find_pattern_run(argc, argv, env))) {
            int err2 = 0;
            err = output_find_pattern_run(argc, argv, env);
            if ((err2 = after_output_find_pattern_run(argc, argv, env))) {
                if (!(err)) err = err2;
            }
        }
        return err;
    }
    virtual int set_output_find_pattern_run(int argc, char_t** argv, char_t** env) {
        int err = 0;
        run_ = &derives::all_output_find_pattern_run;
        return err;
    }
    virtual int output_find_pattern_run_set(int argc, char_t** argv, char_t** env) {
        int err = 0;
        return err;
    }
    virtual int unset_output_find_pattern_run(int argc, char_t** argv, char_t** env) {
        int err = 0;
        run_ = 0;
        return err;
    }
    virtual int output_find_pattern_run_unset(int argc, char_t** argv, char_t** env) {
        int err = 0;
        return err;
    }
    //////////////////////////////////////////////////////////////////////////
    /// ...output_match_pattern_run
    virtual int output_match_pattern_run(int argc, char_t** argv, char_t** env) {
        const string_t &match_pattern = this->match_pattern();
        int err = 0;
        this->outln(match_pattern);
        return err;
    }
    virtual int before_output_match_pattern_run(int argc, char_t** argv, char_t** env) {
        int err = 0;
        return err;
    }
    virtual int after_output_match_pattern_run(int argc, char_t** argv, char_t** env) {
        int err = 0;
        return err;
    }
    virtual int all_output_match_pattern_run(int argc, char_t** argv, char_t** env) {
        int err = 0;
        if (!(err = before_output_match_pattern_run(argc, argv, env))) {
            int err2 = 0;
            err = output_match_pattern_run(argc, argv, env);
            if ((err2 = after_output_match_pattern_run(argc, argv, env))) {
                if (!(err)) err = err2;
            }
        }
        return err;
    }
    virtual int set_output_match_pattern_run(int argc, char_t** argv, char_t** env) {
        int err = 0;
        run_ = &derives::all_output_match_pattern_run;
        return err;
    }
    virtual int output_match_pattern_run_set(int argc, char_t** argv, char_t** env) {
        int err = 0;
        return err;
    }
    virtual int unset_output_match_pattern_run(int argc, char_t** argv, char_t** env) {
        int err = 0;
        run_ = 0;
        return err;
    }
    virtual int output_match_pattern_run_unset(int argc, char_t** argv, char_t** env) {
        int err = 0;
        return err;
    }
    //////////////////////////////////////////////////////////////////////////
    /// ...output_skip_pattern_run
    virtual int output_skip_pattern_run(int argc, char_t** argv, char_t** env) {
        const string_t &skip_pattern = this->skip_pattern();
        int err = 0;
        this->outln(skip_pattern);
        return err;
    }
    virtual int before_output_skip_pattern_run(int argc, char_t** argv, char_t** env) {
        int err = 0;
        return err;
    }
    virtual int after_output_skip_pattern_run(int argc, char_t** argv, char_t** env) {
        int err = 0;
        return err;
    }
    virtual int all_output_skip_pattern_run(int argc, char_t** argv, char_t** env) {
        int err = 0;
        if (!(err = before_output_skip_pattern_run(argc, argv, env))) {
            int err2 = 0;
            err = output_skip_pattern_run(argc, argv, env);
            if ((err2 = after_output_skip_pattern_run(argc, argv, env))) {
                if (!(err)) err = err2;
            }
        }
        return err;
    }
    virtual int set_output_skip_pattern_run(int argc, char_t** argv, char_t** env) {
        int err = 0;
        run_ = &derives::all_output_skip_pattern_run;
        return err;
    }
    virtual int output_skip_pattern_run_set(int argc, char_t** argv, char_t** env) {
        int err = 0;
        return err;
    }
    virtual int unset_output_skip_pattern_run(int argc, char_t** argv, char_t** env) {
        int err = 0;
        run_ = 0;
        return err;
    }
    virtual int output_skip_pattern_run_unset(int argc, char_t** argv, char_t** env) {
        int err = 0;
        return err;
    }
    /// ...
    /// ...output...pattern_run
    //////////////////////////////////////////////////////////////////////////

    //////////////////////////////////////////////////////////////////////////
    /// ...argv_run
    virtual int argv_run(int argc, char_t** argv, char_t** env) {
        const string_t &source = this->get_source(), &target = this->get_target();
        const char_t* chars = 0; size_t length = 0;
        int err = 0;

        LOGGER_IS_LOGGED_INFO("(chars = source.has_chars(length))...");
        if ((chars = source.has_chars(length))) {
            LOGGER_IS_LOGGED_INFO("...(chars = source.has_chars(length))");
            LOGGER_IS_LOGGED_INFO("(chars = target.has_chars(length))...");
            if ((chars = target.has_chars(length))) {
                LOGGER_IS_LOGGED_INFO("...(chars = target.has_chars(length))");
                LOGGER_IS_LOGGED_INFO("err = all_target_run(target, source, argc, argv, env)...");
                err = all_target_run(target, source, argc, argv, env);
            } else {
                LOGGER_IS_LOGGED_INFO("...failed on (chars = target.has_chars(length))");
                LOGGER_IS_LOGGED_INFO("err = all_source_run(source, argc, argv, env)...");
                err = all_source_run(source, argc, argv, env);
            }
        } else {
            err = extends::run(argc, argv, env);
        }
        return err;
    }
    virtual int before_argv_run(int argc, char_t** argv, char_t** env) {
        int err = 0, optind = ::optind;
        const char_t* arg = 0;

        LOGGER_IS_LOGGED_INFO("((argc > (optind)) && (arg = argv[optind]) && (arg[0]))...");
        if ((argc > (optind)) && (arg = argv[optind]) && (arg[0])) {
            LOGGER_IS_LOGGED_INFO("...((argc > (" << optind << ")) && (arg = argv[" << optind << "]) && (arg[0]))");
            /*LOGGER_IS_LOGGED_INFO("this->set_source(\"" << arg << "\")...");
            this->set_source(arg);*/
            LOGGER_IS_LOGGED_INFO("!(err = on_source_option(\"" << arg << "\", optind, argc, argv, env))...");
            if (!(err = on_source_option(arg, optind, argc, argv, env))) {
                LOGGER_IS_LOGGED_INFO("...!(" << err << " = on_source_option(\"" << arg << "\", optind, argc, argv, env))");
            } else {
                LOGGER_IS_LOGGED_INFO("...failed on !(" << err << " = on_source_option(\"" << arg << "\", optind, argc, argv, env))");
            }
            LOGGER_IS_LOGGED_INFO("((argc > (++optind)) && (arg = argv[optind]) && (arg[0]))...");
            if ((argc > (++optind)) && (arg = argv[optind]) && (arg[0])) {
                LOGGER_IS_LOGGED_INFO("...((argc > (" << optind << ")) && (arg = argv[" << optind << "]) && (arg[0]))");
                /*LOGGER_IS_LOGGED_INFO("this->set_target(\"" << arg << "\")...");
                this->set_target(arg);*/
                LOGGER_IS_LOGGED_INFO("!(err = on_target_option(\"" << arg << "\", optind, argc, argv, env))...");
                if (!(err = on_target_option(arg, optind, argc, argv, env))) {
                    LOGGER_IS_LOGGED_INFO("...!(" << err << " = on_target_option(\"" << arg << "\", optind, argc, argv, env))");
                } else {
                    LOGGER_IS_LOGGED_INFO("...failed on !(" << err << " = on_target_option(\"" << arg << "\", optind, argc, argv, env))");
                }
            } else {
                LOGGER_IS_LOGGED_INFO("...failed on ((argc > (++optind)) && (arg = argv[optind]) && (arg[0]))");
            }
        } else {
            LOGGER_IS_LOGGED_INFO("...failed on ((argc > (optind)) && (arg = argv[optind]) && (arg[0]))");
            LOGGER_IS_LOGGED_INFO("err = extends::run(argc, argv, env)...");
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
    /// on...find...option...
    /// ...
    /// on...find_name_option...
    virtual int on_get_find_name_option
    (const char_t* optarg, int optind, int argc, char_t**argv, char_t**env) {
        int err = 0;
        return err;
    }
    virtual int on_find_name_option_get
    (const char_t* optarg, int optind, int argc, char_t**argv, char_t**env) {
        int err = 0;
        if (!(err = set_output_find_name_run(argc, argv, env))) {
            if (!(err = output_find_name_run_set(argc, argv, env))) {
            } else {
            }
        } else {
        }
        return err;
    }
    virtual int on_set_find_name_option
    (const char_t* optarg, int optind, int argc, char_t**argv, char_t**env) {
        int err = 0;
        if ((optarg) && (optarg[0])) {
            set_find_name(optarg);
        } else {
        }
        return err;
    }
    virtual int on_find_name_option_set
    (const char_t* optarg, int optind, int argc, char_t**argv, char_t**env) {
        int err = 0;
        if (!(err = set_output_find_name_run(argc, argv, env))) {
            if (!(err = output_find_name_run_set(argc, argv, env))) {
            } else {
            }
        } else {
        }
        return err;
    }
    virtual int on_find_name_option
    (int optval, const char_t* optarg, const char_t* optname,
     int optind, int argc, char_t**argv, char_t**env) {
        int err = 0;
        if ((optarg) && (optarg[0])) {
            if (!(err = on_set_find_name_option(optarg, optind, argc, argv, env))) {
                if (!(err = on_find_name_option_set(optarg, optind, argc, argv, env))) {
                } else {
                }
            } else {
            }
        } else {
            if (!(err = on_get_find_name_option(optarg, optind, argc, argv, env))) {
                if (!(err = on_find_name_option_get(optarg, optind, argc, argv, env))) {
                } else {
                }
            } else {
            }
        }
        return err;
    }
    virtual const char_t* find_name_option_usage(const char_t*& optarg, const struct option* longopt) {
        const char_t* chars = XOS_APP_CONSOLE_ARCHA_MAIN_FIND_NAME_OPTUSE;
        optarg = XOS_APP_CONSOLE_ARCHA_MAIN_FIND_NAME_OPTARG;
        return chars;
    }

    /// on...find_base_option...
    virtual int on_get_find_base_option
    (const char_t* optarg, int optind, int argc, char_t**argv, char_t**env) {
        int err = 0;
        return err;
    }
    virtual int on_find_base_option_get
    (const char_t* optarg, int optind, int argc, char_t**argv, char_t**env) {
        int err = 0;
        if (!(err = set_output_find_base_run(argc, argv, env))) {
            if (!(err = output_find_base_run_set(argc, argv, env))) {
            } else {
            }
        } else {
        }
        return err;
    }
    virtual int on_set_find_base_option
    (const char_t* optarg, int optind, int argc, char_t**argv, char_t**env) {
        int err = 0;
        if ((optarg) && (optarg[0])) {
            set_find_base(optarg);
        } else {
        }
        return err;
    }
    virtual int on_find_base_option_set
    (const char_t* optarg, int optind, int argc, char_t**argv, char_t**env) {
        int err = 0;
        if (!(err = set_output_find_base_run(argc, argv, env))) {
            if (!(err = output_find_base_run_set(argc, argv, env))) {
            } else {
            }
        } else {
        }
        return err;
    }
    virtual int on_find_base_option
    (int optval, const char_t* optarg, const char_t* optname,
     int optind, int argc, char_t**argv, char_t**env) {
        int err = 0;
        if ((optarg) && (optarg[0])) {
            if (!(err = on_set_find_base_option(optarg, optind, argc, argv, env))) {
                if (!(err = on_find_base_option_set(optarg, optind, argc, argv, env))) {
                } else {
                }
            } else {
            }
        } else {
            if (!(err = on_get_find_base_option(optarg, optind, argc, argv, env))) {
                if (!(err = on_find_base_option_get(optarg, optind, argc, argv, env))) {
                } else {
                }
            } else {
            }
        }
        return err;
    }
    virtual const char_t* find_base_option_usage(const char_t*& optarg, const struct option* longopt) {
        const char_t* chars = XOS_APP_CONSOLE_ARCHA_MAIN_FIND_BASE_OPTUSE;
        optarg = XOS_APP_CONSOLE_ARCHA_MAIN_FIND_BASE_OPTARG;
        return chars;
    }

    /// on...find_extension_option...
    virtual int on_get_find_extension_option
    (const char_t* optarg, int optind, int argc, char_t**argv, char_t**env) {
        int err = 0;
        return err;
    }
    virtual int on_find_extension_option_get
    (const char_t* optarg, int optind, int argc, char_t**argv, char_t**env) {
        int err = 0;
        if (!(err = set_output_find_extension_run(argc, argv, env))) {
            if (!(err = output_find_extension_run_set(argc, argv, env))) {
            } else {
            }
        } else {
        }
        return err;
    }
    virtual int on_set_find_extension_option
    (const char_t* optarg, int optind, int argc, char_t**argv, char_t**env) {
        int err = 0;
        if ((optarg) && (optarg[0])) {
            set_find_extension(optarg);
        } else {
        }
        return err;
    }
    virtual int on_find_extension_option_set
    (const char_t* optarg, int optind, int argc, char_t**argv, char_t**env) {
        int err = 0;
        if (!(err = set_output_find_extension_run(argc, argv, env))) {
            if (!(err = output_find_extension_run_set(argc, argv, env))) {
            } else {
            }
        } else {
        }
        return err;
    }
    virtual int on_find_extension_option
    (int optval, const char_t* optarg, const char_t* optname,
     int optind, int argc, char_t**argv, char_t**env) {
        int err = 0;
        if ((optarg) && (optarg[0])) {
            if (!(err = on_set_find_extension_option(optarg, optind, argc, argv, env))) {
                if (!(err = on_find_extension_option_set(optarg, optind, argc, argv, env))) {
                } else {
                }
            } else {
            }
        } else {
            if (!(err = on_get_find_extension_option(optarg, optind, argc, argv, env))) {
                if (!(err = on_find_extension_option_get(optarg, optind, argc, argv, env))) {
                } else {
                }
            } else {
            }
        }
        return err;
    }
    virtual const char_t* find_extension_option_usage(const char_t*& optarg, const struct option* longopt) {
        const char_t* chars = XOS_APP_CONSOLE_ARCHA_MAIN_FIND_EXTENSION_OPTUSE;
        optarg = XOS_APP_CONSOLE_ARCHA_MAIN_FIND_EXTENSION_OPTARG;
        return chars;
    }
    /// ...
    /// on...find...option...
    //////////////////////////////////////////////////////////////////////////

    //////////////////////////////////////////////////////////////////////////
    /// on...pattern_option...
    /// ...
    /// on...find_pattern_option...
    virtual int on_get_find_pattern_option
    (const char_t* optarg, int optind, int argc, char_t**argv, char_t**env) {
        int err = 0;
        return err;
    }
    virtual int on_find_pattern_option_get
    (const char_t* optarg, int optind, int argc, char_t**argv, char_t**env) {
        int err = 0;
        if (!(err = set_output_find_pattern_run(argc, argv, env))) {
            if (!(err = output_find_pattern_run_set(argc, argv, env))) {
            } else {
            }
        } else {
        }
        return err;
    }
    virtual int on_set_find_pattern_option
    (const char_t* optarg, int optind, int argc, char_t**argv, char_t**env) {
        int err = 0;
        if ((optarg) && (optarg[0])) {
            set_find_pattern(optarg);
        } else {
        }
        return err;
    }
    virtual int on_find_pattern_option_set
    (const char_t* optarg, int optind, int argc, char_t**argv, char_t**env) {
        int err = 0;
        if (!(err = set_output_find_pattern_run(argc, argv, env))) {
            if (!(err = output_find_pattern_run_set(argc, argv, env))) {
            } else {
            }
        } else {
        }
        return err;
    }
    virtual int on_find_pattern_option
    (int optval, const char_t* optarg, const char_t* optname,
     int optind, int argc, char_t**argv, char_t**env) {
        int err = 0;
        if ((optarg) && (optarg[0])) {
            if (!(err = on_set_find_pattern_option(optarg, optind, argc, argv, env))) {
                if (!(err = on_find_pattern_option_set(optarg, optind, argc, argv, env))) {
                } else {
                }
            } else {
            }
        } else {
            if (!(err = on_get_find_pattern_option(optarg, optind, argc, argv, env))) {
                if (!(err = on_find_pattern_option_get(optarg, optind, argc, argv, env))) {
                } else {
                }
            } else {
            }
        }
        return err;
    }
    virtual const char_t* find_pattern_option_usage(const char_t*& optarg, const struct option* longopt) {
        const char_t* chars = XOS_APP_CONSOLE_ARCHA_MAIN_FIND_PATTERN_OPTUSE;
        optarg = XOS_APP_CONSOLE_ARCHA_MAIN_FIND_PATTERN_OPTARG;
        return chars;
    }

    /// on...match_pattern_option...
    virtual int on_get_match_pattern_option
    (const char_t* optarg, int optind, int argc, char_t**argv, char_t**env) {
        int err = 0;
        return err;
    }
    virtual int on_match_pattern_option_get
    (const char_t* optarg, int optind, int argc, char_t**argv, char_t**env) {
        int err = 0;
        if (!(err = set_output_match_pattern_run(argc, argv, env))) {
            if (!(err = output_match_pattern_run_set(argc, argv, env))) {
            } else {
            }
        } else {
        }
        return err;
    }
    virtual int on_set_match_pattern_option
    (const char_t* optarg, int optind, int argc, char_t**argv, char_t**env) {
        int err = 0;
        if ((optarg) && (optarg[0])) {
            set_match_pattern(optarg);
        } else {
        }
        return err;
    }
    virtual int on_match_pattern_option_set
    (const char_t* optarg, int optind, int argc, char_t**argv, char_t**env) {
        int err = 0;
        if (!(err = set_output_match_pattern_run(argc, argv, env))) {
            if (!(err = output_match_pattern_run_set(argc, argv, env))) {
            } else {
            }
        } else {
        }
        return err;
    }
    virtual int on_match_pattern_option
    (int optval, const char_t* optarg, const char_t* optname,
     int optind, int argc, char_t**argv, char_t**env) {
        int err = 0;
        if ((optarg) && (optarg[0])) {
            if (!(err = on_set_match_pattern_option(optarg, optind, argc, argv, env))) {
                if (!(err = on_match_pattern_option_set(optarg, optind, argc, argv, env))) {
                } else {
                }
            } else {
            }
        } else {
            if (!(err = on_get_match_pattern_option(optarg, optind, argc, argv, env))) {
                if (!(err = on_match_pattern_option_get(optarg, optind, argc, argv, env))) {
                } else {
                }
            } else {
            }
        }
        return err;
    }
    virtual const char_t* match_pattern_option_usage(const char_t*& optarg, const struct option* longopt) {
        const char_t* chars = XOS_APP_CONSOLE_ARCHA_MAIN_MATCH_PATTERN_OPTUSE;
        optarg = XOS_APP_CONSOLE_ARCHA_MAIN_MATCH_PATTERN_OPTARG;
        return chars;
    }

    /// on...skip_pattern_option...
    virtual int on_get_skip_pattern_option
    (const char_t* optarg, int optind, int argc, char_t**argv, char_t**env) {
        int err = 0;
        return err;
    }
    virtual int on_skip_pattern_option_get
    (const char_t* optarg, int optind, int argc, char_t**argv, char_t**env) {
        int err = 0;
        if (!(err = set_output_skip_pattern_run(argc, argv, env))) {
            if (!(err = output_skip_pattern_run_set(argc, argv, env))) {
            } else {
            }
        } else {
        }
        return err;
    }
    virtual int on_set_skip_pattern_option
    (const char_t* optarg, int optind, int argc, char_t**argv, char_t**env) {
        int err = 0;
        if ((optarg) && (optarg[0])) {
            set_skip_pattern(optarg);
        } else {
        }
        return err;
    }
    virtual int on_skip_pattern_option_set
    (const char_t* optarg, int optind, int argc, char_t**argv, char_t**env) {
        int err = 0;
        if (!(err = set_output_skip_pattern_run(argc, argv, env))) {
            if (!(err = output_skip_pattern_run_set(argc, argv, env))) {
            } else {
            }
        } else {
        }
        return err;
    }
    virtual int on_skip_pattern_option
    (int optval, const char_t* optarg, const char_t* optname,
     int optind, int argc, char_t**argv, char_t**env) {
        int err = 0;
        if ((optarg) && (optarg[0])) {
            if (!(err = on_set_skip_pattern_option(optarg, optind, argc, argv, env))) {
                if (!(err = on_skip_pattern_option_set(optarg, optind, argc, argv, env))) {
                } else {
                }
            } else {
            }
        } else {
            if (!(err = on_get_skip_pattern_option(optarg, optind, argc, argv, env))) {
                if (!(err = on_skip_pattern_option_get(optarg, optind, argc, argv, env))) {
                } else {
                }
            } else {
            }
        }
        return err;
    }
    virtual const char_t* skip_pattern_option_usage(const char_t*& optarg, const struct option* longopt) {
        const char_t* chars = XOS_APP_CONSOLE_ARCHA_MAIN_SKIP_PATTERN_OPTUSE;
        optarg = XOS_APP_CONSOLE_ARCHA_MAIN_SKIP_PATTERN_OPTARG;
        return chars;
    }
    /// ...
    /// on...pattern_option...
    //////////////////////////////////////////////////////////////////////////

    //////////////////////////////////////////////////////////////////////////
    /// on...first_search_option...
    /// ...
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
        const char_t* chars = XOS_APP_CONSOLE_ARCHA_MAIN_BREADTH_FIRST_SEARCH_OPTUSE;
        optarg = XOS_APP_CONSOLE_ARCHA_MAIN_BREADTH_FIRST_SEARCH_OPTARG;
        return chars;
    }

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
        const char_t* chars = XOS_APP_CONSOLE_ARCHA_MAIN_DEPTH_FIRST_SEARCH_OPTUSE;
        optarg = XOS_APP_CONSOLE_ARCHA_MAIN_DEPTH_FIRST_SEARCH_OPTARG;
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
        const char_t* chars = XOS_APP_CONSOLE_ARCHA_MAIN_DEPEND_FIRST_SEARCH_OPTUSE;
        optarg = XOS_APP_CONSOLE_ARCHA_MAIN_DEPEND_FIRST_SEARCH_OPTARG;
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
        const char_t* chars = XOS_APP_CONSOLE_ARCHA_MAIN_BOTTOM_FIRST_SEARCH_OPTUSE;
        optarg = XOS_APP_CONSOLE_ARCHA_MAIN_BOTTOM_FIRST_SEARCH_OPTARG;
        return chars;
    }
    /// ...
    /// on...first_search_option...
    //////////////////////////////////////////////////////////////////////////

    //////////////////////////////////////////////////////////////////////////
    /// on...option...
    /// ...
    /// on...source_option...
    virtual int on_get_source_option
    (const char_t* optarg, int optind, int argc, char_t**argv, char_t**env) {
        int err = 0;
        return err;
    }
    virtual int on_source_option_get
    (const char_t* optarg, int optind, int argc, char_t**argv, char_t**env) {
        int err = 0;
        return err;
    }
    virtual int on_set_source_option
    (const char_t* optarg, int optind, int argc, char_t**argv, char_t**env) {
        int err = 0;
        if ((optarg) && (optarg[0])) {
            LOGGER_IS_LOGGED_INFO("this->set_source(\"" << optarg << "\")...");
            this->set_source(optarg);
        } else {
        }
        return err;
    }
    virtual int on_source_option_set
    (const char_t* optarg, int optind, int argc, char_t**argv, char_t**env) {
        int err = 0;
        if ((optarg) && (optarg[0])) {
        } else {
        }
        return err;
    }
    virtual int on_source_option
    (const char_t* optarg, int optind, int argc, char_t**argv, char_t**env) {
        int err = 0;
        if ((optarg) && (optarg[0])) {
            if (!(err = on_set_source_option(optarg, optind, argc, argv, env))) {
                if (!(err = on_source_option_set(optarg, optind, argc, argv, env))) {
                } else {
                }
            } else {
            }
        } else {
            if (!(err = on_get_source_option(optarg, optind, argc, argv, env))) {
                if (!(err = on_source_option_get(optarg, optind, argc, argv, env))) {
                } else {
                }
            } else {
            }
        }
        return err;
    }
    //////////////////////////////////////////////////////////////////////////
    /// on...target_option...
    virtual int on_get_target_option
    (const char_t* optarg, int optind, int argc, char_t**argv, char_t**env) {
        int err = 0;
        return err;
    }
    virtual int on_target_option_get
    (const char_t* optarg, int optind, int argc, char_t**argv, char_t**env) {
        int err = 0;
        return err;
    }
    virtual int on_set_target_option
    (const char_t* optarg, int optind, int argc, char_t**argv, char_t**env) {
        int err = 0;
        if ((optarg) && (optarg[0])) {
                LOGGER_IS_LOGGED_INFO("this->set_target(\"" << optarg << "\")...");
                this->set_target(optarg);
        } else {
        }
        return err;
    }
    virtual int on_target_option_set
    (const char_t* optarg, int optind, int argc, char_t**argv, char_t**env) {
        int err = 0;
        if ((optarg) && (optarg[0])) {
        } else {
        }
        return err;
    }
    virtual int on_target_option
    (const char_t* optarg, int optind, int argc, char_t**argv, char_t**env) {
        int err = 0;
        if ((optarg) && (optarg[0])) {
            if (!(err = on_set_target_option(optarg, optind, argc, argv, env))) {
                if (!(err = on_target_option_set(optarg, optind, argc, argv, env))) {
                } else {
                }
            } else {
            }
        } else {
            if (!(err = on_get_target_option(optarg, optind, argc, argv, env))) {
                if (!(err = on_target_option_get(optarg, optind, argc, argv, env))) {
                } else {
                }
            } else {
            }
        }
        return err;
    }
    /// ...
    /// on...option...
    //////////////////////////////////////////////////////////////////////////

    //////////////////////////////////////////////////////////////////////////
    /// on_option
    virtual int on_option
    (int optval, const char_t* optarg, const char_t* optname,
     int optind, int argc, char_t**argv, char_t**env) {
        int err = 0;
        switch(optval) {

        case XOS_APP_CONSOLE_ARCHA_MAIN_FIND_NAME_OPTVAL_C:
            err = this->on_find_name_option(optval, optarg, optname, optind, argc, argv, env);
            break;
        case XOS_APP_CONSOLE_ARCHA_MAIN_FIND_BASE_OPTVAL_C:
            err = this->on_find_base_option(optval, optarg, optname, optind, argc, argv, env);
            break;
        case XOS_APP_CONSOLE_ARCHA_MAIN_FIND_EXTENSION_OPTVAL_C:
            err = this->on_find_extension_option(optval, optarg, optname, optind, argc, argv, env);
            break;

        case XOS_APP_CONSOLE_ARCHA_MAIN_FIND_PATTERN_OPTVAL_C:
            err = this->on_find_pattern_option(optval, optarg, optname, optind, argc, argv, env);
            break;
        case XOS_APP_CONSOLE_ARCHA_MAIN_MATCH_PATTERN_OPTVAL_C:
            err = this->on_match_pattern_option(optval, optarg, optname, optind, argc, argv, env);
            break;
        case XOS_APP_CONSOLE_ARCHA_MAIN_SKIP_PATTERN_OPTVAL_C:
            err = this->on_skip_pattern_option(optval, optarg, optname, optind, argc, argv, env);
            break;

        case XOS_APP_CONSOLE_ARCHA_MAIN_BREADTH_FIRST_SEARCH_OPTVAL_C:
            err = this->on_breadth_first_search_option(optval, optarg, optname, optind, argc, argv, env);
            break;
        case XOS_APP_CONSOLE_ARCHA_MAIN_DEPTH_FIRST_SEARCH_OPTVAL_C:
            err = this->on_depth_first_search_option(optval, optarg, optname, optind, argc, argv, env);
            break;
        case XOS_APP_CONSOLE_ARCHA_MAIN_DEPEND_FIRST_SEARCH_OPTVAL_C:
            err = this->on_depend_first_search_option(optval, optarg, optname, optind, argc, argv, env);
            break;
        case XOS_APP_CONSOLE_ARCHA_MAIN_BOTTOM_FIRST_SEARCH_OPTVAL_C:
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

        case XOS_APP_CONSOLE_ARCHA_MAIN_FIND_NAME_OPTVAL_C:
            chars = this->find_name_option_usage(optarg, longopt);
            break;
        case XOS_APP_CONSOLE_ARCHA_MAIN_FIND_BASE_OPTVAL_C:
            chars = this->find_base_option_usage(optarg, longopt);
            break;
        case XOS_APP_CONSOLE_ARCHA_MAIN_FIND_EXTENSION_OPTVAL_C:
            chars = this->find_extension_option_usage(optarg, longopt);
            break;

        case XOS_APP_CONSOLE_ARCHA_MAIN_FIND_PATTERN_OPTVAL_C:
            chars = this->find_pattern_option_usage(optarg, longopt);
            break;
        case XOS_APP_CONSOLE_ARCHA_MAIN_MATCH_PATTERN_OPTVAL_C:
            chars = this->match_pattern_option_usage(optarg, longopt);
            break;
        case XOS_APP_CONSOLE_ARCHA_MAIN_SKIP_PATTERN_OPTVAL_C:
            chars = this->skip_pattern_option_usage(optarg, longopt);
            break;

        case XOS_APP_CONSOLE_ARCHA_MAIN_BREADTH_FIRST_SEARCH_OPTVAL_C:
            chars = this->breadth_first_search_option_usage(optarg, longopt);
            break;
        case XOS_APP_CONSOLE_ARCHA_MAIN_DEPTH_FIRST_SEARCH_OPTVAL_C:
            chars = this->depth_first_search_option_usage(optarg, longopt);
            break;
        case XOS_APP_CONSOLE_ARCHA_MAIN_DEPEND_FIRST_SEARCH_OPTVAL_C:
            chars = this->depend_first_search_option_usage(optarg, longopt);
            break;
        case XOS_APP_CONSOLE_ARCHA_MAIN_BOTTOM_FIRST_SEARCH_OPTVAL_C:
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
        static const char_t* chars = XOS_APP_CONSOLE_ARCHA_BASE_MAIN_OPTIONS_CHARS;
        static struct option optstruct[]= {
            XOS_APP_CONSOLE_ARCHA_BASE_MAIN_OPTIONS_OPTIONS
            {0, 0, 0, 0}};
        longopts = optstruct;
        return chars;
    }

    /// ...on...argument...
    virtual int on_argument
    (const char_t* arg, int argind, int argc, char_t** argv, char** env) {
        int err = 0;
        if ((1 > (argind)) && (0 <= (argind))) {
            if (!(err = set_argv_run(argc, argv, env))) {
                if (!(err = argv_run_set(argc, argv, env))) {
                } else {
                }
            } else {
            }
        } else {
        }
        return err;
    }

    /// arguments
    virtual const char_t* arguments(const char_t**& argv) {
        static const char_t* _args = XOS_APP_CONSOLE_ARCHA_BASE_MAIN_ARGS;
        static const char_t* _argv[] = {
            XOS_APP_CONSOLE_ARCHA_BASE_MAIN_ARGV
            0};
        argv = _argv;
        return _args;
    }
    //////////////////////////////////////////////////////////////////////////

    //////////////////////////////////////////////////////////////////////////
    /// set... / get...
    /// ...
    virtual string_t& set_find_name(const string_t& to) {
        string_t& find_name = this->find_name();
        find_name.assign(to);
        return find_name;
    }
    virtual string_t& set_find_name(const char_t* to, size_t length) {
        string_t& find_name = this->find_name();
        find_name.assign(to, length);
        return find_name;
    }
    virtual string_t& set_find_name(const char_t* to) {
        string_t& find_name = this->find_name();
        find_name.assign(to);
        return find_name;
    }
    virtual const string_t& get_find_name() const {
        string_t& find_name = this->find_name();
        return find_name;
    }
    virtual string_t& find_name() const {
        string_t& find_name = (string_t&)find_name_;
        return find_name;
    }
    //////////////////////////////////////////////////////////////////////////

    //////////////////////////////////////////////////////////////////////////
    virtual string_t& set_find_base(const string_t& to) {
        string_t& find_base = this->find_base();
        find_base.assign(to);
        return find_base;
    }
    virtual string_t& set_find_base(const char_t* to, size_t length) {
        string_t& find_base = this->find_base();
        find_base.assign(to, length);
        return find_base;
    }
    virtual string_t& set_find_base(const char_t* to) {
        string_t& find_base = this->find_base();
        find_base.assign(to);
        return find_base;
    }
    virtual const string_t& get_find_base() const {
        string_t& find_base = this->find_base();
        return find_base;
    }
    virtual string_t& find_base() const {
        string_t& find_base = (string_t&)find_base_;
        return find_base;
    }
    //////////////////////////////////////////////////////////////////////////

    //////////////////////////////////////////////////////////////////////////
    virtual string_t& set_find_extension(const string_t& to) {
        string_t& find_extension = this->find_extension();
        find_extension.assign(to);
        return find_extension;
    }
    virtual string_t& set_find_extension(const char_t* to, size_t length) {
        string_t& find_extension = this->find_extension();
        find_extension.assign(to, length);
        return find_extension;
    }
    virtual string_t& set_find_extension(const char_t* to) {
        string_t& find_extension = this->find_extension();
        find_extension.assign(to);
        return find_extension;
    }
    virtual const string_t& get_find_extension() const {
        string_t& find_extension = this->find_extension();
        return find_extension;
    }
    virtual string_t& find_extension() const {
        string_t& find_extension = (string_t&)find_extension_;
        return find_extension;
    }
    //////////////////////////////////////////////////////////////////////////

    //////////////////////////////////////////////////////////////////////////
    virtual string_t& set_copy(const string_t& to) {
        string_t& copy = this->copy();
        copy.assign(to);
        return copy_set();
    }
    virtual string_t& set_copy(const char_t* to, size_t length) {
        string_t& copy = this->copy();
        copy.assign(to, length);
        return copy_set();
    }
    virtual string_t& set_copy(const char_t* to) {
        string_t& copy = this->copy();
        copy.assign(to);
        return copy_set();
    }
    virtual string_t& copy_set() {
        string_t& copy = this->copy();
        string_t& before = this->before();
        string_t& before_found = this->before_found();
        before_found.assign(copy);
        before_found.append(before);
        return copy;
    }
    virtual const string_t& get_copy() const {
        string_t& copy = this->copy();
        return copy;
    }
    virtual string_t& copy() const {
        string_t& copy = (string_t&)copy_;
        return copy;
    }
    //////////////////////////////////////////////////////////////////////////

    //////////////////////////////////////////////////////////////////////////
    virtual string_t& set_before(const string_t& to) {
        string_t& before = this->before();
        before.assign(to);
        return before;
    }
    virtual string_t& set_before(const char_t* to, size_t length) {
        string_t& before = this->before();
        before.assign(to, length);
        return before;
    }
    virtual string_t& set_before(const char_t* to) {
        string_t& before = this->before();
        before.assign(to);
        return before;
    }
    virtual const string_t& get_before() const {
        string_t& before = this->before();
        return before;
    }
    virtual string_t& before() const {
        string_t& before = (string_t&)before_;
        return before;
    }
    //////////////////////////////////////////////////////////////////////////

    //////////////////////////////////////////////////////////////////////////
    virtual string_t& set_before_found(const string_t& to) {
        string_t& before_found = this->before_found();
        before_found.assign(to);
        return before_found;
    }
    virtual string_t& set_before_found(const char_t* to, size_t length) {
        string_t& before_found = this->before_found();
        before_found.assign(to, length);
        return before_found;
    }
    virtual string_t& set_before_found(const char_t* to) {
        string_t& before_found = this->before_found();
        before_found.assign(to);
        return before_found;
    }
    virtual const string_t& get_before_found() const {
        string_t& before_found = this->before_found();
        return before_found;
    }
    virtual string_t& before_missing() const {
        string_t& before_found = this->before_found();
        return before_found;
    }
    virtual string_t& before_found() const {
        string_t& before_found = (string_t&)before_found_;
        return before_found;
    }
    //////////////////////////////////////////////////////////////////////////

    //////////////////////////////////////////////////////////////////////////
    virtual string_t& set_between_found(const string_t& to) {
        string_t& between_found = this->between_found();
        between_found.assign(to);
        return between_found;
    }
    virtual string_t& set_between_found(const char_t* to, size_t length) {
        string_t& between_found = this->between_found();
        between_found.assign(to, length);
        return between_found;
    }
    virtual string_t& set_between_found(const char_t* to) {
        string_t& between_found = this->between_found();
        between_found.assign(to);
        return between_found;
    }
    virtual const string_t& get_between_found() const {
        string_t& between_found = this->between_found();
        return between_found;
    }
    virtual string_t& between_found() const {
        string_t& between_found = (string_t&)between_found_;
        return between_found;
    }
    //////////////////////////////////////////////////////////////////////////

    //////////////////////////////////////////////////////////////////////////
    virtual string_t& set_after_found(const string_t& to) {
        string_t& after_found = this->after_found();
        after_found.assign(to);
        return after_found;
    }
    virtual string_t& set_after_found(const char_t* to, size_t length) {
        string_t& after_found = this->after_found();
        after_found.assign(to, length);
        return after_found;
    }
    virtual string_t& set_after_found(const char_t* to) {
        string_t& after_found = this->after_found();
        after_found.assign(to);
        return after_found;
    }
    virtual const string_t& get_after_found() const {
        string_t& after_found = this->after_found();
        return after_found;
    }
    virtual string_t& after_found() const {
        string_t& after_found = (string_t&)after_found_;
        return after_found;
    }
    //////////////////////////////////////////////////////////////////////////

    //////////////////////////////////////////////////////////////////////////
    virtual string_t& set_find_pattern(const string_t& to) {
        string_t& find_pattern = this->find_pattern();
        find_pattern.assign(to);
        return find_pattern;
    }
    virtual string_t& set_find_pattern(const char_t* to, size_t length) {
        string_t& find_pattern = this->find_pattern();
        find_pattern.assign(to, length);
        return find_pattern;
    }
    virtual string_t& set_find_pattern(const char_t* to) {
        string_t& find_pattern = this->find_pattern();
        find_pattern.assign(to);
        return find_pattern;
    }
    virtual const string_t& get_find_pattern() const {
        string_t& find_pattern = this->find_pattern();
        return find_pattern;
    }
    virtual string_t& find_pattern() const {
        string_t& find_pattern = (string_t&)find_pattern_;
        return find_pattern;
    }
    //////////////////////////////////////////////////////////////////////////

    //////////////////////////////////////////////////////////////////////////
    virtual string_t& set_match_pattern(const string_t& to) {
        string_t& match_pattern = this->match_pattern();
        match_pattern.assign(to);
        return match_pattern;
    }
    virtual string_t& set_match_pattern(const char_t* to, size_t length) {
        string_t& match_pattern = this->match_pattern();
        match_pattern.assign(to, length);
        return match_pattern;
    }
    virtual string_t& set_match_pattern(const char_t* to) {
        string_t& match_pattern = this->match_pattern();
        match_pattern.assign(to);
        return match_pattern;
    }
    virtual const string_t& get_match_pattern() const {
        string_t& match_pattern = this->match_pattern();
        return match_pattern;
    }
    virtual string_t& match_pattern() const {
        string_t& match_pattern = (string_t&)match_pattern_;
        return match_pattern;
    }
    //////////////////////////////////////////////////////////////////////////

    //////////////////////////////////////////////////////////////////////////
    virtual string_t& set_skip_pattern(const string_t& to) {
        string_t& skip_pattern = this->skip_pattern();
        skip_pattern.assign(to);
        return skip_pattern;
    }
    virtual string_t& set_skip_pattern(const char_t* to, size_t length) {
        string_t& skip_pattern = this->skip_pattern();
        skip_pattern.assign(to, length);
        return skip_pattern;
    }
    virtual string_t& set_skip_pattern(const char_t* to) {
        string_t& skip_pattern = this->skip_pattern();
        skip_pattern.assign(to);
        return skip_pattern;
    }
    virtual const string_t& get_skip_pattern() const {
        string_t& skip_pattern = this->skip_pattern();
        return skip_pattern;
    }
    virtual string_t& skip_pattern() const {
        string_t& skip_pattern = (string_t&)skip_pattern_;
        return skip_pattern;
    }
    //////////////////////////////////////////////////////////////////////////

    //////////////////////////////////////////////////////////////////////////
    virtual string_t& set_source(const string_t& to) {
        string_t& source = this->source();
        source.assign(to);
        return source;
    }
    virtual string_t& set_source(const char_t* to, size_t length) {
        string_t& source = this->source();
        source.assign(to, length);
        return source;
    }
    virtual string_t& set_source(const char_t* to) {
        string_t& source = this->source();
        source.assign(to);
        return source;
    }
    virtual const string_t& get_source() const {
        string_t& source = this->source();
        return source;
    }
    virtual string_t& source() const {
        string_t& source = (string_t&)source_;
        return source;
    }
    //////////////////////////////////////////////////////////////////////////

    //////////////////////////////////////////////////////////////////////////
    virtual string_t& set_target(const string_t& to) {
        string_t& target = this->target();
        target.assign(to);
        return target;
    }
    virtual string_t& set_target(const char_t* to, size_t length) {
        string_t& target = this->target();
        target.assign(to, length);
        return target;
    }
    virtual string_t& set_target(const char_t* to) {
        string_t& target = this->target();
        target.assign(to);
        return target;
    }
    virtual const string_t& get_target() const {
        string_t& target = this->target();
        return target;
    }
    virtual string_t& target() const {
        string_t& target = (string_t&)target_;
        return target;
    }
    /// ...
    /// set... / get...
    //////////////////////////////////////////////////////////////////////////

    //////////////////////////////////////////////////////////////////////////
protected:
    string_t match_pattern_, skip_pattern_, find_pattern_, 
             find_name_, find_base_, find_extension_, 
             copy_, before_, before_found_, between_found_, after_found_,
             source_, target_;
}; /// class main_optt 
typedef main_optt<> main_opt;

} /// namespace base 
} /// namespace archa 
} /// namespace console 
} /// namespace app 
} /// namespace xos 

#endif /// ndef XOS_APP_CONSOLE_ARCHA_BASE_MAIN_OPT_HPP
