#include "board_init.h"

#include "lvgl.h"
#include "port/lv_port_indev.h"
#include "common_data.h"


void board_init(void)
{
    /* Display off the backlight */
    R_IOPORT_PinWrite(&g_ioport_ctrl, LCD_DISPON, BSP_IO_LEVEL_LOW);

#if 1
    fsp_err_t err;
    err = RM_LVGL_PORT_Open(&g_lvgl_port_ctrl, &g_lvgl_port_cfg);
    if (FSP_SUCCESS != err)
    {
        __BKPT(0);
    }

    /* enable the display */
    R_IOPORT_PinWrite(&g_ioport_ctrl, LCD_DISPON, BSP_IO_LEVEL_HIGH);

    /* Enable the backlight */
    R_IOPORT_PinWrite(&g_ioport_ctrl, DISP_BLEN, BSP_IO_LEVEL_HIGH);

    lv_display_set_default(g_lvgl_port_ctrl.p_lv_display);

    lv_port_indev_init();
}
