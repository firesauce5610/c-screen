/*


Author: Caden Gross

Title: tabview.h

Description: Manages tabviews

Date: 11/8/25

*/

#ifndef _tabview_H_
#define _tabview_H_

#include "liblvgl/core/lv_obj_style.h"
#include "liblvgl/misc/lv_style.h"
#include "liblvgl/misc/lv_types.h"
#include "main.h" // IWYU pragma: keep
#include "liblvgl/misc/lv_area.h"
#include <cstdarg>
#include <cstring>  
#include <climits>

/**
 * Creates a button
 *
 * Example:
 * lv_obj_t * tabview = createTabView(60, style, example_screen, LV_DIR_TOP);
 * 
 * lv_obj_t * tab1 = lv_tabview_add_tab(tabview, "Test1");
 * lv_obj_t * tab2 = lv_tabview_add_tab(tabview, "Test2");
 * lv_obj_t * tab3 = lv_tabview_add_tab(tabview, "Test3");
 *
 * @param width     The width of the dropdown
 * @param style     The objects style
 * @param screen    The screen/parent object of the child object
 * @param dir       The direction of the screen that the object is on
 * @return          The button
 */
inline lv_obj_t * createTabView(int width, lv_style_t & style, lv_obj_t * screen = lv_screen_active(), lv_dir_t dir = LV_DIR_TOP) {
	lv_obj_t * tabview;
    tabview = lv_tabview_create(screen);

	lv_tabview_set_tab_bar_position(tabview, dir);
    lv_tabview_set_tab_bar_size(tabview, width);
	lv_obj_add_style(tabview, &style, 0); /*0 means add to the main part and default state*/

	lv_obj_remove_flag(lv_tabview_get_content(tabview), LV_OBJ_FLAG_SCROLLABLE);

	return tabview;
}


#endif