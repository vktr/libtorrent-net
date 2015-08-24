#include "torrent_handle.h"

#include <libtorrent/torrent_handle.hpp>

using namespace lt;

torrent_handle::torrent_handle(libtorrent::torrent_handle& handle)
{
    handle_ = new libtorrent::torrent_handle(handle);
}

torrent_handle::~torrent_handle()
{
    delete handle_;
}
