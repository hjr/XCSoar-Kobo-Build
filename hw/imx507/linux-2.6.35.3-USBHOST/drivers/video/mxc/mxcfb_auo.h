#ifndef __AUO_EPD_G2_S3C2416_H__
#define __AUO_EPD_G2_S3C2416_H__


#define I80_CMD_INIT_SET        0x0000
#define I80_CMD_STANDBY         0x0001
#define I80_CMD_WAKEUP          0x0002
#define I80_CMD_TCON_RESET      0x0003
#define I80_CMD_PARAM_MOD       0x0004
#define I80_CMD_SPI_IF_SEL      0x0005
#define I80_CMD_DMA_START       0x1001
#define I80_CMD_DATA_STOP       0x1002
#define I80_CMD_LUT_START       0x1003
#define I80_CMD_DISP_REFRESH    0x1004
#define I80_CMD_DISP_RESET      0x1005
#define I80_CMD_CURSOR_START    0x1007
#define I80_CMD_PIP_START       0x1008
#define I80_CMD_ANI_START       0x100C
#define I80_CMD_DDMA_START      0x1009
#define I80_CMD_DCURSOR_START   0x100A
#define I80_CMD_DPIP_START      0x100B
#define I80_CMD_DANI_START      0x100D
#define I80_CMD_P_DISP_START    0x100E
#define I80_CMD_P_DATA_STOP     0x100F
#define I80_CMD_DISP_INTERRUPT  0x1010
#define I80_CMD_READ_VER        0x4000
#define I80_CMD_READ_STATUS     0x4001
#define I80_CMD_DATA_READ       0x4002
#define I80_CMD_LUT_READ        0x4003
#define I80_CMD_L_BALANCE       0x5001
#define I80_CMD_AGING_MODE      0x6000
#define I80_CMD_EXIT_AGING      0x6001
#define I80_CMD_PLL_CTRL        0x7000
#define I80_CMD_NOP             0xFFFF

#define SCREEN_BUFF_TYPE_DMA 0
#define SCREEN_BUFF_TYPE_PIP 1
#define SCREEN_BUFF_TYPE_CSR 2
#define SCREEN_BUFF_TYPE_ANI 3


typedef struct tag_epd_send_img_buff_param{
  u8 dest;
  u16 x,y,w,h;
  u8 rotate;
  u8 id;
  int shm_size;//in size of byte, it should be even (each i80 is 16-bit)
  int shmid;
} SEND_IMG_BUFF_PARAM;

typedef struct tag_epd_show_img_buff_param{
  u8 dest; //0: DMA, 1: PiP, 2:CSR, 3: Animation
  u16 x, y, w, h;
  u8 epd_mode;
  u8 flip; //0: nonFlip, 1: Flip
  u8 pip_mode_or_id;
  u8 csr_iprot;
} SHOW_IMG_BUFF_PARAM;





#define	FB_IOCTL_ID							'F'
#define	FB_IOCTL_USER_CMD_OFFSET 			0x40

/*  ..  mark define on  /include/linux/mxcfb.h
// IOCTLs for E-ink panel updates 
#define MXCFB_SET_WAVEFORM_MODES			_IOW(FB_IOCTL_ID, 0x2B, struct mxcfb_waveform_modes)
#define MXCFB_SET_TEMPERATURE				_IOW(FB_IOCTL_ID, 0x2C, int32_t)
#define MXCFB_SET_AUTO_UPDATE_MODE			_IOW(FB_IOCTL_ID, 0x2D, __u32)
#define MXCFB_SEND_UPDATE					_IOW(FB_IOCTL_ID, 0x2E, struct mxcfb_update_data)
#define MXCFB_WAIT_FOR_UPDATE_COMPLETE		_IOW(FB_IOCTL_ID, 0x2F, __u32)
#define MXCFB_SET_PWRDOWN_DELAY				_IOW(FB_IOCTL_ID, 0x30, int32_t)
#define MXCFB_GET_PWRDOWN_DELAY				_IOR(FB_IOCTL_ID, 0x31, int32_t)
#define MXCFB_SET_UPDATE_SCHEME				_IOW(FB_IOCTL_ID, 0x32, __u32)
*/

// IOCTLs for AUO panel updates 
#define	IOCTL_CMD_SEND_IMG_BUFF 			_IOW( FB_IOCTL_ID, FB_IOCTL_USER_CMD_OFFSET + 0 , SEND_IMG_BUFF_PARAM * )
#define	IOCTL_CMD_SHOW_IMG_BUFF 			_IOW( FB_IOCTL_ID, FB_IOCTL_USER_CMD_OFFSET + 1 , SHOW_IMG_BUFF_PARAM * )
#define	IOCTL_CMD_SEND_IMG_FB 				_IOW( FB_IOCTL_ID, FB_IOCTL_USER_CMD_OFFSET + 2 , SEND_IMG_BUFF_PARAM * )
#define	IOCTL_CMD_SHOW_IMG_FB 				_IOW( FB_IOCTL_ID, FB_IOCTL_USER_CMD_OFFSET + 3 , SHOW_IMG_BUFF_PARAM * )
#define	IOCTL_CMD_TCON_RESET            	_IOW( FB_IOCTL_ID, FB_IOCTL_USER_CMD_OFFSET + 4 , unsigned int )
#define	IOCTL_CMD_DISP_RESET        		_IOW( FB_IOCTL_ID, FB_IOCTL_USER_CMD_OFFSET + 5 , unsigned int )
#define	IOCTL_CMD_DISP_REFRESH      		_IOW( FB_IOCTL_ID, FB_IOCTL_USER_CMD_OFFSET + 6 , unsigned int)
#define	IOCTL_CMD_PARAM_SET     			_IOR( FB_IOCTL_ID, FB_IOCTL_USER_CMD_OFFSET + 7 , u16)
#define	IOCTL_CMD_SEND_COMMAND				_IOW( FB_IOCTL_ID, FB_IOCTL_USER_CMD_OFFSET + 8 , unsigned int )
#define	IOCTL_CMD_SEND_DATA					_IOW( FB_IOCTL_ID, FB_IOCTL_USER_CMD_OFFSET + 9 , unsigned int )
#define	IOCTL_CMD_SET_REFRESH_MODE			_IOW( FB_IOCTL_ID, FB_IOCTL_USER_CMD_OFFSET + 10 , unsigned int )
#define	IOCTL_CMD_SET_ROTATION_ANGLE		_IOW( FB_IOCTL_ID, FB_IOCTL_USER_CMD_OFFSET + 11 , unsigned int )
#define IOCTL_CMD_PENDNG_FB_DISPLAY			_IO(FB_IOCTL_ID, FB_IOCTL_USER_CMD_OFFSET + 12)
#define IOCTL_CMD_RESUME_FB_DISPLAY			_IO(FB_IOCTL_ID, FB_IOCTL_USER_CMD_OFFSET + 13)
#define IOCTL_CMD_READ_DATA			        _IOR(FB_IOCTL_ID, FB_IOCTL_USER_CMD_OFFSET + 14, u16)
#define IOCTL_CMD_DISABLE_AUTO_FLASH		_IO(FB_IOCTL_ID, FB_IOCTL_USER_CMD_OFFSET + 16)
#define IOCTL_CMD_ENABLE_AUTO_FLASH			_IO(FB_IOCTL_ID, FB_IOCTL_USER_CMD_OFFSET + 17)
#define IOCTL_CMD_SET_AUTO_FLASH_TIMES		_IOW(FB_IOCTL_ID, FB_IOCTL_USER_CMD_OFFSET + 18, unsigned int)
#define IOCTL_CMD_WRITE_G2_LUT              _IOW(FB_IOCTL_ID, FB_IOCTL_USER_CMD_OFFSET + 19, unsigned int)
#define IOCTL_CMD_READ_G2_LUT               _IOW(FB_IOCTL_ID, FB_IOCTL_USER_CMD_OFFSET + 20, unsigned int)
#define IOCTL_CMD_CHECKBUSY                 _IOR(FB_IOCTL_ID, FB_IOCTL_USER_CMD_OFFSET + 21, u16)

#define IOCTL_CMD_READ_EPD_MODE				_IOR(FB_IOCTL_ID, FB_IOCTL_USER_CMD_OFFSET + 22, u16)

#define IOCTL_CMD_AUTO_FLASH_NOW			_IO(FB_IOCTL_ID, FB_IOCTL_USER_CMD_OFFSET + 23)
#define IOCTL_CMD_READ_ROTATION_ANGLE		_IOR(FB_IOCTL_ID, FB_IOCTL_USER_CMD_OFFSET + 24, u16)
#define IOCTL_CMD_PULL_SLP_RST_DOWN			_IO(FB_IOCTL_ID, FB_IOCTL_USER_CMD_OFFSET + 25)
#define IOCTL_CMD_PULL_SLP_RST_UP			_IO(FB_IOCTL_ID, FB_IOCTL_USER_CMD_OFFSET + 26)
#define IOCTL_CMD_SET_PULL_DOWN_TIME		_IOW(FB_IOCTL_ID, FB_IOCTL_USER_CMD_OFFSET + 27, unsigned int)

#define IOCTL_CMD_POWER_ON					_IO(FB_IOCTL_ID, FB_IOCTL_USER_CMD_OFFSET + 28)
#define IOCTL_CMD_POWER_OFF					_IO(FB_IOCTL_ID, FB_IOCTL_USER_CMD_OFFSET + 29)

#define IOCTL_CMD_PRE_DISP_BUFF				_IOW( FB_IOCTL_ID, FB_IOCTL_USER_CMD_OFFSET + 30 , SEND_IMG_BUFF_PARAM * )

// IOCTLs for special ioctl 
#define	IOCTL_CMD_FB_AUTO_REFRESH			_IOW( FB_IOCTL_ID, FB_IOCTL_USER_CMD_OFFSET + 31 , unsigned int )
#define	IOCTL_CMD_SHOW_FB_IMG_BUFF			_IOW( FB_IOCTL_ID, FB_IOCTL_USER_CMD_OFFSET + 32 , unsigned int )

#endif

