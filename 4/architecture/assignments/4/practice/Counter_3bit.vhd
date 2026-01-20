----------
-- File Name : Counter_3bit.vhd
-- Function : Count the Clock (3 bit)
-- Author : Manabu Inoue
-- Rev and Date : 1.0 , 2008/11/19 , original source
----------


library IEEE;
use IEEE.std_logic_1164.all;
use IEEE.std_logic_arith.all;
use IEEE.std_logic_signed.all;


entity Counter_3bit is

	port (
		CLK : in std_logic;
		RST : in std_logic;
		CNT : out integer range 0 to 7
	);
	
end Counter_3bit;


architecture RTL of Counter_3bit is
	signal cnt_reg : integer range 0 to 7;
	-- output端子に内部からアクセスすることができない
begin

	COUNT2 : process(CLK, RST)
	begin
		if (RST = '1') then
			cnt_reg <= 0;
		elsif (CLK'event and CLK = '1') then
			if (cnt_reg = 3) then
				cnt_reg <= 0;
			else
				cnt_reg <= cnt_reg + 1;
			end if;
		end if;
	end process;

	CNT <= cnt_reg;

end RTL;