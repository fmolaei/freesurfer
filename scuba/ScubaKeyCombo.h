/**
 * @file  ScubaKeyCombo.h
 * @brief Encapsulates keypress combinations
 *
 * This is a class to encapsulate the idea of key combinations, or
 * keypresses to trigger events. These are used in a few places:
 *
 *   The main interface widget (e.g. ToglFrame) transforms keypress
 *   events into ScubaKeyCombo subclasses from their native widget
 *   type.

 *   Other widgets that check for key combos in event response
 *   functions can simply match input ScubaKeyCombos against
 *   ScubaKeyCombos stored in preferences. For example, ScubaView
 *   grabs the string pref for the MoveViewIn key, makes a
 *   ScubaKeyCombo out of it, and checks it against the current key
 *   from the InputState.
 *
 *   Preference dialog boxes read input from the user, create a
 *   ScubaKeyCombo from it, and use the ToString function to generate
 *   the string version to be stored in ScubaGlobalPreferences.
 *
 *   Each widget type should have a subclass ScubaKeyCombo
 *   (e.g. TclScubaKeyCombo) that knows how to parse input strings
 *   from that widget framework. A corresponding ScubaKeyComboFactory
 *   should be made to make those kinds of ScubaKeyCombo
 *   subclasses. The main function, knowing what kind of widget
 *   framework is being used, calls SetFactory with that subclass
 *   factory. Then, all other classes use ScubaKeyCombo::MakeKeyCombo
 *   to make their framework-specific ScubaKeyCombos.
 *
 */
/*
 * Original Author: Kevin Teich
 * CVS Revision Info:
 *    $Author: nicks $
 *    $Date: 2011/03/02 00:04:37 $
 *    $Revision: 1.8 $
 *
 * Copyright © 2011 The General Hospital Corporation (Boston, MA) "MGH"
 *
 * Terms and conditions for use, reproduction, distribution and contribution
 * are found in the 'FreeSurfer Software License Agreement' contained
 * in the file 'LICENSE' found in the FreeSurfer distribution, and here:
 *
 * https://surfer.nmr.mgh.harvard.edu/fswiki/FreeSurferSoftwareLicense
 *
 * Reporting: freesurfer@nmr.mgh.harvard.edu
 *
 */


#ifndef ScubaKeyCombo_h
#define ScubaKeyCombo_h

#include <string>
#include "DebugReporter.h"

class ScubaKeyComboFactory;

class ScubaKeyCombo : public DebugReporter {

  friend class ScubaKeyComboFactory;

public:

  virtual ~ScubaKeyCombo() {};

  // Static functions for setting the current factory and making a
  // KeyCombo with that factory.
  static void SetFactory ( ScubaKeyComboFactory* iFactory );
  static ScubaKeyCombo* MakeKeyCombo ();
  
  // Set ourselves from a string. This is overrideable by the subclass
  // to take the string representation of a key and convert it to our
  // generic type here.
  virtual void SetFromString ( std::string const& isKey );

  // Return a human readable string for this combo.
  std::string ToString () const;

  // Comparators.
  bool IsSameAs ( ScubaKeyCombo const& iCombo ) const;
  bool IsSameAs ( ScubaKeyCombo const* iCombo ) const;

  // Accessors.
  int GetKeyCode () const;
  bool IsShiftKeyDown () const;
  bool IsAltKeyDown () const;
  bool IsMetaKeyDown () const;
  bool IsControlKeyDown () const;

  // Settors
  void CopyFrom ( ScubaKeyCombo const& iKey );
  void CopyFrom ( ScubaKeyCombo const* iKey );
  void SetKeyCode ( int iKey );
  void SetShiftKeyDown ( bool isDown );
  void SetAltKeyDown ( bool isDown );
  void SetMetaKeyDown ( bool isDown );
  void SetControlKeyDown ( bool isDown );

  // This is straight out of Qt. We use their key codes for simplicity
  // with the QtScubaKeyCombo class.
  enum Key {
    Key_Escape = 0x1000,
    Key_Tab = 0x1001,
    Key_Backtab = 0x1002, Key_BackTab = Key_Backtab,
    Key_Backspace = 0x1003, Key_BackSpace = Key_Backspace,
    Key_Return = 0x1004,
    Key_Enter = 0x1005,
    Key_Insert = 0x1006,
    Key_Delete = 0x1007,
    Key_Pause = 0x1008,
    Key_Print = 0x1009,
    Key_SysReq = 0x100a,
    Key_Clear = 0x100b,
    Key_Home = 0x1010,
    Key_End = 0x1011,
    Key_Left = 0x1012,
    Key_Up = 0x1013,
    Key_Right = 0x1014,
    Key_Down = 0x1015,
    Key_Prior = 0x1016, Key_PageUp = Key_Prior,
    Key_Next = 0x1017, Key_PageDown = Key_Next,
    Key_Shift = 0x1020,
    Key_Control = 0x1021,
    Key_Meta = 0x1022,
    Key_Alt = 0x1023,
    Key_CapsLock = 0x1024,
    Key_NumLock = 0x1025,
    Key_ScrollLock = 0x1026,
    Key_F1 = 0x1030,
    Key_F2 = 0x1031,
    Key_F3 = 0x1032,
    Key_F4 = 0x1033,
    Key_F5 = 0x1034,
    Key_F6 = 0x1035,
    Key_F7 = 0x1036,
    Key_F8 = 0x1037,
    Key_F9 = 0x1038,
    Key_F10 = 0x1039,
    Key_F11 = 0x103a,
    Key_F12 = 0x103b,
    Key_F13 = 0x103c,
    Key_F14 = 0x103d,
    Key_F15 = 0x103e,
    Key_F16 = 0x103f,
    Key_F17 = 0x1040,
    Key_F18 = 0x1041,
    Key_F19 = 0x1042,
    Key_F20 = 0x1043,
    Key_F21 = 0x1044,
    Key_F22 = 0x1045,
    Key_F23 = 0x1046,
    Key_F24 = 0x1047,
    Key_F25 = 0x1048,
    Key_F26 = 0x1049,
    Key_F27 = 0x104a,
    Key_F28 = 0x104b,
    Key_F29 = 0x104c,
    Key_F30 = 0x104d,
    Key_F31 = 0x104e,
    Key_F32 = 0x104f,
    Key_F33 = 0x1050,
    Key_F34 = 0x1051,
    Key_F35 = 0x1052,
    Key_Super_L = 0x1053,
    Key_Super_R = 0x1054,
    Key_Menu = 0x1055,
    Key_Hyper_L = 0x1056,
    Key_Hyper_R = 0x1057,
    Key_Help = 0x1058,
    Key_Direction_L = 0x1059,
    Key_Direction_R = 0x1060,
    Key_Space = 0x20,
    Key_Any = Key_Space,
    Key_Exclam = 0x21,
    Key_QuoteDbl = 0x22,
    Key_NumberSign = 0x23,
    Key_Dollar = 0x24,
    Key_Percent = 0x25,
    Key_Ampersand = 0x26,
    Key_Apostrophe = 0x27,
    Key_ParenLeft = 0x28,
    Key_ParenRight = 0x29,
    Key_Asterisk = 0x2a,
    Key_Plus = 0x2b,
    Key_Comma = 0x2c,
    Key_Minus = 0x2d,
    Key_Period = 0x2e,
    Key_Slash = 0x2f,
    Key_0 = 0x30,
    Key_1 = 0x31,
    Key_2 = 0x32,
    Key_3 = 0x33,
    Key_4 = 0x34,
    Key_5 = 0x35,
    Key_6 = 0x36,
    Key_7 = 0x37,
    Key_8 = 0x38,
    Key_9 = 0x39,
    Key_Colon = 0x3a,
    Key_Semicolon = 0x3b,
    Key_Less = 0x3c,
    Key_Equal = 0x3d,
    Key_Greater = 0x3e,
    Key_Question = 0x3f,
    Key_At = 0x40,
    Key_A = 0x41,
    Key_B = 0x42,
    Key_C = 0x43,
    Key_D = 0x44,
    Key_E = 0x45,
    Key_F = 0x46,
    Key_G = 0x47,
    Key_H = 0x48,
    Key_I = 0x49,
    Key_J = 0x4a,
    Key_K = 0x4b,
    Key_L = 0x4c,
    Key_M = 0x4d,
    Key_N = 0x4e,
    Key_O = 0x4f,
    Key_P = 0x50,
    Key_Q = 0x51,
    Key_R = 0x52,
    Key_S = 0x53,
    Key_T = 0x54,
    Key_U = 0x55,
    Key_V = 0x56,
    Key_W = 0x57,
    Key_X = 0x58,
    Key_Y = 0x59,
    Key_Z = 0x5a,
    Key_BracketLeft = 0x5b,
    Key_Backslash = 0x5c,
    Key_BracketRight = 0x5d,
    Key_AsciiCircum = 0x5e,
    Key_Underscore = 0x5f,
    Key_QuoteLeft = 0x60,
    Key_BraceLeft = 0x7b,
    Key_Bar = 0x7c,
    Key_BraceRight = 0x7d,
    Key_AsciiTilde = 0x7e,

    Key_unknown = 0xffff
  };

protected:
  ScubaKeyCombo ();

  // Key info.
  int mKeyCode;
  bool mbShift, mbAlt, mbMeta, mbControl;

  // Our static factory.
  static ScubaKeyComboFactory* mFactory;
};

// A static factory class that we can subclass to create our specific
// kind of key.
class ScubaKeyComboFactory {
public:
  virtual ~ScubaKeyComboFactory() {};

  // Make the key type.
  virtual ScubaKeyCombo* MakeKeyCombo() const {
    return new ScubaKeyCombo();
  }
};

std::ostream& operator << ( std::ostream&, ScubaKeyCombo const& iKey  );

#endif
