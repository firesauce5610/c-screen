#include "main.h"
#include "liblvgl/misc/lv_area.h"
#include "liblvgl/misc/lv_color.h"
#include <cstdarg>
#include <cstring>  
#include "c-screen/api.hpp"
#include "liblvgl/misc/lv_types.h"
#include "liblvgl/widgets/tabview/lv_tabview.h"
#include <stdio.h>  // For standard file I/O (fopen, fgets, etc.)
#include <stdlib.h> // For 'atof' (string to float conversion)

lv_obj_t * auto_selector = NULL;
lv_obj_t * pid_screen = NULL;

lv_obj_t* fieldImg;

void btn_event_to_pid_screen(lv_event_t * e)
{
    lv_screen_load(pid_screen);
}

void btn_event_to_auto_selector(lv_event_t * e)
{
    lv_screen_load(auto_selector);
}

/**
 * Runs initialization code. This occurs as soon as the program is started.
 *
 * All other competition modes are blocked by initialize; it is recommended
 * to keep execution time for this mode under a few seconds.
 */

void auto_selectorManager() {
	/* Styles - Basically CSS ngl*/
	static lv_style_t linestyle;
	lv_style_init(&linestyle);
	styleUpdate(linestyle, "Line Color: ", 0xeb4d31);
	styleUpdate(linestyle, "Line Width: ", 8);
	styleUpdate(linestyle, "Line Rounded: ", true);

	static lv_style_t buttonStyle;
	lv_style_init(&buttonStyle);
	styleUpdate(buttonStyle, "Background Color: ", 0xeb4d31);
	styleUpdate(buttonStyle, "Border Width: ", 2);

	/* Styles - Basically CSS ngl*/

	/* Dropdown Object - Autonomous Dropdown, the main selecting thing */
	lv_obj_t * autonDropdown = createDropDown(
		LV_ALIGN_DEFAULT,
		10, // The X
		10, // The Y
		120,
		LV_SIZE_CONTENT,
		buttonStyle,
		auto_selector
	);

	lv_dropdown_set_options(
		autonDropdown,
		"TopRed\n"
		"BottomRed\n"
		"TopBlue\n"
		"BottomBlue\n"
		"Skills"
	);
	/* Dropdown Object - Autonomous Dropdown, the main selecting thing */
	
	/* Image - Field Image */
	LV_IMAGE_DECLARE(field);
	fieldImg = lv_image_create(auto_selector);
	lv_image_set_src(fieldImg, &field);
	lv_obj_set_size(fieldImg, 230, 230);
	lv_obj_align(fieldImg, LV_ALIGN_RIGHT_MID, 0, 0);
	/* Image - Field Image */

	/* Line Object - Line Seperator that divides image and menu stuff*/

	static clvgl_line seperator({{240, 0}, {240, 240}}, linestyle, auto_selector);
	/* Line Object - Line Seperator that divides image and menu stuff*/


	/* Button Object - PID Screen Button */

	lv_obj_t * pid_screen_button = createButton(
		LV_ALIGN_DEFAULT,
		10, // The X
		180, // The Y
		120,
		LV_SIZE_CONTENT,
		buttonStyle,
		auto_selector
	);

	lv_obj_t * pid_screen_button_label = addText(pid_screen_button, "PID Editor");
	lv_obj_add_event_cb(pid_screen_button, btn_event_to_pid_screen, LV_EVENT_CLICKED, NULL);
	/* Button Object - PID Screen Button */
}


// Just some variables for the pid_screenManager
static lv_obj_t * active_box = NULL;

static void textarea_event_handler(lv_event_t * e)
{
    lv_event_code_t code = lv_event_get_code(e);
    lv_obj_t * ta = lv_event_get_target_obj(e);

    // If the text area is clicked or focused...
    if(code == LV_EVENT_CLICKED || code == LV_EVENT_FOCUSED) {
        // ...set it as the new 'active_box'
        active_box = ta;
    }
}

static void keypad_event_handler(lv_event_t * e)
{
    lv_obj_t * obj = lv_event_get_target_obj(e);
    
    // Get the currently active text area from our static variable
    lv_obj_t * ta = active_box;

    // If no text area is active, do nothing
    if(ta == NULL) {
        return;
    }

    const char * txt = lv_buttonmatrix_get_button_text(obj, lv_buttonmatrix_get_selected_button(obj));

    // Handle the button press and apply it to the active text area
    if(lv_strcmp(txt, LV_SYMBOL_BACKSPACE) == 0) {
        lv_textarea_delete_char(ta);
    }
    else if(lv_strcmp(txt, LV_SYMBOL_NEW_LINE) == 0) {
        // Send an 'LV_EVENT_READY' event to the text area
        lv_obj_send_event(ta, LV_EVENT_READY, NULL);
    }
    else {
        // Add the button's text to the text area
        lv_textarea_add_text(ta, txt);
    }

}

void pid_screenManager() {
	/* Styles - Basically CSS ngl*/

	static lv_style_t backBStyle;
	lv_style_init(&backBStyle);
	styleUpdate(backBStyle, "Background Color: ", 0x5ac477);
	styleUpdate(backBStyle, "Border Width: ", 2);

	static lv_style_t saveBStyle;
	lv_style_init(&saveBStyle);
	styleUpdate(saveBStyle, "Background Color: ", 0x36d1a5);
	styleUpdate(saveBStyle, "Border Width: ", 2);

	/* Styles - Basically CSS ngl*/

	/* Textarea - The kP of PID*/
	lv_obj_t * kP_ta = lv_textarea_create(pid_screen);
    lv_textarea_set_one_line(kP_ta, true);
    lv_obj_align(kP_ta, LV_ALIGN_TOP_MID, 80, 10);
	lv_obj_set_width(kP_ta, 100);
    lv_obj_add_event_cb(kP_ta, textarea_event_handler, LV_EVENT_ALL, NULL);
	/* Textarea - The kP of PID*/

	/* Label - The label for kP textarea*/
 	lv_obj_t * kP_label  = addText(pid_screen, LV_ALIGN_TOP_MID, 10, 23, "kP = ");
	/* Label - The label for kP textarea*/

	/* Textarea - The kI of PID*/
	lv_obj_t * kI_ta = lv_textarea_create(pid_screen);
    lv_textarea_set_one_line(kI_ta, true);
    lv_obj_align(kI_ta, LV_ALIGN_TOP_MID, 80, 55);
	lv_obj_set_width(kI_ta, 100);
    lv_obj_add_event_cb(kI_ta, textarea_event_handler, LV_EVENT_ALL, NULL);
	/* Textarea - The kI of PID*/

	/* Label - The label for kI textarea*/
 	lv_obj_t * kI_label  = addText(pid_screen, LV_ALIGN_TOP_MID, 10, 68, "kI = ");
	/* Label - The label for kI textarea*/

	/* Textarea - The kD of PID*/
	lv_obj_t * kD_ta = lv_textarea_create(pid_screen);
    lv_textarea_set_one_line(kD_ta, true);
    lv_obj_align(kD_ta, LV_ALIGN_TOP_MID, 80, 100);
	lv_obj_set_width(kD_ta, 100);
    lv_obj_add_event_cb(kD_ta, textarea_event_handler, LV_EVENT_ALL, NULL);
	/* Textarea - The kD of PID*/

	/* Label - The label for kD textarea*/
 	lv_obj_t * kD_label  = addText(pid_screen, LV_ALIGN_TOP_MID, 10, 113, "kD = ");
	/* Label - The label for kD textarea*/

	active_box = kP_ta;
	lv_obj_add_state(active_box, LV_STATE_FOCUSED);

	/* Button Matrix Object - The main keypad*/
	static const char * keypad_map[] = {"1", "2", "3", "\n",
                                      "4", "5", "6", "\n",
                                      "7", "8", "9", "\n",
                                      LV_SYMBOL_BACKSPACE, "0", ".", ""
                                     };
	lv_obj_t * keypad = lv_buttonmatrix_create(pid_screen);
	lv_obj_set_size(keypad, 200, 150);
    lv_obj_align(keypad, LV_ALIGN_TOP_LEFT, 10, 10);
    lv_obj_add_event_cb(keypad, keypad_event_handler, LV_EVENT_VALUE_CHANGED, NULL);
    lv_obj_remove_flag(keypad, LV_OBJ_FLAG_CLICK_FOCUSABLE); /*To keep the text area focused on button clicks*/
    lv_buttonmatrix_set_map(keypad, keypad_map);
	/* Button Matrix Object - The main keypad*/

	/* Button Object - Auton Screen Button */
	lv_obj_t * back_button = createButton(
		LV_ALIGN_BOTTOM_LEFT,
		20, // The X
		-20, // The Y
		80,
		LV_SIZE_CONTENT,
		backBStyle,
		pid_screen
	);

	lv_obj_t * back_button_label = addText(back_button, "Back");
	lv_obj_add_event_cb(back_button, btn_event_to_auto_selector, LV_EVENT_CLICKED, NULL);
	/* Button Object - Auton Screen Button */

	/* Switch Object - Angular or Lateral PID Switch */
	lv_obj_t * pidSwitch;
	pidSwitch = lv_switch_create(pid_screen);
	lv_obj_align(pidSwitch, LV_ALIGN_BOTTOM_MID, 0, -20);
    lv_obj_add_state(pidSwitch, LV_STATE_CHECKED);
    //lv_obj_has_state(obj, LV_STATE_CHECKED) to get off or on

	lv_obj_t * angular_label = addText(pid_screen, LV_ALIGN_BOTTOM_MID, -60, -27, "Angular");
	lv_obj_t * lateral_label = addText(pid_screen, LV_ALIGN_BOTTOM_MID, 60, -27, "Lateral");

	/* Switch Object - Angular or Lateral PID Switch */

	/* Button Object - Save Screen Button */
	lv_obj_t * save_button = createButton(
		LV_ALIGN_BOTTOM_RIGHT,
		-20, // The X
		-20, // The Y
		80,
		LV_SIZE_CONTENT,
		saveBStyle,
		pid_screen
	);

	lv_obj_t * save_button_label = addText(save_button, "Save");
	lv_obj_add_event_cb(save_button, btn_event_to_auto_selector, LV_EVENT_CLICKED, NULL);
	/* Button Object - Save Screen Button */

}

void initialize() {

	auto_selector = lv_obj_create(NULL);
	pid_screen = lv_obj_create(NULL);
	
	auto_selectorManager();
	pid_screenManager();

	// Starts the auto selector by loading the correct screen
	lv_screen_load(auto_selector);
	
	
}

/**
 * Runs while the robot is in the disabled state of Field Management System or
 * the VEX Competition Switch, following either autonomous or opcontrol. When
 * the robot is enabled, this task will exit.
 */
void disabled() {}

/**
 * Runs after initialize(), and before autonomous when connected to the Field
 * Management System or the VEX Competition Switch. This is intended for
 * competition-specific initialization routines, such as an autonomous selector
 * on the LCD.
 *
 * This task will exit when the robot is enabled and autonomous or opcontrol
 * starts.
 */
void competition_initialize() {}

/**
 * Runs the user autonomous code. This function will be started in its own task
 * with the default priority and stack size whenever the robot is enabled via
 * the Field Management System or the VEX Competition Switch in the autonomous
 * mode. Alternatively, this function may be called in initialize or opcontrol
 * for non-competition testing purposes.
 *
 * If the robot is disabled or communications is lost, the autonomous task
 * will be stopped. Re-enabling the robot will restart the task, not re-start it
 * from where it left off.
 */
void autonomous() {}

/**
 * Runs the operator control code. This function will be started in its own task
 * with the default priority and stack size whenever the robot is enabled via
 * the Field Management System or the VEX Competition Switch in the operator
 * control mode.
 *
 * If no competition control is connected, this function will run immediately
 * following initialize().
 *
 * If the robot is disabled or communications is lost, the
 * operator control task will be stopped. Re-enabling the robot will restart the
 * task, not resume it from where it left off.
 */
void opcontrol() {
	pros::Controller master(pros::E_CONTROLLER_MASTER);
	pros::MotorGroup left_mg({1, -2, 3});    // Creates a motor group with forwards ports 1 & 3 and reversed port 2
	pros::MotorGroup right_mg({-4, 5, -6});  // Creates a motor group with forwards port 5 and reversed ports 4 & 6


	while (true) {
		// Arcade control scheme
		int dir = master.get_analog(ANALOG_LEFT_Y);    // Gets amount forward/backward from left joystick
		int turn = master.get_analog(ANALOG_RIGHT_X);  // Gets the turn left/right from right joystick
		left_mg.move(dir - turn);                      // Sets left motor voltage
		right_mg.move(dir + turn);                     // Sets right motor voltage
		pros::delay(20);                               // Run for 20 ms then update
	}
}