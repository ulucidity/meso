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
///   File: event.hpp
///
/// Author: $author$
///   Date: 1/8/2024
//////////////////////////////////////////////////////////////////////////
#ifndef XOS_BASE_EVENT_HPP
#define XOS_BASE_EVENT_HPP

#include "xos/base/logged.hpp"

namespace xos {

/// enum event_handled_status
typedef int event_handled_status;
enum {
    event_unhandled = 0,
    event_handled_success,
    event_handled_failed
};/// enum event_handled_status

/// class eventt
template <class TExtends = xos::extended::logged, class TImplements = typename TExtends::implements>
class exported eventt: virtual public TImplements, public TExtends {
public:
    typedef TImplements implements;
    typedef TExtends extends;
    typedef eventt derives;

    /// constructor / destructor
    eventt(const eventt &copy): extends(copy) {
    }
    eventt() {
    }
    virtual ~eventt() {
    }

protected:
}; /// class eventt
typedef eventt<> event;

} /// namespace xos 

#endif /// ndef XOS_BASE_EVENT_HPP
