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
///   File: range.hpp
///
/// Author: $author$
///   Date: 1/2/2024
//////////////////////////////////////////////////////////////////////////
#ifndef XOS_TREE_RANGE_HPP
#define XOS_TREE_RANGE_HPP

#include "xos/base/base.hpp"
#include <list>

namespace xos {
namespace tree {

/// class reverse_ranget
template <class TRange, class TExtends = extend, class TImplements = implement>
class exported reverse_ranget: virtual public TImplements, public TExtends {
public:
    typedef TImplements implements;
    typedef TExtends extends;
    typedef reverse_ranget derives;

    typedef TRange range_t;
    
    /// constructor / destructor
    reverse_ranget(range_t& range): range_(range) {
    }
    reverse_ranget(const reverse_ranget &copy): range_(copy.range_) {
    }
    reverse_ranget(): range_(this_range_) {
    }
    virtual ~reverse_ranget() {
    }

    /// begin / end
    typename range_t::reverse_iterator begin() const {
        return range_.rbegin();
    }
    typename range_t::reverse_iterator end() const {
        return range_.rend();
    }

protected:
    range_t this_range_, &range_;
}; /// class reverse_ranget
///typedef reverse_ranget<> reverse_range;

} /// namespace tree 
} /// namespace xos 

#endif /// ndef XOS_TREE_RANGE_HPP
