----------
-- File Name : Counter_Disp.vhd
-- Function : Up/Down Count by Pos-edge Clock and Display Counts on the 7 Segment LED
-- Author : Manabu Inoue
-- Rev and Date : 1.0 , 2025/01/20 , original source
----------


library IEEE;
use IEEE.std_logic_1164.all;
use IEEE.std_logic_arith.all;
use IEEE.std_logic_signed.all;


entity UDcnt_Disp is

	port (
		CLK : in std_logic;
		RST : in std_logic;
		UDS : in std_logic;
		SEG7 : out std_logic_vector(6 downto 0)
	);
	
end UDcnt_Disp;


architecture STRUCTURE of UDcnt_Disp is

	component UDCounter
	port (
		CLK : in std_logic;
		RST : in std_logic;
		UDS : in std_logic;
		CNT : out integer range 0 to 15
	);
	end component;

	component Pattern_10
	port (
		DATA : in integer range 0 to 9;
		SEG7 : out std_logic_vector(6 downto 0)
	);
	end component;

	signal cnt_data : integer range 0 to 9;

begin

	UDC : UDCounter port map (
		CLK => CLK,
		UDS => UDS,
		RST => RST,
		CNT => cnt_data
	);

	P10 : Pattern_10 port map (
		DATA => cnt_data,
		SEG7 => SEG7
	);

end STRUCTURE;