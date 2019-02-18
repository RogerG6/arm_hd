# include "lcd.h"
# define LCD_FB_BASE 0x33c00000

lcd_params lcd_4_3_params = {
    .name = "lcd_4.3",
    .pins_pol = {
        .de    = NORMAL,     /* normal: 高电平时，能够传输数据 */
        .pwren = NORMAL,     /* normal: 高电平时，给lcd提供AVDD */
        .vclk  = NORMAL,     /* normal: 在下降沿获取数据 */
        .rgb   = NORMAL,     /* normal: 高电平表示1 */
        .hsync = INVERT,     /* normal: 高脉冲 */
        .vsync = INVERT,     /* normal: 高脉冲 */
    },

    .time_seq = {
        /* 垂直方向 */
        .tvp = 10,    /* vsync脉冲宽度 Vertical Pulse width */
        .tvb = 2,     /* 上边黑框 Vertical Back porch */
        .tvf = 2,     /* 下边黑框 Vertical Front porch */

        /* 水平方向 */
        .thp = 41,    /* hsync脉冲宽度 Horizontal Pulse width */
        .thb = 2,     /* 左边黑框 Horizontal Back porch */
        .thf = 2,     /* 右边黑框 Horizontal Front porch */
        .vclk = 9,    /* MHz */

    },

    .xres = 480,    /* colum num */
    .yres = 272,    /* row num */
    .bpp = 32,
    .fb_base = LCD_FB_BASE,
};

void lcd_4_3_add(void)
{
    register_lcd(&lcd_4_3_params);
}




