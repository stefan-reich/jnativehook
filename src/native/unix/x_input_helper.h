/* JNativeHook: Global keyboard and mouse hooking for Java.
 * Copyright (C) 2006-2013 Alexander Barker.  All Rights Received.
 * http://code.google.com/p/jnativehook/
 *
 * JNativeHook is free software: you can redistribute it and/or modify
 * it under the terms of the GNU Lesser General Public License as published
 * by the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * JNativeHook is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU Lesser General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */

#ifndef _included_x_input_helpers
#define _included_x_input_helpers

#include <stdint.h>
#include <X11/Xlib.h>

/* Converts an X11 key code to the appropriate keyboard scan code.
 */
extern uint16_t keycode_to_scancode(KeyCode keycode);

/* Converts a keyboard scan code to the appropriate X11 key code.
 */
extern KeyCode scancode_to_keycode(uint16_t scancode);

/* Converts an X11 key code and event mask to the appropriate X11 key symbol.
 * This functions in much the same way as XKeycodeToKeysym() but allows for a
 * faster and more flexible lookup.
 */
extern KeySym keycode_to_keysym(KeyCode keycode, unsigned int modifier_mask);

/* Initialize items required for KeyCodeToKeySym() and KeySymToUnicode()
 * functionality.  This method is called by OnLibraryLoad() and may need to be
 * called in combination with UnloadInputHelper() if the native keyboard layout
 * is changed.
 */
extern void load_input_helper();

/* De-initialize items required for KeyCodeToKeySym() and KeySymToUnicode()
 * functionality.  This method is called by OnLibraryUnload() and may need to be
 * called in combination with LoadInputHelper() if the native keyboard layout
 * is changed.
 */
extern void unload_input_helper();

#endif
