----------
-- File Name : AdderPM.vhd
-- Function : ADD or SUB 2 Input
-- Author : Manabu Inoue
-- Rev and Date : 1.0 , 2025/01/10 , original source
----------


library IEEE;
use IEEE.std_logic_1164.all;
use IEEE.std_logic_arith.all;
use IEEE.std_logic_signed.all;


entity AdderPM is

	port (
		INA : in integer range 0 to 3;
		INB : in integer range 0 to 3;
		MDS : in std_logic;
		RES : out integer range -8 to 7
	);

end AdderPM;


architecture RTL of AdderPM is

begin

	-- 三項演算子みたいなやつ
	RES <=	INA + INB when (MDS = '0') else
			INA - INB;

end RTL;