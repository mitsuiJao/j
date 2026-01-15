----------
-- File Name : Adder.vhd
-- Function : 2 Input Accumulator
-- Author : Manabu Inoue
-- Rev and Date : 1.0 , 2008/10/19 , original source
----------


library IEEE;
use IEEE.std_logic_1164.all;
use IEEE.std_logic_arith.all;
use IEEE.std_logic_signed.all;


entity Adder is

	port (
		INA : in integer range 0 to 3;
		INB : in integer range 0 to 3;
		SUM : out integer range 0 to 7
	);

end Adder;


architecture RTL of Adder is

begin

	SUM <= INA + INB;

end RTL;