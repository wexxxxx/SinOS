#ifndef __FS_SUPER_BLOCK_H
#define __FS_SUPER_BLOCK_H
#include <cpu/type.h>

typedef struct super_block super_block;
/* 超级块 */
struct super_block {
   uint32_t magic;		    // 用来标识文件系统类型,支持多文件系统的操作系统通过此标志来识别文件系统类型
   uint32_t sec_cnt;		    // 本分区总共的扇区数
   uint32_t inode_cnt;		    // 本分区中inode数量
   uint32_t part_lba_base;	    // 本分区的起始lba地址

   uint32_t block_bitmap_lba;	    // 空闲块位图本身起始扇区地址
   uint32_t block_bitmap_sects;     // 扇区位图本身占用的扇区数量

   uint32_t inode_bitmap_lba;	    // i结点位图起始扇区lba地址
   uint32_t inode_bitmap_sects;	    // i结点位图占用的扇区数量

   uint32_t inode_table_lba;	    // i结点表起始扇区lba地址
   uint32_t inode_table_sects;	    // i结点表占用的扇区数量
   uint32_t inodenum_per_sec;  // 每个扇区含有的inode数量

   uint32_t dir_entry_lba;  // 目录区lba地址，所有文件的索引信息都在这里
   uint32_t dir_entry_secs; // 目录区所占的扇区数量

   uint32_t data_start_lba;	    // 数据区开始的第一个扇区号
   uint8_t  pad[460];		    // 加上460字节,凑够512字节1扇区大小

} __attribute__((packed));

#endif
