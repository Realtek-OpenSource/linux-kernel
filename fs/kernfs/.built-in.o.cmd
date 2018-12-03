cmd_fs/kernfs/built-in.o :=  ccache arm-linux-gnueabi-ld -EL    -r -o fs/kernfs/built-in.o fs/kernfs/mount.o fs/kernfs/inode.o fs/kernfs/dir.o fs/kernfs/file.o fs/kernfs/symlink.o 
