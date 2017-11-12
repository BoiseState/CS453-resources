#!/bin/bash

case "$1" in
        start)
            echo "in start..."
            ;;
        stop)
            echo "in stop..."
            ;; 
        status)
            echo "in status..."
            ;;
        restart)
            echo "in restart"
            ;;         
        *)
            echo $"Usage: $0 {start|stop|restart|status}"
            exit 1
 
esac

