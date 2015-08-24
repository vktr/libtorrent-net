#include "torrent_status.h"

#include <libtorrent/torrent_handle.hpp>

#include "interop.h"

using namespace lt;

torrent_status::torrent_status(libtorrent::torrent_status& status)
{
    status_ = new libtorrent::torrent_status(status);
}

torrent_status::~torrent_status()
{
    delete status_;
}

System::String^ torrent_status::error::get()
{
    return interop::from_std_string(status_->error);
}

System::String^ torrent_status::save_path::get()
{
    return interop::from_std_string(status_->save_path);
}

System::String^ torrent_status::name::get()
{
    return interop::from_std_string(status_->name);
}

System::TimeSpan torrent_status::next_announce::get()
{
    return System::TimeSpan(0, 0, status_->next_announce.total_seconds());
}

System::TimeSpan torrent_status::announce_interval::get()
{
    return System::TimeSpan(0, 0, status_->announce_interval.total_seconds());
}

System::String^ torrent_status::current_tracker::get()
{
    return interop::from_std_string(status_->current_tracker);
}

long long torrent_status::total_download::get()
{
    return status_->total_download;
}

long long torrent_status::total_upload::get()
{
    return status_->total_upload;
}

long long torrent_status::total_payload_download::get()
{
    return status_->total_payload_download;
}

long long torrent_status::total_payload_upload::get()
{
    return status_->total_payload_upload;
}

long long torrent_status::total_failed_bytes::get()
{
    return status_->total_failed_bytes;
}

long long torrent_status::total_reduntant_bytes::get()
{
    return status_->total_redundant_bytes;
}

long long torrent_status::total_done::get()
{
    return status_->total_done;
}

long long torrent_status::total_wanted_done::get()
{
    return status_->total_wanted_done;
}

long long torrent_status::total_wanted::get()
{
    return status_->total_wanted;
}

long long torrent_status::all_time_upload::get()
{
    return status_->all_time_upload;
}

long long torrent_status::all_time_download::get()
{
    return status_->all_time_download;
}

System::DateTime torrent_status::added_time::get()
{
    return System::DateTime(1970, 1, 1, 0, 0, 0, 0, System::DateTimeKind::Utc).AddSeconds(status_->added_time).ToLocalTime();
}

System::DateTime torrent_status::completed_time::get()
{
    return System::DateTime(1970, 1, 1, 0, 0, 0, 0, System::DateTimeKind::Utc).AddSeconds(status_->completed_time).ToLocalTime();
}

System::DateTime torrent_status::last_seen_complete::get()
{
    return System::DateTime(1970, 1, 1, 0, 0, 0, 0, System::DateTimeKind::Utc).AddSeconds(status_->last_seen_complete).ToLocalTime();
}

float torrent_status::progress::get()
{
    return status_->progress;
}

int torrent_status::progress_ppm::get()
{
    return status_->progress_ppm;
}

int torrent_status::queue_position::get()
{
    return status_->queue_position;
}

int torrent_status::download_rate::get()
{
    return status_->download_rate;
}

int torrent_status::upload_rate::get()
{
    return status_->upload_rate;
}

int torrent_status::download_payload_rate::get()
{
    return status_->download_payload_rate;
}

int torrent_status::upload_payload_rate::get()
{
    return status_->upload_payload_rate;
}

int torrent_status::num_seeds::get()
{
    return status_->num_seeds;
}

int torrent_status::num_peers::get()
{
    return status_->num_peers;
}

int torrent_status::num_complete::get()
{
    return status_->num_complete;
}

int torrent_status::num_incomplete::get()
{
    return status_->num_incomplete;
}

int torrent_status::list_seeds::get()
{
    return status_->list_seeds;
}

int torrent_status::list_peers::get()
{
    return status_->list_peers;
}

int torrent_status::connect_candidates::get()
{
    return status_->connect_candidates;
}

int torrent_status::num_pieces::get()
{
    return status_->num_pieces;
}

int torrent_status::distributed_full_copies::get()
{
    return status_->distributed_full_copies;
}

int torrent_status::distributed_fraction::get()
{
    return status_->distributed_fraction;
}

float torrent_status::distributed_copies::get()
{
    return status_->distributed_copies;
}

int torrent_status::block_size::get()
{
    return status_->block_size;
}

int torrent_status::num_uploads::get()
{
    return status_->num_uploads;
}

int torrent_status::num_connections::get()
{
    return status_->num_connections;
}

int torrent_status::uploads_limit::get()
{
    return status_->uploads_limit;
}

int torrent_status::connections_limit::get()
{
    return status_->connections_limit;
}

int torrent_status::up_bandwidth_queue::get()
{
    return status_->up_bandwidth_queue;
}

int torrent_status::down_bandwidth_queue::get()
{
    return status_->down_bandwidth_queue;
}

int torrent_status::time_since_upload::get()
{
    return status_->time_since_upload;
}

int torrent_status::time_since_download::get()
{
    return status_->time_since_download;
}

int torrent_status::active_time::get()
{
    return status_->active_time;
}

int torrent_status::finished_time::get()
{
    return status_->finished_time;
}

int torrent_status::seeding_time::get()
{
    return status_->seeding_time;
}

int torrent_status::seed_rank::get()
{
    return status_->seed_rank;
}

int torrent_status::last_scrape::get()
{
    return status_->last_scrape;
}

int torrent_status::sparse_regions::get()
{
    return status_->sparse_regions;
}

int torrent_status::priority::get()
{
    return status_->priority;
}

bool torrent_status::need_save_resume::get()
{
    return status_->need_save_resume;
}

bool torrent_status::ip_filter_applies::get()
{
    return status_->ip_filter_applies;
}

bool torrent_status::upload_mode::get()
{
    return status_->upload_mode;
}

bool torrent_status::share_mode::get()
{
    return status_->share_mode;
}

bool torrent_status::super_seeding::get()
{
    return status_->super_seeding;
}

bool torrent_status::paused::get()
{
    return status_->paused;
}

bool torrent_status::auto_managed::get()
{
    return status_->auto_managed;
}

bool torrent_status::sequential_download::get()
{
    return status_->sequential_download;
}

bool torrent_status::is_seeding::get()
{
    return status_->is_seeding;
}

bool torrent_status::is_finished::get()
{
    return status_->is_finished;
}

bool torrent_status::has_metadata::get()
{
    return status_->has_metadata;
}

bool torrent_status::has_incoming::get()
{
    return status_->has_incoming;
}

bool torrent_status::seed_mode::get()
{
    return status_->seed_mode;
}

bool torrent_status::moving_storage::get()
{
    return status_->moving_storage;
}
