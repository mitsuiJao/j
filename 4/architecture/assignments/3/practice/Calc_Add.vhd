----------
-- File Name : Calc_Add.vhd
-- Function : 2 Input Accumulator and Display the Result on the 7 Segment LED
-- Author : name
-- Rev and Date : 1.0 , 0000/00/00 , original source
----------


library IEEE;
use IEEE.std_logic_1164.all;
use IEEE.std_logic_arith.all;
use IEEE.std_logic_signed.all;


entity Calc_Add is

	port (
		INA : in integer range 0 to 3;
		INB : in integer range 0 to 3;
		SEG7 : out std_logic_vector(6 downto 0)
	);
	
end Calc_Add;


architecture STRUCTURE of Calc_Add is

	component Adder
	port (
		INA : in integer range 0 to 3;
		INB : in integer range 0 to 3;
		SUM : out integer range 0 to 7
	);
	end component;

	component Pattern_8
	port (
		DATA : in integer range 0 to 7;
		SEG7 : out std_logic_vector(6 downto 0)
	);
	end component;

	signal data_intd : integer range 0 to 7;

begin

	AD : Adder port map (
		INA	=> INA,
		INB	=> INB,
		SUM	=> data_intd
	);

	P8 : Pattern_8 port map (
		DATA => data_intd,
		SEG7 => SEG7
	);

end STRUCTURE;