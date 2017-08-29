#!/bin/sh


#unset SERIAL_ANALYZE_SUPPORT
if [ $# -eq 1 ]; then
    export SERIAL_ANALYZE_SUPPORT=1
    echo "support SERIAL_ANALYZE!"
else

    export SERIAL_ANALYZE_SUPPORT=0
    echo "not support SERIAL_ANALYZE!(default)"
fi

export TOP_DIR=`pwd`
export HLP_ENV=ok

