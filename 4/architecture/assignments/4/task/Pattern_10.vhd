----------
-- File Name : Pattern_8_slv.vhd
-- Function : Display the Input Pattern on the 7 Segment LED
-- Author : Manabu Inoue
-- Rev and Date : 1.0 , 2008/10/19 , original source
----------


library IEEE;
use IEEE.std_logic_1164.all;
use IEEE.std_logic_arith.all;
use IEEE.std_logic_signed.all;


entity Pattern_10 is

	port (
		DATA : in integer range 0 to 9;
		SEG7 : out std_logic_vector(6 downto 0)
	);

end Pattern_10;


architecture RTL of Pattern_10 is

begin
	SEG_CONTROL : process(DATA)
	begin
		case DATA is
			when 0 		=> 	SEG7 <= "0000001";
			when 1 		=> 	SEG7 <= "1001111";
			when 2 		=> 	SEG7 <= "0010010";
			when 3 		=> 	SEG7 <= "0000110";
			when 4 		=> 	SEG7 <= "1001100";
			when 5 		=> 	SEG7 <= "0100100";
			when 6 		=> 	SEG7 <= "0100000";
			when 7 		=> 	SEG7 <= "0001111";
            when 8      =>  SEG7 <= "0000000";
            when 9      =>  SEG7 <= "0000100";
			when others =>	SEG7 <= "1111110";
		end case;
	end process;

end RTL;