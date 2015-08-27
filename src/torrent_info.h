#pragma once

namespace libtorrent
{
    class torrent_info;
}

namespace lt
{
    ref class announce_entry;
    ref class sha1_hash;

    public ref class torrent_info
    {
    public:
        torrent_info(cli::array<System::Byte>^ buffer);
        torrent_info(System::String^ fileName);

        ~torrent_info();

        // TODO files
        // TODO orig_files
        void rename_file(int index, System::String^ new_filename);
        // TODO remap files
        cli::array<announce_entry^>^ trackers();
        void add_tracker(System::String^ url, int tier);
        // TODO add url seed
        // TODO web seeds
        // TODO add http seed
        int num_pieces();
        long long total_size();
        int piece_length();
        sha1_hash^ info_hash();
        int num_files();
        // TODO file_at
        // TODO map block
        System::String^ ssl_cert();
        bool is_valid();
        bool priv();
        bool is_i2p();
        // TODO hash for piece
        int piece_size(int index);
        // TODO merkle tree
        // TODO set merkle tree
        System::Nullable<System::DateTime>^ creation_date();
        System::String^ name();
        System::String^ comment();
        System::String^ creator();
        // TODO nodes
        // TODO add node
        // TODO parse info section
        // TODO info
        int metadata_size();
        cli::array<System::Byte>^ metadata();
        bool is_merkle_torrent();

    internal:
        torrent_info(const libtorrent::torrent_info& info);

        libtorrent::torrent_info* ptr();

    private:
        libtorrent::torrent_info* info_;
    };
}
