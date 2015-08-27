#include "torrent_handle.h"

#include <libtorrent/peer_info.hpp>
#include <libtorrent/torrent_handle.hpp>

#include "announce_entry.h"
#include "interop.h"
#include "peer_info.h"
#include "sha1_hash.h"
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

void torrent_handle::add_piece(int piece, cli::array<System::Byte>^ data, int flags)
{
    pin_ptr<unsigned char> ptr = &data[0];
    const char *pbegin = (const char*)(const unsigned char*)ptr;
    handle_->add_piece(piece, pbegin, flags);
}

void torrent_handle::read_piece(int index)
{
    handle_->read_piece(index);
}

bool torrent_handle::have_piece(int index)
{
    return handle_->have_piece(index);
}

cli::array<peer_info^>^ torrent_handle::get_peer_info()
{
    std::vector<libtorrent::peer_info> p;
    handle_->get_peer_info(p);

    cli::array<peer_info^>^ result = gcnew cli::array<peer_info^>(p.size());

    for (size_t i = 0; i < p.size(); i++)
    {
        result[i] = gcnew peer_info(p[i]);
    }

    return result;
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

cli::array<long long>^ torrent_handle::file_progress(int flags)
{
    std::vector<libtorrent::size_type> progress;
    handle_->file_progress(progress, flags);

    cli::array<long long>^ result = gcnew cli::array<long long>(progress.size());
    for (size_t i = 0; i < progress.size(); i++)
    {
        result[i] = progress[i];
    }

    return result;
}

void torrent_handle::clear_error()
{
    handle_->clear_error();
}

cli::array<announce_entry^>^ torrent_handle::trackers()
{
    std::vector<libtorrent::announce_entry> trackers = handle_->trackers();
    cli::array<announce_entry^>^ result = gcnew cli::array<announce_entry^>(trackers.size());

    for (size_t i = 0; i < trackers.size(); i++)
    {
        result[i] = gcnew announce_entry(trackers[i]);
    }

    return result;
}

void torrent_handle::add_tracker(announce_entry^ entry)
{
    handle_->add_tracker(*entry->ptr());
}

void torrent_handle::add_url_seed(System::String^ url)
{
    handle_->add_url_seed(interop::to_std_string(url));
}

void torrent_handle::remove_url_seed(System::String^ url)
{
    handle_->remove_url_seed(interop::to_std_string(url));
}

cli::array<System::String^>^ torrent_handle::url_seeds()
{
    std::set<std::string> url_seeds = handle_->url_seeds();
    cli::array<System::String^>^ result = gcnew cli::array<System::String^>(url_seeds.size());

    for (size_t i = 0; i < url_seeds.size(); i++)
    {
        result[i] = interop::from_std_string(
            *std::next(url_seeds.begin(), i));
    }

    return result;
}

void torrent_handle::add_http_seed(System::String^ url)
{
    handle_->add_http_seed(interop::to_std_string(url));
}

void torrent_handle::remove_http_seed(System::String^ url)
{
    handle_->remove_http_seed(interop::to_std_string(url));
}

cli::array<System::String^>^ torrent_handle::http_seeds()
{
    std::set<std::string> http_seeds = handle_->http_seeds();
    cli::array<System::String^>^ result = gcnew cli::array<System::String^>(http_seeds.size());

    for (size_t i = 0; i < http_seeds.size(); i++)
    {
        result[i] = interop::from_std_string(
            *std::next(http_seeds.begin(), i));
    }

    return result;
}

void torrent_handle::set_metadata(cli::array<System::Byte>^ metadata)
{
    pin_ptr<unsigned char> ptr = &metadata[0];
    const char *pbegin = (const char*)(const unsigned char*)ptr;
    handle_->set_metadata(pbegin, metadata->Length);
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

void torrent_handle::set_ssl_certificate(System::String^ certificate, System::String^ private_key, System::String^ dh_params, System::String^ passphrase)
{
    handle_->set_ssl_certificate(
        interop::to_std_string(certificate),
        interop::to_std_string(private_key),
        interop::to_std_string(dh_params),
        interop::to_std_string(passphrase));
}

torrent_info^ torrent_handle::torrent_file()
{
    if (!handle_->torrent_file())
    {
        return nullptr;
    }

    return gcnew torrent_info(*handle_->torrent_file().get());
}

cli::array<int>^ torrent_handle::piece_availability()
{
    std::vector<int> avail;
    handle_->piece_availability(avail);

    cli::array<int>^ result = gcnew cli::array<int>(avail.size());
    for (size_t i = 0; i < avail.size(); i++)
    {
        result[i] = avail[i];
    }

    return result;
}

int torrent_handle::piece_priority(int index)
{
    return handle_->piece_priority(index);
}

void torrent_handle::piece_priority(int index, int priority)
{
    handle_->piece_priority(index, priority);
}

cli::array<int>^ torrent_handle::piece_priorities()
{
    std::vector<int> prio = handle_->piece_priorities();
    cli::array<int>^ result = gcnew cli::array<int>(prio.size());

    for (size_t i = 0; i < prio.size(); i++)
    {
        result[i] = prio[i];
    }

    return result;
}

int torrent_handle::file_priority(int index)
{
    return handle_->file_priority(index);
}

void torrent_handle::prioritize_files(cli::array<int>^ files)
{
    std::vector<int> f;
    f.reserve(files->Length);

    for (int i = 0; i < files->Length; i++)
    {
        f[i] = files[i];
    }

    handle_->prioritize_files(f);
}

void torrent_handle::file_priority(int index, int priority)
{
    handle_->file_priority(index, priority);
}

cli::array<int>^ torrent_handle::file_priorities()
{
    std::vector<int> prios = handle_->file_priorities();
    cli::array<int>^ result = gcnew cli::array<int>(prios.size());

    for (size_t i = 0; i < prios.size(); i++)
    {
        result[i] = prios[i];
    }

    return result;
}

void torrent_handle::force_reannounce(int seconds, int tracker_index)
{
    handle_->force_reannounce(seconds, tracker_index);
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

sha1_hash^ torrent_handle::info_hash()
{
    return gcnew sha1_hash(handle_->info_hash());
}
