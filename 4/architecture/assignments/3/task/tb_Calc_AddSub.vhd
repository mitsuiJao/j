----------
-- File Name : tb_Calc_AddSub.vhd
-- Function : Test Bench for Calc_AddSub.vhd
-- Author : Manabu Inoue
-- Rev and Date : 1.0 , 2025/01/10 , original source
----------


library IEEE;
use IEEE.std_logic_1164.all;

entity tb_Calc_AddSub is
end tb_Calc_AddSub;

architecture IO of tb_Calc_AddSub is

	component Calc_AddSub
	port (
		INA : in integer range 0 to 3;
		INB : in integer range 0 to 3;
		MDS : in std_logic;
		MS7 : out std_logic_vector(7 downto 0)
	);
	end component;

	signal done : boolean := false;
	signal ina : integer range 0 to 3 := 0;
	signal inb : integer range 0 to 3 := 0;
	signal mds : std_logic := '0';
	signal ms7 : std_logic_vector(7 downto 0);

begin

	SIM : Calc_AddSub port map (
		INA => ina,
		INB => inb,
		MDS => mds,
		MS7 => ms7
	);

	SIM_TIME : process
	begin
		wait for 2000 ns;
		done <= true;
		wait;
	end process;

	INPUT_A : process
	begin
		if done = false then
			ina <= 0;
			wait for 50 ns;
			ina <= 1;
			wait for 50 ns;
			ina <= 2;
			wait for 50 ns;
			ina <= 3;
			wait for 50 ns;
		else
			wait;
		end if;
	end process;

	INPUT_B : process
	begin
		if done = false then
			inb <= 0;
			wait for 200 ns;
			inb <= 1;
			wait for 200 ns;
			inb <= 2;
			wait for 200 ns;
			inb <= 3;
			wait for 200 ns;
		else
			wait;
		end if;
	end process;
	
	MODE_SEL : process
	begin
		if done = false then
			mds <= '0';
			wait for 800 ns;
			mds <= '1';
			wait for 800 ns;
		else
			wait;
		end if;
	end process;

end IO;