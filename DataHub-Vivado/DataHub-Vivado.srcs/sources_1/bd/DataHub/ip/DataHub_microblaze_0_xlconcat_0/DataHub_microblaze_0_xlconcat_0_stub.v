// Copyright 1986-2017 Xilinx, Inc. All Rights Reserved.
// --------------------------------------------------------------------------------
// Tool Version: Vivado v.2017.4 (win64) Build 2086221 Fri Dec 15 20:55:39 MST 2017
// Date        : Tue Mar 13 18:04:30 2018
// Host        : Keith-Z640 running 64-bit major release  (build 9200)
// Command     : write_verilog -force -mode synth_stub
//               c:/Users/Keith/Documents/Git/DataHub/DataHub-Vivado/DataHub-Vivado.srcs/sources_1/bd/DataHub/ip/DataHub_microblaze_0_xlconcat_0/DataHub_microblaze_0_xlconcat_0_stub.v
// Design      : DataHub_microblaze_0_xlconcat_0
// Purpose     : Stub declaration of top-level module interface
// Device      : xc7a100tcsg324-1
// --------------------------------------------------------------------------------

// This empty module with port declaration file causes synthesis tools to infer a black box for IP.
// The synthesis directives are for Synopsys Synplify support to prevent IO buffer insertion.
// Please paste the declaration into a Verilog source file or add the file as an additional source.
(* X_CORE_INFO = "xlconcat_v2_1_1_xlconcat,Vivado 2017.4" *)
module DataHub_microblaze_0_xlconcat_0(In0, dout)
/* synthesis syn_black_box black_box_pad_pin="In0[0:0],dout[0:0]" */;
  input [0:0]In0;
  output [0:0]dout;
endmodule