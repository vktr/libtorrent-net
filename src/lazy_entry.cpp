#include "lazy_entry.h"

#include <libtorrent/lazy_entry.hpp>

using namespace lt;

lazy_entry::lazy_entry(libtorrent::lazy_entry& e)
{
    entry_ = new libtorrent::lazy_entry();
    entry_->swap(e);
}

lazy_entry::~lazy_entry()
{
    delete entry_;
}

libtorrent::lazy_entry* lazy_entry::ptr()
{
    return entry_;
}