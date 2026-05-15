# Kumquat -- traditional, usable into the future

Kumquat is a desktop environment (DE) for GNU/Linux and other UNIX-like systems.
It is inspired by the look-and-feel of [GNOME](https://www.gnome.org) 2 and
[MATE](https://mate-desktop.org).  However, it is written entirely from scratch,
using [Qt](https://www.qt.io) instead of [GTK](https://gtk.org) and the
GNOME libraries.  By writing it from scratch, it allows Kumquat to move forward
and hopefully support newer technologies such as
[Wayland](https://wayland.freedesktop.org/), without being burdened by code rot,
backward compatibility issues, or disagreements with the GNOME developers'
choices and project direction.

Overall, the project is licensed under the MIT License, intentionally chosen to
restrict users' and developers' freedoms as little as absolutely possible.
**However, please see the section entitled 'LICENSING'.**

## kumquat-core

This is a collection of library routines and other support functionality shared
by many or all of the applications and other programs comprising Kumquat.
Additionally, this repository also hosts `kumquat-about`, a simple About dialog
program revealing Kumquat's version information and other information regarding
Kumquat; and `kumquat-colors`, a simple color chooser application similar to
`mate-color-select` from the MATE Desktop project.

---

## BUILD INSTRUCTIONS

Kumquat currently requires:

 - Qt 6 -- specifically the following modules:
  * Core
  * Gui
  * Widgets

Kumquat uses Meson as the build system.  In a nutshell:

```
$ mkdir .build
$ cd .build
$ meson setup ..
$ ninja
$ sudo ninja install
```

---

## LICENSING

Kumquat and all of its components are licensed under the MIT License, unless
explicitly noted otherwise.  However, Kumquat relies on other libraries, most
notably Qt, which is LGPL-licensed.  Only binary distributions of Kumquat are
affected, though, and even then only if they are statically linked to Qt;
dynamic linking to Qt is almost always the default, and is permissible,
provided that an appropriate notice is included with any binary distributions.
Furthermore, most GNU/Linux distributors should be completely unaffected by
this licensing issue, since they distribute Qt as one or more entirely
separate packages upon which Kumquat depends.

Please see
[Qt's open source licensing terms](https://www.qt.io/development/open-source-lgpl-obligations)
for details regarding Qt's licensing.  The LGPL version 3 (and its dependent
license, the GPL version 3) are available in the file `LICENSE.LGPL`.  The LGPL
is also available directly from
[the GNU website itself](https://www.gnu.org/licenses/lgpl-3.0.en.html).

Kumquat is inspired by GNOME and MATE; it does not use any code directly from
either project.  As such no licensing issues arise via that route.
