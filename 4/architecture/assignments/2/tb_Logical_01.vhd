----------
-- File Name : tb_Logical_01.vhd
-- Function : Test Bench for Logical_01.vhd
-- Author : Manabu Inoue
-- Rev and Date : 1.0 , 2008/10/19 , original source
----------


library IEEE;
use IEEE.std_logic_1164.all;

entity tb_Logical_01 is
end tb_Logical_01;

architecture IO of tb_Logical_01 is

	component Logical_01
	port (
		SW : in std_logic;
		SEG7 : out std_logic_vector(6 downto 0)
	);
	end component;

	signal done : boolean := false;
	signal sw : std_logic := '0';
	signal seg : std_logic_vector(6 downto 0);

begin

	SIM : Logical_01 port map (
		SW => sw,
		SEG7 => seg
	);

	SIM_TIME : process
	begin
		wait for 500 ns;
		done <= true;
		wait;
	end process;

	SWL : process
	begin
		if done = false then
			sw <= '0';
			wait for 100 ns;
			sw <= '1';
			wait for 100 ns;
		else
			wait;
		end if;
	end process;

end IO;