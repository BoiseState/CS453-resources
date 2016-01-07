#!/bin/bash
original_output="`../simple-malloc/simple-malloc-test v`";
refactored_output="`./simple-malloc-test v`";
diff_output=`diff <(echo "$refactored_output") <(echo "$original_output")`;
if [ -n "$diff_output" ]
then
	echo "Refactor broke something";
fi
