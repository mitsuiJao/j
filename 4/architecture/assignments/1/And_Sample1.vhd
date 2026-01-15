----------
-- File Name : And_Sample1.vhd
-- Function : Operate the Logical AND for Two Input
-- Author : Manabu Inoue
-- Rev and Date : 1.0 , 2008/10/19 , original source
----------


library IEEE;
use IEEE.std_logic_1164.all;
use IEEE.std_logic_arith.all;
use IEEE.std_logic_signed.all;


entity And_Sample1 is

	port (
		A : in std_logic;
		B : in std_logic;
		Y : out std_logic
	);
	
end And_Sample1;


architecture RTL of And_Sample1 is

begin

	Y <= A and B;

end RTL;