----------
-- File Name : UDCounter.vhd
-- Function : Up/Down Counter
-- Author : Manabu Inoue
-- Rev and Date : 1.0 , 2025/01/20 , original source
----------


library IEEE;
use IEEE.std_logic_1164.all;
use IEEE.std_logic_arith.all;
use IEEE.std_logic_signed.all;


entity UDCounter is

	port (
		CLK : in std_logic;
		RST : in std_logic;
		UDS : in std_logic;
		CNT : out integer range 0 to 15
	);
	
end UDCounter;


architecture RTL of UDCounter is

	signal cnt_reg : integer range 0 to 9;

begin

	COUNT3 : process(CLK, RST)
	begin

		if (RST = '1') then 
			cnt_reg <= 0;
		elsif (CLK'event and CLK = '1') then

			if (UDS = '0') then
				if (cnt_reg = 9) then
					cnt_reg <= 0;
				else 
					cnt_reg <= cnt_reg + 1;
				end if;
			else
				if (cnt_reg = 0) then
					cnt_reg <= 9;
				else 
					cnt_reg <= cnt_reg - 1;
				end if;
			end if;
		end if;
	end process;

	CNT <= cnt_reg;

end RTL;