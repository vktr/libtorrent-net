#include "torrent_handle.h"

#include <libtorrent/torrent_handle.hpp>

#include "interop.h"
#include "torrent_info.h"
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

libtorrent::torrent_handle* torrent_handle::ptr()
{
    return handle_;
}

void torrent_handle::read_piece(int index)
{
    handle_->read_piece(index);
}

bool torrent_handle::have_piece(int index)
{
    return handle_->have_piece(index);
}

torrent_status^ torrent_handle::status()
{
    return gcnew torrent_status(handle_->status());
}

void torrent_handle::reset_piece_deadline(int index)
{
    handle_->reset_piece_deadline(index);
}

void torrent_handle::clear_piece_deadlines()
{
    handle_->clear_piece_deadlines();
}

void torrent_handle::set_piece_deadline(int index, int deadline)
{
    handle_->set_piece_deadline(index, deadline);
}

void torrent_handle::set_priority(int priority)
{
    handle_->set_priority(priority);
}

void torrent_handle::clear_error()
{
    handle_->clear_error();
}

bool torrent_handle::is_valid()
{
    return handle_->is_valid();
}

void torrent_handle::pause()
{
    handle_->pause();
}

void torrent_handle::resume()
{
    handle_->resume();
}

void torrent_handle::set_upload_mode(bool m)
{
    handle_->set_upload_mode(m);
}

void torrent_handle::set_share_mode(bool m)
{
    handle_->set_share_mode(m);
}

void torrent_handle::flush_cache()
{
    handle_->flush_cache();
}

void torrent_handle::apply_ip_filter(bool m)
{
    handle_->apply_ip_filter(m);
}

void torrent_handle::force_recheck()
{
    handle_->force_recheck();
}

void torrent_handle::save_resume_data(int flags)
{
    handle_->save_resume_data(flags);
}

bool torrent_handle::need_save_resume_data()
{
    return handle_->need_save_resume_data();
}

void torrent_handle::auto_managed(bool b)
{
    handle_->auto_managed(b);
}

void torrent_handle::queue_position_down()
{
    handle_->queue_position_down();
}

void torrent_handle::queue_position_top()
{
    handle_->queue_position_top();
}

int torrent_handle::queue_position()
{
    return handle_->queue_position();
}

void torrent_handle::queue_position_bottom()
{
    handle_->queue_position_bottom();
}

void torrent_handle::queue_position_up()
{
    handle_->queue_position_up();
}

void torrent_handle::resolve_countries(bool r)
{
    handle_->resolve_countries(r);
}

bool torrent_handle::resolve_countries()
{
    return handle_->resolve_countries();
}

torrent_info^ torrent_handle::torrent_file()
{
    if (!handle_->torrent_file())
    {
        return nullptr;
    }

    return gcnew torrent_info(*handle_->torrent_file().get());
}

int torrent_handle::piece_priority(int index)
{
    return handle_->piece_priority(index);
}

void torrent_handle::piece_priority(int index, int priority)
{
    handle_->piece_priority(index, priority);
}

int torrent_handle::file_priority(int index)
{
    return handle_->file_priority(index);
}

void torrent_handle::file_priority(int index, int priority)
{
    handle_->file_priority(index, priority);
}

void torrent_handle::force_dht_announce()
{
    handle_->force_dht_announce();
}

void torrent_handle::scrape_tracker()
{
    handle_->scrape_tracker();
}

int torrent_handle::upload_limit()
{
    return handle_->upload_limit();
}

int torrent_handle::download_limit()
{
    return handle_->download_limit();
}

void torrent_handle::set_upload_limit(int limit)
{
    handle_->set_upload_limit(limit);
}

void torrent_handle::set_download_limit(int limit)
{
    handle_->set_download_limit(limit);
}

void torrent_handle::set_sequential_download(bool m)
{
    handle_->set_sequential_download(m);
}

int torrent_handle::max_uploads()
{
    return handle_->max_uploads();
}

void torrent_handle::set_max_uploads(int max_uploads)
{
    handle_->set_max_uploads(max_uploads);
}

int torrent_handle::max_connections()
{
    return handle_->max_connections();
}

void torrent_handle::set_max_connections(int max_connections)
{
    handle_->set_max_connections(max_connections);
}

void torrent_handle::set_tracker_login(System::String^ name, System::String^ password)
{
    handle_->set_tracker_login(
        interop::to_std_string(name),
        interop::to_std_string(password));
}

void torrent_handle::move_storage(System::String^ save_path, int flags)
{
    handle_->move_storage(
        interop::to_std_string(save_path),
        flags);
}

void torrent_handle::rename_file(int index, System::String^ name)
{
    handle_->rename_file(
        index,
        interop::to_std_string(name));
}

void torrent_handle::super_seeding(bool on)
{
    handle_->super_seeding(on);
}
