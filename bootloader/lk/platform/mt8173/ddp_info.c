#define LOG_TAG "INFO"

#include <platform/ddp_log.h>

#include <platform/ddp_info.h>

char* ddp_get_module_name(DISP_MODULE_ENUM module)
{
	switch (module) {
		case DISP_MODULE_UFOE   :
			return "ufoe ";
		case DISP_MODULE_AAL    :
			return "aal ";
		case DISP_MODULE_COLOR0 :
			return "color0 ";
		case DISP_MODULE_COLOR1 :
			return "color1 ";
		case DISP_MODULE_RDMA0  :
			return "rdma0 ";
		case DISP_MODULE_RDMA1  :
			return "rdma1 ";
		case DISP_MODULE_RDMA2  :
			return "rdma2 ";
		case DISP_MODULE_WDMA0  :
			return "wdma0 ";
		case DISP_MODULE_WDMA1  :
			return "wdma1 ";
		case DISP_MODULE_OVL0   :
			return "ovl0 ";
		case DISP_MODULE_OVL1   :
			return "ovl1 ";
		case DISP_MODULE_GAMMA  :
			return "gamma ";
		case DISP_MODULE_PWM0   :
			return "pwm0 ";
		case DISP_MODULE_PWM1   :
			return "pwm1 ";
		case DISP_MODULE_OD     :
			return "od ";
		case DISP_MODULE_MERGE  :
			return "merge ";
		case DISP_MODULE_SPLIT0 :
			return "split0 ";
		case DISP_MODULE_SPLIT1 :
			return "split1 ";
		case DISP_MODULE_DSI0   :
			return "dsi0 ";
		case DISP_MODULE_DSI1   :
			return "dsi1 ";
		case DISP_MODULE_DSIDUAL:
			return "dsidual ";
		case DISP_MODULE_DPI0    :
			return "dpi ";
		case DISP_MODULE_SMI_COMMON    :
			return "smi_common ";
		case DISP_MODULE_SMI_LARB0:
			return "smi_larb0 ";
		case DISP_MODULE_LARB4:
			return "smi_larb4 ";
		case DISP_MODULE_CONFIG :
			return "config ";
		case DISP_MODULE_CMDQ   :
			return "cmdq ";
		case DISP_MODULE_MUTEX  :
			return "mutex ";
		default:
			DDPMSG("invalid module id=%d", module);
			return "unknown";
	}
}

int ddp_get_module_max_irq_bit(DISP_MODULE_ENUM module)
{
	switch (module) {
		case DISP_MODULE_UFOE   :
			return 0;
		case DISP_MODULE_AAL    :
			return 1;
		case DISP_MODULE_COLOR0 :
			return 2;
		case DISP_MODULE_COLOR1 :
			return 2;
		case DISP_MODULE_RDMA0  :
			return 5;
		case DISP_MODULE_RDMA1  :
			return 5;
		case DISP_MODULE_RDMA2  :
			return 5;
		case DISP_MODULE_WDMA0  :
			return 1;
		case DISP_MODULE_WDMA1  :
			return 1;
		case DISP_MODULE_OVL0   :
			return 3;
		case DISP_MODULE_OVL1   :
			return 3;
		case DISP_MODULE_GAMMA  :
			return 0;
		case DISP_MODULE_PWM0   :
			return 0;
		case DISP_MODULE_PWM1   :
			return 0;
		case DISP_MODULE_OD     :
			return 0;
		case DISP_MODULE_MERGE  :
			return 0;
		case DISP_MODULE_SPLIT0 :
			return 0;
		case DISP_MODULE_SPLIT1 :
			return 0;
		case DISP_MODULE_DSI0   :
			return 6;
		case DISP_MODULE_DSI1   :
			return 6;
		case DISP_MODULE_DSIDUAL:
			return 6;
		case DISP_MODULE_DPI0    :
			return 2;
		case DISP_MODULE_SMI_COMMON:
			return 0;
		case DISP_MODULE_SMI_LARB0:
			return 0;
		case DISP_MODULE_CONFIG :
			return 0;
		case DISP_MODULE_CMDQ   :
			return 0;
		case DISP_MODULE_MUTEX  :
			return 19;
		default:
			DDPMSG("invalid module id=%d", module);
			return 0;
	}
}

unsigned int ddp_module_to_idx(int module)
{
	unsigned int id=0;
	switch (module) {
		case DISP_MODULE_UFOE:
		case DISP_MODULE_AAL:
		case DISP_MODULE_COLOR0:
		case DISP_MODULE_RDMA0:
		case DISP_MODULE_WDMA0:
		case DISP_MODULE_OVL0:
		case DISP_MODULE_GAMMA:
		case DISP_MODULE_PWM0:
		case DISP_MODULE_OD:
		case DISP_MODULE_SPLIT0:
		case DISP_MODULE_DSI0:
		case DISP_MODULE_DPI0:
			id = 0;
			break;

		case DISP_MODULE_COLOR1:
		case DISP_MODULE_RDMA1:
		case DISP_MODULE_WDMA1:
		case DISP_MODULE_OVL1:
		case DISP_MODULE_PWM1:
		case DISP_MODULE_SPLIT1:
		case DISP_MODULE_DSI1:
			id = 1;
			break;
		case DISP_MODULE_RDMA2:
		case DISP_MODULE_DSIDUAL:
			id = 2;
			break;
		default:
			DDPERR("ddp_module_to_idx, module=0x%x \n", module);
	}

	return id;
}

int ddp_enable_module_clock(DISP_MODULE_ENUM module)
{
	switch (module) {
		case DISP_MODULE_SMI_COMMON:
		case DISP_MODULE_SMI_LARB0:
			DISP_REG_SET_FIELD(NULL,MMSYS_CG_FLD_CG0_SMI_COMMON,DISP_REG_CONFIG_MMSYS_CG_CLR0,1);
			DISP_REG_SET_FIELD(NULL,MMSYS_CG_FLD_CG0_SMI_LARB0,DISP_REG_CONFIG_MMSYS_CG_CLR0,1);
			break;
		case DISP_MODULE_LARB4:
			DISP_REG_SET_FIELD(NULL,MMSYS_CG_FLD_CG1_SMI_LARB4,DISP_REG_CONFIG_MMSYS_CG_CLR1,1);
			break;
		case DISP_MODULE_MUTEX:
			DISP_REG_SET_FIELD(NULL,MMSYS_CG_FLD_CG0_MUTEX_32K,DISP_REG_CONFIG_MMSYS_CG_CLR0,1);
			break;
		case DISP_MODULE_OVL0:
			DISP_REG_SET_FIELD(NULL,MMSYS_CG_FLD_CG0_OVL0,DISP_REG_CONFIG_MMSYS_CG_CLR0,1);
			break;
		case DISP_MODULE_OVL1:
			DISP_REG_SET_FIELD(NULL,MMSYS_CG_FLD_CG0_OVL1,DISP_REG_CONFIG_MMSYS_CG_CLR0,1);
			break;
		case DISP_MODULE_COLOR0:
			DISP_REG_SET_FIELD(NULL,MMSYS_CG_FLD_CG0_COLOR0,DISP_REG_CONFIG_MMSYS_CG_CLR0,1);
			break;
		case DISP_MODULE_COLOR1:
			DISP_REG_SET_FIELD(NULL,MMSYS_CG_FLD_CG0_COLOR1,DISP_REG_CONFIG_MMSYS_CG_CLR0,1);
			break;
		case DISP_MODULE_AAL:
			DISP_REG_SET_FIELD(NULL,MMSYS_CG_FLD_CG0_AAL,DISP_REG_CONFIG_MMSYS_CG_CLR0,1);
			break;
		case DISP_MODULE_OD:
			DISP_REG_SET_FIELD(NULL,MMSYS_CG_FLD_CG0_OD,DISP_REG_CONFIG_MMSYS_CG_CLR0,1);
			break;
		case DISP_MODULE_UFOE:
			DISP_REG_SET_FIELD(NULL,MMSYS_CG_FLD_CG0_UFOE,DISP_REG_CONFIG_MMSYS_CG_CLR0,1);
			break;
		case DISP_MODULE_RDMA0:
			DISP_REG_SET_FIELD(NULL,MMSYS_CG_FLD_CG0_RDMA0,DISP_REG_CONFIG_MMSYS_CG_CLR0,1);
			break;
		case DISP_MODULE_RDMA1:
			DISP_REG_SET_FIELD(NULL,MMSYS_CG_FLD_CG0_RDMA1,DISP_REG_CONFIG_MMSYS_CG_CLR0,1);
			break;
		case DISP_MODULE_RDMA2:
			DISP_REG_SET_FIELD(NULL,MMSYS_CG_FLD_CG0_RDMA2,DISP_REG_CONFIG_MMSYS_CG_CLR0,1);
			break;
		case DISP_MODULE_SPLIT0:
			DISP_REG_SET_FIELD(NULL,MMSYS_CG_FLD_CG0_SPLIT0,DISP_REG_CONFIG_MMSYS_CG_CLR0,1);
			break;
		case DISP_MODULE_SPLIT1:
			DISP_REG_SET_FIELD(NULL,MMSYS_CG_FLD_CG0_SPLIT1,DISP_REG_CONFIG_MMSYS_CG_CLR0,1);
			break;
		case DISP_MODULE_GAMMA:
			DISP_REG_SET_FIELD(NULL,MMSYS_CG_FLD_CG0_GAMMA,DISP_REG_CONFIG_MMSYS_CG_CLR0,1);
			break;
		case DISP_MODULE_DSI0:
			DISP_REG_SET_FIELD(NULL,MMSYS_CG_FLD_CG1_DSI0_ENG,DISP_REG_CONFIG_MMSYS_CG_CLR1,1);
			DISP_REG_SET_FIELD(NULL,MMSYS_CG_FLD_CG1_DSI0_DIG,DISP_REG_CONFIG_MMSYS_CG_CLR1,1);
			break;
		case DISP_MODULE_DSI1:
			DISP_REG_SET_FIELD(NULL,MMSYS_CG_FLD_CG1_DSI1_ENG,DISP_REG_CONFIG_MMSYS_CG_CLR1,1);
			DISP_REG_SET_FIELD(NULL,MMSYS_CG_FLD_CG1_DSI1_DIG,DISP_REG_CONFIG_MMSYS_CG_CLR1,1);
			break;
		case DISP_MODULE_DPI0:
			DISP_REG_SET_FIELD(NULL,MMSYS_CG_FLD_CG1_DPI_PIX,DISP_REG_CONFIG_MMSYS_CG_CLR1,1);
			DISP_REG_SET_FIELD(NULL,MMSYS_CG_FLD_CG1_DPI_ENG,DISP_REG_CONFIG_MMSYS_CG_CLR1,1);
			break;
		case DISP_MODULE_PWM0:
			DISP_REG_SET_FIELD(NULL,MMSYS_CG_FLD_CG1_PWM0_MM,DISP_REG_CONFIG_MMSYS_CG_CLR1,1);
			DISP_REG_SET_FIELD(NULL,MMSYS_CG_FLD_CG1_PWM0_26M,DISP_REG_CONFIG_MMSYS_CG_CLR1,1);
			break;
		case DISP_MODULE_DSIDUAL:
			DISP_REG_SET_FIELD(NULL,MMSYS_CG_FLD_CG1_DSI0_ENG,DISP_REG_CONFIG_MMSYS_CG_CLR1,1);
			DISP_REG_SET_FIELD(NULL,MMSYS_CG_FLD_CG1_DSI0_DIG,DISP_REG_CONFIG_MMSYS_CG_CLR1,1);
			DISP_REG_SET_FIELD(NULL,MMSYS_CG_FLD_CG1_DSI1_ENG,DISP_REG_CONFIG_MMSYS_CG_CLR1,1);
			DISP_REG_SET_FIELD(NULL,MMSYS_CG_FLD_CG1_DSI1_DIG,DISP_REG_CONFIG_MMSYS_CG_CLR1,1);
			break;
		default:
			DDPERR("enable module clock unknow module %d ",module);
	}
	DISP_REG_SET(NULL, DISP_REG_CONFIG_MMSYS_DUMMY,~0x58003);
	DDPMSG("enable  %s clk, CG0 0x%x, CG1 0x%x \n",
	       ddp_get_module_name(module), DISP_REG_GET(DISP_REG_CONFIG_MMSYS_CG_CON0),DISP_REG_GET(DISP_REG_CONFIG_MMSYS_CG_CON1));
	return 0;
}

int ddp_disable_module_clock(DISP_MODULE_ENUM module)
{
	switch (module) {
		case DISP_MODULE_SMI_COMMON:
		case DISP_MODULE_SMI_LARB0:
			DISP_REG_SET_FIELD(NULL,MMSYS_CG_FLD_CG0_SMI_COMMON,DISP_REG_CONFIG_MMSYS_CG_SET0,1);
			DISP_REG_SET_FIELD(NULL,MMSYS_CG_FLD_CG0_SMI_LARB0,DISP_REG_CONFIG_MMSYS_CG_SET0,1);
			break;
		case DISP_MODULE_LARB4:
			DISP_REG_SET_FIELD(NULL,MMSYS_CG_FLD_CG1_SMI_LARB4,DISP_REG_CONFIG_MMSYS_CG_SET1,1);
			break;
		case DISP_MODULE_MUTEX:
			DISP_REG_SET_FIELD(NULL,MMSYS_CG_FLD_CG0_MUTEX_32K,DISP_REG_CONFIG_MMSYS_CG_SET0,1);
			break;
		case DISP_MODULE_OVL0:
			DISP_REG_SET_FIELD(NULL,MMSYS_CG_FLD_CG0_OVL0,DISP_REG_CONFIG_MMSYS_CG_SET0,1);
			break;
		case DISP_MODULE_OVL1:
			DISP_REG_SET_FIELD(NULL,MMSYS_CG_FLD_CG0_OVL1,DISP_REG_CONFIG_MMSYS_CG_SET0,1);
			break;
		case DISP_MODULE_COLOR0:
			DISP_REG_SET_FIELD(NULL,MMSYS_CG_FLD_CG0_COLOR0,DISP_REG_CONFIG_MMSYS_CG_SET0,1);
			break;
		case DISP_MODULE_COLOR1:
			DISP_REG_SET_FIELD(NULL,MMSYS_CG_FLD_CG0_COLOR1,DISP_REG_CONFIG_MMSYS_CG_SET0,1);
			break;
		case DISP_MODULE_AAL:
			DISP_REG_SET_FIELD(NULL,MMSYS_CG_FLD_CG0_AAL,DISP_REG_CONFIG_MMSYS_CG_SET0,1);
			break;
		case DISP_MODULE_OD:
			DISP_REG_SET_FIELD(NULL,MMSYS_CG_FLD_CG0_OD,DISP_REG_CONFIG_MMSYS_CG_SET0,1);
			break;
		case DISP_MODULE_UFOE:
			DISP_REG_SET_FIELD(NULL,MMSYS_CG_FLD_CG0_UFOE,DISP_REG_CONFIG_MMSYS_CG_SET0,1);
			break;
		case DISP_MODULE_RDMA0:
			DISP_REG_SET_FIELD(NULL,MMSYS_CG_FLD_CG0_RDMA0,DISP_REG_CONFIG_MMSYS_CG_SET0,1);
			break;
		case DISP_MODULE_RDMA1:
			DISP_REG_SET_FIELD(NULL,MMSYS_CG_FLD_CG0_RDMA1,DISP_REG_CONFIG_MMSYS_CG_SET0,1);
			break;
		case DISP_MODULE_RDMA2:
			DISP_REG_SET_FIELD(NULL,MMSYS_CG_FLD_CG0_RDMA2,DISP_REG_CONFIG_MMSYS_CG_SET0,1);
			break;
		case DISP_MODULE_SPLIT0:
			DISP_REG_SET_FIELD(NULL,MMSYS_CG_FLD_CG0_SPLIT0,DISP_REG_CONFIG_MMSYS_CG_SET0,1);
			break;
		case DISP_MODULE_SPLIT1:
			DISP_REG_SET_FIELD(NULL,MMSYS_CG_FLD_CG0_SPLIT1,DISP_REG_CONFIG_MMSYS_CG_SET0,1);
			break;
		case DISP_MODULE_GAMMA:
			DISP_REG_SET_FIELD(NULL,MMSYS_CG_FLD_CG0_GAMMA,DISP_REG_CONFIG_MMSYS_CG_SET0,1);
			break;
		case DISP_MODULE_DSI0:
			DISP_REG_SET_FIELD(NULL,MMSYS_CG_FLD_CG1_DSI0_ENG,DISP_REG_CONFIG_MMSYS_CG_SET1,1);
			DISP_REG_SET_FIELD(NULL,MMSYS_CG_FLD_CG1_DSI0_DIG,DISP_REG_CONFIG_MMSYS_CG_SET1,1);
			break;
		case DISP_MODULE_DSI1:
			DISP_REG_SET_FIELD(NULL,MMSYS_CG_FLD_CG1_DSI1_ENG,DISP_REG_CONFIG_MMSYS_CG_SET1,1);
			DISP_REG_SET_FIELD(NULL,MMSYS_CG_FLD_CG1_DSI1_DIG,DISP_REG_CONFIG_MMSYS_CG_SET1,1);
			break;
		case DISP_MODULE_PWM0:
			DISP_REG_SET_FIELD(NULL,MMSYS_CG_FLD_CG1_PWM0_MM,DISP_REG_CONFIG_MMSYS_CG_SET1,1);
			DISP_REG_SET_FIELD(NULL,MMSYS_CG_FLD_CG1_PWM0_26M,DISP_REG_CONFIG_MMSYS_CG_SET1,1);
			break;
		case DISP_MODULE_DSIDUAL:
			DISP_REG_SET_FIELD(NULL,MMSYS_CG_FLD_CG1_DSI0_ENG,DISP_REG_CONFIG_MMSYS_CG_SET1,1);
			DISP_REG_SET_FIELD(NULL,MMSYS_CG_FLD_CG1_DSI0_DIG,DISP_REG_CONFIG_MMSYS_CG_SET1,1);
			DISP_REG_SET_FIELD(NULL,MMSYS_CG_FLD_CG1_DSI1_ENG,DISP_REG_CONFIG_MMSYS_CG_SET1,1);
			DISP_REG_SET_FIELD(NULL,MMSYS_CG_FLD_CG1_DSI1_DIG,DISP_REG_CONFIG_MMSYS_CG_SET1,1);
			break;
		default:
			DDPERR("disable module clock unknow module %d ",module);
	}
	DDPMSG("disable %s clk, CG0 0x%x, CG1 0x%x \n",
	       ddp_get_module_name(module), DISP_REG_GET(DISP_REG_CONFIG_MMSYS_CG_CON0),DISP_REG_GET(DISP_REG_CONFIG_MMSYS_CG_CON1));
	return 0;
}



// dsi
extern DDP_MODULE_DRIVER ddp_driver_dsi0;
extern DDP_MODULE_DRIVER ddp_driver_dsi1;
extern DDP_MODULE_DRIVER ddp_driver_dsidual;
// dpi
extern DDP_MODULE_DRIVER ddp_driver_dpi0;
extern DDP_MODULE_DRIVER ddp_driver_dpi1;


// ovl
extern DDP_MODULE_DRIVER ddp_driver_ovl0;
extern DDP_MODULE_DRIVER ddp_driver_ovl1;
// rdma
extern DDP_MODULE_DRIVER ddp_driver_rdma0;
extern DDP_MODULE_DRIVER ddp_driver_rdma1;
extern DDP_MODULE_DRIVER ddp_driver_rdma2;


// wdma
//extern DDP_MODULE_DRIVER ddp_driver_wdma0;
//extern DDP_MODULE_DRIVER ddp_driver_wdma1;
// color
extern DDP_MODULE_DRIVER ddp_driver_color;
// aal
extern DDP_MODULE_DRIVER ddp_driver_aal;
// od
extern  DDP_MODULE_DRIVER ddp_driver_od;
// ufoe
extern DDP_MODULE_DRIVER ddp_driver_ufoe;
// gamma
extern DDP_MODULE_DRIVER ddp_driver_gamma;

// split
extern DDP_MODULE_DRIVER ddp_driver_split0;
extern DDP_MODULE_DRIVER ddp_driver_split1 ;

// pwm
//extern DDP_MODULE_DRIVER ddp_driver_pwm;

DDP_MODULE_DRIVER  * ddp_modules_driver[DISP_MODULE_NUM] = {
	0, // DISP_MODULE_CONFIG,
	&ddp_driver_ovl0, // DISP_MODULE_OVL0,
	&ddp_driver_ovl1, // DISP_MODULE_OVL1,
	&ddp_driver_rdma0, // DISP_MODULE_RDMA0  ,
	&ddp_driver_rdma1, // DISP_MODULE_RDMA1,
	&ddp_driver_rdma2, // DISP_MODULE_RDMA2,      /* 5 */
	0, // DISP_MODULE_WDMA0  ,
	0, // DISP_MODULE_WDMA1  ,
	&ddp_driver_color, // DISP_MODULE_COLOR0,
	&ddp_driver_color, // DISP_MODULE_COLOR1,
	&ddp_driver_aal, // DISP_MODULE_AAL,        /* 10 */
	&ddp_driver_od, // DISP_MODULE_OD     ,
	&ddp_driver_gamma, // DISP_MODULE_GAMMA,
	0, // DISP_MODULE_MERGE,
	&ddp_driver_split0, // DISP_MODULE_SPLIT0 ,
	&ddp_driver_split1, // DISP_MODULE_SPLIT1,     /* 15 */
	&ddp_driver_ufoe, // DISP_MODULE_UFOE,
	0, // DISP_MODULE_DISPATCHER,
	&ddp_driver_dsi0, // DISP_MODULE_DSI0,
	&ddp_driver_dsi1, // DISP_MODULE_DSI1,
	&ddp_driver_dpi0, // DISP_MODULE_DPI0,       /* 20 */
	&ddp_driver_dpi1, // DISP_MODULE_DPI1,
	0, // DISP_MODULE_PWM0,
	0, // DISP_MODULE_PWM1,
	0, // DISP_MODULE_MUTEX,
	0, // DISP_MODULE_SMI_LARB0,  /* 25 */
	0, // DISP_MODULE_SMI_COMMON,
	0, // DISP_MODULE_HDMI,
	0, // DISP_MODULE_LVDS,
	0, // DISP_MODULE_LARB4,
	0, // DISP_MODULE_MIPITX0,    /* 30 */
	0, // DISP_MODULE_MIPITX1,
	&ddp_driver_dsidual,//DISP_MODULE_DSIDUAL, // 32
	0, // DISP_MODULE_CMDQ,
	0, // DISP_MODULE_CONFIG2,
	0, // DISP_MODULE_CONFIG3,    /* 35 */
	0, // DISP_MODULE_IO_DRIVING,
	0, // DISP_MODULE_TVDPLL_CFG6,
	0, // DISP_MODULE_TVDPLL_CON0,
	0, // DISP_MODULE_TVDPLL_CON1,
	0 // DISP_MODULE_UNKNOWN,    /* 40 */
};
