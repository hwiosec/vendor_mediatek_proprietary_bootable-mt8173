#ifndef _SPM_
#define _SPM_

//#include <platform.h>
//#include <sync_write.h>
#include <platform/mt_reg_base.h>
#include <platform/mt_typedefs.h>

#define SPM_BASE SLEEP_BASE
/**************************************
 * Define and Declare
 **************************************/
#define SPM_POWERON_CONFIG_SET      (SPM_BASE + 0x000)
#define SPM_POWER_ON_VAL0       (SPM_BASE + 0x010)
#define SPM_POWER_ON_VAL1       (SPM_BASE + 0x014)
#define SPM_CLK_SETTLE          (SPM_BASE + 0x100)
#define SPM_CA7_CPU0_PWR_CON        (SPM_BASE + 0x200)
#define SPM_CA7_DBG_PWR_CON     (SPM_BASE + 0x204)
#define SPM_CA7_CPUTOP_PWR_CON      (SPM_BASE + 0x208)
#define SPM_VDE_PWR_CON         (SPM_BASE + 0x210)
#define SPM_MFG_PWR_CON         (SPM_BASE + 0x214)
#define SPM_CA7_CPU1_PWR_CON        (SPM_BASE + 0x218)
#define SPM_CA7_CPU2_PWR_CON        (SPM_BASE + 0x21c)
#define SPM_CA7_CPU3_PWR_CON        (SPM_BASE + 0x220)
#define SPM_VEN_PWR_CON         (SPM_BASE + 0x230)
#define SPM_IFR_PWR_CON         (SPM_BASE + 0x234)
#define SPM_ISP_PWR_CON         (SPM_BASE + 0x238)
#define SPM_DIS_PWR_CON         (SPM_BASE + 0x23c)
#define SPM_DPY_PWR_CON         (SPM_BASE + 0x240)
#define SPM_CA7_CPUTOP_L2_PDN       (SPM_BASE + 0x244)
#define SPM_CA7_CPUTOP_L2_SLEEP     (SPM_BASE + 0x248)
#define SPM_CA7_CPU0_L1_PDN     (SPM_BASE + 0x25c)
#define SPM_CA7_CPU1_L1_PDN     (SPM_BASE + 0x264)
#define SPM_CA7_CPU2_L1_PDN     (SPM_BASE + 0x26c)
#define SPM_CA7_CPU3_L1_PDN     (SPM_BASE + 0x274)
#define SPM_GCPU_SRAM_CON       (SPM_BASE + 0x27c)
#define SPM_CONN_PWR_CON        (SPM_BASE + 0x280)
#define SPM_MD_PWR_CON          (SPM_BASE + 0x284)
#define SPM_MCU_PWR_CON         (SPM_BASE + 0x290)
#define SPM_IFR_SRAMROM_CON     (SPM_BASE + 0x294)
#define SPM_MJC_PWR_CON         (SPM_BASE + 0x298)
#define SPM_AUDIO_PWR_CON       (SPM_BASE + 0x29c)
#define SPM_CA15_CPU0_PWR_CON       (SPM_BASE + 0x2a0)
#define SPM_CA15_CPU1_PWR_CON       (SPM_BASE + 0x2a4)
#define SPM_CA15_CPU2_PWR_CON       (SPM_BASE + 0x2a8)
#define SPM_CA15_CPU3_PWR_CON       (SPM_BASE + 0x2ac)
#define SPM_CA15_CPUTOP_PWR_CON     (SPM_BASE + 0x2b0)
#define SPM_CA15_L1_PWR_CON     (SPM_BASE + 0x2b4)
#define SPM_CA15_L2_PWR_CON     (SPM_BASE + 0x2b8)
#define SPM_MFG_2D_PWR_CON      (SPM_BASE + 0x2c0)
#define SPM_MFG_ASYNC_PWR_CON       (SPM_BASE + 0x2c4)
#define SPM_MD32_SRAM_CON       (SPM_BASE + 0x2c8)
#define SPM_ARMPLL_DIV_PWR_CON  (SPM_BASE + 0x2cc)
#define SPM_MD2_PWR_CON         (SPM_BASE + 0x2d0)
#define SPM_C2K_PWR_CON         (SPM_BASE + 0x2d4)//mt6735  
#define SPM_INFRA_MD_PWR_CON    (SPM_BASE + 0x2d8)//mt6735 
#define SPM_CPU_EXT_ISO         (SPM_BASE + 0x2dc)//mt6735
#define SPM_PCM_CON0            (SPM_BASE + 0x310)
#define SPM_PCM_CON1            (SPM_BASE + 0x314)
#define SPM_PCM_IM_PTR          (SPM_BASE + 0x318)
#define SPM_PCM_IM_LEN          (SPM_BASE + 0x31c)
#define SPM_PCM_REG_DATA_INI        (SPM_BASE + 0x320)
#define SPM_PCM_EVENT_VECTOR0       (SPM_BASE + 0x340)
#define SPM_PCM_EVENT_VECTOR1       (SPM_BASE + 0x344)
#define SPM_PCM_EVENT_VECTOR2       (SPM_BASE + 0x348)
#define SPM_PCM_EVENT_VECTOR3       (SPM_BASE + 0x34c)
#define SPM_PCM_MAS_PAUSE_MASK      (SPM_BASE + 0x354)
#define SPM_PCM_PWR_IO_EN       (SPM_BASE + 0x358)
#define SPM_PCM_TIMER_VAL       (SPM_BASE + 0x35c)
#define SPM_PCM_TIMER_OUT       (SPM_BASE + 0x360)
#define SPM_PCM_REG0_DATA       (SPM_BASE + 0x380)
#define SPM_PCM_REG1_DATA       (SPM_BASE + 0x384)
#define SPM_PCM_REG2_DATA       (SPM_BASE + 0x388)
#define SPM_PCM_REG3_DATA       (SPM_BASE + 0x38c)
#define SPM_PCM_REG4_DATA       (SPM_BASE + 0x390)
#define SPM_PCM_REG5_DATA       (SPM_BASE + 0x394)
#define SPM_PCM_REG6_DATA       (SPM_BASE + 0x398)
#define SPM_PCM_REG7_DATA       (SPM_BASE + 0x39c)
#define SPM_PCM_REG8_DATA       (SPM_BASE + 0x3a0)
#define SPM_PCM_REG9_DATA       (SPM_BASE + 0x3a4)
#define SPM_PCM_REG10_DATA      (SPM_BASE + 0x3a8)
#define SPM_PCM_REG11_DATA      (SPM_BASE + 0x3ac)
#define SPM_PCM_REG12_DATA      (SPM_BASE + 0x3b0)
#define SPM_PCM_REG13_DATA      (SPM_BASE + 0x3b4)
#define SPM_PCM_REG14_DATA      (SPM_BASE + 0x3b8)
#define SPM_PCM_REG15_DATA      (SPM_BASE + 0x3bc)
#define SPM_PCM_EVENT_REG_STA       (SPM_BASE + 0x3c0)
#define SPM_PCM_FSM_STA         (SPM_BASE + 0x3c4)
#define SPM_PCM_IM_HOST_RW_PTR      (SPM_BASE + 0x3c8)
#define SPM_PCM_IM_HOST_RW_DAT      (SPM_BASE + 0x3cc)
#define SPM_PCM_EVENT_VECTOR4       (SPM_BASE + 0x3d0)
#define SPM_PCM_EVENT_VECTOR5       (SPM_BASE + 0x3d4)
#define SPM_PCM_EVENT_VECTOR6       (SPM_BASE + 0x3d8)
#define SPM_PCM_EVENT_VECTOR7       (SPM_BASE + 0x3dc)
#define SPM_PCM_SW_INT_SET      (SPM_BASE + 0x3e0)
#define SPM_PCM_SW_INT_CLEAR        (SPM_BASE + 0x3e4)
#define SPM_CLK_CON         (SPM_BASE + 0x400)
#define SPM_SLEEP_DUAL_VCORE_PWR_CON    (SPM_BASE + 0x404)
#define SPM_SLEEP_PTPOD2_CON        (SPM_BASE + 0x408)
#define SPM_APMCU_PWRCTL        (SPM_BASE + 0x600)
#define SPM_AP_DVFS_CON_SET     (SPM_BASE + 0x604)
#define SPM_AP_STANBY_CON       (SPM_BASE + 0x608)
#define SPM_PWR_STATUS          (SPM_BASE + 0x60c)
#define SPM_PWR_STATUS_2ND      (SPM_BASE + 0x610)
//#define SPM_AP_BSI_REQ            (SPM_BASE + 0x614)
#define SPM_SLEEP_MDBSI_CON     (SPM_BASE + 0x614)//mt6735 
#define SPM_BSI_GEN             (SPM_BASE + 0x620)//mt6735
#define SPM_BSI_EN_SR             (SPM_BASE + 0x624)//mt6735
#define SPM_BSI_CLK_SR          (SPM_BASE + 0x628)//mt6735
#define SPM_BSI_DO_SR             (SPM_BASE + 0x62c)//mt6735
#define SPM_BSI_D1_SR             (SPM_BASE + 0x630)//mt6735
#define SPM_BSI_D2_SR             (SPM_BASE + 0x634)//mt6735
#define SPM_AP_SEMA             (SPM_BASE + 0x638)//mt6735
#define SPM_SPM_SEMA              (SPM_BASE + 0x63c)//mt6735                    
#define SPM_SLEEP_TIMER_STA     (SPM_BASE + 0x720)
#define SPM_SLEEP_TWAM_CON      (SPM_BASE + 0x760)
#define SPM_SLEEP_TWAM_STATUS0      (SPM_BASE + 0x764)
#define SPM_SLEEP_TWAM_STATUS1      (SPM_BASE + 0x768)
#define SPM_SLEEP_TWAM_STATUS2      (SPM_BASE + 0x76c)
#define SPM_SLEEP_TWAM_STATUS3      (SPM_BASE + 0x770)
#define SPM_SLEEP_TWAM_CURR_STATUS0 (SPM_BASE + 0x774)
#define SPM_SLEEP_TWAM_CURR_STATUS1 (SPM_BASE + 0x778)
#define SPM_SLEEP_TWAM_CURR_STATUS2 (SPM_BASE + 0x77C)
#define SPM_SLEEP_TWAM_CURR_STATUS3 (SPM_BASE + 0x780)
#define SPM_SLEEP_TWAM_TIMER_OUT    (SPM_BASE + 0x784)
#define SPM_SLEEP_TWAM_WINDOW_LEN   (SPM_BASE + 0x788)
#define SPM_SLEEP_IDLE_SEL          (SPM_BASE + 0x78C)
#define SPM_SLEEP_WAKEUP_EVENT_MASK (SPM_BASE + 0x810)
#define SPM_SLEEP_CPU_WAKEUP_EVENT  (SPM_BASE + 0x814)
#define SPM_SLEEP_MD32_WAKEUP_EVENT_MASK    (SPM_BASE + 0x818)
#define SPM_PCM_WDT_TIMER_VAL       (SPM_BASE + 0x824)
#define SPM_PCM_WDT_TIMER_OUT       (SPM_BASE + 0x828)
#define SPM_PCM_MD32_MAILBOX        (SPM_BASE + 0x830)
#define SPM_PCM_MD32_IRQ        (SPM_BASE + 0x834)
#define SPM_SLEEP_ISR_MASK      (SPM_BASE + 0x900)
#define SPM_SLEEP_ISR_STATUS        (SPM_BASE + 0x904)
#define SPM_SLEEP_ISR_RAW_STA       (SPM_BASE + 0x910)
#define SPM_SLEEP_MD32_ISR_RAW_STA  (SPM_BASE + 0x914)
#define SPM_SLEEP_WAKEUP_MISC       (SPM_BASE + 0x918)
#define SPM_SLEEP_BUS_PROTECT_RDY   (SPM_BASE + 0x91c)
#define SPM_SLEEP_SUBSYS_IDLE_STA   (SPM_BASE + 0x920)
#define SPM_PCM_RESERVE         (SPM_BASE + 0xb00)
#define SPM_PCM_RESERVE2        (SPM_BASE + 0xb04)
#define SPM_PCM_FLAGS           (SPM_BASE + 0xb08)
#define SPM_PCM_SRC_REQ         (SPM_BASE + 0xb0c)
#define SPM_PCM_DEBUG_CON       (SPM_BASE + 0xb20)
#define SPM_CA7_CPU0_IRQ_MASK       (SPM_BASE + 0xb30)
#define SPM_CA7_CPU1_IRQ_MASK       (SPM_BASE + 0xb34)
#define SPM_CA7_CPU2_IRQ_MASK       (SPM_BASE + 0xb38)
#define SPM_CA7_CPU3_IRQ_MASK       (SPM_BASE + 0xb3c)
#define SPM_CA15_CPU0_IRQ_MASK      (SPM_BASE + 0xb40)
#define SPM_CA15_CPU1_IRQ_MASK      (SPM_BASE + 0xb44)
#define SPM_CA15_CPU2_IRQ_MASK      (SPM_BASE + 0xb48)
#define SPM_CA15_CPU3_IRQ_MASK      (SPM_BASE + 0xb4c)
#define SPM_PCM_PASR_DPD_0      (SPM_BASE + 0xb60)
#define SPM_PCM_PASR_DPD_1      (SPM_BASE + 0xb64)
#define SPM_PCM_PASR_DPD_2      (SPM_BASE + 0xb68)
#define SPM_PCM_PASR_DPD_3      (SPM_BASE + 0xb6c)
#define SPM_SLEEP_CA7_WFI0_EN       (SPM_BASE + 0xf00)
#define SPM_SLEEP_CA7_WFI1_EN       (SPM_BASE + 0xf04)
#define SPM_SLEEP_CA7_WFI2_EN       (SPM_BASE + 0xf08)
#define SPM_SLEEP_CA7_WFI3_EN       (SPM_BASE + 0xf0c)
#define SPM_SLEEP_CA15_WFI0_EN      (SPM_BASE + 0xf10)
#define SPM_SLEEP_CA15_WFI1_EN      (SPM_BASE + 0xf14)
#define SPM_SLEEP_CA15_WFI2_EN      (SPM_BASE + 0xf18)
#define SPM_SLEEP_CA15_WFI3_EN      (SPM_BASE + 0xf1c)

#define SPM_PROJECT_CODE    0xb16

#define SPM_REGWR_EN        (1U << 0)
#define SPM_REGWR_CFG_KEY   (SPM_PROJECT_CODE << 16)


/**************************************
 * Macro and Inline
 **************************************/
#define spm_read(addr)          DRV_Reg32(addr)
#define spm_write(addr, val)        DRV_WriteReg32(addr, val)

#define PWR_RST_B           (0x1 << 0)
#define PWR_ISO             (0x1 << 1)
#define PWR_ON              (0x1 << 2)
#define PWR_ON_2ND          (0x1 << 3)
#define PWR_CLK_DIS         (0x1 << 4)

#define STA_POWER_DOWN  0
#define STA_POWER_ON    1

#define INFRACFG_AO_BASE  (0x10000000)
#define TOPAXI_PROT_EN          (INFRACFG_AO_BASE + 0x0220)
#define TOPAXI_PROT_STA1        (INFRACFG_AO_BASE + 0x0228)

//#define APMIXED_BASE              (0x10209000)
//#define AP_PLL_CON7             (APMIXED_BASE + 0x1C)

#define MD1_PROT_MASK        ( (0x1<<24) | (0x1<<25) | (0x1<<26) | (0x1<<27) | (0x1<<28)) //bit 24,25,26,27,28
#define MD2_PROT_MASK        ( (0x1<<29) | (0x1<<30) | (0x1<<31) )//bit 29, 30, 31

#define MD_SRAM_PDN         (0x1 << 8) //MD1, C2K
#define MD1_PWR_STA_MASK    (0x1 << 0)
#define MD2_PWR_STA_MASK    (0x1 << 22)

extern int spm_mtcmos_ctrl_mdsys1(int state);
extern int spm_mtcmos_ctrl_mdsys2(int state);


#endif
