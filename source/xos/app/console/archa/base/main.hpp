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
///   Date: 1/21/2024, 1/29/2024
//////////////////////////////////////////////////////////////////////////
#ifndef XOS_APP_CONSOLE_ARCHA_BASE_MAIN_HPP
#define XOS_APP_CONSOLE_ARCHA_BASE_MAIN_HPP

#include "xos/app/console/archa/base/main_opt.hpp"
#include "xos/app/console/archa/branch.hpp"
#include "xos/app/console/archa/leaf.hpp"
#include "xos/app/console/archa/node.hpp"
#include "xos/app/console/archa/find.hpp"
#include "xos/fs/entry/matcher/pattern.hpp"
#include "xos/fs/entry/matcher/patterns.hpp"
#include "xos/fs/entry/pattern/matches.hpp"
#include "xos/fs/entry/matchers.hpp"
#include "xos/fs/entry/all/matcher.hpp"
#include "xos/fs/entry/none/matcher.hpp"
#include "xos/fs/entry/name/matcher.hpp"
#include "xos/fs/entry/base/matcher.hpp"
#include "xos/fs/entry/extension/matcher.hpp"
#include "xos/fs/entry/modified/comparor.hpp"
#include "xos/fs/entry/content/comparor.hpp"
#include "xos/fs/os/entry.hpp"

namespace xos {
namespace app {
namespace console {
namespace archa {
namespace base {

/// class maint
template 
<class TFind = find,
 class TExtends = xos::app::console::archa::base::main_optt<>,  class TImplements = typename TExtends::implements>

class maint: virtual public TFind, virtual public TImplements, public TExtends {
public:
    typedef TImplements implements;
    typedef TExtends extends;
    typedef maint derives;

    typedef archa::node node;
    typedef archa::leaf leaf;
    typedef archa::branch branch;
    typedef archa::entry_type entry_type;
    typedef archa::entry entry;

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
    /// ...search_run
    /// ...
    /// ...depth_first_directory_search_run
    virtual int depth_first_directory_search_run(const string_t& source, int argc, char_t** argv, char_t** env) {
        int err = 0;
        typedef xos::tree::depth_first_searcht<branch, branches, leaves> search;
        typedef xos::tree::findt<branch, find, search> found; 
        branch b(source);
        found(*this, b);
        return err;
    }
    /// ...breadth_first_directory_search_run
    virtual int breadth_first_directory_search_run(const string_t& source, int argc, char_t** argv, char_t** env) {
        int err = 0;
        typedef xos::tree::breadth_first_searcht<branch, branches, leaves> search;
        typedef xos::tree::findt<branch, find, search> found; 
        branch b(source);
        found(*this, b);
        return err;
    }
    /// ...depend_first_directory_search_run
    virtual int depend_first_directory_search_run(const string_t& source, int argc, char_t** argv, char_t** env) {
        int err = 0;
        typedef xos::tree::depend_first_searcht<branch, branches, leaves> search;
        typedef xos::tree::findt<branch, find, search> found; 
        branch b(source);
        found(*this, b);
        return err;
    }
    /// ...bottom_first_directory_search_run
    virtual int bottom_first_directory_search_run(const string_t& source, int argc, char_t** argv, char_t** env) {
        int err = 0;
        typedef xos::tree::bottom_first_searcht<branch, branches, leaves> search;
        typedef xos::tree::findt<branch, find, search> found; 
        branch b(source);
        found(*this, b);
        return err;
    }
    //////////////////////////////////////////////////////////////////////////
    /// ...source_search_run
    virtual int source_search_run(const string_t& source, int argc, char_t** argv, char_t** env) {
        int err = 0;
        ::xos::fs::entry::type_which which = ::xos::fs::entry::type_none;
        ::xos::fs::os::entry entry;

        LOGGER_IS_LOGGED_INFO("(::xos::fs::entry::type_none != (which = exists_entry(entry, \"" << source << "\")))...");
        if (::xos::fs::entry::type_none != (which = exists_entry(entry, source))) {
            LOGGER_IS_LOGGED_INFO("...(::xos::fs::entry::type_none != (" << which << " = exists_entry(entry, \"" << source << "\")))");
            LOGGER_IS_LOGGED_INFO("!(::xos::fs::entry::type_directory != (" << which << ")))...");
            if (!(::xos::fs::entry::type_directory != (which))) {
                LOGGER_IS_LOGGED_INFO("...!(::xos::fs::entry::type_directory != (" << which << ")))");
                if (!(err = this->all_directory_search_run(source, argc, argv, env))) {
                } else {
                }
            } else {
                LOGGER_IS_LOGGED_INFO("...failed on !(::xos::fs::entry::type_directory != (" << which << ")))");
                LOGGER_IS_LOGGED_INFO("!(::xos::fs::entry::type_file != (" << which << ")))...");
                if (!(::xos::fs::entry::type_file != (which))) {
                    LOGGER_IS_LOGGED_INFO("...!(::xos::fs::entry::type_file != (" << which << ")))");
                    if (!(err = this->all_file_search_run(source, argc, argv, env))) {
                    } else {
                    }
                } else {
                    LOGGER_IS_LOGGED_INFO("...failed on !(::xos::fs::entry::type_file != (" << which << ")))");
                }
            }
        } else {
            LOGGER_IS_LOGGED_INFO("...failed on (::xos::fs::entry::type_none != (" << which << " = exists_entry(entry, \"" << source << "\")))");
        }
        return err;
    }
    /// ...
    /// ...search_run
    //////////////////////////////////////////////////////////////////////////

    //////////////////////////////////////////////////////////////////////////
    /// on...option...
    /// ...
    //////////////////////////////////////////////////////////////////////////
    virtual int on_find_name_option_set
    (const char_t* optarg, int optind, int argc, char_t**argv, char_t**env) {
        int err = 0;
        if (!(err = extends::on_find_name_option_set(optarg, optind, argc, argv, env))) {
            ::xos::fs::entry::name::matcher& find_name_matcher = this->find_name_matcher();
            ::xos::fs::entry::matchers& find_matchers = this->find_matchers();
            const string_t& find_name = this->find_name();
            ::xos::fs::entry::pattern::matches find_matches(find_name);
            
            find_matchers.clear();
            find_matches.parse(find_matchers, find_name_matcher);
            if (!(err = set_find_found_entry(argc, argv, env))) {
                if (!(err = find_found_entry_set(argc, argv, env))) {
                } else {
                }
            } else {
            }
        } else {
        }
        return err;
    }
    //////////////////////////////////////////////////////////////////////////
    virtual int on_find_base_option_set
    (const char_t* optarg, int optind, int argc, char_t**argv, char_t**env) {
        int err = 0;
        if (!(err = extends::on_find_base_option_set(optarg, optind, argc, argv, env))) {
            ::xos::fs::entry::base::matcher& find_base_matcher = this->find_base_matcher();
            ::xos::fs::entry::matchers& find_matchers = this->find_matchers();
            const string_t& find_base = this->find_base();
            ::xos::fs::entry::pattern::matches find_matches(find_base);
            
            find_matchers.clear();
            find_matches.parse(find_matchers, find_base_matcher);
            if (!(err = set_find_found_entry(argc, argv, env))) {
                if (!(err = find_found_entry_set(argc, argv, env))) {
                } else {
                }
            } else {
            }
        } else {
        }
        return err;
    }
    //////////////////////////////////////////////////////////////////////////
    virtual int on_find_extension_option_set
    (const char_t* optarg, int optind, int argc, char_t**argv, char_t**env) {
        int err = 0;
        if (!(err = extends::on_find_extension_option_set(optarg, optind, argc, argv, env))) {
            ::xos::fs::entry::extension::matcher& find_extension_matcher = this->find_extension_matcher();
            ::xos::fs::entry::matchers& find_matchers = this->find_matchers();
            const string_t& find_extension = this->find_extension();
            ::xos::fs::entry::pattern::matches find_matches(find_extension);
            
            find_matchers.clear();
            find_matches.parse(find_matchers, find_extension_matcher);
            if (!(err = set_find_found_entry(argc, argv, env))) {
                if (!(err = find_found_entry_set(argc, argv, env))) {
                } else {
                }
            } else {
            }
        } else {
        }
        return err;
    }
    //////////////////////////////////////////////////////////////////////////
    virtual int on_find_pattern_option_set
    (const char_t* optarg, int optind, int argc, char_t**argv, char_t**env) {
        int err = 0;
        if (!(err = extends::on_find_pattern_option_set(optarg, optind, argc, argv, env))) {
            const string_t& find_pattern = this->find_pattern();
            ::xos::fs::entry::matchers& find_matchers = this->find_matchers();
            ::xos::fs::entry::matcher::patterns matcher_patterns(find_pattern);
            
            find_matchers.clear();
            matcher_patterns.parse(find_matchers);
            if (!(err = set_find_found_entry(argc, argv, env))) {
                if (!(err = find_found_entry_set(argc, argv, env))) {
                } else {
                }
            } else {
            }
        } else {
        }
        return err;
    }
    //////////////////////////////////////////////////////////////////////////
    virtual int on_match_pattern_option_set
    (const char_t* optarg, int optind, int argc, char_t**argv, char_t**env) {
        int err = 0;
        if (!(err = extends::on_match_pattern_option_set(optarg, optind, argc, argv, env))) {
            const string_t& match_pattern = this->match_pattern();
            ::xos::fs::entry::matchers& match_matchers = this->match_matchers();
            ::xos::fs::entry::matcher::patterns match_patterns(match_pattern);
            
            match_matchers.clear();
            match_patterns.parse(match_matchers);
            if (!(err = set_match_found_entry(argc, argv, env))) {
                if (!(err = match_found_entry_set(argc, argv, env))) {
                } else {
                }
            } else {
            }
        } else {
        }
        return err;
    }
    //////////////////////////////////////////////////////////////////////////
    virtual int on_skip_pattern_option_set
    (const char_t* optarg, int optind, int argc, char_t**argv, char_t**env) {
        int err = 0;
        if (!(err = extends::on_skip_pattern_option_set(optarg, optind, argc, argv, env))) {
            const string_t& skip_pattern = this->skip_pattern();
            ::xos::fs::entry::matchers& skip_matchers = this->skip_matchers();
            ::xos::fs::entry::matcher::patterns skip_patterns(skip_pattern);
            
            skip_matchers.clear();
            skip_patterns.parse(skip_matchers);
            if (!(err = set_skip_found_entry(argc, argv, env))) {
                if (!(err = skip_found_entry_set(argc, argv, env))) {
                } else {
                }
            } else {
            }
        } else {
        }
        return err;
    }
    //////////////////////////////////////////////////////////////////////////
    virtual int on_target_option_set
    (const char_t* optarg, int optind, int argc, char_t**argv, char_t**env) {
        int err = 0;
        if (!(err = extends::on_target_option_set(optarg, optind, argc, argv, env))) {
            const string_t& skip_pattern = this->skip_pattern();
            const string_t& match_pattern = this->match_pattern();
            ::xos::fs::entry::matchers& skip_matchers = this->skip_matchers();
            ::xos::fs::entry::matchers& match_matchers = this->match_matchers();
            ::xos::fs::entry::matcher::patterns skip_patterns(skip_pattern);
            ::xos::fs::entry::matcher::patterns match_patterns(match_pattern);
            
            skip_matchers.clear();
            skip_patterns.parse(skip_matchers);
            match_matchers.clear();
            match_patterns.parse(match_matchers);
            if (!(err = set_match_found_entry(argc, argv, env))) {
                if (!(err = match_found_entry_set(argc, argv, env))) {
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
    /// ...entry
    /// ...
    //////////////////////////////////////////////////////////////////////////
    /// ...exists_entry
    virtual ::xos::fs::entry::type_which exists_entry(::xos::fs::os::entry &entry, const string_t &path) {
        ::xos::fs::entry::type_which which = ::xos::fs::entry::type_none;
        const char_t* chars = 0; size_t length = 0;

        LOGGER_IS_LOGGED_INFO("(chars = path.has_chars(length))...");
        if ((chars = path.has_chars(length))) {
            bool exists = false;
            
            LOGGER_IS_LOGGED_INFO("(exists = entry.exists(\"" << chars << "\", " << length << "))...");
            if ((exists = entry.exists(chars, length))) {
                LOGGER_IS_LOGGED_INFO("...(" << exists << " = entry.exists(\"" << chars << "\", " << length << "))");

                LOGGER_IS_LOGGED_INFO("(::xos::fs::entry::type_none != (which = entry.type().which()))...");
                if (::xos::fs::entry::type_none != (which = entry.type().which())) {
                    LOGGER_IS_LOGGED_INFO("...(::xos::fs::entry::type_none != (" << which << " = entry.type().which()))");
                } else {
                    LOGGER_IS_LOGGED_INFO("...failed on (::xos::fs::entry::type_none != (" << which << " = entry.type().which()))");
                }
            } else {
                LOGGER_IS_LOGGED_INFO("...failed on (" << exists << " = entry.exists(\"" << chars << "\", " << length << "))");
            }
        } else {
            LOGGER_IS_LOGGED_INFO("...failed on (chars = path.has_chars(" << length << "))");
        }
        return which;
    }
    //////////////////////////////////////////////////////////////////////////
    /// ...found_entry
    int (derives::*found_entry_)(entry *&found, entry &e, const string_t &path);
    virtual int found_entry(entry *&found, entry &e, const string_t &path) {
        int err = 0;
        if (found_entry_) {
            if (!(err = (this->*found_entry_)(found, e, path))) {
            } else {
            }
        } else {
            if (!(err = output_found_entry(found, e, path))) {
            } else {
            }
        }
        return err;
    }
    //////////////////////////////////////////////////////////////////////////
    /// ...output_found_entry_target
    virtual int output_found_entry_target(entry *&found, entry &e, const string_t &path, const string_t &target_path, const string_t &before_found) {
        int err = 0; 
        const char_t *chars = 0; size_t length = 0;

        LOGGER_IS_LOGGED_INFO("(chars = path.has_chars(length))...");
        if ((chars = path.has_chars(length))) {
            const char_t *target_chars = 0; size_t target_length = 0;

            LOGGER_IS_LOGGED_INFO("...(\"" << chars << "\" = path.has_chars(" << length << "))");
            LOGGER_IS_LOGGED_INFO("(target_chars = target_path.has_chars(target_length))...");
            if ((target_chars = target_path.has_chars(target_length))) {
                const string_t &between_found = this->between_found(), &after_found = this->after_found();
                const char_t *before_chars = before_found.chars(), *between_chars = between_found.chars(), *after_chars = after_found.chars();

                LOGGER_IS_LOGGED_INFO("...(\"" << target_chars << "\" = target_path.has_chars(" << target_length << "))");
                this->outlln(before_chars, chars, between_chars, target_chars, after_chars, null);
            } else {
                LOGGER_IS_LOGGED_INFO("...failed on (target_chars = target_path.has_chars(" << target_length << "))");
            }
        } else {
            LOGGER_IS_LOGGED_INFO("...failed on (chars = path.has_chars(" << length << "))");
        }
        return err;
    }
    /// ...output_missing_entry_target
    virtual int output_missing_entry_target(entry *&found, entry &e, const string_t &path, const string_t &target_path) {
        int err = 0; 
        const string_t &before_missing = this->before_missing();

        LOGGER_IS_LOGGED_INFO("err = output_found_entry_target(found, e, \"" << path << "\", \"" << target_path << "\", \"" << before_missing << "\")...");
        err = output_found_entry_target(found, e, path, target_path, before_missing);
        return err;
    }
    /// ...output_found_entry_target
    virtual int output_found_entry_target(entry *&found, entry &e, const string_t &path, const string_t &target_path) {
        int err = 0; 
        const string_t &before_found = this->before_found();

        LOGGER_IS_LOGGED_INFO("err = output_found_entry_target(found, e, \"" << path << "\", \"" << target_path << "\", \"" << before_found << "\")...");
        err = output_found_entry_target(found, e, path, target_path, before_found);
        return err;
    }
    /// ...output_found_entry
    virtual int output_found_entry(entry *&found, entry &e, const string_t &path) {
        int err = 0; const char_t *chars = 0; size_t length = 0;
        LOGGER_IS_LOGGED_INFO("(chars = path.has_chars(length))...");
        if ((chars = path.has_chars(length))) {
            LOGGER_IS_LOGGED_INFO("...(\"" << chars << "\" = path.has_chars(" << length << "))");
            this->outln(chars, length);
        } else {
            LOGGER_IS_LOGGED_INFO("...failed on (chars = path.has_chars(" << length << "))");
        }
        return err;
    }
    //////////////////////////////////////////////////////////////////////////
    /// ...matched_found_entry_target
    virtual int matched_found_entry_target(entry *&found, entry &e, const string_t &path, const string_t &target_path) {
        int err = 0; 
        const char_t *target_chars = 0; size_t target_length = 0; 

        LOGGER_IS_LOGGED_INFO("(target_chars = target_path.has_chars(target_length))...");
        if ((target_chars = target_path.has_chars(target_length))) {
            ::xos::fs::entry::type_which target_type = ::xos::fs::entry::type_none;
            ::xos::fs::os::entry target_entry;
             
            LOGGER_IS_LOGGED_INFO("...(\"" << target_chars << "\" = target_path.has_chars(" << target_length << "))");
            LOGGER_IS_LOGGED_INFO("(::xos::fs::entry::type_none != (target_type = exists_entry(target_entry, \"" << target_path << "\")))...");
            if ((::xos::fs::entry::type_none != (target_type = exists_entry(target_entry, target_path)))) {
                const ::xos::fs::entry::type_which source_type = e.type();

                LOGGER_IS_LOGGED_INFO("...(::xos::fs::entry::type_none != (" << target_type << " = exists_entry(target_entry, \"" << target_path << "\")))");
                LOGGER_IS_LOGGED_INFO("!((source_type = " << source_type << ") != (target_type = " << target_type << "))...");
                if (!((source_type) != (target_type))) {
                    int unequal = 0;
                    ::xos::fs::entry::modified::comparor& modified_comparor = this->modified_comparor();

                    LOGGER_IS_LOGGED_INFO("...!((source_type = " << source_type << ") != (target_type = " << target_type << "))");
                    LOGGER_IS_LOGGED_INFO("(modified_comparor.compares(unequal, e, \"" << path << "\", target_entry, \"" << target_path << "\"))...");
                    if ((modified_comparor.compares(unequal, e, path, target_entry, target_path))) {
                        LOGGER_IS_LOGGED_INFO("...(modified_comparor.compares(" << unequal << ", e, \"" << path << "\", target_entry, \"" << target_path << "\"))");
                        LOGGER_IS_LOGGED_INFO("err = output_found_entry_target(found, e, \"" << path << "\", \"" << target_path << "\")...");
                        err = output_found_entry_target(found, e, path, target_path);
                    } else {
                        LOGGER_IS_LOGGED_INFO("...failed on (modified_comparor.compares(" << unequal << ", e, \"" << path << "\", target_entry, \"" << target_path << "\"))");
                        LOGGER_IS_LOGGED_INFO("(0 == (unequal)...");
                        if ((0 == (unequal))) {
                            ::xos::fs::entry::content::comparor& content_comparor = this->content_comparor();

                            LOGGER_IS_LOGGED_INFO("...(0 == (unequal = " << unequal << ")");
                            LOGGER_IS_LOGGED_INFO("(content_comparor.compares(unequal, e, \"" << path << "\", target_entry, \"" << target_path << "\"))...");
                            if ((content_comparor.compares(unequal, e, path, target_entry, target_path))) {
                                LOGGER_IS_LOGGED_INFO("...(content_comparor.compares(" << unequal << ", e, \"" << path << "\", target_entry, \"" << target_path << "\"))");
                                LOGGER_IS_LOGGED_INFO("err = output_found_entry_target(found, e, \"" << path << "\", \"" << target_path << "\")...");
                                err = output_found_entry_target(found, e, path, target_path);
                            } else {
                                LOGGER_IS_LOGGED_INFO("...failed on (content_comparor.compares(" << unequal << ", e, \"" << path << "\", target_entry, \"" << target_path << "\"))");
                            }
                        } else {
                            LOGGER_IS_LOGGED_INFO("...failed on (0 == (unequal = " << unequal << ")");
                        }
                    }
                } else {
                    LOGGER_IS_LOGGED_INFO("...failed on !((source_type = " << source_type << ") != (target_type = " << target_type << "))");
                }
            } else {
                LOGGER_IS_LOGGED_INFO("...failed on (::xos::fs::entry::type_none != (" << target_type << " = exists_entry(target_entry, target_path)))");
                LOGGER_IS_LOGGED_INFO("err = output_missing_entry_target(found, e, \"" << path << "\", \"" << target_path << "\")...");
                err = output_missing_entry_target(found, e, path, target_path);
            }
        } else {
            LOGGER_IS_LOGGED_INFO("...failed on (target_chars = target_path.has_chars(" << target_length << "))");
            LOGGER_IS_LOGGED_INFO("err = output_found_entry_target(found, e, \"" << path << "\", \"" << target_path << "\")...");
            err = output_found_entry_target(found, e, path, target_path);
        }
        return err;
    }
    /// ...matched_found_entry
    virtual int matched_found_entry(entry *&found, entry &e, const string_t &path) {
        int err = 0; const char_t *chars = 0; size_t length = 0; 

        LOGGER_IS_LOGGED_INFO("(chars = path.has_chars(length))...");
        if ((chars = path.has_chars(length))) {
            const string_t& target = this->target(); 
            const char_t *target_chars = 0; size_t target_length = 0;

            LOGGER_IS_LOGGED_INFO("...(\"" << chars << "\" = path.has_chars(" << length << "))");
            LOGGER_IS_LOGGED_INFO("(target_chars = target.has_chars(target_length))...");
            if ((target_chars = target.has_chars(target_length))) {
                const char_t *path_chars = 0; size_t path_length = 0;

                LOGGER_IS_LOGGED_INFO("...(\"" << target_chars << "\" = target.has_chars(" << target_length << "))");
                LOGGER_IS_LOGGED_INFO("(path_chars = e.has_path(path_length))...");
                if ((path_chars = e.has_path(path_length))) {
                    const char_t *name_chars = 0; size_t name_length = 0;

                    LOGGER_IS_LOGGED_INFO("...(\"" << path_chars << "\" = e.has_path(" << path_length << "))");
                    LOGGER_IS_LOGGED_INFO("(name_chars = e.has_name(name_length))...");
                    if ((name_chars = e.has_name(name_length))) {
                        const string_t& source = this->source();
                        const char_t *source_chars = 0; size_t source_length = 0;

                        LOGGER_IS_LOGGED_INFO("...(\"" << name_chars << "\" = e.has_name(" << name_length << "))");
                        LOGGER_IS_LOGGED_INFO("(source_chars = source.has_chars(source_length))...");
                        if ((source_chars = source.has_chars(source_length))) {
                            string_t target_path(target_chars, target_length);

                            LOGGER_IS_LOGGED_INFO("...(\"" << source_chars << "\" = source.has_chars(" << source_length << "))");
                            LOGGER_IS_LOGGED_INFO("(length = " << length << " > source_length = " << source_length << ")...");
                            if ((length > source_length)) {
                                size_t source_path_length = (length - source_length);
                                const char_t *source_path_chars = (chars + source_length);
                                const char_t *target_path_chars = 0; size_t target_path_length = 0;

                                LOGGER_IS_LOGGED_INFO("...(length = " << length << " > source_length = " << source_length << ")");
                                LOGGER_IS_LOGGED_INFO("target_path.append(\"" << source_path_chars << "\", " << source_path_length << ")...");
                                target_path.append(source_path_chars, source_path_length);
                                LOGGER_IS_LOGGED_INFO("(target_path_chars = target_path.has_chars(target_path_length))...");
                                if ((target_path_chars = target_path.has_chars(target_path_length))) {
                                    LOGGER_IS_LOGGED_INFO("...(\"" << target_path_chars << "\" = target_path.has_chars(" << target_path_length << "))");
                                    LOGGER_IS_LOGGED_INFO("err = matched_found_entry_target(found, e, \"" << path << "\", \"" << target_path << "\")...");
                                    err = matched_found_entry_target(found, e, path, target_path);
                                } else {
                                    LOGGER_IS_LOGGED_INFO("...failed on (target_path_chars = target_path.has_chars(" << target_path_length << "))");
                                }
                            } else {
                                LOGGER_IS_LOGGED_INFO("...failed on (length = " << length << " > source_length = " << source_length << ")");
                            }
                        } else {
                            LOGGER_IS_LOGGED_INFO("...failed on (source_chars = source.has_chars(" << source_length << "))");
                        }
                    } else {
                        LOGGER_IS_LOGGED_INFO("...failed on (name_chars = e.has_name(" << name_length << "))");
                    }
                } else {
                    LOGGER_IS_LOGGED_INFO("...failed on (path_chars = e.has_path(" << path_length << "))");
                }
            } else {
                LOGGER_IS_LOGGED_INFO("...failed on (target_chars = target.has_chars(" << target_length << "))");
                LOGGER_IS_LOGGED_INFO("err = output_found_entry(found, e, \"" << path << "\")...");
                err = output_found_entry(found, e, path);
            }
        } else {
            LOGGER_IS_LOGGED_INFO("...failed on (chars = path.has_chars(" << length << "))");
        }
        return err;
    }
    //////////////////////////////////////////////////////////////////////////
    /// ...skip_found_entry
    virtual int skip_found_entry(entry *&found, entry &e, const string_t &path) {
        int err = 0; entry_type type = 0; const char_t *chars = 0; size_t length = 0;
        LOGGER_IS_LOGGED_INFO("(chars = e.name(length)) && (fs::entry::type_file == (type = e.type()))...");
        if ((chars = e.name(length)) && (fs::entry::type_file == (type = e.type()))) {
            LOGGER_IS_LOGGED_INFO("...(\"" << chars << "\" = e.name(" << length << ")) && (fs::entry::type_file == (" << type << " = e.type()))");
            LOGGER_IS_LOGGED_INFO("(skip_matchers_.matches(e))...");
            if ((skip_matchers_.matches(e))) {
                LOGGER_IS_LOGGED_INFO("...(skip_matchers_.matches(e))");
            } else {
                LOGGER_IS_LOGGED_INFO("...failed on (skip_matchers_.matches(e))");
                LOGGER_IS_LOGGED_INFO("err = matched_found_entry(found, e, \"" << path << "\")...");
                err = matched_found_entry(found, e, path);
            }
        } else {
            LOGGER_IS_LOGGED_INFO("...failed on (chars = e.name(" << length << ")) && (fs::entry::type_file == (" << type << " = e.type()))");
        }
        return err;
    }
    virtual int set_skip_found_entry(int argc, char_t** argv, char_t** env) {
        int err = 0;
        found_entry_ = &derives::skip_found_entry;
        return err;
    }
    virtual int skip_found_entry_set(int argc, char_t** argv, char_t** env) {
        int err = 0;
        return err;
    }
    virtual int unset_skip_found_entry(int argc, char_t** argv, char_t** env) {
        int err = 0;
        found_entry_ = 0;
        return err;
    }
    virtual int skip_found_entry_unset(int argc, char_t** argv, char_t** env) {
        int err = 0;
        return err;
    }
    //////////////////////////////////////////////////////////////////////////
    /// ...match_found_entry
    virtual int match_found_entry(entry *&found, entry &e, const string_t &path) {
        int err = 0; entry_type type = 0; const char_t *chars = 0; size_t length = 0;
        LOGGER_IS_LOGGED_INFO("(chars = e.name(length)) && (fs::entry::type_file == (type = e.type()))...");
        if ((chars = e.name(length)) && (fs::entry::type_file == (type = e.type()))) {
            LOGGER_IS_LOGGED_INFO("...(\"" << chars << "\" = e.name(" << length << ")) && (fs::entry::type_file == (" << type << " = e.type()))");
            LOGGER_IS_LOGGED_INFO("(skip_matchers_.matches(e))...");
            if ((skip_matchers_.matches(e))) {
                LOGGER_IS_LOGGED_INFO("...(skip_matchers_.matches(e))");
            } else {
                LOGGER_IS_LOGGED_INFO("...failed on (skip_matchers_.matches(e))");
                LOGGER_IS_LOGGED_INFO("(match_matchers_.matches(e))...");
                if ((match_matchers_.matches(e))) {
                    LOGGER_IS_LOGGED_INFO("...(match_matchers_.matches(e))");
                    LOGGER_IS_LOGGED_INFO("err = matched_found_entry(found, e, \"" << path << "\")...");
                    err = matched_found_entry(found, e, path);
                } else {
                    LOGGER_IS_LOGGED_INFO("...failed on (match_matchers_.matches(e))");
                }
            }
        } else {
            LOGGER_IS_LOGGED_INFO("...failed on (chars = e.name(" << length << ")) && (fs::entry::type_file == (" << type << " = e.type()))");
        }
        return err;
    }
    virtual int set_match_found_entry(int argc, char_t** argv, char_t** env) {
        int err = 0;
        found_entry_ = &derives::match_found_entry;
        return err;
    }
    virtual int match_found_entry_set(int argc, char_t** argv, char_t** env) {
        int err = 0;
        return err;
    }
    virtual int unset_match_found_entry(int argc, char_t** argv, char_t** env) {
        int err = 0;
        found_entry_ = 0;
        return err;
    }
    virtual int match_found_entry_unset(int argc, char_t** argv, char_t** env) {
        int err = 0;
        return err;
    }
    //////////////////////////////////////////////////////////////////////////
    /// ...find_found_entry
    virtual int find_found_entry(entry *&found, entry &e, const string_t &path) {
        int err = 0; entry_type type = 0; const char_t *chars = 0; size_t length = 0;
        LOGGER_IS_LOGGED_INFO("(chars = e.name(length)) && (fs::entry::type_file == (type = e.type()))...");
        if ((chars = e.name(length))) {
            LOGGER_IS_LOGGED_INFO("...(\"" << chars << "\" = e.name(" << length << ")) && (fs::entry::type_file == (" << type << " = e.type()))");
            LOGGER_IS_LOGGED_INFO("(skip_matchers_.matches(e))...");
            if ((skip_matchers_.matches(e))) {
                LOGGER_IS_LOGGED_INFO("...(skip_matchers_.matches(e))");
            } else {
                LOGGER_IS_LOGGED_INFO("...failed on (skip_matchers_.matches(e))");
                LOGGER_IS_LOGGED_INFO("(find_matchers_.matches(e))...");
                if ((find_matchers_.matches(e))) {
                    LOGGER_IS_LOGGED_INFO("...(find_matchers_.matches(e))");
                    LOGGER_IS_LOGGED_INFO("err = matched_found_entry(found, e, \"" << path << "\")...");
                    err = matched_found_entry(found, e, path);
                } else {
                    LOGGER_IS_LOGGED_INFO("...failed on (find_matchers_.matches(e))");
                }
            }
        } else {
            LOGGER_IS_LOGGED_INFO("...failed on (chars = e.name(" << length << ")) && (fs::entry::type_file == (" << type << " = e.type()))");
        }
        return err;
    }
    virtual int set_find_found_entry(int argc, char_t** argv, char_t** env) {
        int err = 0;
        found_entry_ = &derives::find_found_entry;
        return err;
    }
    virtual int find_found_entry_set(int argc, char_t** argv, char_t** env) {
        int err = 0;
        return err;
    }
    virtual int unset_find_found_entry(int argc, char_t** argv, char_t** env) {
        int err = 0;
        found_entry_ = 0;
        return err;
    }
    virtual int find_found_entry_unset(int argc, char_t** argv, char_t** env) {
        int err = 0;
        return err;
    }
    /// ...
    /// ...found
    //////////////////////////////////////////////////////////////////////////

public:
    //////////////////////////////////////////////////////////////////////////
    /// found
    virtual leaf* found(leaf* l) {
        leaf* lfound = 0;
        entry* efound = 0;
        entry* e = l;
        if ((efound = found(e))) {
            LOGGER_IS_LOGGED_INFO("...lfound = l");
            lfound = l;
        }
        return lfound;
    }
    virtual branch* found(branch* b) {
        branch* bfound = 0;
        entry* efound = 0;
        entry* e = b;
        if ((efound = found(e))) {
            LOGGER_IS_LOGGED_INFO("...bfound = b");
            bfound = b;
        } else {
            leaf* lfound = 0;            
            for (auto l: b->leaves()) {
                if ((lfound = found(l))) {
                    LOGGER_IS_LOGGED_INFO("...bfound = b");
                    bfound = b;
                    break;
                }
            }
        }
        return bfound;
    }
    virtual entry* found(entry* e) {
        typedef entry::char_t char_t;
        entry* efound = 0;
        if (e) {
            const char_t *name_chars = 0; size_t name_length = 0;

            LOGGER_IS_LOGGED_INFO("(name_chars = e->has_name(name_length))...");
            if ((name_chars = e->has_name(name_length))) {
                const char_t *path_chars = 0; size_t path_length = 0;

                LOGGER_IS_LOGGED_INFO("...(\"" << name_chars << "\" = e->has_name(" << name_length << "))");
                LOGGER_IS_LOGGED_INFO("(path_chars = e->has_path_name(path_length))...");
                if ((path_chars = e->has_path_name(path_length))) {
                    const char_t *separator_chars = e->directory_separator_chars();
                    string_t path(path_chars, path_length);

                    LOGGER_IS_LOGGED_INFO("...(\"" << path_chars << "\" = e->has_path_name(" << path_length << "))");
                    LOGGER_IS_LOGGED_INFO("e->set_path(\"" << path_chars << "\", " << path_length << ")...");
                    e->set_path(path_chars, path_length);
                    LOGGER_IS_LOGGED_INFO("e->separate_name()...");
                    e->separate_name();
                    LOGGER_IS_LOGGED_INFO("((\"" << path_chars << "\"[" << path_length-1 << "]) != (\"" << separator_chars << "\"[0]))...");
                    if (((path_chars[path_length-1]) != (separator_chars[0]))) {
                        LOGGER_IS_LOGGED_INFO("...((\"" << path_chars << "\"[" << path_length-1 << "]) != (\"" << separator_chars << "\"[0]))");
                        LOGGER_IS_LOGGED_INFO("path.append(\"" << separator_chars << "\")...");
                        path.append(separator_chars);
                    } else {
                        LOGGER_IS_LOGGED_INFO("...failed on ((\"" << path_chars << "\"[" << path_length-1 << "]) != (\"" << separator_chars << "\"[0]))");
                    }
                    LOGGER_IS_LOGGED_INFO("path.append(\"" << name_chars << "\", " << name_length << ")...");
                    path.append(name_chars, name_length);
                    LOGGER_IS_LOGGED_INFO("(path_chars = path.has_chars(path_length))...");
                    if ((path_chars = path.has_chars(path_length))) {
                        int err = 0;
                        LOGGER_IS_LOGGED_INFO("...(\"" << path_chars << "\" = path.has_chars(" << path_length << "))");
                        LOGGER_IS_LOGGED_INFO("!(err = found_entry(efound, *e, \"" << path << "\"))...");
                        if (!(err = found_entry(efound, *e, path))) {
                            LOGGER_IS_LOGGED_INFO("...!(" << err << " = found_entry(efound, *e, \"" << path << "\"))");
                        } else {
                            LOGGER_IS_LOGGED_INFO("...failed on !(" << err << " = found_entry(efound, *e, \"" << path << "\"))");
                        }
                    } else {
                        LOGGER_IS_LOGGED_INFO("...failed on (path_chars = path.has_chars(" << path_length << "))");
                    }
                } else {
                    LOGGER_IS_LOGGED_INFO("...failed on (path_chars = e->has_path_name(" << path_length << "))");
                }
            } else {
                LOGGER_IS_LOGGED_INFO("...failed on (name_chars = e->has_name(" << name_length << "))");
            }
        }
        return efound;
    }
    //////////////////////////////////////////////////////////////////////////

protected:
    //////////////////////////////////////////////////////////////////////////
    /// ...comparor...
    virtual ::xos::fs::entry::modified::comparor& modified_comparor() const {
        return (::xos::fs::entry::modified::comparor&)modified_comparor_;
    }
    virtual ::xos::fs::entry::content::comparor& content_comparor() const {
        return (::xos::fs::entry::content::comparor&)content_comparor_;
    }
    //////////////////////////////////////////////////////////////////////////
    /// ...matcher...
    virtual ::xos::fs::entry::name::matcher& find_name_matcher() const {
        return (::xos::fs::entry::name::matcher&)find_name_matcher_;
    }
    virtual ::xos::fs::entry::base::matcher& find_base_matcher() const {
        return (::xos::fs::entry::base::matcher&)find_base_matcher_;
    }
    virtual ::xos::fs::entry::extension::matcher& find_extension_matcher() const {
        return (::xos::fs::entry::extension::matcher&)find_extension_matcher_;
    }
    virtual ::xos::fs::entry::matchers& find_matchers() const {
        return (::xos::fs::entry::matchers&)find_matchers_;
    }
    virtual ::xos::fs::entry::matchers& match_matchers() const {
        return (::xos::fs::entry::matchers&)match_matchers_;
    }
    virtual ::xos::fs::entry::matchers& skip_matchers() const {
        return (::xos::fs::entry::matchers&)skip_matchers_;
    }
    //////////////////////////////////////////////////////////////////////////

    //////////////////////////////////////////////////////////////////////////
protected:
    ::xos::fs::entry::modified::comparor modified_comparor_;
    ::xos::fs::entry::content::comparor content_comparor_;
    ::xos::fs::entry::name::matcher find_name_matcher_;
    ::xos::fs::entry::base::matcher find_base_matcher_;
    ::xos::fs::entry::extension::matcher find_extension_matcher_;
    ::xos::fs::entry::matchers find_matchers_, match_matchers_, skip_matchers_;
}; /// class maint 
typedef maint<> main;

} /// namespace base 
} /// namespace archa 
} /// namespace console 
} /// namespace app 
} /// namespace xos 

#endif /// ndef XOS_APP_CONSOLE_ARCHA_BASE_MAIN_HPP
