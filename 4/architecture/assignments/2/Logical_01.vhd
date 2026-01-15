----------
-- File Name : Logical_01.vhd
-- Function : Display the Input Logic on the 7 Segment LED
-- Author : Manabu Inoue
-- Rev and Date : 1.0 , 2008/10/19 , original source
----------


library IEEE;
use IEEE.std_logic_1164.all;
use IEEE.std_logic_arith.all;
use IEEE.std_logic_signed.all;


entity Logical_01 is

	port (
		SW : in std_logic;
		SEG7 : out std_logic_vector(6 downto 0)
	);
	
end Logical_01;


architecture RTL of Logical_01 is

begin

	SEG_CONTROL : process(SW)
	begin

		case SW is
			when '0' =>     SEG7 <= "0000001"; -- display 0
			when '1' =>     SEG7 <= "1001111"; -- display 1
			when others =>  SEG7 <= "1111110"; -- display -
		end case;

--		case SW is
--			when '0' =>     SEG7 <= "0000001"; -- display 0
--			when others =>  SEG7 <= "1001111"; -- display 1
--		end case;

	end process;

end RTL;