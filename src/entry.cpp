#include "entry.h"

#include <libtorrent/entry.hpp>

using namespace lt;

entry::entry(const libtorrent::entry& e)
{
    entry_ = new libtorrent::entry(e);
}

entry::~entry()
{
    delete entry_;
}

libtorrent::entry* entry::ptr()
{
    return entry_;
}
