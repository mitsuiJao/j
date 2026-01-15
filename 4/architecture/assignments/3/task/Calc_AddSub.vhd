----------
-- File Name : Calc_AddSub.vhd
-- Function : 2 Input Accumulator and Display the Result on the 7 Segment LEDs
-- Author : Manabu Inoue
-- Rev and Date : 1.0 , 2025/01/10 , original source
----------


library IEEE;
use IEEE.std_logic_1164.all;
use IEEE.std_logic_arith.all;
use IEEE.std_logic_signed.all;


entity Calc_AddSub is

	port (
		INA : in integer range 0 to 3;
		INB : in integer range 0 to 3;
		MDS : in std_logic;
		MS7 : out std_logic_vector(7 downto 0)
	);
	
end Calc_AddSub;


architecture STRUCTURE of Calc_AddSub is

	component AdderPM
	port (
		INA : in integer range 0 to 3;
		INB : in integer range 0 to 3;
		MDS : in std_logic;
		RES : out integer range -8 to 7
	);
	end component;

	component ResultAS
	port (
		DAT : in integer range -8 to 7;
		MS7 : out std_logic_vector(7 downto 0)
	);
	end component;

	signal res_dat : integer range -8 to 7;

begin

	AP : AdderPM port map (
		INA => INA,
		INB => INB,
		MDS => MDS,
		RES => res_dat
	);

	RA : ResultAS port map (
		DAT => res_dat,
		MS7 => MS7
	);

end STRUCTURE;