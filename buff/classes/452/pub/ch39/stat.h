// trimmed /usr/include/bits/stat.h

struct stat {
  __dev_t st_dev;          // Device.
  __ino_t st_ino;          // File serial number.
  __nlink_t st_nlink;      // Link count.
  __mode_t st_mode;        // File mode.
  __uid_t st_uid;          // User ID of the file's owner.
  __gid_t st_gid;          // Group ID of the file's group.
  __dev_t st_rdev;         // Device number, if device.
  __off_t st_size;         // Size of file, in bytes.
  __blksize_t st_blksize;  // Optimal block size for I/O.
  __blkcnt_t st_blocks;    // Number 512-byte blocks allocated.
  struct timespec st_atim; // Time of last access.
  struct timespec st_mtim; // Time of last modification.
  struct timespec st_ctim; // Time of last status change.
};
