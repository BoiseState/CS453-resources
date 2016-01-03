#!/bin/bash

astyle --style=kr --indent=spaces --convert-tabs --recursive "./*.cpp"
astyle --style=kr --indent=spaces --convert-tabs --recursive "./*.h" 
astyle --style=kr --indent=spaces --convert-tabs --recursive "./*.c" 
