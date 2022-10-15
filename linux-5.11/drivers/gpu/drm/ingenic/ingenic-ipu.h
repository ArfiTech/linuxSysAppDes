/* SPDX-License-Identifier: GPL-2.0 */
//
// Ingenic JZ47xx IPU - Register definitions and private API
//
// Copyright (C) 2020, Paul Cercueil <paul@crapouillou.net>

#ifndef DRIVERS_GPU_DRM_INGENIC_INGENIC_IPU_H
#define DRIVERS_GPU_DRM_INGENIC_INGENIC_IPU_H

#include <linux/bitops.h>

#define JZ_REG_IPU_CTRL			0x00
#define JZ_REG_IPU_STATUS		0x04
#define JZ_REG_IPU_D_FMT		0x08
#define JZ_REG_IPU_Y_ADDR		0x0c
#define JZ_REG_IPU_U_ADDR		0x10
#define JZ_REG_IPU_V_ADDR		0x14
#define JZ_REG_IPU_IN_GS		0x18
#define JZ_REG_IPU_Y_STRIDE		0x1c
#define JZ_REG_IPU_UV_STRIDE		0x20
#define JZ_REG_IPU_OUT_ADDR		0x24
#define JZ_REG_IPU_OUT_GS		0x28
#define JZ_REG_IPU_OUT_STRIDE		0x2c
#define JZ_REG_IPU_RSZ_COEF_INDEX	0x30
#define JZ_REG_IPU_CSC_C0_COEF		0x34
#define JZ_REG_IPU_CSC_C1_COEF		0x38
#define JZ_REG_IPU_CSC_C2_COEF		0x3c
#define JZ_REG_IPU_CSC_C3_COEF		0x40
#define JZ_REG_IPU_CSC_C4_COEF		0x44
#define JZ_REG_IPU_HRSZ_COEF_LUT	0x48
#define JZ_REG_IPU_VRSZ_COEF_LUT	0x4c
#define JZ_REG_IPU_CSC_OFFSET		0x50
#define JZ_REG_IPU_Y_PHY_T_ADDR		0x54
#define JZ_REG_IPU_U_PHY_T_ADDR		0x58
#define JZ_REG_IPU_V_PHY_T_ADDR		0x5c
#define JZ_REG_IPU_OUT_PHY_T_ADDR	0x60

#define JZ_IPU_CTRL_ADDR_SEL		BIT(20)
#define JZ_IPU_CTRL_ZOOM_SEL		BIT(18)
#define JZ_IPU_CTRL_DFIX_SEL		BIT(17)
#define JZ_IPU_CTRL_LCDC_SEL		BIT(11)
#define JZ_IPU_CTRL_SPKG_SEL		BIT(10)
#define JZ_IPU_CTRL_VSCALE		BIT(9)
#define JZ_IPU_CTRL_HSCALE		BIT(8)
#define JZ_IPU_CTRL_STOP		BIT(7)
#define JZ_IPU_CTRL_RST			BIT(6)
#define JZ_IPU_CTRL_FM_IRQ_EN		BIT(5)
#define JZ_IPU_CTRL_CSC_EN		BIT(4)
#define JZ_IPU_CTRL_VRSZ_EN		BIT(3)
#define JZ_IPU_CTRL_HRSZ_EN		BIT(2)
#define JZ_IPU_CTRL_RUN			BIT(1)
#define JZ_IPU_CTRL_CHIP_EN		BIT(0)

#define JZ_IPU_STATUS_OUT_END		BIT(0)

#define JZ_IPU_IN_GS_H_LSB		0x0
#define JZ_IPU_IN_GS_W_LSB		0x10
#define JZ_IPU_OUT_GS_H_LSB		0x0
#define JZ_IPU_OUT_GS_W_LSB		0x10

#define JZ_IPU_Y_STRIDE_Y_LSB		0
#define JZ_IPU_UV_STRIDE_U_LSB		16
#define JZ_IPU_UV_STRIDE_V_LSB		0

#define JZ_IPU_D_FMT_IN_FMT_LSB		0
#define JZ_IPU_D_FMT_IN_FMT_RGB555	(0x0 << JZ_IPU_D_FMT_IN_FMT_LSB)
#define JZ_IPU_D_FMT_IN_FMT_YUV420	(0x0 << JZ_IPU_D_FMT_IN_FMT_LSB)
#define JZ_IPU_D_FMT_IN_FMT_YUV422	(0x1 << JZ_IPU_D_FMT_IN_FMT_LSB)
#define JZ_IPU_D_FMT_IN_FMT_RGB888	(0x2 << JZ_IPU_D_FMT_IN_FMT_LSB)
#define JZ_IPU_D_FMT_IN_FMT_YUV444	(0x2 << JZ_IPU_D_FMT_IN_FMT_LSB)
#define JZ_IPU_D_FMT_IN_FMT_RGB565	(0x3 << JZ_IPU_D_FMT_IN_FMT_LSB)

#define JZ_IPU_D_FMT_YUV_FMT_LSB	2
#define JZ_IPU_D_FMT_YUV_Y1UY0V		(0x0 << JZ_IPU_D_FMT_YUV_FMT_LSB)
#define JZ_IPU_D_FMT_YUV_Y1VY0U		(0x1 << JZ_IPU_D_FMT_YUV_FMT_LSB)
#define JZ_IPU_D_FMT_YUV_UY1VY0		(0x2 << JZ_IPU_D_FMT_YUV_FMT_LSB)
#define JZ_IPU_D_FMT_YUV_VY1UY0		(0x3 << JZ_IPU_D_FMT_YUV_FMT_LSB)
#define JZ_IPU_D_FMT_IN_FMT_YUV411	(0x3 << JZ_IPU_D_FMT_IN_FMT_LSB)

#define JZ_IPU_D_FMT_OUT_FMT_LSB	19
#define JZ_IPU_D_FMT_OUT_FMT_RGB555	(0x0 << JZ_IPU_D_FMT_OUT_FMT_LSB)
#define JZ_IPU_D_FMT_OUT_FMT_RGB565	(0x1 << JZ_IPU_D_FMT_OUT_FMT_LSB)
#define JZ_IPU_D_FMT_OUT_FMT_RGB888	(0x2 << JZ_IPU_D_FMT_OUT_FMT_LSB)
#define JZ_IPU_D_FMT_OUT_FMT_YUV422	(0x3 << JZ_IPU_D_FMT_OUT_FMT_LSB)
#define JZ_IPU_D_FMT_OUT_FMT_RGBAAA	(0x4 << JZ_IPU_D_FMT_OUT_FMT_LSB)

#define JZ_IPU_D_FMT_RGB_OUT_OFT_LSB	22
#define JZ_IPU_D_FMT_RGB_OUT_OFT_RGB	(0x0 << JZ_IPU_D_FMT_RGB_OUT_OFT_LSB)
#define JZ_IPU_D_FMT_RGB_OUT_OFT_RBG	(0x1 << JZ_IPU_D_FMT_RGB_OUT_OFT_LSB)
#define JZ_IPU_D_FMT_RGB_OUT_OFT_GBR	(0x2 << JZ_IPU_D_FMT_RGB_OUT_OFT_LSB)
#define JZ_IPU_D_FMT_RGB_OUT_OFT_GRB	(0x3 << JZ_IPU_D_FMT_RGB_OUT_OFT_LSB)
#define JZ_IPU_D_FMT_RGB_OUT_OFT_BRG	(0x4 << JZ_IPU_D_FMT_RGB_OUT_OFT_LSB)
#define JZ_IPU_D_FMT_RGB_OUT_OFT_BGR	(0x5 << JZ_IPU_D_FMT_RGB_OUT_OFT_LSB)

#define JZ4725B_IPU_RSZ_LUT_COEF_LSB	2
#define JZ4725B_IPU_RSZ_LUT_COEF_MASK	0x7ff
#define JZ4725B_IPU_RSZ_LUT_IN_EN	BIT(1)
#define JZ4725B_IPU_RSZ_LUT_OUT_EN	BIT(0)

#define JZ4760_IPU_RSZ_COEF20_LSB	6
#define JZ4760_IPU_RSZ_COEF31_LSB	17
#define JZ4760_IPU_RSZ_COEF_MASK	0x7ff
#define JZ4760_IPU_RSZ_OFFSET_LSB	1
#define JZ4760_IPU_RSZ_OFFSET_MASK	0x1f

#define JZ_IPU_CSC_OFFSET_CHROMA_LSB	16
#define JZ_IPU_CSC_OFFSET_LUMA_LSB	16

#endif /* DRIVERS_GPU_DRM_INGENIC_INGENIC_IPU_H */
