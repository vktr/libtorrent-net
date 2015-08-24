#include "torrent_handle.h"

#include <libtorrent/torrent_handle.hpp>

#include "torrent_status.h"

using namespace lt;

torrent_handle::torrent_handle(libtorrent::torrent_handle& handle)
{
    handle_ = new libtorrent::torrent_handle(handle);
}

torrent_handle::~torrent_handle()
{
    delete handle_;
}

torrent_status^ torrent_handle::status()
{
    return gcnew torrent_status(handle_->status());
}
