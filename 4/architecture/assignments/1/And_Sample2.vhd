----------
-- File Name : And_Sample2.vhd
-- Function : Operate the Logical AND for Two Input
-- Author : Manabu Inoue
-- Rev and Date : 1.0 , 2008/10/19 , original source
----------


library IEEE;
use IEEE.std_logic_1164.all;
use IEEE.std_logic_arith.all;
use IEEE.std_logic_signed.all;


entity And_Sample2 is

	port (
		A : in std_logic;
		B : in std_logic;
		Y : out std_logic
	);
	
end And_Sample2;


architecture RTL of And_Sample2 is

begin

	LOGICAL_AND : process(A, B)
	begin

		if ((A = '1') and (B = '1')) then
			Y <= '1';
		else
			Y <= '0';
		end if;

--		if ((A = '0') or (B = '0')) then
--			Y <= '0';
--		else
--			Y <= '1';
--		end if;

	end process;

end RTL;