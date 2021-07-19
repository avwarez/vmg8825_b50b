#!/bin/sh

echo Applying Speed Service License

cat /etc/spdsvc_license.txt > /proc/spdsvc/license
