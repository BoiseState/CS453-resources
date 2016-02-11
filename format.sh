#!/bin/bash

# =====================================================================
# This script uses the Artistic Style source code formatter.
# (http://astyle.sourceforge.net/)
# =====================================================================
# If you are running on your own system, you may need to install the
# astyle package. On Fedora, use `sudo dnf astyle`
#
# =====================================================================
# To use this script:
# =====================================================================
# 1. Copy this file into your project directory.
# 2. Change file permissions so this is an executable.
#    chmod +x format.sh
# 3. Execute this script in your project directory to format all files
#    ./format.sh
# =====================================================================

astyle --style=kr --indent=spaces --convert-tabs --recursive "./*.cpp"
astyle --style=kr --indent=spaces --convert-tabs --recursive "./*.h"
astyle --style=kr --indent=spaces --convert-tabs --recursive "./*.c"
