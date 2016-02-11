#!/bin/bash

# To use:
# =====================================================================
# 1. Copy this file into your project directory.
# 2. Change file permissions so this is an executable.
#    chmod +x format.sh
# 3. Execute this script in your project directory to format all files
#    ./format.sh

astyle --style=kr --indent=spaces --convert-tabs --recursive "./*.cpp"
astyle --style=kr --indent=spaces --convert-tabs --recursive "./*.h"
astyle --style=kr --indent=spaces --convert-tabs --recursive "./*.c"
