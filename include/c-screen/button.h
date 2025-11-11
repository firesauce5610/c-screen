/*


Author: Caden Gross

Title: button.h

Description: Adds buttons

Date: 11/7/25

*/

#ifndef _button_H_
#define _button_H_

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
 * lv_obj_t * button = createButton(LV_ALIGN_CENTER, 12, 12, 120, 120, style, screen); 
 * lv_obj_t * unneededlabel = addText(button, "Button Text");
 *
 * @param Alignment The alignment of the object
 * @param xOffset   The x position of the object, offsetted from the alignment
 * @param yOffset   The y position of the object, offsetted from the alignment
 * @param width     The width of the object
 * @param height    The height of the object
 * @param style     The objects style
 * @param screen    The screen/parent object of the child object
 * @return          The button
 */
inline lv_obj_t * createButton(lv_align_t Alignment, int xOffset, int yOffset, int width, int height, lv_style_t & style, lv_obj_t * screen = lv_screen_active()) {
	lv_obj_t * button = lv_button_create(screen);
	lv_obj_add_style(button, &style, 0); /*0 means add to the main part and default state*/
	/* Set parent-sized width, and content-sized height */
	lv_obj_set_size(button, width, height);
	/* Align to the right center with 20px offset horizontally */
	lv_obj_align(button, Alignment, xOffset, yOffset);

	return button;
}

/**
 * Creates a button
 *
 * Example:
 * lv_obj_t * button = createButton(120, 50, 120, 120, style, screen); 
 * lv_obj_t * unneededlabel = addText(button, "Button Text");
 *
 * @param xPos      The x position of the object
 * @param yPos      The y position of the object
 * @param width     The width of the object
 * @param height    The height of the object
 * @param style     The objects style
 * @param screen    The screen/parent object of the child object
 * @return          The button
 */
inline lv_obj_t * createButton(int xPos, int yPos, int width, int height, lv_style_t & style, lv_obj_t * screen = lv_screen_active()) {
	lv_obj_t * button = lv_button_create(screen);
	lv_obj_add_style(button, &style, 0); /*0 means add to the main part and default state*/
	/* Set parent-sized width, and content-sized height */
	lv_obj_set_size(button, width, height);
	/* Align to the right center with 20px offset horizontally */
	lv_obj_align(button, LV_ALIGN_DEFAULT, xPos, yPos);
	
	return button;
}

#endif