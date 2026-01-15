----------
-- File Name : ResultAS.vhd
-- Function : Display the ADD or SUB Result on 7 Segment LEDs
-- Author : Manabu Inoue
-- Rev and Date : 1.0 , 2025/01/10 , original source
----------


library IEEE;
use IEEE.std_logic_1164.all;
use IEEE.std_logic_arith.all;
use IEEE.std_logic_signed.all;


entity ResultAS is

	port (
		DAT : in integer range -8 to 7;
		MS7 : out std_logic_vector(7 downto 0)
	);

end ResultAS;


architecture RTL of ResultAS is

begin

	SEG_CONTROL : process(DAT)
	begin
		case DAT is
			when -7 	=> 	MS7 <= "00001111";
			when -6 	=> 	MS7 <= "00100000";
			when -5 	=> 	MS7 <= "00100100";
			when -4 	=> 	MS7 <= "01001100";
			when -3 	=> 	MS7 <= "00000110";
			when -2 	=> 	MS7 <= "00010010";
			when -1 	=> 	MS7 <= "01001111";
			when 0 		=> 	MS7 <= "10000001";
			when 1 		=> 	MS7 <= "11001111";
			when 2 		=> 	MS7 <= "10010010";
			when 3 		=> 	MS7 <= "10000110";
			when 4 		=> 	MS7 <= "11001100";
			when 5 		=> 	MS7 <= "10100100";
			when 6 		=> 	MS7 <= "10100000";
			when 7 		=> 	MS7 <= "10001111";

			when others =>	MS7 <= "11111110";
		end case;
	end process;

end RTL;