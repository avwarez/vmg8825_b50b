#!/bin/sh

echo ">>>>> Creating static device nodes <<<<<"

#Create standard character devices
mknod /dev/kmem c 1 2
mknod /dev/tty0 c 4 0
mknod /dev/tty1 c 4 1
## __zy_bsp__ >>>
## 502L04:
## mknod /dev/ttyH0 c 4 66
## 502L05:
mknod /dev/ttyH0 c 4 70
## __zy_bsp__ <<<
mknod /dev/ptm c 128 1
mknod /dev/printer0 c 180 0

# Create Broadcom Proprietary devices. Major numbers must fall in the range 256-512
mknod /dev/pwrmngt c        300 0
mknod /dev/bcmfap c         301 0
mknod /dev/fcache c         302 0
mknod /dev/ingqos c         303 0
mknod /dev/bpm c            304 0
mknod /dev/bcmarl c         305 0
mknod /dev/chipinfo c       306 0
mknod /dev/bcm_user_tod c   307 0
#mknod /dev/tms c            308 0
# The original tms define is 308, changing script avoid have multiple ncomm and tmsctl version maintenance.
mknod /dev/tms c            3008 0
mknod /dev/pktrunner c      309 0
mknod /dev/otp c            310 0
mknod /dev/ext_bonding c    311 0
mknod /dev/fbond c          312 0
mknod /dev/bcmepon c        313 0
mknod /dev/laser_dev c      314 0
mknod /dev/bcmomcipm c      316 0
mknod /dev/bcm_user_ploam c 317 0
mknod /dev/bcm_omci c       318 0
mknod /dev/bcm_ploam c      319 0
mknod /dev/opticaldetect c  320 0
mknod /dev/bdmf_shell c     321 0
mknod /dev/rgs_logger c     322 0
mknod /dev/bcmvlan c        323 0
mknod /dev/buzzz c          324 0
mknod /dev/sysperf c        325 0
mknod /dev/gmac c           326 0
mknod /dev/bcmtm c          327 0
mknod /dev/spdsvc c         328 0
mknod /dev/bcmxtmcfg0 c     329 0
mknod /dev/bcmprof c        330 0
mknod /dev/bcm c            331 0
mknod /dev/bcmatm0 c        332 0
mknod /dev/bcmadsl0 c       333 0
mknod /dev/bcmadsl1 c       333 1
chmod 666 /dev/bcmadsl*
#mknod /dev/detector c      334 0 is created by dpiinit.sh
#node /dev/bcmrdpa c        337 0 is created by rdpa_cmd.ko
mknod /dev/blog c           338 0
mknod /dev/archer c         339 0
mknod /dev/wantypedetect c  340 0
mknod /dev/sotp c           341 0
mknod /dev/slicslac c       350 1
mknod /dev/dect c           351 0
mknod /dev/dectdbg c        351 1
mknod /dev/ac97 c           360 0
# ADD NEW PROPIETARY DEVICE NODES ABOVE THIS LINE -- ALL PROPRIETARY MAJOR NUMBERS MUST BE IN THE RANGE 300-512

# All NEW OPENSOURCE DRIVERS SHOULD CREATE SYSFS CLASS/DEVICE
# ENTRIES SO THAT MDEV CAN DYNAMICALLY CREATE DEVICE NODES 

# USB Serial
mknod /dev/ttyUSB0 c 188 0
mknod /dev/ttyUSB1 c 188 1
mknod /dev/ttyUSB2 c 188 2
mknod /dev/ttyUSB3 c 188 3
mknod /dev/ttyUSB4 c 188 4
mknod /dev/ttyUSB5 c 188 5
mknod /dev/ttyUSB6 c 188 6
mknod /dev/ttyUSB7 c 188 7
mknod /dev/ttyUSB8 c 188 8
mknod /dev/ttyUSB9 c 188 9

# USB CDC_WDM
mknod /dev/cdc-wdm0 c 180 176
mknod /dev/cdc-wdm1 c 180 177
mknod /dev/cdc-wdm2 c 180 178

# USB CDC-ACM
mknod /dev/ttyACM0 c 166 0
mknod /dev/ttyACM1 c 166 1
mknod /dev/ttyACM2 c 166 2
mknod /dev/ttyACM3 c 166 3
mknod /dev/ttyACM4 c 166 4
mknod /dev/ttyACM5 c 166 5
mknod /dev/ttyACM6 c 166 6
mknod /dev/ttyACM7 c 166 7
mknod /dev/ttyACM8 c 166 8
mknod /dev/ttyACM9 c 166 9

# USB HSO
mknod /dev/ttyHS0 c 254 0
mknod /dev/ttyHS1 c 254 1
mknod /dev/ttyHS2 c 254 2
mknod /dev/ttyHS3 c 254 3
mknod /dev/ttyHS4 c 254 4
mknod /dev/ttyHS5 c 254 5
mknod /dev/ttyHS6 c 254 6
mknod /dev/ttyHS7 c 254 7
mknod /dev/ttyHS8 c 254 8
mknod /dev/ttyHS9 c 254 9

# LTE Qualcomm D19Q1
mknod /dev/qcqmi0 c 249 0
mknod /dev/qcqmi1 c 249 1
mknod /dev/qcqmi2 c 249 2

# WAH1604
mknod /dev/qcqmi5 c 254 0

