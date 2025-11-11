/*


Author: Caden Gross

Title: shapes.h

Description: Adds all shape classes and functions

Date: 11/7/25

*/

#ifndef _shapes_H_
#define _shapes_H_

#include "liblvgl/core/lv_obj_style.h"
#include "liblvgl/misc/lv_style.h"
#include "liblvgl/misc/lv_types.h"
#include "main.h" // IWYU pragma: keep
#include "liblvgl/misc/lv_area.h"
#include <cstdarg>
#include <cstring>  
#include <climits>

class clvgl_line {
private:
	lv_obj_t* line_obj;

	// Big permanent storage that is a 2d array which stores all the points
	std::vector<lv_point_precise_t> m_points; 

public:
	// Big magic constructor which takes the temp array given to the function and makes sure it is turn permanent
	clvgl_line(const std::vector<lv_point_precise_t>& initial_points, lv_style_t& style, lv_obj_t * screen = lv_screen_active()) { 
		// Copys the temp points into the m_points vector
		m_points = initial_points;

		line_obj = lv_line_create(screen);

		lv_line_set_points(line_obj, m_points.data(), m_points.size());
        lv_obj_add_style(line_obj, &style, 0);
	}

	// Clean up
	~clvgl_line() {
		lv_obj_delete(line_obj);
	}
};

#endif