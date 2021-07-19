#!/bin/sh  

################################################################################
# zytool_multi_zld.sh
#
# To generate multiple zld.bin for different project with same ras.bin.
# This script will call by \target\linux\brcm963xx\image\Makefile.
#
# PS.This file need to be created at sub-target folder for each project.
################################################################################

# External variable
# INPUT $1 : the path of zytool
# INPUT $2 : the path of zld.bin
# INPUT $3 : board chip (ex.63138, 63268)
# INPUT $4 : endianness (ex.big, little)
ZYTOOL=$1/zytool
ZLD_BIN=$2/zld.bin

# Internal variable
# Declare projects those want to use the same ras.bin :
# (here should be declared case by case depends on project requirement)
board_id_list=("VMG8825-B60B" "VMG8825-B50C" "VMG8825-B60C" "AM3100-B0")
product_name_list=("VMG8825-B60B" "VMG8825-B50C" "VMG8825-B60C" "AM3100-B0")
voice_board_id_list=("LE9642_ZSI_BB" "LE9642_ZSI_BB" "LE9642_ZSI_BB" "NOSLIC")
mrd_feature_bits_list=("0103030200000000" "0103030100000000" "0103030200000000" "0000000000000000")

# Main
count1=${#board_id_list[*]}
count2=${#product_name_list[*]}
count3=${#voice_board_id_list[*]}
count4=${#mrd_feature_bits_list[*]}
i=0

if [ $3 -eq 63138 ] || [ $3 -eq 63148 ]
then 
    nvram_offset=10000
else
    nvram_offset=0
fi

if [ $count1 -eq $count2 -a $count2 -eq $count3 -a $count3 -eq $count4 ]
then
    while [ $i -lt $count1 ]
    do
        echo "Generate bootloader for ${board_id_list[$i]} :"
        cp $ZLD_BIN zld_${board_id_list[$i]}.bin
        $ZYTOOL -b ${board_id_list[$i]} -n ${product_name_list[$i]} -c ${voice_board_id_list[$i]} -r ${mrd_feature_bits_list[$i]} -o $nvram_offset -e $4 -f zld_${board_id_list[$i]}.bin
        cp zld_${board_id_list[$i]}.bin $2
        rm zld_${board_id_list[$i]}.bin
        let i=$i+1
        echo "=================================================="
    done
fi
