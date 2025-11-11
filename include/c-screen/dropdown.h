/*


Author: Caden Gross

Title: dropdown.h

Description: Creates and manages dropdowns

Date: 11/8/25

*/

#ifndef _dropdown_H_
#define _dropdown_H_

#include "liblvgl/core/lv_obj_style.h"
#include "liblvgl/misc/lv_style.h"
#include "liblvgl/misc/lv_types.h"
#include "main.h" // IWYU pragma: keep
#include "liblvgl/misc/lv_area.h"
#include <cstdarg>
#include <cstring>  
#include <climits>

/**
 * Creates a dropdown
 *
 * Example:
 * lv_obj_t * dropdown = createDropdown(LV_ALIGN_CENTER, 12, 12, 120, 120, style, screen); 
 * lv_dropdown_set_options( // Creates the dropdowns options
 *		thedropdown,
 *		"Example\n"
 *		"SecondLine\n"
 *		"ThirdOption"
 *	);
 *
 * @param Alignment The alignment of the object
 * @param xOffset   The x position of the object, offsetted from the alignment
 * @param yOffset   The y position of the object, offsetted from the alignment
 * @param width     The width of the object
 * @param height    The height of the object
 * @param style     The objects style
 * @param screen    The screen/parent object of the child object
 * @return          The dropdown
 */
inline lv_obj_t * createDropDown(lv_align_t Alignment, int xOffset, int yOffset, int width, int height, lv_style_t & style, lv_obj_t * screen = lv_screen_active()) {
	lv_obj_t * list = lv_dropdown_create(screen);
	lv_obj_add_style(list, &style, 0); /*0 means add to the main part and default state*/
	/* Set parent-sized width, and content-sized height */
	lv_obj_set_size(list, width, height);
	/* Align to the right center with 20px offset horizontally */
	lv_obj_align(list, Alignment, xOffset, yOffset);

	return list;
}

#endif