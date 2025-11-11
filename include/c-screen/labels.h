/*


Author: Caden Gross

Title: labels.h

Description: Label stuff

Date: 11/8/25

*/

#ifndef _labels_H_
#define _labels_H_

#include "liblvgl/core/lv_obj_style.h"
#include "liblvgl/misc/lv_style.h"
#include "liblvgl/misc/lv_types.h"
#include "main.h" // IWYU pragma: keep
#include "liblvgl/misc/lv_area.h"
#include <cstdarg>
#include <cstring>  
#include <climits>

/**
 * DOESN'T FULLY FUNCTION YET, DO NOT TRY PUTTING VARIABLES IN THESE.
 *
 * Example:
 * lv_obj_t * label = addText(button, "ButtonText");
 * 
 *
 * @param parent	The parent object
 * @param fmt       The text and stuff
 * @return          The label
 * @warning         There is a different version of addText for labels not just text on another object
*/
inline lv_obj_t * addText(lv_obj_t * parent, const char * fmt, ...) {
	lv_obj_t * label = lv_label_create(parent);

	va_list args;

	va_start(args, fmt);

	char buffer[256]; // There really shouldn't be a scenario where we add a text with more than 256 so I don't care

	lv_vsnprintf(buffer, sizeof(buffer), fmt, args);
	lv_label_set_text_fmt(label, buffer); 

	return label;
}

/** 
 * DOESN'T FULLY FUNCTION YET, DO NOT TRY PUTTING VARIABLES IN THESE.
 *
 * Example:
 * lv_obj_t * label = addText(datscreen, style, LV_ALIGN_DEFAULT, 5, 10, "Text");
 * 
 *
 * @param parent	The parent object
 * @param style     The labels style
 * @param Alignment The alignment of the object
 * @param xOffset   The x position of the object, offsetted from the alignment
 * @param yOffset   The y position of the object, offsetted from the alignment
 * @param fmt       The text and stuff
 * @return          The label
 * 
*/
inline lv_obj_t * addText(lv_obj_t * parent, lv_style_t & style, lv_align_t Alignment, int xOffset, int yOffset, const char * fmt, ...) {
	lv_obj_t * label = lv_label_create(parent);

	va_list args;
	va_start(args, fmt);
	char buffer[256]; // There really shouldn't be a scenario where we add a text with more than 256 so I don't care

	lv_vsnprintf(buffer, sizeof(buffer), fmt, args);
	lv_label_set_text_fmt(label, buffer);
	lv_obj_add_style(label, &style, 0);

	int xo = (xOffset != INT_MIN) ? xOffset : 0;
	int yo = (yOffset != INT_MIN) ? yOffset : 0;
	lv_obj_align(label, Alignment, xo, yo);

	return label;
}

/** 
 * DOESN'T FULLY FUNCTION YET, DO NOT TRY PUTTING VARIABLES IN THESE.
 *
 * Example:
 * lv_obj_t * label = addText(datscreen, style, LV_ALIGN_DEFAULT, 5, 10, "Text");
 * 
 *
 * @param parent	The parent object
 * @param Alignment The alignment of the object
 * @param xOffset   The x position of the object, offsetted from the alignment
 * @param yOffset   The y position of the object, offsetted from the alignment
 * @param fmt       The text and stuff
 * @return          The label
 * 
*/
inline lv_obj_t * addText(lv_obj_t * parent, lv_align_t Alignment, int xOffset, int yOffset, const char * fmt, ...) {
	lv_obj_t * label = lv_label_create(parent);

	va_list args;
	va_start(args, fmt);
	char buffer[256]; // There really shouldn't be a scenario where we add a text with more than 256 so I don't care

	lv_vsnprintf(buffer, sizeof(buffer), fmt, args);
	lv_label_set_text_fmt(label, buffer);

	int xo = (xOffset != INT_MIN) ? xOffset : 0;
	int yo = (yOffset != INT_MIN) ? yOffset : 0;
	lv_obj_align(label, Alignment, xo, yo);

	return label;
}



/** 
 * DOESN'T FULLY FUNCTION YET, DO NOT TRY PUTTING VARIABLES IN THESE.
 *
 * Example:
 * lv_obj_t * label = addText(datscreen, style, 5, 10, "Text");
 * 
 *
 * @param parent	The parent object
 * @param style     The labels style
 * @param xPos      The x position of the object
 * @param yPos      The y position of the object
 * @param fmt       The text and stuff
 * @return          The label
 * 
*/
inline lv_obj_t * addText(lv_obj_t * parent, lv_style_t & style, int xPos, int yPos, const char * fmt, ...) {
	lv_obj_t * label = lv_label_create(parent);

	va_list args;
	va_start(args, fmt);
	char buffer[256]; // There really shouldn't be a scenario where we add a text with more than 256 so I don't care

	lv_vsnprintf(buffer, sizeof(buffer), fmt, args);
	lv_label_set_text_fmt(label, buffer);
	lv_obj_add_style(label, &style, 0);

	lv_obj_align(label, LV_ALIGN_DEFAULT, xPos, yPos);

	return label;
}


/** 
 * DOESN'T FULLY FUNCTION YET, DO NOT TRY PUTTING VARIABLES IN THESE.
 *
 * Example:
 * updateText(buttonLabel, "New Text");
 * 
 *
 * @param obj      	The label you are updating
 * @param fmt       The text and stuff
 * 
*/
inline void updateText(lv_obj_t * obj, const char * fmt, ...) {
	va_list args;

	va_start(args, fmt);

	char buffer[256]; // There really shouldn't be a scenario where we add a text with more than 256 so I don't care

	lv_vsnprintf(buffer, sizeof(buffer), fmt, args);
	lv_label_set_text_fmt(obj, buffer);
}



#endif