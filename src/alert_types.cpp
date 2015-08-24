#include "alert_types.h"

#include <libtorrent/alert_types.hpp>

#include "torrent_handle.h"

using namespace lt;

torrent_alert::torrent_alert(libtorrent::torrent_alert* a)
    : alert(a)
{
    handle_ = gcnew torrent_handle(a->handle);
}

torrent_handle^ torrent_alert::handle::get()
{
    return handle_;
}

torrent_added_alert::torrent_added_alert(libtorrent::torrent_added_alert* a)
    : torrent_alert(a)
{
}

torrent_removed_alert::torrent_removed_alert(libtorrent::torrent_removed_alert* a)
    : torrent_alert(a)
{
}
