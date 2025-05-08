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
///   Date: 1/3/2024
//////////////////////////////////////////////////////////////////////////
#ifndef XOS_TREE_NODE_HPP
#define XOS_TREE_NODE_HPP

#include "xos/tree/range.hpp"

namespace xos {
namespace tree {

/// class nodet
template 
<class TBranch, class TLeaf, class TNode, class TStream, 
 class TExtends = extend, class TImplements = implement>
class exported nodet: virtual public TImplements, public TExtends {
public:
    typedef TImplements implements;
    typedef TExtends extends;
    typedef nodet derives;

    typedef TBranch branch_t;
    typedef TLeaf leaf_t;
    typedef TNode node_t;
    typedef TStream stream_t;

    /// constructor / destructor
    nodet(const nodet &copy): depth_(copy.depth()) {
    }
    nodet() {
    }
    virtual ~nodet() {
    }

    /// write... / read...
    virtual ssize_t write(stream_t& to) const {
        return 0;
    }
    virtual ssize_t read(stream_t& from) {
        return 0;
    }
    virtual operator branch_t* () const {
        return 0;
    }
    virtual operator leaf_t* () const {
        return 0;
    }

    /// ...depth
    virtual size_t& set_depth(size_t to) {
        size_t& depth = this->depth();
        depth = to;
        return depth;
    }
    virtual const size_t& get_depth() const {
        const size_t& depth = this->depth();
        return depth;
    }
    virtual size_t& depth() const {
        return (size_t&)depth_;
    }

protected:
    size_t depth_;
}; /// class nodet
///typedef nodet<> node;

} /// namespace tree 
} /// namespace xos 

#endif /// ndef XOS_TREE_NODE_HPP
