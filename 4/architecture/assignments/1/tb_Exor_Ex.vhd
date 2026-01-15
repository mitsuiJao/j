----------
-- File Name : tb_Exor_Ex.vhd
-- Function : Test Bench for Exor_Ex.vhd
-- Author : Manabu Inoue
-- Rev and Date : 1.0 , 2008/10/19 , original source
----------


library IEEE;
use IEEE.std_logic_1164.all;

entity tb_Exor_Ex is
end tb_Exor_Ex;

architecture IO of tb_Exor_Ex is

	component Exor_Ex
	port (
		A : in std_logic;
		B : in std_logic;
		Y : out std_logic
	);
	end component;

	signal done : boolean := false;
	signal a : std_logic := '0';
	signal b : std_logic := '0';
	signal y : std_logic;

begin

	SIM : Exor_Ex port map (
		A => a,
		B => b,
		Y => y
	);

	SIM_TIME : process
	begin
		wait for 500 ns;
		done <= true;
		wait;
	end process;

	INPUT_A : process
	begin
		if done = false then
			a <= '0';
			wait for 100 ns;
			a <= '1';
			wait for 100 ns;
		else
			wait;
		end if;
	end process;

	INPUT_B : process
	begin
		if done = false then
			b <= '0';
			wait for 50 ns;
			b <= '1';
			wait for 100 ns;
			b <= '0';
			wait for 50 ns;
		else
			wait;
		end if;
	end process;

end IO;