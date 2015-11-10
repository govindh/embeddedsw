##############################################################################
#
# Copyright (C) 2015 Xilinx, Inc. All rights reserved.
#
# Permission is hereby granted, free of charge, to any person obtaining a copy
# of this software and associated documentation files (the "Software"),to deal
# in the Software without restriction, including without limitation the rights
# to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
# copies of the Software, and to permit persons to whom the Software is
# furnished to do so, subject to the following conditions:
#
# The above copyright notice and this permission notice shall be included in
# all copies or substantial portions of the Software.
#
# Use of the Software is limited solely to applications:
# (a) running on a Xilinx device, or
# (b) that interact with a Xilinx device through a bus or interconnect.
#
# THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
# IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
# FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL
# XILINX BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER
# IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM, OUT OF
# OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
# SOFTWARE.
#
# Except as contained in this notice, the name of the Xilinx shall not be used
# in advertising or otherwise to promote the sale, use or other dealings in
# this Software without prior written authorization from Xilinx.
###############################################################################

proc generate {drv_handle} {
    xdefine_include_file $drv_handle "xparameters.h" "XV_mix" "NUM_INSTANCES" "DEVICE_ID" "C_S_AXI_CTRL_BASEADDR" "C_S_AXI_CTRL_HIGHADDR" "SAMPLES_PER_CLOCK" "MAX_COLS" "MAX_ROWS" "MAX_DATA_WIDTH"  "NR_LAYERS" "LOGO_LAYER" "MAX_LOGO_COLS" "MAX_LOGO_ROWS" "LAYER1_ALPHA" "LAYER2_ALPHA" "LAYER3_ALPHA" "LAYER4_ALPHA" "LAYER5_ALPHA" "LAYER6_ALPHA" "LAYER7_ALPHA" "LAYER1_UPSAMPLE" "LAYER2_UPSAMPLE" "LAYER3_UPSAMPLE" "LAYER4_UPSAMPLE" "LAYER5_UPSAMPLE" "LAYER6_UPSAMPLE" "LAYER7_UPSAMPLE" "LAYER1_MAX_WIDTH" "LAYER2_MAX_WIDTH" "LAYER3_MAX_WIDTH" "LAYER4_MAX_WIDTH" "LAYER5_MAX_WIDTH" "LAYER6_MAX_WIDTH" "LAYER7_MAX_WIDTH"

    ::hsi::utils::define_config_file $drv_handle "xv_mix_g.c" "XV_mix" "DEVICE_ID" "C_S_AXI_CTRL_BASEADDR" "SAMPLES_PER_CLOCK" "MAX_COLS" "MAX_ROWS" "MAX_DATA_WIDTH" "NR_LAYERS" "LOGO_LAYER" 		"MAX_LOGO_COLS" "MAX_LOGO_ROWS" "LAYER1_ALPHA" "LAYER2_ALPHA" "LAYER3_ALPHA" "LAYER4_ALPHA" "LAYER5_ALPHA" "LAYER6_ALPHA" "LAYER7_ALPHA" "LAYER1_UPSAMPLE" "LAYER2_UPSAMPLE" "LAYER3_UPSAMPLE" "LAYER4_UPSAMPLE" "LAYER5_UPSAMPLE" "LAYER6_UPSAMPLE" "LAYER7_UPSAMPLE" "LAYER1_MAX_WIDTH" "LAYER2_MAX_WIDTH" "LAYER3_MAX_WIDTH" "LAYER4_MAX_WIDTH" "LAYER5_MAX_WIDTH" "LAYER6_MAX_WIDTH" "LAYER7_MAX_WIDTH"

    xdefine_canonical_xpars $drv_handle "xparameters.h" "XV_mix" "DEVICE_ID" "C_S_AXI_CTRL_BASEADDR" "C_S_AXI_CTRL_HIGHADDR" "SAMPLES_PER_CLOCK" "MAX_COLS" "MAX_ROWS" "MAX_DATA_WIDTH"  "NR_LAYERS" "LOGO_LAYER" "MAX_LOGO_COLS" "MAX_LOGO_ROWS" "LAYER1_ALPHA" "LAYER2_ALPHA" "LAYER3_ALPHA" "LAYER4_ALPHA" "LAYER5_ALPHA" "LAYER6_ALPHA" "LAYER7_ALPHA" "LAYER1_UPSAMPLE" "LAYER2_UPSAMPLE" "LAYER3_UPSAMPLE" "LAYER4_UPSAMPLE" "LAYER5_UPSAMPLE" "LAYER6_UPSAMPLE" "LAYER7_UPSAMPLE" "LAYER1_MAX_WIDTH" "LAYER2_MAX_WIDTH" "LAYER3_MAX_WIDTH" "LAYER4_MAX_WIDTH" "LAYER5_MAX_WIDTH" "LAYER6_MAX_WIDTH" "LAYER7_MAX_WIDTH"

}

#
# Given a list of arguments, define them all in an include file.
# Handles IP model/user parameters, as well as the special parameters NUM_INSTANCES,
# DEVICE_ID
# Will not work for a processor.
#
proc xdefine_include_file {drv_handle file_name drv_string args} {
    set list_alpha {LAYER1_ALPHA LAYER2_ALPHA LAYER3_ALPHA LAYER4_ALPHA LAYER5_ALPHA LAYER6_ALPHA LAYER7_ALPHA}
    set list_upsmpl {LAYER1_UPSAMPLE LAYER2_UPSAMPLE LAYER3_UPSAMPLE LAYER4_UPSAMPLE LAYER5_UPSAMPLE LAYER6_UPSAMPLE LAYER7_UPSAMPLE}

    set args [::hsi::utils::get_exact_arg_list $args]
    # Open include file
    set file_handle [::hsi::utils::open_include_file $file_name]

    # Get all peripherals connected to this driver
    set periphs [::hsi::utils::get_common_driver_ips $drv_handle]

    # Handle special cases
    set arg "NUM_INSTANCES"
    set posn [lsearch -exact $args $arg]
    if {$posn > -1} {
        puts $file_handle "/* Definitions for driver [string toupper [common::get_property name $drv_handle]] */"
        # Define NUM_INSTANCES
        puts $file_handle "#define [::hsi::utils::get_driver_param_name $drv_string $arg] [llength $periphs]"
        set args [lreplace $args $posn $posn]
    }

    # Check if it is a driver parameter
    lappend newargs
    foreach arg $args {
        set value [common::get_property CONFIG.$arg $drv_handle]
        if {[llength $value] == 0} {
            lappend newargs $arg
        } else {
            puts $file_handle "#define [::hsi::utils::get_driver_param_name $drv_string $arg] [common::get_property $arg $drv_handle]"
        }
    }
    set args $newargs

    # Print all parameters for all peripherals
    set device_id 0
    foreach periph $periphs {
        puts $file_handle ""
        puts $file_handle "/* Definitions for peripheral [string toupper [common::get_property NAME $periph]] */"
        foreach arg $args {
            if {[string compare -nocase "DEVICE_ID" $arg] == 0} {
                set value $device_id
                incr device_id
            } else {
                set value [common::get_property CONFIG.$arg $periph]
            }
            if {[llength $value] == 0} {
                set value 0
            }
            set value [::hsi::utils::format_addr_string $value $arg]

            if {[string compare -nocase "LOGO_LAYER" $arg] == 0} {
                if {[string compare -nocase "true" "$value"] == 0} {
                    set value 1
                } else {
                    set value 0
                }
                puts $file_handle "#define [::hsi::utils::get_ip_param_name $periph $arg] $value"
            } elseif {[lsearch -nocase $list_alpha $arg] >= 0} {
                if {[string compare -nocase "true" "$value"] == 0} {
                    set value 1
                } else {
                    set value 0
                }
                puts $file_handle "#define [::hsi::utils::get_ip_param_name $periph $arg] $value"
            } elseif {[lsearch -nocase $list_upsmpl $arg] >= 0} {
                if {[string compare -nocase "true" "$value"] == 0} {
                    set value 1
                } else {
                    set value 0
                }
                puts $file_handle "#define [::hsi::utils::get_ip_param_name $periph $arg] $value"
            } else {
                puts $file_handle "#define [::hsi::utils::get_ip_param_name $periph $arg] $value"
            }
        }
        puts $file_handle ""
    }
    puts $file_handle "\n/******************************************************************/\n"
    close $file_handle
}

#
# define_canonical_xpars - Used to print out canonical defines for a driver.
# Given a list of arguments, define each as a canonical constant name, using
# the driver name, in an include file.
#
proc xdefine_canonical_xpars {drv_handle file_name drv_string args} {
    set list_alpha {LAYER1_ALPHA LAYER2_ALPHA LAYER3_ALPHA LAYER4_ALPHA LAYER5_ALPHA LAYER6_ALPHA LAYER7_ALPHA}
    set list_upsmpl {LAYER1_UPSAMPLE LAYER2_UPSAMPLE LAYER3_UPSAMPLE LAYER4_UPSAMPLE LAYER5_UPSAMPLE LAYER6_UPSAMPLE LAYER7_UPSAMPLE}

    set args [::hsi::utils::get_exact_arg_list $args]
   # Open include file
   set file_handle [::hsi::utils::open_include_file $file_name]

   # Get all the peripherals connected to this driver
   set periphs [::hsi::utils::get_common_driver_ips $drv_handle]

   # Get the names of all the peripherals connected to this driver
   foreach periph $periphs {
       set peripheral_name [string toupper [common::get_property NAME $periph]]
       lappend peripherals $peripheral_name
   }

   # Get possible canonical names for all the peripherals connected to this
   # driver
   set device_id 0
   foreach periph $periphs {
       set canonical_name [string toupper [format "%s_%s" $drv_string $device_id]]
       lappend canonicals $canonical_name

       # Create a list of IDs of the peripherals whose hardware instance name
       # doesn't match the canonical name. These IDs can be used later to
       # generate canonical definitions
       if { [lsearch $peripherals $canonical_name] < 0 } {
           lappend indices $device_id
       }
       incr device_id
   }

   set i 0
   foreach periph $periphs {
       set periph_name [string toupper [common::get_property NAME $periph]]

       # Generate canonical definitions only for the peripherals whose
       # canonical name is not the same as hardware instance name
       if { [lsearch $canonicals $periph_name] < 0 } {
           puts $file_handle "/* Canonical definitions for peripheral $periph_name */"
           set canonical_name [format "%s_%s" $drv_string [lindex $indices $i]]

           foreach arg $args {
               set lvalue [::hsi::utils::get_driver_param_name $canonical_name $arg]

               # The commented out rvalue is the name of the instance-specific constant
               # set rvalue [::hsi::utils::get_ip_param_name $periph $arg]
               # The rvalue set below is the actual value of the parameter
               set rvalue [::hsi::utils::get_param_value $periph $arg]
               if {[llength $rvalue] == 0} {
                   set rvalue 0
               }
               set rvalue [::hsi::utils::format_addr_string $rvalue $arg]


               if {[string compare -nocase "LOGO_LAYER" $arg] == 0} {
                    if {[string compare -nocase "true" "$rvalue"] == 0} {
                        set rvalue 1
                    } else {
                        set rvalue 0
                    }
                    puts $file_handle "#define [string toupper $lvalue] $rvalue"
               } elseif {[lsearch -nocase $list_alpha $arg] >= 0} {
                    if {[string compare -nocase "true" "$rvalue"] == 0} {
                        set rvalue 1
                    } else {
                        set rvalue 0
                    }
                    puts $file_handle "#define [string toupper $lvalue] $rvalue"
               } elseif {[lsearch -nocase $list_upsmpl $arg] >= 0} {
                    if {[string compare -nocase "true" "$rvalue"] == 0} {
                        set rvalue 1
                    } else {
                        set rvalue 0
                    }
                    puts $file_handle "#define [string toupper $lvalue] $rvalue"
               } else {
                   puts $file_handle "#define [string toupper $lvalue] $rvalue"
               }
           }
           puts $file_handle ""
           incr i
       }
   }

   puts $file_handle "\n/******************************************************************/\n"
   close $file_handle
}