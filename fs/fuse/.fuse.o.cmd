cmd_fs/fuse/fuse.o := ccache arm-linux-gnueabi-ld -EL    -r -o fs/fuse/fuse.o fs/fuse/dev.o fs/fuse/dir.o fs/fuse/file.o fs/fuse/inode.o fs/fuse/control.o fs/fuse/xattr.o fs/fuse/acl.o 
