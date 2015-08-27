#include "alert_types.h"

#include <libtorrent/alert_types.hpp>

#include "entry.h"
#include "error_code.h"
#include "interop.h"
#include "sha1_hash.h"
#include "torrent_handle.h"
#include "torrent_status.h"

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

peer_alert::peer_alert(libtorrent::peer_alert* a)
    : torrent_alert(a),
    alert_(a)
{
}

sha1_hash^ peer_alert::pid::get()
{
    return gcnew sha1_hash(alert_->pid);
}

tracker_alert::tracker_alert(libtorrent::tracker_alert* a)
    : torrent_alert(a),
    alert_(a)
{
}

System::String^ tracker_alert::url::get()
{
    return interop::from_std_string(alert_->url);
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

state_changed_alert::state_changed_alert(libtorrent::state_changed_alert* a)
    : torrent_alert(a),
    alert_(a)
{
}

int state_changed_alert::state::get()
{
    return alert_->state;
}

int state_changed_alert::prev_state::get()
{
    return alert_->prev_state;
}

tracker_error_alert::tracker_error_alert(libtorrent::tracker_error_alert* a)
    : tracker_alert(a),
    alert_(a)
{
}

int tracker_error_alert::times_in_row::get()
{
    return alert_->times_in_row;
}

int tracker_error_alert::status_code::get()
{
    return alert_->status_code;
}

System::String^ tracker_error_alert::msg::get()
{
    return interop::from_std_string(alert_->msg);
}

error_code^ tracker_error_alert::error::get()
{
    return gcnew error_code(alert_->error);
}

tracker_warning_alert::tracker_warning_alert(libtorrent::tracker_warning_alert* a)
    : tracker_alert(a),
    alert_(a)
{
}

System::String^ tracker_warning_alert::msg::get()
{
    return interop::from_std_string(alert_->msg);
}

scrape_reply_alert::scrape_reply_alert(libtorrent::scrape_reply_alert* a)
    : tracker_alert(a),
    alert_(a)
{
}

int scrape_reply_alert::incomplete::get()
{
    return alert_->incomplete;
}

int scrape_reply_alert::complete::get()
{
    return alert_->complete;
}

scrape_failed_alert::scrape_failed_alert(libtorrent::scrape_failed_alert* a)
    : tracker_alert(a),
    alert_(a)
{
}

System::String^ scrape_failed_alert::msg::get()
{
    return interop::from_std_string(alert_->msg);
}

tracker_reply_alert::tracker_reply_alert(libtorrent::tracker_reply_alert* a)
    : tracker_alert(a),
    alert_(a)
{
}

int tracker_reply_alert::num_peers::get()
{
    return alert_->num_peers;
}

dht_reply_alert::dht_reply_alert(libtorrent::dht_reply_alert* a)
    : tracker_alert(a),
    alert_(a)
{
}

int dht_reply_alert::num_peers::get()
{
    return alert_->num_peers;
}

tracker_announce_alert::tracker_announce_alert(libtorrent::tracker_announce_alert* a)
    : tracker_alert(a),
    alert_(a)
{
}

int tracker_announce_alert::event::get()
{
    return alert_->event;
}

hash_failed_alert::hash_failed_alert(libtorrent::hash_failed_alert* a)
    : torrent_alert(a),
    alert_(a)
{
}

int hash_failed_alert::piece_index::get()
{
    return alert_->piece_index;
}

peer_ban_alert::peer_ban_alert(libtorrent::peer_ban_alert* a)
    : peer_alert(a)
{
}

peer_unsnubbed_alert::peer_unsnubbed_alert(libtorrent::peer_unsnubbed_alert* a)
    : peer_alert(a)
{
}

peer_snubbed_alert::peer_snubbed_alert(libtorrent::peer_snubbed_alert* a)
    : peer_alert(a)
{
}

peer_error_alert::peer_error_alert(libtorrent::peer_error_alert* a)
    : peer_alert(a),
    alert_(a)
{
}

error_code^ peer_error_alert::error::get()
{
    return gcnew error_code(alert_->error);
}

peer_connect_alert::peer_connect_alert(libtorrent::peer_connect_alert* a)
    : peer_alert(a),
    alert_(a)
{
}

int peer_connect_alert::socket_type::get()
{
    return alert_->socket_type;
}

peer_disconnected_alert::peer_disconnected_alert(libtorrent::peer_disconnected_alert* a)
    : peer_alert(a),
    alert_(a)
{
}

error_code^ peer_disconnected_alert::error::get()
{
    return gcnew error_code(alert_->error);
}

invalid_request_alert::invalid_request_alert(libtorrent::invalid_request_alert* a)
    : peer_alert(a),
    alert_(a)
{
}

torrent_finished_alert::torrent_finished_alert(libtorrent::torrent_finished_alert* a)
    : torrent_alert(a)
{
}

piece_finished_alert::piece_finished_alert(libtorrent::piece_finished_alert* a)
    : torrent_alert(a),
    alert_(a)
{
}

int piece_finished_alert::piece_index::get()
{
    return alert_->piece_index;
}

request_dropped_alert::request_dropped_alert(libtorrent::request_dropped_alert* a)
    : peer_alert(a),
    alert_(a)
{
}

int request_dropped_alert::block_index::get()
{
    return alert_->block_index;
}

int request_dropped_alert::piece_index::get()
{
    return alert_->piece_index;
}

block_timeout_alert::block_timeout_alert(libtorrent::block_timeout_alert* a)
    : peer_alert(a),
    alert_(a)
{
}

int block_timeout_alert::block_index::get()
{
    return alert_->block_index;
}

int block_timeout_alert::piece_index::get()
{
    return alert_->piece_index;
}

block_finished_alert::block_finished_alert(libtorrent::block_finished_alert* a)
    : peer_alert(a),
    alert_(a)
{
}

int block_finished_alert::block_index::get()
{
    return alert_->block_index;
}

int block_finished_alert::piece_index::get()
{
    return alert_->piece_index;
}

block_downloading_alert::block_downloading_alert(libtorrent::block_downloading_alert* a)
    : peer_alert(a),
    alert_(a)
{
}

System::String^ block_downloading_alert::peer_speedmsg::get()
{
    return interop::from_std_string(alert_->peer_speedmsg);
}

int block_downloading_alert::block_index::get()
{
    return alert_->block_index;
}

int block_downloading_alert::piece_index::get()
{
    return alert_->piece_index;
}

unwanted_block_alert::unwanted_block_alert(libtorrent::unwanted_block_alert* a)
    : peer_alert(a),
    alert_(a)
{
}

int unwanted_block_alert::block_index::get()
{
    return alert_->block_index;
}

int unwanted_block_alert::piece_index::get()
{
    return alert_->piece_index;
}

storage_moved_alert::storage_moved_alert(libtorrent::storage_moved_alert* a)
    : torrent_alert(a),
    alert_(a)
{
}

System::String^ storage_moved_alert::path::get()
{
    return interop::from_std_string(alert_->path);
}

storage_moved_failed_alert::storage_moved_failed_alert(libtorrent::storage_moved_failed_alert* a)
    : torrent_alert(a),
    alert_(a)
{
}

error_code^ storage_moved_failed_alert::error::get()
{
    return gcnew error_code(alert_->error);
}

torrent_deleted_alert::torrent_deleted_alert(libtorrent::torrent_deleted_alert* a)
    : torrent_alert(a),
    alert_(a)
{
}

sha1_hash^ torrent_deleted_alert::info_hash::get()
{
    return gcnew sha1_hash(alert_->info_hash);
}

torrent_delete_failed_alert::torrent_delete_failed_alert(libtorrent::torrent_delete_failed_alert* a)
    : torrent_alert(a),
    alert_(a)
{
}

sha1_hash^ torrent_delete_failed_alert::info_hash::get()
{
    return gcnew sha1_hash(alert_->info_hash);
}

error_code^ torrent_delete_failed_alert::error::get()
{
    return gcnew error_code(alert_->error);
}

save_resume_data_alert::save_resume_data_alert(libtorrent::save_resume_data_alert* a)
    : torrent_alert(a),
    alert_(a)
{
}

entry^ save_resume_data_alert::resume_data::get()
{
    return gcnew entry(*alert_->resume_data);
}

save_resume_data_failed_alert::save_resume_data_failed_alert(libtorrent::save_resume_data_failed_alert* a)
    : torrent_alert(a),
    alert_(a)
{
}

error_code^ save_resume_data_failed_alert::error::get()
{
    return gcnew error_code(alert_->error);
}

torrent_paused_alert::torrent_paused_alert(libtorrent::torrent_paused_alert* a)
    : torrent_alert(a)
{
}

torrent_resumed_alert::torrent_resumed_alert(libtorrent::torrent_resumed_alert* a)
    : torrent_alert(a)
{
}

torrent_checked_alert::torrent_checked_alert(libtorrent::torrent_checked_alert* a)
    : torrent_alert(a)
{
}

url_seed_alert::url_seed_alert(libtorrent::url_seed_alert* a)
    : torrent_alert(a),
    alert_(a)
{
}

System::String^ url_seed_alert::url::get()
{
    return interop::from_std_string(alert_->url);
}

System::String^ url_seed_alert::msg::get()
{
    return interop::from_std_string(alert_->msg);
}

file_error_alert::file_error_alert(libtorrent::file_error_alert* a)
    : torrent_alert(a),
    alert_(a)
{
}

System::String^ file_error_alert::file::get()
{
    return interop::from_std_string(alert_->file);
}

error_code^ file_error_alert::error::get()
{
    return gcnew error_code(alert_->error);
}

metadata_failed_alert::metadata_failed_alert(libtorrent::metadata_failed_alert* a)
    : torrent_alert(a),
    alert_(a)
{
}

error_code^ metadata_failed_alert::error::get()
{
    return gcnew error_code(alert_->error);
}

metadata_received_alert::metadata_received_alert(libtorrent::metadata_received_alert* a)
    : torrent_alert(a)
{
}

udp_error_alert::udp_error_alert(libtorrent::udp_error_alert* a)
    : alert(a),
    alert_(a)
{
}

error_code^ udp_error_alert::error::get()
{
    return gcnew error_code(alert_->error);
}

external_ip_alert::external_ip_alert(libtorrent::external_ip_alert* a)
    : alert(a),
    alert_(a)
{
}

listen_failed_alert::listen_failed_alert(libtorrent::listen_failed_alert* a)
    : alert(a),
    alert_(a)
{
}

int listen_failed_alert::operation::get()
{
    return alert_->operation;
}

error_code^ listen_failed_alert::error::get()
{
    return gcnew error_code(alert_->error);
}

listen_succeeded_alert::listen_succeeded_alert(libtorrent::listen_succeeded_alert* a)
    : alert(a),
    alert_(a)
{
}

portmap_error_alert::portmap_error_alert(libtorrent::portmap_error_alert* a)
    : alert(a),
    alert_(a)
{
}

int portmap_error_alert::mapping::get()
{
    return alert_->mapping;
}

int portmap_error_alert::map_type::get()
{
    return alert_->map_type;
}

error_code^ portmap_error_alert::error::get()
{
    return gcnew error_code(alert_->error);
}

portmap_alert::portmap_alert(libtorrent::portmap_alert* a)
    : alert(a),
    alert_(a)
{
}

int portmap_alert::mapping::get()
{
    return alert_->mapping;
}

int portmap_alert::external_port::get()
{
    return alert_->external_port;
}

int portmap_alert::map_type::get()
{
    return alert_->map_type;
}

portmap_log_alert::portmap_log_alert(libtorrent::portmap_log_alert* a)
    : alert(a),
    alert_(a)
{
}

int portmap_log_alert::map_type::get()
{
    return alert_->map_type;
}

System::String^ portmap_log_alert::msg::get()
{
    return interop::from_std_string(alert_->msg);
}

fastresume_rejected_alert::fastresume_rejected_alert(libtorrent::fastresume_rejected_alert* a)
    : torrent_alert(a),
    alert_(a)
{
}

error_code^ fastresume_rejected_alert::error::get()
{
    return gcnew error_code(alert_->error);
}

peer_blocked_alert::peer_blocked_alert(libtorrent::peer_blocked_alert* a)
    : torrent_alert(a),
    alert_(a)
{
}

int peer_blocked_alert::reason::get()
{
    return alert_->reason;
}

dht_announce_alert::dht_announce_alert(libtorrent::dht_announce_alert* a)
    : alert(a),
    alert_(a)
{
}

int dht_announce_alert::port::get()
{
    return alert_->port;
}

sha1_hash^ dht_announce_alert::info_hash::get()
{
    return gcnew sha1_hash(alert_->info_hash);
}

dht_get_peers_alert::dht_get_peers_alert(libtorrent::dht_get_peers_alert* a)
    : alert(a),
    alert_(a)
{
}

sha1_hash^ dht_get_peers_alert::info_hash::get()
{
    return gcnew sha1_hash(alert_->info_hash);
}

stats_alert::stats_alert(libtorrent::stats_alert* a)
    : torrent_alert(a),
    alert_(a)
{
}

cli::array<int>^ stats_alert::transferred::get()
{
    int num_channels = libtorrent::stats_alert::stats_channel::num_channels - 1;
    cli::array<int>^ result = gcnew cli::array<int>(num_channels);

    for (int i = 0; i < num_channels; i++)
    {
        result[i] = alert_->transferred[i];
    }

    return result;
}

int stats_alert::interval::get()
{
    return alert_->interval;
}

cache_flushed_alert::cache_flushed_alert(libtorrent::cache_flushed_alert* a)
    : torrent_alert(a)
{
}

anonymous_mode_alert::anonymous_mode_alert(libtorrent::anonymous_mode_alert* a)
    : torrent_alert(a),
    alert_(a)
{
}

int anonymous_mode_alert::kind::get()
{
    return alert_->kind;
}

System::String^ anonymous_mode_alert::str::get()
{
    return interop::from_std_string(alert_->str);
}

lsd_peer_alert::lsd_peer_alert(libtorrent::lsd_peer_alert* a)
    : peer_alert(a)
{
}

trackerid_alert::trackerid_alert(libtorrent::trackerid_alert* a)
    : tracker_alert(a),
    alert_(a)
{
}

System::String^ trackerid_alert::trackerid::get()
{
    return interop::from_std_string(alert_->trackerid);
}

dht_bootstrap_alert::dht_bootstrap_alert(libtorrent::dht_bootstrap_alert* a)
    : alert(a)
{
}

torrent_error_alert::torrent_error_alert(libtorrent::torrent_error_alert* a)
    : torrent_alert(a),
    alert_(a)
{
}

error_code^ torrent_error_alert::error::get()
{
    return gcnew error_code(alert_->error);
}

torrent_need_cert_alert::torrent_need_cert_alert(libtorrent::torrent_need_cert_alert* a)
    : torrent_alert(a),
    alert_(a)
{
}

error_code^ torrent_need_cert_alert::error::get()
{
    return gcnew error_code(alert_->error);
}

incoming_connection_alert::incoming_connection_alert(libtorrent::incoming_connection_alert* a)
    : alert(a),
    alert_(a)
{
}

int incoming_connection_alert::socket_type::get()
{
    return alert_->socket_type;
}

add_torrent_alert::add_torrent_alert(libtorrent::add_torrent_alert* a)
    : torrent_alert(a),
    alert_(a)
{
}

error_code^ add_torrent_alert::error::get()
{
    return gcnew error_code(alert_->error);
}

state_update_alert::state_update_alert(libtorrent::state_update_alert* a)
    : alert(a),
    alert_(a)
{
}

cli::array<torrent_status^>^ state_update_alert::status::get()
{
    cli::array<torrent_status^>^ result = gcnew cli::array<torrent_status^>(alert_->status.size());

    for (size_t i = 0; i < alert_->status.size(); i++)
    {
        result[i] = gcnew torrent_status(alert_->status[i]);
    }

    return result;
}

torrent_update_alert::torrent_update_alert(libtorrent::torrent_update_alert* a)
    : torrent_alert(a),
    alert_(a)
{
}

sha1_hash^ torrent_update_alert::old_ih::get()
{
    return gcnew sha1_hash(alert_->old_ih);
}

sha1_hash^ torrent_update_alert::new_ih::get()
{
    return gcnew sha1_hash(alert_->new_ih);
}

dht_error_alert::dht_error_alert(libtorrent::dht_error_alert* a)
    : alert(a),
    alert_(a)
{
}

error_code^ dht_error_alert::error::get()
{
    return gcnew error_code(alert_->error);
}
