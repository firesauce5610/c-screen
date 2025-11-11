/*


Author: Caden Gross

Title: styles.h

Description: Manages and creates styles

Date: 11/7/25

*/

#ifndef _styles_H_
#define _styles_H_

#include "liblvgl/core/lv_obj_style.h"
#include "liblvgl/misc/lv_style.h"
#include "liblvgl/misc/lv_types.h"
#include "main.h" // IWYU pragma: keep
#include "liblvgl/misc/lv_area.h"
#include <cstdarg>
#include <cstring>  
#include <climits>

inline void styleUpdate(lv_style_t & style, const char * option, ...) {

	va_list args; // Creates the list of arguments 
	va_start(args, option);

	if (strcmp(option, "Background Color: ") == 0) {
        lv_style_set_bg_color(&style, lv_color_hex(va_arg(args, int)));
    }

	if (strcmp(option, "Border Width: ") == 0) {
        lv_style_set_border_width(&style, va_arg(args, int));
    }

	if (strcmp(option, "Line Color: ") == 0) {
		lv_style_set_line_color(&style, lv_color_hex(va_arg(args, int)));
    }

	if (strcmp(option, "Line Width: ") == 0) {
		lv_style_set_line_width(&style, va_arg(args, int));
    }

	if (strcmp(option, "Line Rounded: ") == 0) {
		lv_style_set_line_rounded(&style, va_arg(args, int));
    }

	if (strcmp(option, "Opacity: ") == 0) {
		lv_style_set_opa(&style, va_arg(args, int));
    }

	if (strcmp(option, "Text Alignment: ") == 0) {
		lv_style_set_text_align(&style, va_arg(args, lv_text_align_t));
    }
}

#endif