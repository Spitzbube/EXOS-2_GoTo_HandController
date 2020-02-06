//
//  $Id: ff.h 42 2008-10-04 18:40:36Z jcw $
//  $Revision: 42 $
//  $Author: jcw $
//  $Date: 2008-10-04 14:40:36 -0400 (Sat, 04 Oct 2008) $
//  $HeadURL: http://tinymicros.com/svn_public/arm/lpc2148_demo/trunk/fatfs/ff.h $
//

/*--------------------------------------------------------------------------/
/  FatFs - FAT file system module include file  R0.04b       (C)ChaN, 2007
/---------------------------------------------------------------------------/
/ FatFs module is an experimenal project to implement FAT file system to
/ cheap microcontrollers. This is a free software and is opened for education,
/ research and development under license policy of following trems.
/
/  Copyright (C) 2007, ChaN, all right reserved.
/
/ * The FatFs module is a free software and there is no warranty.
/ * You can use, modify and/or redistribute it for personal, non-profit or
/   profit use without any restriction under your responsibility.
/ * Redistributions of source code must retain the above copyright notice.
/
/---------------------------------------------------------------------------*/

#ifndef _FATFS_H_
#define _FATFS_H_

#define _MCU_ENDIAN 2
/* The _MCU_ENDIAN defines which access method is used to the FAT structure.
/  1: Enable word access.
/  2: Disable word access and use byte-by-byte access instead.
/  When the architectural byte order of the MCU is big-endian and/or address
/  miss-aligned access is prohibited, the _MCU_ENDIAN must be set to 2.
/  If it is not the case, it can be set to 1 for good code efficiency. */

#define _FS_READONLY    0
/* Setting _FS_READONLY to 1 defines read only configuration. This removes
/  writing functions, f_write, f_sync, f_unlink, f_mkdir, f_chmod, f_rename
/  and useless f_getfree. */

#define _FS_MINIMIZE    0
/* The _FS_MINIMIZE option defines minimization level to remove some functions.
/  0: Full function.
/  1: f_stat, f_getfree, f_unlink, f_mkdir, f_chmod and f_rename are removed.
/  2: f_opendir and f_readdir are removed in addition to level 1.
/  3: f_lseek is removed in addition to level 2. */

#define _DRIVES     1
/* Number of logical drives to be used. This affects the size of internal table. */

#define _USE_MKFS   1
/* When _USE_MKFS is set to 1 and _FS_READONLY is set to 0, f_mkfs function is
/  enabled. */

#define _MULTI_PARTITION    0
/* When _MULTI_PARTITION is set to 0, each logical drive is bound to same
/  physical drive number and can mount only 1st primaly partition. When it is
/  set to 1, each logical drive can mount a partition listed in Drives[]. */

#define _USE_FSINFO 1
/* To enable FSInfo support on FAT32 volume, set _USE_FSINFO to 1. */

#define _USE_SJIS   1
/* When _USE_SJIS is set to 1, Shift-JIS code transparency is enabled, otherwise
/  only US-ASCII(7bit) code can be accepted as file/directory name. */

#define _USE_NTFLAG 1
/* When _USE_NTFLAG is set to 1, upper/lower case of the file name is preserved.
/  Note that the files are always accessed in case insensitive. */

#include "sysdefs.h"

//
//  Definitions corresponds to multiple sector size (not tested) 
//
#define S_MAX_SIZ   512         /* Do not change */
#if S_MAX_SIZ > 512
#define S_SIZ   (fs->s_size)
#else
#define S_SIZ   512
#endif

//
//  File system object structure 
//
typedef struct _FATFS
{
    U16 id;             /* File system mount ID */
    U16 n_rootdir;      /* Number of root directory entries */
    U32 winsect;        /* Current sector appearing in the win[] */
    U32 sects_fat;      /* Sectors per fat */
    U32 max_clust;      /* Maximum cluster# + 1 */
    U32 fatbase;        /* FAT start sector */
    U32 dirbase;        /* Root directory start sector (cluster# for FAT32) */
    U32 database;       /* Data start sector */
#if _FS_READONLY == 0
    U32 last_clust;     /* Last allocated cluster */
    U32 free_clust;     /* Number of free clusters */
#if _USE_FSINFO
    U32 fsi_sector;     /* fsinfo sector */
    U8  fsi_flag;       /* fsinfo dirty flag (1:must be written back) */
    U8  pad2;
#endif
#endif
    U8  fs_type;        /* FAT sub type */
    U8  sects_clust;    /* Sectors per cluster */
#if S_MAX_SIZ > 512
    U32 s_size;         /* Sector size */
#endif
    U8  n_fats;         /* Number of FAT copies */
    U8  drive;          /* Physical drive number */
    U8  winflag;        /* win[] dirty flag (1:must be written back) */
    U8  pad1;
    U8  win[S_MAX_SIZ]; /* Disk access window for Directory/FAT */
} 
/* __attribute__ ((packed)) */ FATFS;

//
//  Directory object structure 
//
typedef struct _DIR 
{
    U16 id;         /* Owner file system mount ID */
    U16 index;      /* Current index */
    FATFS*  fs;     /* Pointer to the owner file system object */
    U32 sclust;     /* Start cluster */
    U32 clust;      /* Current cluster */
    U32 sect;       /* Current sector */
} 
/* __attribute__ ((packed)) */ DIR;

//
//  File object structure 
//
typedef struct _FIL 
{
    U16 id;             /* Owner file system mount ID */
    U8  flag;           /* File status flags */
    U8  sect_clust;     /* Left sectors in cluster */
    FATFS* fs;          /* Pointer to the owner file system object */
    U32 fptr;           /* File R/W pointer */
    U32 fsize;          /* File size */
    U32 org_clust;      /* File start cluster */
    U32 curr_clust;     /* Current cluster */
    U32 curr_sect;      /* Current sector */
#if _FS_READONLY == 0
    U32 dir_sect;       /* Sector containing the directory entry */
    U8* dir_ptr;        /* Ponter to the directory entry in the window */
#endif
    U8  buffer [S_MAX_SIZ];  /* File R/W buffer */
} 
/* __attribute__ ((packed)) */ FIL;

//
//  File status structure 
//
typedef struct _FILINFO 
{
    U32 fsize;              /* Size */
    U16 fdate;              /* Date */
    U16 ftime;              /* Time */
    U8 fattrib;             /* Attribute */
    char fname [8+1+3+1];   /* Name (8.3 format) */
} 
/* __attribute__ ((packed)) */ FILINFO;

//
//  Definitions corresponds to multi partition 
//
#if _MULTI_PARTITION != 0   /* Multiple partition cfg */

typedef struct _PARTITION 
{
    U8 pd;  /* Physical drive # (0-255) */
    U8 pt;  /* Partition # (0-3) */
} 
/* __attribute__ ((packed)) */ PARTITION;

extern const PARTITION Drives [];   /* Logical drive# to physical location conversion table */
#define LD2PD(drv) (Drives[drv].pd) /* Get physical drive# */
#define LD2PT(drv) (Drives[drv].pt) /* Get partition# */

#else                       /* Single partition cfg */

#define LD2PD(drv) (drv)        /* Physical drive# is equal to logical drive# */
#define LD2PT(drv) 0            /* Always mounts the 1st partition */

#endif

#include "disk.h"

//
//  File function return code (FRESULT) 
//
typedef enum 
{
    FR_OK = 0,          /* 0 */
    FR_NOT_READY,       /* 1 */
    FR_NO_FILE,         /* 2 */
    FR_NO_PATH,         /* 3 */
    FR_INVALID_NAME,    /* 4 */
    FR_INVALID_DRIVE,   /* 5 */
    FR_DENIED,          /* 6 */
    FR_EXIST,           /* 7 */
    FR_RW_ERROR,        /* 8 */
    FR_WRITE_PROTECTED, /* 9 */
    FR_NOT_ENABLED,     /* 10 */
    FR_NO_FILESYSTEM,   /* 11 */
    FR_INVALID_OBJECT,  /* 12 */
    FR_MKFS_ABORTED     /* 13 */
} 
FRESULT;

//
//  FatFs module application interface
//
const char *f_ferrorlookup (FRESULT d);
void    f_printerror (FRESULT d);              /* Print DRESULT error code */
FRESULT f_mount (U8, FATFS*);                   /* Mount/Unmount a logical drive */
FRESULT f_open (FIL*, const char*, U8);         /* Open or create a file */
FRESULT f_read (FIL*, void*, U16, U16*);        /* Read data from a file */
FRESULT f_write (FIL*, const void*, U16, U16*); /* Write data to a file */
FRESULT f_lseek (FIL*, U32);                    /* Move file pointer of a file object */
FRESULT f_close (FIL*);                         /* Close an open file object */
FRESULT f_opendir (DIR*, const char*);          /* Open an existing directory */
FRESULT f_readdir (DIR*, FILINFO*);             /* Read a directory item */
FRESULT f_stat (const char*, FILINFO*);         /* Get file status */
FRESULT f_getfree (const char*, U32*, FATFS**); /* Get number of free clusters on the drive */
FRESULT f_sync (FIL*);                          /* Flush cached data of a writing file */
FRESULT f_unlink (const char*);                 /* Delete an existing file or directory */
FRESULT f_mkdir (const char*);                  /* Create a new directory */
FRESULT f_chmod (const char*, U8, U8);          /* Change file/dir attriburte */
FRESULT f_rename (const char*, const char*);    /* Rename/Move a file or directory */
FRESULT f_mkfs (U8, U8, U8);                    /* Create a file system on the drive */

//
//  User defined function to give a current time to fatfs module 
//
U32 get_fattime (void); /* 31-25: Year(0-127 org.1980), 24-21: Month(1-12), 20-16: Day(1-31) */
                        /* 15-11: Hour(0-23), 10-5: Minute(0-59), 4-0: Second(0-29 *2) */

//
//  File access control and file status flags (FIL.flag)
//
#define FA_OPEN_EXISTING    0x00
#define FA_READ             0x01
#if _FS_READONLY == 0
#define FA_WRITE            0x02
#define FA_CREATE_NEW       0x04
#define FA_CREATE_ALWAYS    0x08
#define FA_OPEN_ALWAYS      0x10
#define FA__WRITTEN         0x20
#define FA__DIRTY           0x40
#endif
#define FA__ERROR           0x80

//
//  FAT sub type (FATFS.fs_type) 
//
#define FS_FAT12    1
#define FS_FAT16    2
#define FS_FAT32    3

//
//  File attribute bits for directory entry 
//
#define AM_RDO  0x01    /* Read only */
#define AM_HID  0x02    /* Hidden */
#define AM_SYS  0x04    /* System */
#define AM_VOL  0x08    /* Volume label */
#define AM_LFN  0x0F    /* LFN entry */
#define AM_DIR  0x10    /* Directory */
#define AM_ARC  0x20    /* Archive */

//
//  Offset of FAT structure members 
//
#define BS_jmpBoot          0
#define BS_OEMName          3
#define BPB_BytsPerSec      11
#define BPB_SecPerClus      13
#define BPB_RsvdSecCnt      14
#define BPB_NumFATs         16
#define BPB_RootEntCnt      17
#define BPB_TotSec16        19
#define BPB_Media           21
#define BPB_FATSz16         22
#define BPB_SecPerTrk       24
#define BPB_NumHeads        26
#define BPB_HiddSec         28
#define BPB_TotSec32        32
#define BS_55AA             510

#define BS_DrvNum           36
#define BS_BootSig          38
#define BS_VolID            39
#define BS_VolLab           43
#define BS_FilSysType       54

#define BPB_FATSz32         36
#define BPB_ExtFlags        40
#define BPB_FSVer           42
#define BPB_RootClus        44
#define BPB_FSInfo          48
#define BPB_BkBootSec       50
#define BS_DrvNum32         64
#define BS_BootSig32        66
#define BS_VolID32          67
#define BS_VolLab32         71
#define BS_FilSysType32     82

#define FSI_LeadSig         0
#define FSI_StrucSig        484
#define FSI_Free_Count      488
#define FSI_Nxt_Free        492

#define MBR_Table           446

#define DIR_Name            0
#define DIR_Attr            11
#define DIR_NTres           12
#define DIR_CrtTime         14
#define DIR_CrtDate         16
#define DIR_FstClusHI       20
#define DIR_WrtTime         22
#define DIR_WrtDate         24
#define DIR_FstClusLO       26
#define DIR_FileSize        28

//
//  Multi-byte word access macros  
//  
#if _MCU_ENDIAN == 1    /* Use word access */
#define LD_U16(ptr)     (U16)(*(U16*)(U8*)(ptr))
#define LD_U32(ptr)     (U32)(*(U32*)(U8*)(ptr))
#define ST_U16(ptr,val) *(U16*)(U8*)(ptr)=(U16)(val)
#define ST_U32(ptr,val) *(U32*)(U8*)(ptr)=(U32)(val)
#else
#if _MCU_ENDIAN == 2    /* Use byte-by-byte access */
#define LD_U16(ptr)     (U16)(((U16)*(U8*)((ptr)+1)<<8)|(U16)*(U8*)(ptr))
#define LD_U32(ptr)     (U32)(((U32)*(U8*)((ptr)+3)<<24)|((U32)*(U8*)((ptr)+2)<<16)|((U16)*(U8*)((ptr)+1)<<8)|*(U8*)(ptr))
#define ST_U16(ptr,val) *(U8*)(ptr)=(U8)(val); *(U8*)((ptr)+1)=(U8)((U16)(val)>>8)
#define ST_U32(ptr,val) *(U8*)(ptr)=(U8)(val); *(U8*)((ptr)+1)=(U8)((U16)(val)>>8); *(U8*)((ptr)+2)=(U8)((U32)(val)>>16); *(U8*)((ptr)+3)=(U8)((U32)(val)>>24)
#else
#error Do not forget to set _MCU_ENDIAN properly!
#endif
#endif

#endif
