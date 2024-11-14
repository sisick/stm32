
/**
 * @file main
 *
 */

/*********************
 *      INCLUDES
 *********************/
#include <stdlib.h>
#include <unistd.h>

#include "lv_conf.h"
#include "lvgl/lvgl.h"
#include "lvgl/demos/lv_demos.h"
#include "lvgl/examples/lv_examples.h"


/*********************
 *      DEFINES
 *********************/

/**********************
 *      TYPEDEFS
 **********************/

/**********************
 *  STATIC PROTOTYPES
 **********************/

/**********************
 *  STATIC VARIABLES
 **********************/
//static const wchar_t * title = L"LVGL port Windows CodeBlocks.      https://lvgl.io | https://docs.lvgl.io";
static const wchar_t * title = L"百问网LVGL课程案例  © Copyright 2024, Shenzhen Baiwenwang Technology Co., Ltd.   https://www.100ask.net | https://lvgl.100ask.net";

/**********************
 *      MACROS
 **********************/

/**********************
 *   GLOBAL FUNCTIONS
 **********************/
int APIENTRY WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR szCmdLine, int nCmdShow)
{
    /*Initialize LVGL*/
    lv_init();

    /*Initialize the HAL for LVGL*/
    lv_display_t * display = lv_windows_create_display(title, 1024, 600, 100, FALSE, FALSE);
    lv_windows_acquire_pointer_indev(display);

    /*Output prompt information to the console, you can also use printf() to print directly*/
    LV_LOG_USER("LVGL initialization completed!");

    /*Run the demo*/
    // 下面这三行是运行一个demo，第一行和后面两行的效果是一样的，只能同时去掉第一行或者后面两行，两者之一的注释
    // 后续学习的时候要确保下面这三行都被注释掉
    lv_demo_widgets();
    //char * demo_str[] = {"widgets"};
    //lv_demos_create(demo_str, strlen((char * )demo_str));

    /* 课程示例代码，一般同时只运行一个
       运行前，请将上面的三行代码都注释掉 */



    while(1) {
        /* Periodically call the lv_task handler.
         * It could be done in a timer interrupt or an OS task too.*/
        lv_task_handler();
        usleep(5000);       /*Just to let the system breath*/
    }
    return 0;
}

