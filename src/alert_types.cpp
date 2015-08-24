#include "alert_types.h"

#include <libtorrent/alert_types.hpp>

#include "interop.h"
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

read_piece_alert::read_piece_alert(libtorrent::read_piece_alert* a)
    : torrent_alert(a),
    alert_(a)
{
    // TODO set buffer
}

cli::array<System::Byte>^ read_piece_alert::buffer::get()
{
    throw gcnew System::NotImplementedException();
}

int read_piece_alert::piece::get()
{
    return alert_->piece;
}

int read_piece_alert::size::get()
{
    return alert_->size;
}

file_completed_alert::file_completed_alert(libtorrent::file_completed_alert* a)
    : torrent_alert(a),
    alert_(a)
{
}

int file_completed_alert::index::get()
{
    return alert_->index;
}

file_renamed_alert::file_renamed_alert(libtorrent::file_renamed_alert* a)
    : torrent_alert(a),
    alert_(a)
{
}

System::String^ file_renamed_alert::name::get()
{
    return interop::from_std_string(alert_->name);
}

int file_renamed_alert::index::get()
{
    return alert_->index;
}

file_rename_failed_alert::file_rename_failed_alert(libtorrent::file_rename_failed_alert* a)
    : torrent_alert(a),
    alert_(a)
{
}

int file_rename_failed_alert::index::get()
{
    return alert_->index;
}

performance_alert::performance_alert(libtorrent::performance_alert* a)
    : torrent_alert(a),
    alert_(a)
{
}

int performance_alert::warning_code::get()
{
    return (int)alert_->warning_code;
}
