#pragma once

namespace libtorrent
{
    struct torrent_handle;
}

namespace lt
{
    ref class torrent_status;

    public ref class torrent_handle
    {
    internal:
        torrent_handle(libtorrent::torrent_handle& handle);

    public:
        ~torrent_handle();
        // TODO add piece
        void read_piece(int index);
        bool have_piece(int index);
        // TODO get peer info
        torrent_status^ status();
        // TODO get download queue
        void reset_piece_deadline(int index);
        void clear_piece_deadlines();
        void set_piece_deadline(int index, int deadline); // TODO flags
        void set_priority(int priority);
        // TODO file progress
        void clear_error();
        // TODO trackers
        // TODO replace trackers
        // TODO add tracker
        // TODO add url seed
        // TODO remove url seed
        // TODO url seeds
        // TODO add http seed
        // TODO remove http seed
        // TODO http seeds
        // TODO add extensino
        // TODO set metadata
        bool is_valid();
        void pause();
        void resume();
        void set_upload_mode(bool b);
        void set_share_mode(bool b);
        void flush_cache();
        void apply_ip_filter(bool b);
        void force_recheck();
        void save_resume_data(int flags);
        bool need_save_resume_data();
        void auto_managed(bool b);
        void queue_position_down();
        void queue_position_top();
        int queue_position();
        void queue_position_bottom();
        void queue_position_up();
        void resolve_countries(bool b);
        bool resolve_countries();
        // TODO set ssl certificate
        // TODO set ssl cert buffer
        // TODO storage
        // TODO torrent file
        // TODO use interface
        // TODO piece availability
        int piece_priority(int index);
        void piece_priority(int index, int priority);
        // TODO piece priorities
        int file_priority(int index);
        // TOOD prioritize files
        void file_priority(int index, int priority);
        // TODO file priorities
        // TODO force reannounce
        void force_dht_announce();
        void scrape_tracker();
        int upload_limit();
        int download_limit();
        void set_upload_limit(int limit);
        void set_download_limit(int limit);
        void set_sequential_download(bool s);
        // TODO connect peer
        int max_uploads();
        void set_max_uploads(int max_uploads);
        int max_connections();
        void set_max_connections(int max_connections);
        void set_tracker_login(System::String^ name, System::String^ password);
        void move_storage(System::String^ save_path, int flags); // TODO flags
        void rename_file(int index, System::String^ name);
        void super_seeding(bool on);
        // TODO info hash
        // TODO compare operators

    private:
        libtorrent::torrent_handle* handle_;
    };
}
