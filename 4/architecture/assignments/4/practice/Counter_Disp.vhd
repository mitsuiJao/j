----------
-- File Name : Counter_Disp.vhd
-- Function : Count the Clock (3 bit) and Display the Result on the 7 Segment LED
-- Author : Manabu Inoue
-- Rev and Date : 1.0 , 2008/11/19 , original source
----------


library IEEE;
use IEEE.std_logic_1164.all;
use IEEE.std_logic_arith.all;
use IEEE.std_logic_signed.all;


entity Counter_Disp is

	port (
		CLK : in std_logic;
		RST : in std_logic;
		SEG7 : out std_logic_vector(6 downto 0)
	);
	
end Counter_Disp;


architecture STRUCTURE of Counter_Disp is

	component Counter_3bit
	port (
		CLK : in std_logic;
		RST : in std_logic;
		CNT : out integer range 0 to 7
	);
	end component;

	component Pattern_8
	port (
		DATA : in integer range 0 to 7;
		SEG7 : out std_logic_vector(6 downto 0)
	);
	end component;

	signal cnt_data : integer range 0 to 7;

begin

	C3 : Counter_3bit port map (
		CLK => CLK,
		RST => RST,
		CNT => cnt_data
	);

	P8 : Pattern_8 port map (
		DATA => cnt_data,
		SEG7 => SEG7
	);

end STRUCTURE;